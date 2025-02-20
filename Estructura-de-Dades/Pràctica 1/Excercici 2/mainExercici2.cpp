#include <iostream>
#include <vector>
using namespace std;

int main(){

    vector <string> opcions = {"Sortir","Benvinguda","Redefinir nom"};

    string nom;

    bool cntrl = true;
    int tria;

    cout << "Hola com et dius?" << endl;
    cin >> nom;

    while (cntrl){
        cout << "Hola " << nom  << ", què vols fer? \n";

        for(int i = 0; i < opcions.size(); i++){
            cout << i+1 << ". " << opcions[i] << "\n";
        }
        cin >> tria;
        switch(tria){
            case 1: 
                cntrl = false;
                break;
            case 2:
                cout << "Benvingut/da a l'assignatura d'estructura de dades " << nom << "\n";
                break;
            case 3:
                cout << "Hola com et dius?" << endl;
                cin >> nom;
                break;
        }
       
    }
    return 0;
}