/*
*   Soubor:     htab_clear.c
*   Název:      Dú 2 IJC, b)
*   Autor:      Lukáš Kaprál - xkapra00
*   Fakulta:    Fakulta informačních technologií
*   Datum:      22.4.2021
*   Popis:      Zruší všechny položky a ponechá prázdnou tabulku
*/

#include <stdio.h>
#include <stdlib.h>
#include "htab.h"
#include "htab_struct.h"

//zrušení všech položek, tabulka zůstane prázdná
void htab_clear(htab_t *t) {
    htab_item *tmp;
    htab_item *tmp_prev;
    size_t n = t->arr_size;
    for (unsigned long i = 0; i < n; i++) {
        tmp = t->list[i];
        while (tmp != NULL) {
            tmp_prev = tmp->next;
            free(tmp->data);
            free(tmp);
            tmp = tmp_prev;
            t->size--;
        }
        t->list[i] = NULL;
    }
}