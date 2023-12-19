/*Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int get_count(long n)
{
    int i = 0;
    if (n == 0)
        return(1);
    if (n < 0)
    {
        //n = n * -1; //esto esta puesto pero en principio no haria falta
        i++;
    }
    while (n)
    {
        n = n / 10;
        i++;
    }
    return (i);
}
/*
int main()
{
    printf("%d", get_count(-4884));
    return (0);
}*/

char	*ft_itoa(int nbr)
{
	int		count;
	char	*str;

	count = get_count(nbr);
	str = ((char *)malloc(count + 1)); //cuidado porque el malloc yo lo hacia diferente
	if (!str)
		return (NULL);
	str[count--] = '\0'; //IMPORTANTISIMO ESTE --
	if (nbr == 0)
		str[0] = '0';
	else
	{
		if (nbr < 0)
		{
			str[0] = '-';
			nbr *= -1; //lo pongo en positivo y sigo con ello
		}
		while (nbr > 0)
		{
			str[count] = (nbr % 10) + '0'; //se puede poner el "--"" aqui
			nbr /= 10;
			count--;
		}
	}
	return (str);
}



int	main(void)
{
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(1));
	printf("%s\n", ft_itoa(42));
	printf("%s\n", ft_itoa(1001));
	printf("%s\n", ft_itoa(-0));
	printf("%s\n", ft_itoa(-2));
	printf("%s\n", ft_itoa(-24));
}