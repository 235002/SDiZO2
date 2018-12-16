#ifndef NSBELLMANFORDLISTA_H
#define NSBELLMANFORDLISTA_H
#include "ListaSasiedztwa.h"

class NSBellmanFordLista
{
  int lkrawedzi,lwierzcholkow;                          // Liczba krawêdzi i wierzcho³ków w grafie
    ElementListy ** A;                                    // Tablica dynamiczna list s¹siedztwa
    long long * tablicaKosztowDojscia;                    // Tablica kosztów dojœcia
    int * tablicaPoprzednikow;                            // Tablica poprzedników
public:
    NSBellmanFordLista(ListaSasiedztwa *l, int vp, int vk);
    ~NSBellmanFordLista();
    bool BF(int v);
};

#endif // NSBELLMANFORDLISTA_H
