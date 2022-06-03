/*
*   Soubor:     htab_find.c
*   Název:      Dú 2 IJC, b)
*   Autor:      Lukáš Kaprál - xkapra00
*   Fakulta:    Fakulta informačních technologií
*   Datum:      21.4.2021
*   Popis:      Vyhledá položku, vrátí ukazatel na položku, pokud ji najde, jinak vrátí NULL
*/

#include <stdio.h>
#include <stdlib.h>
#include "htab.h"
#include "htab_struct.h"

/*V tabulce  t  vyhledá záznam odpovídající řetězci  key  a
        - pokud jej nalezne, vrátí ukazatel na záznam
        - pokud nenalezne, vrátí NULL
*/
htab_pair_t *htab_find(htab_t *t, htab_key_t key)
{
    htab_item *tmp = NULL;
    size_t index = (htab_hash_function(key) % t->arr_size);
    tmp = t->list[index];
    while (tmp != NULL)
    {
        if (strcmp(tmp->data->key, key) == 0) {
            return tmp->data;
        }
        tmp = tmp->next;
    }
    return NULL;
}