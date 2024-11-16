#pragma once

#include "RandomNameGenerator.hpp"
// #include "RandomWydzialGenerator.hpp"
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
    static constexpr int CI            = 100;
    static int const     wynagrodzenie = 6000;
    Inzynier()
    {
        imie    = getRandomName();
        wydzial = getRandomWydzial();
    }
    void print() override
    {
        std::cout << "Inzynier o imieniu: " << imie << ". \t Otrzymuje wynagrodzenie wynoszace: " << wynagrodzenie
                  << ".\t Studiowal na wydziale " << wydzial << ".\n";
    }
};

class Magazynier : public Pracownik
{
    bool obsl_widl;

public:
    static int const     wynagrodzenie = 3200;
    static constexpr int CMag          = 1000;

    Magazynier()
    {
        imie      = getRandomName();
        obsl_widl = getRandomObslugaWozka();
    }
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
    static int const     wynagrodzenie = 4000;
    static constexpr int CMkt          = 200;

    Marketer()
    {
        imie    = getRandomName();
        follows = getRandomFollows();
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
    static int const     wynagrodzenie = 3200;
    static constexpr int CR            = 40;

    Robotnik()
    {
        but=getRandomBut();
    }

    void print() override
    {
        std::cout << "Robotnik o imieniu: " << imie << ". \t Otrzymuje wynagrodzenie wynoszace: " << wynagrodzenie
                  << ".\t Jego rozmiar buta to: " << but << ".\n";
    }
};