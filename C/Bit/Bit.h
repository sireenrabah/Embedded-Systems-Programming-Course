#ifndef __BIT1_H__
#define __BIT1_H__
#include <string.h>
#include <stdio.h>
#define ERORR 0xFF

void printBinary(unsigned char x);
int count_Bits(unsigned char ch);
int count_BitsSIGNED(signed char chr);
unsigned char reverseBits(unsigned char x);
unsigned char invertBits(unsigned char x1);
unsigned char rotate_Right(unsigned char x, int n);
unsigned char setbits(unsigned char x, int p, int n, unsigned char y);
unsigned char* compress_no_bitfield(unsigned char *s, unsigned int *out_len);


#endif