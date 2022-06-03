/*
*   Soubor:     htab_size.c
*   Název:      Dú 2 IJC, b)
*   Autor:      Lukáš Kaprál - xkapra00
*   Fakulta:    Fakulta informačních technologií
*   Datum:      20.4.2021
*   Popis:      Funkce vrací počet neprázdných prvků 
*/

#include "htab.h"
#include "htab_struct.h"

//vrátí počet prvků tabulky (.size)
size_t htab_size(const htab_t *t) {
    size_t size = t->size;
    return size;
}