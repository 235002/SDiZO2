#ifndef MACIERZINCYDENCJI_H
#define MACIERZINCYDENCJI_H
#include <iostream>
using namespace std;

class MacierzIncydencji
{
private:
    int lwierzcholkow;
    int lkrawedzi;
    signed int **tablica;

public:
    MacierzIncydencji();
    ~MacierzIncydencji();
    bool Wczytaj(string nazwapliku);
    bool UtworzLosowo(int lwierzcholkow, float gestosc);
    void Wyswietl();
    int getLWierzcholkow() const;
    int getLKrawedzi() const;
    signed int **getTablica();
    bool czyGrafSpojny();
    void zapiszDoPliku(string nazwapliku, string tresc);
};

#endif // MACIERZINCYDENCJI_H
