/*Assignment name  : ft_swap
Expected files   : ft_swap.c
Allowed functions: 
--------------------------------------------------------------------------------

Write a function that swaps the contents of two integers the adresses of which
are passed as parameters.

Your function must be declared as follows:

void	ft_swap(int *a, int *b);*/
#include <stdio.h>
#include <unistd.h>

void ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}


int main(void)
{
	int a = 42;
	int b = 43;
	
	printf("A es:%d y B es:%d\n", a, b); 

	ft_swap(&a, &b);

	printf("A es:%d y B es:%d\n", a, b); 

	return(0);
}

