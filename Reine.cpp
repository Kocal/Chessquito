#include <iostream>
#include <cmath>
#include "Reine.h"
#include "Util.h"

Reine::Reine(int couleur, int etat, int valeur, int code)
    : Piece(couleur, etat, valeur, code)
{
}

bool Reine::verifierDeplacement(Coordonnees co1, Coordonnees co2) {
    return std::abs(co1.x - co2.x) == std::abs(co1.y - co2.y)
         || co1.x == co2.x || co1.y == co2.y;
}

Reine::~Reine() {

}
