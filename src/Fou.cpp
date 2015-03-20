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
    int* co1 = coordonnees(c1);
    int* co2 = coordonnees(c2);

    bool ret =  abs(co1[0] - co2[0]) == abs(co1[1] - co2[1]);

    delete[] co1;
    delete[] co2;

    return ret;
}

void Fou::affichage() {
    Piece::affichage("Fou", this->couleur);
}

Fou::~Fou()
{
    //dtor
}
