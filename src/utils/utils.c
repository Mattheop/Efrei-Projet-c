#include "utils.h"
#include <stdio.h>

void flush_input(){
    int c;
    while ((c = getchar()) != '\n')
    {
    }
}

void wait_to_continue(){
    printf("Veuillez appuyer sur entrer pour continuer...\n");
    getchar();
}
