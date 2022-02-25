#ifndef APLICATIE_H
#define APLICATIE_H
#include <iostream>
#include <string.h>
#include <string>
#include <fstream>

using namespace std;

class aplicatie
{
    string nume;
    string categorie;
    public:
        aplicatie(string ="a", string ="a");
        aplicatie(const aplicatie&);
        friend istream & operator >> (istream &, aplicatie &);
        virtual ~aplicatie();
        void afisare();
        void setnume(string );
        void setcategorie(string );
        string getcategorie();
        string getnume();
};

#endif // APLICATIE_H
