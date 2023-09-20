/*

Assignment name  : hidenp
Expected files   : hidenp.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program named hidenp that takes two strings and displays 1
followed by a newline if the first string is hidden in the second one,
otherwise displays 0 followed by a newline.

Let s1 and s2 be strings. We say that s1 is hidden in s2 if it's possible to
find each character from s1 in s2, in the same order as they appear in s1.
Also, the empty string is hidden in any string.

If the number of parameters is not 2, the program displays a newline.

Examples :

$>./hidenp "fgex.;" "tyf34gdgf;'ektufjhgdgex.;.;rtjynur6" | cat -e
1$
$>./hidenp "abc" "2altrb53c.sse" | cat -e
1$
$>./hidenp "abc" "btarc" | cat -e
0$
$>./hidenp | cat -e
$
$>*/

#include <stdio.h>
#include <unistd.h>

//a mi manera FUNCIONA
void hidenp(char *str1, char *str2) 
{
	int i = 0;
	int j = 0;

	while (str2[j])
	{
		if (str1[i] == str2[j])
			i++;
		j++;
	}
	if (str1[i]) // IMPORTANTE ESTO, parecido a wdmatch
		write(1, "0", 1);
	else if (!str1[i])
		write(1, "1", 1);
}

int main(int ac, char **av)
{
	if (ac == 3)
		hidenp(av[1], av[2]);
	write(1, "\n", 1);
	return 0;
}

/*
int hidenp(char *s1, char *s2)
{
	int i = 0;
	int j = 0;

	while (s1[i])
	{
		while (s2[j])
		{
			if (s2[j] == s1[i])
			{
				i++;
			}
			j++;
		}
		if (s1[i]) //si sigue quedando string es que no ha coincidido por completo
			return (0);
	}
	return (1);
}

int main(int ac, char **av)
{
	char c; //mucho cuidado porque hay que escribirlo asi!!! si haces un write se vuelve loco
	if (ac == 3)
	{
		c = hidenp(av[1], av[2]) + '0'; // + 48 para pasarlo de int a char
		write(1, &c, 1);
	}
	write(1, "\n", 1);
	return (0);
}*/
