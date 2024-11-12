#pragma once
#include "Kredyt.hpp"
#include "Pracownik.hpp"
#include "PrinterPracownikow.hpp"
#include "WynagrodzeniePracownikow.hpp"
#include <memory>
#include <variant>

#define ilosc_pracownikow_max 1000
#define ilosc_kredytow_max 100
#define ilosc_iteracji_max 1000
#define stan_konta_poczatek 20000
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
        prac       = make_unique< variant< Inzynier, Magazynier, Marketer, Robotnik >[] >(ilosc_pracownikow_max);
        kredyty         = make_unique< Kredyt[] >(ilosc_kredytow_max);
        historia_przych = unique_ptr< double[] >(new double[ilosc_iteracji_max]);

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
        if (kredyty[n_kredytow - 1].get_dlug() <= 0)
            cout << "Bank nie udzielil kredytu!.\n";
        else
        {
            stan_konta += kwota;
            cout << "Bank udzielil kretytu. Kwota " << kwota
                 << " zostala przelana na twoj rachunek, ktorego obecny stan wynosi: " << stan_konta << ".\n";
        }
    }
    void zatrudnij(variant< Inzynier, Magazynier, Marketer, Robotnik > p)
    {
        prac[n_prac] = p;
        n_prac++;
    }

    void zaplac_wynagrodzenie()
    {
        double wyn = 0;
        for (int i = 0; i < n_prac; i++)
        {
            wyn += visit(WynagrodzeniePracownikow(), prac[i]);
        }
        stan_konta -= wyn;
        cout << "Zaplaciles wynagrodzenie w wysokosci: " << wyn << ".\n";
    }

    void otrzymaj_przychod()
    {
        historia_przych[iteracja] = oblicz_przychod();
        cout << "W tej trurze twoj przychod wyniosl: " << historia_przych[iteracja] << ".\n";
        stan_konta += historia_przych[iteracja];
        iteracja++;
    }

    void splac_raty()
    {
        double raty = 0;
        for (int i = 0; i < n_kredytow; i++)
        {
            raty += kredyty[i].splac_rate();
        }
        stan_konta -= raty;
        cout << "Raty wyniosly: " << raty << ".\n";
    }
    double get_stan_konta() { return stan_konta; }
    double wartosc_firmy()
    {
        if (iteracja == 0)
            return stan_konta_poczatek;
        double wartosc_firmy = 0;
        int    i_max         = N;
        if (iteracja < i_max)
            i_max = iteracja;
        for (int i = 1; i <= i_max; i++)
        {
            wartosc_firmy += historia_przych[iteracja - i];
        }
        return wartosc_firmy / i_max;
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

    void print_statystyki()
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
        cout << "Robotnicy moga wyprodukowac maksymalnie " << wyprodukowane_produkty << " produktow.\n";
        cout << "Pojemnosc magazynu wynosi: " << pojemnosc_magazynu << ".\n";
        cout << popyt << " osob chce kupic ten produkt.\n";
        cout << "Cena jednostkowa produktu wynosi: " << cena << ".\n";
    }

    void print_raty()
    {
        cout << "Lista bierzacych kredytow:\n";
        for (int i = 0; i < n_kredytow; i++)
        {
            kredyty[i].print();
        }
    }
};