/*
*   Soubor:     wordcount.c
*   Název:      Dú 2 IJC, b)
*   Autor:      Lukáš Kaprál - xkapra00
*   Fakulta:    Fakulta informačních technologií
*   Datum:      23.4.2021
*   Popis:      Funkce čte slova ze souboru, dokud nenarazí na EOF. Slova ukládá do tabulky table.
*/

#include "htab.h"
#include "htab_struct.h"
#include "io.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void print(htab_pair_t *data) {
    printf("%s\t%d\n", data->key, data->value);
}

int main()
{
    htab_t *table;
    htab_t *move;
    htab_pair_t *check;

    char *str;
    str = calloc(128, 0);
    if (str == NULL) {
        return -1;
    }
    int word = 0;
    bool warning = false;

    FILE *fp = stdin;
    table = htab_init(7000);
    while (word != EOF) {
        word = read_word(str, 128, fp);
        if (word == 128 && !(warning)) {
            fprintf(stderr, "wordcount: Slovo přesáhlo povolenou délu 127 znaků\n");
            warning = true;
        }
        if (word == EOF) {
            break;
        }
        if (str[0] != '\0') {
           check = htab_lookup_add(table, str);
           check->value++;
        }
    }
    #ifdef MOVETEST
    move = htab_init(7000);
    move = htab_move(7000, table);
    htab_for_each(move, print);
    htab_free(move);
    #else
    htab_for_each(table, print);
    #endif
    free(str);
    htab_free(table);
    return 0;
}