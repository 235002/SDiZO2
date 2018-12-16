#include "Testy.h"

#include <sstream>

using namespace std;


void Testy::ZachowajCzas() {
    timeus= (float) ((1000000.0 * elapsed) / frequency);
}

long long int Testy::read_QPC() {
    LARGE_INTEGER count;
    QueryPerformanceCounter(&count);
    return((long long int)count.QuadPart);
}

void Testy::zapiszStatystykeDoPliku(std::string nazwapliku, float timeus) {
    std::ofstream plik;
    plik.open(nazwapliku, std::ios_base::app);
    plik<< timeus<<" ";
    plik.close();
}

void Testy::zapiszDoPliku(std::string nazwapliku, std::string tresc) {
    std::ofstream plik;
    plik.open(nazwapliku, std::ios_base::app);
    plik << tresc;
    plik.close();
}

void Testy::statMST(std::string nazwaPliku) {
    signed int ** ttmptab=new signed int* [0];
    float tmp = 0;

  /*for(int i=1; i<=4; i++) {                             //test dla 10 elementów
        int lw=10;
        float gestosc=i*0.25;
        ostringstream ss;
        ss << gestosc;
        string str = ss.str();
        zapiszDoPliku(nazwaPliku, "\nTest dla 10 elementow i gestosci ");
        zapiszDoPliku(nazwaPliku, str);
        zapiszDoPliku(nazwaPliku, " ");
        zapiszDoPliku("statystykiPrimListowo.txt", "\nTest dla 10 elementow i gestosci ");
        zapiszDoPliku("statystykiPrimListowo.txt", str);
        zapiszDoPliku("statystykiPrimListowo.txt", " ");

        ttm.UtworzLosowo(lw, gestosc);
        if (ttm.UtworzLosowo(lw, gestosc) == false) {
            cout << "Graf nie jest spojny!"<<endl;
        } else {
            ttmptab = ttm.getTablica();
            tl.UtworzLosowo(ttmptab, lw, gestosc);
        }
        for (int i = 0; i < 10; i++) {
            start = read_QPC();
            dpm = new MSTTreeMacierz(&ttm, 2); //Prim macierzowo
            elapsed = read_QPC() - start;
            ZachowajCzas();
            tmp += timeus;
        }
        tmp = tmp / 10;
        zapiszStatystykeDoPliku(nazwaPliku, tmp);
        tmp = 0;

        for (int i = 0; i < 10; i++) {
            start = read_QPC();
            dpl = new MSTTreeLista(&tl, 2); //Prim macierzowo
            elapsed = read_QPC() - start;
            ZachowajCzas();
            tmp += timeus;
        }
        tmp = tmp / 10;
        zapiszStatystykeDoPliku("statystykiPrimListowo.txt", tmp);
        tmp = 0;
    }






    for(int i=1; i<=4; i++) {                             //test dla 20 elementów
        int lw=20;
        float gestosc=i*0.25;
        ostringstream ss;
        ss << gestosc;
        string str = ss.str();
        zapiszDoPliku(nazwaPliku, "\nTest dla 20 elementow i gestosci ");
        zapiszDoPliku(nazwaPliku, str);
        zapiszDoPliku(nazwaPliku, " ");
        zapiszDoPliku("statystykiPrimListowo.txt", "\nTest dla 20 elementow i gestosci ");
        zapiszDoPliku("statystykiPrimListowo.txt", str);
        zapiszDoPliku("statystykiPrimListowo.txt", " ");

        ttm.UtworzLosowo(lw, gestosc);
        if (ttm.UtworzLosowo(lw, gestosc) == false) {
            cout << "Graf nie jest spojny!"<<endl;
        } else {
            ttmptab = ttm.getTablica();
            tl.UtworzLosowo(ttmptab, lw, gestosc);
        }
        for (int i = 0; i < 10; i++) {
            start = read_QPC();
            dpm = new MSTTreeMacierz(&ttm, 2); //Prim macierzowo
            elapsed = read_QPC() - start;
            ZachowajCzas();
            tmp += timeus;
        }
        tmp = tmp / 10;
        zapiszStatystykeDoPliku(nazwaPliku, tmp);
        tmp = 0;

        for (int i = 0; i < 10; i++) {
            start = read_QPC();
            dpl = new MSTTreeLista(&tl, 2); //Prim macierzowo
            elapsed = read_QPC() - start;
            ZachowajCzas();
            tmp += timeus;
        }
        tmp = tmp / 10;
        zapiszStatystykeDoPliku("statystykiPrimListowo.txt", tmp);
        tmp = 0;
    }

*/


    for(int i=1; i<=4; i++) {                             //test dla 50 elementów
        int lw=50;
        float gestosc=i*0.25;
        ostringstream ss;
        ss << gestosc;
        string str = ss.str();
        zapiszDoPliku(nazwaPliku, "\nTest dla 50 elementow i gestosci ");
        zapiszDoPliku(nazwaPliku, str);
        zapiszDoPliku(nazwaPliku, " ");
        zapiszDoPliku("statystykiPrimListowo.txt", "\nTest dla 50 elementow i gestosci ");
        zapiszDoPliku("statystykiPrimListowo.txt", str);
        zapiszDoPliku("statystykiPrimListowo.txt", " ");

        ttm.UtworzLosowo(lw, gestosc);
        if (ttm.UtworzLosowo(lw, gestosc) == false) {
            cout << "Graf nie jest spojny!"<<endl;
        } else {
            ttmptab = ttm.getTablica();
            tl.UtworzLosowo(ttmptab, lw, gestosc);
        }
        for (int i = 0; i < 10; i++) {
            start = read_QPC();
            dpm = new MSTTreeMacierz(&ttm, 2); //Prim macierzowo
            elapsed = read_QPC() - start;
            ZachowajCzas();
            tmp += timeus;
        }
        tmp = tmp / 10;
        zapiszStatystykeDoPliku(nazwaPliku, tmp);
        tmp = 0;

        for (int i = 0; i < 10; i++) {
            start = read_QPC();
            dpl = new MSTTreeLista(&tl, 2); //Prim macierzowo
            elapsed = read_QPC() - start;
            ZachowajCzas();
            tmp += timeus;
        }
        tmp = tmp / 10;
        zapiszStatystykeDoPliku("statystykiPrimListowo.txt", tmp);
        tmp = 0;
    }


    for(int i=1; i<=4; i++) {                             //test dla 100 elementów
        int lw=100;
        float gestosc=i*0.25;
        ostringstream ss;
        ss << gestosc;
        string str = ss.str();
        zapiszDoPliku(nazwaPliku, "\nTest dla 100 elementow i gestosci ");
        zapiszDoPliku(nazwaPliku, str);
        zapiszDoPliku(nazwaPliku, " ");
        zapiszDoPliku("statystykiPrimListowo.txt", "\nTest dla 100 elementow i gestosci ");
        zapiszDoPliku("statystykiPrimListowo.txt", str);
        zapiszDoPliku("statystykiPrimListowo.txt", " ");

        ttm.UtworzLosowo(lw, gestosc);
        if (ttm.UtworzLosowo(lw, gestosc) == false) {
            cout << "Graf nie jest spojny!"<<endl;
        } else {
            ttmptab = ttm.getTablica();
            tl.UtworzLosowo(ttmptab, lw, gestosc);
        }
        for (int i = 0; i < 10; i++) {
            start = read_QPC();
            dpm = new MSTTreeMacierz(&ttm, 2); //Prim macierzowo
            elapsed = read_QPC() - start;
            ZachowajCzas();
            tmp += timeus;
        }
        tmp = tmp / 10;
        zapiszStatystykeDoPliku(nazwaPliku, tmp);
        tmp = 0;

        for (int i = 0; i < 10; i++) {
            start = read_QPC();
            dpl = new MSTTreeLista(&tl, 2); //Prim macierzowo
            elapsed = read_QPC() - start;
            ZachowajCzas();
            tmp += timeus;
        }
        tmp = tmp / 10;
        zapiszStatystykeDoPliku("statystykiPrimListowo.txt", tmp);
        tmp = 0;
    }





    for(int i=1; i<=4; i++) {                             //test dla 75 elementów
        int lw=75;
        float gestosc=i*0.25;
        ostringstream ss;
        ss << gestosc;
        string str = ss.str();
        zapiszDoPliku(nazwaPliku, "\nTest dla 75 elementow i gestosci ");
        zapiszDoPliku(nazwaPliku, str);
        zapiszDoPliku(nazwaPliku, " ");
        zapiszDoPliku("statystykiPrimListowo.txt", "\nTest dla 75 elementow i gestosci ");
        zapiszDoPliku("statystykiPrimListowo.txt", str);
        zapiszDoPliku("statystykiPrimListowo.txt", " ");

        ttm.UtworzLosowo(lw, gestosc);
        if (ttm.UtworzLosowo(lw, gestosc) == false) {
            cout << "Graf nie jest spojny!"<<endl;
        } else {
            ttmptab = ttm.getTablica();
            tl.UtworzLosowo(ttmptab, lw, gestosc);
        }
        for (int i = 0; i < 10; i++) {
            start = read_QPC();
            dpm = new MSTTreeMacierz(&ttm, 2); //Prim macierzowo
            elapsed = read_QPC() - start;
            ZachowajCzas();
            tmp += timeus;
        }
        tmp = tmp / 10;
        zapiszStatystykeDoPliku(nazwaPliku, tmp);
        tmp = 0;

        for (int i = 0; i < 10; i++) {
            start = read_QPC();
            dpl = new MSTTreeLista(&tl, 2); //Prim macierzowo
            elapsed = read_QPC() - start;
            ZachowajCzas();
            tmp += timeus;
        }
        tmp = tmp / 10;
        zapiszStatystykeDoPliku("statystykiPrimListowo.txt", tmp);
        tmp = 0;
    }
}


