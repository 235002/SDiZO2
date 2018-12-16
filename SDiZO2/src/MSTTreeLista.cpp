#include "MSTTreeLista.h"

MSTTreeLista::MSTTreeLista(int n) {             // Konstruktor - tworzy tablic� pustych list s�siedztwa
    A=new ElementListy * [n];                 // Tworzymy tablic� dynamiczn�
    for(int i = 0; i < n; i++) {              // i wype�niamy j� pustymi listami
        A[i] = NULL;
    }
    Alen = n - 1;                   // Zapami�tujemy d�ugo�� tablicy
    weight = 0;                     // Zerujemy wag� drzewa
}




MSTTreeLista::~MSTTreeLista() {                 // Destruktor - usuwa listy oraz tablic� s�siedztwa
    //cout<<"\nWykonuje sie destruktor drzewa listowego\n";
    ElementListy *p, *r;
    for(int i = 0; i <= Alen; i++) {
        p = A[i];
        while(p) {
            r = p;                      // Zapami�tujemy wskazanie
            p = p->nast;                // Przesuwamy si� do nast�pnego elementu listy
            delete r;                   // Usuwamy element
        }
    }
    delete [] A;                    // Usuwamy tablic� list s�siedztwa
}


ElementListy *MSTTreeLista::getAList(int n) {
    return A[n];
}

void MSTTreeLista::addEdge(Edge e) {      // Dodaje kraw�d� do drzewa
    ElementListy *p;
    weight += e.weight;             // Do wagi drzewa dodajemy wag� kraw�dzi
    p = new ElementListy;                  // Tworzymy nowy w�ze�
    p->v = e.v2;                    // Wierzcho�ek ko�cowy
    p->waga = e.weight;           // Waga kraw�dzi
    p->nast = A[e.v1];              // Dodajemy p do listy wierzcho�ka v1
    A[e.v1] = p;

    p = new ElementListy;                  // To samo dla kraw�dzi odwrotnej
    p->v = e.v1;                    // Wierzcho�ek ko�cowy
    p->waga = e.weight;           // Waga kraw�dzi
    p->nast = A[e.v2];              // Dodajemy p do listy wierzcho�ka v2
    A[e.v2] = p;
}



void MSTTreeLista::print() {              // Wy�wietla zawarto�� drzewa oraz jego wag�
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

        for (int i = 1; i < lwGrafu; i++) {          // P�tla wykonuje si� n - 1 razy !!!
            do {
                e = Q.front();              // Pobieramy z kolejki kraw�d�
                Q.pop();                    // Kraw�d� usuwamy z kolejki
            } while (Z.FindSet(e.v1) == Z.FindSet(e.v2));
            T.addEdge(e);                 // Dodajemy kraw�d� do drzewa
            Z.UnionSets(e);               // Zbiory z wierzcho�kami ��czymy ze sob�
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
        int v = 0;                          // Wierzcho�ek startowy
        visited[v] = true;              // Oznaczamy go jako odwiedzonego

        for(int i = 1; i < lwGrafu; i++) {         // Do drzewa dodamy n - 1 kraw�dzi grafu
            for(p = G.getAList(v); p; p = p->nast) { // Przegl�damy list� s�siad�w
                if (!visited[p->v]) {         // Je�li s�siad jest nieodwiedzony,
                    e.v1 = v;                 // to tworzymy kraw�d�
                    e.v2 = p->v;
                    e.weight = p->waga;
                    Q.push(e);                // Dodajemy j� do kolejki priorytetowej
                }
            }
            do {
                e = Q.front();              // Pobieramy kraw�d� z kolejki
                Q.pop();
            } while(visited[e.v2]);       // Kraw�d� prowadzi poza drzewo?

            T.addEdge(e);                 // Dodajemy kraw�d� do drzewa rozpinaj�cego
            visited[e.v2] = true;         // Oznaczamy drugi wierzcho�ek jako odwiedzony
            v = e.v2;
        }

        // Wy�wietlamy wyniki

        T.print();

        delete [] visited;
    }
}
