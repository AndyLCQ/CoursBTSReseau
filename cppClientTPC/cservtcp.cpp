 #include "cservtcp.h"

CservTCP::CservTCP(unsigned short PortLocal)
{
        desc_ecoute = socket(AF_INET,SOCK_STREAM,0);
        if(desc_ecoute==-1)
        {
            erreur='s';
        }
        else
        {
            local.sin_addr.s_addr = INADDR_ANY;
            local.sin_port = htons(PortLocal);
            local.sin_family = AF_INET;

            int retour=bind(desc_ecoute,(struct sockaddr *)&local,sizeof(local));
            if (retour==-1)
            {
                erreur='a';
            }
            listen(desc_ecoute,1);
        }


}

/*************************************************************************************************************/
int CservTCP::envoyer(void *buff, int taille)
{
    return send(desc_dialogue, buff, taille,0);
}

/*************************************************************************************************************/
int CservTCP::recevoir(void *buff, int taille)
{
    return recv(desc_dialogue, buff, taille, 0);
}

/*************************************************************************************************************/
int CservTCP::accepter()
{
    unsigned int longueur=sizeof(distant);

    desc_dialogue=accept(desc_ecoute, (struct sockaddr *)&distant, &longueur);

    return desc_dialogue;
}
/*************************************************************************************************************/
int CservTCP::fermerdia()
{
   return close(desc_dialogue);

}

/*************************************************************************************************************/
CservTCP::~CservTCP()
{
    close(desc_ecoute);
}

/*************************************************************************************************************/
char CservTCP::RecupErreur()
{
    return erreur;
}
