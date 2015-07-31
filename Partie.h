#ifndef PARTIE_H
#define PARTIE_H

#include <string>
#include <vector>

#include "Plateau.h"
#include "Joueur.h"

class Joueur;
class Plateau;

class Partie
{
    public:
        Partie(std::string date = "01-01-1970", int nbJoueurs = 0,
               int largeurPlateau = 4, int longueurPlateau = 4, int nbPiecesParJoueur = 4);
        Partie(Partie* const&);
        ~Partie();

        Plateau* plateau;

        void addJoueur(Joueur* joueur);
        void listJoueurs(void);
        void organizePlayersArray(void);

        Joueur* getJoueur(int joueurID);
        Joueur* getCurrentJoueur(void);
        int getCurrentJoueurId(void);
        Joueur* getWinner(void);
        int getWinnerId(void);

        int getNbJoueurs(void) { return this->nbJoueurs; }
        int getNbPiecesParJoueur(void) { return this->nbPiecesParJoueur; }

        int getNbTours(void) { return this->nbTours; }
        void setNbTours(int tour) { this->nbTours = tour; }
        void increaseNbTours(void) { this->nbTours++; }

        int getNbToursSansPrise(void) { return this->nbToursSansPrise; }
        void setNbToursSansPrise(int tour) { this->nbToursSansPrise = tour; }
        void increaseNbToursSansPrise(void) { this->nbToursSansPrise++; }

        bool isJouable(void);
        bool isTerminee_regle1(void);
        void quitte(Joueur* joueur);

    private:
        std::string date;
        int nbJoueurs;
        int nbPiecesParJoueur;
        int nbTours;
        int nbToursSansPrise;

        Joueur** joueurs;
};

#endif // PARTIE_H
