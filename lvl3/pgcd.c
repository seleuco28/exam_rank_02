/*Assignment name  : pgcd
Expected files   : pgcd.c
Allowed functions: printf, atoi, malloc, free
--------------------------------------------------------------------------------

Write a program that takes two strings representing two strictly positive
integers that fit in an int.

Display their highest common denominator followed by a newline (It's always a
strictly positive integer).

If the number of parameters is not 2, display a newline.

Examples:

$> ./pgcd 42 10 | cat -e
2$
$> ./pgcd 42 12 | cat -e
6$
$> ./pgcd 14 77 | cat -e
7$
$> ./pgcd 17 3 | cat -e 
1$
$> ./pgcd | cat -e
$*/



#include <stdio.h>
#include <unistd.h>

int atoi_simple(char *s) //esto es una especie de atoi simplificado
{
	int resultado = 0; //hay que inicializarlo a 0 sino te da fallo

	while (*s)
	{
		resultado = resultado * 10 + *s - '0';
		s++;
	}
	return (resultado);
}

void ft_putnbr(int i)
{
	int iauxiliar;
	char numero;

	iauxiliar = i;
	if (i > 9)
	{
		iauxiliar = i % 10;
		i = i / 10;
		ft_putnbr(i);

	}
	numero = iauxiliar + 48;
	write(1, &numero, 1);
}

void pgcd(char *s1, char *s2) // ATENCION, ESTOS DOS ARGUMENTOS NO PUDEN SER INT PORQUE EN EL MAIN SON CHAR **AV
{
	int i = atoi_simple(s1);
	int j = atoi_simple(s2);
	int aux = 1; //
	int gcd = 1; //greatest common denominator, la variable que imprimiremos

	while (aux <= j || aux <= i)
	{
		if (j % aux == 0  && i % aux == 0)
			gcd = aux;
		aux++;
	}
	
	ft_putnbr(gcd);
}

int main(int ac, char **av)
{
	if (ac == 3)
		pgcd(av[1], av[2]);
	write(1, "\n", 1);
	return(0);
}