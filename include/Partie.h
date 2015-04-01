#ifndef PARTIE_H
#define PARTIE_H

#include <iostream>
#include <string>
#include "Joueur.h"
#include "Piece.h"

using namespace std;

const int plateauTaille = 4;
typedef Piece* Plateau[plateauTaille][plateauTaille];

class Joueur;

class Partie
{
    public:
        Partie();
        Partie(string);
        virtual ~Partie();

        void setDate(string);
        string getDate(void);

        bool setJoueur(Joueur*);
        void quittePartie(Joueur*);
        bool estJouable(void);

        void initPlateau(void);

        bool canPieceBePlaced(string);
        bool setPiece(Piece*, string);
        Piece* getPiece(int, int) const;

        Piece* operator()(int);
        Piece* operator()(int, int);
        Piece* operator()(string);

        const Piece* operator()(int) const;
        const Piece* operator()(int, int) const;
        const Piece* operator()(string) const;

    private:
        string date;
        int nbJoueurs;
        int nbJoueursMax;

        Plateau plateau;

        Joueur* j1;
        Joueur* j2;

};

ostream& operator<<(ostream& o, const Partie &);

#endif // PARTIE_H
