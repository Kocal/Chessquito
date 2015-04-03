#include <iostream>
#include "Util.h"
#include "Piece.h"
#include "Reine.h"

using namespace std;

Reine::Reine() : Piece() {
    cout << "Reine()" << endl;
}

Reine::Reine(int c) : Piece(c) {
    cout << "Reine(int) : " << this->couleur << endl;
}

Reine::Reine(int c, int e) : Piece(c, e) {
    cout << "Reine(int, int) : " << this->couleur << ", " << this->etat << endl;
}

Reine::Reine(Reine const& t) : Piece(t) {
    cout << "Reine(Reine const& t)" << endl;
}

bool Reine::verifierDeplacement(string c1, string c2) {
    int x, y, x2, y2;
    coordonnees(c1, x, y);
    coordonnees(c2, x2, y2);

    return abs(x - x2) == abs(y - y2);
}

void Reine::affichage() {
    Piece::affichage("Reine", this->couleur);
}

string Reine::getCode() {
    return Piece::getCode('R', this->couleur);
}

Reine::~Reine()
{
    //dtor
}
