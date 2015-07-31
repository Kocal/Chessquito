#ifndef FOU_H
#define FOU_H

#include <string>
#include "Piece.h"
#include "Util.h"

class Fou : public Piece
{
    public:
        Fou(int couleur = BLANC, int etat = DISPONIBLE, int valeur = 2, int code = FOU);
        ~Fou();

        bool verifierDeplacement(Coordonnees coordonnees1, Coordonnees coordonnees2);
        bool verifierDeplacement(std::string coordonnees1, std::string coordonnees2) {
            return Piece::verifierDeplacement(coordonnees1, coordonnees2);
        }

        virtual std::string toString(bool full) { return Piece::toString(this->code, this->couleur, full); }
};

#endif // FOU_H
