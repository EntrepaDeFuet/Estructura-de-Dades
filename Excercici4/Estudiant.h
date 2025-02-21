#include <iostream>
using namespace std;

class Estudiant
{
private:
    string nom;
    int any;
    int matricules;

public:
    Estudiant();
    Estudiant(string, int , int);
    int getEdat();
    void print();

};


