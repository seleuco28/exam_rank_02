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


//a mi manera, funciona
char *ft_strrev(char *str)
{
	int i = 0;
	int len = 0;
	char temp;
	while (str[len])
		len++;
	len--; //siempre nos vamos uno en len;
	while (i < len) //posible fallo, aqui antes he puesto "while (str[i])" y no me lo hacia CUIDADO
	{
		temp = str[i];
		str[i] = str[len];
		str[len] = temp;
		i++;
		len--;
	}
	return(str);
}

int main()
{
	char string[7] = "123456";

	//printf("%s\n", string);
	//ft_strrev(string);
	printf("%s\n", ft_strrev(string));
	return 0;
}


/*
char *ft_strrev(char *str)
{
	int i = -1;
	int len = 0; //si no inicializo len, me da bus error
	char tmp;

	while (str[len])
		len++;
	while (++i < --len) //hay que poner a len el -- delante porque strlen siempre se pasa uno CUIDADO
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
	char str[] = "123456";
	printf("%s\n", ft_strrev(str));
	return(0);
}*/