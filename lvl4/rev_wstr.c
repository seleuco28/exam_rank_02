/*Assignment name  : rev_wstr
Expected files   : rev_wstr.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string as a parameter, and prints its words in 
reverse order.

A "word" is a part of the string bounded by spaces and/or tabs, or the 
begin/end of the string.

If the number of parameters is different from 1, the program will display 
'\n'.

In the parameters that are going to be tested, there won't be any "additional" 
spaces (meaning that there won't be additionnal spaces at the beginning or at 
the end of the string, and words will always  be separated by exactly one space).

Examples:

$> ./rev_wstr "le temps du mepris precede celui de l'indifference" | cat -e
l'indifference de celui precede mepris du temps le$
$> ./rev_wstr "abcdefghijklm"
abcdefghijklm
$> ./rev_wstr "il contempla le mont" | cat -e
mont le contempla il$
$> ./rev_wstr | cat -e
$
$>*/

#include <unistd.h>

//a mi manera y funcionando
void rev_wstr(char *str)
{
    int i = 0;
    int start;
    int end;
    while (str[i])
        i++;
    while (i >= 0) //aqui no se puede poner while (str[i]) porque ya no existe claro!!
    {
        while (str[i] == ' ' || str[i] == '\t' || str[i] == '\0') //importante este '\0' porque en el primer supuesto siempre sera asi
            i--;
        end = i;
        //ATENCION!!!en esta linea de abajo he fallado mucho y por eso no me daba!! IMPORTANTISIMO EL "Y QUE EXISTA"
        while (str[i] && (!(str[i] == ' ' || str[i] == '\t'))) //mientras palabra IMPORTANTISIMO EL "Y QUE EXISTA"
            i--;
        start = i + 1; //importante este +1 para estar dentro de la 1ra letra
        int flag;
        flag = start;
        while (start <= end)
        {
            write(1, &str[start], 1);
            start++;
        }
		//esto es para pintar todos los espacios menos el último
        if (flag != 0) //si flag no existe porque era igual a start y se ha acabado, al final: start = "-1 + 1 = 0" y no pintaria
            write(1, " ", 1);
    }       
}

int main(int ac, char **av)
{
    if (ac == 2)
        rev_wstr(av[1]);
    write(1, "\n", 1);
    return (0);
}

/*
int main(int argc, char **argv)
{
	int start;
	int end;
	int i = 0;
		
	if(argc == 2)
	{   
		while(argv[1][i] != '\0')
			i++;
		while(i >= 0)
		{
			while( argv[1][i] == '\0' || argv[1][i] == ' ' || argv[1][i] == '\t')
				i--;
			end = i;
			while(argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
				i--;
			start = i + 1;
			int  flag;
			flag = start;
			while(start <= end)
			{
				write (1, &argv[1][start],1);
				start++;		
			}
			if (flag != 0)
			{
				write(1, " ", 1);
			}
		}
	}
	write(1, "\n", 1);
}*/