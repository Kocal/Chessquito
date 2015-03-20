#include <iostream>
#include <cstdlib>

#include "Partie.h"
#include "Joueur.h"

#include "Piece.h"
#include "Tour.h"
#include "Fou.h"

using namespace std;

int main() {

    Partie* partie = new Partie("2015-03-30");
    Joueur* j1 = new Joueur("Alpha");
    Joueur* j2 = new Joueur("Beta");
    //Joueur* j3 = new Joueur("Gamma");

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

    cout << endl;

    Tour tour;
    tour.setCouleur(COULEUR_NOIR);
    cout << "Couleur de la nouvelle tour : " << tour.getCouleur() << endl;

    cout << endl;

    Tour tour_blanche(COULEUR_BLANC);

    cout << endl;

    Tour tour_noire(tour_blanche);
    cout << "Ancienne couleur : " << tour_noire.getCouleur() << endl;
    tour_noire.setCouleur(COULEUR_NOIR);
    cout << "Nouvelle couleur : " << tour_noire.getCouleur() << endl;

    cout << endl;
    Tour tour_foo(COULEUR_BLANC, ETAT_DISPONIBLE);
    cout << endl;


//    Tour* tour2 = new Tour();
//    Fou* fou2 = new Fou();

    cout << endl;


    if(j1) delete j1;
    if(j2) delete j2;
    if(partie) delete partie;

    return EXIT_SUCCESS;
}
