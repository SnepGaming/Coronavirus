#ifndef GESTIONE_H_INCLUDED
#define GESTIONE_H_INCLUDED
#include "giocatore.h"
#include "computer.h"
class stato_vita: public giocatore
{
    public:
    void set_morto (int pos)
    { 
        cout<<"debug"<<endl;
        vivo_morto [pos]="Sei morto";
    }
    void set_vivo (int pos)
    { cout<<"debug2"<<endl;
        vivo_morto [pos]="Sei sopravvissuto";
    }    
};

/*
class controllo: simulazione
{
    public:
    simulazione sim;
void selezione(int sel, int genere[], int pos)
{
switch (sel)
{
case 1:
if (genere[pos]==1)
{
sim.simula_maschio(pos);    
}
if (genere[pos]==2)
{
sim.simula_femmina(pos);    
}
    break;
case 2:
    break;

default:
cout<<"Selezione invalida"<<endl;
    break;
}



}
};
*/


#endif //#GESTIONE_H_INCLUDED