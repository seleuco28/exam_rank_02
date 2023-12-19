/*Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str);*/

#include <stdlib.h>
#include <stdio.h>

int	ft_wordlen(char *str) //mido la len de una palabra
{
	int i = 0;

	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		i++;
	return (i);
}

char	*word_strdup(char *str) // le hago malloc a la palabra y copio el string original
{
	int i = 0;
	int len = ft_wordlen(str);
	char *word = malloc(sizeof(char) * (len + 1));
	
	
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

void	fill_words(char **array, char *str)
{
	int word_index = 0;
	
	while (*str == ' ' || *str == '\t' || *str == '\n') //me salto los primeros espacios
		str++;
	while (*str != '\0')
	{
		array[word_index] = word_strdup(str); //meto la copya de la palabra, en el **array
		word_index++;
		while (*str != '\0' && *str != ' ' && *str != '\t' && *str != '\n') //me salto la palabra
			str++;
		while (*str == ' ' || *str == '\t' || *str == '\n') //me salto los espacios
			str++;
	}
}

int		count_words(char *str)
{
	int num_words = 0;
	
	while (*str == ' ' || *str == '\t' || *str == '\n') //salto los espacios
		str++;
	while (*str != '\0')
	{
		num_words++; //cuento palabra
		while (*str != '\0' && *str != ' ' && *str != '\t' && *str != '\n') //salto espacios
			str++;
		while (*str == ' ' || *str == '\t' || *str == '\n') //salto palabra
			str++;
	}
	return (num_words);
}

char	**ft_split(char *str)
{
	int		num_words;
	char	**array;
	
	num_words = count_words(str);
	array = malloc(sizeof(char *) * (num_words + 1)); //ATENCION AQUI, QUE ES MALLOC A CHAR*
	
	array[num_words] = 0; //asi paro el array
	fill_words(array, str); //llena las palabras de cada cajon del array
	return (array); //retorna puntero al array
}

int main(void)
{
    int i = 0;
    char **tab;
    tab = ft_split("Hello world como estamos?");

    while (i < 4)
    {
        printf("%s\n", tab[i]);
        i++;
    }

    return (0);
}