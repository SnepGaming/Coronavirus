#ifndef GIOCATORE_HPP_INCLUDED
#define GIOCATORE_HPP_INCLUDED
#include <iostream>
#include <string>
using namespace std; 

//giocatore

class giocatore
{
    protected:
    string Nome_Cognome [30]; 
    int eta[30];
    int genere [30];
    int n;
    int risorse=0;
    bool vivo_morto [30];
    public:
    
    void set_giocatore(string nc,int e,int g,int i) 
    {
        Nome_Cognome[i]=nc; 
        eta[i]=e;
        genere[i]=g;
    }
    string get_Nome_Cognome(int i) {return Nome_Cognome[i];};
    int get_eta(int i) {return eta[i];};
    int get_genere(int i) {return genere[i];};
    bool get_vivo_morto(int i) {return vivo_morto[i];}
    void set_vivo_morto(bool stato, int pos) {vivo_morto[pos]=stato;}
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
            if (get_vivo_morto(i)==true)
            {
                 cout<<"Stato del paziente "<<i+1<<" Sei Vivo :)"<<endl;
            }
            else
            {
                cout<<"Stato del paziente "<<i+1<<" Sei Morto :("<<endl;
            }
            
           
        }
    }
};

class stato_vita
{
    private:
    giocatore gg;
    public:
    void set_morto (int pos)
    { 
        cout<<"debug"<<endl;
        gg.set_vivo_morto(false,pos);
    }
    void set_vivo (int pos)
    {   cout<<"debug2"<<endl;
        gg.set_vivo_morto(true,pos);
    }    
};


#endif //GIOCATORE_HPP_INCLUDED