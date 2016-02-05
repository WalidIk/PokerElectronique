/*
jeux.c
---------

Par Lawid75, pour Mr P. Courant.

Rôle : Gestion du jeu
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

void Initialisation_Jeux(char *dossier, char JeuxDeCarte[MAX][MAX], int *i)
{

    DIR *dir;
    struct dirent *ent;
    dir = opendir (dossier);
    if (dir != NULL)
    {
        while ((ent = readdir (dir)) != NULL)
            {
                if (!strcmp(ent->d_name, ".") || !strcmp(ent->d_name, "..")){

                }else{
                strcat(&JeuxDeCarte[*i], dossier);
                strcat(&JeuxDeCarte[*i], ent->d_name);
                *i = *i+1;

                }
            }
        closedir (dir);
    }
    else
    {
        perror ("Un probléme est survenu dans l'ouverture des cartes");
    }


return;


}


 void Gestion_Jeux(SDL_Surface **ecran, SDL_Surface **carte, char JeuxDeCarte[MAX][MAX], SDL_Rect *position_carte, int* MainJouer[NB_CARTE],FLAG *FLAG, int *Selection_Carte[NB_CARTE], int *JeuxActuel[NB_CARTE], char **JeuxActuel1, int MainGagnante[NB_CARTE], int *MainGarder[NB_CARTE], int *Credit)
 {
    SDL_Surface *initialisation = NULL;
    SDL_Rect position_initialisation;
    TTF_Font *police_contenu = NULL;
    int selection = 0;
    int compteur = 0;
    int MainEnCours[5] = RAZ_CARTE;
    int nombre;


    /* Le flag permet de vérifier que nous somme au debut d'une partie */
    if (FLAG->FLAG_JEUX == 1){
        MainGarder[0] = 0;
        MainGarder[1] = 0;
        MainGarder[2] = 0;
        MainGarder[3] = 0;
        MainGarder[4] = 0;
        MainGarder[5] = 0;
        MainJouer[0] = 7;
        MainJouer[1] = 7;
        MainJouer[2] = 7;
        MainJouer[3] = 7;
        MainJouer[4] = 7;
        MainJouer[5] = 7;


        /* Géneration des cartes aléatoire pour le premier tour*/
        for (compteur = 0 ; compteur <= 4 ; compteur++)
        {
            if (MainJouer[compteur] == 7){
                if (compteur == 0){
                    MainEnCours[compteur] = Random (1,52);
                }else{
                    do
                    {
                        MainEnCours[compteur] = Random (1,52);
                        nombre = MainEnCours[compteur];
                        JeuxActuel[compteur] = nombre;
                    } while(!isvalid(nombre, &MainEnCours, 4, compteur));
                }
            }
        }

        for (compteur = 0 ; compteur <= 4 ; compteur++)
        {
            selection = MainEnCours[compteur];
            MainGagnante[compteur] = selection;
            JeuxActuel[compteur] = selection;
            JeuxActuel1[compteur] = JeuxDeCarte[selection];
            carte[compteur] = IMG_Load(JeuxDeCarte[selection]);

        }

        /*Blit du jeu generé */

        for (compteur = 0 ; compteur <= 4 ; compteur++)
        {
            SDL_BlitSurface(carte[compteur], NULL, *ecran, &position_carte[compteur]);
        }

    }



    /* Le flag permet de vérifier que nous somme au second tour de la partie */

    if (FLAG->FLAG_GAIM == 1){

        for (compteur = 0 ; compteur <= 4 ; compteur++)
        {
            if (MainJouer[compteur]==7){
                do
                {
                    MainEnCours[compteur] = Random(1,52);
                    nombre = MainEnCours[compteur];
                    JeuxActuel[compteur] = nombre;
                } while(!isvalid(nombre, JeuxActuel, 4, compteur));
            }
         }


        for (compteur = 0 ; compteur <= 4 ; compteur++)
        {
            if (MainJouer[compteur]==7){
                selection = MainEnCours[compteur];
                MainGagnante[compteur] = selection;
                JeuxActuel1[compteur] = JeuxDeCarte[selection];
                carte[compteur] = IMG_Load(JeuxDeCarte[selection]);
            }
        }


        /*Blit du jeu generé */
        for (compteur = 0 ; compteur <= 4 ; compteur++)
        {
            SDL_BlitSurface(carte[compteur], NULL, *ecran, &position_carte[compteur]);
        }


        Affichage_Main(&initialisation, &police_contenu, &position_initialisation, JeuxActuel1, MainGagnante, Credit);

        SDL_BlitSurface(initialisation, NULL, *ecran, &position_initialisation);

        /*RAZ Flag permettant de reprendre une nouvelle partie */
        FLAG->FLAG_GAIM = 0;
        FLAG->FLAG_INI = 1;
        FLAG->FLAG_JEUX = 0;
        FLAG->FLAG_SELECTION = 0;
        //FLAG permetant d'afficher le GAIN
        FLAG->FLAG_RESULTAT = 1;
        /* Remise a zéro des cartes */
        MainJouer[0] = 7;
        MainJouer[1] = 7;
        MainJouer[2] = 7;
        MainJouer[3] = 7;
        MainJouer[4] = 7;

    }

    /* Mise en place des parametres afin de passer au second tour */

    if (FLAG->FLAG_JEUX == 1){

        FLAG->FLAG_JEUX = 0;
        FLAG->FLAG_SELECTION = 1;
        FLAG->FLAG_GAIM = 1;
        FLAG->FLAG_RESULTAT = 0;
        Selection_Carte[0] = 1;
        Selection_Carte[1] = 1;
        Selection_Carte[2] = 1;
        Selection_Carte[3] = 1;
        Selection_Carte[4] = 1;

   }



    /*Mise a jour de l'écran */
    SDL_Flip(*ecran);

 }




 void RetirerCarte(SDL_Surface **ecran, SDL_Surface **carte, SDL_Rect *position_carte, int* MainJouer[NB_CARTE], FLAG *FLAG, int *Selection_Carte[NB_CARTE], int *MainGarder[NB_CARTE], int touche){

    int compteur=0;
    MainJouer[touche] = 7;
    FLAG->FLAG_GAIM = 1;
    Selection_Carte[touche] = 1;
    MainGarder[touche] = 0;

    SDL_FillRect(*ecran, NULL, SDL_MapRGB((**ecran).format, 0, 0, 255));


    SDL_Rect position;
    SDL_Surface *Img_Garder;

    Img_Garder = IMG_Load(CHEMIN_GARDER);

    for (compteur = 0 ; compteur <= 4 ; compteur++)
     {
             SDL_BlitSurface(carte[compteur], NULL, *ecran, &position_carte[compteur]);
     }

    for (compteur = 0 ; compteur <= 4 ; compteur++)
     {
         if (MainGarder[compteur] == 1){
            position.x = ((position_carte)[compteur].x)+15;
            position.y = ((position_carte)[compteur].y)+80;
            SDL_BlitSurface(Img_Garder, NULL, *ecran, &position);
         }
     }


}

