#pragma once

#include "RandomNameGenerator.hpp"
#include <iostream>
#include <random>

class Pracownik
{
private:
protected:
    std::string imie;

public:
    static int const wynagrodzenie = 0;
    Pracownik() { imie = getRandomName(); }
    virtual void print()
    {
        std::cout << "Pracownik o imieniu: " << imie << ". \t Otrzymuje wynagrodzenie wynoszace: " << wynagrodzenie
                  << ".\n";
    }
};

class Inzynier : public Pracownik
{
    std::string wydzial;

public:
    static const int CI            = 100;
    static int const wynagrodzenie = 6000;
    Inzynier()
    {
        imie    = getRandomName();
        wydzial = "MEiL";
    }
    void print() override
    {
        std::cout << "Inzynier o imieniu: " << imie << ". \t Otrzymuje wynagrodzenie wynoszace: " << wynagrodzenie
                  << ".\t Studiowal na wydziale: " << wydzial << ".\n";
    }
};

class Magazynier : public Pracownik
{
    bool obsl_widl;

public:
    static int const wynagrodzenie = 3200;
    static const int CMag          = 1000;

    Magazynier() {}
    void print() override
    {
        std::cout << "Magazynier o imieniu: " << imie << ". \t Otrzymuje wynagrodzenie wynoszace: " << wynagrodzenie;
        if (obsl_widl)
        {
            std::cout << ".\t Moze obslugiwac wozek widlowy.\n";
        }
        else
        {
            std::cout << ".\t Nie moze obslugiwac wozka widlowego.\n";
        }
    }
};

class Marketer : public Pracownik
{
    int follows;

public:
    static int const wynagrodzenie = 4000;
    static const int CMkt          = 200;

    Marketer()
    {
        std::default_random_engine           gen;
        std::uniform_int_distribution< int > dist(0, 10000000);
        follows = dist(gen);
    }
    void print() override
    {
        std::cout << "Marketer o imieniu: " << imie << ". \t Otrzymuje wynagrodzenie wynoszace: " << wynagrodzenie
                  << ".\t Ma " << follows << " obserwujacych.\n";
    }
};

class Robotnik : public Pracownik
{
    double but;

public:
    static int const wynagrodzenie = 3200;
    static const int CR            = 40;

    Robotnik()
    {
        std::default_random_engine           gen;
        std::uniform_int_distribution< int > dist(60, 82);
        but = dist(gen);
        but = but / 2;
    }

    void print() override
    {
        std::cout << "Robotnik o imieniu: " << imie << ". \t Otrzymuje wynagrodzenie wynoszace: " << wynagrodzenie
                  << ".\t Jego rozmiar buta to: " << but << ".\n";
    }
};