
/* 
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        PROGRAMA QUE SUME DOS NUMEROS

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Autor: Diego Leonardo Alejo Cantu
Fecha de actualizacion: 26/01/2024

 */
#include <stdio.h>

int main(void)
{
    int number_1 = 0, number_2 = 0;

    printf("Digita el numero 1: ");
    scanf("%d", &number_1);

    printf("Digita el numero 2: ");
    scanf("%d", &number_2);
    
    printf("La suma de los numeros ingresados es de: %d", number_1 + number_2);
}