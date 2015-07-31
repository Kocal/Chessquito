#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>

#include "Util.h"
#include "Plateau.h"
#include "Reine.h"
#include "Tour.h"
#include "Fou.h"
#include "Cavalier.h"
#include "Pion.h"
#include "Roi.h"

using std::cout;
using std::endl;

Plateau::Plateau(Partie* p, int largeur, int longueur)
    : partie(p), nbPieces(0), largeur(largeur), longueur(longueur)
{
    // Initialisation des tableaux de pièces et plateau
    this->initPlateau();
    this->initPieces();
}

Plateau::Plateau(Plateau* const &p, Partie* const &partie)
    : partie(partie), nbPieces(p->nbPieces), largeur(p->largeur), longueur(p->longueur) {

    // Initialisation des tableaux de pièces et plateau
    this->initPlateau();
    this->initPieces();

    // Piece
    for(int i = 0; i < p->nbPieces; i++) {
        // Clonage de la pièce
        this->pieces[i] = this->clone(p->pieces[i]);

        // On ajoute la pièce clonée aux coordonnées de la pièce d'origine
        this->addPiece(this->pieces[i], p->getCoords(p->pieces[i]));
    }
}

Piece* Plateau::clone(Piece* p) {
    if(!p) { return NULL; }

    Piece* _p = NULL;

    // Code de la pièce, afin de différencier chaque pièce
    int _c = p->getCode();

    // Le meilleur switch de l'univers pour instancier un nouvel objet........
    // $p = new $_c(); => Vive PHP !
    switch(_c) {
        case CAVALIER:
            _p = new Cavalier();
            break;
        case FOU:
            _p = new Fou();
            break;
        case PION:
            _p = new Pion();
            break;
        case REINE:
            _p = new Reine();
            break;
        case ROI:
            _p = new Roi();
            break;
        case TOUR:
            _p = new Tour();
    }

    // Si on a bien une pièce, alors on lui affecte sa couleur et son état
    if(_p) {
        _p->setCouleur(p->getCouleur());
        _p->setEtat(p->getEtat());
    }

    return _p;
}

// Initialisation d'un plateau de taille `largeur * longueur`
void Plateau::initPlateau() {
    this->plateau = new Piece**[largeur];

    for(int i = 0; i < largeur ; i++) {
        this->plateau[i] = new Piece*[longueur];

        for(int j = 0; j < longueur; j++) {
            this->plateau[i][j] = NULL;
        }
    }
}

// Remet toutes les cases du plateau à NULL (quand on crée une nouvelle partie par exemple)
void Plateau::resetPlateau(void) {
    for(int i = 0; i < this->longueur; i++) {
        for(int j = 0; j < this->largeur; j++) {
            if(this->plateau[i][j]) {
                this->plateau[i][j] = NULL;
            }
        }
    }
}

// Initialisation du tableau de pièces
void Plateau::initPieces() {
    this->nbPieces = this->partie->getNbJoueurs() * this->partie->getNbPiecesParJoueur();
    this->pieces = new Piece*[this->nbPieces];
    this->resetPieces();
}

void Plateau::resetPieces(void) {
    for(int i = 0; i < this->nbPieces; i++) {
        this->pieces[i] = NULL;
    }
}

// Initialise les pièces pour la règle 1
void Plateau::initPiecesRegle1(void) {
    // Reine - Tour - Fou - Cavalier
    int j = 0;
    int n = this->partie->getNbPiecesParJoueur();

    for(int i = 0; i < this->partie->getNbJoueurs(); i++) {
        j = 0;
        this->pieces[i * n + j++] = new Reine(i);
        this->pieces[i * n + j++] = new Tour(i);
        this->pieces[i * n + j++] = new Fou(i);
        this->pieces[i * n + j++] = new Cavalier(i);
    }
}

// Initialise les pièces pour la règle 2
void Plateau::initPiecesRegle2(void) {
    // Pion - Cavalier - Fou - Tour
    int j = 0;
    int n = this->partie->getNbPiecesParJoueur();

    for(int i = 0; i < this->partie->getNbJoueurs(); i++) {
        j = 0;
        this->pieces[i * n + j++] = new Pion(i);
        this->pieces[i * n + j++] = new Cavalier(i);
        this->pieces[i * n + j++] = new Fou(i);
        this->pieces[i * n + j++] = new Tour(i);
    }
}

