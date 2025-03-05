/*Assignment name  : ft_list_foreach
Expected files   : ft_list_foreach.c, ft_list.h
Allowed functions: 
--------------------------------------------------------------------------------

Write a function that takes a list and a function pointer, and applies this
function to each element of the list.

It must be declared as follows:

void    ft_list_foreach(t_list *begin_list, void (*f)(void *));

The function pointed to by f will be used as follows:

(*f)(list_ptr->data);

You must use the following structure, and turn it in as a file called
ft_list.h:

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;*/

#include <unistd.h>
#include <stdlib.h>
#include "ft_list.h"

void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
    while (begin_list)
    {
        if (begin_list->data)
            (*f)(begin_list->data);
        begin_list = begin_list->next;
    }

}

///////////////////aqui acaba mi codigo

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

t_list	*ft_new_elem(void *data)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (node = NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}

int	main(void)
{
	t_list	*test_list;

	test_list = ft_new_elem("Follow ");
	test_list->next = ft_new_elem("the ");
	test_list->next->next = ft_new_elem("white ");
	test_list->next->next->next = ft_new_elem("rabbit ");
	test_list->next->next->next->next = ft_new_elem(".");
	ft_list_foreach(test_list, (void *)ft_putstr);
	ft_putstr("\n");
	return (0);
}
//loop or tab iteration or as you want
