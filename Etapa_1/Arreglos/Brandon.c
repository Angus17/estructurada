#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>


int main(void)
{
    int arreglo[100] = {0}, posiciones_pares[100], numero, i, potencia, contador_pares = 0;
    bool pares_encontrados = false;

    do
    {
        printf("Ingresa tamanio: ");
        scanf("%d", &numero);
    } while (numero < 1 || numero > 100);

    potencia = numero << 64;

    fgets(arreglo, sizeof(arreglo), stdin);

    

    i = 0;
    
    while (i < numero)
    {
        if (arreglo[i] % 2 == 0)
        {
            pares_encontrados = true;
            posiciones_pares[contador_pares] = i;
            contador_pares++;
        }
        i++;
    }

    if (pares_encontrados)
    {
        for ( i = 0; i < contador_pares; i++)
        
            printf("[%d] ", arreglo[posiciones_pares[i]]);
    }
    else
    
        printf("\n:(");
    
    
    
    
    

}