void GarderCarte(int* MainJouer[5], FLAG *FLAG, int *Selection_Carte[NB_CARTE], SDL_Rect *position_carte, SDL_Surface **ecran, int *MainGarder[NB_CARTE], int touche){

    SDL_Rect position;
    SDL_Surface *Img_Garder;

    MainGarder[touche] = 1;
    Img_Garder = IMG_Load(CHEMIN_GARDER);
    position.x = ((position_carte)[touche].x)+15;
    position.y = ((position_carte)[touche].y)+80;
    MainJouer[touche] = 1;
    FLAG->FLAG_GAIM = 1;
    Selection_Carte[touche] = 0;

    SDL_BlitSurface(Img_Garder, NULL, *ecran, &position);

    SDL_Flip(*ecran);
}


void Affichage_Main(SDL_Surface **initialisation, TTF_Font **police_contenu, SDL_Rect *position_initialisation, char **JeuxActuel1, int MainEnCours[NB_CARTE], int *Credit){

    JEUXCARTE JeuxEnCours[NB_CARTE];
    char *RESULTAT;




    Conversion_CarteTableau(JeuxActuel1, &JeuxEnCours);

    ordonnerTableau(JeuxEnCours, NB_CARTE);


    RESULTAT = TraductionCartes(&JeuxEnCours);

    Calcul_Gaim(Credit, RESULTAT);





    *police_contenu = TTF_OpenFont("code.ttf", 25);

    SDL_Color couleurNoire = {255, 255, 255};

    *initialisation = TTF_RenderText_Blended(*police_contenu, RESULTAT, couleurNoire);

    position_initialisation->x = 300;
    position_initialisation->y = 180;


}

void NouvellePartie(SDL_Surface **ecran, SDL_Surface **carte, SDL_Rect *position_carte, FLAG *FLAG, SDL_Surface **Affiche_Credit, SDL_Rect position_credit, SDL_Surface **Affiche_Credit_Reel, SDL_Rect position_credit_reel) {
    int selection=0;
    int compteur=0;

    /*On rentre dans la boucle du jeux */
    FLAG->FLAG_INI = 0;
    FLAG->FLAG_JEUX = 1;


    /*On charge les cartes vierges afin d'initialiser la partie */
    carte[0] = IMG_Load(CHEMIN_CARTE_VIERGE);
    carte[1] = IMG_Load(CHEMIN_CARTE_VIERGE);
    carte[2] = IMG_Load(CHEMIN_CARTE_VIERGE);
    carte[3] = IMG_Load(CHEMIN_CARTE_VIERGE);
    carte[4] = IMG_Load(CHEMIN_CARTE_VIERGE);

    SDL_BlitSurface(carte[0], NULL, *ecran, &position_carte[0]);
    SDL_BlitSurface(carte[1], NULL, *ecran, &position_carte[1]);
    SDL_BlitSurface(carte[2], NULL, *ecran, &position_carte[2]);
    SDL_BlitSurface(carte[3], NULL, *ecran, &position_carte[3]);
    SDL_BlitSurface(carte[4], NULL, *ecran, &position_carte[4]);

    SDL_Flip(*ecran);


 }

