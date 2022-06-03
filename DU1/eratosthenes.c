/*
*   Soubor:     eratosthenes.c
*   Název:      Dú 1 IJC, a)
*   Autor:      Lukáš Kaprál - xkapra00
*   Fakulta:    Fakulta informačních technologií
*   Datum:      17.3.2021
*   Popis:      Definuje funkci Eratosthenes, která nastaví všem ne-prvočíslům 1, prvočísla nechá na 0
*/

#include "error.h"
#include "eratosthenes.h"
#include "bitset.h"

void Eratosthenes(bitset_t pole) {
    unsigned long size = bitset_size(pole);
    for (unsigned long i = 2; i*i <= size-1; i++){
        if (bitset_getbit(pole, i) == 0) {
            for (unsigned long j = 2; i*j <= size-1; j++) {
                bitset_setbit(pole, (i*j), 1);
            }
        }
    }
}