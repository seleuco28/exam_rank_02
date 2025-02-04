/*Assignment name  : print_bits
Expected files   : print_bits.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a function that takes a byte, and prints it in binary WITHOUT A NEWLINE
AT THE END.

Your function must be declared as follows:

void	print_bits(unsigned char octet);

Example, if you pass 2 to print_bits, it will print "00000010"*/

#include <unistd.h>
#include <stdio.h>

void print_bits(unsigned char octet)
{
	int	i = 256; // 256 te llena los 8 primeros 0s
    while (i >>= 1) //con i = 256, se va /2 8 veces, al desplazarlo una vez a la derecha se divide entre 2
	{
        if (octet & i) //MIRARLO EN PYTONTUTOR pero, si coincide el 1er uno de i con n, pintamos 1 y sino pintamos 0
            write(1, "1", 1);
        else
            write(1, "0", 1);
    }
    //con mis palabras, vas moviendo el 1 a la derecha, y si nuestro numero coincicde que tiene 1 lo escribe
    // else le pone un 0 y asi quedaría escrito
}
int main()
{
    int n = 42;
    print_bits(n); //ATENCION: es unsigned char, pero hay que meterle un int!
    printf("\n");
}

/*
La función print_bits toma un argumento octet de tipo unsigned char que representa un byte (8 bits) y muestra en la salida estándar (stdout) 
la representación binaria de ese byte, imprimiendo 0's y 1's. El proceso de impresión de los bits se realiza en un bucle while que usa la variable
 i como una máscara para obtener el valor de cada bit en el byte octet. Inicialmente, i se establece en 256, que es el valor binario 100000000 
 (el bit más alto es 1 y los demás son 0). En cada iteración del bucle, i se desplaza un bit a la derecha mediante el operador de desplazamiento 
 bit a bit >>=, lo que hace que i tome los valores binarios 010000000, 001000000, 000100000, 000010000, 000001000, 000000100, 000000010 y 000000001, 
 respectivamente.
En cada iteración, se realiza una operación AND bit a bit entre octet y i, lo que da como resultado un valor de 0 o 1, 
dependiendo de si el bit correspondiente en octet está encendido o apagado. Si el resultado es 1, se imprime un carácter '1' en 
la salida estándar mediante la función write, que es una función de bajo nivel de la biblioteca estándar de C. Si el resultado es 0, 
se imprime un carácter '0' en su lugar.

Al final del bucle, se han impreso los 8 bits de octet en orden, comenzando por el bit más significativo y 
terminando en el bit menos significativo, lo que muestra la representación binaria del byte octet.
*/