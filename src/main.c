#include <stdio.h>
#include "core/repertoire.h"
#include "core/personne.h"
#include "commands/commands.h"
#include "storage/storage_csv.h"

void afficher_menu() {
    printf("========================================\n");
    printf("Sélectionner une option:\n");
    printf("1. Ajouter une personne\n");
    printf("2. Afficher le repertoire\n");
    printf("3. Rechercher par un nom\n");
    printf("4. Supprimer par un nom\n");
    printf("0. Sauvegarder et quitter\n");
    printf("========================================\n");
}

int demander_commande() {
    printf("Votre choix: ");

    int choice = 0;
    scanf("%d", &choice);
    printf("\n");

    return choice;
}

int main(void) {
    int choice;
    printf("Bienvenue dans le repertoire téléphonique\n");

    Repertoire *rep = creerRepertoire();
    if (charger_csv(rep, "repertoire.csv")) {
        printf("Chargement du repertoire réussi\n");
    } else {
        printf("Chargement du repertoire échoué, le repertoire est vide\n");
    }

    do {
        afficher_menu();
        choice = demander_commande();

        switch (choice) {
            case 1:
                commande_ajouter_personne(rep);
                break;
            case 2:
                commande_afficher_repertoire(rep);
                break;
            case 3:
                commande_chercher_personne_par_nom(rep);
                break;
            case 4:
                commande_supprimer_personne_par_nom(rep);
                break;
            case 0:
                commande_sauvegarder_repertoire(rep, "repertoire.csv");
                printf("Au revoir\n");
                break;
            default:
                printf("Choix invalide\n");
                break;
        }

    } while (choice != 0);

    return 0;
}