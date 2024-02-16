/* 
    Realizar un programa que les ingrese y valide (0-100)
    las 3 calificaciones de los 7 alumnos, pedirles el nombre
    y calcular su promedio

    Imprimir nombre y promedio de sus calificaciones

Autor: Diego Leonardo Alejo Cantu
Fecha: 15-02-2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#if __linux__
    #include <stdio_ext.h>
#endif

int main(void)
{
    int i, j, calificacion[7][3], promedio[7], suma, contador, espacio_caracter, longitud = 0;
    char nombre[7][50];

    for ( i = 0; i < 7; i++)
    {
        do
        {
            printf("Escribe el nombre del alumn@ %d: ", i + 1);

            #if defined(_WIN32) || defined(_WIN64)
                fflush(stdin);
            #elif __linux__
                __fpurge(stdin);
            #endif

            fgets(nombre[i], 50, stdin); /* gets(nombre[i]) */

            nombre[i][strcspn(nombre[i], "\n")] = '\0';  

            longitud = strlen(nombre[i]);

            if (longitud != 0)
            {
                espacio_caracter = 0;
                contador = 0;

                while (nombre[i][espacio_caracter] != '\0')
                {
                    if (isalpha(nombre[i][espacio_caracter]) || nombre[i][espacio_caracter] == 32)
                    
                        contador++;
                    
                    espacio_caracter++;
                }
            }

        } while (longitud == 0 || longitud != contador);

        #if defined(_WIN32) || defined(_WIN64)
            system("cls");
        #elif __linux__
            system("clear");
        #endif

        for ( j = 0; j < 3; j++)
        {
            
            do
            {
                printf("Ingresa la calificacion %d del alumn@ %d: ", j + 1, i + 1);
                #ifdef __linux__
                    __fpurge(stdin);
                #endif
                scanf("%d", &calificacion[i][j]);

                #if defined(_WIN32) || defined(_WIN64)
                    if (calificacion[i][j] < 0 || calificacion[i][j] > 100)
                    {
                        system("cls");

                        printf("Ingresa una respuesta valida");
                        printf("\nPresiona la tecla ENTER para continuar. . . ");
                        fflush(stdin);
                        getchar();
                        system("cls");
                    }
                #elif __linux__
                    if (calificacion[i][j] < 0 || calificacion[i][j] > 100)
                    {
                        system("clear");

                        printf("Ingresa una respuesta valida");
                        fflush(stdout);
                        
                        printf("\nPresiona la tecla ENTER para continuar. . . ");
                        fflush(stdout);
                        __fpurge(stdin);
                        getchar();
                        
                        system("clear");
                    }
                #endif
            } while (calificacion[i][j] < 0 || calificacion[i][j] > 100);
        }

        #if defined(_WIN32) || defined(_WIN64)
            system("cls");
        #elif __linux__
            system("clear");
        #endif
    }
    
    for ( i = 0; i < 7; i++)
    {
        suma = 0;
        
        for ( j = 0; j < 3; j++)
        
            suma += calificacion[i][j];

        promedio[i] = suma / 3;
    }
    

    for ( i = 0; i < 7; i++)
    {
        printf("\nEl promedio de %s: ", nombre[i]);
        printf("%d ", promedio[i]);
    }
    

}