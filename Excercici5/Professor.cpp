#include <iostream>
#include "Professor.h"
#include <stdexcept>

using namespace std;

Professor::Professor()
{

}

void Professor::setNom(string nom){
    this->nom = nom;
}

void Professor::setAny(int any){
    if (any > 0 && any < 2025){
        this->any =any;
    } else{
        throw invalid_argument("Any invàlid, recorda que els anys han de ser possitius i inferiors a 2025!");
    }
}


Professor::Professor(string nom, int any){
    try{
    this->setAny(any);
    } catch (invalid_argument &er){
        cout << er.what() << endl;
    }
    this->setNom(nom);
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