/*Assignment name  : swap_bits
Expected files   : swap_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, swaps its halves (like the example) and
returns the result.

Your function must be declared as follows:

unsigned char	swap_bits(unsigned char octet);

Example:

  1 byte
_____________
 0100 | 0001
     \ /
     / \
 0001 | 0100*/

#include <unistd.h>
#include <stdio.h>

unsigned char   swap_bits(unsigned char octet)
{
    return ((octet >> 4) + (octet << 4));
}

int main() {
    unsigned char byte = 0x3A;  // 00111010 in binary
    printf("Original byte: 0x%X\n", byte);

    byte = swap_bits(byte);
    printf("Swapped byte: 0x%X\n", byte);

    return 0;
}

// PARECE QUE SI FUNCIONA, PORQUE AL COMPILAR EL MAIN, NOS DA QUE 0XA3 esta swappeado y haciendolo binario nos lo da hecho
