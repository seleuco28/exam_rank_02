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
#include <stdlib.h>

int ft_atoi(const char *str)
{
	int signo = 1; //IMPORTANTE INICIALIZAR LAS DOS VARIABLES
	int resultado = 0; //IMPORTANTE INICIALIZAR LAS DOS VARIABLES

	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '-')
	{
		signo = -1;
		str++; //esto es necesario? (creo que no)
	}
	while (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9') //IMPORTANTE PONER QUE ESTE EN ESTE RANGO (no que exista)
	{
		resultado = resultado * 10 + (*str - '0');
		str++;
	}

	return(signo * resultado); //NO OLVIDAR EL RETURN ESTE
}

int main()
{
    printf("%d\n", atoi("		-123")); //no da lo mismo si ponemos un mas (pero el corrector lo pone bien)
    printf("%d\n", ft_atoi("		-123"));//no da lo mismo si ponemos un mas (pero el corrector lo pone bien)
    return 0;
}
