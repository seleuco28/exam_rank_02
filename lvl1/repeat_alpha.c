/*Assignment name  : repeat_alpha
Expected files   : repeat_alpha.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called repeat_alpha that takes a string and display it
repeating each alphabetical character as many times as its alphabetical index,
followed by a newline.

'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

Case remains unchanged.

If the number of arguments is not 1, just display a newline.

Examples:

$>./repeat_alpha "abc"
abbccc
$>./repeat_alpha "Alex." | cat -e
Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
$>./repeat_alpha 'abacadaba 42!' | cat -e
abbacccaddddabba 42!$
$>./repeat_alpha | cat -e
$
$>
$>./repeat_alpha "" | cat -e
$
$>*/

#include <unistd.h>
//última manera en la que lo he hecho FUNCIONA
void repeat_alpha(char *str)
{
    int i = 0;
    int contador;
    while (str[i])
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            contador = str[i] - 'a' + 1;
        else if (str[i] >= 'A' && str[i] <= 'Z')
            contador = str[i] - 'A' + 1;
        else 
            contador = 1;
        while (contador >= 1)
        {
            write(1, &str[i], 1);
            contador--;
        }
        i++;
    }
}

int main(int ac, char **av)
{
    if (ac == 2)
        repeat_alpha(av[1]);
    write(1, "\n", 1);
    return 0;
}

/*
//OTRA MANERA, funcionando
void repeat_alpha(char *str)
{
    int i = 0;
    int contador;
    while (str[i])
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            contador = str[i] - 'a';
            while (contador >= 0)
            {
                write(1, &str[i], 1);
                contador--;
            }
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            contador = str[i] - 'A';
            while (contador >= 0)
            {
                write(1, &str[i], 1);
                contador--;
            }
        }
        else
            write(1, &str[i], 1);
        i++;
    }
}

int main(int ac, char **av)
{
    if (ac == 2)
        repeat_alpha(av[1]);
    write(1, "\n", 1);
    return 0;
}*/

/*
//a mi manera y funciona guay
int contador_letras(char c)
{
    int contador;

    if (c >= 'A' && c <= 'Z')
        contador = c - 'A' + 1;
    else if (c >= 'a' && c <= 'z')
        contador = c - 'a' + 1;
    else
        contador = 1;
    return (contador);
}

void repeat_alpha(char *str)
{
    int retorno;
    int i = 0;
    while (str[i])
    {
        retorno = contador_letras(str[i]);
        while (retorno-- > 0)
            write(1, &str[i], 1);
        i++;
    }
}

int main(int ac, char **av)
{
    if (ac == 2)
        repeat_alpha(av[1]);
    write(1, "\n", 1);
    return 0;
}*/


/* 	CON UN CONTADOR int i
int contador_letras(char c)
{
    int contador;

    if (c >= 'a' && c <= 'z')
        contador = c - 'a' + 1;
    else if (c >= 'A' && c <= 'Z')
        contador = c - 'A' + 1;
    else 
        contador = 1;

    return (contador);
}


int main(int ac, char **av)
{
    int retorno;
    int i;

    i = 0;
    if (ac == 2)
    {
        while (av[1][i])
        {
            retorno = contador_letras(av[1][i]);
            while (retorno)
            {
                write(1, &av[1][i] ,1);
                retorno--;
            }
            i++;
        }
        write(1, "\n", 1);
    }
    return(0);
}
*/
/*
// lo prefiero con i como arriba, me lio menos
int contador_letras(char c)
{
	int retorno;

	if (c >= 'a' && c <= 'z')
		retorno = c - 'a' + 1;
	else if	(c >= 'A' && c <= 'Z')
		retorno = c - 'A' + 1;
	else
		retorno = 1;

	return(retorno);
}


int main(int ac, char **av)
{
	int retorno;
	
	if (ac == 2)
	{
		while (*av[1])
		{
			retorno = contador_letras(*av[1]);
			while (retorno--)
				write(1, av[1], 1);
			av[1]++;
		}

	}
	write(1, "\n", 1);
	return(0);
}*/
