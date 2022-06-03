/*
*   Soubor:     htab_struct.h
*   Název:      Dú 2 IJC, b)
*   Autor:      Lukáš Kaprál - xkapra00
*   Fakulta:    Fakulta informačních technologií
*   Datum:      20.4.2021
*   Popis:      Definuje struktury pro položku (htab_item) a pro celou tabulku (htab_t)
*/

#ifndef __HTABLE_STRUCT_H__
#define __HTABLE_STRUCT_H__

#include <stdio.h>
#include <stdlib.h>
#include "htab.h"

//struktura htab_item
typedef struct htab_item
{
    htab_pair_t *data;
    struct htab_item *next;
} htab_item;

/*table je struktura obsahující pole seznamů, jeho 
velikost arr_size(počet prvků pole) a počet položek tabulky size
*/
struct htab {
    size_t size;
    size_t arr_size;
    htab_item *list[];
};

#endif // __HTABLE_STRUCT_H__