#include <iostream>
#include "Util.h"
#include "Piece.h"
#include "Tour.h"

using namespace std;

Tour::Tour() : Piece() {
    cout << "Tour()" << endl;
}

Tour::Tour(int c) : Piece(c) {
    cout << "Tour(int) : " << this->couleur << endl;
}

Tour::Tour(int c, int e) : Piece(c, e) {
    cout << "Tour(int, int) : " << this->couleur << ", " << this->etat << endl;
}

Tour::Tour(Tour const& t) : Piece(t) {
    cout << "Tour(Tour const& t)" << endl;
}

void Tour::affichage() {
    Piece::affichage("Tour", this->couleur);
}

bool Tour::verifierDeplacement(string c1, string c2) {
    int x, y, x2, y2;
    coordonnees(c1, x, y);
    coordonnees(c2, x2, y2);

    return x == x2 || y == y2;
}

/*
const Piece* Tour::operator=(Tour* const& p) const {
    cout << "Ancienne pièce : " << this << endl;
    cout << "Nouvelle pièce : " << p << endl;

    if(p != this) {
        p->setCouleur(this->getCouleur());
        p->setEtat(this->getEtat());
        return &p;
    }

    return NULL;
}
*/

Tour::~Tour()
{
    //dtor
}
