/*
*   Soubor:     ppm.h
*   Název:      Dú 1 IJC, b)
*   Autor:      Lukáš Kaprál - xkapra00
*   Fakulta:    Fakulta informačních technologií
*   Datum:      20.3.2021
*/
#ifndef HEADFILE_H
#define HEADFILE_H

struct ppm {
        unsigned xsize;
        unsigned ysize;
        char data[];
     };

struct ppm *ppm_read(const char * filename);
void ppm_free(struct ppm *p);

#endif