#pragma once

#define max_raty 20
#define oprocentowanie_miesiecznie 0.05

#include <iostream>

using namespace std;

class Kredyt
{
    double dlug;
    int    pozostale_raty;

public:
    double splac_rate()
    {
        dlug += dlug * oprocentowanie_miesiecznie;
        double rata = oblicz_rate();
        dlug -= rata;
        pozostale_raty--;
        return rata;
    }

    Kredyt(double wysokosc_kredytu, int ilosc_rat) : dlug(wysokosc_kredytu), pozostale_raty(ilosc_rat)
    {
        if (dlug > 0)
        {
            if (pozostale_raty > max_raty)
                pozostale_raty = 0;
            dlug += dlug * oprocentowanie_miesiecznie;
        }
        else
        {
            dlug           = 0;
            pozostale_raty = 0;
        }
    }
    Kredyt()
    {
        pozostale_raty = 0;
        dlug           = 0;
    }

    double get_dlug() { return dlug; }
    double oblicz_rate()
    {
        if (pozostale_raty > 0)
            return dlug / pozostale_raty;
        return 0;
    }

    void print()
    {
        if (oblicz_rate() > 0)
        {
            cout << "Kwota kredytu wynosi: " << dlug << ". Pozostalo " << pozostale_raty << " rat.\n";
        }
    }
};