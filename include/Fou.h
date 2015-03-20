#ifndef FOU_H
#define FOU_H

#include "Piece.h"


class Fou : public Piece
{
    public:
        Fou();
        Fou(int);
        Fou (const Fou&);
        virtual ~Fou();
    protected:
    private:
};

#endif // FOU_H
