#pragma once

#include <iostream>
#include "gamer.hpp"
#include "utente.hpp"
#include "librerie/random.hpp"


using Random = effolkronium::random_static;
using namespace std;


class simulazione:  giocatore
{
private:
stato_vita sv;
public: 
void simula_maschio (int pos)
{
    bool morto=false; 
    if ((get_eta(pos)<=40) && (get_eta(pos)>0))
    {
         
        auto morto= Random::get<bool>(0.02); //randomizzatore da libreria random.hpp 2% di possibilità di morire
        if (morto==true)
        {
        sv.set_morto(pos);
        }
        else
        {
        sv.set_vivo(pos);
        }
    }
     if ((get_eta(pos)<=70) && (get_eta(pos)>40))
    {
        auto morto= Random::get<bool>(0.04);
        if (morto==true)
        {
        sv.set_morto(pos);
        }                                               
        else
        {
        sv.set_vivo(pos);
        }
    }
         if (get_eta(pos)>70)
    {
        auto morto = Random::get<bool>(0.32);
        if (morto==true)
        {
        sv.set_morto(pos);
        }
        else
        {
        sv.set_vivo(pos);
        }
    }
        

}
void simula_femmina (int pos)
{
    
    bool morto=false;
    if ((get_eta(pos)<=40) && (get_eta(pos)>0))
    {
       
        auto morto = Random::get<bool>(0.01); //randomizzatore da libreria random.hpp 1% di possibilità di morire
        if (morto==true)
        {
        sv.set_morto(pos);
        }
        else
        {
        sv.set_vivo(pos);
        }
    }
     if ((get_eta(pos)<=70) && (get_eta(pos)>40))
    {
        auto morto = Random::get<bool>(0.02);
        if (morto==true)
        {
        sv.set_morto(pos);
        }
        else
        {
        sv.set_vivo(pos);
        }
    }
         if (get_eta(pos)>70)
    {
        auto morto = Random::get<bool>(0.3);
        if (morto==true)
        {
        sv.set_morto(pos);
        }
        else
        {
        sv.set_vivo(pos);
        }
    }
        
        
}
};

class controllo
{
    public:
    simulazione sim;
    gioco gm;
    giocatore gio;
void selezione(int sel, int pos)
{
switch (sel)
{
case (1):
if (gio.get_genere(pos)==1)
{
sim.simula_maschio(pos);    
}
if (gio.get_genere(pos)==2)
{
sim.simula_femmina(pos);    
}
    break;
case (2):
gm.game();
    break;

default:
cout<<"Selezione invalida"<<endl;
    break;
}



}
};

