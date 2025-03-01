#include <iostream>
#include "Director.h"
#include <stdexcept>
using namespace std;

Director::Director(int id, int gen, string nom){
    this->setDirectorId(id);
    this->setGenere(gen);
    this->setNom(nom);
}

void Director::setDirectorId(int id){
    this->directorId = id;
}

void Director::setGenere(int gen){
    this->genere = gen;
}

void Director::setNom(string nom){
    this->nom = nom;
}

int Director::getDirectorId(){
    return this->directorId;
}

int Director::getGenere(){
    return this->genere;
}

string Director::getNom(){
    return this->nom;
}

vector <Peli> Director::getPelis(){
    return this->pelis;
}

void Director::addPeli(int id, int director, int duracio, float puntuacio, string titol){
    Peli peliNova = Peli(id, director, duracio, puntuacio, titol);
    this->pelis.push_back(peliNova);
}

void Director::removePeli(int id){
    bool cntrl = true;
    int index = -1;

    for (int i = 0; i< pelis.size() && cntrl ; i++){
        if (pelis[i].getPeliId() == id){
            cntrl = false;
            index = i;
        }
    }
    if (index >= 0){
        cout <<"S'esborrarà la següent pel·licula:"<< endl;
        pelis[index].print();
        pelis.erase(pelis.begin()+index);

    } else {
        cout << "No s'ha trobat cap pel·licula amb aquesta ID i aques director, ho sentim." << endl;
    }
}

int Director::getNumeroDePelis(){
    return this->pelis.size();
}

void Director::print(){

    string genere;

    switch (this->getGenere())
    {
    case 0:
        genere = "No binari ";
        break;
    
    case 1:
        genere = "Dona ";
        break;
    case 2:
        genere = "Home ";
        break;

    }

    cout << "Nom del director: " << this->getNom() << " Id del director: " << this->getDirectorId() << "Genere del director: " << genere << "Pelis del director: " <<  this->getNumeroDePelis() << endl;
    cout << "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-" << endl;
}

void Director::printPelis(){

    cout << "Pel·licules de " << this->getNom() << " :" << endl;

    for (int i = 0; i < this->getNumeroDePelis() ; i++){
        pelis[i].print();
    }
}