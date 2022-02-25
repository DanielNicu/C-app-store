#include "catalog.h"

catalog::catalog(aplicatie&p)
{
    this->aplic.setnume(p.getnume());
    this->aplic.setcategorie(p.getcategorie());
}

catalog::~catalog()
{

}
istream & operator >> (istream &st, catalog &x){
    string nume, categorie;
    getline(st,nume);
    getline(st,categorie);
    x.aplic.setnume(nume);
    x.aplic.setcategorie(categorie);
    return st;
}
void catalog::afisare(){
    cout<<this->aplic.getnume();
}
