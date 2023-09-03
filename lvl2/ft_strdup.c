/*Assignment name  : ft_strdup
Expected files   : ft_strdup.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Reproduce the behavior of the function strdup (man strdup).

Your function must be declared as follows:

char    *ft_strdup(char *src);*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *ft_strdup(const char *s1)
{
    char *str;
    int i;

    i = 0;
    while (s1[i])
        i++;
    str = malloc(sizeof(char) * (i + 1));
    if (!str)
        return (0);
    i = 0;
    while (s1[i])
    {
        str[i] = s1[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}

int main()
{
    printf("%s\n", strdup("abc123"));
    printf("%s\n", ft_strdup("abc123"));
    return (0);
}