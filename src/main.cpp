#include "Pracownik.hpp"
#include "PrinterPracownikow.hpp"
#include "Firma.hpp"
#include <iostream>
#include <memory>
#include <variant>

using namespace std;

int main()
{
    // unique_ptr<variant<Inzynier,Magazynier,Marketer,Robotnik>[]> pracownicy(new variant<Inzynier,Magazynier,Marketer,Robotnik>[1000]);
    // pracownicy[0]=Inzynier();
    
    
    // cout<<holds_alternative<Inzynier>(pracownicy[0])<<"\t"<<holds_alternative<Robotnik>(pracownicy[0])<<"\n\n";

    // visit(PrinterPracownikow(),pracownicy[0]);

    // Firma f{};
    // f.zatrudnij(Robotnik());
    // f.zaplac_wynagrodzenie();
    // cout<<f.get_stan_konta();


}
