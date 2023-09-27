/*Assignment name  : sort_int_tab
Expected files   : sort_int_tab.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

void sort_int_tab(int *tab, unsigned int size);

It must sort (in-place) the 'tab' int array, that contains exactly 'size'
members, in ascending order.

Doubles must be preserved.

Input is always coherent.*/

#include <stdio.h>

//a mi manera, funciona, igual que abajo pero comentado
void sort_int_tab(int *tab, unsigned int size)
{
	int i = 0; //hay que inicializar a 0, obvio
	int temp;

	while (i < (size - 1)) //y poner un size - 1 para que no pete el while //NO SE SI HAY QUE PONER EL SIZE -1 O NO
	{
		if (tab[i] > tab[i + 1]) //haces el swap Y VUELVES A EMPEZAR, IMPORTANTE
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = 0;
		}
		else //si no pongo este else me da mal!!! ATENCION!!!!!S
			i++;
	}
}

int main()
{
	int i = 0;
	int array[] = {2, 0, 1, 4};
	unsigned int size = 4;

	sort_int_tab(array, size);

	while (i < size)
	{
		printf("%d\n", array[i]);
		i++;
	}
}

/*
void	sort_int_tab(int *tab, unsigned int size)
{
	int	i = 0;
	int	temp;

	while (i < (size - 1))
	{
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i+ 1];
			tab[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
}

int		main(void)
{
	int tab[] = { -1, 6, 7, 3, -6, 7, 2, 4, 5, 2147483647, -2147483648 };
	unsigned int size = 11;

	sort_int_tab(tab, size);

	unsigned int i = 0;
	while (i < size)
	{
		printf("element %d: %d\n", i, tab[i]);
		i++;
	}
	return 0;
}*/