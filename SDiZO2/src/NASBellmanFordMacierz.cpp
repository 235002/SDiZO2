#include "NASBellmanFordMacierz.h"

NSBellmanFordMacierz::NSBellmanFordMacierz(MacierzIncydencji *m, int vp, int vk) {
    if(vp >= 0 && vp <lwierzcholkow && vk >=0 && vk <lwierzcholkow) {
        int sptr;
        int *S;

        lwierzcholkow = m->getLWierzcholkow();
        lkrawedzi = m->getLKrawedzi();

        graf = m->getTablica();                                           // Tworzymy tablic� list s�siedztwa
        tablicaKosztowDojscia = new long long[lwierzcholkow];          // Tworzymy tablic� koszt�w doj�cia
        tablicaPoprzednikow = new int[lwierzcholkow];                // Tworzymy tablice poprzednik�w
        for (int i = 0; i < lwierzcholkow; i++) {                      // Inicjujemy struktury danych
            tablicaKosztowDojscia[i] = 2147483647;
            tablicaPoprzednikow[i] = -1;
        }

        cout << endl;
        // Wyznaczamy najkr�tsze �cie�ki algorytmem Bellmana-Forda

        if (BF(vp)) {
            S = new int[lwierzcholkow];                                                                                    // Tworzymy prosty stos
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
                cout << endl;

                for (int i = 0; i < lwierzcholkow; i++) {
                    cout << "koszt dojscia do wierzcholka " << i << " to " << tablicaKosztowDojscia[i] << endl;
                }
                cout << endl << endl << endl;
            } else {
                cout << "Nie ma polaczenia miedzy wierzcholkami." << endl;
            }

        } else cout << "Znaleziono cykl ujemny" << endl;
    }
    else {
        cout << "Blad! Nie ma takiego wierzcholka" << endl;
    }
}






NSBellmanFordMacierz::~NSBellmanFordMacierz() {
    delete [] tablicaKosztowDojscia;
    delete [] tablicaPoprzednikow;
    for(int i = 0; i < lwierzcholkow; i++) {
        delete [] graf[i];
    }
    delete [] graf;
}






bool NSBellmanFordMacierz::BF(int v) {
    bool test;
    int * pv;

    tablicaKosztowDojscia[v] = 0;                                                                     // Zerujemy koszt doj�cia do v
    for(int i = 1; i < lwierzcholkow; i++){                                                               // P�tla relaksacji
        test = true;                                                                                  // Oznacza, �e algorytm nie wprowadzi� zmian do d i p
        for(int wierzcholekU = 0; wierzcholekU < lwierzcholkow; wierzcholekU++) {                                                           // Przechodzimy przez kolejne wierzcho�ki grafu


            for(int t=0;t<lkrawedzi;t++){
                if(graf[wierzcholekU][t]>0){
                    for(int k=0;k<lwierzcholkow;k++){
                        if(graf[k][t]==-1) {                                                               // Modyfikujemy odpowiednio wszystkich s�siad�w u, kt�rzy s� w Q
                            if  (tablicaKosztowDojscia[k] > tablicaKosztowDojscia[wierzcholekU] + graf[wierzcholekU][t]){
                                tablicaKosztowDojscia[k] = tablicaKosztowDojscia[wierzcholekU] + graf[wierzcholekU][t];
                                tablicaPoprzednikow[k] = wierzcholekU;
                            }
                            break;
                        }
                    }
                }
            }
        }
        if(test) {
            return true;
        }                                                                         // Je�li nie by�o zmian, to ko�czymy
    }

    // Sprawdzamy istnienie ujemnego cyklu

    for(int wierzcholekU = 0; wierzcholekU < lwierzcholkow; wierzcholekU++) {

        for(int t=0;t<lkrawedzi;t++){
            if(graf[wierzcholekU][t]>0){
                for(int k=0;k<lwierzcholkow;k++){
                    if(graf[k][t]==-1) {                                                               // Modyfikujemy odpowiednio wszystkich s�siad�w u, kt�rzy s� w Q
                        if  (tablicaKosztowDojscia[k] > tablicaKosztowDojscia[wierzcholekU] + graf[wierzcholekU][t]) {
                            return false;
                        }
                        break;
                    }
                }
            }
        }

    }
    return true;
}
