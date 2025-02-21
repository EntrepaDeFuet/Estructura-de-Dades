#include <iostream>
#include "Estudiant.h"
#include <stdexcept>

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
    try{
        return 2025 - this->any;
    } catch(const std::invalid_argument& ex ){
        cout << "Any de naixement incorrecte." << endl;
        return 0;  
    }

}
void Estudiant::print(){
    cout << "Nom: " << this->nom << "\n";
    cout << "Edat: " << getEdat() << "\n";
    cout << "Any de naixement: " << any << "\n";
    cout << "Assignatures matriculades: " << matricules << "\n";
}