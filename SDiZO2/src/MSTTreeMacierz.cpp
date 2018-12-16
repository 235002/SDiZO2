#include "MSTTreeMacierz.h"
#include <iostream>
#include <iomanip>


MSTTreeMacierz::MSTTreeMacierz(int n) {

    //konstruktor 1-parametrowy
    Alen = n - 1;                   // Zapamiêtujemy d³ugoœæ tablicy
    weight = 0;                     // Zerujemy wagê drzewa
    A=new signed int* [n]; ;
    for(int i = 0; i < n; i++) {            // i wype³niamy j¹ pustymi tablicami (?)
        A[i] = new signed int [Alen];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <Alen; j++) {            // i wype³niamy j¹ zerami
            A[i][j] = 0;
        }
    }
}

MSTTreeMacierz::~MSTTreeMacierz() {
    //cout<<"\nWykonuje sie destruktor drzewa macierzowego\n";
    for(int i = 0; i <= Alen; i++) {
        delete [] A[i];             //usuwamy tablice wierzcholkow
    }
    delete [] A;                    // Usuwamy tablicê krawedzi
}



void MSTTreeMacierz::addEdge(Edge e) {
    //signed int * p=new signed int [Alen-1];      //tworzymy nowa krawedz
    A[e.v1][licznikK]=e.weight;
    A[e.v2][licznikK]=-1;
    licznikK++;
    weight+=e.weight;
}
/*
void MST::addEdgeMatrix(Edge e) {
    //tabMSTIncidenceMatrix;
    weight += e.weight;
    //e.v2 wierzcholek koncowy
    //e.weight //waga krawedzi
    //e.v1

   // std::cout << "e.v2: " << e.v2 << std::endl;
  //  std::cout << "e.v1: " << e.v1 << std::endl;
  //  std::cout << "e.weight: " << e.weight << std::endl;
    tabMSTIncidenceMatrix[e.v1][tmpCounter] = e.weight;
    tabMSTIncidenceMatrix[e.v2][tmpCounter] = -1;
    tmpCounter++;



}
 */


void MSTTreeMacierz::printMacierz() {
        int lwierzcholkow=Alen+1;
        cout <<endl<< "   ";
        for(int i = 0; i <Alen; i++) {
            cout << setw(3) << i;
        }
        cout << endl << endl;

        for(int i = 0; i < lwierzcholkow; i++) {
            cout << setw(3) << i;
            for(int j = 0; j <Alen; j++) {
                cout << setw(3) << A[i][j];
            }
            cout << endl;
        }
    cout << endl << endl << "Waga minimalnego drzewa rozpinajacego = " << weight << endl << endl;
}





