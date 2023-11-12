#include <stdlib.h>
#include <string.h>
#include "personne.h"

Personne *creerPersonne(char *nom, char *prenom, char *numero, char *mail) {
    Personne *p = malloc(sizeof(Personne));

    strcpy(p->nom, nom);
    strcpy(p->prenom, prenom);
    strcpy(p->numero, numero);
    strcpy(p->mail, mail);

    return p;
}

void afficherPersonne(Personne *p) {
    printf("========================================\n");
    printf("Nom: %s\n", p->nom);
    printf("Prenom: %s\n", p->prenom);
    printf("Numero: %s\n", p->numero);
    printf("Mail: %s\n", p->mail);
    printf("========================================\n");
}