/*
void Testy::statMSTKrusk(std::string nazwaPliku) {
    signed int ** ttmptab=new signed int* [0];
    float tmp = 0;

    for(int i=1; i<=4; i++) {                             //test dla 10 elementów
        int lw=10;
        float gestosc=i*0.25;
        ostringstream ss;
        ss << gestosc;
        string str = ss.str();
        zapiszDoPliku(nazwaPliku, "\nTest Kruskala dla 10 elementow i gestosci ");
        zapiszDoPliku(nazwaPliku, str);
        zapiszDoPliku(nazwaPliku, " ");
        zapiszDoPliku("statystykiKruskalListowo.txt", "\nTest dla 10 elementow i gestosci ");
        zapiszDoPliku("statystykiKruskalListowo.txt", str);
        zapiszDoPliku("statystykiKruskalListowo.txt", " ");

        ttm.UtworzLosowo(lw, gestosc);
        if (ttm.UtworzLosowo(lw, gestosc) == false) {
            cout << "Graf nie jest spojny!"<<endl;
        } else {
            ttmptab = ttm.getTablica();
            tl.UtworzLosowo(ttmptab, lw, gestosc);
        }
        for (int i = 0; i < 10; i++) {
            start = read_QPC();
            dpm = new MSTTreeMacierz(&ttm, 1); //Kruskal macierzowo
            elapsed = read_QPC() - start;
            ZachowajCzas();
            tmp += timeus;
        }
        tmp = tmp / 10;
        zapiszStatystykeDoPliku(nazwaPliku, tmp);
        tmp = 0;

        for (int i = 0; i < 10; i++) {
            start = read_QPC();
            dpl = new MSTTreeLista(&tl, 1); //Kruskal listowo
            elapsed = read_QPC() - start;
            ZachowajCzas();
            tmp += timeus;
        }
        tmp = tmp / 10;
        zapiszStatystykeDoPliku("statystykiKruskalListowo.txt", tmp);
        tmp = 0;
    }

    for(int i=1; i<=4; i++) {                             //test dla 20 elementów
        int lw=20;
        float gestosc=i*0.25;
        ostringstream ss;
        ss << gestosc;
        string str = ss.str();
        zapiszDoPliku(nazwaPliku, "\nTest Kruskala dla 20 elementow i gestosci ");
        zapiszDoPliku(nazwaPliku, str);
        zapiszDoPliku(nazwaPliku, " ");
        zapiszDoPliku("statystykiKruskalListowo.txt", "\nTest dla 20 elementow i gestosci ");
        zapiszDoPliku("statystykiKruskalListowo.txt", str);
        zapiszDoPliku("statystykiKruskalListowo.txt", " ");

        ttm.UtworzLosowo(lw, gestosc);
        if (ttm.UtworzLosowo(lw, gestosc) == false) {
            cout << "Graf nie jest spojny!"<<endl;
        } else {
            ttmptab = ttm.getTablica();
            tl.UtworzLosowo(ttmptab, lw, gestosc);
        }
        for (int i = 0; i < 10; i++) {
            start = read_QPC();
            dpm = new MSTTreeMacierz(&ttm, 1); //Kruskal macierzowo
            elapsed = read_QPC() - start;
            ZachowajCzas();
            tmp += timeus;
        }
        tmp = tmp / 10;
        zapiszStatystykeDoPliku(nazwaPliku, tmp);
        tmp = 0;

        for (int i = 0; i < 10; i++) {
            start = read_QPC();
            dpl = new MSTTreeLista(&tl, 1); //Kruskal listowo
            elapsed = read_QPC() - start;
            ZachowajCzas();
            tmp += timeus;
        }
        tmp = tmp / 10;
        zapiszStatystykeDoPliku("statystykiKruskalListowo.txt", tmp);
        tmp = 0;
    }

    for(int i=1; i<=4; i++) {                             //test dla 50 elementów
        int lw=50;
        float gestosc=i*0.25;
        ostringstream ss;
        ss << gestosc;
        string str = ss.str();
        zapiszDoPliku(nazwaPliku, "\nTest Kruskala dla 50 elementow i gestosci ");
        zapiszDoPliku(nazwaPliku, str);
        zapiszDoPliku(nazwaPliku, " ");
        zapiszDoPliku("statystykiKruskalListowo.txt", "\nTest dla 50 elementow i gestosci ");
        zapiszDoPliku("statystykiKruskalListowo.txt", str);
        zapiszDoPliku("statystykiKruskalListowo.txt", " ");

        ttm.UtworzLosowo(lw, gestosc);
        if (ttm.UtworzLosowo(lw, gestosc) == false) {
            cout << "Graf nie jest spojny!"<<endl;
        } else {
            ttmptab = ttm.getTablica();
            tl.UtworzLosowo(ttmptab, lw, gestosc);
        }
        for (int i = 0; i < 10; i++) {
            start = read_QPC();
            dpm = new MSTTreeMacierz(&ttm, 1); //Kruskal macierzowo
            elapsed = read_QPC() - start;
            ZachowajCzas();
            tmp += timeus;
        }
        tmp = tmp / 10;
        zapiszStatystykeDoPliku(nazwaPliku, tmp);
        tmp = 0;

        for (int i = 0; i < 10; i++) {
            start = read_QPC();
            dpl = new MSTTreeLista(&tl, 1); //Kruskal listowo
            elapsed = read_QPC() - start;
            ZachowajCzas();
            tmp += timeus;
        }
        tmp = tmp / 10;
        zapiszStatystykeDoPliku("statystykiKruskalListowo.txt", tmp);
        tmp = 0;
    }


    for(int i=1; i<=4; i++) {                             //test dla 100 elementów
        int lw=100;
        float gestosc=i*0.25;
        ostringstream ss;
        ss << gestosc;
        string str = ss.str();
        zapiszDoPliku(nazwaPliku, "\nTest Kruskala dla 100 elementow i gestosci ");
        zapiszDoPliku(nazwaPliku, str);
        zapiszDoPliku(nazwaPliku, " ");
        zapiszDoPliku("statystykiKruskalListowo.txt", "\nTest dla 100 elementow i gestosci ");
        zapiszDoPliku("statystykiKruskalListowo.txt", str);
        zapiszDoPliku("statystykiKruskalListowo.txt", " ");

        ttm.UtworzLosowo(lw, gestosc);
        if (ttm.UtworzLosowo(lw, gestosc) == false) {
            cout << "Graf nie jest spojny!"<<endl;
        } else {
            ttmptab = ttm.getTablica();
            tl.UtworzLosowo(ttmptab, lw, gestosc);
        }
        for (int i = 0; i < 10; i++) {
            start = read_QPC();
            dpm = new MSTTreeMacierz(&ttm, 1); //Kruskal macierzowo
            elapsed = read_QPC() - start;
            ZachowajCzas();
            tmp += timeus;
        }
        tmp = tmp / 10;
        zapiszStatystykeDoPliku(nazwaPliku, tmp);
        tmp = 0;

        for (int i = 0; i < 10; i++) {
            start = read_QPC();
            dpl = new MSTTreeLista(&tl, 1); //Kruskal listowo
            elapsed = read_QPC() - start;
            ZachowajCzas();
            tmp += timeus;
        }
        tmp = tmp / 10;
        zapiszStatystykeDoPliku("statystykiKruskalListowo.txt", tmp);
        tmp = 0;
    }

    for(int i=1; i<=4; i++) {                             //test dla 75 elementów
        int lw=75;
        float gestosc=i*0.25;
        ostringstream ss;
        ss << gestosc;
        string str = ss.str();
        zapiszDoPliku(nazwaPliku, "\nTest Kruskala dla 75 elementow i gestosci ");
        zapiszDoPliku(nazwaPliku, str);
        zapiszDoPliku(nazwaPliku, " ");
        zapiszDoPliku("statystykiKruskalListowo.txt", "\nTest dla 75 elementow i gestosci ");
        zapiszDoPliku("statystykiKruskalListowo.txt", str);
        zapiszDoPliku("statystykiKruskalListowo.txt", " ");

        ttm.UtworzLosowo(lw, gestosc);
        if (ttm.UtworzLosowo(lw, gestosc) == false) {
            cout << "Graf nie jest spojny!"<<endl;
        } else {
            ttmptab = ttm.getTablica();
            tl.UtworzLosowo(ttmptab, lw, gestosc);
        }
        for (int i = 0; i < 10; i++) {
            start = read_QPC();
            dpm = new MSTTreeMacierz(&ttm, 1); //Kruskal macierzowo
            elapsed = read_QPC() - start;
            ZachowajCzas();
            tmp += timeus;
        }
        tmp = tmp / 10;
        zapiszStatystykeDoPliku(nazwaPliku, tmp);
        tmp = 0;

        for (int i = 0; i < 10; i++) {
            start = read_QPC();
            dpl = new MSTTreeLista(&tl, 1); //Kruskal listowo
            elapsed = read_QPC() - start;
            ZachowajCzas();
            tmp += timeus;
        }
        tmp = tmp / 10;
        zapiszStatystykeDoPliku("statystykiKruskalListowo.txt", tmp);
        tmp = 0;
    }
}

void Testy::statDikstra(std::string nazwaPliku) {
    signed int ** ttmptab=new signed int* [0];
    float tmp = 0;

    for(int i=1; i<=4; i++) {                             //test dla 10 elementów
        int lw=10;
        float gestosc=i*0.25;
        ostringstream ss;
        ss << gestosc;
        string str = ss.str();
        zapiszDoPliku(nazwaPliku, "\nTest dla 10 elementow i gestosci ");
        zapiszDoPliku(nazwaPliku, str);
        zapiszDoPliku(nazwaPliku, " ");
        zapiszDoPliku("statystykiDikstralListowo.txt", "\nTest dla 10 elementow i gestosci ");
        zapiszDoPliku("statystykiDikstralListowo.txt", str);
        zapiszDoPliku("statystykiDikstralListowo.txt", " ");

        ttm.UtworzLosowo(lw, gestosc);
        if (ttm.UtworzLosowo(lw, gestosc) == false) {
            cout << "Graf nie jest spojny!"<<endl;
        } else {
            ttmptab = ttm.getTablica();
            tl.UtworzLosowo(ttmptab, lw, gestosc);
        }
        for (int i = 0; i < 10; i++) {
            start = read_QPC();
            tsdm=new NajkrotszaSciezkaMacierz(ttm,0,1);
            elapsed = read_QPC() - start;
            ZachowajCzas();
            tmp += timeus;
        }
        tmp = tmp / 10;
        zapiszStatystykeDoPliku(nazwaPliku, tmp);
        tmp = 0;

        for (int i = 0; i < 10; i++) {
            start = read_QPC();
            tsdl=new NajkrotszaSciezkaLista(tl,0,1);
            elapsed = read_QPC() - start;
            ZachowajCzas();
            tmp += timeus;
        }
        tmp = tmp / 10;
        zapiszStatystykeDoPliku("statystykiDikstralListowo.txt", tmp);
        tmp = 0;
    }

    for(int i=1; i<=4; i++) {                             //test dla 20 elementów
        int lw=20;
        float gestosc=i*0.25;
        ostringstream ss;
        ss << gestosc;
        string str = ss.str();
        zapiszDoPliku(nazwaPliku, "\nTest dla 20 elementow i gestosci ");
        zapiszDoPliku(nazwaPliku, str);
        zapiszDoPliku(nazwaPliku, " ");
        zapiszDoPliku("statystykiDikstralListowo.txt", "\nTest dla 20 elementow i gestosci ");
        zapiszDoPliku("statystykiDikstralListowo.txt", str);
        zapiszDoPliku("statystykiDikstralListowo.txt", " ");

        ttm.UtworzLosowo(lw, gestosc);
        if (ttm.UtworzLosowo(lw, gestosc) == false) {
            cout << "Graf nie jest spojny!"<<endl;
        } else {
            ttmptab = ttm.getTablica();
            tl.UtworzLosowo(ttmptab, lw, gestosc);
        }
        for (int i = 0; i < 10; i++) {
            start = read_QPC();
            tsdm=new NajkrotszaSciezkaMacierz(ttm,0,1);
            elapsed = read_QPC() - start;
            ZachowajCzas();
            tmp += timeus;
        }
        tmp = tmp / 10;
        zapiszStatystykeDoPliku(nazwaPliku, tmp);
        tmp = 0;

        for (int i = 0; i < 10; i++) {
            start = read_QPC();
            tsdl=new NajkrotszaSciezkaLista(tl,0,1);
            elapsed = read_QPC() - start;
            ZachowajCzas();
            tmp += timeus;
        }
        tmp = tmp / 10;
        zapiszStatystykeDoPliku("statystykiDikstralListowo.txt", tmp);
        tmp = 0;
    }


    for(int i=1; i<=4; i++) {                             //test dla 50 elementów
        int lw=50;
        float gestosc=i*0.25;
        ostringstream ss;
        ss << gestosc;
        string str = ss.str();
        zapiszDoPliku(nazwaPliku, "\nTest dla 50 elementow i gestosci ");
        zapiszDoPliku(nazwaPliku, str);
        zapiszDoPliku(nazwaPliku, " ");
        zapiszDoPliku("statystykiDikstralListowo.txt", "\nTest dla 50 elementow i gestosci ");
        zapiszDoPliku("statystykiDikstralListowo.txt", str);
        zapiszDoPliku("statystykiDikstralListowo.txt", " ");

        ttm.UtworzLosowo(lw, gestosc);
        if (ttm.UtworzLosowo(lw, gestosc) == false) {
            cout << "Graf nie jest spojny!"<<endl;
        } else {
            ttmptab = ttm.getTablica();
            tl.UtworzLosowo(ttmptab, lw, gestosc);
        }
        for (int i = 0; i < 10; i++) {
            start = read_QPC();
            tsdm=new NajkrotszaSciezkaMacierz(ttm,0,1);
            elapsed = read_QPC() - start;
            ZachowajCzas();
            tmp += timeus;
        }
        tmp = tmp / 10;
        zapiszStatystykeDoPliku(nazwaPliku, tmp);
        tmp = 0;

        for (int i = 0; i < 10; i++) {
            start = read_QPC();
            tsdl=new NajkrotszaSciezkaLista(tl,0,1);
            elapsed = read_QPC() - start;
            ZachowajCzas();
            tmp += timeus;
        }
        tmp = tmp / 10;
        zapiszStatystykeDoPliku("statystykiDikstralListowo.txt", tmp);
        tmp = 0;
    }


    for(int i=1; i<=4; i++) {                             //test dla 100 elementów
        int lw=100;
        float gestosc=i*0.25;
        ostringstream ss;
        ss << gestosc;
        string str = ss.str();
        zapiszDoPliku(nazwaPliku, "\nTest dla 100 elementow i gestosci ");
        zapiszDoPliku(nazwaPliku, str);
        zapiszDoPliku(nazwaPliku, " ");
        zapiszDoPliku("statystykiDikstralListowo.txt", "\nTest dla 100 elementow i gestosci ");
        zapiszDoPliku("statystykiDikstralListowo.txt", str);
        zapiszDoPliku("statystykiDikstralListowo.txt", " ");

        ttm.UtworzLosowo(lw, gestosc);
        if (ttm.UtworzLosowo(lw, gestosc) == false) {
            cout << "Graf nie jest spojny!"<<endl;
        } else {
            ttmptab = ttm.getTablica();
            tl.UtworzLosowo(ttmptab, lw, gestosc);
        }
        for (int i = 0; i < 10; i++) {
            start = read_QPC();
            tsdm=new NajkrotszaSciezkaMacierz(ttm,0,1);
            elapsed = read_QPC() - start;
            ZachowajCzas();
            tmp += timeus;
        }
        tmp = tmp / 10;
        zapiszStatystykeDoPliku(nazwaPliku, tmp);
        tmp = 0;

        for (int i = 0; i < 10; i++) {
            start = read_QPC();
            tsdl=new NajkrotszaSciezkaLista(tl,0,1);
            elapsed = read_QPC() - start;
            ZachowajCzas();
            tmp += timeus;
        }
        tmp = tmp / 10;
        zapiszStatystykeDoPliku("statystykiDikstralListowo.txt", tmp);
        tmp = 0;
    }


    for(int i=1; i<=4; i++) {                             //test dla 75 elementów
        int lw=75;
        float gestosc=i*0.25;
        ostringstream ss;
        ss << gestosc;
        string str = ss.str();
        zapiszDoPliku(nazwaPliku, "\nTest dla 75 elementow i gestosci ");
        zapiszDoPliku(nazwaPliku, str);
        zapiszDoPliku(nazwaPliku, " ");
        zapiszDoPliku("statystykiDikstralListowo.txt", "\nTest dla 75 elementow i gestosci ");
        zapiszDoPliku("statystykiDikstralListowo.txt", str);
        zapiszDoPliku("statystykiDikstralListowo.txt", " ");

        ttm.UtworzLosowo(lw, gestosc);
        if (ttm.UtworzLosowo(lw, gestosc) == false) {
            cout << "Graf nie jest spojny!"<<endl;
        } else {
            ttmptab = ttm.getTablica();
            tl.UtworzLosowo(ttmptab, lw, gestosc);
        }
        for (int i = 0; i < 10; i++) {
            start = read_QPC();
            tsdm=new NajkrotszaSciezkaMacierz(ttm,0,1);
            elapsed = read_QPC() - start;
            ZachowajCzas();
            tmp += timeus;
        }
        tmp = tmp / 10;
        zapiszStatystykeDoPliku(nazwaPliku, tmp);
        tmp = 0;

        for (int i = 0; i < 10; i++) {
            start = read_QPC();
            tsdl=new NajkrotszaSciezkaLista(tl,0,1);
            elapsed = read_QPC() - start;
            ZachowajCzas();
            tmp += timeus;
        }
        tmp = tmp / 10;
        zapiszStatystykeDoPliku("statystykiDikstralListowo.txt", tmp);
        tmp = 0;
    }

}


void Testy::statFordBellman(std::string nazwaPliku) {
    signed int ** ttmptab=new signed int* [0];
    float tmp = 0;

    for(int i=1; i<=4; i++) {                             //test dla 10 elementów
        int lw=10;
        float gestosc=i*0.25;
        ostringstream ss;
        ss << gestosc;
        string str = ss.str();
        zapiszDoPliku(nazwaPliku, "\nTest dla 10 elementow i gestosci ");
        zapiszDoPliku(nazwaPliku, str);
        zapiszDoPliku(nazwaPliku, " ");
        zapiszDoPliku("statystykiFBListowo.txt", "\nTest dla 10 elementow i gestosci ");
        zapiszDoPliku("statystykiFBListowo.txt", str);
        zapiszDoPliku("statystykiFBListowo.txt", " ");

        ttm.UtworzLosowo(lw, gestosc);
        if (ttm.UtworzLosowo(lw, gestosc) == false) {
            cout << "Graf nie jest spojny!"<<endl;
        } else {
            ttmptab = ttm.getTablica();
            tl.UtworzLosowo(ttmptab, lw, gestosc);
        }
        for (int i = 0; i < 10; i++) {
            start = read_QPC();
            tsbfm=new NSBellmanFordMacierz(ttm,0,1);
            elapsed = read_QPC() - start;
            ZachowajCzas();
            tmp += timeus;
        }
        tmp = tmp / 10;
        zapiszStatystykeDoPliku(nazwaPliku, tmp);
        tmp = 0;

        for (int i = 0; i < 10; i++) {
            start = read_QPC();
            tsbfl=new NSBellmanFordLista(tl,0,1);
            elapsed = read_QPC() - start;
            ZachowajCzas();
            tmp += timeus;
        }
        tmp = tmp / 10;
        zapiszStatystykeDoPliku("statystykiFBListowo.txt", tmp);
        tmp = 0;
    }

    for(int i=1; i<=4; i++) {                             //test dla 20 elementów
        int lw=20;
        float gestosc=i*0.25;
        ostringstream ss;
        ss << gestosc;
        string str = ss.str();
        zapiszDoPliku(nazwaPliku, "\nTest dla 20 elementow i gestosci ");
        zapiszDoPliku(nazwaPliku, str);
        zapiszDoPliku(nazwaPliku, " ");
        zapiszDoPliku("statystykiFBListowo.txt", "\nTest dla 20 elementow i gestosci ");
        zapiszDoPliku("statystykiFBListowo.txt", str);
        zapiszDoPliku("statystykiFBListowo.txt", " ");

        ttm.UtworzLosowo(lw, gestosc);
        if (ttm.UtworzLosowo(lw, gestosc) == false) {
            cout << "Graf nie jest spojny!"<<endl;
        } else {
            ttmptab = ttm.getTablica();
            tl.UtworzLosowo(ttmptab, lw, gestosc);
        }
        for (int i = 0; i < 10; i++) {
            start = read_QPC();
            tsbfm=new NSBellmanFordMacierz(ttm,0,1);
            elapsed = read_QPC() - start;
            ZachowajCzas();
            tmp += timeus;
        }
        tmp = tmp / 10;
        zapiszStatystykeDoPliku(nazwaPliku, tmp);
        tmp = 0;

        for (int i = 0; i < 10; i++) {
            start = read_QPC();
            tsbfl=new NSBellmanFordLista(tl,0,1);
            elapsed = read_QPC() - start;
            ZachowajCzas();
            tmp += timeus;
        }
        tmp = tmp / 10;
        zapiszStatystykeDoPliku("statystykiFBListowo.txt", tmp);
        tmp = 0;
    }


    for(int i=1; i<=4; i++) {                             //test dla 50 elementów
        int lw=50;
        float gestosc=i*0.25;
        ostringstream ss;
        ss << gestosc;
        string str = ss.str();
        zapiszDoPliku(nazwaPliku, "\nTest dla 50 elementow i gestosci ");
        zapiszDoPliku(nazwaPliku, str);
        zapiszDoPliku(nazwaPliku, " ");
        zapiszDoPliku("statystykiFBListowo.txt", "\nTest dla 50 elementow i gestosci ");
        zapiszDoPliku("statystykiFBListowo.txt", str);
        zapiszDoPliku("statystykiFBListowo.txt", " ");

        ttm.UtworzLosowo(lw, gestosc);
        if (ttm.UtworzLosowo(lw, gestosc) == false) {
            cout << "Graf nie jest spojny!"<<endl;
        } else {
            ttmptab = ttm.getTablica();
            tl.UtworzLosowo(ttmptab, lw, gestosc);
        }
        for (int i = 0; i < 10; i++) {
            start = read_QPC();
            tsbfm=new NSBellmanFordMacierz(ttm,0,1);
            elapsed = read_QPC() - start;
            ZachowajCzas();
            tmp += timeus;
        }
        tmp = tmp / 10;
        zapiszStatystykeDoPliku(nazwaPliku, tmp);
        tmp = 0;

        for (int i = 0; i < 10; i++) {
            start = read_QPC();
            tsbfl=new NSBellmanFordLista(tl,0,1);
            elapsed = read_QPC() - start;
            ZachowajCzas();
            tmp += timeus;
        }
        tmp = tmp / 10;
        zapiszStatystykeDoPliku("statystykiFBListowo.txt", tmp);
        tmp = 0;
    }


    for(int i=1; i<=4; i++) {                             //test dla 100 elementów
        int lw=100;
        float gestosc=i*0.25;
        ostringstream ss;
        ss << gestosc;
        string str = ss.str();
        zapiszDoPliku(nazwaPliku, "\nTest dla 100 elementow i gestosci ");
        zapiszDoPliku(nazwaPliku, str);
        zapiszDoPliku(nazwaPliku, " ");
        zapiszDoPliku("statystykiFBListowo.txt", "\nTest dla 100 elementow i gestosci ");
        zapiszDoPliku("statystykiFBListowo.txt", str);
        zapiszDoPliku("statystykiFBListowo.txt", " ");

        ttm.UtworzLosowo(lw, gestosc);
        if (ttm.UtworzLosowo(lw, gestosc) == false) {
            cout << "Graf nie jest spojny!"<<endl;
        } else {
            ttmptab = ttm.getTablica();
            tl.UtworzLosowo(ttmptab, lw, gestosc);
        }
        for (int i = 0; i < 10; i++) {
            start = read_QPC();
            tsbfm=new NSBellmanFordMacierz(ttm,0,1);
            elapsed = read_QPC() - start;
            ZachowajCzas();
            tmp += timeus;
        }
        tmp = tmp / 10;
        zapiszStatystykeDoPliku(nazwaPliku, tmp);
        tmp = 0;

        for (int i = 0; i < 10; i++) {
            start = read_QPC();
            tsbfl=new NSBellmanFordLista(tl,0,1);
            elapsed = read_QPC() - start;
            ZachowajCzas();
            tmp += timeus;
        }
        tmp = tmp / 10;
        zapiszStatystykeDoPliku("statystykiFBListowo.txt", tmp);
        tmp = 0;
    }


    for(int i=1; i<=4; i++) {                             //test dla 75 elementów
        int lw=75;
        float gestosc=i*0.25;
        ostringstream ss;
        ss << gestosc;
        string str = ss.str();
        zapiszDoPliku(nazwaPliku, "\nTest dla 75 elementow i gestosci ");
        zapiszDoPliku(nazwaPliku, str);
        zapiszDoPliku(nazwaPliku, " ");
        zapiszDoPliku("statystykiFBListowo.txt", "\nTest dla 75 elementow i gestosci ");
        zapiszDoPliku("statystykiFBListowo.txt", str);
        zapiszDoPliku("statystykiFBListowo.txt", " ");

        ttm.UtworzLosowo(lw, gestosc);
        if (ttm.UtworzLosowo(lw, gestosc) == false) {
            cout << "Graf nie jest spojny!"<<endl;
        } else {
            ttmptab = ttm.getTablica();
            tl.UtworzLosowo(ttmptab, lw, gestosc);
        }
        for (int i = 0; i < 10; i++) {
            start = read_QPC();
            tsbfm=new NSBellmanFordMacierz(ttm,0,1);
            elapsed = read_QPC() - start;
            ZachowajCzas();
            tmp += timeus;
        }
        tmp = tmp / 10;
        zapiszStatystykeDoPliku(nazwaPliku, tmp);
        tmp = 0;

        for (int i = 0; i < 10; i++) {
            start = read_QPC();
            tsbfl=new NSBellmanFordLista(tl,0,1);
            elapsed = read_QPC() - start;
            ZachowajCzas();
            tmp += timeus;
        }
        tmp = tmp / 10;
        zapiszStatystykeDoPliku("statystykiFBListowo.txt", tmp);
        tmp = 0;
    }

}*/
