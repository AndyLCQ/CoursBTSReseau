#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
	//Déclaration des variables
	struct servent * srv;
	char protocole;
	int i=0;
	char NameService[100];
	
	//Saisie du Service
	printf("Nom du service :\n");
	scanf("%s", NameService);
	
	//UDP
	srv = getservbyname(NameService, "udp");
	if(srv== 0)
	{
		printf("Le service n'utilise pas de protocole UDP\n -----------\n");
	}
	else
	{
	//Affichage pour un protocole UDP
		printf("Nom principal : \t %s\n", srv->s_name);
		printf("Port utilisé : \t %hd \n", ntohs(srv->s_port));
		printf("Protocole utilisé : \t %s \n", srv->s_proto);
			//Affichage des aliases
		while(srv->s_aliases[i]!=0)
		{
			printf("Alias %d: \n %s\t\n", i+1, srv->s_aliases[i]);
			i++;
		}
	}
	//TCP
	srv = getservbyname(NameService, "tcp");
	if(srv== 0)
	{
		printf("Le service n'utilise pas de protocole TCP\n");
	}
	else
	{ 
	//Affichage pour un protocole TCP
		printf("Nom principal : \t %s\n", srv->s_name);
		printf("Port utilisé : \t %hd \n", ntohs(srv->s_port));
		printf("Protocole utilisé : \t %s \n", srv->s_proto);
			//Affichage des aliases
		while(srv->s_aliases[i]!=0)
		{
			printf("Alias %d: \n %s\t\n", i+1, srv->s_aliases[i]);
			i++;
		}
	}
	
	
	return 0;
}

