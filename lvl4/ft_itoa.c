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
        n = n * -1;
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
    printf("%d", get_count(4884));
    return (0);
}*/

char	*ft_itoa(int nbr)
{
	int		index;
	long	number;
	char	*string;

	number = nbr;
	index = get_count(number);
	string = ((char *)malloc(index + 1));
	if (!string)
		return (NULL);
	string[index--] = '\0';
	if (number == 0)
		string[0] = '0';
	else
	{
		if (number < 0)
		{
			string[0] = '-';
			number *= -1;
		}
		while (number > 0)
		{
			string[index] = (number % 10) + '0';
			number /= 10;
			index--;
		}
	}
	return (string);
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
	printf("%s\n", ft_itoa(-2147483648));
	printf("%s\n", ft_itoa(2147483647));
}