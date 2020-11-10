#ifndef GESTIONE_H_INCLUDED
#define GESTIONE_H_INCLUDED
#include "computer.h"
#include "giocatore.h"

class controllo 
{
    public:
    void selezione(int sel, int genere[], int pos)
    {
if (sel==1)// 1 gioca pc
{
computer_simula sm;
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