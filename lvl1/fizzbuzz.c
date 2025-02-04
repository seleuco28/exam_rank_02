/*Assignment name  : fizzbuzz
Expected files   : fizzbuzz.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that prints the numbers from 1 to 100, each separated by a
newline.

If the number is a multiple of 3, it prints 'fizz' instead.

If the number is a multiple of 5, it prints 'buzz' instead.

If the number is both a multiple of 3 and a multiple of 5, it prints 'fizzbuzz' instead.

Example:

$>./fizzbuzz
1
2
fizz
4
buzz
fizz
7
8
fizz
buzz
11
fizz
13
14
fizzbuzz
[...]
97
98
fizz
buzz
$>*/
#include <unistd.h>
#include <stdio.h>

void ft_putnbr(int i)
{
	int iauxiliar;
	char numero;

	iauxiliar = i; //cuidado, si lo pongo al reves (i = iauxiliar) me falla!!
	if (i > 9) //esto es un if no un while
	{
		iauxiliar = i % 10; //poner esto al reves da fallo
		i = i / 10;			//poner esto al reves da fallo
		ft_putnbr(i);
	}
	numero = iauxiliar + '0';
	write(1, &numero, 1);
}

int main(void)
{
	int i;

	i = 1;
	while (i <= 100)
	{
		if( (i % 3) == 0 && (i % 5) == 0)
			write(1, "fizzbuzz", 8);
		else if (i % 3 == 0)
			write (1, "fizz", 4 );
		else if (i % 5 == 0)
			write(1, "buzz", 4);
		else
			ft_putnbr(i);
		write (1, "\n", 1);
		i++;
	}
	return (0);
}
