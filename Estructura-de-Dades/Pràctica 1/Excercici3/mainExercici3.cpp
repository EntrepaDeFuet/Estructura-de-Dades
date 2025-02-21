#include <iostream>
#include <vector>
#include "Estudiant.cpp"

using namespace std;

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
                cntrl = false;
                break;
            case 2:
                informarEstudiant(llista);
                cout << llista.size() << "\n";
                break;
                
        }
    }



    return 0;
}