// Liste les pièces du tableau de pièces
void Plateau::listPieces() {
    for(int i = 0; i < this->nbPieces; i++) {
        cout << "Pièce " << i << " : ";

        if(this->pieces[i]) {
            cout << this->pieces[i] << " - " << this->pieces[i]->toString() << " - " << etatToString(this->pieces[i]->getEtat()) << " - " << this->getCoords(this->pieces[i]).str;
        } else {
            cout << "NULL";
        }

        cout << endl;
    }
}

// Polymorphisme.
// Ajoute une pièce aux coordonnées `c`
bool Plateau::addPiece(Piece* p, std::string c) {
    Coordonnees co;
    coordonnees(c, co);
    return this->addPiece(p, co);
}

// Ajoute une pièce aux coordonnées `co`
bool Plateau::addPiece(Piece* p, Coordonnees co)  {
    // On vérifie s'il y a déjà une pièce aux coordonnées
    if(this->getPieceFromPlateau(co.y, co.x) != NULL) {
        return false;
    }

    this->plateau[co.y][co.x] = p;
    return true;
}

// Créer un tableau `plateau` alternatif, où :
// - 0 => Pas de pièce
// - 1 => Pièce
// Cette méthode est utilisée pour la fonction `nbPiecesEntre`
int** Plateau::getPlateau() {
    int ** p = new int*[this->longueur];

    for(int i = 0; i < this->longueur; i++) {
        p[i] = new int[this->largeur];

        for(int j = 0; j < this->largeur; j++) {
            p[i][j] = (this->plateau[i][j] != NULL ? 1 : 0);
        }
    }

    return p;
}

// Retourne la pièce aux coordonnées c, ou NULL
Piece* Plateau::getPiece(std::string c) {
    Coordonnees co;
    coordonnees(c, co);

    return this->getPiece(co);
}

// Retourne la pièce aux coordonnées co, ou NULL
Piece* Plateau::getPiece(Coordonnees co) {
    return this->getPieceFromPlateau(co.y, co.x);
}

// Retourne la pièce du plateau aux coordonnées, ou NULL
Piece* Plateau::getPieceFromPlateau(int a, int b) {
    if(a < 0 || a >= largeur || b < 0 || b >= largeur) {
        return NULL;
    }

    return this->plateau[a][b];
}

// Retourne le nombre de pièces étant dans l'état `etat`
int Plateau::getNbPiecesByEtat(int etat) {
    int n = 0;
    for(int i = 0; i < this->nbPieces; i++) {
        if(this->pieces[i] != NULL && this->pieces[i]->getEtat() == etat) {
            n++;
        }
    }

    return n;
}

// Retourne les coordonnées d'une pièce
Coordonnees Plateau::getCoords(Piece* p) {
    Coordonnees c;

    for(int i = 0; i < this->longueur; i++) {
        for(int j = 0; j < this->largeur; j++) {
            if(this->plateau[i][j] == p) {
                c = newCoords(j, i);
                return c;
            }
        }
    }

    return c;
}

// Supprime une pièce du plateau
void Plateau::removePieceFromPlateau(Piece* p) {
    Coordonnees co = this->getCoords(p);

    for(int i = 0; i < this->longueur; i++) {
        for(int j = 0; j < this->largeur; j++) {
            if(co.x == j && co.y == i) {
                this->plateau[i][j] = NULL;
            }
        }
    }
}

// Déplace une pièce `p` aux coordonnées `nouvelleCoords`
void Plateau::movePiece(Piece* p, Coordonnees nouvelleCoords) {
    Coordonnees ancienneCoord = this->getCoords(p);

    for(int i = 0; i < this->longueur; i++) {
        for(int j = 0; j < this->largeur; j++) {
            if(ancienneCoord.x == j && ancienneCoord.y == i) {
                this->plateau[i][j] = NULL;
                this->plateau[nouvelleCoords.y][nouvelleCoords.x] = p;
            }
        }
    }
}

Piece* Plateau::operator()(std::string c) {
    return this->getPiece(c);
}

Piece* Plateau::operator()(Coordonnees co) {
    return this->getPiece(co);
}

