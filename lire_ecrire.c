#include "deck.h"
#include "gestion_Cartes.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>


int ouverture(){
    int descripteur;
    descripteur = open("ini.txt",O_RDONLY);
    return descripteur;
}

TABLE lecture_pour_table(TABLE tabl){
	char val[10] = {0};
	char c;
	int ligne[3];
	int descripteur=ouverture();
    int i,j;
    for(i=0;i<3;i++){
		j=0;
	do{
    read(descripteur,&c,1);
    val[j] = c;
    if (val[j]==';'){
		val[j]='\0';
		break;}
	j++;
	
    }while(c!=';' && j<10);
    ligne[i] = atoi(val);   
}
tabl.nbJoueurs=ligne[0];
tabl.nbDecks=ligne[1];
tabl.nbMains=ligne[2];
 return tabl;
}
Joueur lecture_pour_joueur(Joueur tabl, int nbline){
	char val[10] = {0};
	char c;
	int ligne[5];
	int descripteur=ouverture();
    int i,j;
    i=0;
    while(i<nbline)
    {
		do{
		read(descripteur,&c,1);
		
	}while(c!='\n');
		i++;
	}
    for(i=0;i<4;i++){
		j=0;
	if(i==1)
	{
	   do{
    read(descripteur,&c,1);
    val[j] = c;
    if (val[j]==';'){
		val[j]='\0';
		break;}
		tabl.typeMise[j] =val[j];
	j++;
	
    }while(c!=';' && j<10);  	
	}
	else
	{
	do{
    read(descripteur,&c,1);
    val[j] = c;
    if (val[j]==';'){
		val[j]='\0';
		break;}
	j++;
	
    }while(c!=';' && j<10);
    ligne[i] = atoi(val);   
}
}
tabl.nbJeton=ligne[0];
tabl.valStop=ligne[2];
tabl.objJeton=ligne[3];
 return tabl;
}

void ecriture(int descripteur, char c){
    write(descripteur, &c, 1);
}
int type_mise(int i){
    
    Joueur tabl;
    int nbline = 1;
    int j = 0;
    
    tabl = lecture_pour_joueur(tabl, nbline );
    while(tabl.typeMise != '0'){
        
        if((tabl.typeMise)[j] == '\0'){
            i = 1;
            return i;
            
        }
        if(((tabl.typeMise)[j]) == '+'){
            i = 2;
            return i;
        }
        
        if(((tabl.typeMise)[j]) == '-'){
            i = 3;
            return i;
        }
        j++;
    }
    return i;
}


