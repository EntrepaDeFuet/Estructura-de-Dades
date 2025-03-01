#include <iostream>
using namespace std;
/*Autor del codi: Oriol Jiménez Blanco
Github: EntrepaDeFuet
email: orioljb1999@gmail.com
*/

class Estudiant
{
private:
    string nom;
    int any;
    int matricules;

public:
    Estudiant();
    void setNom(string nom);
    void setAny(int edat);
    void setMatricules(int matricules);
    Estudiant(string, int , int);
    int getEdat();
    void print();

};


