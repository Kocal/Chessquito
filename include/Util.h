#ifndef UTIL_H
#define UTIL_H

#define COULEUR_BLANC 0
#define COULEUR_NOIR 1

#define ETAT_DISPONIBLE 0
#define ETAT_PLACE 1
#define ETAT_PRIS 2

#define NB_PIECES 4

#include <iostream>

using namespace std;

void clear(void);
void separation(void);
void coordonnees(string, int&, int&);
void separationPlateau(int);
string getStringByCouleur(int);
char getCharByCouleur(int);
#endif // UTIL_H
