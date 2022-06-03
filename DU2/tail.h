/*
*   Soubor:     tail.h
*   Název:      Dú 2 IJC, a)
*   Autor:      Lukáš Kaprál - xkapra00
*   Fakulta:    Fakulta informačních technologií
*   Datum:      15.4.2021
*   Popis:      Definuje funkce pro tail
*/

#ifndef MYHEADFILE_H
#define MYHEADFILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_LEN 512

void nextline (char *row, FILE *fp) {
    if (row[strlen(row)-1] != '\n') {
            int c;
            while((c = fgetc(fp)) !='\n') {
                continue;
            }
            ungetc(c, fp);
        }
}

void errorline (char *row) {
    if (row[strlen(row)-1] != '\n') {
        fprintf(stderr, "Některé řádky jsou delší než povolený limit 511 znaků\n");
    }
}

void printlines(FILE *fp, int num) {
    rewind(fp);
    bool printed = false;
    char *row = malloc(MAX_LEN * sizeof(char));
    if (row == NULL) {
        fprintf(stderr, "MALLOC ERROR");
        return;
    }
    if (!printed) {
        errorline(row);
        printed = true;
    }
    while(fgets(row, MAX_LEN, fp) != NULL) {

        (num - 10) > 0 ? num-- : ((printf("%s", row)) ? printf("ANO") : printf("NE"));
        if (num == 0)
            break;
        nextline(row, fp);
    }
    free(row);
    return;
}

void printmorelines(FILE *fp, int lines, long num) {
    rewind(fp);
    bool printed = false;
    char *row = malloc(MAX_LEN * sizeof(char));
    if (row == NULL) {
        fprintf(stderr, "MALLOC ERROR");
        return;
    }
    if (!printed) {
        errorline(row);
        printed = true;
    }
    int count = 1;
    while(fgets(row, MAX_LEN, fp) != NULL) {
        (count < num) ? count++ : printf("%s", row);
        if (count == lines)
            break;
        nextline(row, fp);
    }
    free(row);
    return;
}

void printnumoflines(FILE *fp, int lines, long num) {
    rewind(fp);
    bool printed = false;
    char *row = malloc(MAX_LEN * sizeof(char));
    if (row == NULL) {
        fprintf(stderr, "MALLOC ERROR");
        return;
    }
    if (!printed) {
        errorline(row);
        printed = true;
    }
    while(fgets(row, MAX_LEN, fp) != NULL) {
        (lines - num) >= 0 ? lines-- : printf("%s", row);
        if (num == 0)
            break;
        nextline(row, fp);
    }
    free(row);
    return;
}

int numoflines(FILE *fp) {
    int c;
    int lines = 0;
    while ((c = fgetc(fp)) != EOF) {
            if (c == '\n')
                lines++;
        }
    return lines;
}
#endif