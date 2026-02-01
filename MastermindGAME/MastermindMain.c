#include <stdio.h>
#include "Mastermind.h"

int main(void)
{
    int code[CODE_SIZE];
    int guess[CODE_SIZE];
    int exact = 0;
    int partial = 0;

    GenerateCode(code);

    printf("=== Numbers Mastermind ===\n");

    while (exact != CODE_SIZE)
    {
        ReadGuess(guess);

        CheckGuess(code, guess, &exact, &partial);

        printf("Exact place: %d\n", exact);
        printf("Correct digit wrong place: %d\n\n", partial);
    }

    printf("Congratulations! You cracked the code!\n");

    return 0;
}
