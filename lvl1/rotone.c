/*Assignment name  : rotone
Expected files   : rotone.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it, replacing each of its
letters by the next one in alphabetical order.

'z' becomes 'a' and 'Z' becomes 'A'. Case remains unaffected.

The output will be followed by a \n.

If the number of arguments is not 1, the program displays \n.

Example:

$>./rotone "abc"
bcd
$>./rotone "Les stagiaires du staff ne sentent pas toujours tres bon." | cat -e
Mft tubhjbjsft ev tubgg of tfoufou qbt upvkpvst usft cpo.$
$>./rotone "AkjhZ zLKIJz , 23y " | cat -e
BlkiA aMLJKa , 23z $
$>./rotone | cat -e
$
$>
$>./rotone "" | cat -e
$
$>*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


void rotone(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] >= 'A' && str[i] < 'Z')
            str[i] = str[i] + 1;
        else if (str[i] >= 'a' && str[i] < 'z')
            str[i] = str[i] + 1;
        else if (str[i] == 'z')
            str[i] = str[i] - 25;
        else if (str[i] == 'Z')
            str[i] = str[i] - 25;
        write(1, &str[i], 1);
        i++;
    }
}

int main(int ac, char **av)
{
    if (ac == 2)
        rotone(av[1]);
    write(1, "\n", 1);
    return 0;
}

/*
void rot(char c)
{
	c += 1;
	write(1, &c, 1);
}


void rotone(char *str)
{
	while (*str)
	{
		if (*str >= 'a' && *str < 'z')
			rot(*str);
		else if (*str >= 'A' && *str < 'Z')
			rot(*str);
		else if (*str == 'Z')
			write(1, "A", 1);
		else if (*str == 'z')
			write(1, "a", 1);
		else
			write(1, str, 1);
		str++;
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
		rotone(av[1]);
	write(1, "\n", 1);
	return(0);
}*/
