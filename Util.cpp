#include "Util.h"
#include <string>
#include <iostream>
//#include "Plateau.h"

using std::cout;
using std::endl;

std::string couleurToString(int c) {
    switch(c) {
        case 0: return "Blanc";
        case 1: return "Noir";
        default: return "???";
    }
}


std::string etatToString(int e) {
    switch(e) {
        case 0: return "Disponible";
        case 1: return "Placé";
        case 2: return "Pris";
        default: return "???";
    }
}

void coordonnees(std::string s, Coordonnees &c) {
    c.x = s.at(0) - 'a';
    c.y = s.at(1) - '1';
    c.str = s;
}

Coordonnees newCoords(int x, int y) {
    Coordonnees c;
    c.x = x;
    c.y = y;

    c.str = (char) ('a' + x);
    c.str += (char) ('1' + y);

    return c;
}

Coordonnees coordonneesMin(Coordonnees co1, Coordonnees co2) {
    if(co1.y - co2.y < 0 || co1.x - co2.x < 0) {
        return co1;
    } else {
        return co2;
    }
}

Coordonnees coordonneesMax(Coordonnees co1, Coordonnees co2) {
    if(co1.str == coordonneesMin(co1, co2).str) {
        return co2;
    }  else {
        return co1;
    }
}

// NOMBRE PIECE ENTRE
int nbPiecesEntre(int **plateau, std::string c1, std::string c2, Sens s) {
    Coordonnees co1;
    Coordonnees co2;

    coordonnees(c1, co1);
    coordonnees(c2, co2);

    return nbPiecesEntre(plateau, co1, co2, s);
}

// Pièce
std::string pieceToString(int p) {
    switch(p) {
        case 0: return "Piece";
        case 1: return "Cavalier";
        case 2: return "Fou";
        case 3: return "Pion";
        case 4: return "Reine";
        case 5: return "Roi";
        case 6: return "Tour";
        default: return "???";
    }
}

int nbPiecesEntre(int **plateau, Coordonnees co1, Coordonnees co2, Sens s) {
    int n = 0;

    Coordonnees min = coordonneesMin(co1, co2);
    Coordonnees max = coordonneesMax(co1, co2);

    switch(s) {
        case HORIZONTAL: {
            // Si les coordonnées ne forment pas une ligne horizontale
            if(min.x != max.x) {
                return -1;
            }

            for(int i = min.y + 1; i < max.y; i++) {
                n += plateau[i][min.x];
            }

            break;
        }

        case VERTICAL: {
            // Si les coordonnées ne forment pas une ligne verticale
            if(min.y != max.y) {
                return -1;
            }

            for(int i = min.x + 1; i < max.x; i++) {
                n += plateau[min.y][i];
            }

            break;
        }

        case DIAGONALE: {
            // Si les coordonnées ne forment bien une diagonale
            if(std::abs(max.x - min.x) != std::abs(max.y - min.y)) {
                return -1;
            }

            for(int i = min.x + 1; i < max.x; i++) {
                n += plateau[i][i];
            }

            break;
        }

        default:
            n = -1;
    }

    return n;

}

std::string separationTableau(int taille) {
    std::string s;

    while(taille--) {
        s += "---------";
    }

    return s;
}
