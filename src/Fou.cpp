#include "Piece.h"
#include "Fou.h"
#include <iostream>

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

Fou::~Fou()
{
    //dtor
}
