#ifndef LISTASASIEDZTWA_H
#define LISTASASIEDZTWA_H
#include "Edge.h"
#include <iostream>
using namespace std;

struct ElementListy
{
    ElementListy *nast;     //Wskaznik na nast wartosc
    int v;                  //Wartosc elementu
    int waga;               //Waga elementu
};

class ListaSasiedztwa
{
private:
    int lwierzcholkow;
    int lkrawedzi;
    ElementListy **tab;

    public:
        ListaSasiedztwa();
        ~ListaSasiedztwa();
        bool Wczytaj(string nazwapliku);
        void UtworzLosowo(signed int ** tmptab, int lwierzcholkow, float gestosc);
        void Wyswietl();
        int getLWierzcholkow() const;
        int getLKrawedzi() const;
        ElementListy** getTab() const;
};

#endif // LISTASASIEDZTWA_H
