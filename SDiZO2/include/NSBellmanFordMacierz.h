#ifndef NSBELLMANFORDMACIERZ_H
#define NSBELLMANFORDMACIERZ_H


#include "MacierzIncydencji.h"

class NSBellmanFordMacierz {
    int lkrawedzi,lwierzcholkow;                          // Liczba krawędzi i wierzchołków w grafie
    int ** graf;                                          // macierz incydencji
    long long * tablicaKosztowDojscia;                    // Tablica kosztów dojścia
    int * tablicaPoprzednikow;                          // Tablica poprzedników
public:
    NSBellmanFordMacierz(MacierzIncydencji *m, int vp, int vk);
    ~NSBellmanFordMacierz();
    bool BF(int v);
};

#endif // NSBELLMANFORDMACIERZ_H
