#include <SDL/SDL.h>

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>
#include <vector>

#include "Partie.h"
#include "Joueur.h"

#include "Reine.h"
#include "Tour.h"
#include "Fou.h"
#include "Cavalier.h"
#include "Pion.h"
#include "Roi.h"

using std::cin;
using std::cout;
using std::endl;

// Lance une partie "Humain VS Humain"
bool nouvellePartieHumain(Partie* partie);

// Lance une partie "Humain VS Ordinateur" classique
bool nouvellePartieOrdinateur(Partie* partie, int *resultats[], int nbIterations);

// Lance une partie "Ordinateur VS Ordinateur" améliorée
bool nouvellePartieIA(Partie* partie, int *resultats[], int nbIterations);

// Affiche un récapitulatif de la partie à chaque début de tour. Utile uniquement pour les parties "Humain VS Humain".
void debutTour(Partie*, std::string msg);
/*
int main() {
    // Si le joueur veut continuer de jouer
    bool continuer = true;

    // Permet de jouer `nbIterations * nbParties` parties "Ordinateur vs Ordinateur"
    int nbIterations = 5;
    int nbParties = 100;

    // Contient le nombre de victoires de `n` joueurs pour `nbIterations * n` parties
    int **resultats;

    // Initialisation des joueurs et d'une partie
    Joueur* j1 = new Joueur();
    Joueur* j2 = new Joueur("Skyyart");
    Partie* partie = new Partie("23-04-2015");

    // Utile pour le placement aléatoire des pièces
    srand(time(NULL));

    // Ajout des joueurs à la partie
    partie->addJoueur(j1);
    partie->addJoueur(j2);

    // Initialisation des tableaux `Plateau::plateau` et `Plateau::pieces`
    partie->plateau->initPlateau();
    partie->plateau->initPieces();

    // Allocation et création du tableau `resultats[nbIterations][nbJoueurs]`
    resultats = new int*[nbIterations];
    for(int i = 0; i < nbIterations; i++) {
        resultats[i] = new int[partie->getNbJoueurs()];

        for(int j = 0; j < partie->getNbJoueurs(); j++) {
            resultats[i][j] = 0;
        }
    }

    // On commence à jouer ici
    for(int it = 0; it < nbIterations; it++) {
        cout << "---------------" << endl;
        cout << "Iteration n°" << it << endl;

        for(int nbp = 0; nbp < nbParties; nbp++) {
            // On ré-initialise quelques attribut de `Partie` et `Plateau` si on va commencer une deuxième partie
            partie->setNbTours(0);
            partie->setNbToursSansPrise(0);
            partie->plateau->resetPlateau();
            partie->plateau->resetPieces();

            // Partie "Humain vs Humain"
//            continuer = nouvellePartieHumain(partie);

            // Partie "Ordinateur vs Ordinateur" classique
//            continuer = nouvellePartieOrdinateur(partie, resultats, it);

            // Partie "Ordinateur vs Ordinateur" améliorée
//            continuer = nouvellePartieIA(partie, resultats, it);
            if(!continuer) { break; }
        }

        // On affiche les victoires de chaque joueurs
        for(int j = 0; j < partie->getNbJoueurs(); j++) {
            cout <<  "Victoires de " << partie->getJoueur(j)->getNom() << " : " << resultats[it][j] << " victoires" << endl;
        }

        if(!continuer) { break; }
    }

    // On n'a plus envie envie de jouer, on supprime le tableau de résultats, le plateau, la partie, et les joueurs
    for(int i = 0; i < nbIterations; i++) {
        delete[] resultats[i];
    }

    delete resultats;
    delete partie->plateau;
    delete partie;

    delete j1;
    delete j2;

    return 0;
}
*/

void debutTour(Partie* partie, std::string messagePerso) {
    system("clear");

    // Déplacements possibles
    std::map<Piece*, std::vector<Coordonnees> > __dep_poss = partie->plateau->deplPossiblesSTL(partie->getCurrentJoueurId());

    // Servira pour l'affichage des différentes pièces, ainsi que le choix des pièces
    int __n = 0;

    cout << "Tour n°" << partie->getNbTours() << endl;
    cout << "Tour sans prise n°" << partie->getNbToursSansPrise() << endl;
    cout << "Pièces disponibles : " << partie->plateau->getNbPiecesByEtat(DISPONIBLE) << " ; "
         << "pièces placées : " << partie->plateau->getNbPiecesByEtat(PLACE) << " ; "
         << "pièces prises : " << partie->plateau->getNbPiecesByEtat(PRIS)
         << endl;

    cout << partie->plateau << endl;

    // Parfois on veut afficher un message du genre "La piece ... a été prise"
    if(messagePerso.length() != 0) {
        cout << endl << messagePerso << endl;
    }

    cout << "C'est au joueur " << partie->getCurrentJoueur()->getNom() << " de jouer !" << endl;
    cout << "Pièces de " << partie->getCurrentJoueur()->getNom() << " : " << endl;

    // On liste les pièces du joueur courant
    for(std::map<Piece*, std::vector<Coordonnees> >::iterator i = __dep_poss.begin(); i != __dep_poss.end(); i++) {
            cout << " - " << __n++ << " : " << i->first->toString(true)
                 << " (" << etatToString(i->first->getEtat()) << ")";

            // Si la pièce est placée et donc que l'on a déjà ses déplacements disponibles
            if(i->second.size() != 0) {
                cout << " => ";
            }

            // On affiche les différentes déplacements possibles pour la pièce en cours
            for(std::vector<Coordonnees>::iterator j = i->second.begin(); j != i->second.end(); j++ ) {
                cout << j->str << " ";
            }

        cout << endl;
    }
}

