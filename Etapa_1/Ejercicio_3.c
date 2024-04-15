
/* 
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        PROGRAMA QUE CALCULE EL NUEVO SUELDO DEL TRABAJADOR
        SI GANA $10,000 O MENOS, EL AUMENTO ES DE 15%
        SI GANA MAS DE $10,000 EL AUMENTO ES DE 8%
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Autor: Diego Leonardo Alejo Cantu
Fecha de actualizacion: 26/01/2024
*/

#include <stdio.h>

int main(void)
{
    int sueldo, sueldo_nuevo;

    printf("Ingresa el sueldo del trabajador: ");
    scanf("%d", &sueldo);

    if (sueldo <= 10000)
    
        sueldo_nuevo = sueldo * 1.15;
    
    else
    
        sueldo_nuevo = sueldo * 1.08;
    

    printf("\nEl sueldo anterior del trabajador era de: $%d\n", sueldo);
    printf("El trabajador recibio un aumento de $%d\n", sueldo_nuevo - sueldo);
    printf("El sueldo nuevo del trabajador es de: $%d\n", sueldo_nuevo);
}