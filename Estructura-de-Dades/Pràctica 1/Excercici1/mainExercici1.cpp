#include <iostream>
using namespace std;

/*Autor del codi: Oriol Jiménez Blanco
Github: EntrepaDeFuet
email: orioljb1999@gmail.com
*/

int main(){

    string nom;

    const int LONGITUD = 2;
    string arr_options[] = {"Sortir", "Benvinguda"};

    bool cntrl = true;
    int tria;

    cout << "Hola com et dius?" << endl;
    cin >> nom;

    while (cntrl){
        cout << "Hola " << nom  << ", què vols fer? \n";

        for(int i = 0; i < LONGITUD; i++){
            cout << i+1 << ". " << arr_options[i] << "\n";
        }
        cin >> tria;
        switch(tria){
            case 1: 
                cntrl = false;
                break;
            case 2:
                cout << "Benvingut/da a l'assignatura d'estructura de dades " << nom << "\n";
        }
        
    }


    


    return 0;
}