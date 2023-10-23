/*Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string and displays this string after rotating it
one word to the left.

Thus, the first word becomes the last, and others stay in the same order.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

Words will be separated by only one space in the output.

If there's less than one argument, the program displays \n.

Example:

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e
$
$>*/

#include <unistd.h>


//A MI MANERA Y FUNCIONA, (esta vez siiii)
void first_word(char *str, int begin_space)
{
	int i = begin_space;
	while (str[i] && (!(str[i] == ' ' || str[i] == '\t')))
	{
		write(1, &str[i], 1);
		i++;
	}
}

void rostring(char *str)
{
	int begin_space = 0;
	int i;
	while (str[begin_space] == ' ' || str[begin_space] == '\t')
		begin_space++;
	i = begin_space;
	while (str[i] && (!(str[i] == ' ' || str[i] == '\t'))) //me salto toda la primera palabra
		i++;
	while (str[i])
	{
		if (str[i] && (str[i - 1] == ' ' || str[i - 1] == '\t') && (!(str[i] == ' ' || str[i] == '\t')))
		{
			while (str[i] && (!(str[i] == ' ' || str[i] == '\t'))) // IMPORTANTISIMO PORNER Y QUE EXISTA!!
			{
				write(1, &str[i], 1);
				i++;
			}
			write(1, " ", 1);
		}
		i++;
	}
	first_word(str, begin_space);
}

int main(int ac, char **av)
{
	if (ac > 1) //el rostring asi da bien, antes lo tenia mal (comprobado por la máquina)
		rostring(av[1]);
	write(1, "\n", 1);
	return 0;
}


/*
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_space(char c)
{
	if ((c == ' ') || (c == '\t'))
		return (1);
	return (0);
}

void	ft_print_first_word(char *str, int begin_space)
{
	while (str[begin_space] != '\0' && !is_space(str[begin_space]))
	{
		ft_putchar(str[begin_space]);
		begin_space++;
	}
}

void	rostring(char *str)
{
	int	idx;
	int	begin_space;

	begin_space = 0;
	while (str[begin_space] != '\0' && is_space(str[begin_space]))
		begin_space++;
	idx = begin_space;
	while (str[idx] != '\0' && !is_space(str[idx])) 
		idx++; //aqui me quedo despues de la 1ra palabra
	while (str[idx] != '\0')
	{
		if (str[idx] != '\0' && !is_space(str[idx]) && is_space(str[idx - 1])) //si esta no es espacio y la anterior si
		{
			while (str[idx] != '\0' && !is_space(str[idx])) //printa mientras no sea espacio
			{
				ft_putchar(str[idx]);
				idx++;
			}
			ft_putchar(' '); //printa espacio
		}
		idx++;
	}
	ft_print_first_word(str, begin_space);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
		rostring(argv[1]);
	ft_putchar('\n');
	return (0);
}*/