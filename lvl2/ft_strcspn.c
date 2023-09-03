/*Assignment name	: ft_strcspn
Expected files	: ft_strcspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strcspn
(man strcspn).

The function should be prototyped as follows:

size_t	ft_strcspn(const char *s, const char *reject);
*/
#include <stdio.h>
#include <string.h>

size_t ft_strcspn(const char *s, const char *reject)
{
	int i;
	int j;

	j = 0;
	while (*s) //mientras recorres el string
	{
		i = 0;
		while (reject[i] && reject[i] != *s) //recorre reject, mientras no coincida
			i++;
		if (reject[i]) //si sobrevive el string que reject retorna j
			return (j);
		s++; // si no sigue iterando
		j++; // y sumas uno
	}
	return (j);
}


int main () {
    int len = strcspn("A0SFASFAS21321321", "0123456789");
    int len_ft = ft_strcspn("A0SFASFAS21321321", "0123456789");
    printf("%d\n", len );
    printf("%d\n", len_ft );
return(0);
}