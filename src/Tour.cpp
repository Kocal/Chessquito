#include <iostream>
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

Tour::~Tour()
{
    //dtor
}
