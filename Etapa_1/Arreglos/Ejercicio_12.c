/* 

        PARA UN ARREGLO DE 10 ELEMENTOS, ORDENARLO DE FORMA ASCENDENTE, 
        CON EL METODO DE LA BURBUJA

*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#ifdef __linux__
    #include <stdio_ext.h>
#endif

int main(void)
{
    int lista_numeros[10], i, j, auxiliar;

    setlocale(LC_CTYPE, "spanish");

	for ( i = 0; i < 10; i++)
    {
        do
        {
            #if defined(_WIN32) || defined(_WIN64)
                system("cls");
                fflush(stdin);
            #elif __linux__
                system("clear");
                __fpurge(stdin); /* NO estandar */
            #endif

            printf("Ingresa número %d: ", i + 1);

        }while (scanf("%d", &lista_numeros[i]) != 1);
    }

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #elif __linux__
        system("clear");
    #endif 
    
    printf("Este es el arreglo ingresado: \n");

    for ( i = 0; i < 10; i++)
    
        printf("[%d] ", lista_numeros[i]);
    
    printf("\n\n");

    for ( i = 0 ; i < 9 ; i++)
    {
        for ( j = i + 1 ; j <= 9 ; j++)
        {
            if (lista_numeros[i] > lista_numeros[j])
            {
                auxiliar = lista_numeros[i];
                lista_numeros[i] = lista_numeros[j];
                lista_numeros[j] = auxiliar;
            }
        }
    }
    
    printf("Este es el arreglo ordenado ascendentemente: \n");

    for ( i = 0; i < 10; i++)
    
        printf("[%d] ", lista_numeros[i]);
    
    printf("\n\n");
}