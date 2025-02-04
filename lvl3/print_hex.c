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

int atoi_simple(char *str)
{
	int resultado = 0; // importante no inicializarlo como char
	int signo = 1;
	while (*str == '-' || *str == '\t')
		str++;
	if (*str == '-')
		signo = -1;
	while (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		resultado = resultado * 10 + *str - '0';
		str++;
	}
	return (signo * resultado);
}

//es una especie de ft_putnbr pero en hexadecimal
void print_hex(int i) //FALLO-CUIDADO, al meter el atoi, de parámetro meto int i
{
	char base[16] = "0123456789abcdef";
	char numero; // he fallado antes inicializandolo como int CUIDADO!!
	
	if (i >= 16) //ojo aqui que si no pones el igual el num 16 te da mal!!
	{
		numero = base[i % 16]; // lo correspondiente al resto, de la base
		i = i / 16;
		print_hex(i);	
	}
	else
		numero = base[i % 16];

	write(1, &numero, 1); //pongo el write abajo de los dos
}


int main(int ac, char **av)
{
	if (ac == 2)
		print_hex(atoi_simple(av[1]));
	write(1, "\n", 1);
	return(0);
}