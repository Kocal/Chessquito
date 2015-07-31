#include <cmath>
#include <string>
#include "Cavalier.h"
#include "Util.h"

Cavalier::Cavalier(int couleur, int etat, int valeur, int code)
    : Piece(couleur, etat, valeur, code)
{
}

bool Cavalier::verifierDeplacement(Coordonnees co1, Coordonnees co2) {
    int a = std::abs(co1.x - co2.x);
    int b = std::abs(co1.y - co2.y);

    return (a == 1 && b == 2) || (a == 2 && b == 1);
}

Cavalier::~Cavalier() {}
