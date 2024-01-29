/* 
    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
        PROGRAMA QUE DETERMINE SI UN NUMERO ES PAR O IMPAR

                Fecha de actualizacion: 27-01-2024 
                    
                *********************************
                    Programacion Estructurada
                *********************************
    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 */

#include <stdio.h>

int main(void)
{
    int number;

    printf("Escribe un numero entero: ");
    scanf("%d", &number);

    if (number % 2 == 0)
    
        printf("El numero %d es par\n",number);

    else
    
        printf("El numero %d es impar\n",number);
}