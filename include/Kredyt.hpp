#pragma once

#define max_raty 20
#define oprocentowanie_miesiecznie 0.1

class Kredyt
{
    double dlug;
    int    pozostale_raty;

public:
    double splac_rate()
    {
        double rata = dlug / pozostale_raty;
        dlug -= rata;
        pozostale_raty--;
        dlug = dlug * oprocentowanie_miesiecznie;
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
    double oblicz_rate() { return dlug / pozostale_raty; }
};