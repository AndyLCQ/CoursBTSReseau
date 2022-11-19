#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(void)
{

/**
  *Déclaration des variables
  *
  */
    int descripteurEcoute;
    int descripteurDialogue;
    int retourBind;

    int retourListen;
    int retourSend;
    int retourRecv;
    char mess[140]="Ceci est un test du serveur !";
    char rep[140];
    struct sockaddr_in local;
    struct sockaddr_in distant;
    unsigned int taille = sizeof(distant);


/**
  *Définitions
  *
  */
    descripteurEcoute=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (descripteurEcoute==-1)
    {
        perror("Erreur de creation de socket d'ecoute");
        exit(1);
    }
/*Remplissage des champs de la structure local*/
    local.sin_family=AF_INET;
    local.sin_addr.s_addr=INADDR_ANY;
    local.sin_port=htons(2000);
/*Attachement*/
    retourBind=bind(descripteurEcoute, (struct sockaddr *)&local, sizeof(local));
    if (retourBind==-1)
    {
        perror("Erreur d'atachement");
        exit(2);
    }
/*Ecoute*/
    retourListen=listen(descripteurEcoute, 3); //ask
    if (retourListen==-1)
    {
        perror("Erreur d'ecoute");
        exit(3);printf("Reponse : %s", rep);
    }
/*acceptation*/
    descripteurDialogue=accept(descripteurEcoute, (struct sockaddr *)&distant, &taille);
    if (descripteurDialogue==-1)
    {
        perror("Erreur d'acceptation");
        exit(4);
    }
/*reception*/
    retourRecv=recv(descripteurDialogue, rep, sizeof(rep), 0);
    if(retourRecv==-1)
    {
        perror("Erreur de reception");
        exit(5);
    }
    printf("Reponse : %s", rep);
/*envoi*/
    retourSend=send(descripteurDialogue, mess, sizeof(mess), 0);
    if(retourSend==-1)
    {
        perror("Erreur d'envoi");
        exit(6);
    }

    return 0;
}

