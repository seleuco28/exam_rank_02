/*Assignment name  : rev_print
Expected files   : rev_print.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string, and displays the string in reverse
followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./rev_print "zaz" | cat -e
zaz$
$> ./rev_print "dub0 a POIL" | cat -e
LIOP a 0bud$
$> ./rev_print | cat -e
$*/

#include <unistd.h>
//ultima manera, FUNCIONANDO
void rev_print(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    i--;
    while (str[i])
    {
        write(1, &str[i], 1);
        i--;
    }
}

int main(int ac, char **av)
{
    if (ac == 2)
        rev_print(av[1]);
    write(1, "\n", 1);
    return 0;
}

/*
//a mi manera y también da bien
int ft_strlen(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return (i);
}

void rev_print(char *str)
{
    int len = (ft_strlen(str) - 1);
    while (str[len])
    {
        write(1, &str[len], 1);
        len--;
    }
}


int main(int ac, char **av)
{
    if (ac == 2)
        rev_print(av[1]);
    write(1, "\n", 1);
    return 0;
}
*/
/*
int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}


int		main(int ac, char **av)
{
	int len;

	if (ac == 2)
	{
		len = ft_strlen(av[1]);
		while (len--)
			write(1, &av[1][len], 1);
	}
	write(1, "\n", 1);
    return (0);
}*/
