#ifndef COMPUTER_H_INCLUDED
#define COMPUTER_H_INCLUDED
#include "giocatore.h"
#include <iostream>
//#include "ghrandom.h"
#include "random.hpp"
#include "gestione.h"
using Random = effolkronium::random_static;
using namespace std;
stato_vita sv;

class simulazione: public giocatore
{
public: //da mettere protected
void simula_maschio (int pos)
{
    int ceta=eta[pos];
    bool morto=false;
    if (ceta<=40 || ceta>0)
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
     if (ceta<=70 || ceta>40)
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
         if (ceta>70)
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
    int ceta=eta[pos];
    bool morto=false;
    if (ceta<=40 || ceta>0)
    {
        auto morto = Random::get<bool>(0.01); //randomizzatore da libreria ghrandom.h 1% di possibilità di morire
        if (morto==true)
        {
        sv.set_morto(pos);
        }
        else
        {
        sv.set_vivo(pos);
        }
    }
     if (ceta<=70 || ceta>40)
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
         if (ceta>70)
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

class controllo: simulazione
{
    public:
    simulazione sim;
void selezione(int sel, int pos)
{
switch (sel)
{
case (1):
if (get_genere(pos)==1)
{
sim.simula_maschio(pos);    
}
if (get_genere(pos)==2)
{
sim.simula_femmina(pos);    
}
    break;
case (2):
cout<<"emy"<<endl;
    break;

default:
cout<<"Selezione invalida"<<endl;
    break;
}



}
};

#endif //COMPUTER_H_INCLUDED