#include <cmath>
#include "Pion.h"
#include "Util.h"

Pion::Pion(int couleur, int etat, int valeur, int code)
    : Piece(couleur, etat, valeur, code)
{
}

bool Pion::verifierDeplacement(Coordonnees co1, Coordonnees co2) {
    int a = std::abs(co1.y - co2.y);
    return std::abs(co1.x - co2.x) == 1 && (a == 0 || a == 1);
}

Pion::~Pion() {}
