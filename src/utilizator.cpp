#include "utilizator.h"

utilizator::utilizator(string utilizat, string parola)
{
    this->utilizat=utilizat;
    this->parola=parola;


}
utilizator::utilizator(const utilizator&c)
{
    this->utilizat = c.utilizat;
    this->parola=c.parola;

}
utilizator::~utilizator()
{
    this->utilizat.erase();
    this->parola.erase();
}
void utilizator::afisare()
{
    cout<<this->utilizat;
}
string utilizator::getutilizat()
{
    return utilizat;
}
string utilizator::getparola()
{
    return parola;
}
bool operator ==( utilizator&c1,  utilizator&c2){
    bool h=(c1.getutilizat() == c2.getutilizat()) && (c1.getparola() == c2.getparola());
    return h;
}
istream & operator >> (istream &st, utilizator &x){
    cout<<"Nume utilizator: ";
    getline(st,x.utilizat);
    cout<<"Parola: ";
    getline(st,x.parola);

    return st;
}
