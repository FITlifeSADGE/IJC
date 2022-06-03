/*
*   Soubor:     htab_hash_function.c
*   Název:      Dú 2 IJC, b)
*   Autor:      Lukáš Kaprál - xkapra00
*   Fakulta:    Fakulta informačních technologií
*   Datum:      20.4.2021
*   Popis:      Funkce předělá zadaný string na číslo
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "htab.h"
#include "htab_struct.h"

/*
její výsledek modulo arr_size určuje index do tabulky:
        index = (htab_hash_function("mystring") % arr_size);
*/
size_t htab_hash_function(const char *str) {
          uint32_t h=0;     // musí mít 32 bitů
          const unsigned char *p;
          for(p=(const unsigned char*)str; *p!='\0'; p++)
              h = 65599*h + *p;
          return h;
        }

/*size_t htab_hash_function(const char *str) {
  unsigned long hash = 5381;
  int c;

  while ((c = (*str++)))
    hash = ((hash << 5) + hash) + c;

  return hash;
}*/