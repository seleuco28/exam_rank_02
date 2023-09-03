/*Assignment name  : print_hex
Expected files   : print_hex.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a positive (or zero) number expressed in base 10,
and displays it in base 16 (lowercase letters) followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./print_hex "10" | cat -e
a$
$> ./print_hex "255" | cat -e
ff$
$> ./print_hex "5156454" | cat -e
4eae66$
$> ./print_hex | cat -e
$*/

#include <stdio.h>
#include <unistd.h>

int atoi_simple(char *s)
{
	int sum = 0;

	while (*s)
	{
		sum = sum * 10 + *s - '0';
		s++;
	}
	return (sum);
}

void putnbr_hex(int i)
{
	char s[16] = "0123456789abcdef";

	char c;
	if (i > 16)
	{
		c = s[i % 16];
		i = i / 16;
		putnbr_hex(i);
		write(1, &c, 1);
	}
	else 
	{
		c = s[i % 16];
		write(1, &c, 1);
	}
}

void print_hex(char *s)
{
	int num = atoi_simple(s);
	putnbr_hex(num);
}

int main(int ac, char **av)
{
	if (ac == 2)
		print_hex(av[1]);
	write(1, "\n", 1);
	return(1);
}