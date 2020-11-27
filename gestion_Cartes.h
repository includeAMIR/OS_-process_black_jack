//afficher la carte en es sa couleur a partir de getValue et get getColor
void famille_printf(cardvalue_t f,cardcolor_t couleur);

typedef struct table {
	int nbJoueurs;
	int nbDecks;
	int nbMains;

}TABLE;

typedef struct Joueur {
	int nbJeton;
	char typeMise[10];
	int valStop;
	int objJeton;
} Joueur;
//afficher les carte a la main du joueur
void afficher_main (card_t * pile);
// addition des cartes a la main du joueur retouren la somme
int addition_cartes (card_t * pile);
//retourner la valeur en point de la carte
int get_point_from_card(cardvalue_t f);
//definir la valeur de L'AS
int valeur_AS(card_t * pile);

card_t * vider_main(card_t * man);
