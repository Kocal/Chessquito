#include <cmath>
#include "Roi.h"
#include "Util.h"

Roi::Roi(int couleur, int etat, int valeur, int code)
    : Piece(couleur, etat, valeur, code)
{
}

bool Roi::verifierDeplacement(Coordonnees co1, Coordonnees co2) {
    int a = std::abs(co1.x - co2.x);
    int b = std::abs(co1.y - co2.y);
    return a >= 0 && a <= 1 && b >= 0 && b <= 1;
}

Roi::~Roi() {}
