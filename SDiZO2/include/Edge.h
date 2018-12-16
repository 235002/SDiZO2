#ifndef EDGE_H
#define EDGE_H


struct Edge{
    int v1,v2,weight;         //Wierzcho³ki krawêdzi, waga krawêdzi
};


//Definicja klasy kolejki priorytetowej
class Queue{
private:
    Edge *Heap;
    int hpos;
public:
    Queue(int n);
    ~Queue();
    Edge front();
    void push(Edge e);
    void pop();
    int lpush = 0;                       //Liczba wstawieñ
    int lpop = 0;                        //Liczba usuniêæ
};


//Definicja struktury zbiorów roz³¹cznych
struct DSNode{
    int up, rank;
};

class DSStruct{
private:
    DSNode *Z;
public:
    DSStruct(int n);
    ~DSStruct();
    void MakeSet(int v);
    int FindSet(int v);
    void UnionSets(Edge e);
};

#endif // EDGE_H
