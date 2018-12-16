#ifndef MSTTREELISTA_H
#define MSTTREELISTA_H
#include <Edge.h>
#include "ListaSasiedztwa.h"


class MSTTreeLista
{
private:
    ElementListy **A;
    //ListaSasiedztwa B;
    int Alen;               //liczba komorek w tablicy
    int weight;             //Waga calego drzewa

public:
    MSTTreeLista(int n);
    ~MSTTreeLista();
    void addEdge(Edge e);
    void print();
    MSTTreeLista(ListaSasiedztwa *l, int alg);
    ElementListy * getAList(int n);
};

#endif // MSTTREELISTA_H
