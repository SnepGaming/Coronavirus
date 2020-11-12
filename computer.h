#ifndef COMPUTER_H_INCLUDED
#define COMPUTER_H_INCLUDED
#include "giocatore.h"
#include <iostream>
#include "ghrandom.h"
#include "gestione.h"
using Random = effolkronium::random_static;
using namespace std;
stato_vita sv;

class computer_simula: public giocatore
{
public: //da mettere protected
void simula_maschio (int pos)
{
    int ceta=eta[pos];
    bool morto=false;
    if (ceta<=40 || ceta>0)
    {
        auto morto= Random::get<bool>(0.02); //randomizzatore da libreria ghrandom.hpp 2% di possibilità di morire
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
        auto morto = Random::get<bool>(0.01); //randomizzatore da libreria ghrandom.hpp 1% di possibilità di morire
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

#endif //COMPUTER_H_INCLUDED