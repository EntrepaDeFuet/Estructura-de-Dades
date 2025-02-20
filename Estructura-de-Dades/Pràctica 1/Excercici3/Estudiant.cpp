#include <iostream>
#include "Estudiant.h"

using namespace std;

Estudiant::Estudiant()
{

}

Estudiant::Estudiant(string nom, int any, int matricules){
    this->nom = nom;
    this->any = any;
    this->matricules = matricules;
}
int Estudiant::getEdat(){
    return 2025 - this->any;

}
void Estudiant::print(){
    cout << "Nom: " << this->nom << "\n";
    cout << "Edat: " << getEdat() << "\n";
    cout << "Any de naixement: " << any << "\n";
    cout << "Assignatures matriculades: " << matricules << "\n";
}