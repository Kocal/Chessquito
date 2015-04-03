#ifndef CAVALIER_H
#define CAVALIER_H

#include "Piece.h"

class Cavalier : public Piece
{
    public:
        Cavalier();
        Cavalier(int);
        Cavalier(int, int);
        Cavalier(const Cavalier&);
        virtual ~Cavalier();

        bool verifierDeplacement(string, string);
        void affichage();
        string getCode(void);

    protected:
    private:
};

#endif // CAVALIER_H
