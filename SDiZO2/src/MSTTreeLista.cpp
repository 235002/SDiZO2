#include "MSTTreeLista.h"

MSTTreeLista::MSTTreeLista(int n) {             // Konstruktor - tworzy tablicê pustych list s¹siedztwa
    A=new ElementListy * [n];                 // Tworzymy tablicê dynamiczn¹
    for(int i = 0; i < n; i++) {              // i wype³niamy j¹ pustymi listami
        A[i] = NULL;
    }
    Alen = n - 1;                   // Zapamiêtujemy d³ugoœæ tablicy
    weight = 0;                     // Zerujemy wagê drzewa
}




MSTTreeLista::~MSTTreeLista() {                 // Destruktor - usuwa listy oraz tablicê s¹siedztwa
    //cout<<"\nWykonuje sie destruktor drzewa listowego\n";
    ElementListy *p, *r;
    for(int i = 0; i <= Alen; i++) {
        p = A[i];
        while(p) {
            r = p;                      // Zapamiêtujemy wskazanie
            p = p->nast;                // Przesuwamy siê do nastêpnego elementu listy
            delete r;                   // Usuwamy element
        }
    }
    delete [] A;                    // Usuwamy tablicê list s¹siedztwa
}


ElementListy *MSTTreeLista::getAList(int n) {
    return A[n];
}

void MSTTreeLista::addEdge(Edge e) {      // Dodaje krawêdŸ do drzewa
    ElementListy *p;
    weight += e.weight;             // Do wagi drzewa dodajemy wagê krawêdzi
    p = new ElementListy;                  // Tworzymy nowy wêze³
    p->v = e.v2;                    // Wierzcho³ek koñcowy
    p->waga = e.weight;           // Waga krawêdzi
    p->nast = A[e.v1];              // Dodajemy p do listy wierzcho³ka v1
    A[e.v1] = p;

    p = new ElementListy;                  // To samo dla krawêdzi odwrotnej
    p->v = e.v1;                    // Wierzcho³ek koñcowy
    p->waga = e.weight;           // Waga krawêdzi
    p->nast = A[e.v2];              // Dodajemy p do listy wierzcho³ka v2
    A[e.v2] = p;
}



void MSTTreeLista::print() {              // Wyœwietla zawartoœæ drzewa oraz jego wagê
    ElementListy *p;

    cout << endl;
    for(int i = 0; i <= Alen; i++) {
        cout << "Wierzcholek " << i << " - ";
        for(p = A[i]; p; p = p->nast) {
            cout<< " waga:" << p->waga<<" do wierzcholka " << p->v<<";";
        }
        cout << endl;
    }
    cout << endl << endl << "Waga minimalnego drzewa rozpinajacego = " << weight << endl << endl;
}





MSTTreeLista::MSTTreeLista(ListaSasiedztwa *l, int alg) {
    if(alg==1) {                                //MSTTreeLista algorytmem Kruska z listy
        int lwGrafu = l->getLWierzcholkow();
        int lkGrafu = l->getLKrawedzi();
        Edge e;
        DSStruct Z(lwGrafu);
        Queue Q(lkGrafu);
        MSTTreeLista T(lwGrafu);
        ElementListy **tab = l->getTab();
        ElementListy *p;

        for (int i = 0; i < lwGrafu; i++) {
            Z.MakeSet(i);
        }

        for (int j = 0; j < lwGrafu; j++) {
            p=tab[j];
            while (p) {
                e.v1 = j;
                e.v2 = p->v;
                e.weight = p->waga;
                Q.push(e);
                p = p->nast;
            }
        }

        for (int i = 1; i < lwGrafu; i++) {          // Pêtla wykonuje siê n - 1 razy !!!
            do {
                e = Q.front();              // Pobieramy z kolejki krawêdŸ
                Q.pop();                    // KrawêdŸ usuwamy z kolejki
            } while (Z.FindSet(e.v1) == Z.FindSet(e.v2));
            T.addEdge(e);                 // Dodajemy krawêdŸ do drzewa
            Z.UnionSets(e);               // Zbiory z wierzcho³kami ³¹czymy ze sob¹
        }
        T.print();
    }




    else if(alg==2){                               //MSTTreeLista algorytmem Prima z listy
        int lwGrafu = l->getLWierzcholkow();
        int lkGrafu = l->getLKrawedzi();
        Edge e;
        //WezelDrzewa *p;  //TNode * p;
        ElementListy *p;
        Queue Q(lkGrafu);
        MSTTreeLista T(lwGrafu);
        MSTTreeLista G(lwGrafu);
        bool * visited = new bool [lwGrafu];
        ElementListy * tmpW;
        ElementListy **tab = l->getTab();

        for(int i = 0; i < lwGrafu; i++) {
            visited[i] = false;
        }

        for (int j = 0; j < lwGrafu; j++) {
            tmpW = tab[j];
            while (tmpW) {
                e.v1 = j;
                e.v2 = tmpW->v;
                e.weight = tmpW->waga;
                G.addEdge(e);
                tmpW = tmpW->nast;
            }
        }
        int v = 0;                          // Wierzcho³ek startowy
        visited[v] = true;              // Oznaczamy go jako odwiedzonego

        for(int i = 1; i < lwGrafu; i++) {         // Do drzewa dodamy n - 1 krawêdzi grafu
            for(p = G.getAList(v); p; p = p->nast) { // Przegl¹damy listê s¹siadów
                if (!visited[p->v]) {         // Jeœli s¹siad jest nieodwiedzony,
                    e.v1 = v;                 // to tworzymy krawêdŸ
                    e.v2 = p->v;
                    e.weight = p->waga;
                    Q.push(e);                // Dodajemy j¹ do kolejki priorytetowej
                }
            }
            do {
                e = Q.front();              // Pobieramy krawêdŸ z kolejki
                Q.pop();
            } while(visited[e.v2]);       // KrawêdŸ prowadzi poza drzewo?

            T.addEdge(e);                 // Dodajemy krawêdŸ do drzewa rozpinaj¹cego
            visited[e.v2] = true;         // Oznaczamy drugi wierzcho³ek jako odwiedzony
            v = e.v2;
        }

        // Wyœwietlamy wyniki

        T.print();

        delete [] visited;
    }
}
