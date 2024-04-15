/* 
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        PROGRAMA QUE CALCULE EL PRECIO TOTAL DE UN ARTICULO DADO 
                    SU COSTO
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Autor: Diego Leonardo Alejo Cantu
Fecha de actualizacion: 26/01/2024
*/

#include <stdio.h>

int main(void)
{
    int costo_articulo, precio_impuestos, precio_total;

    printf("Ingresa el costo del articulo: ");
    scanf("%d", &costo_articulo);

    if (costo_articulo <= 200)
    
        precio_impuestos = 0;
    
    else if (costo_articulo <= 400)
        
            precio_impuestos = (costo_articulo - 200) * 0.30;
        
        else if (costo_articulo <= 5000)
            
                precio_impuestos = 200 * 0.30 + (costo_articulo - 400) * 0.40;
            
            else
            
                precio_impuestos = 200 * 0.30 + (costo_articulo - 400) * 0.50;
    
    precio_total = costo_articulo + precio_impuestos;
    
    printf("\nEl precio total final del articulo es de: $%d\n", precio_total);
}