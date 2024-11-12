#pragma once
#include "Kredyt.hpp"
#include "Pracownik.hpp"
#include "PrinterPracownikow.hpp"
#include "WynagrodzeniePracownikow.hpp"
#include <memory>
#include <variant>

#define ilosc_pracownikow_max 1000
#define ilosc_kredytow_max 100
#define stan_konta_poczatek 10000
#define N 10

using namespace std;

class Firma
{
    double                 stan_konta;
    int                    n_kredytow;
    unique_ptr< Kredyt[] > kredyty;
    int                    n_prac;
    int                    iteracja;

    unique_ptr< variant< Inzynier, Magazynier, Marketer, Robotnik >[] > prac;
    unique_ptr< double[] >                                              historia_przych;

public:
    Firma()
    {
        n_prac     = 0;
        n_kredytow = 0;
        iteracja   = 0;
        stan_konta = stan_konta_poczatek;
        prac       = unique_ptr< variant< Inzynier, Magazynier, Marketer, Robotnik >[] >(
            new variant< Inzynier, Magazynier, Marketer, Robotnik >[ilosc_pracownikow_max]);
        // kredyty = unique_ptr< Kredyt[] >(new Kredyt[ilosc_kredytow_max]);
        kredyty = make_unique< Kredyt[] >(ilosc_kredytow_max);

        zatrudnij(Inzynier());
        zatrudnij(Marketer());
        zatrudnij(Magazynier());
        zatrudnij(Robotnik());
    }

    void drukuj_pracownikow()
    {
        for (int i = 0; i < n_prac; i++)
        {
            visit(PrinterPracownikow(), prac[i]);
        }
    }
    void wez_kredyt(double kwota, int czas_splaty)
    {
        kredyty[n_kredytow] = Kredyt(kwota, czas_splaty);
        n_kredytow++;
    }
    void zatrudnij(variant< Inzynier, Magazynier, Marketer, Robotnik > p)
    {
        prac[n_prac] = p;
        n_prac++;
    }

    void zaplac_wynagrodzenie()
    {
        for (int i = 0; i < n_prac; i++)
        {
            stan_konta -= visit(WynagrodzeniePracownikow(), prac[i]);
        }
    }

    void otrzymaj_przychod()
    {
        iteracja++;
        historia_przych[iteracja] = oblicz_przychod();
        stan_konta += historia_przych[iteracja];
    }

    void splac_raty()
    {
        for (int i = 0; i < n_kredytow; i++)
        {
            stan_konta -= kredyty[i].splac_rate();
        }
    }

    double get_stan_konta() { return stan_konta; }
    double wartosc_firmy()
    {
        double wartosc_firmy = 0;
        for (int i = 1; i <= N; i++)
        {
            wartosc_firmy += historia_przych[iteracja - i];
        }
        return wartosc_firmy;
    }

    double oblicz_przychod()
    {
        int wyprodukowane_produkty = 0;
        int pojemnosc_magazynu     = 0;
        int popyt                  = 0;
        int cena                   = 0;
        for (int i = 0; i < n_prac; i++)
        {
            if (holds_alternative< Robotnik >(prac[i]))
                wyprodukowane_produkty += get< Robotnik >(prac[i]).CR;
            else if (holds_alternative< Magazynier >(prac[i]))
                pojemnosc_magazynu += get< Magazynier >(prac[i]).CMag;
            else if (holds_alternative< Marketer >(prac[i]))
                popyt += get< Marketer >(prac[i]).CMkt;
            else if (holds_alternative< Inzynier >(prac[i]))
                cena += get< Inzynier >(prac[i]).CI;
        }
        if (popyt < wyprodukowane_produkty)
        {
            return popyt * cena;
        }
        else
        {
            return wyprodukowane_produkty * cena;
        }
    }

    double oblicz_zadluzenie()
    {
        double ret = 0;
        for (int i = 0; i < n_kredytow; i++)
        {
            ret += kredyty[i].get_dlug();
        }
        return ret;
    }
};