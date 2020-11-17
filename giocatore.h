#ifndef GIOCATORE_H_INCLUDED
#define GIOCATORE_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;
class giocatore
{
    protected:
    string Nome_Cognome [30];
    int eta[30];
    int genere [30];
    int n;
    int risorse=0;
    public:
    string vivo_morto [30];
    void set_giocatore(string nc,int e,int g,int i) 
    {
        Nome_Cognome[i]=nc; 
        eta[i]=e;
        genere[i]=g;
    }
    string get_Nome_Cognome(int i) {return Nome_Cognome[i];};
    int get_eta(int i) {return eta[i];};
    int get_genere(int i) {return genere[i];};
    string get_vivo_morto(int i) {return vivo_morto[i];}
    int get_n(){return n;}
    void set_risorse(int ris)
    {
        risorse=ris;
    }
    int get_risorse(){return risorse;}
 


};

class lv_giocatore: public giocatore
{  public:
   
    void load (int n, string nc,int e,int g)
    {
        for(int i=0; i<n; i++)
        {
            cout<<"Inserisci nome del paziente "<<i+1<<endl;
            cin>>nc;
            cout<<"Inserisci l'eta' del paziente "<<i+1<<endl;
            cin>>e;
            cout<<"Inserisci il genere del paziente "<<i+1<< " 1=<<maschio>> 2=<<femmina>>"<<endl;
            cin>>g;
            set_giocatore (nc,e,g,i);
        }
    }

    void visualizza_eta (int n)
    {
        for(int i=0; i<n; i++)
        {
            cout<<"Eta del paziente "<<i+1<<endl;
            cout<<get_eta(i)<<endl;
        }

    }
    void visualizza_vivo_morto (int n)
    {
        for(int i=0; i<n; i++)
        {
            cout<<"Stato del paziente "<<i+1<<" "<<get_vivo_morto(i)<<endl;
        }
    }
};


#endif //GIOCATORE_H_INCLUDED