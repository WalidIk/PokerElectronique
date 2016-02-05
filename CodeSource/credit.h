/*
credit.h
----------

Par Lawid75, pour Mr P. Courant.

Rôle : prototypes des fonctions de crédit du jeu
*/



#ifndef DEF_CREDIT
#define DEF_CREDIT


/*------------------Prototype-------------------------------*/


void Generation_Visuel_Credit(SDL_Surface **ecran, SDL_Surface **Affiche_Credit, SDL_Rect *position_credit, SDL_Surface **Affiche_Credit_Reel, SDL_Rect *position_credit_reel, int *Credit);
void Retirer_Credit(int *Credit);
void Game_Over(SDL_Surface **ecran);
void Calcul_Gaim(int *Credit, char *Resultat_Main);

#endif
