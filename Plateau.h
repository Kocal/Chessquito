#ifndef PLATEAU_H
#define PLATEAU_H

#include <ostream>
#include <vector>
#include <map>

#include "Util.h"
#include "Partie.h"
#include "Piece.h"
#include "Joueur.h"

class Partie;

class Plateau
{
    public:
        Plateau(Partie*, int largeur = 4, int longueur = 4);
        Plateau(Plateau* const&, Partie* const&);
        ~Plateau();

        int getLongueur(void) { return this->longueur; }
        int getLargeur(void) { return this->largeur; }

        void initPlateau(void);
        void resetPlateau(void);
        void initPieces(void);
        void resetPieces(void);

        Piece* clone(Piece*);

        void initPiecesRegle1(void);
        void initPiecesRegle2(void);
        void listPieces(void);

        Partie *partie;

        bool addPiece(Piece* piece, std::string coordonnees);
        bool addPiece(Piece* piece, Coordonnees coordonnees);

        Piece* getPiece(std::string coordonnees);
        Piece* getPiece(Coordonnees coordonnees);
        Piece* getPieceFromPlateau(int y, int x);
        int getNbPiecesByEtat(int etat);

        std::vector<Coordonnees> deplPossiblesSTL(Piece* piece);
        std::map<Piece*, std::vector<Coordonnees> > deplPossiblesSTL(int joueurID);
        bool placeAleatoireSTL(int joueurID);
        bool placeSuiteSTL(int joueurID);
        bool deplaceAleatoireSTL(int joueurID);
        bool monteCarlo(int joueurID);

        void movePiece(Piece* piece, Coordonnees coordonnes);
        void removePieceFromPlateau(Piece* piece);

        Coordonnees getCoords(Piece* piece);

        Piece* getPieceJoueur(int pieceID, int joueurID = -1);

        Piece* operator()(std::string coordonnees);
        Piece* operator()(Coordonnees coordonnees);

        int **getPlateau(void);

    private:
        int nbPieces;

        // Contient la liste des pièces
        Piece* *pieces;

        // Contient le véritable plateau de jeu
        Piece* **plateau;

        int largeur;
        int longueur;
};

std::ostream& operator<<(std::ostream& f, Plateau* p);

#endif // PLATEAU_H
