/*Assignment name  : ft_strrev
Expected files   : ft_strrev.c
Allowed functions: 
--------------------------------------------------------------------------------

Write a function that reverses (in-place) a string.

It must return its parameter.

Your function must be declared as follows:

char    *ft_strrev(char *str);*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *ft_strrev(char *str)
{
	int i = -1;
	int len = 0;
	char tmp;

	while (str[len])
		len++;
	while (++i < --len)
	{
		tmp = str[i];
		str[i] = str[len];
		str[len] = tmp;
	}
	return (str);
}

int main()
{
	//char str[] = "abc";
	char str[] = "abcdefg123";
	printf("%s\n", ft_strrev(str));
	return(0);
}