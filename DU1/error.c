/*
*   Soubor:     error.c
*   Název:      Dú 1 IJC, a), b)
*   Autor:      Lukáš Kaprál - xkapra00
*   Fakulta:    Fakulta informačních technologií
*   Datum:      15.3.2021
*   Popis:      Definuje funkce na ukončení programu v případě, že něco bylo zadáno jinak, než je povoleno
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "error.h"


void warning_msg(const char *fmt, ...) {
    va_list arguments;
    va_start(arguments, fmt);
    fprintf(stderr, "CHYBA: ");
    vfprintf(stderr, fmt, arguments);
    fprintf(stderr, "\n");
    va_end(arguments);
}

void error_exit(const char *fmt, ...) {
    va_list arguments;
    va_start(arguments, fmt);
    fprintf(stderr, "CHYBA: ");
    vfprintf(stderr, fmt, arguments);
    fprintf(stderr, "\n");
    va_end(arguments);
    exit(1);
}