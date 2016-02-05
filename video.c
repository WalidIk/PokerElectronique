/*
jeux.c
---------

Par Lawid75, pour Mr P. Courant.

Rôle : Gestion de la video
*/



#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "jeux.h"
#include "constante.h"

void Initialisation_Accueil(SDL_Surface **ecran, FLAG *FLAG, SDL_Rect *position_carte)
{
    /*Declaration des variables */

    SDL_Surface *titre = NULL;
    SDL_Surface *version = NULL;
    SDL_Surface *initialisation = NULL;
    SDL_Rect position_titre, position_version, position_initialisation;
    TTF_Font *police_titre = NULL;
    TTF_Font *police_contenu = NULL;
    TTF_Font *police_version = NULL;
    /* Fin Declaration  */

    /* --------------- */

    /* Initialisation des FLAG permettant de demarer la premiere boucle */
    FLAG->FLAG_INI = 1;
    FLAG->FLAG_JEUX = 0;
    FLAG->FLAG_GAIM = 0;
    FLAG->FLAG_SELECTION = 0;
    FLAG->FLAG_RESULTAT = 0;

    /* Fin Initialisation  */

    /* Initialisation de la position des cartes */
    (position_carte)[0].x = 50;
    (position_carte)[0].y = 250;

    (position_carte)[1].x = 50+150;
    (position_carte)[1].y = 250;

    (position_carte)[2].x = 50+300;
    (position_carte)[2].y = 250;

    (position_carte)[3].x = 50+450;
    (position_carte)[3].y = 250;

    (position_carte)[4].x = 50+600;
    (position_carte)[4].y = 250;

    /* Fin Initialisation  */

    /* --------------- */

    /* Initialisation de la vidéo */

    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    *ecran = SDL_SetVideoMode(LARGEUR_FENETRE, HAUTEUR_FENETRE, 32 , SDL_HWSURFACE | SDL_DOUBLEBUF);

    SDL_WM_SetCaption("TP", NULL);

    SDL_FillRect(*ecran, NULL, SDL_MapRGB((**ecran).format, 0, 0, 255));
    /* Fin Initialisation  */

    /* --------------- */

    /* Ecran d'accueil */

    police_contenu = TTF_OpenFont("BebasNeue.otf", 30);
    police_titre = TTF_OpenFont("code.ttf", 50);
    police_version = TTF_OpenFont("code.ttf", 10);

    SDL_Color couleurNoire = {255, 255, 255};

    titre = TTF_RenderText_Blended(police_titre, "POKER CASINO", couleurNoire);
    initialisation = TTF_RenderText_Blended(police_contenu, "Pour commencer appuyer sur la touche [ESPACE]", couleurNoire);
    version = TTF_RenderText_Blended(police_version, "Poker V1.0 / COPYRIGHT - Walid IKACHADEN", couleurNoire);

    position_titre.x = 200;
    position_titre.y = 150;

    position_version.x = 280;
    position_version.y = 400;

    position_initialisation.x = 200;
    position_initialisation.y = 250;

    /*Fin ecran d'accueil */

    /* --------------- */

    SDL_BlitSurface(titre, NULL, *ecran, &position_titre);
    SDL_BlitSurface(version, NULL, *ecran, &position_version);
    SDL_BlitSurface(initialisation, NULL, *ecran, &position_initialisation);

    /*Mise a jour de l'ecran */
    SDL_Flip(*ecran);

}
