/*Assignment name  : inter
Expected files   : inter.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.

The display will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Examples:

$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "rien" "cette phrase ne cache rien" | cat -e
rien$
$>./inter | cat -e
$*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void inter(char *str1, char *str2)
{
    int i;
    //poner estas llaves
    int ascii[256] = {0}; //hacemos una tabla ascii y la rellenamos de ceros

    i = 0;
    while (str2[i])
    {
        if (ascii[(int)str2[i]] == 0) // si es la 1ra vez que lo ves hazlo un uno
            ascii[(int)str2[i]] = 1;
        i++;
    }
    // saliendo de esto ascii ya tiene valores con unos y con zeros (unos los no repetidos)

    i = 0;
    while (str1[i])
    {
        if (ascii[(int)str1[i]] == 1) //si te encuentras con un 1 es que estaba arriba y lo escribes
        {
            ascii[(int)str1[i]] = 2; //esta linea es para que no se repitan las letras del str1
            write(1, &str1[i], 1);
        }
        i++;
    }
}

int main(int ac, char **av)
{
	if (ac == 3)
		inter(av[1], av[2]);
	write (1, "\n", 1);
	return (0);
}