/*
*   Soubor:     htab_lookup_add.c
*   Název:      Dú 2 IJC, b)
*   Autor:      Lukáš Kaprál - xkapra00
*   Fakulta:    Fakulta informačních technologií
*   Datum:      21.4.2021
*   Popis:      Funkce přidává řetězec key do záznamu
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htab.h"
#include "htab_struct.h"

htab_item *item_init(htab_key_t key)
{
    htab_item *item = malloc(sizeof(htab_item));
    if (item == NULL) {
        return NULL;
    }
    item->data = malloc(sizeof(htab_pair_t));
    if (item->data == NULL) {
        return NULL;
    }
    size_t len = strlen(key) + 1;
    item->data->key = malloc(len);
    if (item->data->key == NULL) {
        return NULL;
    }
    memcpy((char *)item->data->key, key, len);
    item->next = NULL;
    item->data->value = 0;
    return item;
}

/*
V tabulce  t  vyhledá záznam odpovídající řetězci  key  a
        - pokud jej nalezne, vrátí ukazatel na záznam
        - pokud nenalezne, automaticky přidá záznam a vrátí ukazatel
*/
htab_pair_t *htab_lookup_add(htab_t *t, htab_key_t key)
{
    size_t index;
    index = ((htab_hash_function(key)) % t->arr_size);
    htab_item *tmp = t->list[index];
    htab_item *prev = NULL;
    //pro prázdný záznam - vytvořím nový item
    if (tmp == NULL)
    {
        t->size++;
        t->list[index] = item_init(key);
        return t->list[index]->data;
    }
    else
    {
        while (tmp != NULL)
        {
            if ((strcmp(tmp->data->key, key) == 0))
            {
                return tmp->data;
            }
            prev = tmp;
            tmp = tmp->next;
        }
        tmp = item_init(key);
        prev->next = tmp;
        t->size++;
    }
    return tmp->data;
}