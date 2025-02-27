#include <iostream>
#include "Peli.h"
#include <stdexcept>
using namespace std;



Peli::Peli(int id, int director, int duracio, float puntuacio, string titol){
    this->setNom(titol);
    this->setPeliId(id);
    this->setDirectorId(director);
    this->setDurada(duracio);
    this->setValoracio(puntuacio);
}

int Peli::getPeliId(){
    return this->peliId;
}

int Peli::getDirectorId(){
    return this->directorId;
}

int Peli::getDurada(){
    return this ->durada;
}

float Peli::getValoracio(){
    return this->valoracio;
}
string Peli::getNom(){
    return this->nom;
}
void Peli::setValoracio(float puntuacio){
    this->valoracio = puntuacio;
}

void Peli::setNom(string titol){
    this->nom = titol;
}

void Peli::setPeliId(int id){
    this->peliId = id;
}

void Peli::setDirectorId(int director){
    this->directorId = director;
}

void Peli::setDurada(int duracio){
    this->durada = duracio;
}

void Peli::print(){
    cout << "Nom de la Peli: " << this->getNom() << endl;
    cout << "Id: " << this->getPeliId() << endl;
    cout << "Id del director: " << this->getDirectorId() << endl;
    cout << "Durada en minuts: " << this->getDurada() << endl;
    cout << "Valoració actual: " << this->getValoracio()<< endl;
    cout << "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-"<< endl;
}
