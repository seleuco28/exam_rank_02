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
    int i = 0;
    int maximo = tab[i]; //He fallado aqui

    if (len == 0) //ATENCION: poner esto, sin ello en main con len = 0 da un numero Y PARA CUMPLIR "If the array is empty, the function returns 0."
        return 0;
    while (i < len) //IMPORTANTE que no sea igual, sino cuenta una mas!!!
    {
        if (maximo < tab[i])
            maximo = tab[i];
        i++;
    }
    return (maximo);

}


int main()
{
    int array[6] = {-1000, 2, 403, 24, 345, 23};

    printf("%d\n", max(array , 6));
}