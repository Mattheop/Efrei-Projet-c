#include "commands.h"
#include "../utils/utils.h"
#include "../validators/validators.h"
#include "../storage/storage_csv.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void commande_afficher_repertoire(Repertoire *rep) {
    if (rep->size == 0) {
        printf("Le repertoire est vide\n");
        wait_to_continue();
        return;
    }

    RepertoireNode *current = rep->head;
    while (current != NULL) {
        afficherPersonne(current->personne);
        current = current->next;
    }
}

void commande_ajouter_personne(Repertoire *rep) {
    char nom[50];
    char prenom[50];
    char numero[50];
    char mail[50];

    printf("Veuillez entrer le nom de la personne: ");
    scanf("%s", nom);

    printf("Veuillez entrer le prenom de la personne: ");
    scanf("%s", prenom);


    printf("Veuillez entrer le numero de la personne (pas d'indicatif, seulement des chiffres): ");
    scanf("%s", numero);
    if (!valider_numero(numero)) {
        do {
            printf("numero invalide, il ne doit contenir que des chiffres et peut commencer par un +\n");
            printf("Veuillez entrer le numero de la personne (pas d'indicatif, seulement des chiffres): ");
            scanf("%s", numero);
        } while (!valider_numero(numero));
    }

    printf("Veuillez entrer le mail de la personne: ");
    scanf("%s", mail);
    if (!valider_email(mail)) {
        do {
            printf("mail invalide, il doit contenir au moins 1 point et un @\n");
            printf("Veuillez entrer le mail de la personne: ");
            scanf("%s", mail);
        } while (!valider_email(mail));
    }

    Personne *p = creerPersonne(nom, prenom, numero, mail);
    ajouterPersonne(rep, p);
    printf("Personne ajoutée avec succès\n");
    wait_to_continue();
}

void commande_chercher_personne_par_nom(Repertoire *rep) {
    char nom[50];
    bool invalid = true;

    while (invalid) {
        printf("Veuillez entrer le nom de la personne (vide pour annuler): ");
        flush_input();
        fgets(nom, sizeof nom, stdin);
        nom[strlen(nom) - 1] = '\0';

        if (strlen(nom) == 0) {
            invalid = false;
            continue;
        }

        Repertoire *result = chercherPersonnes(rep, nom);
        if (result->size == 0) {
            printf("Personne non trouvée\n");
        } else {
            printf("Personnes trouvées (%d resultats):\n", result->size);
            commande_afficher_repertoire(result);
            invalid = false;
        }
    }

    wait_to_continue();
}

void commande_supprimer_personne_par_nom(Repertoire *rep) {
    char nom[50];
    bool invalid = true;
    char confirmer;

    while (invalid) {
        printf("Veuillez entrer le nom de la personne (vide pour annuler): ");
        flush_input();
        fgets(nom, sizeof nom, stdin);
        nom[strlen(nom) - 1] = '\0';

        if (strlen(nom) == 0) {
            printf("Annulation de la suppression\n");
            invalid = false;
            continue;
        }

        Repertoire *result = chercherPersonnes(rep, nom);

        if (result->size == 0) {
            printf("Personne non trouvée\n");
            continue;
        }

        Personne *chosen = result->head->personne;

        if (result->size > 1) {
            printf("Plusieurs personnes trouvées (%d resultats):\n", result->size);
            commande_afficher_repertoire(result);

            printf("Veuillez entrer la position de la personne à supprimer (vide pour annuler): ");
            fgets(nom, sizeof nom, stdin);
            nom[strlen(nom) - 1] = '\0';
            if (strlen(nom) == 0) {
                printf("Annulation de la suppression\n");
                invalid = false;
                continue;
            }

            int position = atoi(nom);

            if (position < 1 || position > result->size) {
                printf("Position invalide\n");
                continue;
            }

            RepertoireNode *current = result->head;
            for (int i = 1; i < position; i++) {
                current = current->next;
            }

            chosen = current->personne;
        }

        printf("Vous allez supprimer la personne suivante :\n");
        afficherPersonne(chosen);
        printf("\nEntrer (y) pour confirmer la suppression : ");
        scanf(" %c", &confirmer);
        invalid = false;

        if (confirmer == 'y') {
            supprimerPersonneExacte(rep, chosen);
            printf("Personne supprimée avec succès\n");
        }
    }

    wait_to_continue();

}

void commande_sauvegarder_repertoire(Repertoire *rep, char *filename) {
    if (savegarder_csv(rep, filename)) {
        printf("Repertoire sauvegardé avec succès\n");
    } else {
        printf("Erreur lors de la sauvegarde du repertoire\n");
    }

    wait_to_continue();
}