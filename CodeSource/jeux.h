/*
jeux.h
----------

Par Lawid75, pour Mr P. Courant.

Rôle : prototypes des fonctions de gestion du jeu de poker
*/




#ifndef JEUX_H_INCLUDED
#define JEUX_H_INCLUDED

#include <SDL_ttf.h>


/*------------------Structure-------------------------------*/

typedef struct FLAG FLAG;
struct FLAG
{
    int FLAG_INI;
    int FLAG_JEUX;
    int FLAG_GAIM;
    int FLAG_SELECTION;
    int FLAG_RESULTAT;

};

typedef struct JEUXCARTE JEUXCARTE;
struct JEUXCARTE
{
    char titre[30];
    char couleur[10];
    int carte;


};

/*------------------Prototype-------------------------------*/


void Initialisation_Jeux(char *dossier, char JeuxDeCarte[256][256], int *i);
void Gestion_Jeux(SDL_Surface **ecran, SDL_Surface **carte, char JeuxDeCarte[256][256], SDL_Rect *position_carte, int *MainJouer[5], FLAG *FLAG, int *Selection_Carte[5], int *JeuxActuel[5], char **JeuxActuel1, int MainGagnante[5], int *MainGarder[5], int *Credit); //Gestion_Jeu
void GarderCarte(int* MainJouer[5], FLAG *FLAG, int *Selection_Carte[5], SDL_Rect *position_carte, SDL_Surface **ecran, int *MainGarder[5], int touche);
void RetirerCarte(SDL_Surface **ecran, SDL_Surface **carte, SDL_Rect *position_carte, int* MainJouer[5], FLAG *FLAG, int *Selection_Carte[5], int *MainGarder[5], int touche);
void Affichage_Main(SDL_Surface **initialisation, TTF_Font **police_contenu, SDL_Rect *position_initialisation, char **JeuxActuel1, int MainEnCours[5], int *Credit); // Affichage_Main
char *TraductionCartes(JEUXCARTE *tableau); //Traduction_Carte
void NouvellePartie(SDL_Surface **ecran, SDL_Surface **carte, SDL_Rect *position_carte, FLAG *FLAG, SDL_Surface **Affiche_Credit, SDL_Rect position_credit, SDL_Surface **Affiche_Credit_Reel, SDL_Rect position_credit_reel);
void Conversion_CarteTableau(char **JeuxActuel, JEUXCARTE JeuxEnCours[5]); //Conversion_CarteTableau


#endif // JEUX_H_INCLUDED
