/*
*   Soubor:     bitset.h
*   Název:      Dú 1 IJC, a)
*   Autor:      Lukáš Kaprál - xkapra00
*   Fakulta:    Fakulta informačních technologií
*   Datum:      15.3.2021
*   Popis:      Definuje makra a inline funkce podle zadání
*   Problémy:    Při kontrolování index < 0 ? jsem neustále dostával varování, 
*               Asi stále nerozumím, jak předělat bitset_alloc tak, aby jméno pole bylo kompatibilní s polem vytvořeným pomocí bitset_create
*/
#ifndef MYHEADFILE_H
#define MYHEADFILE_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include "error.h"


typedef unsigned long *bitset_t;
typedef unsigned long bitset_index_t;
/*
*   Makra na ušetření místa
*/

//výpočet potřebného místa
#define velikost(size)\
    ((size)/(CHAR_BIT * sizeof(unsigned long)))\
    + 1 + (((size) % (CHAR_BIT * sizeof(unsigned long))) ? 1 : 0)

//výpočet pozice v poli
#define pos(index)\
index/(CHAR_BIT * sizeof(unsigned long)) + 1

//výpočet o kolik pozic se musí posunout (unsigned long)1 
#define mod(index)\
index%(CHAR_BIT * sizeof(unsigned long))

//vytvoří pole o správné velikosti, na první pozici nahraje size, zbytek nastaví na 0
#define bitset_create(name, size)\
    static_assert(size > 0, "Pole musi mit velikost vetsi nez 0");\
    unsigned long name[velikost(size)] = {size}

//funguje jako bitset_create, akorát využívá pamět na heapu
#define bitset_alloc(name, size)\
    assert((size < ULONG_MAX-1 && (size) > 0));\
    bitset_t name = calloc(velikost(size), sizeof(unsigned long));\
    (name == NULL) ? (error_exit("bitset_alloc:Chyba alokace paměti"), 0) : (name[0] = (size))

#ifdef USE_INLINE
    inline void bitset_free(bitset_t name) {
        free(name);
    }
#else
    #define bitset_free(name) free(name)
#endif

#ifdef USE_INLINE
    inline unsigned long bitset_size(bitset_t name) {
        return name[0];
    }
#else
    #define bitset_size(name) (name[0])
#endif

//Nekontroluji, jestli je index > 0, neustále to vypisuje varování
//pokud nastavuji na 1 => (1 OR 1 = 1, 0 OR 1 = 1); pokud nastavuji na 0 => na místě, které chci nastavit bude po negaci (unsigned long)1 nula, všude jinde bude 1
//(1 & 0 = 0, 0 & 0 = 0)
#ifdef USE_INLINE
    inline void bitset_setbit(bitset_t name, unsigned long index, int num) {
        if(index > bitset_size(name)-1) {
            error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu", (unsigned long)index, (unsigned long)bitset_size(name)-1); 
        }
        if(num) {
            name[pos(index)] |= (unsigned long)1 << (mod(index));
        }
        else {
            name[pos(index)] &= ~((unsigned long)1) << (mod(index));
        }
    }
#else
    #define bitset_setbit(name, index, num)\
            (index > bitset_size(name)-1) ? \
            (error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu", (unsigned long)index, (unsigned long)bitset_size(name)-1), 0) : \
            ((num) ? (name[pos(index)] |= (unsigned long)1 << (mod(index))) : (name[pos(index)] &= ~(((unsigned long)1) << (mod(index)))))

#endif

//na zadané pozici bude buď 1, nebo 0. Vezmu toto číslo, použiju &, (1 & 1 = 1; 0 & 1 = 0)
#ifdef USE_INLINE
    inline unsigned long bitset_getbit(bitset_t name, unsigned long index) {
        if(index > bitset_size(name)-1) {
            error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu", (unsigned long)index, (unsigned long)bitset_size(name)-1, 0); 
        }
        return name[pos(index)] & (unsigned long)1 << (mod(index)) ? (unsigned long)1 : (unsigned long)0;
    }
#else
    #define bitset_getbit(name, index)\
        (index > bitset_size(name)-1) ? \
        (error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu", (unsigned long)index, (unsigned long)bitset_size(name)-1), 0) : \
        (name[pos(index)] & (unsigned long)1 << (mod(index)) ? (unsigned long)1 : (unsigned long)0)
#endif
#endif
