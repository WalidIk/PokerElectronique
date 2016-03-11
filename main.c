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
#include "global.h"
#include "constante.h"
#include "credit.h"

int main(int argc, char *argv[])
{

    char dossier[] = CHEMIN_CARTE;
    char JeuxDeCarte[MAX][MAX];
    int JeuxActuel[NB_CARTE] = RAZ_CARTE;

    //Déclaration des variables vidéo
    SDL_Surface *ecran = NULL;
    SDL_Surface *carte[NB_CARTE] = RAZ_CARTE;
    SDL_Rect position_carte[NB_CARTE];
    SDL_Rect position_credit;
    SDL_Rect position_credit_reel;
    SDL_Event event;
    SDL_Surface *Affiche_Credit = NULL;
    SDL_Surface *Affiche_Credit_Reel = NULL;


    //Declaration des variables concernant le jeu
    int i = 1;
    int MainGagnante[NB_CARTE] = RAZ_CARTE;
    int continuer = 1;
    int Selection_Carte[NB_CARTE] = RAZ_SELECTION;
    int MainJouer[NB_CARTE] = RAZ_MAIN;
    int MainGarder[NB_CARTE] = RAZ_CARTE;
    char *JeuxActuel1[NB_CARTE] = RAZ_CARTE;
    int Credit = CREDIT;
    //Declaration du flag permettant de gerer les etapes du jeu
    FLAG FLAG;


    Initialisation_Accueil(&ecran, &FLAG, position_carte);

    Initialisation_Jeux(dossier, &JeuxDeCarte, &i);



     while (continuer)
     {

         SDL_WaitEvent(&event);
         switch(event.type)
         {
             case SDL_QUIT:
                continuer = 0;
                break;

            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                     case SDLK_KP_ENTER:
                             if (FLAG.FLAG_JEUX == 1){
                                Retirer_Credit(&Credit);
                                Generation_Visuel_Credit(&ecran, &Affiche_Credit, &position_credit, &Affiche_Credit_Reel, &position_credit_reel, &Credit);
                            }
                            Gestion_Jeux(&ecran, &carte[6], &JeuxDeCarte, &position_carte, &MainJouer, &FLAG, &Selection_Carte, &JeuxActuel[NB_CARTE], JeuxActuel1, MainGagnante, &MainGarder, &Credit);
                            break;

                     case SDLK_KP1:
                        if (FLAG.FLAG_SELECTION == 1){
                            if (Selection_Carte[0] == 0){
                                RetirerCarte(&ecran, &carte[6], &position_carte, &MainJouer, &FLAG, &Selection_Carte, &MainGarder, 0);
                                Generation_Visuel_Credit(&ecran, &Affiche_Credit, &position_credit, &Affiche_Credit_Reel, &position_credit_reel, &Credit);
                                SDL_Flip(ecran);
                                break;

                            }else if(Selection_Carte[0] == 1){
                                GarderCarte(&MainJouer, &FLAG, &Selection_Carte, &position_carte, &ecran, &MainGarder, 0);
                                break;
                            }

                         }
                         break;
                     case SDLK_KP2:
                         if (FLAG.FLAG_SELECTION == 1){
                            if (Selection_Carte[1] == 0){
                                RetirerCarte(&ecran, &carte[6], &position_carte, &MainJouer, &FLAG, &Selection_Carte, &MainGarder, 1);
                                Generation_Visuel_Credit(&ecran, &Affiche_Credit, &position_credit, &Affiche_Credit_Reel, &position_credit_reel, &Credit);
                                SDL_Flip(ecran);
                                break;
                            }else if(Selection_Carte[1] == 1){
                                GarderCarte(&MainJouer, &FLAG, &Selection_Carte, &position_carte, &ecran, &MainGarder, 1);
                                break;
                            }
                         }
                         break;
                     case SDLK_KP3:
                         if (FLAG.FLAG_SELECTION == 1){
                            if (Selection_Carte[2] == 0){
                                RetirerCarte(&ecran, &carte[6], &position_carte, &MainJouer, &FLAG, &Selection_Carte, &MainGarder, 2);
                                Generation_Visuel_Credit(&ecran, &Affiche_Credit, &position_credit, &Affiche_Credit_Reel, &position_credit_reel, &Credit);
                                SDL_Flip(ecran);
                                break;
                            }else if(Selection_Carte[2] == 1){
                                GarderCarte(&MainJouer, &FLAG, &Selection_Carte, &position_carte, &ecran, &MainGarder, 2);
                                break;
                            }
                         }
                         break;
                     case SDLK_KP4:
                         if (FLAG.FLAG_SELECTION == 1){
                            if (Selection_Carte[3] == 0){
                                RetirerCarte(&ecran, &carte[6], &position_carte, &MainJouer, &FLAG, &Selection_Carte, &MainGarder, 3);
                                Generation_Visuel_Credit(&ecran, &Affiche_Credit, &position_credit, &Affiche_Credit_Reel, &position_credit_reel, &Credit);
                                SDL_Flip(ecran);
                                break;
                            }else if(Selection_Carte[3] == 1){
                                GarderCarte(&MainJouer, &FLAG, &Selection_Carte, &position_carte, &ecran, &MainGarder, 3);
                                break;
                            }
                         }
                         break;
                     case SDLK_KP5:
                         if (FLAG.FLAG_SELECTION == 1){
                            if (Selection_Carte[4] == 0){
                                RetirerCarte(&ecran, &carte[6], &position_carte, &MainJouer, &FLAG, &Selection_Carte, &MainGarder, 4);
                                Generation_Visuel_Credit(&ecran, &Affiche_Credit, &position_credit, &Affiche_Credit_Reel, &position_credit_reel, &Credit);
                                SDL_Flip(ecran);
                                break;
                            }else if(Selection_Carte[4] == 1){
                                GarderCarte(&MainJouer, &FLAG, &Selection_Carte, &position_carte, &ecran, &MainGarder, 4);
                                break;
                            }
                         }
                         break;
                     case SDLK_SPACE:

                         if (Credit == 0){
                            Game_Over(&ecran);
                         }else{
                         if (FLAG.FLAG_INI == 1){
                             //Ecran RAZ
                            SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 255));
                            Generation_Visuel_Credit(&ecran, &Affiche_Credit, &position_credit, &Affiche_Credit_Reel, &position_credit_reel, &Credit);
                            NouvellePartie(&ecran, &carte[6],  &position_carte, &FLAG, &Affiche_Credit, position_credit, &Affiche_Credit_Reel, position_credit_reel);// Initialisation de l'application video

                            }}
                         break;
                     default:
                        break;
                }break;
            break;
         }





     }

    SDL_FreeSurface(Affiche_Credit_Reel);
    SDL_FreeSurface(Affiche_Credit);
    SDL_FreeSurface(carte[0]);
    SDL_FreeSurface(carte[1]);
    SDL_FreeSurface(carte[2]);
    SDL_FreeSurface(carte[3]);
    SDL_FreeSurface(carte[4]);

     SDL_Quit();

    return EXIT_SUCCESS;
}