MSTTreeMacierz::MSTTreeMacierz(MacierzIncydencji *m, int alg) {
    if (alg == 1) {                                                          //MSTTreeMacierz algorytmem Kruska z macierzy
        int lwGrafu = m->getLWierzcholkow();
        int lkGrafu = m->getLKrawedzi();
        Edge e;
        DSStruct Z(lwGrafu);
        Queue Q(lkGrafu);
        signed int **tablica1 = m->getTablica();

        //konstruktor 1-parametrowy
        Alen = lwGrafu - 1;                           // Zapamiêtujemy d³ugoœæ tablicy
        weight = 0;                                   // Zerujemy wagê drzewa
        A = new signed int *[lwGrafu];                  // Tworzymy tablicê dynamiczn¹

        for (int i = 0; i < lwGrafu; i++) {            // wype³niamy j¹ pustymi tablicami
            A[i] = new signed int[Alen];
        }
        for (int i = 0; i < lwGrafu; i++) {
            for (int j = 0; j < Alen; j++) {            // i wype³niamy je zerami
                A[i][j] = 0;
            }
        }


        for (int i = 0; i < lwGrafu; i++) {
            Z.MakeSet(i);
        }

        for (int i = 0; i < lkGrafu; i++) {
            for (int j = 0; j < lwGrafu; j++) {
                if (tablica1[j][i] > 0) {
                    for (int k = 0; k < lwGrafu; k++) {
                        if (tablica1[k][i] == -1) {
                            e.v1 = j;
                            e.v2 = k;
                            e.weight = tablica1[j][i];
                            Q.push(e);
                            //break;
                        }
                    }
                }
            }
        }

        for (int i = 1; i < lwGrafu; i++) {          // Pêtla wykonuje siê n - 1 razy !!!
            do {
                e = Q.front();              // Pobieramy z kolejki krawêdŸ
                Q.pop();                    // KrawêdŸ usuwamy z kolejki
            } while (Z.FindSet(e.v1) == Z.FindSet(e.v2));
            this->addEdge(e);                 // Dodajemy krawêdŸ do drzewa
            Z.UnionSets(e);               // Zbiory z wierzcho³kami ³¹czymy ze sob¹
        }

        // this->printMacierz();
    }


    /*else if(alg==2) {
        int lwGrafu = m->getLWierzcholkow();
        int lkGrafu = m->getLKrawedzi();
        Alen = lwGrafu - 1;                                                           // Zapamiêtujemy d³ugoœæ tablicy
        weight = 0;                                                                   // Zerujemy wagê drzewa
        A=new signed int* [lwGrafu]; ;
        for(int i = 0; i < lwGrafu; i++) {                                            // i wype³niamy j¹ pustymi tablicami
            A[i] = new signed int [Alen];
        }
        for(int i = 0; i < lwGrafu; i++) {
            for(int j = 0; j <Alen; j++) {                                            // i wype³niamy j¹ zerami
                A[i][j] = 0;
            }
        }
        Edge tmpE;
        //Queue Q(lwGrafu);
        Queue * Q=new Queue(lwGrafu);
        visited = new bool[lwGrafu];
        signed int **tablica1 = m->getTablica();
        for(int i =0;i<lwGrafu;i++){
            visited[i] = false;
        }
        int v = 0;                                                                     //wierzcholek startowy
        visited[v]=true;
        Edge *edges = new Edge[lkGrafu];
        for (int i = 0; i < lkGrafu; i++) {
            for (int j = 0; j < lwGrafu; j++) {
                if (tablica1[j][i] != 0 && tablica1[j][i] != -1) {
                    edges[i].v1 = j;
                    edges[i].weight = tablica1[j][i];
                } else if (tablica1[j][i] == -1) {
                    edges[i].v2 = j;
                }
            }
        }
        for (long  i = 1; i < lwGrafu; i++) {
            for (int g = 0; g < lkGrafu; g++) {
                if (tablica1[v][g] != 0) {
                    for (long j = 0; j < lwGrafu; j++) {
                        if (j != v && tablica1[j][g] != 0 && !visited[j]) {
                            tmpE.v1 = v;
                            tmpE.v2 = j;
                            tmpE.weight = edges[g].weight;
                            //cout<<j<<endl;
                            Q->push(tmpE);
                        }
                    }
                }
            }
            do {
                tmpE = Q->front();
                Q->pop();
            } while (visited[tmpE.v2]);

            addEdge(tmpE);
            visited[tmpE.v2] = true;
            v = tmpE.v2;
        }

    }
    cout<<"ala"<<endl;*/

  /*  else if (alg == 2) {         //MSTTreeMacierz algorytmem Prima z macierzy
        int lwGrafu = m->getLWierzcholkow();
        int lkGrafu = m->getLKrawedzi();
        bool *visited = new bool[lwGrafu];             //utworzenie tablicy visited

        for (int i = 0; i < lwGrafu; i++) {            //ustawienie wszystkich visited na false
            visited[i] = false;
        }
        int v = 0;
        visited[v]=true;



        //konstruktor 1-parametrowy
        Alen = lwGrafu - 1;                            // Zapamiêtujemy d³ugoœæ tablicy
        weight = 0;                                    // Zerujemy wagê drzewa
        A = new signed int *[lwGrafu];                 // Tworzymy tablicê dynamiczn¹

        for (int i = 0; i < lwGrafu; i++) {            //  wype³niamy j¹ pustymi tablicami
            A[i] = new signed int[Alen];
        }
        for (int i = 0; i < lwGrafu; i++) {
            for (int j = 0; j < Alen; j++) {            // i wype³niamy je zerami
                A[i][j] = 0;
            }
        }

        Edge *edges = new Edge[lkGrafu];
        tablica1 = m->getTablica();
        for (int i = 0; i < lkGrafu; i++) {
            for (int j = 0; j < lwGrafu; j++) {
                if (tablica1[j][i] != 0 && tablica1[j][i] != -1) {
                    edges[i].v1 = j;
                    edges[i].weight = tablica1[j][i];
                } else if (tablica1[j][i] == -1) {
                    edges[i].v2 = j;
                }

            }
        }

        cout << "Cygany tera wypiszcie liste edgy: " << endl;
        for (int i = 0; i < lkGrafu; i++) {
            cout << edges[i].v1 << " " << edges[i].v2 << " " << edges[i].weight << endl;
        }


    }*/



    else if(alg==2) {         //MSTTreeMacierz algorytmem Prima z macierzy
        int lwGrafu = m->getLWierzcholkow();
        int lkGrafu = m->getLKrawedzi();

        //konstruktor 1-parametrowy
        Alen = lwGrafu - 1;                            // Zapamiêtujemy d³ugoœæ tablicy
        weight = 0;                                    // Zerujemy wagê drzewa
        // A = new WezelDrzewa * [n];
        A = new signed int *[lwGrafu];                 // Tworzymy tablicê dynamiczn¹

        for (int i = 0; i < lwGrafu; i++) {            //  wype³niamy j¹ pustymi tablicami
            A[i] = new signed int[Alen];
        }
        for (int i = 0; i < lwGrafu; i++) {
            for (int j = 0; j < Alen; j++) {            // i wype³niamy je zerami
                A[i][j] = 0;
            }
        }


        signed int **tablica1 = m->getTablica();
        bool *visited = new bool[lwGrafu];             //utworzenie tablicy visited

        for (int i = 0; i < lwGrafu; i++) {            //ustawienie wszystkich visited na false
            visited[i] = false;
        }

        int v = 0;                          // Wierzcho³ek startowy
        visited[v] = true;              // Oznaczamy go jako odwiedzonego

        Edge tmpE1;
        Edge tmpE2;
        tmpE1.weight = tmpE2.weight = 1000000;
        int tmp=0;
        int n =0;
        gg:
        if(licznikK<lwGrafu-1) {
            for (int t = 0; t < lwGrafu; t++) {
                if (visited[t] == true) {
                    for (int i = 0; i < lwGrafu; i++) {
                        if (visited[i] == true) {
                            for (int j = 0; j < lkGrafu; j++) {
                                tmp++;                                    //tmp liczy ile krawedzio-poczatkowWierzcholkow musi sprawdzic zanim bedzie mogl dodac krawedz do drzewa (czy nie ma mniejszej w wierzcholkach z true)
                                if (tablica1[i][j] != 0) {
                                    for (int k = 0; k < lwGrafu; k++) {
                                        if (tablica1[k][j] != 0 && tablica1[k][j]!=tablica1[i][j] && visited[k] == false) {
                                            tmpE2.v1 = i;
                                            tmpE2.v2 = k;
                                            tmpE2.weight = tablica1[i][j];
                                            if(tablica1[k][j]>tablica1[i][j]){
                                                tmpE2.weight=tablica1[k][j];
                                            }
                                            if (tmpE2.weight < tmpE1.weight) {
                                                tmpE1 = tmpE2;
                                                t = -1;                    //zeby zaczal jeszcze raz od zera
                                            }
                                            break;
                                        }
                                    }
                                }
                                if (tmp >=lkGrafu*(n+1)  && tmpE1.weight != 1000000) {
                                    this->addEdge(tmpE1);
                                    visited[tmpE1.v2] = true;
                                    tmpE1.weight = 1000000;
                                    tmp = 0;
                                    n++;                                //n pamieta ile wierzcholkow ma true, czyli tez ile krawedzi jest juz dodanych
                                    goto gg;
                                }
                            }
                        }
                    }
                }
            }
        }
       // this->printMacierz();
        delete [] visited;
    }

}
