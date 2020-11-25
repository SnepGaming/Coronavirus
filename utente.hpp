#ifndef UTENTE_HPP_INCLUDED
#define UTENTE_HPP_INCLUDED
#include <iostream>
#include "librerie/random.hpp"
#include "gestione.hpp"
#include "giocatore.hpp"
using Random = effolkronium::random_static; //da libreriarandom.hpp
//utente

class utente
{
private:
    uint32_t media_vita;
    uint32_t parametri[5]={100,100,100,100,100};
    string const nome_parametri[5]{"Sistema nervoso", "Sistema circolatorio","Sistema Respiratorio", "Sistema scheletrico","Sistema Immunitario"};
    string const upgrade[6]{"TAC","Analgesici", "Farmaci Immunostimolanti", "Ossigeno","Corticosteroidi", "Vaccino"};
    int const upgrade_value [6]= {10,3,8,15,5,50};
    int punti=0;// funzione get random

public:
utente();
void set_media_vita (int mv)
{
    mv=media_vita;
}
uint32_t get_media_vita ()
{
    return media_vita;
}
void set_parametri (int pp, int pos)
{
    pp=parametri[pos];
}
uint32_t get_parametri (int pos)
{
    return parametri[pos];
}
void set_punti (int pp)
{
    pp=punti;
}
int get_punti ()
{
    return punti;
}
string get_nome_parametri (int pos)
{
    return nome_parametri[pos];
}
int get_upgrade_value (int pos)
{
    return upgrade_value[pos];
}
string get_upgrade (int pos)
{
    return upgrade[pos];
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
    algoritmi a;
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
class gestione 
{
private:
utente us;
public:
void upgrade ()
{
for (int i=0; i<6; i++)
{
    cout<<"Upgrade "<<i+1<<": "<<us.get_upgrade(i)<<" costo: "<<us.get_upgrade_value(i)<<endl;
}
int up;
if (us.get_punti()>=3)
{
cout<<"Inserisci il numero dell'upgrade che vuoi"<<"Inserisci 10 se non vuoi selezionare alcun upgrade"<<endl;
cin>>up;
switch (up)
{
    case (1):
    us.set_punti(us.get_punti()-us.get_upgrade_value(0));
    if (us.get_parametri(2)<=90)//DA CONTROLLARE MEDIA 
    {
    us.set_parametri(us.get_parametri(2)+15,2);
    }
    else
    {
    us.set_parametri(100,2);
    }
    break;
    case (2):
    us.set_punti(us.get_punti()-us.get_upgrade_value(1));

    break;
    case (3):
    us.set_punti(us.get_punti()-us.get_upgrade_value(2));

    break;
    case (4):
    us.set_punti(us.get_punti()-us.get_upgrade_value(3));

    break;
    case (5):
    us.set_punti(us.get_punti()-us.get_upgrade_value(4));

    break;
    case (6):
    us.set_punti(us.get_punti()-us.get_upgrade_value(5));

    break;
default:
cout<<"Input errato"<<endl;
break;
}
}
else
{
   cout<<"Non hai...i punti"<<endl;
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

#endif //UTENTE_HPP_INCLUDED