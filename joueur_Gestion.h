// on demande la pioche au fils il renvoie 1 ou 0
int demande_pioche();
// le fils envoie son score au pere
void envoie_score(int compt,int * ecrire_fils);
//fonction qui permet de recevoie une carte apres une demande de pioche
void reception_pioche(card_t * man, int * ecrire_pere, Joueur j);

int reception_jetons(int * ecrire_pere);

void envoie_jetons(int * ecrire_pere, int jetons);

void gagne_perdu(int * ecrire_pere, int bol);
int reception_gagne_perdu(int * ecrire_pere);
