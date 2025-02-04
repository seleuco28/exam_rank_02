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
$*/

// a mi manera funcionando
#include <unistd.h>

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
    //no poner aqui el i = 0 porque no printa nada HE FALLADO EN ESTO
    if (!str1[i])
    {
        i = 0; // IMPORTANTE  poner el i = 0; aquí dentro
        while (str1[i])
        {
            write(1, &str1[i], 1);
            i++;
        }
    }
}

int main(int ac, char **av)
{
    if (ac == 3)
        wdmatch(av[1], av[2]);
    write(1, "\n", 1);
    return 0;
}
