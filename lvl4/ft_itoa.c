/*Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int get_count(int n)
{
    int i = 0;
    //if (!n)
    //    return (1); esto es necesario¿?¿?¿?¿?¿?¿?
    while (n)
    {
        n = n / 10;
        i++;
    }
    //printf("%d", i);
    return (i);
}
/*
int main()
{
    get_count(4884);
    return (0);
}*/

char *ft_itoa(int n)
{
    int count = get_count(n);
    char *str;
    str = (char *)malloc(sizeof(char) * count + 1);
    str[count] = '\0';
    if (!n)
        str[0] = '\0';
    while (n)
    {
        str[--count] = n % 10 + '0';
        n = n / 10;
    }
    //printf("%s\n", str);
    return (str);
}

int main()
{
    char *str;
    str = ft_itoa(122);
    printf("%s\n", str);
    return (0);
}