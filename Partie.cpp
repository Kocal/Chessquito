#include <iostream>
#include "Util.h"
#include "Partie.h"
#include "Plateau.h"
#include "Joueur.h"

using std::cout;
using std::endl;

Partie::Partie(std::string date, int nbJoueurs, int largeurPlateau, int longueurPlateau, int nbPiecesParJoueur)
    : date(date), nbJoueurs(nbJoueurs), nbPiecesParJoueur(nbPiecesParJoueur), nbTours(0), nbToursSansPrise(0)
{
    this->plateau = new Plateau(this, largeurPlateau, longueurPlateau);
    this->joueurs = new Joueur*[nbJoueurs];
}

// Constructeur par copie
Partie::Partie(Partie* const &p)
    : date(p->date), nbJoueurs(p->nbJoueurs), nbPiecesParJoueur(p->nbPiecesParJoueur), nbTours(p->nbTours), nbToursSansPrise(p->nbToursSansPrise) {

    // Joueurs
    this->joueurs = new Joueur*[p->nbJoueurs];

    for(int i = 0; i < p->nbJoueurs; i++) {
        this->joueurs[i] = p->joueurs[i];
    }

    // On crée un nouveau plateau à partir de `Partie::plateau`
    this->plateau = new Plateau(p->plateau, this);
}

// Ajout un joueur `j` à un tableau dynamique de joueurs
void Partie::addJoueur(Joueur *j) {
    int i;
    bool ajoute = false;

    Joueur** tmp = new Joueur*[this->nbJoueurs + 1];

    for(i = 0; i < this->nbJoueurs; i++) {
        if(this->joueurs[i] == NULL && !ajoute) {
            j->setPartie(this);
            tmp[i] = j;
        }

        tmp[i] = this->joueurs[i];
    }

    if(!ajoute) {
        j->setPartie(this);
        tmp[i] = j;
    }

    this->nbJoueurs++;
    delete[] this->joueurs;
    this->joueurs = tmp;

    this->organizePlayersArray();
}

// Fais le tri entre des pointeurs de joueur et des NULL.
// Créer un nouveau tableau de joueurs de taille `nbJoueurs - nombre de NULL`
void Partie::organizePlayersArray() {
    int nbPlayers = 0;
    int j = 0;

    for(int i = 0; i < this->nbJoueurs; i++) {
        if(this->joueurs[i] != NULL) {
            nbPlayers++;
        }
    }

    Joueur** tmp = new Joueur*[nbPlayers];

    for(int i = 0; i < this->nbJoueurs; i++) {
        if(this->joueurs[i] != NULL) {
            tmp[j++] = this->joueurs[i];
        }
    }

    delete[] this->joueurs;
    this->joueurs = tmp;
    this->nbJoueurs = j;
}

// Liste les différents joueurs
void Partie::listJoueurs(void) {
    for(int i = 0; i < this->nbJoueurs; i++) {
        std::cout << "Joueur " << i << " : " << this->joueurs[i]->getNom() << std::endl;
    }
}

bool Partie::isJouable(void) {
    return this->nbJoueurs > 1;
}

Joueur* Partie::getJoueur(int joueurID) {
    if(this->joueurs[joueurID]) {
        return this->joueurs[joueurID];
    }

    return NULL;
}

bool Partie::isTerminee_regle1() {
    // Stocke temporairement une pièce
    Piece* __p;

    // Nombre de pièce
    int __n = 0;

    // On liste les pièces placées de chaque joueurs, et on renvoit directement `true` si un joueur n'a plus de pièce.
    for(int i = 0; i < this->nbJoueurs; i++) {
        for(int j = 0; j < this->nbPiecesParJoueur; j++) {
            __p = this->plateau->getPieceJoueur(j, i);

            if(__p && __p->getEtat() == PLACE) {
                __n++;
            }
        }

        if(__n == 0) {
            return true;
        }

        __n = 0;
    }

    return this->plateau->getNbPiecesByEtat(PLACE) == 1 || this->nbToursSansPrise >= 5;
}

// Retourne un entier qui est l'id du joueur courant.
int Partie::getCurrentJoueurId() {
    return this->nbTours % this->nbJoueurs;
}

// Retourne le joueur courant
Joueur* Partie::getCurrentJoueur() {
    return this->joueurs[this->getCurrentJoueurId()];
}

// Retourne l'identifiant du gagnant
int Partie::getWinnerId(void) {
    int winnerId = 0;
    Piece* __p;

    // Total des valeurs des pièces d'un joueur
    int __n = 0;
    // Total max des valeurs des pièces d'un joueur
    int __max = 0;

    for(int i = 0; i < this->nbJoueurs; i++) {
        for(int j = 0; j < this->nbPiecesParJoueur; j++) {
            __p = this->plateau->getPieceJoueur(j, i);
            if(__p && __p->getEtat() == PLACE) {
                __n += __p->getValeur();
            }
        }
        if(__n > __max) {
            __max = __n;
            winnerId = i;
        }

     __n = 0;
    }

    return winnerId;
}

// Retourne le gagnant
Joueur* Partie::getWinner(void) {
    return this->joueurs[this->getWinnerId()];
}

// Est déclenchée quand un joueur quitte la partie.
void Partie::quitte(Joueur *j) {
    j->setPartie(NULL);

    for(int i = 0; i < this->nbJoueurs; i++) {
        if(this->joueurs[i] == j) {
            this->joueurs[i] = NULL;
        }
    }

    this->organizePlayersArray();
}

Partie::~Partie() {
    for(int i = 0; i < this->nbJoueurs; i++) {
        if(this->joueurs[i]) {
            this->joueurs[i]->setPartie(NULL);
        }
    }
}
