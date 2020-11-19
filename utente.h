#ifndef UTENTE_H_INCLUDED
#define UTENTE_H_INCLUDED
#include <iostream>
#include <math.h>
#include "librerie/random.hpp"
#include "gestione.h"
#include "giocatore.h"
using Random = effolkronium::random_static; //da random.hpp
class utente
{
private:
    uint32_t media_vita;
    uint32_t parametri[10];
    string const nome_parametri[10]{"Sistema nervoso", "Apparato circolatorio","Apparato respiratorio", "Sistema scheletrico"};//ecc
    string const upgrade[10]{};//da definire

public:
utente();
void set_media_vita (int mv)
{
    mv=media_vita;
}
int get_media_vita ()
{
    return media_vita;
}
void set_parametri (int pp, int pos)
{
    pp=parametri[pos];
}
int get_parametri (int pos)
{
    return parametri[pos];
}


};
class algoritmi
{
    private:
    utente u;
    public:
int media_vita ()
{
  int media=0;
for (int i=0; i<10; i++)
{
    media=media+u.get_parametri(i);
}
    media=media/10;
    u.set_media_vita(media);
}
};

class vita: public utente
{
    private:
    int max_r=5;
    int min_r=1;
    public:
int get_max_r()
{
    return max_r;
}
int get_min_r ()
{
    return min_r;
}
    int parametro_random ()
    {
     int val;
     auto val=Random::get(0, 9);
     return val;
       
    }
        int get_random (int min_r,int max_r)
    {
     int val;
     auto val = Random::get(min_r, max_r);
     return val;   
    }
    int difine_m_r(int pos)
    {
        if ((get_media_vita()<80)&&(get_media_vita()>=50))
        {
            min_r=get_random(get_random(1,max_r), max_r);
            max_r=get_random(min_r, max_r+15);
        }
        if ((get_media_vita()<50)&&(get_media_vita()>=40))
        {
            min_r=get_random(get_random(2,max_r), max_r);
            max_r=get_random(min_r, max_r+5);
        }
        if ((get_media_vita()<40)&&(get_media_vita()>=30))
        {
            min_r=get_random(get_random(1,max_r), max_r);
            max_r=get_random(min_r, max_r+5);
        }
        if ((get_media_vita()<30)&&(get_media_vita()>=20))
        {
            min_r=get_random(get_random(1,max_r), max_r);
            max_r=get_random(min_r, max_r+3);
        }
        if ((get_media_vita()<20)&&(get_media_vita()>=10))
        {
            min_r=get_random(get_random(1,max_r), max_r);
            max_r=get_random(min_r, max_r);
        }
        if ((get_media_vita()<10)&&(get_media_vita()>=5))
        {
            min_r=get_random(get_random(-10,1), min_r);
            max_r=get_random(min_r, 5);
        }
        if (get_media_vita()<5)
        {
            stato_vita st;
            st.set_morto(pos);
        }
    }
    };
class gioco: public vita
{private:
giocatore g;
public:
gioco();
void game ()
{
difine_m_r(0);
int tot=0;
int pr;
while (tot<g.get_n())
{

for (int i=0 ;i<parametro_random(); i++)
{
pr=parametro_random();
int val= get_random(get_min_r(), get_max_r());
set_parametri(val=get_parametri(pr)-val, pr);

}
difine_m_r(tot);
tot++;
}
}


};

#endif //UTENTE_H_INCLUDED