#include <iostream>
#include <cstdlib>

#include "Util.h"

#include "Partie.h"
#include "Joueur.h"

#include "Piece.h"
#include "Tour.h"
#include "Fou.h"

using namespace std;

const int taille = 4;
typedef Piece* Plateau[taille][taille];

void initPlateau(Plateau);

int main() {
    Plateau plateau;

    Partie* partie = new Partie("2015-03-30");

    Joueur* j1 = new Joueur("Alpha");
    Joueur* j2 = new Joueur("Beta");

    partie->setJoueur(j1);
    partie->setJoueur(j2);

    /*
    delete j1;

    cout << "Partie de j2 : " << j2->getPartie() << endl;

    if(!partie->estJouable()) {
        cout << "La partie n'est plus jouable" << endl;

        delete partie;
        partie = NULL;

        cout << "Partie de j2 : " << j2->getPartie() << endl;
    }
    */

    /*
    separation();

    cout << "INITIALISATION DES TOURS" << endl;

    Tour tour;
    tour.setCouleur(COULEUR_NOIR);
    cout << "Couleur de la nouvelle tour : " << tour.getCouleur() << endl;

    separation();

    Tour tour_blanche(COULEUR_BLANC);

    separation();

    Tour tour_noire(tour_blanche);
    cout << "Ancienne couleur : " << tour_noire.getCouleur() << endl;
    tour_noire.setCouleur(COULEUR_NOIR);
    cout << "Nouvelle couleur : " << tour_noire.getCouleur() << endl;

    separation();

    Tour tour_foo(COULEUR_BLANC, ETAT_DISPONIBLE);

    separation();

    cout << "INITIALISATION DES FOUS" << endl;

    Fou fou;
    fou.setCouleur(COULEUR_NOIR);
    cout << "Couleur du nouveau Fou : " << fou.getCouleur() << endl;

    separation();

    Fou fou_blanc(COULEUR_BLANC);

    separation();

    Fou fou_noir(fou_blanc);
    cout << "Ancienne couleur : " << fou_noir.getCouleur() << endl;
    fou_noir.setCouleur(COULEUR_NOIR);
    cout << "Nouvelle couleur : " << fou_noir.getCouleur() << endl;

    separation();

    Fou fou_foo(COULEUR_BLANC, ETAT_DISPONIBLE);

    separation();
    */

    initPlateau(plateau);

    /*
    int *coor = coordonnees("a1");
    cout << coor[0] << " - " << coor[1] << endl;

    coor = coordonnees("c3");
    cout << coor[0] << " - " << coor[1] << endl;

    coor = coordonnees("d4");
    cout << coor[0] << " - " << coor[1] << endl;
    */

    separation();

    Tour tour(COULEUR_BLANC);
    tour.affichage();
    cout << "(a1;a4 : " << tour.verifierDeplacement("a1", "a4") << endl;
    cout << "(b1;a4) : " << tour.verifierDeplacement("b1", "a4") << endl;
    cout << "(c3;a4) : " << tour.verifierDeplacement("c3", "a4") << endl;


    separation();

    Fou fou(COULEUR_NOIR);
    fou.affichage();
    cout << "(a1;c3) : " << fou.verifierDeplacement("a1", "c3") << endl;
    cout << "(d4;c3) : " << fou.verifierDeplacement("d4", "c3") << endl;
    cout << "(c3;d4) : " << fou.verifierDeplacement("c3", "d4") << endl;
    cout << "(c1;c3) : " << fou.verifierDeplacement("c1", "c3") << endl;

    separation();

    if(j1) delete j1;
    if(j2) delete j2;
    if(partie) delete partie;

    return EXIT_SUCCESS;
}

void initPlateau(Plateau p) {
    for(int i = 0; i < taille; i++) {
        for(int j = 0; j < taille; j++) {
            p[i][j] = NULL;
        }
    }
}
