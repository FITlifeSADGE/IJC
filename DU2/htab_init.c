/*
*   Soubor:     htab_init.c
*   Název:      Dú 2 IJC, b)
*   Autor:      Lukáš Kaprál - xkapra00
*   Fakulta:    Fakulta informačních technologií
*   Datum:      20.4.2021
*   Popis:      Funkce pro inicializování tabulky
*/

#include <stdio.h>
#include <stdlib.h>
#include "htab.h"
#include "htab_struct.h"

/*konstruktor: vytvoření a inicializace tabulky
n = počet prvků pole (.arr_size)*/
htab_t *htab_init(size_t n)
{
    htab_t *init = malloc(sizeof(htab_t) + n * (sizeof(htab_item)));
    if (init == NULL)
    {
        fprintf(stderr, "htab_init: Malloc error");
        return NULL;
    }

    for (unsigned long i = 0; i < n; i++)
    {
        init->list[i] = NULL;
    }
    init->arr_size = n;
    init->size = 0;

    return init;
}