#ifndef NAJKROTSZASCIEZKALISTA_H
#define NAJKROTSZASCIEZKALISTA_H
#include "ListaSasiedztwa.h"

class NajkrotszaSciezkaLista
{
private:
    int lwierzcholkow;
    int wierzcholek;
    int wierzcholekU;
    int sptr;
    int *tablicaKosztowDojscia;
    int *tablicaPoprzednikow;
    int *S;
    bool *QS;                       // Zbiory Q i S
    ElementListy **graf;            // Tablica list s¹siedztwa
    ElementListy *pw;
    ElementListy *rw;

public:
    NajkrotszaSciezkaLista(ListaSasiedztwa *l, int vp, int vk);
   ~NajkrotszaSciezkaLista();
};

#endif // NAJKROTSZASCIEZKALISTA_H
