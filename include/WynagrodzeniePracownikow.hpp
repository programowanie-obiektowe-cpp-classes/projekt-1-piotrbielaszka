#pragma once

#include "Pracownik.hpp"
#include <variant>

struct WynagrodzeniePracownikow
{
    int operator()(Pracownik var) const { return var.wynagrodzenie; }
    int operator()(Inzynier var) const { return var.wynagrodzenie; }
    int operator()(Marketer var) const { return var.wynagrodzenie; }
    int operator()(Magazynier var) const { return var.wynagrodzenie; }
    int operator()(Robotnik var) const { return var.wynagrodzenie; }
};