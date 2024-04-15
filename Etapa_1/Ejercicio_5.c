/* 
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        PROGRAMA QUE CALCULE DADO EL SUELDO DE UN TRABAJADOR, CALCULE
        SU AUMENTO SEGUN:

        - SUELDO < 10000, UN AUMENTO DEL 15%
        - 10000 <= SUELDO <= 15000 UN AUMENTO DEL 11%
        - SUELDO > 15000 UN AUENTO DEL 8%

        IMPPRIMIR SUELDO ANTERIOR, SUELDO NUEVO, AUMENTO
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Autor: Diego Leonardo Alejo Cantu
Fecha de actualizacion: 01/02/2024
*/

#include <stdio.h>

int main(void)
{
    int sueldo, sueldo_nuevo;

    printf("\t\tIngresa el sueldo del trabajador: ");
    scanf("%d", &sueldo);

    if (sueldo < 10000)
    
        sueldo_nuevo = sueldo * 1.15;
    
    else if (sueldo <= 15000)
        
            sueldo_nuevo = sueldo * 1.11;
        
        else
        
            sueldo_nuevo = sueldo * 1.08;
        
    printf("\n\t\tEl sueldo anterior del trabajador era de: $%d\n", sueldo);
    printf("\t\tEl trabajador recibio un aumento de $%d\n", sueldo_nuevo - sueldo);
    printf("\t\tEl sueldo nuevo del trabajador es de: $%d\n", sueldo_nuevo);
}