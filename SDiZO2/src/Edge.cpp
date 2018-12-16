#include "Edge.h"
#include <iostream>
using namespace std;

//Definicje metod klasy Queue

//Konstruktor tworzy lwierzcholkowa tablice heap na kopcu
Queue::Queue(int n)
{
    Heap = new Edge[n];      //Alokowanie tablicy n elementowej
    hpos = 0;                //Pozycja w kopcu
}

//Destruktor usuwa kopiec z pamieci
Queue::~Queue()
{
    delete [] Heap;
}

//Zwraca krawedz z poczatku kopca
Edge Queue::front()
{
    return Heap[0];
}

//push() - umieszcza w kopcu now¹ krawêdŸ i odtwarza strukturê kopca
void Queue::push(Edge e)
{
    int i,j;                        //Zmienne pomocnicze
    lpush++;

    i = hpos++;                     //i ustawiamy na koniec kopca
    j = (i-1) >> 1;                 //obliczamy pozycjê rodzica

    while(i && (Heap[j].weight > e.weight))//Szukamy miejsca w kopcu dla krawedzi e
    {
        Heap[i] = Heap[j];
        i = j;
        j = (i-1) >> 1;
    }
    Heap[i] = e;                    //Wstawienie krawedzi e do kopca
}

//pop() - Metoda usuwa korzen i przywraca jego strukture
void Queue::pop()
{
    int i, j;                       //Zmienne pomocnicze
    Edge e;
    lpop++;

    if(hpos != 0)
    {
        e = Heap[--hpos];

        i = 0;
        j = 1;

        while(j < hpos)
        {
            if((j+1 < hpos) && (Heap[j+1].weight < Heap[j].weight)) j++;
            if(e.weight <= Heap[j].weight)  break;

            Heap[i] = Heap[j];
            i = j;
            j = (j<<1) + 1;
        }
        Heap[i] = e;
    }
}


//Definicje klasy DSStruct
//Konstruktor
DSStruct::DSStruct(int n)
{
    Z = new DSNode[n];          //Tworzymy tablice dla elementow zbiorow
}

//Destruktor
DSStruct::~DSStruct()
{
    delete [] Z;                //Uswanie tablicy ze zbiorami
}

//Wpisanie wartosci v do tablicy Z
void DSStruct::MakeSet(int v)
{
    Z[v].up = v;
    Z[v].rank = 0;
}

//Metoda zwraca indeks reprezentanta zbioru, w ktorym jest wierzcholek v
int DSStruct::FindSet(int v)
{
    if(Z[v].up != v)
    {
        Z[v].up = FindSet(Z[v].up);         //Rekrurencyjne wywolywanie funkcji w celu znalezienia wartosci
    }
    return Z[v].up;
}

//Metoda laczy ze soba zbiory v i u
void DSStruct::UnionSets(Edge e)
{
    int fu, fv;

    fu = FindSet(e.v1);                     //Wyznaczenie korzenia drzewa o wezle u
    fv = FindSet(e.v2);                     //Wyznaczenie korzenia drzewa o wezle v

    if(fu != fv)                            //Korzenie musza byc rozne!
    {
        if(Z[fu].rank > Z[fv].rank)         //Porowanie rangi drzew
        {
            Z[fv].up = fu;                  //fu > fv
        }
        else
        {
            Z[fu].up = fv;                  //fu <= fv
            if(Z[fu].rank == Z[fv].rank) Z[fv].rank++;
        }
    }
}

