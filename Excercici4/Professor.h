#include <iostream>
using namespace std;

class Professor
{
private:
    string nom;
    int any;


public:
    Professor();
    Professor(string, int );
    int getEdat();
    void print();

};