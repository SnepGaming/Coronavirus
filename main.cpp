#include <iostream>
#include "giocatore.hpp"
#include "computer.hpp"
#include "gestione.hpp"
#include "librerie/random.hpp"
#include <stdlib.h>
#include <windows.h>

//main

using namespace std; 

int main () 
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 10);
    
int m_eta, m_genere, n;
string nc;
string c;
getline(cin,c);
lv_giocatore cv;
cout<<"n"<<endl;
cin>>n;
cv.load(n, nc, m_eta, m_genere);
cv.visualizza_eta(n);
int sel;
cout<<"sel"<<endl;
cin>>sel;
//controllo cn;
simulazione sn;
//cn.selezione(sel,1);
sn.simula_maschio(0);
cv.visualizza_vivo_morto(n);
    return 0; //merge
}
