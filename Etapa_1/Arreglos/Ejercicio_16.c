/* 
    -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
        Para un grupo de N alumnos se tiene las 5 calificaciones de
        sus parciales. Se desea conocer lo siguiente:

        a) El promedio de sus calificaciones de cada uno de los N alumnos
        b) El alumno que obtuvo la mejor calificacion en el 3er parcial
        c) El tipo de examen que obtuvo el mayor promedio de calificacion, asi como el promedio
        
        Validar que la calificacion se encuentre entre 0 y 100

        Autor: Diego Leonardo Alejo Cantu
        Fecha: 15-02-2024
    -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#ifdef __linux__
    #include <stdio_ext.h>
#endif 

int main(void)
{
    int calificaciones[100][5], contador_alumnos = 0, alumno_calificacion_mayor, promedio_mayor_examenes = 0;
    bool existencia = false;
    char respuesta;

    do
    {
        printf("Existen alumnos?\nS.Si\nN.No\n: ");

        #if defined(_WIN32) || defined(_WIN64)
            fflush(stdin);
        #elif __linux__
            __fpurge(stdin);
        #endif
        scanf(" %c", &respuesta);

        respuesta = tolower(respuesta);

        if (respuesta != 's' || respuesta != 'n')
        {
            #if defined(_WIN32) || defined(_WIN64)
                system("cls");

                printf("Ingresa una respuesta valida");
                printf("\nPresiona la tecla ENTER para continuar. . . ");
                fflush(stdin);
                getchar();
                system("cls");

            #elif __linux__
                system("clear");

                printf("Ingresa una respuesta valida");
                fflush(stdout);
                
                printf("\nPresiona la tecla ENTER para continuar. . . ");
                fflush(stdout);
                __fpurge(stdin);
                getchar();
                
                system("clear");

            #endif
        }
        

    } while (respuesta != 's' || respuesta != 'n');
    
    
}