/*Assignment name  : search_and_replace
Expected files   : search_and_replace.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program called search_and_replace that takes 3 arguments, the first 
arguments is a string in which to replace a letter (2nd argument) by
another one (3rd argument).

If the number of arguments is not 3, just display a newline.

If the second argument is not contained in the first one (the string)
then the program simply rewrites the string followed by a newline.

Examples:
$>./search_and_replace "Papache est un sabre" "a" "o"
Popoche est un sobre
$>./search_and_replace "zaz" "art" "zul" | cat -e
$
$>./search_and_replace "zaz" "r" "u" | cat -e
zaz$
$>./search_and_replace "jacob" "a" "b" "c" "e" | cat -e
$
$>./search_and_replace "ZoZ eT Dovid oiME le METol." "o" "a" | cat -e
ZaZ eT David aiME le METal.$
$>./search_and_replace "wNcOre Un ExEmPle Pas Facilw a Ecrirw " "w" "e" | cat -e
eNcOre Un ExEmPle Pas Facile a Ecrire $*/

#include <unistd.h>
// todo cambiado, a mi manera, FUNCIONA
void search_and_replace(char *str, char *se, char *re)
{
    int i = 0;
    if ((!se[1]) && (!re[1])) // CUIDADO, ES && no || (creo, el simulador da las dos bien)
    {
        while (str[i])
        {
            if (str[i] == se[0])
                str[i] = re[0];
            write(1, &str[i], 1);
            i++;
        }
    }
}

int main(int ac, char **av)
{
    if (ac == 4)
        search_and_replace(av[1], av[2], av[3]);
    write(1, "\n", 1);
    return 0;
}