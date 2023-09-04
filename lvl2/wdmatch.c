/*
Assignment name  : wdmatch
Expected files   : wdmatch.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and checks whether it's possible to
write the first string with characters from the second string, while respecting
the order in which these characters appear in the second string.

If it's possible, the program displays the string, followed by a \n, otherwise
it simply displays a \n.

If the number of arguments is not 2, the program displays a \n.

Examples:

$>./wdmatch "faya" "fgvvfdxcacpolhyghbreda" | cat -e
faya$
$>./wdmatch "faya" "fgvvfdxcacpolhyghbred" | cat -e
$
$>./wdmatch "quarante deux" "qfqfsudf arzgsayns tsregfdgs sjytdekuoixq " | cat -e
quarante deux$
$>./wdmatch "error" rrerrrfiiljdfxjyuifrrvcoojh | cat -e
$
$>./wdmatch | cat -e
$
*/

#include <unistd.h>

//a mi manera y funciona
void ft_putstr(char *str)
{
	int i = 0;

	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void wdmatch(char *str1, char *str2)
{
	int i = 0;
	int j = 0;

	while (str2[j])
	{
		if (str1[i] == str2[j])
			i++;
		j++;
	}
	if (!str1[i]) //importante esto!!!
		ft_putstr(str1);
}

int main(int ac, char **av)
{
	if (ac == 3)
		wdmatch(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}
/*
void ft_putstr(char const *str)
{
    int i;
    i = 0;

    while(str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}
// CON MAIN + FUNCIÓN

void wdmatch(char *str1, char *str2)
{
    int i = 0;
    int j = 0;

    while (str2[j])
    {
        if (str2[j] == str1[i])
            i++;
        j++;
    }
    if (!str1[i])
        ft_putstr(str1);
}


int main(int ac, char **av)
{
    if (ac == 3)
        wdmatch(av[1], av[2]);
    write(1, "\n", 1);
    return (0);
}*/


// EN EL MAIN TODO, PREFIERO HACERLO CON UNA FUNCION SEPARADA
/*
int main(int ac, char **av)
{
    int i;
    int j;
    
    i = 0;
    j = 0;

    if (ac == 3)
    {
        while (av[2][j])
        {
            if (av[2][j] == av[1][i])
                i++;
            j++;
        }
        if (!av[1][i])
            ft_putstr(av[1]);
    }
    write (1, "\n", 1);
    return (0);
}*/