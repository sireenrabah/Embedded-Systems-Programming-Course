 #include "Bit.h"


void printBinary(unsigned char x)
{
    for (int i = 7; i >= 0; i--) {
        printf("%d", (x >> i) & 1);
    }
}

int count_Bits(unsigned char ch)
{
    int count = 0;
    for (int i = 0; i < 8; i++) {
        if (ch & (1 << i)) {  
            count++;
        }
    }
    return count;


}

int count_BitsSIGNED(signed char chr)
{
    int count = 0;
    unsigned char temp = (unsigned char)chr;  
    for (int i = 0; i < 8; i++) {
        if (temp & (1 << i)) {
            count++;
        }
    }
    return count;
}

/* 
 * Reverses the bits of an unsigned char (8 bits)
 * Example: 00001101 -> 10110000
 */
unsigned char reverseBits(unsigned char x)
{
    unsigned char result = 0;
    int i;

    for (i = 0; i < 8; i++)
    {
        result <<= 1;        /* Shift result left */
        result |= (x & 1);   /* Copy the most right (lsb) bit of x */
        x >>= 1;             /* Shift x right to process next bit */
    }

    return result;
}

unsigned char invertBits(unsigned char x1)
{ 
    unsigned char y;
    y = ~x1;

 printBinary(y);
 printf(" \n");

}

/*x = 10100111 
n = 3        

 מזיזים ימינה ב‑n ביטים: 
x >> n = 00010100

 מחזירים את הביטים שנחתכו מימין לצד שמאל: 
x << (8 - n) = 11100000

 מחברים את שני החלקים עם OR: 
   00010100
|  11100000
-------------
   11110100      (התוצאה הסופית לאחר Rotate Right)*/
unsigned char rotate_Right(unsigned char x, int n)
{
    n = n % 8;                  // מניעת סיבוב מיותר
    return (x >> n) | (x << (8 - n));

}


unsigned char setbits(unsigned char x, int p, int n, unsigned char y)
{
    unsigned char y_rightmost;
    unsigned char clearp;

    if(p<n){

      return  ERORR;
    }
    y_rightmost = y & ((1 << n) - 1);
    y_rightmost = y_rightmost << (p - n );
    clearp =((1 << n) - 1) << (p - n);
    clearp= ~clearp;
    x= x & clearp;
    x |= y_rightmost;
    return x;



}


unsigned char* compress_no_bitfield(unsigned char *s, unsigned int *out_len)
{
    unsigned int len;
    unsigned int i = 0;   /* index in original string */
    unsigned int j = 0;   /* index in packed bytes */
    unsigned char pad = 0x0F; /* padding if odd length */

    if (s == NULL || out_len == NULL)
        return NULL;

    len = (unsigned int)strlen((const char *)s);

    while (i < len)
    {
        unsigned char first = (unsigned char)(s[i] - 'a'); /* 0..14 */
        unsigned char second = pad;

        if (i + 1 < len)
            second = (unsigned char)(s[i + 1] - 'a');

        s[j] = (unsigned char)((first << 4) | (second & 0x0F));

        i += 2;
        j += 1;
    }

    *out_len = j;
    return s;
}
    




