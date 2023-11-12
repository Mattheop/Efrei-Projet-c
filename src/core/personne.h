#include <stdio.h>

#ifndef PERSONNE_H
#define PERSONNE_H

typedef struct Personne {
    char nom[50];
    char prenom[50];
    char numero[50];
    char mail[50];

} Personne;

void afficherPersonne(Personne *p);
Personne *creerPersonne(char *nom, char *prenom, char *numero, char *mail);

#endif
