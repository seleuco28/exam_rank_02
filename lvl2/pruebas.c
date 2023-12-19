/*Assignment name  : ft_strrev
Expected files   : ft_strrev.c
Allowed functions: 
--------------------------------------------------------------------------------

Write a function that reverses (in-place) a string.

It must return its parameter.

Your function must be declared as follows:

char    *ft_strrev(char *str);*/

#include <stdio.h>

char *ft_strrev(char *str)
{
    int i = 0;
    int len = 0;
    char temp;
    while (str[len])
        len++;
    len--;
    while (i <= len)
    {
        temp = str[i];
        str[i] = str[len];
        str[len] = temp;
        len--;
        i++;
    }
    return(str);
}

int main()
{
    char string[] = "1234567";
    printf("%s", ft_strrev(string));

    return 0;
}