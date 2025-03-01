#include <iostream>
using namespace std;
/*Autor del codi: Oriol Jiménez Blanco
Github: EntrepaDeFuet
email: orioljb1999@gmail.com
*/

class Professor
{
private:
    string nom;
    int any;


public:
    Professor();
    void setNom(string nom);
    void setAny(int edat);
    Professor(string, int );
    int getEdat();
    void print();

};