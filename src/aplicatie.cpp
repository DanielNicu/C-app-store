#include "aplicatie.h"

aplicatie::aplicatie(string nume, string categorie)
{
    this->nume=nume;
    this->categorie=categorie;

}
aplicatie::aplicatie(const aplicatie&c)
{
    this->nume = c.nume;
    this->categorie=c.categorie;


}
aplicatie::~aplicatie()
{
    this->nume.erase();
    this->categorie.erase();
}
void aplicatie::afisare()
{
    cout<<this->nume;
}
istream & operator >> (istream &st, aplicatie &x){
    getline(st,x.nume);
    getline(st,x.categorie);
    return st;
}

string aplicatie::getcategorie()
{
    return categorie;
}
string aplicatie::getnume()
{
    return nume;
}

void aplicatie::setnume(string a)
{
    this->nume=a;
}
void aplicatie::setcategorie(string a)
{
    this->categorie=a;
}

