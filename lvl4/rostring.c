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

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int ft_isspace(char c)
{
	if (c == ' ' || c == '	')
		return (1);
	return (0);
}

void rostring(char *s)
{
	int flag = 0;
	while (ft_isspace(*s) && *s)
		s++;
	int i = -1;
	while (s[++i])
		i++;
	i = 0;
	while (!ft_isspace(s[i]) && s[i])
		i++;
	while (ft_isspace(s[i]) && s[i])
		i++;
	while (s[i])
	{
		if (!ft_isspace(s[i]))
		{
			while(!ft_isspace(s[i]) && s[i])
			{
				write(1, &s[i], 1);
				i++;
			}
			flag = 1;
			if (s[i])
				write(1, " ", 1);
		}
		while (ft_isspace(s[i]) && s[i])
			i++;
	}
	if (flag)
		write(1, " ", 1);
	i = 0;
	while(s[i] && !ft_isspace(s[i]))
		write(1, &s[i++], 1);
}

int main(int ac, char **av)
{
	if (ac > 1)
		rostring(av[1]);
	write(1, "\n", 1);
	return (0);
}
