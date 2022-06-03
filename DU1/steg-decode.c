/*
*   Soubor:     steg-decode.c
*   Název:      Dú 1 IJC, b)
*   Autor:      Lukáš Kaprál - xkapra00
*   Fakulta:    Fakulta informačních technologií
*   Datum:      21.3.2021
*   Popis:      Vezme první bit prvočíselného bytu, uloží ho na správný bit charu, pokud je v charu již 8 bitů, uloží se do zprávy a opět se char nastaví na 0
*/


#include "ppm.h"
#include "eratosthenes.h"
#include "error.h"
#include "bitset.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        error_exit("Zadali jste malo argumentu");
    }
    struct ppm *image = ppm_read(argv[1]);
    if (image == NULL) {
        error_exit("Načítání obrázku se nezdařilo");
    }
    size_t size = image->xsize * image->ysize * 3;
    char *message;
    message = malloc(size);
    if (message == NULL) {
        error_exit("Chyba alokace paměti");
    }
    bitset_alloc(pole, size);
    Eratosthenes(pole);
    char c = 0;
    int count = 0;
    int pos = 0;
    int check = 0;

    for (unsigned long i = 23; i < size; i++) {
        if (bitset_getbit(pole, i) == 0) {
            c |= (image->data[i] & 1) << count;
            count++;
            if (count == 8) {
                message[pos] = c;
                pos++;
                if (c == '\0') {
                    check++;
                    break;
                }
                c = 0;
                count = 0;

            }
        }
    }
    if (check == 0) {
        ppm_free(image);
        bitset_free(pole);
        free(message);
        error_exit("Soubor nebyl správně ukončen");
    }

    printf("%s\n", message);
    ppm_free(image);
    bitset_free(pole);
    free(message);
    return 0;
}