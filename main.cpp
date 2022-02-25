#include <iostream>
#include <conio.h>
#include <string>
#include "aplicatie.h"
#include "utilizator.h"
using namespace std;
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
ifstream fin;
ifstream gin;
ifstream hin;
ofstream gout;
ofstream hout;
aplicatie s[100];
utilizator s2[100];
int data[100][100];
int n,m,q=0;
void date()
{
    hin.open("c.txt");
    int i,j;
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            hin>>data[i][j];
    hin.close();
}
bool logare(int &i)
{
    cout<<"Va rog introduceti numele de utilizator si parola."<<endl;
    utilizator a;
    cin>>a;
    for(i=0; i<m; i++)
    {
        if(a==s2[i])
        {
            return true;
        }
    }
    return false;
}
void k()
{
    fin.open("a.txt");
    int i;
    fin>>n;
    fin.ignore();
    for(i=0; i<n; i++)
        fin>>s[i];
    fin.close();
}
void k2()
{
    gin.open("b.txt");
    int i;
    gin>>m;
    gin.ignore();
    for(i=0; i<m; i++)
        gin>>s2[i];
    gin.close();
}
int meniu()
{
    int i=0;
    char ch=0;
    while(ch!='\r')
    {
        system("@cls||clear");
        if(ch==72 && i!=0)
            i--;
        if(ch==80 && i!=4)
            i++;
        cout<<"Sistem de gestionare a aplicatiilor"<<endl<<endl;
        cout<<"1.Catalog aplicatii ";
        if(i==0)
            cout<<"<--";
        cout<<endl;
        cout<<"2.Vizualizare aplicatii ";
        if(i==1)
            cout<<"<--";
        cout<<endl;
        cout<<"3.Dezinstalare aplicatii ";
        if(i==2)
            cout<<"<--";
        cout<<endl;
        cout<<"4.Statistici ";
        if(i==3)
            cout<<"<--";
        cout<<endl;
        cout<<"5.Iesire ";
        if(i==4)
            cout<<"<--";
        cout<<endl;
        ch=getch();
    }
    return i;
}
int categorii()
{
    int i=0;
    char ch=0;
    while(ch!='\r')
    {
        system("@cls||clear");
        if(ch==72 && i!=0)
            i--;
        if(ch==80 && i!=4)
            i++;
        cout<<"Selectati categoria"<<endl<<endl;
        cout<<"1.Entertainment ";
        if(i==0)
            cout<<"<--";
        cout<<endl;
        cout<<"2.Social ";
        if(i==1)
            cout<<"<--";
        cout<<endl;
        cout<<"3.Productivity ";
        if(i==2)
            cout<<"<--";
        cout<<endl;
        cout<<"4.Health ";
        if(i==3)
            cout<<"<--";
        cout<<endl;
        cout<<"5.Inapoi la meniu ";
        if(i==4)
            cout<<"<--";
        cout<<endl;
        ch=getch();
    }
    return i;
}
int inceput(int o)
{
    int i=1;
    char ch=0;
    while(ch!='\r')
    {
        system("@cls||clear");
        if(ch==72 && i!=1)
            i--;
        if(ch==80 && i!=2)
            i++;
        if (o==0)
            cout<<"Bine ati venit! "<<endl<<endl;
        else
            cout<<"Datele introduse nu sunt corecte."<<endl<<endl;
        cout<<"1.Conectare ";
        if(i==1)
            cout<<"<--";
        cout<<endl;
        cout<<"2.Inregistrare ";
        if(i==2)
            cout<<"<--";
        cout<<endl;
        ch=getch();
    }
    return i;
}
int instalare(string a, int q)
{
    int i=1;
    int z=1;
    int j, lol ;
    int data2[100]= {0};
    for(j=0; j<n; j++)
    {
        if(data[q][j]==0 && a==s[j].getcategorie())
        {
            data2[j]=z;
            z++;
        }
    }
    while(i!=n)
    {
        char ch=0;
        while(ch!='\r')
        {
            system("@cls||clear");
            if(ch==72 && i!=1)
                i--;
            if(ch==80 && i!=z)
                i++;
            cout<<"Catalog de aplicatii din categoria "<<a<<endl<<endl;
            for(j=0; j<n; j++)
            {
                if(data[q][j]==0 && a==s[j].getcategorie())
                {
                    s[j].afisare();
                    if(i==data2[j])
                        cout<<" <--";
                    cout<<endl;
                }
            }
            cout<<"Inapoi ";
            if(i==z)
                cout<<"<--";
            ch=getch();
        }
        if(i==z)
            return 0;
        for(j=0; j<n; j++)
        {
            if(i==data2[j])
            {
                lol=j;
                break;


            }
        }

        i=1;
        ch=0;
        while(ch!='\r')
        {
            system("@cls||clear");
            if(ch==72 && i!=1)
                i--;
            if(ch==80 && i!=2)
                i++;
            cout<<"Sunteti sigur ca doriti sa instalati acceasta aplicatie?"<<endl<<endl;
            cout<<"Da";
            if(i==1)
                cout<<" <--";
            cout<<endl;
            cout<<"Nu";
            if(i==2)
                cout<<" <--";
            ch=getch();
        }
        if(i==1)
        {
            data[q][lol]=1;
            hout.open("c.txt");
            int t,top;
            for(t=0; t<m; t++)
            {
                for(top=0; top<n; top++)
                    hout<<data[t][top]<<" ";
                hout<<endl;
            }
            hout.close();

            ch=0;
            while(ch!='\r')
            {
                system("@cls||clear");
                cout<<"Aplicatia a fost instalata cu succes!"<<endl;
                cout<<"Apasati tasta enter pentru a reveni la meniu.";
                ch=getch();
            }
            return 1;
        }

    }
    return 0;
}
int vizualizare(string a, int q)
{
    char ch=0,ok=0;
    int j;
    while(ch!='\r')
    {
        system("@cls||clear");
        cout<<"Aplicatiile instalate din categoria "<<a<<endl<<endl;
        for(j=0; j<n; j++)
        {
            if(data[q][j]==1 && a==s[j].getcategorie())
            {
                s[j].afisare();
                cout<<endl;
                ok=1;
            }
        }
        if(ok==0)
            cout<<"Nu exista aplicatii instalate in aceasta categorie."<<endl;
        cout<<"Apasati enter pentru a va intoarce la meniu";
        ch=getch();
    }
    return 1;
}
int dezinstalare(string a, int q)
{
    int i=1;
    int z=1;
    int j, lol ;
    int data2[100]= {0};
    for(j=0; j<n; j++)
    {
        if(data[q][j]==1 && a==s[j].getcategorie())
        {
            data2[j]=z;
            z++;
        }
    }
    while(i!=n)
    {
        char ch=0;
        while(ch!='\r')
        {
            system("@cls||clear");
            if(ch==72 && i!=1)
                i--;
            if(ch==80 && i!=z)
                i++;
            cout<<"Catalog de aplicatii din categoria "<<a<<endl<<endl;
            for(j=0; j<n; j++)
            {
                if(data[q][j]==1 && a==s[j].getcategorie())
                {
                    s[j].afisare();
                    if(i==data2[j])
                        cout<<" <--";
                    cout<<endl;
                }
            }
            cout<<"Inapoi ";
            if(i==z)
                cout<<"<--";
            ch=getch();
        }
        if(i==z)
            return 0;
        for(j=0; j<n; j++)
        {
            if(i==data2[j])
            {
                lol=j;
                break;


            }
        }

        i=1;
        ch=0;
        while(ch!='\r')
        {
            system("@cls||clear");
            if(ch==72 && i!=1)
                i--;
            if(ch==80 && i!=2)
                i++;
            cout<<"Sunteti sigur ca doriti sa dezinstalati acceasta aplicatie?"<<endl<<endl;
            cout<<"Da";
            if(i==1)
                cout<<" <--";
            cout<<endl;
            cout<<"Nu";
            if(i==2)
                cout<<" <--";
            ch=getch();
        }
        if(i==1)
        {
            data[q][lol]=0;
            hout.open("c.txt");
            int t,top;
            for(t=0; t<m; t++)
            {
                for(top=0; top<n; top++)
                    hout<<data[t][top]<<" ";
                hout<<endl;
            }
            hout.close();

            ch=0;
            while(ch!='\r')
            {
                system("@cls||clear");
                cout<<"Aplicatia a fost dezinstalata cu succes!"<<endl;
                cout<<"Apasati tasta enter pentru a reveni la meniu.";
                ch=getch();
            }
            return 1;
        }

    }
    return 0;
}
int statistici(int q)
{
    system("@cls||clear");
    int j=0,i;
    cout<<"Statisticile utilizatorului: ";
    s2[q].afisare();
    cout<<endl<<endl;
    for(i=0; i<n; i++)
    {
        if(data[q][i]==1)
            j=j+1;
    }
    cout<<"Aveti un total de "<<j<<" aplicatii instalate."<<endl;
    cout<<"Dintre care:"<<endl;
    j=0;
    for(i=0; i<n; i++)
    {
        if(data[q][i]==1 && s[i].getcategorie()=="Entertainment")
            j=j+1;
    }
    cout<<"-> "<<j<<" aplicatii de Entertainment"<<endl;
    j=0;
    for(i=0; i<n; i++)
    {
        if(data[q][i]==1 && s[i].getcategorie()=="Social")
            j=j+1;
    }
    cout<<"-> "<<j<<" aplicatii de Social"<<endl;
    j=0;
    for(i=0; i<n; i++)
    {
        if(data[q][i]==1 && s[i].getcategorie()=="Productivity")
            j=j+1;
    }
    cout<<"-> "<<j<<" aplicatii de Productivity"<<endl;
    j=0;
    for(i=0; i<n; i++)
    {
        if(data[q][i]==1 && s[i].getcategorie()=="Health")
            j=j+1;
    }
    cout<<"-> "<<j<<" aplicatii de Health"<<endl;
    char ch=0;
    cout<<"Apasati tasta enter pentru a va intoarce la meniu.";
    while(ch!='\r')
    {
        ch=getch();
    }
    return 0;

}
int main()
{
    k();
    k2();
    int i=0,j=0,h=0,o=0,z=0;
    bool log=false;
    string a;
    date();
    system("@cls||clear");
    while(o!=3)
    {
        z=0;
        o=inceput(o);
        if(o==1)
        {
            system("@cls||clear");
            log=logare(q);
            system("@cls||clear");
            if(log==false)
                cout<<"Datele introduse nu sunt corecte."<<endl<<endl;
            else
                o=3;
        }
        if(o==2)
        {
            system("@cls||clear");
            cin>>s2[m];
            for(i=0; i<m; i++)
            {
                if(s2[m].getutilizat()==s2[i].getutilizat())
                {
                    system("@cls||clear");
                    char ch=0;
                    while(ch!='\r')
                    {
                        cout<<"Utilizatorul deja exista"<<endl<<"Apasati enter pentru a va intoarce la logare!";
                        ch=getch();
                    }
                    z=1;
                }
            }
            if(z!=1)
            {
                m=m+1;
                q=m-1;
                gout.open("b.txt");
                hout.open("c.txt");
                gout<<m<<endl;
                for(i=0; i<m; i++)
                {
                    gout<<s2[i].getutilizat()<<endl;
                    gout<<s2[i].getparola();
                    if(i!=m-1)
                        gout<<endl;
                }
                for(i=0; i<m; i++)
                {
                    for(j=0; j<n; j++)
                        hout<<data[i][j]<<" ";
                    hout<<endl;
                }
                gout.close();
                hout.close();
                o=3;
            }
        }
    }
    i=0;

    while(i!=4)
    {
        i=meniu();
        j=0;
        if(i==0)
        {
            while(j!=4)
            {
                j=categorii();
                if(j==0)
                    a="Entertainment";
                if(j==1)
                    a="Social";
                if(j==2)
                    a="Productivity";
                if(j==3)
                    a="Health";
                if(j!=4)
                    h=instalare(a,q);
                if(h==1)
                    j=4;
            }
        }
        if(i==1)
        {
            while(j!=4)
            {
                j=categorii();
                if(j==0)
                    a="Entertainment";
                if(j==1)
                    a="Social";
                if(j==2)
                    a="Productivity";
                if(j==3)
                    a="Health";
                if(j!=4)
                    h=vizualizare(a,q);
                if(h==1)
                    j=4;
            }
        }
        if(i==2)
        {
            while(j!=4)
            {
                j=categorii();
                if(j==0)
                    a="Entertainment";
                if(j==1)
                    a="Social";
                if(j==2)
                    a="Productivity";
                if(j==3)
                    a="Health";
                if(j!=4)
                    h=dezinstalare(a,q);
                if(h==1)
                    j=4;
            }
        }
        if(i==3)
        {
            h=statistici(q);
        }

    }
    system("@cls||clear");
    cout<<"O zi buna!";
}
