#ifndef GIOCATORE_H_INCLUDED
#define GIOCATORE_H_INCLUDED
#include <iostream>
using namespace std;
class giocatore
{
    protected:
    string Nome_Cognome [30];
    int età [30];
    int genere [30];
    public:
    string vivo_morto [30];

};
class lv_giocatore: public giocatore
{
    void load (int n)
    {
        for(int i=0; i<n; i++)
        {
            cin>>Nome_Cognome [i];
            cin>>età [i];
            cin>>genere [i];

        }
    }
};


#endif //GIOCATORE_H_INCLUDED