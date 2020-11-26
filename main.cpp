#include <iostream>
#include "gamer.hpp"
#include "computer.hpp"
#include "utente.hpp"
#include <stdlib.h>
#include <windows.h>



using namespace std; 

int main () 
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 10);

    
int m_eta, m_genere, m_n, m_sel;

int m_eta, m_genere, n;

string nc;
lv_giocatore cv;

controllo menu;

cout<<"Quante persone vuoi che si infettino da SARS-CoV-2?"<<endl;
cin>>m_n;
cv.load(m_n, nc, m_eta, m_genere);
for (int i=0; i<m_n; i++)
{
    cout<<"Seleziona 1 per simulare o 2 per giocare."<<endl;
    cin>>m_sel;
    menu.selezione(m_sel,i);
    cv.visualizza_vivo_morto(m_n, i);
    
}




    return 0; //merge
}
