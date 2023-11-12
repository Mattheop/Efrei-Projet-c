#include <stdbool.h>
#include "storage_csv.h"
#include "string.h"
#include "../core/personne.h"
#include "../validators/validators.h"

bool charger_csv(Repertoire *rep, char *filename) {
    FILE *fichier = fopen(filename, "r");
    if (fichier == NULL) {
        return false;
    }

    char ligne[210];
    while (fgets(ligne, 210, fichier) != NULL) {
        // on sépare les données NON thread safe !!
        char *nom = strtok(ligne, ";");
        char *prenom = strtok(NULL, ";");
        char *email = strtok(NULL, ";");
        char *numero = strtok(NULL, ";");
        numero[strlen(numero) - 1] = '\0';

        // on revérifie les donnees
        if (valider_email(email) && valider_numero(numero)) {
            Personne *aPersonne = creerPersonne(nom, prenom, numero, email);
            ajouterPersonne(rep, aPersonne);
        } else {
            valider_email(email);
            valider_numero(numero);
            printf("Erreur de chargement de la ligne %s %s %s %s. Validation: email %d, numero %d\n", nom, prenom, email, numero, valider_email(email), valider_numero(numero));
        }
    }

    fclose(fichier);
    return true;
}

bool savegarder_csv(Repertoire *rep, char *filename) {
    FILE *fichier = fopen(filename, "w");
    if (fichier == NULL) {
        return false;
    }

    if (rep->size == 0) {
        fclose(fichier);
        return true;
    }

    RepertoireNode *current = rep->head;
    while (current != NULL) {
        fprintf(fichier, "%s;%s;%s;%s\n", current->personne->nom, current->personne->prenom, current->personne->mail,
                current->personne->numero);
        current = current->next;
    }

    return true;
}