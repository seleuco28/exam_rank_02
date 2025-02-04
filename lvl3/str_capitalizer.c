/*Assignment name  : str_capitalizer
Expected files   : str_capitalizer.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes one or several strings and, for each argument,
capitalizes the first character of each word (If it's a letter, obviously),
puts the rest in lowercase, and displays the result on the standard output,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string. If a word only has one letter, it must be
capitalized.

If there are no arguments, the progam must display \n.

Example:

$> ./str_capitalizer | cat -e
$
$> ./str_capitalizer "Premier PETIT TesT" | cat -e
Premier Petit Test$
$> ./str_capitalizer "DeuxiEmE tEST uN PEU moinS  facile" "   attention C'EST pas dur QUAND mEmE" "ALLer UN DeRNier 0123456789pour LA rouTE    E " | cat -e
Deuxieme Test Un Peu Moins  Facile$
   Attention C'est Pas Dur Quand Meme$
Aller Un Dernier 0123456789pour La Route    E $
$>*/



#include <unistd.h>
//ultima manera de hacerlo y me ha funcionado bien //abajo hay una parecida

void str_capitalizer(char *str)
{
	int i = 0;
	while (str[i]) //todo a minusculas
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	i = 0;
	while (str[i])
	{
		if (str[0] >= 'a' && str[0] <= 'z') //si primer char letra -= 32
			str[0] -= 32;
		if ((str[i - 1] == ' ' || str[i - 1] == '\t') && (str[i] >= 'a' && str[i] <= 'z'))//si anterior espacio y esta letra -= 32
			str[i] -= 32;
		write(1, &str[i], 1);
		i++;
	}
}

int main(int ac, char **av)
{
	int i = 1;
	if (ac == 1)
		write(1, "\n", 1);
	else
	{
		while (i <= (ac - 1)) //importante este -1
		{
			str_capitalizer(av[i]);
			write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}

/*
void str_capitalizer(char *str)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	i = 0; //aqui todo en minusculas
	if (str[i] >= 'a' && str[i] <= 'z') //si la primera es letra, escribemela en mayusculas
	{
		str[i] -= 32;
		write(1, &str[i], 1);
		i++;
	}
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z') && (str[i - 1] == ' ' || str[i - 1] == '\t')) //si letra y anterior espacio O tab (IMPORTANTE)
			str[i] -= 32;
		write(1, &str[i], 1);
		i++;
	}
}

int main(int ac, char **av)
{
	int i = 1;
	if (ac > 1)
	{
		while (i <= (ac - 1)) //chequear esto que aqui esta lo tricky del asunto
		{
			str_capitalizer(av[i]); //importante esto
			write(1, "\n", 1);
			i++;
		}
	}
	else
		write(1, "\n", 1);
	return 0;
}*/
