/*Assignment name  : ft_strdup
Expected files   : ft_strdup.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Reproduce the behavior of the function strdup (man strdup).

Your function must be declared as follows:

char    *ft_strdup(char *src);*/

#include <stdlib.h>
#include <stdio.h>

char *ft_strdup(char *src)
{
	char *string;
	int i = 0;

	while (src[i])
		i++;
	string = malloc(sizeof(char) * i + 1);
	i = 0;
	while (src[i])
	{
		string[i] = src[i];
		i++;
	}
	string[i] = '\0';
	return(string);
}

int main()
{
	char hola[] = "holaaaa";
	printf("%s", ft_strdup(hola));

	return 0;
}