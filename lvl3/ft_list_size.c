/*Assignment name  : ft_list_size
Expected files   : ft_list_size.c, ft_list.h
Allowed functions: 
--------------------------------------------------------------------------------

Write a function that returns the number of elements in the linked list that's
passed to it.

It must be declared as follows:

int	ft_list_size(t_list *begin_list);

You must use the following structure, and turn it in as a file called
ft_list.h:

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;*/


#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"
/*
typedef struct	s_list
{
	struct s_list *next;
	void		  *data;
}	t_list; */

int	ft_list_size(t_list *begin_list)
{
	int i = 0;

	while (begin_list)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (i);
}

int main()
{	
	int a = 5;
	int b = 7;
	int c = 2;
	int d = 4;
    int e = 5;
    int f = 6;

	int *w;
	int *x;
	int *y;
	int *z;
    int *zz;
    int *zzz;

	w = &a;
	x = &b;
	y = &c;
	z = &d;
    zz = &e;
    zzz = &f;
	t_list *list1;
	t_list *list2;
	t_list *list3;
	t_list *list4;
    t_list *list5;
    t_list *list6;
	list1 = malloc(sizeof(t_list));
	list2 = malloc(sizeof(t_list));
	list3 = malloc(sizeof(t_list));
	list4 = malloc(sizeof(t_list));
    list5 = malloc(sizeof(t_list));
    list6 = malloc(sizeof(t_list));
	list1->data = (void *)w;
	list2->data = (void *)x;
	list3->data = (void *)y;
	list4->data = (void *)z;
	list1->next = list2;
	list2->next = list3;
	list3->next = list4;
	list4->next = list5;
    list5->next = list6;
    list6->next = NULL;
	printf("%d", ft_list_size(list1));
}