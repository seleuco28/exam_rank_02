/*Assignment name  : ft_strcpy
Expected files   : ft_strcpy.c
Allowed functions: 
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcpy (man strcpy).

Your function must be declared as follows:

char    *ft_strcpy(char *s1, char *s2);*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>

char *ft_strcpy(char *s1, char *s2)
{
    int i = 0;
    while (s2[i])
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0'; 
    return (s1);
}

int main()
{
    char src[10] = "1234";
    char dst[10] = "4444";

    char src_2[10] = "1234";
    char dst_2[10] = "4444";

    printf("%s\n", dst);
    printf("%s\n", strcpy(dst, src));

    printf("%s\n", dst_2);
    printf("%s\n", ft_strcpy(dst_2, src_2));

    return 0;
}