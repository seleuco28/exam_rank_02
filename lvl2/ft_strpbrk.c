/*Assignment name	: ft_strpbrk
Expected files	: ft_strpbrk.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strpbrk
(man strpbrk).

The function should be prototyped as follows:

char	*ft_strpbrk(const char *s1, const char *s2);*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *ft_strchr(const char *s, int c)
{
    int i;

    i = 0;
    if (!s)
        return (0);
    while (s[i])
    {
        if ((char)c == s[i])
            return((char *)&s[i]); // para retornar el puntero al string en cierta posicion
        i++;
    }
    if (c == '\0') // The terminating null character is considered to be part of the
                   //string; therefore if c is `\0', the functions locate the terminating `\0'.
        return((char *)&s[i]); //hasta el final
    return (0);
}
/*
int main(void)
{
    char tweet[] = "tripouillete hola buenas tardes";
	char tweet1[] = "tripouillete hola buenas tardes";
	
	printf("%s\n", strchr(tweet1, 'a'));
    printf("%s\n", ft_strchr(tweet, 'a'));

    return(0);
}
*/

char *ft_strpbrk(const char *s1, const char *s2)
{
    while (*s1)
    {
        if (ft_strchr(s2, *s1))
            return ((char *)s1);
        s1++;
    }
    return (NULL);
}

int main()
{
    char tweet[] = "tripouillete hola buenas tardes";
    char tweet_aux[] = "lhoa";
    char tweet1[] = "tripouillete hola buenas tardes";
    char tweet1_aux[] = "lhoa";

    printf("%s\n", strpbrk(tweet, tweet_aux));
    printf("%s\n", ft_strpbrk(tweet1, tweet1_aux));
    return (0);
}