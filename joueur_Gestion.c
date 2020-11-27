#include "deck.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gestion_Cartes.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "lire_ecrire.h"
#include "banque_Gestion.h"
int demande_pioche(int * ecrire_fils,Joueur j,int compt)
{
	int i;
	srand (time (NULL));
	i=rand()%2;	
	if( i && compt<=j.valStop)
	{	
		printf("-->joueur pioche:\n");
	close(ecrire_fils[0]);
   write(ecrire_fils[1],&i,sizeof(int));
   
	}
	else{
		i=0;
		printf("-->joueur ne pioche pas\n");	
		close(ecrire_fils[0]);
   write(ecrire_fils[1],&i,sizeof(int));
		}
		 return i;
}

void envoie_score(int compt,int * ecrire_fils)
{
		close(ecrire_fils[0]);
   write(ecrire_fils[1],&compt,sizeof(int));
   
}
void reception_pioche(card_t * man, int * ecrire_pere, Joueur j)
{

       man=reception_carte (ecrire_pere,man,j);
}

void envoie_jetons(int * ecrire_pere, int jetons)
{
	
   close(ecrire_pere[0]);
   write(ecrire_pere[1],&jetons,sizeof(int));
   
}

int reception_jetons(int * ecrire_pere)
{
	int jetons;
   close(ecrire_pere[1]);
   read(ecrire_pere[0],&jetons,sizeof(int));
   return jetons;
   
}

void gagne_perdu(int * ecrire_pere, int bol)
{
   close(ecrire_pere[0]);
   write(ecrire_pere[1],&bol,sizeof(int));
   
}

int reception_gagne_perdu(int * ecrire_pere)
{ int bol;
   close(ecrire_pere[1]);
   read(ecrire_pere[0],&bol,sizeof(int));
   return bol;
}
