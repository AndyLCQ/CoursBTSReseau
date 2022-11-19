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
    int descripteur;
    int retourConnect;
    int retourSend;
    int retourRecv;

    char mess[140]="Coucou, je suis le client !";
    char rep[140];
    struct sockaddr_in distant;


/**
  *Définition
  *
  */
    descripteur=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (descripteur==-1)
    {
        perror("Erreur de creation de socket");
        exit(1);
    }
    distant.sin_family=AF_INET;
    distant.sin_addr.s_addr=inet_addr("127.0.0.1");
    distant.sin_port=htons(2000);

    retourConnect=connect(descripteur, (struct sockaddr *)&distant, sizeof(distant));
    if (retourConnect==-1)
    {
        perror("Erreur de connexion");
        exit(2);
    }
    retourSend=send(descripteur, mess, sizeof(mess), 0);
    if (retourSend==-1)
    {
        perror("Erreur d'envoie");
        exit(3);
    }
    retourRecv=recv(descripteur, rep, sizeof(rep), 0);
    if (retourRecv==-1)
    {
        perror("Erreur de reception");
        exit(4);
    }
    printf("Reponse : %s", rep);

    return 0;
}

