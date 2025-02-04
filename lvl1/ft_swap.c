/*Assignment name  : ft_swap
Expected files   : ft_swap.c
Allowed functions: 
--------------------------------------------------------------------------------

Write a function that swaps the contents of two integers the adresses of which
are passed as parameters.

Your function must be declared as follows:

void	ft_swap(int *a, int *b);*/

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
    int temp; //la variable que creo no es puntero (int normal)

    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a = 42; //cuidado aqui que no es (*a)
    int b = 43;	//cuidado aqui que no es (*b)

    printf("a: %d, b: %d\n", a, b);
    ft_swap(&a, &b); //cuidado aqui porque no es (*a , *b)
    printf("a: %d, b: %d\n", a, b);

    return 0;
}
