
/* 
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        PROGRAMA QUE CALCULE AREA Y CIRCUNFERENCIA DE UN CIRCULO

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Autor: Diego Leonardo Alejo Cantu
Fecha de actualizacion: 26/01/2024

 */
#include <stdio.h>
#define PI 3.1416

int main(void)
{
    float area, circunferencia, radio;

    printf("Digita el radio del circulo: ");
    scanf("%f", &radio);

    area = PI * radio * radio;
    circunferencia = 2 * PI * radio;
    
    printf("El area del circulo es de : %.2f unidades\n", area);
    printf("La circunferencia del circulo es de: %.2f unidades", circunferencia);
}