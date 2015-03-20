#ifndef TOUR_H
#define TOUR_H

#include "Piece.h"

class Tour : public Piece
{
    public:
        Tour();
        Tour(int);
        Tour(int, int);
        Tour(const Tour&);
        virtual ~Tour();

        bool verifierDeplacement(string, string);
        void affichage();
    protected:

    private:
};

#endif // TOUR_H
