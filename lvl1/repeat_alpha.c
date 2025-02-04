/*Assignment name  : repeat_alpha
Expected files   : repeat_alpha.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called repeat_alpha that takes a string and display it
repeating each alphabetical character as many times as its alphabetical index,
followed by a newline.

'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

Case remains unchanged.

If the number of arguments is not 1, just display a newline.

Examples:

$>./repeat_alpha "abc"
abbccc
$>./repeat_alpha "Alex." | cat -e
Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
$>./repeat_alpha 'abacadaba 42!' | cat -e
abbacccaddddabba 42!$
$>./repeat_alpha | cat -e
$
$>
$>./repeat_alpha "" | cat -e
$
$>*/

#include <unistd.h>
//última manera en la que lo he hecho FUNCIONA
void repeat_alpha(char *str)
{
    int i = 0;
    int contador;
    while (str[i])
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            contador = str[i] - 'a' + 1;
        else if (str[i] >= 'A' && str[i] <= 'Z')
            contador = str[i] - 'A' + 1;
        else 
            contador = 1;
        while (contador >= 1)
        {
            write(1, &str[i], 1);
            contador--;
        }
        i++;
    }
}

int main(int ac, char **av)
{
    if (ac == 2)
        repeat_alpha(av[1]);
    write(1, "\n", 1);
    return 0;
}
