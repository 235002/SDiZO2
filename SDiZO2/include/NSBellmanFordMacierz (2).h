#ifndef NASBELLMANFORDMACIERZ_H
#define NASBELLMANFORDMACIERZ_H
#include "MacierzIncydencji.h"

class NSBellmanFordMacierz
{
   int lkrawedzi,lwierzcholkow;                          // Liczba kraw�dzi i wierzcho�k�w w grafie
    int ** graf;                                          // macierz incydencji
    long long * tablicaKosztowDojscia;                    // Tablica koszt�w doj�cia
    int * tablicaPoprzednikow;                          // Tablica poprzednik�w
public:
    NSBellmanFordMacierz(MacierzIncydencji *m, int vp, int vk);
    ~NSBellmanFordMacierz();
    bool BF(int v);
};

#endif // NASBELLMANFORDMACIERZ_H
