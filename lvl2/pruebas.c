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

 #include <unistd.h>
 #include <stdio.h>

unsigned char reverse_bits(unsigned char octet)
{
    unsigned char r = 0;
    unsigned char byte_len = 8;

    while (byte_len--)
    {
        r = (r << 1) | (octet & 1);
        octet >>= 1;
    } 
    return (r);
}

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