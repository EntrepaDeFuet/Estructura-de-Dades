#include <iostream>
#include <stdexcept>
#include "Peli.cpp"
#include "Director.cpp"
#include <fstream>
using namespace std;

int menu(){
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

void afegirDirector(vector <Director> & directors){

    string nom;
    int id,genere;

    cout << "Quin és el nom del director? " << endl;
    cin >> nom;

    cout << "Quina és la seva id? " << endl;
    cin >> id;
    
}

int main(){


    return 0;
}