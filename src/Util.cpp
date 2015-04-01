#include "Util.h"

void coordonnees(string n, int &x, int &y) {
    x = n[0] - 'a'; // a => 0, b => 1 ...
    y = n[1] - '0'; // 1 => 0, 2 => 1 ...
}

void separation(void) {
    cout << "----------------------------" << endl;
}

void separationPlateau(int taille) {
    for(int j = 0; j < taille; j++) {
        cout << "------";
    }

    cout << '-' << endl;
}

char getCharByCouleur(int couleur) {
    switch(couleur) {
    case COULEUR_BLANC:
        return 'b';

    case COULEUR_NOIR:
        return 'n';

    default:
        return 'x';
    }
}

string getStringByCouleur(int couleur) {
    switch(couleur) {
    case COULEUR_BLANC:
        return "blanc";

    case COULEUR_NOIR:
        return "noir";

    default:
        return "rien";
    }
}
