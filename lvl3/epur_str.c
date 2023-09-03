/*Assignment name  : epur_str
Expected files   : epur_str.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string, and displays this string with exactly one
space between words, with no spaces or tabs either at the beginning or the end,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

If the number of arguments is not 1, or if there are no words to display, the
program displays \n.

Example:

$> ./epur_str "vous voyez c'est facile d'afficher la meme chose" | cat -e
vous voyez c'est facile d'afficher la meme chose$
$> ./epur_str " seulement          la c'est      plus dur " | cat -e
seulement la c'est plus dur$
$> ./epur_str "comme c'est cocasse" "vous avez entendu, Mathilde ?" | cat -e
$
$> ./epur_str "" | cat -e
$
$>*/

#include <unistd.h>

void epur_str(char *str)
{
    int i = 0;
    int flag = 0;
    while (str[i] == ' ' || str[i] == '\t')
        i++;

    while (str[i])
    {
        if (str[i] == ' ' || str[i] == '\t')
            flag = 1;
        if (!(str[i] == ' ' || str[i] == '\t')) //esto me da bien
        //if (str[i] != ' ' || str[i] != '\t') //y esto, que es como lo suelo hacer yo, Y ME DA MAL
        {
            if (flag == 1)
            {
                write(1, " ", 1);
                flag = 0;
            }
            write(1, &str[i], 1);
        }
        i++;
    }
}


int main(int ac, char **av)
{
    if (ac == 2)
        epur_str(av[1]);
    write(1, "\n", 1);
    return (0);
}