#include "ListaSasiedztwa.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

ListaSasiedztwa::ListaSasiedztwa()
{
    lwierzcholkow = 0;
    lkrawedzi = 0;
    tab = new ElementListy*[0];
}

ListaSasiedztwa::~ListaSasiedztwa()
{
    delete [] tab;
}

//Metoda wczytuje dane z pliku
bool ListaSasiedztwa::Wczytaj(string nazwapliku)
{
    ElementListy *z;
    fstream plik;

    plik.open(nazwapliku.c_str());
    if(plik.good())
    {
    int tmpp, tmpk, tmpw;
    plik >> lkrawedzi;
    plik >> lwierzcholkow;

    tab = new ElementListy*[lwierzcholkow];

    int i;
    for(i=0; i<lwierzcholkow; i++)
        tab[i] = NULL;



        i = 0;
        while(i<lkrawedzi)
        {
            plik >> tmpp >> tmpk >> tmpw;
            z =  new ElementListy;
            z->v = tmpk;
            z->waga = tmpw;
            z->nast = tab[tmpp];
            tab[tmpp] = z;
            i++;
        }
    }
    else
    {
        cout<<"Nie udalo sie otworzyc pliku."<<endl;
        return false;
    }
    plik.close();
    return true;
}

//Metoda uzupelnia liste losowymi wartosciami
void ListaSasiedztwa::UtworzLosowo(signed int ** tmptab, int lwierzcholkow, float gestosc)
{
    ElementListy *z;
    //int tmpp, tmpk, tmpw;
    this->lwierzcholkow = lwierzcholkow;
    lkrawedzi = floor((gestosc*(lwierzcholkow*(lwierzcholkow-1)))/2);

    tab = new ElementListy*[lwierzcholkow];

    for(int i=0; i<lwierzcholkow; i++)
        tab[i] = NULL;

    srand(time(NULL));

    for(int i=0; i<lwierzcholkow; i++)
    {
        for(int j=0; j<lkrawedzi; j++)
        {
            if(tmptab[i][j]>0)
            {
                for(int k=0; k<lwierzcholkow; k++)
                {
                    z = new ElementListy;
                    z->v = (rand()+0);
                    z->waga = tmptab[i][j];
                    z->nast = tab[i];
                    tab[i] = z;
                    break;
                }
            }
        }
    }
}

//Metoda wyswietla liste
void ListaSasiedztwa::Wyswietl()
{
    ElementListy *z;
    for(int i=0; i<lwierzcholkow; i++)
    {
        cout<<"Wierzcholek: "<<i<<" - ";
        z = tab[i];
        while(z)
        {
            cout<<setw(3)<<" waga: "<<z->waga<<" wartosc: "<<z->v;
            z = z->nast;
        }
        cout<<endl;
    }
}

//Metoda zwraca ilosc wierzcholkow
int ListaSasiedztwa::getLWierzcholkow()const
{
    return lwierzcholkow;
}

//Metoda zwraca ilosc krawedzi
int ListaSasiedztwa::getLKrawedzi()const
{
    return lkrawedzi;
}

//Metoda zwraca wskaznik na tablice wskaznikow ?!?
ElementListy** ListaSasiedztwa::getTab()const
{
    return tab;
}







