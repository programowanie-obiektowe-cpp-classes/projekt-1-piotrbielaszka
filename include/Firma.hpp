#pragma once
#include <memory>
#include "Pracownik.hpp"
#include "Kredyt.hpp"

class Firma{
    double stan_konta;
    int n_kredytow;
    std::unique_ptr<Kredyt[]> kredyty;
    int n_prac;
    std::unique_ptr<std::unique_ptr<Pracownik>[]> prac;
    std::unique_ptr<double[]> historia_przych;

    void drukuj_pracownikow(){

    }
    void wez_kredyt(double kwota, int czas_splaty){

    }
    void zatrudnij(std::unique_ptr<Pracownik>){

    }

    void zaplac_wynagrodzenie(){

    }
    void otrzymaj_przychod(){

    }
    void spalc_raty(){

    }

    double get_stan_konta(){

    }
    double wartosc_firmy(){

    }

    double oblicz_przychod(){
        
    }
};