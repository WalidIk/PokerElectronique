/*
credit.c
---------

Par Lawid75, pour Mr P. Courant.

Rôle : Gestion des crédits
*/


#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL_image.h> /* Inclusion du header de SDL_image (adapter le dossier au besoin) */
#include <stdio.h>
#include "jeux.h"
#include <dirent.h>
#include <string.h>
#include <time.h>
#include <SDL_ttf.h>
#include "video.h"
#include "constante.h"
#include "credit.h"



void Generation_Visuel_Credit(SDL_Surface **ecran, SDL_Surface **Affiche_Credit, SDL_Rect *position_credit, SDL_Surface **Affiche_Credit_Reel, SDL_Rect *position_credit_reel, int *Credit){

    TTF_Init();
    TTF_Font *police_credit = NULL;
    police_credit = TTF_OpenFont("code.ttf", 20);
    SDL_Color couleurNoire = {255, 255, 255};
    char credit[10]="";

    sprintf(&credit, "%d", *Credit); /* On écrit dans la chaîne "temps" le nouveau temps */

    *Affiche_Credit_Reel = TTF_RenderText_Blended(police_credit, &credit, couleurNoire);

    *Affiche_Credit = IMG_Load(CHEMIN_CREDIT);

    position_credit_reel->x = 750; // Les coordonnées de la surface seront (0, 0)
    position_credit_reel->y = 500;

    position_credit->x = 700; // Les coordonnées de la surface seront (0, 0)
    position_credit->y = 470;

    SDL_BlitSurface(*Affiche_Credit, NULL, *ecran, position_credit);
    SDL_BlitSurface(*Affiche_Credit_Reel, NULL, *ecran, position_credit_reel);

    // Remplissage de la surface avec du blanc
}


void Retirer_Credit(int *Credit){


    *Credit = *Credit - 1;


}




void Calcul_Gaim(int *Credit, char *Resultat_Main){

    FILE* fichier = NULL;

    fichier = fopen("WalidCredit.txt", "w");


    if (strcmp(Resultat_Main, CPAIRE) == 0) {
        *Credit = *Credit + 0;

    }// match!

    if (strcmp(Resultat_Main, CDOUBLE_PAIRE) == 0) {
        *Credit = *Credit + GDOUBLE_PAIRE;

    }// match!


    if (strcmp(Resultat_Main, CBRELAN) == 0) {
        *Credit = *Credit + GBRELAN;

    }// match!


    if (strcmp(Resultat_Main, CSUITE) == 0) {
        *Credit = *Credit + GSUITE;

    }// match!

    if (strcmp(Resultat_Main, CCOULEUR) == 0) {
        *Credit = *Credit + GCOULEUR;

    }// match!

    if (strcmp(Resultat_Main, CFULL) == 0) {
        *Credit = *Credit + GFULL;

    }// match!

    if (strcmp(Resultat_Main, CCARRE) == 0) {
        *Credit = *Credit + GCARRE;

    }// match!

    if (strcmp(Resultat_Main, CQUINTE_FLUSH) == 0) {
        *Credit = *Credit + GQUINTE_FLUSH;

    }// match!

        if (strcmp(Resultat_Main, CQUINTE_FLUSH_ROYALE) == 0) {
        *Credit = *Credit + GQUINTE_FLUSH_ROYALE;

    }// match!

}

void Game_Over(SDL_Surface **ecran){

    SDL_Rect position;
    SDL_Surface *Img_Garder;

    Img_Garder = IMG_Load(CHEMIN_GO);
    position.x = 250;
    position.y = 50;

    SDL_BlitSurface(Img_Garder, NULL, *ecran, &position);

    SDL_Flip(*ecran);
}
