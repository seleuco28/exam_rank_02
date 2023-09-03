/*Assignment name  : ulstr
Expected files   : ulstr.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and reverses the case of all its letters.
Other characters remain unchanged.

You must display the result followed by a '\n'.

If the number of arguments is not 1, the program displays '\n'.

Examples :

$>./ulstr "L'eSPrit nE peUt plUs pRogResSer s'Il staGne et sI peRsIsTent VAnIte et auto-justification." | cat -e
l'EspRIT Ne PEuT PLuS PrOGrESsER S'iL STAgNE ET Si PErSiStENT vaNiTE ET AUTO-JUSTIFICATION.$
$>./ulstr "S'enTOuRer dE sECreT eSt uN sIGnE De mAnQuE De coNNaiSSanCe.  " | cat -e
s'ENtoUrER De SecREt EsT Un SigNe dE MaNqUe dE COnnAIssANcE.  $
$>./ulstr "3:21 Ba  tOut  moUn ki Ka di KE m'en Ka fe fot" | cat -e
3:21 bA  ToUT  MOuN KI kA DI ke M'EN kA FE FOT$
$>./ulstr | cat -e
$*/


#include <unistd.h>

//a mi manera y funciona
void ulstr(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
        else if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
        write(1, &str[i], 1);
        i++;
    }
}

int main(int ac, char **av)
{
    if (ac == 2)
        ulstr(av[1]);
    write(1, "\n", 1);
    return 0;
}

/*
//esto sería con la auxiliar y dos sub-funciones (al estilo de rotone)

void a_mayus(char c)
{
    c -= 32;
    write(1, &c, 1);
}

void a_minus(char c)
{
    c += 32;
    write(1, &c, 1);
}

void ulstr(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            a_mayus(str[i]);
        else if (str[i] >= 'A' && str[i] <= 'Z')
            a_minus(str[i]);
        else
            write(1, &str[i], 1);
        i++;
    }
}


int main(int ac, char **av)
{
    if (ac == 2)
        ulstr(av[1]);
    write(1, "\n", 1);
    return 0;
}*/


//SIN LA AUXILIAR
/*
void ulstr(char *str)
{
	char c;

	c  = *str;
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			c = *str - 32;
		else if (*str >= 'A' && *str <= 'Z')
			c = *str + 32;
		else
			c = *str;
		str++;
		write (1, &c, 1);
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
		ulstr(av[1]);
	write(1, "\n", 1);
	return (1);
}*/
