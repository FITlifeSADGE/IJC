/*
*   Soubor:     bitset.c
*   Název:      Dú 1 IJC, a)
*   Autor:      Lukáš Kaprál - xkapra00
*   Fakulta:    Fakulta informačních technologií
*   Datum:      16.3.2021
*   Popis:      Definuje externí inline funkce v případě -O0
*/

#include "bitset.h"

#ifdef USE_INLINE

extern inline unsigned long bitset_getbit(bitset_t name, unsigned long index);
extern inline void bitset_setbit(bitset_t name, unsigned long index, int num);
extern inline unsigned long bitset_size(bitset_t name);
extern inline void bitset_free(bitset_t name);
#endif