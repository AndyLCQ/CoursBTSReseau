#ifndef CUDP_H
#define CUDP_H
#define PORTLOCAL 3001


#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>
using namespace std;
//------------------------------------------------------------------------------------------------------------------------//

class Cudp
{
private:
    int desc;
    char erreur;
    unsigned int longueur;
    struct sockaddr_in local, distant;

public:
    Cudp(short PortDistant=0, char * IPDistant="0");
    ~Cudp();
    int envoyer(char *buff, int taille);
    int recevoir(char *buff, int taille);
    char RecupErreur();
};

#endif // CUDP_H


