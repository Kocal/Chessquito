#ifndef TOUR_H
#define TOUR_H

#include <string>
#include "Piece.h"
#include "Util.h"

class Tour : public Piece
{
    public:
        Tour(int couleur = BLANC, int etat = DISPONIBLE, int valeur = 4, int code = TOUR);
        ~Tour();

        bool verifierDeplacement(Coordonnees coordonnees1, Coordonnees coordonnees2);
        bool verifierDeplacement(std::string coordonnees1, std::string coordonnees2) {
            return Piece::verifierDeplacement(coordonnees1, coordonnees2);
        }

        virtual std::string toString(bool full) { return Piece::toString(this->code, this->couleur, full); }
};

#endif // TOUR_H
