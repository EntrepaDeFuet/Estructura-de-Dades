#include <iostream>
#include <vector>
#include "Estudiant.cpp"
#include "Professor.cpp"
#include <fstream>
using namespace std;

int menuTriar(){

    string resultat;
    int sel;
    try{
        cin >> resultat;
        sel = std::stoi(resultat);
    } 
    catch(std::invalid_argument& e){
        return 4;
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

void llegirEstudiant(string nom, int any, int matricules,vector <Estudiant> & estudiants ){

    Estudiant estudiantNou(nom,any,matricules);
    estudiants.push_back(estudiantNou);
    estudiantNou.print();

}

void llegirProfessor(string nom, int any,vector <Professor> & professors ){

    Professor profeNou(nom,any);
    professors.push_back(profeNou);
    profeNou.print();
}

void lectura(string nomDoc, vector <Estudiant> &estudiants, vector <Professor> &professors){
    ifstream document(nomDoc);
    char tipus;
    string nom;
    int any, matricules;
    while (!document.eof()){
        document >> tipus;
        document >> nom;
        document >> any;
        switch (tipus)
        {
        case 'E':
            document >> matricules;
            cout << "Estudiant: " << estudiants.size() +1 << endl;
            llegirEstudiant(nom,any,matricules,estudiants);

            break;
        case 'P':
                cout << "Professor: " << professors.size()+1 << endl;
                llegirProfessor(nom,any,professors);
            break;
        
        default:
            break;
        }

        
    }
    
}

int main(){

    bool cntrl = true;
    int menu;
    string nomDoc;
    vector <string> opcions = {"Sortir","Afegir Persona","Llegir document"};
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

            case 3:
                cout << "Com  es diu el fitxer?"<< endl;
    
                cin >> nomDoc;

                lectura(nomDoc,llistaEstudiants, llistaProfessors);
                break;

            default:

                cout << "No t'he entès." << endl;
                
        }


    }
    return 0;
}