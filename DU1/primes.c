/*
*   Soubor:     primes.c
*   Název:      Dú 1 IJC, a)
*   Autor:      Lukáš Kaprál - xkapra00
*   Fakulta:    Fakulta informačních technologií
*   Datum:      17.3.2021
*   Popis:      Zapíše posledních 10 prvočísel do pole, poté je vytiskne
*/

#include <stdio.h>
#include <stdlib.h>
#include "error.h"
#include "eratosthenes.h"
#include <time.h>

int main()
{
    bitset_alloc(pole, 200000000);
    Eratosthenes(pole);

    int count = 10;
    int arr[10] = {0};

    for (unsigned long i = bitset_size(pole) - 1; i > 1; i--)
    {
        if (bitset_getbit(pole, i) == 0)
        {
            arr[count - 1] = i;
            count--;
            if (count == 0)
            {
                break;
            }
        }
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", arr[i]);
    }
    clock_t start = clock();
    fprintf(stderr, "Time=%.3g\n", (double)(clock() - start) / CLOCKS_PER_SEC);
    bitset_free(pole);
    return 0;
}
