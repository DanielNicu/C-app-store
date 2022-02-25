#ifndef CATALOG_H
#define CATALOG_H
#include "aplicatie.h"
using namespace std;
aplicatie a;
class catalog
{
    aplicatie aplic;
    public:
        catalog(aplicatie&p=a);
        virtual ~catalog();
        friend istream & operator >> (istream &, catalog &);
        void afisare();
};

#endif // CATALOG_H
