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
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

int get_digit(char c, int str_base) //usamos esto para darle la posicion del char dentro de la base
{
	int max_digit; //posicionamos el ultimo valor de la base que queramos
	if (str_base <= 10)
		max_digit = str_base + '0';
	else
		max_digit = str_base - 10 + 'a'; //aqui por ejemplo, si es 11 -> (11 - 10 = 1) + a

	if (c >= '0' && c <= '9' && c <= max_digit) //aqui por ejemplo retorna 8 - 0 = 8
		return (c - '0');
	else if (c >= 'a' && c <= 'f' && c <= max_digit) //aqui retorna por ejemplo: (si 'b') 10 + 'b' - 'a' = 11
		return (10 + c - 'a');
	else
		return (-1);
}

int ft_atoi_base(const char *str, int str_base)
{
	int resultado = 0;
	int signo = 1;
	int digit;

	if (*str == '-')
	{
		signo = -1;
		++str;
	}

	while ((digit = get_digit(to_lower(*str), str_base)) >= 0) //llega un momento en que get_digit() retorna -1 y se sale
	{
		resultado = resultado * str_base + (digit);
		++str;
	}
	return (signo * resultado);
}

int	main()
{		
	printf("%d\n", ft_atoi_base("-4D2" , 16)); // esto es 1234
	printf("%d\n", ft_atoi_base("-10011010010", 2)); // esto tambien
	printf("%d\n", ft_atoi_base("-1234" , 10)); // esto es 1234
	return (0);
}
