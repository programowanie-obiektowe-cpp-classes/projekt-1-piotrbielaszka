#pragma once

#include "RandomNameGenerator.hpp"
#include <iostream>

double const CI   = 1;
double const CMag = 1;
double const CMkt = 1;
double const CR   = 1;

class Pracownik
{
private:
protected:
    std::string imie;

public:
    Pracownik() { imie = getRandomName(); }
    static const double wynagrodzenie;
    virtual void        print() { std::cout << "Pracownik o imieniu: " << imie << ".\n"; }
};

class Inzynier : Pracownik
{
    std::string wydzial;

public:
    Inzynier()
    {
        imie    = getRandomName();
        wydzial = "MEiL";
    }
    //  static const double wynagrodzenie = 1000;
    void print() override
    {
        std::cout << "Inzynier o imieniu: " << imie << ". Studiowal na wydziale: " << wydzial << ".\n";
    }
};

class Magazynier : Pracownik
{
    bool obsl_widl;

public:
    Magazynier() {}
    //  static const int wynagrodzenie = 1000;
    void print() override
    {
        std::cout << "Magazynier o imieniu: " << imie;
        if (obsl_widl)
        {
            std::cout << ". Moze obslugiwac wozek widlowy.\n";
        }
        else
        {
            std::cout << ". Nie moze obslugiwac wozka widlowego.\n";
        }
    }
};

class Marketer : Pracownik
{
    int follows;

public:
    // Marketer() { follows = std::uniform_int_distribution<>(0, 1e7); }
    // static const double wynagrodzenie = 1000;
    void print() override { std::cout << "Marketr o imieniu: " << imie << ". Ma " << follows << "obserwujacych.\n"; }
};

class Robotnik : Pracownik
{
    double but;

public:
    // static const double wynagrodzenie = 1000;
    void print() override { std::cout << "Robotnik o imieniu: " << imie << ". Jego rozmiar bura to: " << but << ".\n"; }
};