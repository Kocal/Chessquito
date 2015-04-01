#include <iostream>
#include <cstdlib>

#include "Util.h"

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

    /*
    partie->initPlateau();
    int x, y;
    coordonnees("a1", x, y);

    cout << x << " - " << y << endl;

    coordonnees("c3", x, y);
    cout << x << " - " << y << endl;

    coordonnees("d4", x, y);
    cout << x << " - " << y << endl;

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

    Tour *tnoir = new Tour(COULEUR_NOIR);
    Tour *tblanc = new Tour(*tnoir);
    Fou *fnoir = new Fou(COULEUR_NOIR);

    tblanc->setCouleur(COULEUR_BLANC);

    partie->setPiece(tnoir, "a1");
    cout << "Tnoir : " << tnoir << " ; partie(0) : " << (*partie)(0) << endl;

    partie->setPiece(tblanc, "a2");
    cout << "Tblanc : " << tblanc << " ; partie(0, 1) : " << (*partie)(0, 1) << endl;

    partie->setPiece(fnoir, "b3");
    cout << "Fnoir : " << fnoir << " ; partie(\"b3\") : " << (*partie)("b3") << endl;

    separation();

    Partie partie2("2015-01-03");
    partie2.initPlateau();

    Tour tnoir2(COULEUR_NOIR);

    Tour tblanc2(tnoir2);
    tblanc2.setCouleur(COULEUR_BLANC);

    partie2.setJoueur(j1);
    partie2.setPiece(&tnoir2, "a2");
    partie2.setPiece(&tblanc2, "b4");
    cout << "tnoir2 : " << &tnoir2 << " ; partie2(\"a2\") : " << partie2("a2") << endl;
    cout << "tblanc2 : " << &tblanc2 << " ; partie2(\"b4\") : " << partie2("b4") << endl;

    cout << "Fnoir : " << (*partie)("b3") << endl;
    cout << "\tcouleur : " << (*partie)("b3")->getCouleur() << endl;

    separation();

    cout << "partie2(\"a3\") : " << partie2("a3") << endl;
    partie2.setPiece(&tblanc2, "a3");
    cout << "partie2(\"a3\") : " << partie2("a3") << endl;

    separation();
    */

    /*
    Tour *tb = new Tour(COULEUR_BLANC);
    Tour *tn = new Tour(COULEUR_NOIR);
    Fou *fb = new Fou(COULEUR_BLANC);
    Fou *fn = new Fou(COULEUR_NOIR);

    partie->setPiece(tb, "a0");
    partie->setPiece(tn, "d3");
    partie->setPiece(fb, "a3");
    partie->setPiece(fn, "d0");

    cout << *partie << endl;

    if(tb) delete tb;
    if(tn) delete tn;
    if(fb) delete fb;
    if(fn) delete fn;
    */



    if(j1) delete j1;
    if(j2) delete j2;
    if(partie) delete partie;

    return EXIT_SUCCESS;
}
