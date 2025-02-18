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

int		count_words(char *str) //me retorna el numero de palabras que tiene el string
{
	int num_words = 0;
	int i = 0;
	while (str[i] == ' ' || str[i] == '\t') //salto los espacios
		i++;
	while (str[i])
	{
		num_words++; //cuento palabra
		while (str[i] && (!(str[i] == ' ' || str[i] == '\t'))) //salto palabra IMPORANTE PONER EL "Y QUE EXISTA"
			i++;
		while (str[i] == ' ' || str[i] == '\t') //salto espacios
			i++;
	}
	return (num_words);
}

/*int	ft_wordlen(char *str) //mido la len de una palabra
{
	int i = 0;

	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		i++;
	return (i);
}*/

// CUIDADO, ESTA FUNCION NO ES EXACTAMENTE IGUAL A UN FT_STRDUP
char	*word_strdup(char *str) // le hago malloc a la palabra y copio el string original (strdup)
{
	int i = 0;
	int len = 0;//ft_wordlen(str);
	while (str[len] && (!(str[len] == ' ' || str[len] == '\t'))) //mientras exista y palabra
		len++;
	char *word = malloc(sizeof(char) * (len + 1));

	while (str[i])
	{
		word[i] = str[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

void	fill_words(char **array, char *str) //meto en un 'cajon' la palabra, y me la salto
{
	int num_cajon = 0;
	int i = 0;

	while (str[i] == ' ' || str[i] == '\t') //me salto los primeros espacios
		i++;
	while (str[i])
	{
		// IMPORTANTE ESTE ----------  &str[i] -> si no da segfault
		array[num_cajon] = word_strdup(&str[i]); //meto la copia de la palabra, en el **array
		num_cajon++;
		while (str[i] && (!(str[i] == ' ' || str[i] == '\t'))) //salto palabra IMPORANTE PONER EL "Y QUE EXISTA"
			i++;
		while (str[i] == ' ' || str[i] == '\t') //salto espacios
			i++;
	}
}

char	**ft_split(char *str)
{
	int		num_words;
	char	**array;
	
	num_words = count_words(str);
	array = malloc(sizeof(char *) * (num_words + 1)); //ATENCION AQUI, QUE ES MALLOC A CHAR*
	                                                  //array siempre de num_words + 1 para que el ultimo sea el NULL
	array[num_words] = 0; //asi paro el array (una especie de /0)
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