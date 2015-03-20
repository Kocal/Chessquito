#ifndef PARTIE_H
#define PARTIE_H

#include <string>
#include "Joueur.h"

using namespace std;

class Joueur;

class Partie
{
    public:
        Partie();
        Partie(string);
        virtual ~Partie();

        void setDate(string);
        string getDate(void);

        bool setJoueur(Joueur*);
        void quittePartie(Joueur*);
        bool estJouable(void);

    private:
        string date;
        int nbJoueurs;
        int nbJoueursMax;

        Joueur* j1;
        Joueur* j2;

};

#endif // PARTIE_H
