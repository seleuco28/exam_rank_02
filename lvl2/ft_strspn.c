/*
Assignment name	: ft_strspn
Expected files	: ft_strspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the strspn function 
(man strspn).

The function should be prototyped as follows:

size_t	ft_strspn(const char *s, const char *accept);*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


char *ft_strchr(const char *s, int c)
{
    int i;

    i = 0;
    if (!s)
        return(0);
    while (s[i])
    {
        if ((char)s[i] == (char)c)
            return((char *)&s[i]);
        i++;
    }
    if (c == '\0')
        return((char *)&s[i]);
    return (0);
}
/*
int main()
{
    char tweet[] = "tripoulliete hola buenas tardes";
    
    printf("%s\n", strchr(tweet, 'a'));
    printf("%s\n", ft_strchr(tweet, 'a'));
    return 0;
}
*/
size_t ft_strspn(const char *s, const char *accept)
{
    size_t i = 0;

    while(s[i] != '\0')
    {
        if (ft_strchr(accept, s[i]) == 0)
            break;
        ++i;
    }
    return (i);
}

int main () {
    int len = strspn("tripoulliete hola buenas tardes", "buenas");
    int len_ft = ft_strspn("tripoulliete hola buenas tardes","buenas");
    printf("%d\n", len );
    printf("%d\n", len_ft );
return(0);
}
