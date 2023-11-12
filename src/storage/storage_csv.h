#ifndef STORAGE_CSV_H
#define STORAGE_CSV_H

#include "../core/repertoire.h"
#include <stdbool.h>

bool charger_csv(Repertoire *rep,char *filename);
bool savegarder_csv(Repertoire *rep,char *filename);

#endif //STORAGE_CSV_H
