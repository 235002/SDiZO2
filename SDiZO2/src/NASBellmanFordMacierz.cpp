#include "NASBellmanFordMacierz.h"

NSBellmanFordMacierz::NSBellmanFordMacierz(MacierzIncydencji *m, int vp, int vk) {
    if(vp >= 0 && vp <lwierzcholkow && vk >=0 && vk <lwierzcholkow) {
        int sptr;
        int *S;

        lwierzcholkow = m->getLWierzcholkow();
        lkrawedzi = m->getLKrawedzi();

        graf = m->getTablica();                                           // Tworzymy tablicê list s¹siedztwa
        tablicaKosztowDojscia = new long long[lwierzcholkow];          // Tworzymy tablicê kosztów dojœcia
        tablicaPoprzednikow = new int[lwierzcholkow];                // Tworzymy tablice poprzedników
        for (int i = 0; i < lwierzcholkow; i++) {                      // Inicjujemy struktury danych
            tablicaKosztowDojscia[i] = 2147483647;
            tablicaPoprzednikow[i] = -1;
        }

        cout << endl;
        // Wyznaczamy najkrótsze œcie¿ki algorytmem Bellmana-Forda

        if (BF(vp)) {
            S = new int[lwierzcholkow];                                                                                    // Tworzymy prosty stos
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

    tablicaKosztowDojscia[v] = 0;                                                                     // Zerujemy koszt dojœcia do v
    for(int i = 1; i < lwierzcholkow; i++){                                                               // Pêtla relaksacji
        test = true;                                                                                  // Oznacza, ¿e algorytm nie wprowadzi³ zmian do d i p
        for(int wierzcholekU = 0; wierzcholekU < lwierzcholkow; wierzcholekU++) {                                                           // Przechodzimy przez kolejne wierzcho³ki grafu


            for(int t=0;t<lkrawedzi;t++){
                if(graf[wierzcholekU][t]>0){
                    for(int k=0;k<lwierzcholkow;k++){
                        if(graf[k][t]==-1) {                                                               // Modyfikujemy odpowiednio wszystkich s¹siadów u, którzy s¹ w Q
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
        }                                                                         // Jeœli nie by³o zmian, to koñczymy
    }

    // Sprawdzamy istnienie ujemnego cyklu

    for(int wierzcholekU = 0; wierzcholekU < lwierzcholkow; wierzcholekU++) {

        for(int t=0;t<lkrawedzi;t++){
            if(graf[wierzcholekU][t]>0){
                for(int k=0;k<lwierzcholkow;k++){
                    if(graf[k][t]==-1) {                                                               // Modyfikujemy odpowiednio wszystkich s¹siadów u, którzy s¹ w Q
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