// Affichage du plateau avec `std::cout`
std::ostream& operator<<(std::ostream& f, Plateau* p) {
    int largeur = p->getLargeur();
    int longueur = p->getLongueur();

    f << separationTableau(largeur) << endl;

    for(int i = longueur + 1; i--;) {
        if(i == longueur) {
            for(int j = 0; j < longueur; j++) {
                f << "|   " << j + 1 << "   ";
            }

            f << '|' << endl;
            continue;
        }

        f << separationTableau(largeur) << endl;

        for(int j = 0; j < largeur; j++) {
            if(p->getPieceFromPlateau(j, i)) {
                f << "| " << p->getPieceFromPlateau(j, i)->toString() << "  ";
            } else {
                f << "|       ";
            }
        }

        f << "| " << (char)('a' + i) << endl;

    }

    f << separationTableau(largeur) << endl;

    return f;
}

// Retourne la pièce `index` du joueur courant (`joueur` == -1), ou du joueur `joueur`
Piece* Plateau::getPieceJoueur(int index, int joueur) {
    // Joueur courant
    if(joueur == -1) {
        joueur = this->partie->getNbTours() % this->partie->getNbJoueurs();
    }

    int n = index + this->partie->getNbPiecesParJoueur() * joueur;

    if(n < 0 || n > this->nbPieces) {
        return NULL;
    }

    return this->pieces[n];
}

std::vector<Coordonnees> Plateau::deplPossiblesSTL(Piece* p) {
    // Code de la pièce
    int __n = p->getCode();

    // Contiendra plusieurs conditions pour différents tests
    bool __c = true;

    // Les déplacements possibles de la pièce `p`
    std::vector <Coordonnees> v;

    // Coordonnées de la pièce
    Coordonnees c1 = this->getCoords(p);
    Coordonnees c2;

    if(p == NULL || c1.str == "") {
        return v;
    }

    for(int i = 0; i < this->longueur; i++) {
        for(int j = 0; j < this->largeur; j++) {
            c2 = newCoords(j, i);

            // Si on a les mêmes coordonnées, on fait rien
            if(c1.str == c2.str) {
                continue;
            }

            if(__n == REINE || __n == ROI) {
                __c = nbPiecesEntre(this->getPlateau(), c1, c2, DIAGONALE) == 0
                    || nbPiecesEntre(this->getPlateau(), c1, c2, HORIZONTAL) == 0
                    || nbPiecesEntre(this->getPlateau(), c1, c2, VERTICAL) == 0;
            }

            if(__n == TOUR) {
                __c = nbPiecesEntre(this->getPlateau(), c1, c2, HORIZONTAL) == 0
                    || nbPiecesEntre(this->getPlateau(), c1, c2, VERTICAL) == 0;
            }

            if(__n == FOU) {
                __c = nbPiecesEntre(this->getPlateau(), c1, c2, DIAGONALE) == 0;
            }

            if(__n == PION) {
                // Le pion peut se déplacer verticalement s'il n'y a pas de pièce qui le bloque,
                // car il ne peut pas prendre de pièce en se déplacement verticalement
                __c = nbPiecesEntre(this->getPlateau(), c1, c2, VERTICAL) == 0 && this->getPiece(c2) == NULL;

                // Le pion peut se déplacer en diagonale, peut importe qu'il y ai une pièce ou non.
                // En revanche, s'il y a une pièce, on doit vérifier sa couleur afin de prendre la pièce
                __c = __c || (nbPiecesEntre(this->getPlateau(), c1, c2, DIAGONALE) == 0 && (
                                this->getPiece(c2) == NULL || (
                                    this->getPiece(c2) != NULL && this->getPiece(c2)->getCouleur() != p->getCouleur()
                                )
                            ));
            }

            // Si `p` peut se déplacer de `c1` à `c2`, et que `__c` vaut bien true
            if(p->verifierDeplacement(c1, c2) && __c) {
                v.push_back(c2);
            }
        }
    }

    return v;
}

// Retourne les déplacements possibles de toutes les pièces du joueur `joueurID`
std::map<Piece*, std::vector<Coordonnees> > Plateau::deplPossiblesSTL(int joueurID) {
    std::map<Piece*, std::vector<Coordonnees> >m;

    for(int i = 0; i < this->partie->getNbPiecesParJoueur(); i++) {
        m[this->getPieceJoueur(i, joueurID)] = this->deplPossiblesSTL(this->getPieceJoueur(i, joueurID));
    }

    return m;
}

