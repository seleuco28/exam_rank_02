/*Assignment name  : ft_strcpy
Expected files   : ft_strcpy.c
Allowed functions: 
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcpy (man strcpy).

Your function must be declared as follows:

char    *ft_strcpy(char *s1, char *s2);*/


#include <stdio.h>
#include <string.h>

char	*ft_strcpy(char *s1, char *s2)
{
	int i;
	i = 0;
	while (s2[i]) // ponemos esta condicion para k no haya overlap
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return(s1);	

}

 int main() {
 	char src[5] = "12345";
 	char dst[9] = "abcde123";

 	printf("%s\n", strcpy(dst, src));
 	printf("%s\n", ft_strcpy(dst, src));
 }
