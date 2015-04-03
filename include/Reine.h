#ifndef REINE_H
#define REINE_H

#include "Piece.h"

class Reine : public Piece
{
    public:
        Reine();
        Reine(int);
        Reine(int, int);
        Reine(const Reine&);
        virtual ~Reine();

        bool verifierDeplacement(string, string);
        void affichage();
        string getCode(void);

    protected:
    private:
};

#endif // REINE_H
