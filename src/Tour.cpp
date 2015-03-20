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

bool Tour::verifierDeplacement(string c1, string c2) {
    int* co1 = coordonnees(c1);
    int* co2 = coordonnees(c2);

    return co1[0] == co2[0] || co1[1] == co2[1];
}

Tour::~Tour()
{
    //dtor
}
