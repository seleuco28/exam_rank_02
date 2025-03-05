/*Assignment name  : rev_wstr
Expected files   : rev_wstr.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string as a parameter, and prints its words in 
reverse order.

A "word" is a part of the string bounded by spaces and/or tabs, or the 
begin/end of the string.

If the number of parameters is different from 1, the program will display 
'\n'.

In the parameters that are going to be tested, there won't be any "additional" 
spaces (meaning that there won't be additionnal spaces at the beginning or at 
the end of the string, and words will always  be separated by exactly one space).

Examples:

$> ./rev_wstr "le temps du mepris precede celui de l'indifference" | cat -e
l'indifference de celui precede mepris du temps le$
$> ./rev_wstr "abcdefghijklm"
abcdefghijklm
$> ./rev_wstr "il contempla le mont" | cat -e
mont le contempla il$
$> ./rev_wstr | cat -e
$
$>*/

#include <unistd.h>

void rev_wstr(char *str)
{
	int i = 0;
	int start;
	int end;
	int flag;

	while (str[i])
		i++;
	i--;
	while (i >= 0)
	{
		if (str[i] == ' ' || str[i] == '\t') //si espacio salta
			i--;
		end = i;
		while (str[i] && (!(str[i] == ' ' || str[i] == '\t')))
			i--;
		start = i + 1;
		flag = start;
		while (start <= end)
		{
			write(1, &str[start], 1);
			start++;
		}
		if (flag != 0)
			write(1, " ", 1);
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
		rev_wstr(av[1]);
	write(1, "\n", 1);
	return 0;
}