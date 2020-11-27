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
#include "joueur_Gestion.h"
#include <signal.h>

int main (){

    
    
    
    
	    
	     int ecrire_pere[2];
	     int envoi_fils[2];
	     int pid_fils,statuts;
	     
	     if(pipe(ecrire_pere) != 0)
		{
        fprintf(stderr, "Erreur de création du tube.\n");
        return EXIT_FAILURE;
		}
		if(pipe(envoi_fils) != 0)
		{
        fprintf(stderr, "Erreur de création du tube.\n");
        return EXIT_FAILURE;
		}

	  pid_fils=fork();
	
	if(pid_fils==0){
		
    Joueur j;
    j=lecture_pour_joueur(j,1);
    printf("nbJetons:%d typeMise:%s ValStop:%d objJetons:%d\n",j.nbJeton,j.typeMise,j.valStop,j.objJeton);
    card_t * man=NULL;
    int jetons=50;
    while(j.nbJeton<j.objJeton && jetons>=50){
		usleep(100);
		printf("----------------------------------------------\n");
     man=reception_carte (ecrire_pere,man,j);
     man=reception_carte (ecrire_pere,man,j);
     sleep(1);
      envoie_score(addition_cartes(man),envoi_fils);
      if(demande_pioche(envoi_fils,j,addition_cartes(man))){
       man=reception_carte (ecrire_pere,man,j);
       envoie_score(addition_cartes(man),envoi_fils);
			}
			man=vider_main(man);
		}
      
		
}
  
  else{
	  
      TABLE  tabl;
    tabl=lecture_pour_table(tabl);
     printf("nbJoueurs:%d nbDecks:%d nbMains:%d\n",tabl.nbJoueurs,tabl.nbDecks,tabl.nbMains);
   deck_t * deck; 
   deck_t * man=NULL;
   int tour;
   int score_fils;
   deck=initDeck (P32,tabl.nbDecks);
   shuffleDeck(deck);
   shuffleDeck(deck);
   shuffleDeck(deck);
   printDrawPile(deck);
  
  for(tour=0;tour<tabl.nbMains;tour++)
  {
	 // kill(pid_fils, SIGSTOP);
			//waitpid(pid_fils,&statuts,WUNTRACED);
   sleep(2);
    envoie_carte (ecrire_pere,deck);
   sleep(1);
    man= destribution_carte_pour_pere (ecrire_pere,man,deck,pid_fils,statuts);
    sleep(2);
    envoie_carte (ecrire_pere,deck);
    man= destribution_carte_pour_pere (ecrire_pere,man,deck,pid_fils,statuts);
   score_fils=reception_fils_score(envoi_fils);
    if (reception_fils_pioch(envoi_fils)){
      envoie_carte (ecrire_pere,deck);
      score_fils=reception_fils_score(envoi_fils);
      if(score_fils>21){
       kill(pid_fils, SIGTERM);
       printf("----Joueru a perdu\n");
       break;
            }
      //sleep(1);
		}
		if (addition_cartes(man)<16){
			printf("--->banque piochee\n");
         man= destribution_carte_pour_pere (ecrire_pere,man,deck,pid_fils,statuts);
            }
            else
            printf("--->banque ne piochee pas\n");
         if(score_fils>addition_cartes(man))
         printf("banque a gagne\n");
         else
         printf("joueur a gagne\n");
         man=vider_main(man);
         
      sleep(1);
		}
	}
   kill(pid_fils, SIGTERM);
    
	wait(NULL);
		  

    return 0;
}