// Place aléatoirement une pièce du joueur `joueurID`, ou du joueur courant `joueurID == -1`
bool Plateau::placeAleatoireSTL(int joueurID = -1) {
    int idPiece = -1;
    Piece* __p = NULL;
    Coordonnees __c;

    if(this->getNbPiecesByEtat(DISPONIBLE) == 0) {
        return false;
    }

    do {
        idPiece = rand() % this->partie->getNbPiecesParJoueur();
        __p = this->getPieceJoueur(idPiece, joueurID);
    } while(__p->getEtat() != DISPONIBLE);

    do {
        __c = newCoords(rand() % this->largeur, rand() % this->longueur);
    } while (this->getPiece(__c) != NULL);

    __p->setEtat(PLACE);
    return this->addPiece(__p, __c);
}

bool Plateau::deplaceAleatoireSTL(int joueurID = -1) {
    std::vector<Coordonnees> __dep_poss;
    Coordonnees __coord;

    Piece* __p1 = NULL;
    Piece* __p2 = NULL;

    int idPiece = -1;

    // On cherche une pièce placée à déplacer
    do {
        // On pioche un identifiant de pièce aléatoire
        idPiece = rand() % this->partie->getNbPiecesParJoueur();

        // On récupère la pièce correspondant à l'identifiant
        __p1 = this->getPieceJoueur(idPiece, joueurID);

        // Tant que l'état de la pièce est différent de `PLACE`
    } while(__p1->getEtat() != PLACE);

    // On cherche les déplacements possibles de la pièce
    __dep_poss = this->deplPossiblesSTL(__p1);

    // Si on a pas de déplacements possibles, on quitte directement la fonction
    if(__dep_poss.size() == 0) {
        return false;
    }

    // On récupère aléatoirement un déplacement possible
    __coord = __dep_poss.at(rand() % __dep_poss.size());
    // On récupère la pièce qui se trouve aux coordonnées `__coord`
    __p2 = this->getPiece(__coord);

    // Si on a bien trouvé une pièce, et que cette pièce est différente de la pièce à déplacer,
    // et que leur couleur sont aussi différentes
    if(__p2 != NULL && (__p1 != __p2 || __p1->getCouleur() != __p2->getCouleur())) {
        // La pièce "trouvée" est maintenant prise
        __p2->setEtat(PRIS);

        // et on l'enlève du plateau
        this->removePieceFromPlateau(__p2);

        this->partie->setNbToursSansPrise(0);
    }

    // On bouge la pièce `__p1` aux coordonnées `__coord`
    this->movePiece(__p1, __coord);
    return true;
}

// Place les pièces à la suite
bool Plateau::placeSuiteSTL(int joueurID) {
    Piece* __p = NULL;
    Coordonnees __c;

    // On quitte directement la fonction s'il y a 0 pièces disponibles
    if(this->getNbPiecesByEtat(DISPONIBLE) == 0) {
        return false;
    }

    __p = this->getPieceJoueur(
                // L'ordre des pièces se fait dans la méthode `Plateau::initPiecesRegle2`
                (this->partie->getNbTours() - 1) / this->partie->getNbJoueurs()
    , joueurID);

    do {
        // On choisi aléatoirement les nouvelles coordonnées de la pièce `__p`
        __c = newCoords(rand() % this->largeur, rand() % this->longueur);

        // S'il y a déjà une pièce sur ces coordonnées, alors on boucle
    } while(this->getPiece(__c) != NULL);

    // On place ensuite la pièce
    __p->setEtat(PLACE);
    return this->addPiece(__p, __c);
}

