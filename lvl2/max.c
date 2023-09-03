/*Write the following function:

int		max(int* tab, unsigned int len);

The first parameter is an array of int, the second is the number of elements in
the array.

The function returns the largest number found in the array.

If the array is empty, the function returns 0.
*/
#include <stdio.h>
#include <unistd.h>

int max(int* tab, unsigned int len)
{
    int i;
    int maximo;

    i = 0;
    maximo = tab[i];
    while (i < len)
    {
        if (maximo < tab[i])
            maximo = tab[i];
        i++;
    }
    return (maximo);

}

int main()
{
    int i[6] = {1000, 2, 403, 24, 345, 23};

    printf("%d\n", max(i , 6));
}