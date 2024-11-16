#pragma once

#include "Pracownik.hpp"
#include <variant>

struct PrinterPracownikow
{
    // void operator()(Pracownik& var) const { var.print(); }
    // void operator()(Inzynier& var) const { var.print(); }
    // void operator()(Marketer& var) const { var.print(); }
    // void operator()(Magazynier& var) const { var.print(); }
    // void operator()(Robotnik& var) const { var.print(); }
    template <typename T>
    void operator()(T& var) const { var.print(); }
};