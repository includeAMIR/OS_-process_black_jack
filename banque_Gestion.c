#include "deck.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gestion_Cartes.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "lire_ecrire.h"


card_t * ajout_main(int val,card_t * main)
{
	card_t * nv=malloc(sizeof(card_t));
	nv->next=main;
	nv->value=val;
	return nv;	
}
void envoie_carte (int * ecrire_pere, deck_t * deck)
{
	
	int send_card=drawCard (deck);
   close(ecrire_pere[0]);
   write(ecrire_pere[1],&send_card,sizeof(int));
   discardCard (deck,send_card);
   printf("carte envoye:\n");
   famille_printf(getValueFromCardID(send_card),getColorFromCardID(send_card));
   
	
}

card_t * reception_carte (int * ecrire_pere,card_t * man, Joueur j)
{
	
	int val;	
	int score;
   close(ecrire_pere[1]);
   read(ecrire_pere[0],&val,sizeof(int));
   //printf("carte recu:\n");
   man=ajout_main(val,man);
   //famille_printf(getValueFromCardID(val),getColorFromCardID(val));
   printf(">cartes a la main du jouer:\n");
   afficher_main(man);
   score=addition_cartes (man);
   printf("-->score joueur:%d\n",score);
	return man;
}

card_t * destribution_carte_pour_pere (int * ecrire_pere,card_t * man, deck_t * deck,int pid_fils,int statuts) 
{
	    usleep(1000);
		kill(pid_fils, SIGSTOP);
			waitpid(pid_fils,&statuts,WUNTRACED);
		int ma_carte=drawCard (deck);
		man=ajout_main(ma_carte,man);
        discardCard (deck,ma_carte);
        printf(">les cartes a la main banque:\n");
        afficher_main(man);
        //addition_cartes (man);
        printf("**>score banque:%d\n",addition_cartes (man));
        		kill(pid_fils, SIGCONT);
   return man;
}
int reception_fils_pioch(int * ecrire_fils)
{
	int recu;	
   close(ecrire_fils[1]);
   read(ecrire_fils[0],&recu,sizeof(int));
   return recu;
}
int reception_fils_score(int * ecrire_fils)
{ 
	int score;
   close(ecrire_fils[1]);
   read(ecrire_fils[0],&score,sizeof(int));
   return score;
}


void envoi_pioch(int pid_fils,int statuts,int * ecrire_pere, deck_t * deck)
{
		 envoie_carte(ecrire_pere,deck);	
	
}
