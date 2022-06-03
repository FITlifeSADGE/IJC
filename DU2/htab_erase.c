/*
*   Soubor:     htab_erase.c
*   Název:      Dú 2 IJC, b)
*   Autor:      Lukáš Kaprál - xkapra00
*   Fakulta:    Fakulta informačních technologií
*   Datum:      22.4.2021
*   Popis:      Vyhledá položku podle stringu key a odstraní ji
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "htab.h"
#include "htab_struct.h"

bool htab_erase(htab_t *t, htab_key_t key)
{
    size_t index = (htab_hash_function(key) % t->arr_size);
    htab_item *current = t->list[index];
    htab_item *prev = current;

    while (current != NULL)
    {
        if (strcmp(current->data->key, key) == 0)
        {
            if (current == prev)
            {
                t->list[index] = current->next;
                t->size--;
                return true;
            }
            t->size--;
            prev->next = current->next;
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false;
}