#ifndef PION_H
#define PION_H

#include <string>
#include "Piece.h"
#include "Util.h"

class Pion : public Piece
{
    public:
        Pion(int couleur = BLANC, int etat = DISPONIBLE, int valeur = 1, int code = PION);
        ~Pion();

        bool verifierDeplacement(Coordonnees coordonnees1, Coordonnees coordonnees2);
        bool verifierDeplacement(std::string coordonnees1, std::string coordonnees2) {
            return Piece::verifierDeplacement(coordonnees1, coordonnees2);
        }

        virtual std::string toString(bool full) { return Piece::toString(this->code, this->couleur, full); }
};

#endif // PION_H
