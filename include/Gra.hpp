#pragma once

#include "Firma.hpp"

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
    bool get_stan() {return stan;}

    void tick() {
        if(get_stan()){
            firma.otrzymaj_przychod();
            firma.zaplac_wynagrodzenie();
            firma.splac_raty();
        }
    }
};