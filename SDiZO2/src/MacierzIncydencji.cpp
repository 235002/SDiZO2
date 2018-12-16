#include "MacierzIncydencji.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include <math.h>
#include <iomanip>
using namespace std;

MacierzIncydencji::MacierzIncydencji()
{
    lwierzcholkow = 0;
    lkrawedzi = 0;
    tablica = new signed int *[0];
}

MacierzIncydencji::~MacierzIncydencji()
{
    for(int i=0; i<lwierzcholkow; i++)
        delete [] tablica[i];
    delete tablica;
}

//Metoda wczytuje dane z pliku
bool MacierzIncydencji::Wczytaj(string nazwapliku)
{
    fstream plik;
    plik.open(nazwapliku.c_str());
    if(plik.good())
    {
        int i = 0;
        int j = 0;
        int tmpp, tmpk, tmpw;

        plik >> lkrawedzi;
        plik >>lwierzcholkow;

        tablica = new signed int *[lwierzcholkow];
        for(int i=0; i<lwierzcholkow; i++)
        {
            tablica[i] = new signed int[lkrawedzi];         //Tworzenie wierszy
        }

        for(int i=0; i<lwierzcholkow; i++)                  //Wypelnianie macierzy zerami
        {
            for(int j=0; i<lkrawedzi; j++)
            {
                tablica[i][j] = 0;
            }
        }
        i=0;
        while(i<lkrawedzi);
        {
            plik >> tmpp >> tmpk >>tmpw;
            tablica[tmpp][i] = tmpw;
            tablica[tmpk][i] = -1;
        }
    }
    else
    {
        cout<<endl<<"Nie udalo sie otworzyc pliku."<<endl;
        return false;
    }
    plik.close();
    return true;
}

//Metoda zapisuje dane do pliku
void MacierzIncydencji::zapiszDoPliku(string nazwapliku, string tresc)
{
    ofstream plik;
    plik.open(nazwapliku.c_str(), ios_base::out);
    if(plik.good())
        plik << tresc;
    plik.close();
}

//Metoda tworzy losowe wartosci dla macierzy
bool MacierzIncydencji::UtworzLosowo(int lwierzcholkow, float gestosc)
{
    string dopliku;
    stringstream ss;
    srand(time(NULL));
    int tmp;
    this->lwierzcholkow = lwierzcholkow;
    lkrawedzi = floor((gestosc*(lwierzcholkow*(lwierzcholkow-1)))/2);
    if(lkrawedzi<lwierzcholkow-1)
    {
        return false;
    }
    else
    {
        ss << lkrawedzi << " " << lwierzcholkow<<"\n";
        tablica = new signed int *[lwierzcholkow];

        for(int i=0; i<lwierzcholkow; i++)
        {
            tablica[i] = new signed int[lkrawedzi];         //Tworzenie wierszy
        }
        for(int i=0; i<lwierzcholkow; i++)
        {
            for(int j=0; j<lkrawedzi; j++)
                tablica[i][j] = 0;
        }
        if(lkrawedzi>0)
        {
            tablica[0][0] = 1;  //tablica[0][0] = -1
        }
        for(int i=0; i<lwierzcholkow-1; i++)
        {
            tablica[i+1][i] = -1;   //tablica[i+1][i] = i+1;
            if(i>0)
            {
                tmp = rand() % (i+1);
                tablica[tmp][i] = rand()%100;
            }

            ss << tmp << " ";
            ss << i+1 << " ";
            ss << tablica[tmp][i] << "\n";
            dopliku = dopliku + ss.str();
        }

        for (int i = lwierzcholkow - 1; i < lkrawedzi; i++) { //nadprogramowe krawedzie
            int tmp = rand() % lwierzcholkow;
            tablica[tmp][i] = rand()%(100);//(i + 1);
            int tmp1 = rand() % lwierzcholkow;
            while (tmp1 == tmp) {
                tmp1 = rand() % lwierzcholkow;
            }
            tablica[tmp1][i] = -1;
            ss << tmp<<" ";
            ss << tmp1<<" ";
            ss << tablica[tmp][i]<<"\n";
            //dopliku=dopliku+ss.str();
        }
        dopliku=ss.str();
        //cout<<dopliku;
        zapiszDoPliku("graf4.txt",dopliku);
        return true;

    }

}

//Metoda wyswietla macierz
void MacierzIncydencji::Wyswietl()
{
    cout<<endl;
    for(int i=0; i<lkrawedzi; i++)
    {
        cout<<setw(3)<<i;
    }
    cout<<endl<<endl;
    for(int i = 0; i < lwierzcholkow; i++) {
        cout << setw(3) << i;
        for(int j = 0; j < lkrawedzi; j++) {
            cout << setw(3) << tablica[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

//Metoda zwraca wskaznik na tablice
signed int **MacierzIncydencji::getTablica()
{
    return tablica;
}

//Metoda zwraca ilosc krawedzi
int MacierzIncydencji::getLKrawedzi()const
{
    return lkrawedzi;
}

//Metoda zwraca ilosc wierzcholkow
int MacierzIncydencji::getLWierzcholkow()const
{
    return lwierzcholkow;
}


