#include "cudp.h"


/*Constructeur de la classe cudp*/

Cudp::Cudp(short PortDistant, char * IPDistant)
{
    /************Creation du descripteur************/
        desc=socket(AF_INET, SOCK_DGRAM, 0);
        if(desc==-1)
        {
             erreur='s';
        }

    /************Attachement************/
         local.sin_family=AF_INET;
         local.sin_addr.s_addr=INADDR_ANY;
         local.sin_port=htons(PORTLOCAL);
         int retour=bind(desc, (struct sockaddr *)&local, sizeof(local));
         if(retour==-1)
              {
                  erreur='a';
              }

    /*Initialisation de la structure distante*/
         distant.sin_family=AF_INET;
         distant.sin_addr.s_addr=inet_addr(IPDistant);
         distant.sin_port=htons(PortDistant);


    /*Attribut longueur prend pour valeur la taille de la structure*/
         longueur=sizeof(distant);

}
//--------------------------------------------------------------------------------------------------------------------------//

/*Méthode d'envoi*/
int Cudp::envoyer(char *buff, int taille)
{
        int retour=sendto(desc, buff, taille, 0, (struct sockaddr *)&distant, sizeof(distant));
        return retour;
}

//--------------------------------------------------------------------------------------------------------------------------//
int Cudp::recevoir(char *buff, int taille)
{
        int erreur=recvfrom(desc, buff, taille,0, (struct sockaddr *)&distant, &longueur);
        return erreur;


}

//-------------------------------------------------------------------------------------------------------------------------//
/*Destructeur*/
Cudp::~Cudp()
{
    close(desc);
}

//-------------------------------------------------------------------------------------------------------------------------//
/*Récupération d'erreur*/
char Cudp::RecupErreur()
{
    return erreur;
}
