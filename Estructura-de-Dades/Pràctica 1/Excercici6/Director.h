#ifndef DIRECTOR_H
#define DIRECTOR_H
#endif

#include <iostream>
#include "Peli.cpp"
#include <stdexcept>
#include <vector>
using namespace std;

class Director
{

    private:

        int directorId, genere;
        string nom;
        vector <Peli> pelis;
        
        //Setters:
        void setDirectorId(int id);
        void setGenere(int gen);
        void setNom(string nom);


    public:
        //Contructor:
        Director(int id, int gen, string nom);

        //Getters:
        int getGenere();
        int getDirectorId();
        string getNom();
        vector <Peli> getPelis();
        int getNumeroDePelis();

        //Altres:
        void addPeli(int id, int director, int duracio, float puntuacio, string titol);
        void removePeli(int id);
        void printPelis();
        void print();

};

