/*Assignment name  : reverse_bits
Expected files   : reverse_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, reverses it, bit by bit (like the
example) and returns the result.

Your function must be declared as follows:

unsigned char	reverse_bits(unsigned char octet);

Example:

  1 byte
_____________
 0010  0110
	 ||
	 \/
 0110  0100*/

#include <stdio.h>
#include <unistd.h>

///////////////////////// EXPLICACION //////////////////////////////////
/**********************************************************************
** 1st Method, for mortals like us ;)
***********************************************************************
** 1) As a byte is equal to 8 it means we will do it while (byte_len--)
**
** 2) We first check if b as a bit on the extreme right with (b & 1);
** if so we light bit 1 on r and move it juste 1 bit on the left by
** multiplying r by 2 with (r << 1)
**
** For novices: r = (r << 1) | (b & 1) might be easier to understand as:
**
**		if (b % 2)           | (b & 1)
**			r = r + 1         
**		r *= 2;              (r << 1) 
**
** 3) Then we divide our unsigned char b by 2 to erase
** the bit located on the extreme right of the variable b.
** For reminder b >>= 1; is equivalent to b /= 2;
*/



unsigned char reverse_bits(unsigned char octet)
{
	// PASA ALGO SI LE QUITO LOS DOS UNSIGNED¿?¿
	unsigned char	c = 0; //declaro variable y la inicializo a 0
	unsigned int byte_len = 8; //esta lleva la cuenta de los bits que quedan (es el int i)

	while (byte_len--) //bucle de 8
	{
		c = (c << 1) | (octet & 1); //pilla el valor y lo desplaza  a la izda
		octet >>= 1; //te mueves al siguiente valor de octet (se va /2)
	}
	return (c);
}

/*
** Test program : . (equal to 046 in ASCII table, 00101110 in binary)
** becomes t (116 in ASCII table, 01110100 in binary).
** byte 00101110 ('.') is indeed the reverse of byte 01110100 ('t').
*/


int	main(void)
{
	unsigned char c;

	c = '.';
	write(1, &c, 1);
	write(1, "\n", 1);
	c = reverse_bits(c);
	write(1, &c, 1);
	return (0);
}