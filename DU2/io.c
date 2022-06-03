/*
*   Soubor:     io.c
*   Název:      Dú 2 IJC, b)
*   Autor:      Lukáš Kaprál - xkapra00
*   Fakulta:    Fakulta informačních technologií
*   Datum:      22.4.2021
*   Popis:      Funkce načte slovo ze souboru, uloží ho do pole s a vrátí jeho délku
*/

#include "io.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int read_word(char s[], int max, FILE *f) {
    int c = 0;
    int num = 0;
    while (((c = fgetc(f)) != EOF) && (num < max-1)) {
        if (isspace(c)) {
            break;
        }
        s[num] = c;
        num++;
    }
    if ((!isspace(c)) && (c != EOF)) {
        while (!(isspace(c))) {
            c = fgetc(f);
        }
        num = max;
    }
    if (c == EOF) {
        return EOF;
    }
    s[num] = '\0';
    return num;
}