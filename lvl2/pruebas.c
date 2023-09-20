
#include <unistd.h>

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char r = 0;
	int byte_len = 8;

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