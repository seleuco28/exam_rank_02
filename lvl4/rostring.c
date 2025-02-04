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

void first_word(char *str)
{
    int i = 0;
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    while (str[i] && (!(str[i] == ' ' || str[i] == '\t')))
    {
        write(1, &str[i], 1);
        i++;
    }
}

void rostring(char *str)
{
    int i = 0;
    while (str[i] == ' ' || str[i] == '\t') //me salto los PRIMEROS espacios
        i++;
    while (str[i] && (!(str[i] == ' ' || str[i] == '\t'))) //me salto la primera palabra
        i++;
    while (str[i])
    {
        if ((str[i - 1] == ' ' || str[i - 1] == '\t') && (!(str[i] == ' ' || str[i] == '\t'))) //si anterior espacio y ahora palabra
        {
            while (str[i] && (!(str[i] == ' ' || str[i] == '\t'))) //IMPORTANTE ESTE QUE EXISTA!!
            {
                write(1, &str[i], 1);
                i++;
            }
            write(1, " ", 1);
        }
        i++;
    }
    first_word(str);
}

int main(int ac, char **av)
{
    if (ac > 1) //MUCHO OJO AQUI, no es como los ejercicios normales LEER EL ENUNCIADO
        rostring(av[1]);
    write(1, "\n", 1);
    return 0;
}

/*
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
	while (str[begin_space] == ' ' || str[begin_space] == '\t') //me salto los espacios
		begin_space++;
	i = begin_space;
	while (str[i] && (!(str[i] == ' ' || str[i] == '\t'))) //me salto toda la primera palabra
		i++;
	while (str[i])
	{
		if (str[i] && (str[i - 1] == ' ' || str[i - 1] == '\t') && (!(str[i] == ' ' || str[i] == '\t'))) //si: 1-existe 2- anterior espacio 3- palabra
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
}*/