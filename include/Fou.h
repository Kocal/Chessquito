#ifndef FOU_H
#define FOU_H

#include "Piece.h"


class Fou : public Piece
{
    public:
        Fou();
        Fou(int);
        Fou(int, int);
        Fou(const Fou&);
        virtual ~Fou();

        bool verifierDeplacement(string, string);
        void affichage();
        string getCode(void);

    protected:
    private:
};

#endif // FOU_H
