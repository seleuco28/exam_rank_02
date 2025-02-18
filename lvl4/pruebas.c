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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_words(char *str)
{
	int i = 0;
	int num_words = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i])
	{
		num_words++;
		while (!(str[i] == ' ' || str[i] == '\t'))
			i++;
		while (str[i] == ' ' || str[i] == '\t')
			i++;
	}
	return(num_words);
}

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

void fill_words(char **array, char *str)
{
	int num_cajon = 0;
	int i = 0;

	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i])
	{
		array[num_cajon] = word_strdup(&str[i]);
		num_cajon++;
		while (str[i] && (!(str[i] == ' ' || str[i] == '\t')))
			i++;
		while (str[i] == ' ' || str[i] == '\t')
			i++;
	}
}

char    **ft_split(char *str)
{
	int num_words = count_words(str);
	char **array;

	array = malloc(sizeof(char *) * (num_words + 1));
	array[num_words] = 0;
	fill_words(array, str);
	return(array);
}

int main()
{
	int i = 0;
	char **tab;
	tab = ft_split("   hola   mundo   adios   agur   ");
	while (i < 4)
	{
		printf("%s\n", tab[i]);
		i++;
	}
	return 0;
}