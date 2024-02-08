/*Assignment name  : ft_strcpy
Expected files   : ft_strcpy.c
Allowed functions: 
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcpy (man strcpy).

Your function must be declared as follows:

char    *ft_strcpy(char *s1, char *s2);*/

#include <stdio.h>
#include <string.h>

char    *ft_strcpy(char *s1, char *s2)
{
    int i = 0;
    
    while (s2[i])
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0'; //cuidado con no olivdar el '\0'
    return(s1);   // ni el return de la funcion (no es void)
}

int main()
{
    char s1[] = "9876543210";
    char s2[] = "123456";
    char s11[] = "9876543210";
    char s22[] = "123456";

    printf("%s\n", strcpy(s1, s2));
    printf("%s\n", ft_strcpy(s11, s22));
    return 0;
}