bool nouvellePartieHumain(Partie* partie) {
    // Déplacements possible d'une pièce
    std::vector<Coordonnees> __dep_poss;

    // Permet de stocker temporairement une pièce
    Piece* __piece;
    Piece* __piece2;

    // Stock temporairement des coordonnées
    Coordonnees __coord;

    // Input utilisateur
    std::string __input;

    // Identifiant de la pièce à placer
    int __n = 0;
    // Contiendra un caractère 'o' ou 'n' pour continuer de jouer
    char __c;
    bool __retry = false;

    std::string messagePerso = "";

    // Initialisation des pièces pour la règle n°1
    partie->plateau->initPiecesRegle1();

    // Placement des pièces
    while(partie->plateau->getNbPiecesByEtat(DISPONIBLE) != 0) {
        // Incrémentation du nombre de tours et affichage du récapitulatif de la partie
        partie->increaseNbTours();
        debutTour(partie, messagePerso);
        messagePerso = "";

        // Le joueur doit choisir une pièce à déplacer
        do {
            cout << "Choississez un identifiant de pièce à placer : ";
            cin >> __input;

            // Conversion std::string en int
            __n = atoi(__input.c_str());

            // On récupère la pièce `__n` du joueur en cours
            __piece = partie->plateau->getPieceJoueur(__n);

            // Si aucune pièce n'a été sélectionnée, ou alors qu'elle a déjà été placée
        } while(__piece == NULL || (__piece != NULL && __piece->getEtat() != DISPONIBLE));


        // Le joueur doit entrer les coordonnées de la pièce sélectionnée précedemment
        do {
            cout << "Entrez les coordonnées de la pièce " << __piece->toString() << " : ";
            cin >> __input;

            // Conversion std::string en Coordonnees
            coordonnees(__input, __coord);

            // On vérifie que les coordonnées ne dépasse pas les dimensions du plateay
            // si les coordonnées sont bien comprises dans le plateau, alors on vérifie
            // qu'il y a bien une pièce aux coordonnées spécifées.
        } while(__coord.x < 0 || __coord.x > partie->plateau->getLargeur()
             || __coord.y < 0 || __coord.y > partie->plateau->getLongueur()
             || partie->plateau->getPieceFromPlateau(__coord.y, __coord.x) != NULL
        );

        // On place la pièce
        partie->plateau->addPiece(__piece, __coord);
        __piece->setEtat(PLACE);
    }

    // Les joueurs peuvent désormait jouer !
    while(!partie->isTerminee_regle1()) {

        // Incrémentation du nombre de tours et affichage du récapitulatif de la partie
        partie->increaseNbTours();
        debutTour(partie, messagePerso);
        messagePerso = "";

        // Le joueur doit choisir une pièce à déplacer
        do {
            cout << "Choississez un identifiant de pièce à déplacer : ";
            cin >> __input;

            // Conversion std::string en int
            __n = atoi(__input.c_str());

            // On récupère la pièce `__n` du joueur courant
            __piece = partie->plateau->getPieceJoueur(__n);

            // Si aucune pièce n'a été sélectionnée, ou alors qu'elle n'est pas placée
        } while(__piece == NULL || (__piece != NULL && __piece->getEtat() != PLACE));

        bool __coords_valid = false;

        // Le joueur doit entrer les nouvelles coordonnées de la pièce sélectionnée précedemment
        do {
            cout << "Entrez les nouvelles coordonnées de la pièce " << __piece->toString() << " : ";
            cin >> __input;

            // Conversion std::string en Coordonnees
            coordonnees(__input, __coord);

            // On récupère les déplacements possibles de la pièce `__piece`
            __dep_poss = partie->plateau->deplPossiblesSTL(__piece);

            // On cherche si les coordonnées se trouve dans les déplacements valides de la pièce
            for(std::vector<Coordonnees>::iterator it = __dep_poss.begin(); it != __dep_poss.end(); it++) {
                if(__coord.str == it->str) {
                    __coords_valid = true;
                }
            }

            // On vérifie que les coordonnées ne dépasse pas les dimensions du plateau
            // ou alors que le déplacement ou les coordonnées ne sont pas valide
        } while(__coord.x < 0 || __coord.x > partie->plateau->getLargeur()
             || __coord.y < 0 || __coord.y > partie->plateau->getLongueur()
             || !__piece->verifierDeplacement(partie->plateau->getCoords(__piece), __coord)
             || !__coords_valid
        );

        partie->increaseNbToursSansPrise();

        // On récupère la pièce qui se trouve aux coordonnées choisies par l'utilisateur
        __piece2 = partie->plateau->getPiece(__coord);

        // Si on a bien une pièce, et que la pièce a déplacer et la pièce pouvant être prise sont différentes, et que leur couleur aussi
        if(__piece2 != NULL && (__piece != __piece2 || __piece->getCouleur() != __piece2->getCouleur())) {
            messagePerso += "La pièce '" + __piece2->toString(true) + "' vient d'être prise !" + "\n";

            // On supprime la pièce prise du plateau (mais elle est toujours dans le tableau de pièces !)
            partie->plateau->removePieceFromPlateau(__piece2);
            __piece2->setEtat(PRIS);

            partie->setNbToursSansPrise(0);
        }

        // On bouge la pièce `__piece` aux coordonnées `__coord`
        partie->plateau->movePiece(__piece, __coord);
    }

    cout << "Le gagnant " << partie->getWinner()->getNom() << endl;

    // Si on veut rejouer ou non
    do {
        cout << "Voulez-vous rejouer ? (O/n) ";
        std::getline(cin, __input);

        // Conversion std::string en char
        __c = tolower(__input.c_str()[0]);
    } while(__c != '\0' &&__c != 'o' && __c != 'n');

    if(__c == 'o' || __c == '\0') {
        __retry = true;
    }

    return __retry;
}

