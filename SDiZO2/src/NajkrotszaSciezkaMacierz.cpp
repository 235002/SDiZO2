#include "NajkrotszaSciezkaMacierz.h"

NajkrotszaSciezkaMacierz::NajkrotszaSciezkaMacierz(MacierzIncydencji *m, int vp, int vk) {
    if(vp >= 0 && vp <lwierzcholkow && vk >=0 && vk <lwierzcholkow) {
        lwierzcholkow = m->getLWierzcholkow();
        lkrawedzi = m->getLKrawedzi();
        wierzcholek = vp;
        tablicaKosztowDojscia = new int[lwierzcholkow];              // Tablica koszt�w doj�cia
        tablicaPoprzednikow = new int[lwierzcholkow];                // Tablica poprzednik�w
        QS = new bool[lwierzcholkow];                                // Zbiory Q i S   -true to S, false to Q
        graf = m->getTablica();                                              // Tablica list s�siedztwa
        S = new int[lwierzcholkow];                                  // Stos
        sptr = 0;                                                     // Wska�nik stosu


        for (int i = 0; i < lwierzcholkow; i++) {
            tablicaKosztowDojscia[i] = 2147483647;
            tablicaPoprzednikow[i] = -1;
            QS[i] = false;
        }
        tablicaKosztowDojscia[wierzcholek] = 0;                       // Koszt doj�cia v jest zerowy

        for (int i = 0; i < lwierzcholkow; i++) {
            for (int c = 0; c < lwierzcholkow; c++) {
                if (QS[c] == false) {
                    wierzcholekU = c;
                }
            }
            for (int c = 0; c < lwierzcholkow; c++) {
                if (QS[c] == false) {
                    if (tablicaKosztowDojscia[c] <
                        tablicaKosztowDojscia[wierzcholekU]) {                                   // Szukamy wierzcho�ka w Q o najmniejszym koszcie d
                        wierzcholekU = c;
                    }
                }
            }
            QS[wierzcholekU] = true;                                                                                         // Znaleziony wierzcho�ek przenosimy do S


            for (int t = 0; t < lkrawedzi; t++) {
                if (graf[wierzcholekU][t] > 0) {
                    for (int k = 0; k < lwierzcholkow; k++) {
                        if (graf[k][t] ==
                            -1) {                                                               // Modyfikujemy odpowiednio wszystkich s�siad�w u, kt�rzy s� w Q
                            if (!QS[k] && (tablicaKosztowDojscia[k] >
                                           tablicaKosztowDojscia[wierzcholekU] + graf[wierzcholekU][t])) {
                                tablicaKosztowDojscia[k] = tablicaKosztowDojscia[wierzcholekU] + graf[wierzcholekU][t];
                                tablicaPoprzednikow[k] = wierzcholekU;
                            }
                            break;
                        }
                    }
                }
            }
        }


        //wyswietlanie
        if (tablicaKosztowDojscia[vk] < 2000000000 && tablicaKosztowDojscia[vk] > -2000000000) {
            cout << "minimalny koszt dojscia z wierzcholka " << vp << " do wierzcholka " << vk
                 << " przez wierzcholki: ";
            for (int j = vk; j >
                             -1; j = tablicaPoprzednikow[j]) {                                                                // �cie�k� przechodzimy od ko�ca ku pocz�tkowi,
                S[sptr++] = j;                                                                                                  // Zapisuj�c na stosie kolejne wierzcho�ki
            }
            while (sptr) {                                                                                                       // Wy�wietlamy �cie�k�, pobieraj�c wierzcho�ki ze stosu
                cout << S[--sptr] << " ";
            }
            cout << "to: " << tablicaKosztowDojscia[vk]
                 << endl;                                                                // Na ko�cu �cie�ki wypisujemy jej koszt
            cout << endl;
            for (int i = 0; i < lwierzcholkow; i++) {
                cout << "koszt dojscia do wierzcholka " << i << " " << tablicaKosztowDojscia[i] << endl;
            }
            cout << endl << endl << endl;
        } else {
            cout << "Nie ma polaczenia miedzy wierzcholkami." << endl;
        }
    } else {
        cout << "Blad! Nie ma takiego wierzcholka" << endl;
    }

}

NajkrotszaSciezkaMacierz::~NajkrotszaSciezkaMacierz() {
    delete [] tablicaKosztowDojscia;
    delete [] tablicaPoprzednikow;
    delete [] QS;
    delete [] S;
    for(int i = 0; i < lwierzcholkow; i++) {
        delete [] graf[i];
    }
    delete [] graf;
}
