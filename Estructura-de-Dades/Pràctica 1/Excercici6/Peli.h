#ifndef PELI_H
#define PELI_H
#endif
/*Autor del codi: Oriol Jiménez Blanco
Github: EntrepaDeFuet
email: orioljb1999@gmail.com
*/

#include <iostream>
using namespace std;

class Peli{

    private:
        int peliId, directorId, durada;
        float valoracio;
        string nom;

        //Setters (estan en privat, doncs només poden modificar les variables a partir del constructor.):
        void setPeliId(int id);
        void setDirectorId(int id);
        void setDurada(int durada);
        void setNom(string nom);

    public:
        //Constructor:
        Peli(int id, int director, int duracio, float puntuacio, string titol); 

        //Getters:
        int getPeliId();
        int getDirectorId();
        int getDurada();
        float getValoracio();
        string getNom();

        //Setter (valoracio és l'únic que té sentit que variï):
        void setValoracio(float valoracio);

        //Altres:
        void print();

};