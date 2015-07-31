#include "Piece.h"
#include "Util.h"

Piece::Piece(int couleur, int etat, int valeur, int code)
    : couleur(couleur), etat(etat), valeur(valeur), code(code)
{

}

bool Piece::verifierDeplacement(std::string c1, std::string c2) {
    Coordonnees co1;
    Coordonnees co2;

    coordonnees(c1, co1);
    coordonnees(c2, co2);

    return this->verifierDeplacement(co1, co2);
}

std::string Piece::toString(int code, int couleur, bool full) {
    std::string piece = pieceToString(code);

    if(full) {
        return piece + " " + couleurToString(couleur);
    }

    std::string p(piece, 0, 2);
    std::string c(couleurToString(couleur), 0, 2);
    return p + c;
}

Piece::~Piece() {

}
