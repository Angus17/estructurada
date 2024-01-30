/* 

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        PROGRAMA QUE CALCULE ENGANCHE Y MENSUALIDADES DE UN 
        VEHICULO

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Autor: Diego Leonardo Alejo Cantu
Fecha de actualizacion: 26/01/2024
*/

#include <stdio.h>
#define PI 3.1416 

int main(void)
{
    float radio, generatriz, altura, area_base, area_lateral, area_total, volumen;

    printf("Ingresa el radio de la base del cono: ");
    scanf("%f", &radio);

    printf("Ingresa la generatriz del cono: ");
    scanf("%f", &generatriz);

    printf("Ingresa la altura del cono: ");
    scanf("%f", &altura);

    area_base = PI * radio * radio;
    area_lateral = PI * radio * generatriz;
    area_total = area_base + area_lateral;
    volumen = (area_base * altura) / 3;

    printf("\nEl area base del cono es de: %.2f  unidades\n", area_base);
    printf("El area lateral del cono es de: %.2f unidades\n", area_lateral);
    printf("El area total del cono es de: %.2f unidades\n", area_total);
    printf("El volumen del cono es de: %.2f unidades\n", volumen);
}