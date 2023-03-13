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

#include <stdio.h>
#include <unistd.h>


int contador(char c)
{
    int conteo;
    if (c >= 'a' && c <= 'z') 
        conteo = c - 'a' + 1;

    else if (c >= 'A' && c <= 'Z') 
        conteo = c - 'A' + 1;
    else
        conteo = 1;

    return (conteo);
}
// se puede hacer el main con int i = 0
int main(int ac, char **av)
{
    int retorno;
    int i = 0;
    if (ac == 2)
    {
        while(av[1][i])
        {
            retorno = contador(av[1][i]);
            while (retorno --)
                write(1, &av[1][i], 1); // aqui si necesitariamos el ampersan y EN EL MAIN DE ABAJO NO...
            i++;
        }
    }
    write(1, "\n", 1);
    return 0;

}

///////////////////////////////////////////////////////////////////////////

/*int main(int ac, char **av)
{
    int retorno;
    if (ac == 2)
    {
        while(*av[1])
        {
            retorno = contador(*av[1]);
            while (retorno --)
                write(1, av[1], 1);
            av[1]++;
        }
    }
    write(1, "\n", 1);
    return 0;

}*/