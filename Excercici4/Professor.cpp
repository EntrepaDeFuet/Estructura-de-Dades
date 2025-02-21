#include <iostream>
#include "Professor.h"
#include <stdexcept>

using namespace std;

Professor::Professor()
{

}

Professor::Professor(string nom, int any){
    this->nom = nom;
    this->any = any;

}
int Professor::getEdat(){
    try{
        return 2025 - this->any;
    } catch(const std::invalid_argument& ex ){
        cout << "Any de naixement incorrecte." << endl;
        return 0;  
    }

}
void Professor::print(){
    cout << "Nom: " << this->nom << "\n";
    cout << "Edat: " << getEdat() << "\n";
    cout << "Any de naixement: " << any << "\n";
}