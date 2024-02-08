/*Assignment name  : ft_strcmp
Expected files   : ft_strcmp.c
Allowed functions: 
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcmp (man strcmp).

Your function must be declared as follows:

int    ft_strcmp(char *s1, char *s2);*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>

int ft_strcmp(char *s1, char *s2)
{
    int i;
    i = 0;
    
    while (s1[i]) //valdria con poner "while (s2[i])"?? == El simulador me dice que si, pero cuidado que puede ser posible fallo
    {
        if (s1[i] != s2[i])
            return(s1[i] - s2[i]);
        i++;
    }
    return (s1[i] - s2[i]);
}  

// ATENCION, SI HAGO ASI EL MAIN ESTARIA DANDO FALLO CUANDO ESTA BIEN
// HACERLO COMO ABAJO

/* 
int main()
{
    printf("%d\n", ft_strcmp("hola", "holaa"));
    printf("%d\n", strcmp("hola", "holaa"));

    return 0;
}*/


int main()
{
	char *s1 = "hola";
	char *s2 = "holaa";

	char *s3 = "hola";
	char *s4 = "holaa";

	printf("%d\n", ft_strcmp(s1, s2));
	printf("%d\n", strcmp(s3, s4));
}