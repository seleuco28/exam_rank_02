/*Assignment name  : is_power_of_2
Expected files   : is_power_of_2.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that determines if a given number is a power of 2.

This function returns 1 if the given number is a power of 2, otherwise it returns 0.

Your function must be declared as follows:

int	    is_power_of_2(unsigned int n);*/

#include <stdio.h>
#include <unistd.h>
#include <stdio.h>

//esta es la unica manera de hacerlo

int is_power_of_2(unsigned int n)
{
	int number = 2; //EMPEZARLO EN 2 para que 1 no de confusion
    if (n == 1) //IMPORTANTISIMA EXCEPCION!!! aunque no parezca 1 is power of 2!!!!
        return(1);
	while(number <= n)
	{
		if (number == n)
		{
			return 1;
		}
		number = number * 2;
	}
	return 0;
}


int main()
{
    printf("%d\n" ,  is_power_of_2(64));
    printf("%d\n" ,  is_power_of_2(24));
    printf("%d\n" ,  is_power_of_2(48));

    return 0;
}