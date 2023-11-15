#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "repertoire.h"

Repertoire *creerRepertoire() {
    Repertoire *rep = malloc(sizeof(Repertoire));
    rep->size = 0;
    rep->head = NULL;

    return rep;
}

void ajouterPersonne(Repertoire *rep, Personne *p) {
    RepertoireNode *node = malloc(sizeof(RepertoireNode));
    node->personne = p;
    node->next = NULL;
    node->prev = NULL;

    if (rep->head == NULL) {
        rep->head = node;
    } else {
        RepertoireNode *current = rep->head;
        while (current->next != NULL) {
            current = current->next;
        }

        current->next = node;
        node->prev = current;
    }

    rep->size++;
}

bool supprimerPersonne(Repertoire *rep, char *nom) {
    RepertoireNode *current = rep->head;
    while (current != NULL) {
        if (strcmp(current->personne->nom, nom) == 0) {
            if (current->prev == NULL) {
                rep->head = current->next;
            } else {
                current->prev->next = current->next;
            }

            if (current->next != NULL) {
                current->next->prev = current->prev;
            }

            free(current);
            rep->size--;
            return true;
        }

        current = current->next;
    }

    return false;
}

Personne *chercherPersonne(Repertoire *rep, char *nom) {
    RepertoireNode *current = rep->head;
    while (current != NULL) {
        if (
            strcmp(current->personne->nom, nom) == 0 |
            strcmp(current->personne->prenom, nom) == 0 |
            strcmp(current->personne->numero, nom) == 0 |
            strcmp(current->personne->mail, nom) == 0
        ) {
            return current->personne;
        }

        current = current->next;
    }

    return NULL;
}

