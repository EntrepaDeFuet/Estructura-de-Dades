#include <iostream>
#include <stdexcept>
#include "Peli.cpp"
#include "Director.cpp"
#include <fstream>
using namespace std;

int triaMenu(){

    int sel;
    string triar;
    cin >> triar;
    try{
        sel = std::stoi(triar);
    } catch (std::invalid_argument& e){
        return 7;
    }

    return sel;
}

bool directorNoRepetit(vector <Director> &directors, int idActual){

    bool noRepetit = true;

    for (int i=0; i < directors.size() && noRepetit; i++){

        if (directors[i].getDirectorId() == idActual){
            noRepetit = false;
        }

    }
    return noRepetit;
}


void afegirDirector(vector <Director> & directors, vector <int> & pelis){

    string nom;
    int id,genere;

    cout << "Quin és el nom del director? " << endl;
    cin >> nom;
    
    cout << "Quina és la seva id? " << endl;
    cin >> id;

    if (id < 0){

        throw invalid_argument("La id del director no pot ser negativa." );
        id = 0000;

    }
    if (directorNoRepetit(directors,id)){

        cout << "Quin és el seu gènere? (1: Dona, 2: Home, 0: No binari)" << endl;
        cin >> genere;

        if (genere <0 || genere > 2 ){

            throw invalid_argument ("El gènere que has escollit no està determinat. ");
            genere = 0;
        }

        Director directorNou = Director(id, genere, nom);
        
        cout << "Voldràs afegir-hi una pel·licula? ('s' = si, 'n' = no)" << endl;
        char resposta;
        cin >> resposta;
        
        switch (resposta)
        {
        case 's':
            afegirPeliDirectorNou(directorNou, pelis);
            break;

        case 'n':
            cout << "Molt bé d'acord." << endl;
            break;
        
        default:
            cout << "No t'he entès, no s'afegirà cap peli. " << endl;
            break;
        }

        directors.push_back(directorNou);

    } else {

        cout << "Ja hi ha un director amb aquesta ID. No es pot afegir un nou director." << endl;

    }
}

bool peliRepetida(vector <int> &pelis, int id){

    bool repetida=false;

    for (int i = 0; i < pelis.size() && !repetida; i++){
        if (id == pelis[i]){
            repetida = true;
        }
    }
    return repetida;
}

void afegirPeliDirectorNou(Director &director, vector <int> &pelis){

    string nom;
    int durada, id;
    float valoracio;

    cout << "Quin és el nom de la peli? " << endl;
    cin >> nom;

    cout << "Quina és la durada en minuts de la peli? " << endl;
    cin >> durada;
    
    if (durada < 0){
        throw invalid_argument("La duració de la peli no pot ser negativa.");
        durada = 90;
    }

    cout << "Quina és la id de la peli? " << endl;
    cin >> id;
    if (id<0){
        throw invalid_argument ("La id de la peli no pot ser negativa. ");
        id = 0000;
    }
    
    cout << "Quina és la valoració de la peli ?" << endl;
    cin >> valoracio;
    if (valoracio < 0 || valoracio > 10){
        throw invalid_argument ("La valoració ha d'estar entre 0 i 10. ");
        valoracio = 5.0;
    }
    if (peliRepetida(pelis, id)){

        cout << "Ja existeix una peli amb aquesta ID, ho sentim no es pot afegir." << endl;

    } else {

        director.addPeli(id,director.getDirectorId(),durada,valoracio,nom);
        pelis.push_back(id);

    }

}

void eliminarPeli(vector <Director>& directors, vector <int>& pelis, int id){

    bool existeixDirector = false;
    int indexDirector, indexPelis;

    for (int i = 0; i<directors.size() && !existeixDirector ; i++ ){
        
        if (directors[i].getDirectorId()==id){
            existeixDirector = true;
            indexDirector = i;
        }

    }

    if (existeixDirector && peliRepetida(pelis, id)){
        
        directors[indexDirector].removePeli(id);
        
    }  else if (existeixDirector && !peliRepetida(pelis,id)){

        cout << "No existeix cap peli associada a aquesta id." << endl;

    } else {
        
        cout << "No existeix cap director amb aquesta id." << endl;

    }
    
}

void afegirPeli(vector <Director> & directors, vector <int> & pelis){

    cout << "Introdueix la id del director a qui vols afegir una peli: " << endl;

    string idString;
    int directorId;
    cin >> idString;

    try{
        directorId = std::stoi(idString);
    } catch (std::invalid_argument& e){

        cout << "El format de la id no és vàlid. " << endl;
        //El return es per a finalitzar la funció. Doncs s'ha introduït una id invàlida.
        return;

    }
            
    bool existeixDirector = false;
    int index;
    
    for (int i = 0; i < directors.size() && !existeixDirector; i++){
        if (directors[i].getDirectorId() == directorId){
            existeixDirector = true;
            index = i;
        }
    }

    if (existeixDirector){

        afegirPeliDirectorNou(directors[index], pelis);

    } else {

        cout << "La id proporcionada no coincideix amb la de cap director. " << endl;

    }


}

void imprimirDirectors(vector <Director> & directors){

    string genere;

    for (int i = 0; i < directors.size(); i++){

        directors[i].print();
    }

}

void imprimirPelis(vector <Director> & directors ,int id){

    bool existeixDirector = false;
    int index;
    
    for (int i = 0; i < directors.size() && !existeixDirector; i++){

        if (directors[i].getDirectorId() == id){
            existeixDirector = true;
            index = i;
        }
    }

    if (existeixDirector){

        directors[index].printPelis();

    } else {

        cout << "La id proporcionada no coincideix amb la de cap director. " << endl;

    }
}

int main(){

    int menu;
    bool loop = true;
    vector <Peli> pelis;
    vector <Director> directors;

    while(loop) {



        menu = triaMenu();

        switch (menu)
        {
        case 1:
            /* code */
            break;
        
        default:
            break;
        }
    }


    return 0;
}