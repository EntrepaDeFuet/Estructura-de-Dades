#include <iostream>
#include <vector>
#include "Estudiant.cpp"

using namespace std;

/*Autor del codi: Oriol Jiménez Blanco
Github: EntrepaDeFuet
email: orioljb1999@gmail.com
*/

void informarEstudiant(vector<Estudiant>& llista){
    string nom;
    int any, matricules;

    cout << "Nom? " << "\n";
    cin >> nom;

    cout << "Any de naixement? " << "\n";
    cin >> any;

    cout << "Assignatures matriculades? " << "\n";
    cin >> matricules;

    Estudiant estudiantNou(nom,any,matricules);
    llista.push_back(estudiantNou);
    estudiantNou.print();
}

int main(){

    bool cntrl = true;
    int tria;
    vector <string> opcions = {"Sortir","Informar estudiant"};
    vector <Estudiant> llista(0);

    while (cntrl){
        cout << "Hola, què vols fer?"<< "\n";

        for(int i = 0; i < opcions.size(); i++){
            cout << i+1 << ". " << opcions[i] << "\n";
        }

        cin >> tria;
        switch(tria){
            case 1: 
                cout << "Fins la propera " << endl;
                cntrl = false;
                break;
            case 2:
                cout << "Estudiant: " << llista.size()+1 << "\n";
                informarEstudiant(llista);
                break;
                
        }
    }



    return 0;
}