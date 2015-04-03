#include <iostream>
#include "Util.h"
#include "Piece.h"
#include "Cavalier.h"

using namespace std;

Cavalier::Cavalier() : Piece() {
    cout << "Cavalier()" << endl;
}

Cavalier::Cavalier(int c) : Piece(c) {
    cout << "Cavalier(int) : " << this->couleur << endl;
}

Cavalier::Cavalier(int c, int e) : Piece(c, e) {
    cout << "Cavalier(int, int) : " << this->couleur << ", " << this->etat << endl;
}

Cavalier::Cavalier(Cavalier const& t) : Piece(t) {
    cout << "Cavalier(Cavalier const& t)" << endl;
}

bool Cavalier::verifierDeplacement(string c1, string c2) {
    int x, y, x2, y2;
    coordonnees(c1, x, y);
    coordonnees(c2, x2, y2);

    return abs(x - x2) == abs(y - y2);
}

void Cavalier::affichage() {
    Piece::affichage("Cavalier", this->couleur);
}

string Cavalier::getCode() {
    return Piece::getCode('C', this->couleur);
}

Cavalier::~Cavalier()
{
    //dtor
}
