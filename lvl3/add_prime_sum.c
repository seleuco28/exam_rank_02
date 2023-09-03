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

int ft_atoi(const char *str)
{
    int signo;
    int resultado;

    signo = 1;
    resultado = 0;

    while (*str == 32 || (*str >= 9 && *str <= 13))
        str++;
    if (*str == '-')
        signo = -1;
    if (*str == '-' || *str == '+')
        str++;
    while (*str >= '0' && *str <= '9')
    {
        resultado = resultado * 10 + *str - '0';
        str++;
    }
    return (signo * resultado);
}

int is_prime(int num)
{
	int i = 1;

	if ( num == 2)
		return (1);
	while (++i < num)
	{
		if (num % i == 0) //no seria primo
			return (0);
	}
	return (1);
}

void	add_prime_sum(int n)
{
	int	i;
	int	count;

	count = 0;
	if (n == 1)
		count = 1;
	i = 1;
	while (++i <= n)
		if (is_prime(i))
			count += i; //lo que habia mas 'i'
	ft_putnbr(count);
}

int main(int ac, char **av)
{
	if (ac == 2)
        add_prime_sum(ft_atoi(av[1]));
	else
		write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}