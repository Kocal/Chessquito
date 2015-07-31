#include <cmath>
#include "Fou.h"
#include "Util.h"

Fou::Fou(int couleur, int etat, int valeur, int code)
    : Piece(couleur, etat, valeur, code)
{
}

bool Fou::verifierDeplacement(Coordonnees co1, Coordonnees co2) {
    return std::abs(co1.x - co2.x) == std::abs(co1.y - co2.y);
}

Fou::~Fou() {}
