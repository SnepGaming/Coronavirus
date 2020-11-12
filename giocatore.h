#ifndef GIOCATORE_H_INCLUDED
#define GIOCATORE_H_INCLUDED
#include <iostream>
using namespace std;
class giocatore
{
    protected:
    string Nome_Cognome [30];
    int eta[30];
    int genere [30];
    public:
    string vivo_morto [30];
    void set_giocatore(string nc[],int e[],int g[],int i) 
    {
        Nome_Cognome[i]=nc[i]; 
        eta[i]=e[i];
        genere[i]=g[i];
    }
    string get_Nome_Cognome(int i) {return Nome_Cognome[i];};
    int get_eta(int i) {return eta[i];};
    int get_genere(int i) {return genere[i];};


};

/*class lv_giocatore: public giocatore
{  public:
    
    void load (int n)
    {
        for(int i=0; i<n; i++)
        {
            cin>>Nome_Cognome [i];
            cin>>eta[i];
            cin>>genere [i];

        }
    }
};*/


#endif //GIOCATORE_H_INCLUDED