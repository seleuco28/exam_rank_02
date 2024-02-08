/*Assignment name  : alpha_mirror
Expected files   : alpha_mirror.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called alpha_mirror that takes a string and displays this string
after replacing each alphabetical character by the opposite alphabetical
character, followed by a newline.

'a' becomes 'z', 'Z' becomes 'A'
'd' becomes 'w', 'M' becomes 'N'

and so on.

Case is not changed.

If the number of arguments is not 1, display only a newline.

Examples:

$>./alpha_mirror "abc"
zyx
$>./alpha_mirror "My horse is Amazing." | cat -e
Nb slihv rh Znzarmt.$
$>./alpha_mirror | cat -e
$
$>*/

#include <unistd.h>
//mi alpha_mirror: FUNCIONANDO
void alpha_mirror(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'M')
			str[i] = 'Z' - (str[i] - 'A');
		else if (str[i] >= 'a' && str[i] <= 'm')
			str[i] = 'z' - (str[i] - 'a');
		else if (str[i] >= 'N' && str[i] <= 'Z')
			str[i] = 'A' + ('Z' - str[i]);
		else if (str[i] >= 'n' && str[i] <= 'z')
			str[i] = 'a' + ('z' - str[i]);
		write(1, &str[i], 1);
		i++;
	}
}

int main(int ac, char **av)
{

	if (ac == 2)
		alpha_mirror(av[1]);
	write(1, "\n", 1);
	return 0;
}

/*
void small_mirror (char c)
{
    if (c <= 'm') //da igual que ponga el igual o no.
        c = 'z' - (c - 'a');
    else 
        c = 'a' - (c - 'z');
    write (1, &c, 1);
}

void capital_mirror (c)
{
    if (c <= 'M')
        c = 'Z' - (c - 'A');
    else
        c = 'A' - (c - 'Z');
    write(1, &c, 1);
}

void alpha_mirror (char *str)
{
    while (*str)
    {
        if (*str >= 'a' && *str <= 'z')
            small_mirror(*str);
        else if (*str >= 'A' && *str <= 'Z')
            capital_mirror(*str);
        else
            write(1, str, 1);
        str++;
    }
}

int main (int ac, char **av)
{
    if (ac == 2)
    {  
        alpha_mirror(av[1]);
    }
    write(1, "\n", 1);
    return (0);
}*/