#ifndef MASTERMIND_H
#define MASTERMIND_H

#define CODE_SIZE 4

/*
Description:
Generates a 4-digit secret code with no repeated digits.

Input:
int code[] - array that will store the generated code.

Output:
None.

Error:
None.
*/
void GenerateCode(int code[]);

/*
Description:
Reads a 4-digit guess from the user into an array.

Input:
int guess[] - array to store the user's guess.

Output:
None.

Error:
None.
*/
void ReadGuess(int guess[]);

/*
Description:
Checks how many digits are correct and in the correct place,
and how many digits are correct but in the wrong place.

Input:
int code[]  - the secret code.
int guess[] - the user's guess.
int *exact  - number of digits in the exact place.
int *partial - number of correct digits in wrong place.

Output:
None.

Error:
None.
*/
void CheckGuess(int code[], int guess[], int *exact, int *partial);

#endif
