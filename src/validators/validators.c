#include "validators.h"
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool valider_email(char *email) {
    char *atSymbol = strchr(email, '@');
    char *dotSymbol = strchr(email, '.');

    if (atSymbol == NULL || dotSymbol == NULL) {
        return false;
    }

    return true;
}

bool valider_numero(char *numero){
    if (numero[0] != '+' && !isdigit(numero[0])) {
        return false;
    }

    for (int i = 1; i < strlen(numero); i++) {
        if (!isdigit(numero[i])) {
            return false;
        }
    }

    return true;
}
