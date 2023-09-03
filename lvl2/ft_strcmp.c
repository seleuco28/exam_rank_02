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
    
    while (s1[i])
    {
        if (s1[i] != s2[i])
            return(s1[i] - s2[i]);
        i++;
    }
    return (s1[i] - s2[i]);
}  

int main()
{
	char *s1 = "hello";
	char *s2 = "helloo";

	char *s3 = "hello";
	char *s4 = "helloo";

	printf("%d\n", ft_strcmp(s1, s2));
	printf("%d\n", strcmp(s3, s4));
}