/*
*   Soubor:     htab_bucket_count.c
*   Název:      Dú 2 IJC, b)
*   Autor:      Lukáš Kaprál - xkapra00
*   Fakulta:    Fakulta informačních technologií
*   Datum:      20.4.2021
*   Popis:      Funkce vrací počet prvků (i prázdných)
*/

#include "htab.h"
#include "htab_struct.h"

//vrátí počet prvků pole (.arr_size)
size_t htab_bucket_count(const htab_t *t) {
    size_t arr_size = t->arr_size;
    return arr_size;
}