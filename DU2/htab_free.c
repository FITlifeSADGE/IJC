/*
*   Soubor:     htab_free.c
*   Název:      Dú 2 IJC, b)
*   Autor:      Lukáš Kaprál - xkapra00
*   Fakulta:    Fakulta informačních technologií
*   Datum:      22.4.2021
*   Popis:      Funkce uvolní alokovanou paměť
*/

#include <stdio.h>
#include <stdlib.h>
#include "htab.h"
#include "htab_struct.h"

void htab_free(htab_t *t)
{
    htab_clear(t);
    free(t);
}