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

char *ft_strdup(const char *src)
{
    char *dst;
    int i;

    i = 0;
    while (src[i])
        i++;
    dst = malloc(sizeof(char) * (i + 1));
    if (!dst) // Importante este fallo del malloc
        return (0);
    i = 0;
    while (src[i]) //si pongo en el while dst, me da fallo poner siempre src!!!
    {               //algo en lo que he fallado la ultima vez, es en no hacer este while que es la copia!!!!
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0'; //importante este cero al final!!!
    return (dst);
}

int main()
{
    printf("%s\n", strdup("abc123"));
    printf("%s\n", ft_strdup("abc123"));
    return (0);
}