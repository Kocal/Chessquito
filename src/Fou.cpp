#include <iostream>
#include <cmath>
#include "Util.h"
#include "Piece.h"
#include "Fou.h"

using namespace std;

Fou::Fou() : Piece() {
    cout << "Fou()" << endl;
}

Fou::Fou(int c) : Piece(c) {
    cout << "Fou(int) : " << this->couleur << endl;
}

Fou::Fou(int c, int e) : Piece(c, e) {
    cout << "Fou(int, int) : " << this->couleur << ", " << this->etat << endl;
}

Fou::Fou(Fou const& t) : Piece(t) {
    cout << "Fou(Fou const& t)" << endl;
}

bool Fou::verifierDeplacement(string c1, string c2) {
    int x, y, x2, y2;
    coordonnees(c1, x, y);
    coordonnees(c2, x2, y2);

    return abs(x - x2) == abs(y - y2);
}

void Fou::affichage() {
    Piece::affichage("Fou", this->couleur);
}

string Fou::getCode() {
    return Piece::getCode('F', this->couleur);
}

Fou::~Fou()
{
    //dtor
}
