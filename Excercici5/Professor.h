#include <iostream>
using namespace std;

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