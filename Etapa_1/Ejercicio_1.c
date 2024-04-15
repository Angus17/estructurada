
/* 
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        PROGRAMA QUE CALCULE ENGANCHE Y MENSUALIDADES DE UN 
        VEHICULO

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Autor: Diego Leonardo Alejo Cantu
Fecha de actualizacion: 26/01/2024

*/

#include <stdio.h>

int main(void)
{
    float enganche, costo, mensualidades;

    printf("Ingresa el precio del vehiculo: ");
    scanf("%f", &costo);

    enganche = costo * .35;
    mensualidades = (costo - enganche) * 1.12 / 36;

    printf("El costo de enganche del vehiculo es de: $%.2f\n", enganche);
    printf("El cliente debera pagar $%.2f en 36 mensualidades", mensualidades);
    
}