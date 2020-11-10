#ifndef GESTIONE_H_INCLUDED
#define GESTIONE_H_INCLUDED
#include "computer.h"
#include "giocatore.h"
class stato_vita
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
}
class controllo 
{
    public:
void selezione(int sel, int genere[], int pos)
{
computer_simula sm;
if (sel==1)// 1 gioca pc
{

if (genere[pos]==1)
{
sm.simula_maschio(pos);    
}
if (genere[pos]==1)
{
sm.simula_femmina(pos);    
}
}
else
{
    //classe giocatore utente da implentare 
}


    }
};



#endif //#GESTIONE_H_INCLUDED