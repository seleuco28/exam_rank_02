/*Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.

The display will be in the order characters appear in the command line, and
will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void union_1(char *str1 , char *str2)
{
    // si te encuentras sin repetir la palabra escribela
    int i = 0;
    int ascii[256] = {0};
    while (str1[i])
    {
        if (ascii[(int)str1[i]] == 0)
        {
            ascii[(int)str1[i]] = 1;
            write(1, &str1[i], 1);
        }
        i++;
    }
    i = 0;
    while (str2[i])
    {
        if (ascii[(int)str2[i]] == 0)
        {
            ascii[(int)str2[i]] = 1;
            write(1, &str2[i], 1);                
        }
        i++;
    }


}

int main(int ac, char **av)
{
    if (ac == 3)
        union_1(av[1], av[2]);
    write(1, "\n", 1);
    return 0;
}