#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>

int main()
{
		//Déclaration des variables
	int descripteur, retour;
	struct sockaddr_in distant;
	struct sockaddr_in local;
	char Tableau[17];
	char mess[100];
	int taille;

		//Envoyer a qui ?
	printf("Entrer l'adresse a qui communiquer : ");
	scanf("%s", Tableau);
	getchar();
	
		//
		descripteur=socket(AF_INET, SOCK_DGRAM, 0);
	if(descripteur==-1)
	{
		perror("Erreur de création de socket\n");
		exit(1);
	}
	local.sin_family=AF_INET;
	local.sin_addr.s_addr=INADDR_ANY;
	local.sin_port=htons(3001);
	retour=bind(descripteur, (struct sockaddr *)&local, sizeof(local));
	if(retour==-1)
	{
		perror("Erreur d'attachement\n");
		exit(2);
	}
	distant.sin_family=AF_INET;
	distant.sin_addr.s_addr=inet_addr(Tableau);
	distant.sin_port=htons(3000);
	taille=sizeof(distant);
	
		//Message
	do
	{
		/*Saisie de message*/
		printf("\tEntrer le message : \n");
		scanf("%[^\n]", mess);
		getchar();
	
		/*envoi du message*/
		retour=sendto(descripteur, mess, sizeof(mess), 0, (struct sockaddr *)&distant, sizeof(distant));
		if(retour==-1)
		{
			perror("Erreur d'envoi\n");
			exit(2);
		}
		
	}while(mess[0]!='*');
	close(descripteur);
	return 0;	
}
