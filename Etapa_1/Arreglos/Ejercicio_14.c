/* 
    Realizar un programa que les ingrese y valide (0-100)
    las 3 calificaciones de los 7 alumnos

    Impriimir las calificaciones del 2do parcial de cada alumno

Autor: Diego Leonardo Alejo Cantu
Fecha: 15-02-2024
 */

#include <stdio.h>
#include <stdlib.h>
#if __linux__
    #include <stdio_ext.h>
#endif

int main(void)
{
    int i, j, calificacion[7][3];

    for ( i = 0; i < 7; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            do
            {
                printf("Ingresa la calificacion %d del alumno %d: ", j + 1, i + 1);
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
    

    printf("\nLas calificaciones del 2do Parcial de cada alumno:\n");
    for ( i = 0; i < 7; i++)
    {
        printf("\nAlumno %d: ", i + 1);
        printf("%d ", calificacion[i][1]);
        
    }
    

}