bool Plateau::monteCarlo(int joueurID) {

    // Statistiques de victoires/défaites/ratio pour chaque déplacements possibles de chaque pièces du joueur `joueurID`, sous la forme :
    // stats[Piece*][Coordonnees][std::string] = float
    //
    // Exemple :
    // stats[0xDEADBEEF]["a1"]["victoires"] = 4;
    // stats[0xDEADBEEF]["a1"]["defaites"] = 4;
    // stats[0xDEADBEEF]["a1"]["ratio"] = 0.5;
    std::map<Piece*, std::map<std::string, std::map<std::string, float> > > stats;

    // Les déplacements possibles de chaques pièces du joueur `joueurID`
    std::map<Piece*, std::vector<Coordonnees> > __deps_poss = this->deplPossiblesSTL(joueurID);

    std::map<Piece*, std::vector<Coordonnees> >::iterator it_map;
    std::vector<Coordonnees>::iterator it_coor;

    float ratio_max = 0.0;

    Piece* _p = NULL;
    Piece* _p2 = NULL;

    Coordonnees _c;

    // On boucle sur toutes les pièces du joueur `joueurID`
    for(it_map = __deps_poss.begin(); it_map != __deps_poss.end(); it_map++) {
        // Si la pièce n'est pas placée, alors on ne fait rien
        if(it_map->first->getEtat() != PLACE) {
            continue;
        }

        // On boucle sur tous les déplacements possibles de la pièce
        for(it_coor = it_map->second.begin(); it_coor != it_map->second.end(); it_coor++) {

            // On initialise les valeurs de base
            stats[it_map->first][it_coor->str]["victoires"] = 0;
            stats[it_map->first][it_coor->str]["defaites"] = 0;
            stats[it_map->first][it_coor->str]["ratio"] = 0;

            // On lance 100 nouvelles parties afin de trouver le meilleur coup
            for(int i = 0; i < 100; i++) {
                // On crée une nouvelle partie, afin que la partie actuelle ne soit pas affectée par les différents déplacements
                Partie* partie = new Partie(this->partie);

                partie->increaseNbTours();
                partie->increaseNbToursSansPrise();

                // On bouge la pièce `it_map->first` aux coordonnées `*it_coor`
                partie->plateau->movePiece(it_map->first, *it_coor);

                // On joue une partie "normalement"
                while(!partie->isTerminee_regle1()) {
                    partie->increaseNbTours();
                    partie->increaseNbToursSansPrise();
                    partie->plateau->deplaceAleatoireSTL(partie->getCurrentJoueurId());
                }

                // Si l'identifiant du gagnant est le même que `joueurID`
                if(partie->getWinnerId() == joueurID) {
                    // on incrémente le nombre de victoires pour la pièce `it_map->first` aux coordonnées `it_coor->str`
                     stats[it_map->first][it_coor->str]["victoires"]++;
                } else {
                    // sinon on incrémente le nombre de défaite
                     stats[it_map->first][it_coor->str]["defaites"]++;
                }

                // Et on supprime ensuite le nouveau plateau et la nouvelle partie
                if(partie->plateau) { delete partie->plateau; }
                if(partie) { delete partie; }
            }
        }
    }

    cout << "Affichage des ratios de victoire des différentes pièces : " << endl;
    for(it_map = __deps_poss.begin(); it_map != __deps_poss.end(); it_map++) {
        for(it_coor = it_map->second.begin(); it_coor != it_map->second.end(); it_coor++) {

            // On calcul le ratio de victoire/défaite
            stats[it_map->first][it_coor->str]["ratio"] = stats[it_map->first][it_coor->str]["victoires"] /
                    (float)(stats[it_map->first][it_coor->str]["victoires"] + stats[it_map->first][it_coor->str]["defaites"]);

//            cout << "monteCarlo() => [" << it_map->first->getName() << "][" << it_coor->str << "]['victoires'] = " << stats[it_map->first][it_coor->str]["victoires"] << endl;
//            cout << "monteCarlo() => [" << it_map->first->getName() << "][" << it_coor->str << "]['defaites'] = " << stats[it_map->first][it_coor->str]["defaites"] << endl;
//            cout << "monteCarlo() => [" << it_map->first->getName() << "][" << it_coor->str << "]['ratio'] = " << stats[it_map->first][it_coor->str]["ratio"] << endl;

            // Si on a un ratio de victoire/défaite supérieur au `ratio_max`
            if(stats[it_map->first][it_coor->str]["ratio"] >= ratio_max) {
                ratio_max = stats[it_map->first][it_coor->str]["ratio"];
                // Assignation de la nouvelle pièce
                _p = it_map->first;

                // Assignation des nouvelles coordonnées
                _c = newCoords(it_coor->x, it_coor->y);

                cout << " - " << ratio_max << " - " << _p->toString(true) << " - " << _c.str << endl;
            }
        }
    }

    cout << "Le meilleur coup est donc : " << ratio_max << " ; Piece : " << _p->toString(true) << " - " << _p->toString(true) << " - " << _c.str << endl;

    _p2 = this->getPiece(_c);

    if(_p2 != NULL && (_p2 != _p || _p->getCouleur() != _p2->getCouleur())) {
        _p2->setEtat(PRIS);
        this->removePieceFromPlateau(_p2);
        this->partie->setNbToursSansPrise(0);
    }

    this->movePiece(_p, _c);
    return true;
}


Plateau::~Plateau() {
    for(int i = 0; i < this->nbPieces; i++) {;
        if(this->pieces[i]) {
            delete this->pieces[i];
        }
    }

    this->resetPlateau();
    this->resetPieces();
}
