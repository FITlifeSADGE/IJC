/*
*   Soubor:     tail.c
*   Název:      Dú 2 IJC, a)
*   Autor:      Lukáš Kaprál - xkapra00
*   Fakulta:    Fakulta informačních technologií
*   Datum:      15.4.2021
*   Popis:      Definuje možnosti volání funkce tail
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tail.h"
#define MAX_LEN 512

int main(int argc, char *argv[])
{
    FILE *fp;
    unsigned lines = 0;
    if (argc == 1)
    {
        lines = numoflines(stdin);
        printlines(stdin, lines);
        return 0;
    }
    if (argc == 2)
    {
        fp = fopen(argv[1], "r");
        if (fp == NULL)
        {
            fprintf(stderr, "tail: cannot open '%s' for reading: no such file or directory\n", argv[1]);
            return 0;
        }
        lines = numoflines(fp);
        printlines(fp, lines);
        fclose(fp);
        return 0;
    }
    if (argc == 3) {
        lines = numoflines(stdin);
        char *ptr;
        long ret;
        ret = strtol(argv[2], &ptr, 10);
        printf("%lu", ret);
        if (ret < 0) {
            fprintf(stderr, "tail: cannot display negative number of lines\n");
            return 0;
        }
        if (argv[2][0] == '+')
        {
            printmorelines(stdin, lines, ret);
        }
        else
        {
            printnumoflines(stdin, lines, ret);
        }
        return 0;
    }

    if (argc == 4)
    {
        char *ptr;
        long ret;

        ret = strtol(argv[2], &ptr, 10);
        if (ret < 0) {
            fprintf(stderr, "tail: cannot display negative number of lines\n");
            return 0;
        }
        fp = fopen(argv[3], "r");
        if (fp == NULL)
        {
            fprintf(stderr, "tail: cannot open '%s' for reading: no such file or directory\n", argv[3]);
            return 0;
        }
        lines = numoflines(fp);
        if (argv[2][0] == '+')
        {
            printmorelines(fp, lines, ret);
        }
        else
        {
            printnumoflines(fp, lines, ret);
        }
        return 0;
    }
    if (argc > 4) {
        fprintf(stderr, "tail: Error, neplatný počet argumentů\n");
        return 0;
    }
}