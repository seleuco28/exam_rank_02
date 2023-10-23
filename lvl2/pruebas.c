/*Assignment name	: ft_strpbrk
Expected files	: ft_strpbrk.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strpbrk
(man strpbrk).

The function should be prototyped as follows:

char	*ft_strpbrk(const char *s1, const char *s2);*/

#include <stdio.h>
#include <string.h>

char *ft_strchr(const char *s, int c) // "locate a character in string"
{
    int i;

    i = 0;
    if (!s)
        return(0);
    while (s[i])
    {
        if ((char)s[i] == (char)c)
            return((char *)&s[i]); //retornamos el resto del string
        i++;
    }
    if (c == '\0')
        return((char *)&s[i]);
    return (0);
}

char	*ft_strpbrk(const char *s1, const char *s2)
{
    while (*s1)
    {
        if (ft_strchr(s2, *s1))
            return((char *)s1);
        s1++;
    }
    return(NULL);   
}

int main()
{
    char tweet[] = "tripouillete hola buenas tardes";
    char tweet_aux[] = "we";
    char tweet1[] = "tripouillete hola buenas tardes";
    char tweet1_aux[] = "we";

    printf("%s\n", strpbrk(tweet, tweet_aux));
    printf("%s\n", ft_strpbrk(tweet1, tweet1_aux));
    return (0);
}