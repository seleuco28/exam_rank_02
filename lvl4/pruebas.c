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

void sort_int_tab(int *tab, unsigned int size)
{
	int temp;
	int i = 0;

	while (i < (size - 1))
	{
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = 0;
		}
		else
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