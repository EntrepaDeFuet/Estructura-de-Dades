#include <iostream>
#include <stdexcept>
#include "Director.cpp"
#include <fstream>
using namespace std;


/*Autor del codi: Oriol Jiménez Blanco
Github: EntrepaDeFuet
email: orioljb1999@gmail.com
*/

// Aquesta funció es per verificar l'entrada que em donen del menú.
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

/*Aquesta funció l'he fet amb l'objectiu de verificar les Id que demano a través del main.*/
int correctorEntrada(){

    int sortida;
    cin >> sortida;
    // Aquest bloc revisa que no s'enviin Id's negatives.
    if(sortida < 0){
        throw invalid_argument ("No es pot establir una Id com a valor negatiu. S'ha establert la Id per defecte.");
        return 0000;
    } else{
        return sortida;
    }
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

void afegirDirector(vector <Director> & directors, vector <int> & pelis){

    string nom;
    int id,genere;

    cout << "Quin és el nom del director? " << endl;
    cin >> nom;
    
    cout << "Quina és la seva id? " << endl;
    cin >> id;

    if (id < 0){

        throw invalid_argument("La id del director no pot ser negativa. S'establirà la id per defecte." );
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




void retirarDeLlista(vector <int> &pelis,int id){
    for (int i = 0; i < pelis.size() && pelis[i] != id; i++){
        if (pelis[i]==id){
            pelis.erase(pelis.begin()+i);
        }
    }
}

void eliminarPeli(vector <Director>& directors, vector <int>& pelis, int id, int peliId){

    bool existeixDirector = false;
    int indexDirector, indexPelis;

    for (int i = 0; i<directors.size() && !existeixDirector ; i++ ){
        
        if (directors[i].getDirectorId()==id){
            existeixDirector = true;
            indexDirector = i;
        }

    }

    if (existeixDirector && peliRepetida(pelis, peliId)){
        
        directors[indexDirector].removePeli(peliId);
        retirarDeLlista(pelis, peliId);
        
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
        try{
            afegirPeliDirectorNou(directors[index], pelis);
        } catch (invalid_argument &e){
            cout << e.what() << endl;
        }

    } else {

        cout << "La id proporcionada no coincideix amb la de cap director. " << endl;

    }


}

void imprimirDirectors(vector <Director> & directors){


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

void eliminarDirector (vector <int> & pelis, vector <Director> & directors, int directorId){

    bool existeixDirector = false;
    int indexDirector;

    for (int i = 0; i < directors.size() && !existeixDirector; i++){
        if (directors[i].getDirectorId() == directorId){    
            indexDirector = i;
            existeixDirector = true;
        }
    }
    if (existeixDirector){

        cout << "S'eliminarà el següent director: " <<  endl;
        directors[indexDirector].print();

        /*El codi escrit a continuació es fa per extreure les id de les pelis del vector de id's general de pelis. Mencionat al main().
        Pot ser és l'únic punt del programa on la complexitat arriba a O(n^2).*/
        vector <Peli> pelisDirector = directors[indexDirector].getPelis();

        for (int i = 0 ; i < pelisDirector.size() ; i++){
            retirarDeLlista(pelis,pelisDirector[i].getPeliId());
        }

        /*El codi següent ja no és degut a aquest afegit que he incorporat. Simplement esborrar el director.*/

        directors.erase(directors.begin()+indexDirector);

    } else {

        throw invalid_argument("La id introduïda no coincideix amb la de cap director.");

    }
}

int main(){
    //aquests ints els faig servir per a revisar que em passin be les id quan les demano aqui al main en comptes de a les funcions.
    int menu,comprovadorId, comprovadorIdAux;
    bool loop = true;

    /* M'he pres la llibertat d'afegir aquesta llista d'ids de pelis, doncs trobo que amb el codi proposat tenim control sobre que no hi 
    hagi id's repetides en el mateix director, pero dues pelis de dos directors diferents podien tindre la mateixa id, cosa que no tenia
    sentit per a mi. Per tant he afegit aquesta llista de id's per a que no passi.
    
    Això fa que algunes funcions del main siguin una mica més enrevessades, però al meu parer el programa té més sentit així.*/
    vector <int> pelis;

    /*També vull comentar el fet de que pot ser per a millorar el encapsulament hagués estat bé fer una classe mUBieflix que contingués els
    directors i les pel·licules. No ho he volgut implementar, doncs això si que s'allunyaria bastant del codi demanat.*/
    vector <Director> directors;
    vector <string> opcions = {"Afegir director","Eliminar director","Afegir peli a un director","Eliminar peli d'un director","Imprimir directors mUBiesflix","Imprimir les pelis d'un director","Sortir"};

    while(loop) {

        cout << "Benvingut a mUBiesflix, escull una opció del menú: "<< "\n";

        for(int i = 0; i < opcions.size(); i++){
            cout << (i+1)%7 << ". " << opcions[i] << "\n";
        }


        menu = triaMenu();

        switch (menu)
        {
        case 0:

            cout << "Es finalitzarà la sessió, que tinguis bon dia." << endl;
            loop = false;
            
            break;
        case 1:

            try{
                afegirDirector(directors,pelis);
            } catch(std::invalid_argument& e){
                cout << e.what() << endl;
            }
            
            break;
        case 2:

            cout << "Digues la Id del director a eliminar siusplau." << endl;
            comprovadorId = correctorEntrada();
            
            try{
                eliminarDirector(pelis,directors,comprovadorId);
            }catch(std::invalid_argument &e){
                cout << e.what() << endl;
            }
            
            break;
        case 3:
            
            afegirPeli(directors,pelis);
            
            break;
        case 4:
            cout << "Introdueix la Id del director siusplau. " << endl;
            comprovadorId = correctorEntrada();
            cout << "Introdueix la Id de la peli siusplau. " << endl;
            comprovadorIdAux = correctorEntrada();
            eliminarPeli(directors,pelis, comprovadorId, comprovadorIdAux);
            
            break;
        case 5:

            imprimirDirectors(directors);
            break;
        case 6:
            cout << "Introdueix la Id del director siusplau. " << endl;
            comprovadorId = correctorEntrada();
            imprimirPelis(directors, comprovadorId);
            break;
        
        default:
        cout << "Ho sento, no t'he entès." << endl;
            break;
        }
    }


    return 0;
}