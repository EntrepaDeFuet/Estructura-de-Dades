#include <iostream>
#include <vector>
#include "Estudiant.cpp"
#include "Professor.cpp"
using namespace std;

int menuTriar(){

    string resultat;
    int sel;
    try{
        cin >> resultat;
        sel = std::stoi(resultat);
    } 
    catch(std::invalid_argument& e){
        return 3;
    }
    catch(std::exception& e){
        return 1000;
    }

    return sel;
}


char ProfessorVsEstudiant(){
    cout << "Per a afegir un Professor escriu 'P' i per a afegir a un estudiant escriu 'E'. " << endl;
    char sel;
    try{
        cin >> sel;
    }catch(std::invalid_argument& e){
        return 'a';
    }
    return sel;
}

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

void informarProfessor( vector <Professor> & llista){
    string nom;
    int any;

    cout << "Nom? " << "\n";
    cin >> nom;

    cout << "Any de naixement? " << "\n";
    cin >> any;

    Professor profeNou(nom,any);
    llista.push_back(profeNou);
    profeNou.print();
}


int main(){

    bool cntrl = true;
    int menu;
    vector <string> opcions = {"Sortir","Afegir Persona"};
    vector <Estudiant> llistaEstudiants(0);
    vector <Professor> llistaProfessors(0);

    while (cntrl){
        cout << "Hola, què vols fer?"<< "\n";

        for(int i = 0; i < opcions.size(); i++){
            cout << i+1 << ". " << opcions[i] << "\n";
        }

        menu = menuTriar();

        switch(menu){
            case 1: 

                cout << "Fins la propera " << endl;
                cntrl = false;
                break;

            case 2:

                switch(ProfessorVsEstudiant()){
                    case 'E':
                        cout << "Estudiant: " << llistaEstudiants.size() +1 << endl;
                        informarEstudiant(llistaEstudiants);                         
                        break;
                    case 'P':
                        cout << "Professor: " << llistaProfessors.size()+1 << endl;
                        informarProfessor(llistaProfessors);
                        break;
                    default:
                        cout << "No t'he entès." << endl;

                }
                break;

            default:

                cout << "No t'he entès." << endl;
                
        }


    }
    return 0;
}