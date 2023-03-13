/*Assignment name  : ft_strlen
Expected files   : ft_strlen.c
Allowed functions: 
--------------------------------------------------------------------------------

Write a function that returns the length of a string.

Your function must be declared as follows:

int	ft_strlen(char *str);*/

#include <stdio.h>
#include <unistd.h>


int ft_strlen(char *str)
{
    int i = 0;

    while(str[i])
        i++;

    return (i);
}

int main()
{
    char *str = "hola buenass";

    printf("%d", ft_strlen(str));

    return 0;
}