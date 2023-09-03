/*Assignment name  : rot_13
Expected files   : rot_13.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it, replacing each of its
letters by the letter 13 spaces ahead in alphabetical order.

'z' becomes 'm' and 'Z' becomes 'M'. Case remains unaffected.

The output will be followed by a newline.

If the number of arguments is not 1, the program displays a newline.

Example:

$>./rot_13 "abc"
nop
$>./rot_13 "My horse is Amazing." | cat -e
Zl ubefr vf Nznmvat.$
$>./rot_13 "AkjhZ zLKIJz , 23y " | cat -e
NxwuM mYXVWm , 23l $
$>./rot_13 | cat -e
$
$>
$>./rot_13 "" | cat -e
$
$>*/


#include <unistd.h>

//a mimanera, funciona
void    rot_13(char *str)
{
    int i = 0;

    while (str[i])
    {
        if (str[i] >= 'a' && str[i] <= 'm')
            str[i] = str[i] + 13;
        else if (str[i] >= 'n' && str[i] <= 'z')
            str[i] = str[i] - 13;
        else if (str[i] >= 'A' && str[i] <= 'M')
            str[i] = str[i] + 13;
        else if (str[i] >= 'N' && str[i] <= 'Z')
            str[i] = str[i] - 13;
        write(1, &str[i], 1);
        i++;
    }
}

int main(int ac, char **av)
{
    if (ac == 2)
        rot_13(av[1]);
    write(1, "\n", 1);
    return (0);
}


/*
void capi_rot(char c)
{
	if (c <= 'M')
		c += 13;
	else
		c -= 13;
	write(1, &c, 1);
}

void small_rot(char c)
{
	if (c <= 'm')
		
		c += 13;
	else
		c -= 13;
	write(1, &c, 1);
}

void rotone_13 (char *str)
{
	while (*str)
	{
		if (*str >= 'a' && *str < 'z')		
			small_rot(*str);
		else if (*str >= 'A' && *str < 'Z')
			capi_rot(*str);
		else
			write(1, str, 1);
		str++;
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
		rotone_13(av[1]);
	write(1, "\n", 1);
	return (0);
}*/
