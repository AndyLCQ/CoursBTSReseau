#include"stdio.h"
#include"unistd.h"
#include"stdlib.h"
#include"netdb.h"

int main()
{
	char mess[100];
    char rep[100];
    int desc;
    int erreur;
    struct sockaddr_in local, distant;
    int taille=sizeof(distant);
    
    desc=socket(AF_INET, SOCK_DGRAM,0);
    if(desc== -1)
    {
        perror("erreur descripteur\n");
        exit(1);
    }
    local.sin_family=AF_INET;
    local.sin_addr.s_addr=INADDR_ANY;
    local.sin_port=htons(3000);
    erreur=bind(desc, (struct sockaddr *)&local, sizeof(local));
    if(erreur== -1)
    {
        perror("erreur attachement\n");
        exit(1);
    }
    do
    {
    	erreur=recvfrom(desc, rep, sizeof(rep),0, (struct sockaddr *)&distant, &taille);
    	if(erreur== -1)
    	{
        	perror("erreur de reception\n");
        	exit(1);
    	}
    	if(rep[0]=='*')
        {
            printf("le client a quitté\n"); 
       }
       else
       {
            printf("\tToi \n%s\n", rep); 
    		printf("\tMoi\n");
    		scanf("%[^\n]", mess);
    		getchar();
    		erreur=sendto(desc,mess,sizeof(mess),0, (struct sockaddr *)&distant, sizeof(distant));
    		if(erreur== -1)
    		{
        		perror("erreur d'envoi\n");
        		exit(1);
    		}
    	}
    }while(1);
    close(desc);
    return 0;
}
