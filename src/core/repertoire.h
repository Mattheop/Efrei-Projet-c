#ifndef REPERTOIRE_H
#define REPERTOIRE_H

#include "personne.h"
#include <stdbool.h>

/*
 * Noeud de la liste chainee
*/
typedef struct RepertoireNode {
    Personne *personne;

    struct RepertoireNode *next;
    struct RepertoireNode *prev;
} RepertoireNode;

/*
 * Struture porteuse de la liste chainee
 * permettant de materialiser le debut, et sa taille
*/
struct Repertoire {
    int size;
    RepertoireNode *head;
} typedef Repertoire;

Repertoire *creerRepertoire();
void ajouterPersonne(Repertoire *rep, Personne *p);
Personne *chercherPersonne(Repertoire *rep, char *nom);
Repertoire *chercherPersonnes(Repertoire *rep, char *nom);
bool supprimerPersonne(Repertoire *rep, char *nom);
bool supprimerPersonneExacte(Repertoire *rep, Personne *p);

#endif