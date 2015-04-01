#ifndef PIECE_H
#define PIECE_H

#include <iostream>

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

        virtual string getCode(void) = 0;
        string getCode(char, int);

        virtual bool verifierDeplacement(string, string) = 0;


        //virtual Piece* operator=(Piece* const&);

    protected:
        int couleur;
        int etat;

    private:
};

#endif // PIECE_H
