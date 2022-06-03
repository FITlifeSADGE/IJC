/*
*   Soubor:     htab_move.c
*   Název:      Dú 2 IJC, b)
*   Autor:      Lukáš Kaprál - xkapra00
*   Fakulta:    Fakulta informačních technologií
*   Datum:      20.4.2021
*   Popis:      Funkce přesune data z jedné tabulky do druhé, původní nechá prázdnou
*/

#include <stdio.h>
#include <stdlib.h>
#include "htab.h"
#include "htab_struct.h"

/*move konstruktor: vytvoření a inicializace
nové tabulky přesunem dat z tabulky t2,
t2 nakonec zůstane prázdná a alokovaná
*/
htab_t *htab_move(size_t n, htab_t *from) {
    htab_item *tmp;
    htab_pair_t *check;
    htab_t *move = htab_init(n);
    if (move == NULL) {
        fprintf(stderr, "htab_move: Malloc error");
        return NULL;
    }
    move->arr_size = n;
    move->size = from->size;
    for (unsigned long i = 0; i < from->arr_size; i++) {
        tmp = from->list[i];
        while (tmp != NULL) {
            check = htab_lookup_add(move, tmp->data->key);
            check->value++;
            tmp = tmp->next;
        }
    }

    htab_clear(from);
    return move;
}