#ifndef MSTTREEMACIERZ_H
#define MSTTREEMACIERZ_H


#include <iostream>
#include "MacierzIncydencji.h"
#include "Edge.h"

class MSTTreeMacierz {
private:
    int **A;      // macierz incydencji
    //MacierzIncydencji M;
    int Alen;                     // Liczba komórek w tablicy
    int weight;                   // Waga ca³ego drzewa
public:
    //int ** tablica1;
    int licznikK=0;
    bool *visited;
    MSTTreeMacierz(int n);
    ~MSTTreeMacierz();
    void addEdge(Edge e);
    void printMacierz();
    MSTTreeMacierz(MacierzIncydencji *m, int alg);

};

#endif // MSTTREEMACIERZ_H
