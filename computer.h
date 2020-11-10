#ifndef COMPUTER_H_INCLUDED
#define COMPUTER_H_INCLUDED
#include <giocatore.h>
#include <iostream>
#include <ghrandom.hpp>
using Random = effolkronium::random_static;

class computer_simula: public giocatore
{

void simula_maschio (int pos)
{
    bool morto=false;
    if (età[pos]<=40, età [pos]>0)
    {
        auto morto= Random::get<bool>(0.02); //randomizzatore da libreria ghrandom.hpp 2% di possibilità di morire
        if (morto==true)
        {
        vivo_morto [pos]="Sei morto";
        }
        else
        {
        vivo_morto [pos]="Sei sopravvissuto";
        }
    }
     if (età[pos]<=70, età [pos]>40)
    {
        auto morto= Random::get<bool>(0.04);
        if (morto==true)
        {
        vivo_morto [pos]="Sei morto";
        }
        else
        {
        vivo_morto [pos]="Sei sopravvissuto";
        }
    }
         if (età [pos]>70)
    {
        auto morto = Random::get<bool>(0.32);
        if (morto==true)
        {
        vivo_morto [pos]="Sei morto";
        }
        else
        {
        vivo_morto [pos]="Sei sopravvissuto";
        }
    }
        

}
void simula_femmina (int pos)
{
    bool morto=false;
    if (età[pos]<=40, età [pos]>0)
    {
        auto morto = Random::get<bool>(0.01); //randomizzatore da libreria ghrandom.hpp 1% di possibilità di morire
        if (morto==true)
        {
        vivo_morto [pos]="Sei morto";
        }
        else
        {
        vivo_morto [pos]="Sei sopravvissuto";
        }
    }
     if (età[pos]<=70, età [pos]>40)
    {
        auto morto = Random::get<bool>(0.02);
        if (morto==true)
        {
        vivo_morto [pos]="Sei morto";
        }
        else
        {
        vivo_morto [pos]="Sei sopravvissuto";
        }
    }
         if (età [pos]>70)
    {
        auto morto = Random::get<bool>(0.3);
        if (morto==true)
        {
        vivo_morto [pos]="Sei morto";
        }
        else
        {
        vivo_morto [pos]="Sei sopravvissuto";
        }
    }
        
        
}
};

#endif //COMPUTER_H_INCLUDED