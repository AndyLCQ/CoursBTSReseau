#ifndef CCLITCP_H
#define CCLITCP_H


#include <iostream>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>

class CcliTCP
{
private:
    int desc;
    struct sockaddr_in distant;
public:
    CcliTCP(const char * IPDistant, unsigned short PortDistant);
    ~CcliTCP();
    int envoyer(void *buff, int taille);
    int recevoir(void *buff, int taille);
};

#endif // CCLITCP_H
