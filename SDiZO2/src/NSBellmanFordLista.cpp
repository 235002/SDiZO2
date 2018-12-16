#include "NSBellmanFordLista.h"

NSBellmanFordLista::NSBellmanFordLista(ListaSasiedztwa *l, int vp, int vk) {
    if(vp >= 0 && vp <lwierzcholkow && vk >=0 && vk <lwierzcholkow) {
        int sptr;
        int *S;
        lwierzcholkow = l->getLWierzcholkow();
        lkrawedzi = l->getLKrawedzi();
        A = l->getTab();                                                  // Tworzymy tablicê list s¹siedztwa
        tablicaKosztowDojscia = new long long[lwierzcholkow];          // Tworzymy tablicê kosztów dojœcia
        tablicaPoprzednikow = new int[lwierzcholkow];                  // Tworzymy tablice poprzedników
        for (int i = 0; i < lwierzcholkow; i++) {                       // Inicjujemy struktury danych
            tablicaKosztowDojscia[i] = 2147483647;
            tablicaPoprzednikow[i] = -1;
        }


        cout << endl;
        // Wyznaczamy najkrótsze œcie¿ki algorytmem Bellmana-Forda

        if (BF(vp)) {
            S = new int[lwierzcholkow];                                     // Tworzymy prosty stos
            sptr = 0;
            if (tablicaKosztowDojscia[vk] < 2000000000 && tablicaKosztowDojscia[vk] > -2000000000) {
                cout << "minimalny koszt dojscia z wierzcholka " << vp << " do wierzcholka " << vk
                     << " przez wierzcholki: ";
                for (int j = vk; j !=
                                 -1; j = tablicaPoprzednikow[j]) {                                                           // Œcie¿kê przechodzimy od koñca ku pocz¹tkowi,
                    S[sptr++] = j;                                                                                              // Zapisuj¹c na stosie kolejne wierzcho³ki
                }
                while (sptr) {                                                                                                   // Wierzcho³ki ze stosu drukujemy
                    cout << S[--sptr]
                         << " ";                                                                                   // w kolejnoœci od pierwszego do ostatniego
                }
                cout << " to: " << tablicaKosztowDojscia[vk] << endl;

                for (int i = 0; i < lwierzcholkow; i++) {
                    cout << "koszt dojscia do wierzcholka " << i << " to " << tablicaKosztowDojscia[i] << endl;
                }
                cout << endl << endl << endl;
            } else {
                cout << "Nie ma polaczenia miedzy wierzcholkami." << endl;
            }


            delete[] S;                  // Usuwamy stos
        } else cout << "Znaleziono cykl ujemny" << endl;
    } else {
        cout << "Blad! Nie ma takiego wierzcholka" << endl;
    }
}






bool NSBellmanFordLista::BF(int v) {
    bool test;
    ElementListy * pv;

    tablicaKosztowDojscia[v] = 0;                                                                     // Zerujemy koszt dojœcia do v
    for(int i = 1; i < lwierzcholkow; i++){                                                               // Pêtla relaksacji
        test = true;                                                                                  // Oznacza, ¿e algorytm nie wprowadzi³ zmian do d i p
        for(int x = 0; x < lwierzcholkow; x++) {                                                           // Przechodzimy przez kolejne wierzcho³ki grafu
            for (pv = A[x]; pv; pv = pv->nast) {                                                       // Przegl¹damy listê s¹siadów wierzcho³ka x
                if (tablicaKosztowDojscia[pv->v] > tablicaKosztowDojscia[x] + pv->waga) {      // Sprawdzamy warunek relaksacji
                    test = false;                                                                     // Jest zmiana w d i p
                    tablicaKosztowDojscia[pv->v] = tablicaKosztowDojscia[x] + pv->waga;       // Relaksujemy krawêdŸ z x do jego s¹siada
                    tablicaPoprzednikow[pv->v] = x;                                                   // Poprzednikiem s¹siada bêdzie x
                }
            }
        }
        if(test) {
            return true;
        }                                                                         // Jeœli nie by³o zmian, to koñczymy
    }

    // Sprawdzamy istnienie ujemnego cyklu

    for(int x = 0; x < lwierzcholkow; x++) {
        for (pv = A[x]; pv; pv = pv->nast) {
            if (tablicaKosztowDojscia[pv->v] > tablicaKosztowDojscia[x] + pv->waga) {
                return false; // ujemny cykl!!
            }
        }
    }
    return true;
}







NSBellmanFordLista::~NSBellmanFordLista() {
    ElementListy *pv,* rv;
    for(int i = 0; i < lwierzcholkow; i++) {
        pv = A[i];
        while(pv) {
            rv = pv;
            pv = pv->nast;
            delete rv;
        }
    }
    delete [] A;
    delete [] tablicaKosztowDojscia;
    delete [] tablicaPoprzednikow;
}
