/*Assignment name  : ft_strdup
Expected files   : ft_strdup.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Reproduce the behavior of the function strdup (man strdup).

Your function must be declared as follows:

char    *ft_strdup(char *src);*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *ft_strdup(char *src)
{
    int i = 0;
    char *str;
    while (src[i])
        i++;
    str = malloc(sizeof(char) * i + 1);
    i = 0;
    while (src[i])
    {
        str[i] = src[i];
        i++;
    }
    str[i] = '\0';
    return(str);
}

int main()
{
    printf("%s\n", strdup("abc123"));
    printf("%s\n", ft_strdup("abc123"));
    return (0);
}