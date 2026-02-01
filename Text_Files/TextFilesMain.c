#include <stdio.h>
#include "TextFiles.h"

int main(void)
{
    Q1_OpenAllModes();

    Q2_PersonsWriteRead();

    Q4_LastNLines("hello.txt", 3);

    Q6_CountWordFromControlFile("control.txt");

    return 0;
}
