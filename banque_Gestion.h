//le pere envoie une carte au fils
void envoie_carte (int * descripteur_tube, deck_t * deck);
//le fils recois une carte et lajoute a sa main
card_t * reception_carte (int * ecrire_pere,card_t * man, Joueur j);
//destribution dune carte au pere
card_t * destribution_carte_pour_pere (int * ecrire_pere,card_t * man,deck_t * deck,int pid_fils,int statuts);
//ajouter une carte a la main dun joueur
card_t * ajout_main(int val,card_t * main);
//le msg recu de la part du fils au pere a propos de la pioche
void reception_fils(int * ecrire_fils);
//reception du score de la part du fils
int reception_fils_score(int * ecrire_fils);
//reception dune reponse a propos de la pioche 
int reception_fils_pioch(int * ecrire_fils);
//fonction qui envoie une carte si le joueur demande de piocher
void envoi_pioch(int pid_fils,int statuts,int * ecrire_pere, deck_t * deck);


