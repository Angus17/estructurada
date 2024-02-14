/* 
    REALIZAR BUSQUEDA LINEAL EN UN ARREGLO DESORDENADO DE 10
    QUE LOS ELEMENTOS SEAN DE 0 A 5000

    AL FINAL IMPRIMIR SI EL NUMERO SE ENCONTRO O NO. EN CASO DE EXISTIR, INDICAR LA POSICION

    Autor: Diego Leonardo Alejo Cantu
    Fecha: 13-02-2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
    int lista_numeros[10], i, elemento = -1, busqueda;
    bool bandera = true;

    for ( i = 0; i < 10; i++)
    {
        do
        {
            printf("Ingresa numero %d: ", i + 1);
            scanf(" %d", &lista_numeros[i]);

            #if defined(_WIN32) || defined(_WIN64)

            #elif __linux__
                if (lista_numeros[i] < 0 || lista_numeros[i] > 5000)
                {
                    system("clear");

                    printf("Ingresa una respuesta valida");
                    fflush(stdout);
                    
                    printf("\nPresiona la tecla ENTER para continuar. . . ");
                    fflush(stdout);
                    while (getchar() != '\n');
                    getchar();
                    
                    system("clear");
                }
                
            #endif 
            if (lista_numeros[i] < 0 || lista_numeros[i] > 5000)
            {
                
            }
            
        } while (lista_numeros[i] < 0 || lista_numeros[i] > 5000);
    }
    
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #elif __linux__
        system("clear");
    #endif 

    do
    {
        printf("Ingresa el numero que quieres buscar: ");
        scanf(" %d", &busqueda);

        #if defined(_WIN32) || defined(_WIN64)
            if (busqueda < 0 || busqueda > 5000)
                {
                    system("cls");

                    printf("Ingresa una respuesta valida");
                    
                    printf("\nPresiona la tecla ENTER para continuar. . . ");
                    fflush(stdin);
                    getchar();
                    
                    system("cls");
                }
        #elif __linux__
            if (busqueda < 0 || busqueda > 5000)
            {
                system("clear");

                printf("Ingresa una respuesta valida");
                fflush(stdout);
                
                printf("\nPresiona la tecla ENTER para continuar. . . ");
                fflush(stdout);
                while (getchar() != '\n');
                getchar();
                
                system("clear");
            }
            
        #endif 
    } while (busqueda < 0 || busqueda > 5000);
    
    i = 0;

    while (i < 10 && bandera)
    {
        if (busqueda == lista_numeros[i])
        {
            elemento = i;
            bandera = false;
        }

        i++;
    }
    

    (elemento != -1) ? printf("\nEl numero que buscas fue encontrado en la posicion %d del arreglo, el numero es: %d\n\n", elemento, lista_numeros[elemento]) : printf("\nEl numero que ingresaste no fue encontrado. . .\n") ;

}