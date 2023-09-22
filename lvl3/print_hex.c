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

void print_hex(int i)
{
	char base[16] = "0123456789abcdef";

	char c;
	if (i >= 16) //ojo aqui que si no pones el igual el num 16 te da mal!!
	{
		c = base[i % 16];
		i = i / 16;
		print_hex(i);
		write(1, &c, 1); //EL WRITE SIEMPRE LO ULTIMO!!	
	}
	else 
	{
		c = base[i % 16];
		write(1, &c, 1);
	}
}


int main(int ac, char **av)
{
	if (ac == 2)
		print_hex(atoi_simple(av[1]));
	write(1, "\n", 1);
	return(0);
}