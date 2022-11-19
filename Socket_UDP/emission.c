#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>


int main()
{
	int des_socket, retour;
	struct sockaddr_in distant;
	char mess[40]="bonjour ma petite coco";
	
	des_socket=socket(AF_INET, SOCK_DGRAM, 0);
	if(des_socket==-1)
	{ 	
		perror("Erreur de création");
		exit(1);
	}
	distant.sin_family=AF_INET;
	distant.sin_addr.s_addr=0x01C910AC;
	retour=sendto(des_socket, mess, sizeof(mess), 0,(struct sockaddr *)&distant, sizeof(distant));
	if(retour==-1)
	{
		perror("Erreur de saisie");
		exit(2);
	}
	close(des_socket);
	return 0;
}
