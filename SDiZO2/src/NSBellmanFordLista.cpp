#include "NSBellmanFordLista.h"

NSBellmanFordLista::NSBellmanFordLista(ListaSasiedztwa *l, int vp, int vk) {
    if(vp >= 0 && vp <lwierzcholkow && vk >=0 && vk <lwierzcholkow) {
        int sptr;
        int *S;
        lwierzcholkow = l->getLWierzcholkow();
        lkrawedzi = l->getLKrawedzi();
        A = l->getTab();                                                  // Tworzymy tablic� list s�siedztwa
        tablicaKosztowDojscia = new long long[lwierzcholkow];          // Tworzymy tablic� koszt�w doj�cia
        tablicaPoprzednikow = new int[lwierzcholkow];                  // Tworzymy tablice poprzednik�w
        for (int i = 0; i < lwierzcholkow; i++) {                       // Inicjujemy struktury danych
            tablicaKosztowDojscia[i] = 2147483647;
            tablicaPoprzednikow[i] = -1;
        }


        cout << endl;
        // Wyznaczamy najkr�tsze �cie�ki algorytmem Bellmana-Forda

        if (BF(vp)) {
            S = new int[lwierzcholkow];                                     // Tworzymy prosty stos
            sptr = 0;
            if (tablicaKosztowDojscia[vk] < 2000000000 && tablicaKosztowDojscia[vk] > -2000000000) {
                cout << "minimalny koszt dojscia z wierzcholka " << vp << " do wierzcholka " << vk
                     << " przez wierzcholki: ";
                for (int j = vk; j !=
                                 -1; j = tablicaPoprzednikow[j]) {                                                           // �cie�k� przechodzimy od ko�ca ku pocz�tkowi,
                    S[sptr++] = j;                                                                                              // Zapisuj�c na stosie kolejne wierzcho�ki
                }
                while (sptr) {                                                                                                   // Wierzcho�ki ze stosu drukujemy
                    cout << S[--sptr]
                         << " ";                                                                                   // w kolejno�ci od pierwszego do ostatniego
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

    tablicaKosztowDojscia[v] = 0;                                                                     // Zerujemy koszt doj�cia do v
    for(int i = 1; i < lwierzcholkow; i++){                                                               // P�tla relaksacji
        test = true;                                                                                  // Oznacza, �e algorytm nie wprowadzi� zmian do d i p
        for(int x = 0; x < lwierzcholkow; x++) {                                                           // Przechodzimy przez kolejne wierzcho�ki grafu
            for (pv = A[x]; pv; pv = pv->nast) {                                                       // Przegl�damy list� s�siad�w wierzcho�ka x
                if (tablicaKosztowDojscia[pv->v] > tablicaKosztowDojscia[x] + pv->waga) {      // Sprawdzamy warunek relaksacji
                    test = false;                                                                     // Jest zmiana w d i p
                    tablicaKosztowDojscia[pv->v] = tablicaKosztowDojscia[x] + pv->waga;       // Relaksujemy kraw�d� z x do jego s�siada
                    tablicaPoprzednikow[pv->v] = x;                                                   // Poprzednikiem s�siada b�dzie x
                }
            }
        }
        if(test) {
            return true;
        }                                                                         // Je�li nie by�o zmian, to ko�czymy
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