bool nouvellePartieOrdinateur(Partie *partie, int *resultats[], int nbIterations) {
    std::string __input;
    char __c;
    bool __retry = false;

    partie->plateau->initPiecesRegle1();

    // Placement des pièces
    while(partie->plateau->getNbPiecesByEtat(DISPONIBLE) != 0) {
        partie->increaseNbTours();

        // On place un pièce aléatoire du joueur `partie->getCurrentJoueurId()`
        partie->plateau->placeAleatoireSTL(partie->getCurrentJoueurId());

        cout << partie->plateau << endl;
    }

    while(!partie->isTerminee_regle1()) {
        partie->increaseNbTours();
        partie->increaseNbToursSansPrise();

        // On déplace une pièce aléatoire du joueur `partie->getCurrentJoueurId()`
        partie->plateau->deplaceAleatoireSTL(partie->getCurrentJoueurId());

        cout << partie->plateau << endl;
    }

    cout << "Le gagnant est " << partie->getWinner()->getNom() << endl;

    // On incrémente le nombre de victoire du joueur `partie->getWinnerId()`
    resultats[nbIterations][partie->getWinnerId()]++;

    // On peut forcer ou non une nouvelle partie
//    return true;


    do {
        cout << "Voulez-vous rejouer ? (O/n) ";
        std::getline(cin, __input);
        __c = tolower(__input.c_str()[0]);
    } while(__c != '\0' &&__c != 'o' && __c != 'n');

    if(__c == 'o' || __c == '\0') {
        __retry = true;
    }

    return __retry;
}

bool nouvellePartieIA(Partie* partie, int *resultats[], int nbIterations) {
    std::string __input;
    char __c;
    bool __retry = false;

    partie->plateau->initPiecesRegle2();

    while(partie->plateau->getNbPiecesByEtat(DISPONIBLE) != 0) {
        partie->increaseNbTours();
        partie->plateau->placeSuiteSTL(partie->getCurrentJoueurId());
    }

    while(!partie->isTerminee_regle1()) {
        partie->increaseNbTours();
        partie->increaseNbToursSansPrise();

        // Monte-Carlo pour déterminer quelle pièce et où le joueur `partie->getCurrentJoueurId()` doit déplacer
        partie->plateau->monteCarlo(partie->getCurrentJoueurId());

        cout << "nbToursSansPrise : " << partie->getNbToursSansPrise() << endl;
        cout << partie->plateau << endl;
    }

    resultats[nbIterations][partie->getWinnerId()]++;

//    return false;

    do {
        cout << "Voulez-vous rejouer ? (O/n) ";
        std::getline(cin, __input);
        __c = tolower(__input.c_str()[0]);
    } while(__c != '\0' &&__c != 'o' && __c != 'n');

    if(__c == 'o' || __c == '\0') {
        __retry = true;
    }

    return __retry;
}

