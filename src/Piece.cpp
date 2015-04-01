#include <iostream>
#include <cstdlib>
#include "Piece.h"
#include "Util.h"
using namespace std;

Piece::Piece() : couleur(COULEUR_BLANC), etat(ETAT_DISPONIBLE) {
    cout << "Piece() : couleur par défaut : " << this->couleur << endl;
}

Piece::Piece(int c) : couleur(c), etat(ETAT_DISPONIBLE) {
    cout << "Piece(int c) : " << this->couleur << endl;
}

Piece::Piece(int c, int e) : couleur(c), etat(e) {
    cout << "Piece(int c, int e) : " << this->couleur << ", " << this->etat << endl;
}

Piece::Piece(Piece const& p) : couleur(p.couleur) {
    cout << "Piece(Piece const& p)" << endl;
}

void Piece::setCouleur(int c) {
    if(c >= 0 && c <= 1) {
        this->couleur = c;
    }
}

int Piece::getCouleur(void) {
    return this->couleur;
}

void Piece::setEtat(int e) {
    if(e >= 0 && e <= 2) {
        this->etat = e;
    }
}

int Piece::getEtat(void) {
    return this->etat;
}

void Piece::affichage(string nom, int couleur) {
    //cout << "Pièce : " << nom << " ; couleur : " << getStringByCouleur(couleur) << endl;
}

string Piece::getCode(void) { return "XX";}

string Piece::getCode(char piece, int couleur) {
    string ret;

    ret += piece;
    ret += getCharByCouleur(couleur);

    return ret;
}

Piece::~Piece()
{
    //dtor
}
