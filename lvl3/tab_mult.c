/*Assignment name  : tab_mult
Expected files   : tab_mult.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays a number's multiplication table.

The parameter will always be a strictly positive number that fits in an int,
and said number times 9 will also fit in an int.

If there are no parameters, the program displays \n.

Examples:

$>./tab_mult 9
1 x 9 = 9
2 x 9 = 18
3 x 9 = 27
4 x 9 = 36
5 x 9 = 45
6 x 9 = 54
7 x 9 = 63
8 x 9 = 72
9 x 9 = 81
$>./tab_mult 19
1 x 19 = 19
2 x 19 = 38
3 x 19 = 57
4 x 19 = 76
5 x 19 = 95
6 x 19 = 114
7 x 19 = 133
8 x 19 = 152
9 x 19 = 171
$>
$>./tab_mult | cat -e
$
$>*/

#include <unistd.h>
#include <stdio.h>

int ft_atoi(const char *str)
{
    int signo;
    int resultado;

    signo = 1;
    resultado = 0; //se puede no inicializar¿?¿

    while (*str == 32 || (*str >= 9 && *str <= 13))
        str++;
    if (*str == '-')
        signo = -1;
    if (*str == '-' || *str == '+')
        str++;
    while (*str >= '0' && *str <= '9')
    {
        resultado = resultado * 10 + *str - '0';
        str++;
    }
    return (signo * resultado);
}
/*
int main()
{
    char *str;
    str = "-123";

    printf("%d\n", ft_atoi(str));
    return 0;
}*/

void ft_putnbr(int i)
{
    int iauxiliar;
    char numero;

    iauxiliar = i;
    if (i > 9)
    {
        iauxiliar = i % 10;
        i = i / 10;
        ft_putnbr(i);
    }
    numero = iauxiliar + 48;
    write(1, &numero, 1);
}
/*
int main ()
{
    ft_putnbr(23);
    return 0;
}*/

int main(int ac, char **av)
{
    int i;
    int nbr;


    if (ac != 2) //esto podría ser 'if ac < 1'??
        write(1, "\n", 1);
    else
    {
        nbr = ft_atoi(av[1]); //si saco estas variables fuera del else, me da segfault sin parametros
        i = 1; //este si lo puedo dejar fuera del else
        while (i <= 9)
        {
            ft_putnbr(i);
            write(1, " x ", 3);
            ft_putnbr(nbr);
            write(1, " = ", 3);
            ft_putnbr(nbr * i);
            write(1, "\n", 1);
            i++;
        }
    }
    return (0);
}
