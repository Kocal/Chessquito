#include <iostream>
#include <cstdlib>
#include <climits>
#include <cmath>

#include "Util.h"

#include "Partie.h"
#include "Joueur.h"

#include "Piece.h"
#include "Reine.h"
#include "Tour.h"
#include "Fou.h"
#include "Cavalier.h"

using namespace std;

Partie* nouvellePartie(string date, Joueur* j1, Joueur *j2);

int main() {
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


    Joueur *j1 = new Joueur("Alpha");
    Joueur *j2 = new Joueur("Beta");

    Partie* partie = nouvellePartie("2015-04-01", j1, j2);

    if(partie) delete partie;
    if(j1) delete j1;
    if(j2) delete j2;

    return EXIT_SUCCESS;
}

Partie* nouvellePartie(string date, Joueur* j1, Joueur *j2) {
    Partie* partie = new Partie(date);

    // Les 4 premières pièces sont pour le joueur blanc, les 4 dernières pièces pour le joueur noir
    Piece* pieces[NB_PIECES * 2] = {new Reine(), new Tour(), new Fou(), new Cavalier(),
                        new Reine(COULEUR_NOIR), new Tour(COULEUR_NOIR), new Fou(COULEUR_NOIR), new Cavalier(COULEUR_NOIR)};

    // C'est pour savoir quelles pièces sont déjà placées
    bool piecesPlacees[NB_PIECES * 2] = {false, false, false, false,
                             false, false, false, false};

    // Fait le lien avec le joueur qui va placer une pièce, et une pièce
    // grâce à la formule : joueurNum * NB_PIECES + i / 2
    // où i va de 0 à NB_PIECES * 2
    int joueurNum = 0;
    Joueur* joueur = NULL;

    // Contient le résultat de la formule précédente
    int pieceIndex = 0;
    Piece* pieceEnCours = NULL;


    int inIdPiece = 0;

    // Coordonnées de la pièce qui sera placée
    string co;
    int x = -1, y = -1;

    partie->setJoueur(j1);
    partie->setJoueur(j2);

    separation();
    cout << "Une nouvelle partie va débuter..." << endl << endl;
    separation();

    // Les joueurs vont poser leurs pions
    for(int i = 0; i < NB_PIECES * 2; i++) {
        if(i % 2 == 0) {
            joueurNum = 0;
            joueur = j1;
        } else {
            joueurNum = 1;
            joueur = j2;
        }

        clear();

        cout << "C'est au joueur " << joueur->getNom() << " de placer une pièce." << endl;
        cout << "Aperçu du plateau : " << endl << *partie << endl;
        cout << "Etats des pièces du joueur " << joueur->getNom() << " : " << endl;

        // On liste les pièces du joueur j, et l'états de ces dernières
        for(int j = 0; j < NB_PIECES; j++) {
            pieceIndex = joueurNum * NB_PIECES + j;
            cout << "- " << j << " : " << pieces[pieceIndex]->getCode() << "(" << (piecesPlacees[pieceIndex] ? "placée" : "non placée") << ") " << endl;
        }

        // On demande au joueur de rentrer l'id de la pièce à placer
        do {
            cout << "Rentrez un identifiant de pièce à placer : "; cin >> inIdPiece;
            pieceIndex = inIdPiece + joueurNum * NB_PIECES;
        } while(inIdPiece < 0 || inIdPiece >= NB_PIECES || piecesPlacees[pieceIndex]);

        // On demande au joueur de rentrer les coordonnées de la pièce précédemment sélectionnée
        pieceEnCours = pieces[pieceIndex];
        do {
            cout << "Rentrez les coordonnées de la pièce " << pieceEnCours->getCode() << " : ";
            cin >> co;
            coordonnees(co, x, y);
        } while(x < 0 || y < 0 || x > NB_PIECES || y > NB_PIECES || partie->getPiece(x, y) != NULL);

        partie->setPiece(pieceEnCours, co);
        piecesPlacees[pieceIndex] = true;
    }

    separation();

    cout << "Toutes les pièces ont été placées" << endl;

    separation();
    cout << "C'est la fin de la partie " << partie << endl;
    separation();

    for(int i = 0; i < 8; i++) {
        cout << "Suppression de la pièce " << pieces[i]->getCode() << endl;

        if(pieces[i]) delete pieces[i];
    }

    separation();

    return partie;
}
