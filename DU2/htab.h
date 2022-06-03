/*
*   Soubor:     htab.h
*   Název:      Dú 2 IJC, b)
*   Autor:      Lukáš Kaprál - xkapra00
*   Fakulta:    Fakulta informačních technologií
*   Datum:      20.4.2021
*   Popis:      Definuje všechny funkce a struktury
*/

#ifndef __HTAB_H__
#define __HTAB_H__

#include <string.h>
#include <stdbool.h>

struct htab; // neúplná deklarace struktury - uživatel nevidí obsah
typedef struct htab htab_t;

// Typy:
typedef const char *htab_key_t; // typ klíče
typedef int htab_value_t;       // typ hodnoty

// Dvojice dat v tabulce:
typedef struct htab_pair
{
    htab_key_t key;     // klíč
    htab_value_t value; // asociovaná hodnota
} htab_pair_t;          // typedef podle zadání

htab_t *htab_init(size_t n);               // konstruktor tabulky
htab_t *htab_move(size_t n, htab_t *from); // přesun dat do nové tabulky
size_t htab_size(const htab_t *t);         // počet záznamů v tabulce
size_t htab_bucket_count(const htab_t *t); // velikost pole

htab_pair_t *htab_find(htab_t *t, htab_key_t key); // hledání
htab_pair_t *htab_lookup_add(htab_t *t, htab_key_t key);

bool htab_erase(htab_t *t, htab_key_t key); // ruší zadaný záznam

// for_each: projde všechny záznamy a zavolá na ně funkci f
void htab_for_each(const htab_t *t, void (*f)(htab_pair_t *data));

void htab_clear(htab_t *t); // ruší všechny záznamy
void htab_free(htab_t *t);  // destruktor tabulky

size_t htab_hash_function(const char *str);

#endif // __HTAB_H__