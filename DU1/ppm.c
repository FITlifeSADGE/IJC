/*
*   Soubor:     ppm.c
*   Název:      Dú 1 IJC, b)
*   Autor:      Lukáš Kaprál - xkapra00
*   Fakulta:    Fakulta informačních technologií
*   Datum:      20.3.2021
*   Popis:      Definuje funkce na načtení souboru do struktury a uvolnění paměti
*   Problémy:   Z nějakého důvodu jsem se stažil několik hodit opravit steg-decode, kde mi to vypisovalo ;4E EH
*               Rozbil jsem si kvůli tomu bitset.h a nakonec jsem se rozhodl celý ppm_read smazat a napsat znovu úplně stejně
*               a najednou to fungovalo
*/

/*
*   Struktura PPM 
*   př. 1 = P6 1024 788 255
*   "P6" <ws>+
*   <xsizetxt> <ws>+ <ysizetxt> <ws>+
*   "255" <ws>
*   <binární data, 3*xsize*ysize bajtů RGB>
*   <EOF>
*
*   implementační detaily
*   omezit limitem 8000*8000*3
*   pouze binární variantu P6
*   barvy 0..255
*   bez komentářů
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "error.h"
#include "ppm.h"

struct ppm *ppm_read(const char *filename) {
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        warning_msg("Nepodařilo se otevřít soubor");
        return NULL;
    }
    struct ppm *image = NULL;
    //zadaný limit
    size_t limit = 8000 * 8000 * 3;
    
    unsigned width, height, color;

    //implementace pouze binární varianty P6
    if(fscanf(fp, "P6 %u %u %u ", &width, &height, &color) != 3) {
        fclose(fp);
        warning_msg("Nepodařilo se otevřít soubor");
        return NULL;
    }
    size_t imgsize = 3 * width * height;

    if (imgsize > limit) {
        fclose(fp);
        warning_msg("Obrazek je prilis velky");
        return NULL;
    }
    
    if (color != 255) {
        fclose(fp);
        warning_msg("Format barev neodpovídá");
        return NULL;
    }

    image = malloc(sizeof(struct ppm) + imgsize);
    
    if (image == NULL) {
        fclose(fp);
        warning_msg("Chyba alokace paměti");
        return NULL;
    }

    image->xsize = width;
    image->ysize = height;

    if(fread(image->data, 1, imgsize, fp) != imgsize) {
        ppm_free(image);
        fclose(fp);
        warning_msg("Soubor se nepodařilo zapsat");
        return NULL;
    }

    fclose(fp);
    return image;
}

void ppm_free(struct ppm *p) {
    free(p);
}