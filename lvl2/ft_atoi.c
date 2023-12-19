/*Assignment name  : ft_atoi
Expected files   : ft_atoi.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str to an integer (type int)
and returns it.

It works much like the standard atoi(const char *str) function, see the man.

Your function must be declared as follows:

int	ft_atoi(const char *str);*/

#include <unistd.h>
#include <stdio.h>

int ft_atoi(const char *str)
{
    int signo;
    int resultado;

    signo = 1;
    resultado = 0; //se puede no inicializar¿?¿ NOOOO DA PROBLEMAS, PONERLOA 0 SIEMPRE

    while (*str == 32 || (*str >= 9 && *str <= 13))
        str++;
    if (*str == '-')
        signo = -1;
    if (*str == '-' || *str == '+')
        str++;
    while (*str >= '0' && *str <= '9') //IMPORTANTE PONER QUE SEA NUMERO (no vale solo con decir 'que exista')
    {
        resultado = resultado * 10 + *str - '0'; //la primera es (0 * 10) = 0 + el mismo string
        str++;
    }
    return (signo * resultado);
}


int main()
{
    char *str;
    str = "-123";

    printf("%d\n", ft_atoi(str));
    return 0;
}
/*
int		main(void)//
{
	char a[] = "    \n\n\v\f\r\t -5234AAAgreghrsth";
	printf("%d\n",ft_atoi(a));
}*/
