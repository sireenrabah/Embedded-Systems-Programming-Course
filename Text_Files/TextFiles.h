#ifndef TEXTFILES_H
#define TEXTFILES_H

/*
Description:
  Opens a file with several fopen modes and checks if fopen returned NULL.

Input:
  None

Output:
  Prints "OK" or "NULL" for each mode.

Error:
  If file cannot be created at the start, prints an error and stops.
*/
void Q1_OpenAllModes(void);


/*
Description:
  Builds 5 person records, writes them to a text file, closes it,
  opens again, reads all persons and prints them.

Input:
  None

Output:
  Prints all persons read from the file.

Error:
  Prints error if file cannot be opened for writing or reading.
*/
void Q2_PersonsWriteRead(void);


/*
Description:
  Prints the last N lines of a text file (simple version).
  Limitation: supports up to 200 lines, each line up to 200 chars.

Input:
  filename - file name to read
  n        - number of last lines to print

Output:
  Prints the last N lines to screen.

Error:
  Prints error if file cannot be opened or if n <= 0.
*/
void Q4_LastNLines(const char* filename, int n);


/*
Description:
  Reads control file containing:
    <targetFile> <word>
  Then counts how many times the word appears in the target file.

Input:
  controlFilename - file name with 2 tokens (targetFile and word)

Output:
  Prints:
    In file X the word Y appeared Z times

Error:
  Prints error if control file cannot be opened,
  or if target file cannot be opened,
  or if control file format is invalid.
*/
void Q6_CountWordFromControlFile(const char* controlFilename);

#endif
