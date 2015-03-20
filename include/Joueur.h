#ifndef JOUEUR_H
#define JOUEUR_H

#include <string>
#include "Partie.h"

using namespace std;

class Partie;

class Joueur
{
    public:
        Joueur();
        Joueur(string);
        virtual ~Joueur();

        void setNom(string);
        string getNom(void);

        void setPartie(Partie*);
        Partie* getPartie(void);

    private:
        string nom;
        Partie* partie;
};

#endif // JOUEUR_H
