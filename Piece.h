#ifndef PIECE_H
#define PIECE_H

#include "Util.h"

class Piece
{
    public:
        Piece(int couleur = BLANC, int etat = DISPONIBLE, int valeur = 0, int code = PIECE);
        virtual ~Piece();

        void setCouleur(int c) { this->couleur = c; }
        int getCouleur(void) { return this->couleur; }

        void setEtat(int e) { this->etat = e; }
        int getEtat(void) { return this->etat; }

        int getValeur(void) { return this->valeur; }
        int getCode(void) { return this->code; }
        std::string getName(void) { return pieceToString(this->code); }

        virtual bool verifierDeplacement(Coordonnees, Coordonnees) = 0;
        virtual bool verifierDeplacement(std::string, std::string);

        virtual std::string toString(int, int, bool);
        virtual std::string toString(bool full = false) = 0;

    protected:
        int couleur;
        int etat;
        int valeur;
        int code;
};

#endif // PIECE_H
