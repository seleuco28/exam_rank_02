/*Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base);*/

#include <stdio.h>
#include <stdlib.h>

char	to_lower(char c) //en todas las bases que me pasen, quiero que las letras sean minusculas
{
	if (c >= 'A' && c <= 'Z') //podría estar entre A y F
		return (c + 32);
	return (c);
}
 //usamos esto para darle la posicion del char dentro de la base
int get_digit(char c, int str_base) //CUIDADO SUELO PONER char *c y me da fallo
{
	int max_digit; //posicionamos el ultimo valor de la base que queramos
	if (str_base <= 10) //en base 2
		max_digit = str_base + '0'; //2 + 0 = 2
	else //en base 16
		max_digit = str_base - 10 + 'a'; // (16 - 10) + 'a' = f

	if (c >= '0' && c <= '9' && c <= max_digit) //CUIDADO AQUI -> a veces pongo str_base en vez de max digit
		return (c - '0'); //ejemplo retorna 8 - 0 = 8
	else if (c >= 'a' && c <= 'f' && c <= max_digit) //CUIDADO AQUI -> a veces pongo str_base en vez de max digit
		return (10 + c - 'a');//ejemplo: (si 'b') 10 + 'b' - 'a' = 11
	else //si c no es ni 0-9 ni a-f O te sales de max_digit
		return (-1); //y así para
}

/*int main()
{
    printf("%d\n", get_digit('a', 16)); //aquí comprobamos que a en base 16 retorna decima posición
	printf("%d\n", get_digit('4', 10)); // y que cuatro en base decimal retorna 4ta posición
	return 0;
}*/

int ft_atoi_base(const char *str, int str_base)
{
	int resultado = 0;
	int signo = 1;
	int digit;

	if (*str == '-')
	{
		signo = -1;
		str++; // cuidado, antes se me ha olvidado esto
	}

	while ((digit = get_digit(to_lower(*str), str_base)) >= 0) //llega un momento en que get_digit() retorna -1 y se sale
	{
		resultado = resultado * str_base + (digit); //No *10 si no *str_base
		str++;
	}
	return (signo * resultado);
}

int	main()
{		
	printf("%d\n", ft_atoi_base("-4D2" , 16)); // esto es 1234
	printf("%d\n", ft_atoi_base("-10011010010", 2)); // esto tambien
	printf("%d\n", ft_atoi_base("-1234" , 10)); // esto es 1234
	
	printf("%d\n", ft_atoi_base("b" , 16)); // esto es 11
	printf("%d\n", ft_atoi_base("10" , 10)); // esto es 10

	return (0);
}
