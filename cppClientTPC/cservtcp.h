#ifndef CSERVTCP_H
#define CSERVTCP_H

#include <iostream>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>


class CservTCP
{
private:
    int desc_ecoute, desc_dialogue;
    struct sockaddr_in local, distant;
    char erreur;
public:
    CservTCP(unsigned short PortLocal);
    ~CservTCP();
    int envoyer(void *buff, int taille);
    int recevoir(void *buff, int taille);
    int accepter();
    int fermerdia();
    char RecupErreur();
};

#endif // CSERVTCP_H
