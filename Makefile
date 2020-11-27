
test: main
	./main																																																																																																																														#

# Edition de liens
main: deck.o main.o gestion_Cartes.o lire_ecrire.o banque_Gestion.o joueur_Gestion.o
	gcc deck.o main.o gestion_Cartes.o lire_ecrire.o banque_Gestion.o joueur_Gestion.o -o main 


#Compilation
banque_Gestion.o: banque_Gestion.c  deck.h gestion_Cartes.h lire_ecrire.h
		gcc -c banque_Gestion.c
#Compilation
lire_ecrire.o: lire_ecrire.c gestion_Cartes.h
	gcc -c lire_ecrire.c
# Compilation
gestion_Cartes.o: gestion_Cartes.c  deck.h gestion_Cartes.h
	gcc -c gestion_Cartes.c 
# Compilation
deck.o: deck.c deck.h gestion_Cartes.h
	gcc -c deck.c 
#Compilation
joueur_Gestion.o: joueur_Gestion.c deck.h gestion_Cartes.h lire_ecrire.h banque_Gestion.h
	gcc -c joueur_Gestion.c
# Compilation
main.o: main.c deck.h gestion_Cartes.h lire_ecrire.h
	gcc -c main.c
editeur:
	geany *.c deck.h mes_types.h gestion_Cartes.h &



clean:
	rm -f *.o
	rm -f main
	
