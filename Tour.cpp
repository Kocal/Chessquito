#include "Tour.h"
#include "Util.h"

Tour::Tour(int couleur, int etat, int valeur, int code)
    : Piece(couleur, etat, valeur, code)
{
}

bool Tour::verifierDeplacement(Coordonnees co1, Coordonnees co2) {
    return co1.x == co2.x || co1.y == co2.y;
}

Tour::~Tour() {}
