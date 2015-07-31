#ifndef REINE_H
#define REINE_H

#include <string>
#include "Piece.h"
#include "Util.h"

class Reine : public Piece
{
    public:
        Reine(int couleur = BLANC, int etat = DISPONIBLE, int valeur = 5, int code = REINE);
        ~Reine();

        bool verifierDeplacement(Coordonnees coordonnees1, Coordonnees coordonnees2);
        bool verifierDeplacement(std::string coordonnees1, std::string coordonnees2) {
            return Piece::verifierDeplacement(coordonnees1, coordonnees2);
        }

        virtual std::string toString(bool full) { return Piece::toString(this->code, this->couleur, full); }
};

#endif // REINE_H
