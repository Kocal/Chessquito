#include <iostream>
#include "Joueur.h"

using std::cout;
using std::endl;

Joueur::Joueur(std::string nom, Partie* partie)
    : partie(partie), nom(nom)
{
    std::cout << "Création du joueur " << nom << std::endl;
}


Joueur::~Joueur() {
    cout << "Le joueur " << this->getNom() << " a quitté la partie." << endl;

    if(this->partie) {
        this->partie->quitte(this);
        this->partie = NULL;
    }
}
