#ifndef ROI_H
#define ROI_H

#include <string>
#include "Piece.h"
#include "Util.h"

class Roi : public Piece
{
    public:
        Roi(int couleur = BLANC, int etat = DISPONIBLE, int valeur = 0, int code = ROI);
        ~Roi();

        bool verifierDeplacement(Coordonnees coordonnees1, Coordonnees coordonnees2);
        bool verifierDeplacement(std::string coordonnees1, std::string coordonnees2) {
            return Piece::verifierDeplacement(coordonnees1, coordonnees2);
        }

        virtual std::string toString(bool full) { return Piece::toString(this->code, this->couleur, full); }
};

#endif // ROI_H
