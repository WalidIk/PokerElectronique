/*
global.h
----------

Par Lawid75, pour Mr P. Courant.

Rôle : prototypes des fonctions global du jeu
*/


#ifndef DEF_GLOBAL
#define DEF_GLOBAL


/*------------------Prototype-------------------------------*/

int isvalid(int nombre,int* tab,int taille, int emplacement); //Aucun_Doublon
int Random (int min, int max); // Aleatoire
void ordonnerTableau(JEUXCARTE *tableau, int tailleTableau); // Ordonner_Tableau


#endif
