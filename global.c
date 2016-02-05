/*
global.c
---------

Par Lawid75, pour Mr P. Courant.

Rôle : gestion des fonctions global du jeu
*/


#include <stdlib.h>
#include <stdio.h>
#include "jeux.h"
#include <dirent.h>
#include <string.h>
#include <time.h>
#include "video.h"



int Random (int min, int max)
{

    static int first = 0;
    if (first == 0){
      srand (time (NULL));
      first = 1;
    }

    return (min + (rand () % (max-min+1)));
}







int isvalid(int nombre,int* tab,int taille, int emplacement)
{
   int i;


   for(i=0;i<=taille;i++){

    if (emplacement != i){
      if (tab[i]==nombre){
         return 0;
      }
    }
   }
   return 1;
}





void ordonnerTableau(JEUXCARTE *tableau, int tailleTableau)
{
       int i,j,tmp;

    char *tmp1;



    for(i=0;i<tailleTableau-1;i++)
    {
       for(j=i+1;j<tailleTableau;j++)
       {
           if (tableau[j].carte<tableau[i].carte){

            tmp=tableau[i].carte;
            tmp1=*tableau[i].couleur;

            tableau[i].carte=tableau[j].carte;
            *tableau[i].couleur=*tableau[j].couleur;
            //strcpy(tableau[i].couleur, tableau[j].couleur);

            tableau[j].carte=tmp;
            *tableau[j].couleur = tmp1;
            //strcpy(tableau[j].couleur, tmp1);
           }

       }
    }

}
