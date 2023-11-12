#ifndef COMMANDS_H
#define COMMANDS_H

#include "../core/repertoire.h"

void commande_afficher_repertoire(Repertoire *rep);
void commande_ajouter_personne(Repertoire *rep);
void commande_chercher_personne_par_nom(Repertoire *rep);
void commande_supprimer_personne_par_nom(Repertoire *rep);
void commande_sauvegarder_repertoire(Repertoire *rep, char *filename);

#endif