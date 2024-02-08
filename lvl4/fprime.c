/*Assignment name  : fprime
Expected files   : fprime.c
Allowed functions: printf, atoi
--------------------------------------------------------------------------------

Write a program that takes a positive int and displays its prime factors on the
standard output, followed by a newline.

Factors must be displayed in ascending order and separated by '*', so that
the expression in the output gives the right result.

If the number of parameters is not 1, simply display a newline.

The input, when there's one, will be valid.

Examples:

$> ./fprime 225225 | cat -e
3*3*5*5*7*11*13$
$> ./fprime 8333325 | cat -e
3*3*5*5*7*11*13*37$
$> ./fprime 9539 | cat -e
9539$
$> ./fprime 804577 | cat -e
804577$
$> ./fprime 42 | cat -e
2*3*7$
$> ./fprime 1 | cat -e
1$
$> ./fprime | cat -e
$
$> ./fprime 42 21 | cat -e
$*/

#include <stdio.h>
#include <stdlib.h>

void fprime(int n)
{
	int i = 2;
	if (n == 1) //importante esta excepcion (te la dan los ejemplos)
		printf("1");
	while (i <= n)
	{
		if (n % i == 0) //si es primo
		{
			printf("%d", i); //imprimes numero
			if (n != i)    //imprimes '*' menos en el último
				printf("*");
			n /= i;         //divides el numero 
			i--;          // retrocedes uno para poder volver a imprimir el mismo número de nuevo 
		}
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
		fprime(atoi(av[1]));
	printf("\n");
	return 0;
}