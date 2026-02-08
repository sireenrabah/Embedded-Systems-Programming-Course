#include <stdio.h>

#define LUT_SIZE 256
#define NUM_OF_BYTES 4

/*ספירת ביטים בבייט*/
void BuildCountBitLUT8(unsigned char lut[])
{
    for (int i = 0; i < LUT_SIZE; i++)
    {
        unsigned char n = (unsigned char)i;
        unsigned char count = 0;

        while (n)
        {
            count += n & 1;
            n >>= 1;
        }

        lut[i] = count;
    }
}


int CountBit(unsigned int num)
{
    static unsigned char lut[LUT_SIZE];
    static int initialized = 0;

    if (!initialized)
    {
        BuildCountBitLUT8(lut);
        initialized = 1;
    }

    return  lut[num & 0xFF] +
            lut[(num >> 8) & 0xFF] +
            lut[(num >> 16) & 0xFF] +
            lut[(num >> 24) & 0xFF];
}

int main(void)
{
    unsigned int x = 29; /* 00011101 → 4 ביטים דלוקים */

    printf("Number: %u\n", x);
    printf("Bit count: %d\n", CountBit(x));

    return 0;
}
