#ifndef NSBELLMANFORDLISTA_H
#define NSBELLMANFORDLISTA_H
#include "ListaSasiedztwa.h"

class NSBellmanFordLista
{
  int lkrawedzi,lwierzcholkow;                          // Liczba kraw�dzi i wierzcho�k�w w grafie
    ElementListy ** A;                                    // Tablica dynamiczna list s�siedztwa
    long long * tablicaKosztowDojscia;                    // Tablica koszt�w doj�cia
    int * tablicaPoprzednikow;                            // Tablica poprzednik�w
public:
    NSBellmanFordLista(ListaSasiedztwa *l, int vp, int vk);
    ~NSBellmanFordLista();
    bool BF(int v);
};

#endif // NSBELLMANFORDLISTA_H
