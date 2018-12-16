#ifndef NAJKROTSZASCIEZKAMACIERZ_H
#define NAJKROTSZASCIEZKAMACIERZ_H
#include "MacierzIncydencji.h"
#include "ListaSasiedztwa.h"

class NajkrotszaSciezkaMacierz
{
private:
    int lkrawedzi;
    int lwierzcholkow;
    int wierzcholek;
    int wierzcholekU;
    int sptr;
    int *tablicaKosztowDojscia;
    int *tablicaPoprzednikow;
    int *S;
    bool *QS;                       // Zbiory Q i S
    int **graf;                    // macierz incydencji
public:
    NajkrotszaSciezkaMacierz(MacierzIncydencji *m, int vp, int vk);
    ~NajkrotszaSciezkaMacierz();
};

#endif // NAJKROTSZASCIEZKAMACIERZ_H
