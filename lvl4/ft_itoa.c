/*Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);*/

#include <stdio.h>
#include <stdlib.h>

int get_count(int nbr)
{
	int i = 0;
	if (nbr <= 0) //importante este igual para que cuanto nbr sea 0 cuente 1!!!
		i++;
	while (nbr)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char *ft_itoa(int nbr)
{
	char *str;
	int count = get_count(nbr);

	str = malloc(sizeof(char) * count); //no necesitaria el +1
	if (!str)
		return (NULL);
	str[count--] = '\0'; //pongo fin al string // ATENCION, SI NO CORRO UNO ATRAS EL COUNT, EL PROGRAMA SE QUEDA PILLADO
	if (nbr == 0) //controlo la excepcion del 0
		str[0] = '0';
	else
	{
		if (nbr < 0)
		{
			str[0] = '-'; //le pongo el negativo
			nbr *= -1;    //y vuelvo el numero positivo (para hacer el caso general)
		}
		while (nbr)
		{
			str[count] = (nbr % 10) + '0';
			nbr /= 10;
			count--;
		}
	}
	return(str);
}

int main()
{
	printf("%s\n", ft_itoa(-123));
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(123));
	return 0;
}