/*
constantes.h
------------
Par Lawid75, pour Mr P. Courant.

Rôle : définit des constantes communes à tout le programme (taille de la fenêtre...)
*/

#ifndef DEF_CONSTANTES
#define DEF_CONSTANTES

    #define CHEMIN_CARTE        "./Jeux/" // Chemin du jeu de carte
    #define CHEMIN_CARTE_VIERGE "./Vierge/Vierge.png" // Chemin du jeu de carte
    #define CHEMIN_GARDER       "./Vierge/GARDER.png" // Chemin du jeu de carte
    #define CHEMIN_CREDIT       "./Vierge/CREDITS.png" // Chemin du jeu de carte
    #define CHEMIN_GO       	"./Vierge/GO.png" // Chemin du jeu de carte
    #define RAZ_CARTE           {0,0,0,0,0} // RAZ de la main gagnante
    #define RAZ_SELECTION       {1,1,1,1,1} // RAZ de la main selectioner
    #define RAZ_MAIN            {7,7,7,7,7} // RAZ de la main
    #define MAX                 256
    #define NB_CARTE            5
    #define LARGEUR_FENETRE     850
    #define HAUTEUR_FENETRE     550
    #define CREDIT              20
    //Tableau des mains possible
    #define CPAIRE               "PAIRE"
    #define CDOUBLE_PAIRE        "DOUBLE PAIR"
    #define CBRELAN              "BRELAN"
    #define CFULL                "FULL"
    #define CCARRE               "CARRE"
    #define CCOULEUR             "COULEUR"
    #define CSUITE               "SUITE"
    #define CQUINTE_FLUSH        "QUINTE FLUSH"
    #define CQUINTE_FLUSH_ROYALE "QUINTE FLUSH ROYALE"
    //tableau des gaims possible
    #define GPAIRE               0
    #define GDOUBLE_PAIRE        2
    #define GBRELAN              3
    #define GFULL                14
    #define GCARRE               20
    #define GCOULEUR             7
    #define GSUITE               5
    #define GQUINTE_FLUSH        50
    #define GQUINTE_FLUSH_ROYALE 500


#endif
