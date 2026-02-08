#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Mastermind.h"

void GenerateCode(int code[])
{
    int i, j, digit;
    int used[10] = {0};

    srand(time(NULL));

    for (i = 0; i < CODE_SIZE; i++)
    {
        do
        {
            digit = rand() % 10;
        } while (used[digit]);

        code[i] = digit;
        used[digit] = 1;
    }
}

void ReadGuess(int guess[])
{
    int i;
    printf("Enter 4 digits (no spaces): ");

    for (i = 0; i < CODE_SIZE; i++)
    {
        scanf("%1d", &guess[i]);
    }
}
void CheckGuess(int code[], int guess[], int *exact, int *partial)
{
    int i, j;
    int usedCode[CODE_SIZE] = {0};
    int usedGuess[CODE_SIZE] = {0};

    *exact = 0;
    *partial = 0;

    /* First pass: exact matches */
    for (i = 0; i < CODE_SIZE; i++)
    {
        if (guess[i] == code[i])
        {
            (*exact)++;
            usedCode[i] = 1;
            usedGuess[i] = 1;
        }
    }

    /* Second pass: partial matches (correct digit, wrong place) */
    for (i = 0; i < CODE_SIZE; i++)
    {
        if (usedGuess[i]) /* already counted as exact */
        {
            continue;
        }

        for (j = 0; j < CODE_SIZE; j++)
        {
            if (!usedCode[j] && guess[i] == code[j])
            {
                (*partial)++;
                usedCode[j] = 1;
                break; /* stop searching for this guess digit */
            }
        }
    }
}
