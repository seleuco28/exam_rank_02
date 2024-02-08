/*Assignment name	: ft_strcspn
Expected files	: ft_strcspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strcspn
(man strcspn).

The function should be prototyped as follows:

size_t	ft_strcspn(const char *s, const char *reject);*/


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

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t i = 0;
	while (s[i])
	{
		if (ft_strchr(reject, s[i]) != 0)
			break;
		i++;
	}
	return(i);
}


int main () {
    int len = strcspn("holllla buenas", "xyza"); //cuenta en el 1er string hasta que haya alguna que coincida
    int len_ft = ft_strcspn("holllla buenas", "xyza");
    printf("%d\n", len );
    printf("%d\n", len_ft );
return(0);
}