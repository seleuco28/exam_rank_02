/*Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>*/

#include <unistd.h>
#include <stdio.h>


void ft_putnbr(int i)
{
	int iauxiliar;
	char numero;

	iauxiliar = i;
	if (i > 9)
	{
		iauxiliar = i % 10;
		i /= 10;
		ft_putnbr(i);
	}
	numero = iauxiliar + '0';
	write(1, &numero, 1);
}

int ft_atoi(const char *str)
{
	int signo;
	int resultado;
	signo = 1;
	resultado = 0;
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '-')
		signo = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		resultado = resultado * 10 + (*str - '0');
		str++;
	}
	return (signo * resultado);
}

int is_prime(int n)
{
	int i = 2;
	if (n < 2) //IMPORTANTE ESTO
		return (0);
	while (i < n) //esto no puede ser igual que...
	{
		if (n % i == 0)
			return 0;
		i++;
	}
	return 1;
}

void add_prime_sum(int n)
{
	int i = 2;
	int numerin = 0;
	while (i <= n)
	{
		if (is_prime(i))
			numerin += i;
		i++;
	}
	ft_putnbr(numerin);

}

int main(int ac, char **av)
{
	if ((ac != 2) || (ft_atoi(av[1]) < 0)) //argumentos diferentes a 1 Y argumentos no positivos IMPORANTE LO DICE EL ENUNCIADO!!!
		write(1, "0", 1);
	else
		add_prime_sum(ft_atoi(av[1]));
	write(1, "\n", 1);
	return 0;
}