#ifndef UTILIZATOR_H
#define UTILIZATOR_H
#include <iostream>
#include <string.h>
#include <string>
#include <fstream>

using namespace std;

class utilizator
{
    string utilizat;
    string parola;
    int instalat[200];
    public:
        utilizator(string="a",string="a");
        virtual ~utilizator();
        utilizator(const utilizator&);
        friend istream & operator >> (istream &, utilizator &);
        void afisare();
        string getutilizat();
        string getparola();
        friend bool operator ==( utilizator&,  utilizator&);
};

#endif // UTILIZATOR_H