char *TraductionCartes(JEUXCARTE* tableau)
{

    int i;
    int COMPTEUR=0;
    int PAIR = 0;
    int DOUBLE_PAIR = 0;
    int BRELAN = 0;
    int FULL = 0;
    int CARRE = 0;
    int COULEUR = 0;
    int SUITE = 0;
    int suite = 0;
    int COMPTEUR_SUITE;
    int COMPTEUR_COULEUR = 0;
    char *RESULTAT_MAIN;

    //On initialise la main
    RESULTAT_MAIN = "Miser un jeton";

    //TROUVER UNE PAIRE, DOUBLE PAIRE, BRELAN, FULL OU CARRER
    for (i=0; i<=3;i++){
        if (tableau[i].carte == tableau[i+1].carte){

            COMPTEUR++;

            if ((COMPTEUR == 1) && (tableau[i+1].carte != tableau[i+2].carte)){
                PAIR = PAIR + 1;
                RESULTAT_MAIN = CPAIRE;
            }
            if (PAIR == 2){
                DOUBLE_PAIR = 1;
                RESULTAT_MAIN = CDOUBLE_PAIRE;
                PAIR = 0;
            }
            if (COMPTEUR == 2){
                BRELAN = 1;
                RESULTAT_MAIN = CBRELAN;

            }
            if ((BRELAN == 1) && (PAIR == 1)){
                FULL = 1;
               RESULTAT_MAIN = CFULL;
            }
            if (COMPTEUR == 3){
                CARRE = 1;
                RESULTAT_MAIN = CCARRE;
            }
        }else{
            COMPTEUR = 0;
        }
    }


    //TROUVER UNE SUITE
    for (i=0; i<=4;i++){
        if (i == 0){
            if (tableau[i].carte == 1 && tableau[i+1].carte == 10){
                suite = 9;
                COMPTEUR_SUITE  = 1;
                suite++;
            }else{
                suite = tableau[i].carte;
                COMPTEUR_SUITE  = 1;
                suite++;
            }
        }else{
            if (tableau[i].carte == suite){
                COMPTEUR_SUITE++;
                suite = suite + 1;
            }
        }
    }

    if (COMPTEUR_SUITE == 5){
       RESULTAT_MAIN = CSUITE;
        SUITE = 1;
    }

    //TROUVER UNE COULEUR
    for (i=0;i<=4;i++){
        if (strcmp(tableau[0].couleur, tableau[i].couleur) == NULL){
            COMPTEUR_COULEUR++;
        }
    }

    if (COMPTEUR_COULEUR == 5){
        RESULTAT_MAIN = CCOULEUR;
        COULEUR = 1;
    }

    //TROUVER UNE QUINTE FLUSH
    if ((SUITE == 1) && (COULEUR == 1)){
        RESULTAT_MAIN = CQUINTE_FLUSH;
        if ((tableau[4].carte == 13) && ((tableau[0].carte == 1))){
            RESULTAT_MAIN = CQUINTE_FLUSH_ROYALE;
        }
    }

    return RESULTAT_MAIN;
}



void Conversion_CarteTableau(char **JeuxActuel, JEUXCARTE JeuxEnCours[NB_CARTE])
{
    int i = 0;
    char tmpCarte[NB_CARTE][20];
    int len;
    char *Couleur;



    strcpy(tmpCarte[0], JeuxActuel[0]+7);
    strcpy(tmpCarte[1], JeuxActuel[1]+7);
    strcpy(tmpCarte[2], JeuxActuel[2]+7);
    strcpy(tmpCarte[3], JeuxActuel[3]+7);
    strcpy(tmpCarte[4], JeuxActuel[4]+7);



    for (i=0;i<=4;i++){
        Couleur = NULL;
        len = strlen(tmpCarte[i]);
        tmpCarte[i][len-4] = '\0';
        Couleur = tmpCarte[i][0];
        strcpy(&JeuxEnCours[i].couleur, &Couleur);
        JeuxEnCours[i].carte = atoi(&tmpCarte[i][2]);
    }



}
