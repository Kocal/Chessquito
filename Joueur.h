#ifndef JOUEUR_H
#define JOUEUR_H

#include <iostream>
#include "Partie.h"

class Partie;

class Joueur
{
    public:

        Joueur(std::string nom = "ZeratoR", Partie* partie = NULL);
        ~Joueur();

        void setNom(std::string nom) { this->nom = nom; }
        std::string getNom(void) { return this->nom; }

        void setPartie(Partie* partie) { this->partie = partie; }
        Partie* getPartie(void) { return this->partie; }
        Partie* partie;

    private:
        std::string nom;
};

#endif // JOUEUR_H
