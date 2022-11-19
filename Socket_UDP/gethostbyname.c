#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
	int i=0;
	struct hostent * hst;
	char NameMachine[100];
	
	printf("Nom de la machine :\n");
	scanf("%s", NameMachine);

	hst= gethostbyname(NameMachine);
	
	if(hst== 0)
	{
		perror("Erreur ! ");
		exit(1);
	}
	printf("Taille en octets de l'adresse : \t %hd\n", hst->h_length);
	printf("Nom principal : \t %s\n", hst->h_name);
	
	
	while(hst->h_aliases[i]!=0)
	{
		printf("Alias %d: \n %s\t\n", i, hst->h_aliases[i]);
		i++;
	}
	
	return 0;
}
