#ifndef GESTIONE_H_INCLUDED
#define GESTIONE_H_INCLUDED
#include "computer.h"
#include "giocatore.h"
#include "ghrandom.h"
computer_simula sm;

class stato_vita: public giocatore
{
    public:
    void set_morto (int pos)
    { 
        vivo_morto [pos]="Sei morto";
    }
    void set_vivo (int pos)
    { 
        vivo_morto [pos]="Sei sopravvissuto";
    }    
};


class controllo: public stato_vita
{
    public:
  
void selezione(int sel, int genere[], int pos)
{



switch (sel)
{
case 1:
if (genere[pos]==1)
{
simula_maschio(pos);    
}
if (genere[pos]==2)
{
simula_femmina(pos);    
}
    break;
case (2):
    break;

default:
cout<<"Selezione invalida"<<endl;
    break;
}



}
};



#endif //#GESTIONE_H_INCLUDED