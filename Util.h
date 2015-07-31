#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <string>

// Couleur
enum Couleur {
    BLANC, NOIR
};
std::string couleurToString(int couleur);

// Etat
enum Etat {
    DISPONIBLE, PLACE, PRIS
};

std::string etatToString(int etat);

// Coordonnees
typedef struct {
    int x;
    int y;
    std::string str;
} Coordonnees;

void coordonnees(std::string coordonneesString, Coordonnees &coordonneesStruct);
Coordonnees newCoords(int x, int y);

Coordonnees coordonneesMin(Coordonnees coordonnees1, Coordonnees coordonnees2);
Coordonnees coordonneesMax(Coordonnees coordonnees1, Coordonnees coordonnees2);

// Pièces
enum PIECE {
    PIECE, CAVALIER, FOU, PION, REINE, ROI, TOUR
};

std::string pieceToString(int p);

// Pièces entre deux coordonnées
enum Sens {
    HORIZONTAL, VERTICAL, DIAGONALE
};

int nbPiecesEntre(int ** plateauInt, std::string coordonnees1, std::string coordonnees2, Sens sens = HORIZONTAL);
int nbPiecesEntre(int ** plateauInt, Coordonnees coordonnees1, Coordonnees coordonnees2, Sens ens = HORIZONTAL);

// Tableau
std::string separationTableau(int largeur);
#endif // CONFIGURATION_H
