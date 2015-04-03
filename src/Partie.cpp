#include <iostream>
#include "Partie.h"
#include "Util.h"

using namespace std;

Partie::Partie() : nbJoueurs(0), nbJoueursMax(2), j1(NULL), j2(NULL) {}

Partie::Partie(string date) : date(date), nbJoueurs(0), nbJoueursMax(2), j1(NULL), j2(NULL) {}

void Partie::setDate(string date) {
    this->date = date;
}

string Partie::getDate() {
    return this->date;
}

bool Partie::setJoueur(Joueur* joueur) {

    this->nbJoueurs++;

    if(!this->j1) {
        joueur->setPartie(this);
        this->j1 = joueur;
    } else if (!this->j2) {
        joueur->setPartie(this);
        this->j2 = joueur;
    } else {
        this->nbJoueurs--;
        cerr << "Impossible d'ajouter le joueur " << joueur->getNom() << " (" << joueur << ")" << endl;
        return false;
    }

    cout << "Ajout du joueur " << joueur->getNom() << " (" << joueur << ")" << " fait avec succès" << endl;
    return true;
}

void Partie::quittePartie(Joueur* j) {
    cout << "Le joueur " << j->getNom() << " a quitté la partie." << endl;
    this->nbJoueurs--;
}

bool Partie::estJouable(void) {
    return this->nbJoueurs == this->nbJoueursMax;
}

void Partie::initPlateau(void) {
    for(int i = 0; i < plateauTaille; i++) {
        for(int j = 0; j < plateauTaille; j++) {
            this->plateau[i][j] = NULL;
        }
    }
}

bool Partie::canPieceBePlaced(string c) {
    int x, y;
    coordonnees(c, x, y);

    if(x < 0 || x >= plateauTaille
    || y < 0 || y >= plateauTaille) {
        return false;
    }

    if(this->plateau[x][y] != NULL) {
        return false;
    }

    return true;
}

bool Partie::setPiece(Piece* piece, string c) {
    int x, y;
    coordonnees(c, x, y);

    if(this->canPieceBePlaced(c)) {
        this->plateau[x][y] = piece;
        return true;
    }

    return false;
}

Piece* Partie::getPiece(int x , int y) const {
    return this->plateau[x][y];
}

Piece* Partie::operator()(int x) {
    return this->getPiece(x, 0);
}

Piece* Partie::operator()(int x, int y) {
    return this->getPiece(x, y);
}

Piece* Partie::operator()(string c) {
    int x, y;
    coordonnees(c, x, y);

    return this->getPiece(x, y);
}

const Piece* Partie::operator()(int x) const {
    return this->getPiece(x, 0);
}

const Piece* Partie::operator()(int x, int y) const {
    return this->getPiece(x, y);
}

const Piece* Partie::operator()(string c) const {
    int x, y;
    coordonnees(c, x, y);

    return this->getPiece(x, y);
}


ostream& operator<<(ostream &flux, Partie const &p) {
    for(int i = plateauTaille + 1; i--;) {

        if(i == plateauTaille) {
            for(int j = 0; j < plateauTaille; j++) {
                flux << "|  " << (char) (j + 'a') << "  ";
            }

            flux << '|' << endl;
            continue;
        }

        separationPlateau(plateauTaille);

        for(int j = 0; j < plateauTaille; j++) {
            int x = i;
            int y = j;

            //flux << "| " << x << ";" << j << " ";
            if(p.getPiece(x, y)) {
                flux << "| " << p.getPiece(x, y)->getCode() << "  ";
            } else {
                flux << "|     ";
            }
        }

        flux << "| " << i << endl;

    }

    return flux;
}

Partie::~Partie() {
    cout << "La partie " << this << " va s'arrêter." << endl;
    if(this->j1) {
        this->j1->setPartie(NULL);
    }

    if(this->j2) {
        this->j2->setPartie(NULL);
    }
}
