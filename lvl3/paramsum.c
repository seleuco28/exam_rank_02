/*Assignment name  : paramsum
Expected files   : paramsum.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays the number of arguments passed to it, followed by
a newline.

If there are no arguments, just display a 0 followed by a newline.

Example:

$>./paramsum 1 2 3 5 7 24
6
$>./paramsum 6 12 24 | cat -e
3$
$>./paramsum | cat -e
0$
$>*/

#include <stdio.h>
#include <unistd.h>

//a mi manera con ft_putnbr() que funciona

void ft_putnbr(int i)
{
	char numero;
	int iauxiliar;

	iauxiliar = i;

	if (i > 9)
	{
		iauxiliar = i % 0;
		i = i / 10;
		ft_putnbr(i);
	}
	numero = iauxiliar + '0';
	write(1, &numero, 1);
}

int main(int ac, char **av)
{
	if (ac == 1)
		write(1, "0", 1);
	else
		ft_putnbr(ac - 1);
	write(1, "\n", 1);
	return 0;
}

/*
void get_num(int num)
{
	char c;
	
	if (num > 9)
	{
		c = num % 10 + '0';
		num = num / 10;
		get_num(num);
		write(1, &c, 1);
	}
	else
	{
		c = num + '0';
		write(1, &c, 1);
	}
}

int main(int ac, char **av)
{
	get_num(ac - 1);
	write(1, "\n", 1);
}*/