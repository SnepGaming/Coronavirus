#pragma once 
#include <iostream>
#include "librerie/random.hpp"
#include <windows.h>
#include "gamer.hpp"
using Random = effolkronium::random_static; //da libreria random.hpp
using namespace std;





class utente
{
private:
    uint32_t media_vita;
    uint32_t parametri[5]={100,100,100,100,100};
    string const nome_parametri[5]{"Sistema nervoso", "Sistema circolatorio","Sistema Respiratorio", "Sistema scheletrico","Sistema Immunitario"};
    string const upgrade[6]{"TAC","Analgesici", "Farmaci Immunostimolanti", "Ossigeno","Corticosteroidi", "Vaccino"};
    int const upgrade_value [6]= {10,3,8,15,5,50};
    int punti=5;//da mettere 0

public:
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
    void visualizza_parametri ()
    {  
        for (int i=0; i<5; i++)
        {
            cout<<get_nome_parametri(i)<<":  "<<get_parametri(i)<<endl;
        }
    }
};
class algoritmi
{
    private:
    utente u;
    public:
void media_vita ()
{
  int media=0;
for (int i=0; i<10; i++)
{
    media=media+u.get_parametri(i);
}
    media=media/5;
    u.set_media_vita(media);
}
};

class vita: public utente
{
    private:
    int max_r=5;
    int min_r=1;
    algoritmi a;
    stato_vita st;
    int val;
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
     auto val=Random::get(0, 9);
     return val;
       
    }
    int get_random (int min_r,int max_r)
    {
     auto val = Random::get(min_r, max_r);
     return val;   
    }
    void difine_m_r(int pos)
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
            //stato_vita st; riga 84
            st.set_morto(pos);
        }
    }
    };
class gestione 
{
private:
utente us;
giocatore stato;
public:
void upgrade (int pos)
{
for (int i=0; i<6; i++)
{
    cout<<"Upgrade "<<i+1<<": "<<us.get_upgrade(i)<<" costo: "<<us.get_upgrade_value(i)<<endl;
}
int up;
if (us.get_punti()>=3)
{
cout<<"Inserisci il numero dell'upgrade che vuoi"<<"\tInserisci 10 se non vuoi selezionare alcun upgrade"<<endl; 
cout<<us.get_punti()<<endl;
cin>>up;
switch (up)
{   
    case (1): //tac  
    if (us.get_punti()>=us.get_upgrade_value(0)) 
    { 
    us.set_punti(us.get_punti()-us.get_upgrade_value(0));
    if (us.get_parametri(2)<=85) 
    {
    us.set_parametri(us.get_parametri(2)+15,2);//respiratorio
    }
    else
    {
    us.set_parametri(100,2);//respiratorio
    }
    }
    else
    {
        cout<<"\t Non hai abbastanza punti per questo upgrade, ritenta il prossimo round!!"<<endl;
    }
    
    break;
    
    case (2): //analgesici
    if (us.get_punti()>=us.get_upgrade_value(1)) 
    {
    us.set_punti(us.get_punti()-us.get_upgrade_value(1));
    if ((us.get_parametri(0)<=95) && (us.get_parametri(3)<=95))  //analgesici
    {
    us.set_parametri(us.get_parametri(0)+5,0);//nervoso
    us.set_parametri(us.get_parametri(3)+5,3);//scheletrico
    }
    else
    {
    us.set_parametri(100,0); //nervoso
    us.set_parametri(100,3); //scheletrico
    }
    }
    else
    {
        cout<<"\t Non hai abbastanza punti per questo upgrade, ritenta il prossimo round!!"<<endl;
    }

    break;
    
    case (3): //farmaci immunostimolanti
    if (us.get_punti()>=us.get_upgrade_value(2))
    {
    us.set_punti(us.get_punti()-us.get_upgrade_value(2));
    if (us.get_parametri(4)<=85)   
    {
    us.set_parametri(us.get_parametri(4)+15,4); //immunitario
    }
    else
    {
    us.set_parametri(100,4); //immunitario
    }
    }
    else
    {
        cout<<"\t Non hai abbastanza punti per questo upgrade, ritenta il prossimo round!!"<<endl;
    }
    
    break;
  
    case (4)://ossigeno 
    if (us.get_punti()>=us.get_upgrade_value(3))
    { 
    us.set_punti(us.get_punti()-us.get_upgrade_value(3));
    if ((us.get_parametri(2)<=85) && (us.get_parametri(1)<=90)) //ossigeno
    {
    us.set_parametri(us.get_parametri(2)+15,2); //respiratorio
    us.set_parametri(us.get_parametri(1)+10,1); //circolatorio
    }
    else
    {
    us.set_parametri(100,2); //respiratorio
    us.set_parametri(100,1); //circolatorio
    } 
    }
    else
    {
        cout<<"\t Non hai abbastanza punti per questo upgrade, ritenta il prossimo round!!"<<endl;
    }
    break;
    
    case (5): //corticosteroidi
    if (us.get_punti()>=us.get_upgrade_value(4))  
    {
    us.set_punti(us.get_punti()-us.get_upgrade_value(4));
    if ((us.get_parametri(1)<=93) && (us.get_parametri(4)<=93))
    {
    us.set_parametri(us.get_parametri(2)+7,1); //circolatorio
    us.set_parametri(us.get_parametri(2)+7,4); //immunitario
    }
    else
    {
    us.set_parametri(100,1); //circolatorio
    us.set_parametri(100,4); //immunitario
    }
    }
    else
    {
        cout<<"\t Non hai abbastanza punti per questo upgrade, ritenta il prossimo round!!"<<endl;
    }
    break;
    
    case (6): //vaccino 
    if (us.get_punti()>=us.get_upgrade_value(5))
    {
       //giocatore stato; riga 151
       stato.set_vivo_morto(false, pos);
    }
    else
    {
      cout<<"\t Questo round non potrai usare upgrade!" <<endl; 
    }
    case (10): //break
    break;  
   

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


class gioco
{
private:
giocatore gt;
vita hp;
utente ut;
gestione gh;
public:

void game ()
{
hp.difine_m_r(0);
int tot=0;
int pr;
while (tot<gt.get_n())
{
ut.visualizza_parametri();
ut.set_punti(ut.get_punti()+hp.get_random(5,7));  //da mettere  da 0 a 7 
gh.upgrade(tot);
for (int i=0 ;i<hp.parametro_random(); i++)
{
pr=hp.parametro_random();
int val= hp.get_random(hp.get_min_r(), hp.get_max_r());
ut.set_parametri(val=ut.get_parametri(pr)-val, pr);

}
hp.difine_m_r(tot);



tot++;
}
}

};

