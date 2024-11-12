#pragma once

#include "Firma.hpp"

#define M 2
#define WartoscWygranej 100000

using namespace std;

class Gra
{
    bool  stan;
    Firma firma;
    void  tick()
    {
        firma.otrzymaj_przychod();
        firma.zaplac_wynagrodzenie();
        firma.splac_raty();
        cout << "Stan konta wynosi: " << firma.get_stan_konta() << "\n\n";
        firma.print_statystyki();

        get_stan();
    }
    void przegrana()
    {
        stan = false;
        cout << "\n\n Przegrales :(";
    }
    void wygrana()
    {
        stan = false;
        cout << "\n\n Wygrales :)";
    }

public:
    Gra()
    {
        stan  = true;
        firma = Firma();
    }
    void akcja_gracza()
    {
        get_stan();
        cout << "\n Wprowadz komende: ";
        string input;
        cin >> input;
        if (input == "lp")
            firma.drukuj_pracownikow();
        else if (input == "lk")
            firma.print_raty();
        else if (input == "zinz")
            firma.zatrudnij(Inzynier{});
        else if (input == "zmag")
            firma.zatrudnij(Magazynier{});
        else if (input == "zmkt")
            firma.zatrudnij(Marketer{});
        else if (input == "zrob")
            firma.zatrudnij(Robotnik{});
        else if (input == "kt")
            tick();
        else if (input == "help")
            print_instrukcja();
        else if (input == "stat")
            firma.print_statystyki();
        else if (input == "kred")
        {
            cout << "\n Wprowadz kwote kredytu: ";
            double k = 0;
            cin >> k;
            cout << "\n Wprowadz ilosc rat: ";
            int r;
            cin >> r;
            firma.wez_kredyt(k, r);
        }
    }
    bool get_stan()
    {
        if (firma.get_stan_konta() <= 0)
            przegrana();
        else if (firma.oblicz_zadluzenie() > M * firma.wartosc_firmy())
            przegrana();
        else if (firma.wartosc_firmy() - firma.oblicz_zadluzenie() >= WartoscWygranej)
            wygrana();
        return stan;
    }
    void print_instrukcja()
    {
        cout << "Dostepne komendy:\n";
        cout << "lp - wylistuj pracownikow\n";
        cout << "lk - wylistuj kredyty\n";
        cout << "zinz - zatrudnij inz.\n";
        cout << "zmag - zatrudnij mag.\n";
        cout << "zmkt - zatrudnij mark.\n";
        cout << "zrob - zatrudnij rob.\n";
        cout << "kred - wez kredyt (w nastepnym kroku podaj kwote i czas splaty)\n";
        cout << "kt - zakoncz ture i wyswietl stan firmy na poczatku nastepnego miesiaca\n";
        cout << "stat - drukuje statystyki dla biezacej tury\n";
        cout << "help - drukuje instrukcje\n";
    }
};