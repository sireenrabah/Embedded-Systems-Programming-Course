 #include "Bit.h"
 
int main() {
    unsigned char u = 7;
    signed char s = -84;  
    printf("Unsigned char 0x%X has %d bits ON\n", u, count_Bits(u));
    printf("Signed char %d has %d bits ON\n", s, count_BitsSIGNED(s));
    
    unsigned char x = 13;    /*  00001101 */
    unsigned char r= reverseBits(x);
    printf("Original value: %u\n", x);
    printf("Reversed bits value: %u\n", r);

   
    unsigned char x1 = 0xCC;// 11001100
    printf("result of invert function in binary \n");
    invertBits(x1);

    unsigned char x3 = 0xA7;  // 10100111
    int n = 3;
    unsigned char y = rotate_Right(x3, n);
    printf("x rotated by %d = ", n);
    printBinary(y);
    printf(" (binary)\n");

    unsigned char x5 = 170;   // 10101010
    unsigned char y1 = 167;   // 10100111
    int n1 = 3;
    int p = 6;
    unsigned char x4 = setbits(x5, p, n1, y1);
    printf("setbits n = %d, p = %d gives x = ", n, p);
    printBinary(x4);
    printf(" (binary)\n");


    unsigned char sr[] = "abcde";
    unsigned int packed_len;
    unsigned char *packed = compress_no_bitfield(sr, &packed_len);
    unsigned int i;
    printf("packed length = %u\n", packed_len);
    printf("packed bytes: ");

    for (i = 0; i < packed_len; i++)
    {
        printf("%02X ", packed[i]);  /* הדפסה בהקסה */
    }

    printf("\n");
  
    return 0;
}

 