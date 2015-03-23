#include "Joueur.h"
#include <iostream>

using namespace std;

Joueur::Joueur() : partie(NULL) {}

Joueur::Joueur(string nom) : nom(nom), partie(NULL) {
}

void Joueur::setNom(string nom) {
    this->nom = nom;
}

string Joueur::getNom(void) {
    return this->nom;
}

void Joueur::setPartie(Partie* partie) {
    this->partie = partie;
}

Partie* Joueur::getPartie(void) {
    return this->partie;
}

Joueur::~Joueur() {
    cout << "Le joueur " << this->getNom() << " va quitter la partie" << endl;
    if(this->getPartie()) {
        this->getPartie()->quittePartie(this);
    }
}
