/*Assignment name  : repeat_alpha
Expected files   : repeat_alpha.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called repeat_alpha that takes a string and display it
repeating each alphabetical character as many times as its alphabetical index,
followed by a newline.

'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

Case remains unchanged.

If the number of arguments is not 1, just display a newline.

Examples:

$>./repeat_alpha "abc"
abbccc
$>./repeat_alpha "Alex." | cat -e
Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
$>./repeat_alpha 'abacadaba 42!' | cat -e
abbacccaddddabba 42!$
$>./repeat_alpha | cat -e
$
$>
$>./repeat_alpha "" | cat -e
$
$>*/

#include <stdio.h>
#include <unistd.h>
int contador_letras(char c)
{
    int contador;

    if (c >= 'A' && c <= 'Z')
        contador = c - 'A' + 1;
    else if (c >= 'a' && c <= 'z')
        contador = c - 'a' + 1;
    else
        contador = 1;
    return (contador);
}

int main()
{
    char character = "a";
    printf("%d\n", contador_letras(character));

    return 0;
}