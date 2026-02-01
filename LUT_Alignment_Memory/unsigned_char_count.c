#include <stdio.h>
#define NUMBERS 256

void BuildCountBitLUT(unsigned char arr[])
{
    int i = 0;

    for (i = 0; i < NUMBERS; ++i)
    {
        unsigned char n = (unsigned char)i;
        unsigned char count = 0;

        while (n != 0)
        {
            count += (unsigned char)(n & 1);
            n >>= 1;
        }

        arr[i] = count;
    }
}

int CountBit(unsigned char _num)
{
        static unsigned char countBitLUT[NUMBERS];
        static int flag;
        if (!flag)
        {
            BuildCountBitLUT(countBitLUT);
            flag = 1;
        }
    return countBitLUT[_num];
}

int main (void)
{
    int num_of_1;
    num_of_1 = CountBit(3);
    printf ("%d \n", num_of_1);
    return 0;
}





