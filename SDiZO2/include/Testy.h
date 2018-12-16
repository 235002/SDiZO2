#ifndef TESTY_H
#define TESTY_H
#include<conio.h>
#include<string>
#include<iostream>
#include <afxres.h>
#include <iomanip>
#include <fstream>
#include "MacierzIncydencji.h"
#include "ListaSasiedztwa.h"
#include "NajkrotszaSciezkaLista.h"
#include "NajkrotszaSciezkaMacierz.h"
#include "NSBellmanFordLista.h"
#include "NSBellmanFordMacierz.h"
#include "MSTTreeMacierz.h"
#include "MSTTreeLista.h"

class Testy
{
public:
    long long int frequency, start, elapsed;
    float times;
    float timems;
    float timeus;
    MacierzIncydencji ttm;
    ListaSasiedztwa tl;
    NajkrotszaSciezkaLista * tsdl;
    NajkrotszaSciezkaMacierz * tsdm;
    NSBellmanFordLista * tsbfl;
    NSBellmanFordMacierz * tsbfm;
    MSTTreeMacierz *dpm;
    MSTTreeLista *dpl;
public:
    void ZachowajCzas();
    long long int read_QPC();
    void zapiszStatystykeDoPliku(std::string nazwapliku, float timeus);
    void zapiszDoPliku(std::string nazwapliku, std::string tresc);
    void statMST( std::string nazwaPliku);
    void statMSTKrusk( std::string nazwaPliku);
    void statDikstra(std::string nazwaPliku);
    void statFordBellman(std::string nazwaPliku);
};

#endif // TESTY_H
