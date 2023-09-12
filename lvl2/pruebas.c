/*Assignment name  : ft_strcmp
Expected files   : ft_strcmp.c
Allowed functions: 
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcmp (man strcmp).

Your function must be declared as follows:

int    ft_strcmp(char *s1, char *s2);*/

#include <string.h>
#include <stdio.h>

int ft_strcmp(char *s1, char *s2)
{
	int i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return(s1[i] - s2[i]);
		i++;
	}
	return(s1[i] - s2[i]);
}

int main()
{
	char *str1 = "hola";
	char *str2 = "holb";

	char *str3 = "hola";
	char *str4 = "holb";

	printf("%d\n", strcmp(str1, str2));
	printf("%d\n", ft_strcmp(str1, str2));
	return 0;
}
