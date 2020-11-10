#ifndef COMPUTER_H_INCLUDED
#define COMPUTER_H_INCLUDED
#include <giocatore.h>
#include <iostream>
#include <ghrandom.hpp>
#include <gestione.h>
using Random = effolkronium::random_static;
stato_vita sv;

class computer_simula: public giocatore
{
public:
void simula_maschio (int pos)
{
    int cetà=età[pos];
    bool morto=false;
    if (cetà<=40, età [pos]>0)
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
     if (cetà<=70, età [pos]>40)
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
         if (età [pos]>70)
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
    if (cetà<=40, età [pos]>0)
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
     if (cetà<=70, età [pos]>40)
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
         if (età [pos]>70)
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