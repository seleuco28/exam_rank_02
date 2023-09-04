/*Assignment name  : last_word
Expected files   : last_word.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays its last word followed by a \n.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or there are no words, display a newline.

Example:

$> ./last_word "FOR PONY" | cat -e
PONY$
$> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
not$
$> ./last_word "   " | cat -e
$
$> ./last_word "a" "b" | cat -e
$
$> ./last_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

//HECHO POR MI FUNCIONANDO
int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

void last_word(char *str)
{
	int len = ft_strlen(str) - 1;


	while (str[len] == ' ')
		len--;
	while (str[len] != ' ')
		len--;
	len++;
	while (str[len] != ' ' && str[len]) // IMPORTANTISIMO ESTET "Y QUE EXISTA" llevo toda la mañañana peleandome con eso
	{
		write(1, &str[len], 1);
		len++;
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
		last_word(av[1]);
	write(1, "\n", 1);
	return (0);
}

/*
// ATENCION, HECHO POR MI Y FUNCIONA, PERO HAY QUE TENER EN CUENTA MUCHO LOS LENS!!

void ft_last_word(char *str)
{
	int len = 0;

	while (str[len])
		len++;
	len--; //para que nos quede con los caracteres imprimibles
	while (str[len] == 32 || str[len] == 9)
		len--;
	while (str[len] >= 33 && str[len] <= 126)
		len--; //aqui nos pasariamos una
	len++;
	while (str[len] >= 33 && str[len] <= 126)
	{
		write(1, &str[len], 1);
		len++;
	}
}


int main(int ac, char **av)
{
	if (ac == 2)
		ft_last_word(av[1]);
	write(1, "\n", 1);
	return (0);
}
*/


/*
void	last_word(char *str)
{
	int	j = 0;
	int i = 0;

	while (str[i])
	{
		if (str[i] == ' ' && str[i + 1] >= 33 && str[i + 1] <= 126) //si hay espacio y la siguiente es letra j algo
			j = i + 1; // j sera el ultimo espacio + 1
		i++;
	}
	while (str[j] >= 33 && str[j] <= 126) //si estas aqui escribe que estas en la última palabra
	{
		write(1, &str[j], 1);
		j++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		last_word(argv[1]);
	write(1, "\n", 1);
	return (0);
} */
