/*Write the following function:

int		max(int* tab, unsigned int len);

The first parameter is an array of int, the second is the number of elements in
the array.

The function returns the largest number found in the array.

If the array is empty, the function returns 0.*/

#include <stdio.h>

int		max(int* tab, unsigned int len)
{
    int i = 0;
    int maximo = tab[0];

    while (i < len)
    {
        if (maximo < tab[i])
            maximo = tab[i];
        i++;
    }
    return(maximo);
}

int main()
{
    int array[4] = {8, 1, 10, 3};
    printf("%d", max(array, 4));

}