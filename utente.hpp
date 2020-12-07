#pragma once 
#include <iostream>
#include "librerie/random.hpp"
#include <windows.h>
#include "gamer.hpp"
#include <stdlib.h>
#include <conio.h>
using Random = effolkronium::random_static; //da libreria random.hpp
using namespace std;





class utente
{
private:
    int media_vita;
    int parametri[5]={100,100,100,100,100};
    string const nome_parametri[5]{"Sistema nervoso", "Sistema circolatorio","Sistema Respiratorio", "Sistema scheletrico","Sistema Immunitario"};
    string const upgrade[6]{"TAC","Analgesici", "Farmaci Immunostimolanti", "Ossigeno","Corticosteroidi", "Vaccino"};
    int const upgrade_value [6]= {10,3,8,15,5,50};
    int punti=0;//da mettere 0

public:
void set_media_vita (int mv)
{
    media_vita=mv;
}
int get_media_vita ()
{
    return media_vita;
}
void set_parametri (int pp, int pos)
{
   parametri[pos]=pp;
}
int get_parametri (int pos)
{
    return parametri[pos];
}
void set_punti (int pup)
{
    punti=pup;
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
    void continua ()
    {
        cout << "Premi Enter per continuare"<<endl;
        getch();
    }
};
class algoritmi
{
    private:
    utente u; 
    int media;
    public:
int media_vita ()
{ 
    media=0;
for (int i=0; i<5; i++)
{ 
    media=media+u.get_parametri(i);
}
    media=media/5;
    u.set_media_vita(media);
    return media;
}
};

class vita: public utente
{
    private:
    int max_r=5;
    int min_r=1;
    algoritmi a;
    stato_vita st;
    public:
    
int get_max_r()
{
    return max_r;
}
int get_min_r ()
{
    return min_r;
}
    auto parametro_random ()
    {
     auto val=Random::get(0, 9);
     return val;
       
    }
    auto get_random ()
    {
     auto val = Random::get(min_r, max_r);
     return val;   
    }
    auto random (int min, int max)
    {
       auto val = Random::get(min, max);
       return val; 
    }
    
    void difine_m_r(int pos)
    {
        if ((a.media_vita()<80)&&(a.media_vita()>=50))
        {
           min_r=random (1, 8);
           max_r=random (8, 15); 
        }
        if ((a.media_vita()<50)&&(a.media_vita()>=40))
        {
            min_r=random (1, 4);
            max_r=random (5, 10); 
            
        }
        if ((a.media_vita()<40)&&(a.media_vita()>=30))
        {
            min_r=random (1, 3);
            max_r=random (4, 8); 
        }
        if ((a.media_vita()<30)&&(a.media_vita()>=20))
        {
            min_r=random (1, 5);
            max_r=random (6, 10); 
        }
        if ((a.media_vita()<20)&&(a.media_vita()>=10))
        {
            min_r=random (1, 3);
            max_r=random (4,6); 
        }
        if ((a.media_vita()<10)&&(a.media_vita()>=5))
        {
            min_r=random (1, 5);
            max_r=random (6, 9); 
        }
        if (a.media_vita()<5)
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
    us.set_parametri((us.get_parametri(2)+15),2);//respiratorio
    }
    else
    {
    us.set_parametri(100,2);//respiratorio
    }
    }
    else
    {
        cout<<"\t Non hai abbastanza punti per questo upgrade, ritenta il prossimo round!!"<<endl;
        us.continua();
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
        us.continua();
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
        us.continua();
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
        us.continua();
    }
    break;
    
    case (5): //corticosteroidi
    if (us.get_punti()>=us.get_upgrade_value(4))  
    {
    us.set_punti(us.get_punti()-us.get_upgrade_value(4));
    if ((us.get_parametri(1)<=93) && (us.get_parametri(4)<=93))
    {
    us.set_parametri(us.get_parametri(1)+7,1); //circolatorio
    us.set_parametri(us.get_parametri(4)+7,4); //immunitario
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
       us.continua();
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
       us.continua();
     
    }
    case (10): //break
    break;  
   
default:
cout<<"Input errato"<<endl;
us.continua();

break;
}
}
else
{
cout<<"Non hai...i punti"<<endl;;
us.continua();

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
algoritmi al;
public:

void game (int pos)
{
hp.difine_m_r(pos);
int tot=0;
int pr;
int p_random;
int val;
while ((al.media_vita()>5)&&(gt.get_vivo_morto(pos)!=false))
{
system("CLS");
ut.visualizza_parametri();
p_random=(ut.get_punti()+hp.random(1,7));
ut.set_punti(p_random); 
gh.upgrade(pos);
for (int i=0 ;i<hp.parametro_random(); i++)
{

pr=hp.parametro_random();
val=hp.random(hp.get_min_r(), hp.get_max_r());
ut.set_parametri(val=ut.get_parametri(pr)-val, pr);

}
hp.difine_m_r(pos);

al.media_vita();
}
}

};

