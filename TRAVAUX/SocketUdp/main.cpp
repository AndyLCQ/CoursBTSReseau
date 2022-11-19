#include <iostream>
#include "cudp.h"
//-----------------------------------------------------//
using namespace std;
//-----------------------------------------------------//


int main()
{
    char mess[100]="Coucou ma ninit";
    char rep[100];
    char adresseIp[16]="172.16.201.1";
    int retour=0;
    int erreur=0    ;


    Cudp objechange(3000, adresseIp );

    do
    {
        cout << "Entrer le message"<<endl;
        cin.getline(mess, sizeof(mess));

        objechange.envoyer(mess, sizeof(mess));

            if(mess[0]!='*')
        {
            objechange.recevoir(rep, sizeof(rep));
            if(erreur==-1)
            {
                cout << "Erreur de reception"<<endl;
             exit(2);
            }
            cout << adresseIp << " : ";
            cout << rep <<endl;
        }


    }while(mess[0]!='*');
return 0;
}
