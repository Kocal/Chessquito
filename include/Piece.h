#ifndef PIECE_H
#define PIECE_H

#include <iostream>

#define COULEUR_BLANC 0
#define COULEUR_NOIR 1


#define ETAT_DISPONIBLE 0
#define ETAT_PLACE 1
#define ETAT_PRIS 2

using namespace std;

class Piece
{
    public:
        Piece();
        Piece(int);
        Piece(int, int);
        Piece(const Piece&);
        virtual ~Piece();

        void setCouleur(int);
        int getCouleur(void);

        void setEtat(int);
        int getEtat(void);

        void affichage(string, int);

    protected:
        int couleur;
        int etat;

    private:
};

#endif // PIECE_H
