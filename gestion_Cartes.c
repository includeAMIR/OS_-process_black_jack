#include "deck.h"
#include <stdio.h>
#include <stdlib.h>
#include "gestion_Cartes.h"
void famille_printf(cardvalue_t f,cardcolor_t couleur)
{
  switch(f) 
  { 
    case VJOK: 
      printf("Joker") ;
      break ;
    case VA :
		printf("As") ;
		break ;
	case V2:
		printf("2") ;
		break ;
	case V3:
		printf("3") ;
		break ;
    case V4:
		printf("4") ;
		break ;
	case V5:
		printf("5") ;
		break ;
	case V6:
		printf("6") ;
		break ;
	case V7:
		printf("7") ;
		break ;
	case V8:
		printf("8") ;
		break ;
	case V9:
		printf("9") ;
		break ;
	case VX:
		printf("10") ;
		break ;
	case VJ:
		printf("Valet") ;
		break ;
	case VQ:
		printf("Dame") ;
		break ;					
	case VK:
		printf("Roi") ;	
		break ;		  
  }
  switch(couleur) 
  { 
	case CJOKR:
		printf("\n");
		break;
    case CCLUB: 
      printf("_de trefle\n") ;
      break ;
    case CDIAM: 
      printf("_de Carreau\n") ;
      break ;
    case CSPAD: 
      printf("_de Pique\n") ;
      break ;
     case CHEAR:
       printf("_de Coeur\n");
       break;
}
}
int get_point_from_card(cardvalue_t f)
{
  switch(f) 
  { 
    case VJOK: 
      printf("Joker") ;
      return 10;
    case VA :
		return 11;
		break ;
	case V2:
		return 2;
		break ;
	case V3:
		return 3;
		break ;
    case V4:
		return 4;
		break ;
	case V5:
		return 5;
		break ;
	case V6:
		return 6;
		break ;
	case V7:
		return 7;
		break ;
	case V8:
		return 8;
		break ;
	case V9:
		return 9;
		break ;
	case VX:
		return 10;
		break ;
	case VJ:
		return 10;
		break ;
	case VQ:
		return 10;
		break ;					
	case VK:
		return 10;	
		break ;		  
  }
  return 0;
}

void afficher_main(card_t * pile) {
	card_t * tmp = pile ;
	famille_printf(getValueFromCardID(tmp->value),getColorFromCardID (tmp->value));
	tmp = tmp->next;
	while (tmp != NULL) {
		printf (" ");
		famille_printf(getValueFromCardID(tmp->value),getColorFromCardID (tmp->value));// moi ajouter
		tmp = tmp->next;
	}
	printf ("\n");
}
int valeur_AS(card_t * pile)
{
		cardvalue_t type=VA;
		card_t * tmp = pile ;
	    while (tmp != NULL) {
		if(getValueFromCardID(tmp->value)==type)
		return 1;
		tmp = tmp->next;
       }
	return 0;		
}
int addition_cartes (card_t * pile) {
	card_t * tmp = pile ;
	int compt=0;
	tmp =pile;
	
	while (tmp != NULL) {
		compt=compt+get_point_from_card(getValueFromCardID(tmp->value));
		tmp = tmp->next;
	}
	
	if(valeur_AS(pile) && compt>21)
	{
		return (compt-10);
		
	}
		
		return compt;
}

card_t * vider_main(card_t * man){
  card_t * tmp=NULL;
  while(man!=NULL){
	tmp=man;
	man=man->next;
    free(tmp);
  }
  
  return man;
}
