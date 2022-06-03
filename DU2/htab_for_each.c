/*
*   Soubor:     htab_for_each.c
*   Název:      Dú 2 IJC, b)
*   Autor:      Lukáš Kaprál - xkapra00
*   Fakulta:    Fakulta informačních technologií
*   Datum:      22.4.2021
*   Popis:      Zavolá funkci f na všechny položky tabulky t
*/

#include <stdio.h>
#include <stdlib.h>
#include "htab.h"
#include "htab_struct.h"

void htab_for_each(const htab_t *t, void (*f)(htab_pair_t *data)) {
    htab_item *tmp;
    size_t n = t->arr_size;
    for (unsigned long i = 0; i < n; i++) {
        tmp = t->list[i];
        while (tmp != NULL) {
            f((tmp->data));
            tmp = tmp->next;
        }
    }
}