#include <iostream>
#include "Estudiant.h"
#include <stdexcept>

using namespace std;

Estudiant::Estudiant()
{

}
void Estudiant::setNom(string nom){
    this->nom = nom;
}

void Estudiant::setAny(int any){
    if (any > 0 && any <= 2025){
        this-> any = any;

    } else {
        throw invalid_argument("Any invàlid, recorda que els anys han de ser possitius i inferiors a 2025!");
    }
}
void Estudiant:: setMatricules(int matricules){
    if (matricules > 0){
        this->matricules = matricules;
    } else {
        throw invalid_argument ("Un alumne ha d'estar matriculat a almenys una matricula.");
    }
}

Estudiant::Estudiant(string nom, int any, int matricules){
    try{
    this->setMatricules(matricules);
    } catch (invalid_argument &e){
        cout << e.what() << endl;
    }
    try{
    this->setAny(any);
    } catch (invalid_argument &er){
        cout << er.what() << endl;
    }
    this->setNom(nom);
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