#ifndef NASBELLMANFORDMACIERZ_H
#define NASBELLMANFORDMACIERZ_H
#include "MacierzIncydencji.h"

class NSBellmanFordMacierz
{
   int lkrawedzi,lwierzcholkow;                          // Liczba krawêdzi i wierzcho³ków w grafie
    int ** graf;                                          // macierz incydencji
    long long * tablicaKosztowDojscia;                    // Tablica kosztów dojœcia
    int * tablicaPoprzednikow;                          // Tablica poprzedników
public:
    NSBellmanFordMacierz(MacierzIncydencji *m, int vp, int vk);
    ~NSBellmanFordMacierz();
    bool BF(int v);
};

#endif // NASBELLMANFORDMACIERZ_H
