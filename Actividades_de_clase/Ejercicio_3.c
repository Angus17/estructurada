/* 

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        PROGRAMA QUE CALCULE EL PERIMETRO DE UN TRIANGULO DADOS 
        3 PUNTOS COORDENADOS

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Autor: Diego Leonardo Alejo Cantu
Fecha de actualizacion: 26/01/2024
*/

#include <stdio.h>
#include <math.h>

int main(void)
{
    float distancia;
    int punto_x_1, punto_y_1, punto_x_2, punto_y_2, punto_x_3, punto_y_3;

    printf("Ingresa el dato X del punto 1: ");
    scanf("%d", &punto_x_1);

    printf("Ingresa el dato Y del punto 1: ");
    scanf("%d", &punto_y_1);

    printf("Ingresa el dato X del punto 2: ");
    scanf("%d", &punto_x_2);

    printf("Ingresa el dato Y del punto 2: ");
    scanf("%d", &punto_y_2);

    printf("Ingresa el dato X del punto 3: ");
    scanf("%d", &punto_x_3);

    printf("Ingresa el dato Y del punto 3: ");
    scanf("%d", &punto_y_3);

    distancia = sqrt((punto_x_1 - punto_x_2) * (punto_x_1 - punto_x_2) + (punto_y_1 - punto_y_2) * (punto_y_1 - punto_y_2));

    distancia += sqrt((punto_x_2 - punto_x_3) * (punto_x_2 - punto_x_3) + (punto_y_2 - punto_y_3) * (punto_y_2 - punto_y_3));

    distancia += sqrt((punto_x_3 - punto_x_1) * (punto_x_3 - punto_x_1) + (punto_y_3 - punto_y_1) * (punto_y_3 - punto_y_1));

    printf("\nEl perimetro total del triangulo es de: %.2f unidades\n", distancia);
}