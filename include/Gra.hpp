#pragma once

#include "Firma.hpp"

#define M 2

class Gra
{
    bool  stan;
    Firma firma;

public:
    Gra()
    {
        stan  = true;
        firma = Firma();
    }
    void akcja_gracza() {}
    bool get_stan()
    {
        if (firma.get_stan_konta() <= 0)
            stan = false;
        if (firma.oblicz_zadluzenie() > M * firma.wartosc_firmy())
            stan = false;
        return stan;
    }

    void tick()
    {
        if (get_stan())
        {
            firma.otrzymaj_przychod();
            firma.zaplac_wynagrodzenie();
            firma.splac_raty();
        }
    }
};