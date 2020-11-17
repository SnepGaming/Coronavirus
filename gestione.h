#ifndef GESTIONE_H_INCLUDED
#define GESTIONE_H_INCLUDED
#include "giocatore.h"
#include "computer.h"
#include <iostream>
using namespace std;

class stato_vita: public giocatore
{
    public:
    void set_morto (int pos)
    { 
        cout<<"debug"<<endl;
        vivo_morto [pos]="Seimorto";
    }
    void set_vivo (int pos)
    { cout<<"debug2"<<endl;
        vivo_morto [pos]="Seisopravvissuto";
    }    
};

/*class controllo: simulazione
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
};*/



#endif //#GESTIONE_H_INCLUDED