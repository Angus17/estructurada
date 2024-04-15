/* 
    -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
        Para un grupo de N alumnos se tiene las 5 calificaciones de
        sus parciales. Se desea conocer lo siguiente:

        a) El promedio de sus calificaciones de cada uno de los N alumnos
        b) El alumno que obtuvo la mejor calificacion en el 3er parcial
        c) El tipo de examen que obtuvo el mayor promedio de calificacion, asi como el promedio
        
        Validar que la calificacion se encuentre entre 0 y 100

        Autor: Diego Leonardo Alejo Cantu
        Fecha: 16-02-2024
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
    int calificaciones[100][5], suma, contador_alumnos = 0, alumno_calificacion_mayor, calificacion_mayor = 0, i, j, examen_mayor;
    float promedio_alumnos[100], promedio_examenes[5], promedio_mayor_examenes = 0.0;
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

        if (respuesta != 's' && respuesta != 'n')
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
        else if (respuesta == 's')
        
            existencia = true;

    } while (respuesta != 's' && respuesta != 'n');

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #elif __linux__
        system("clear");
    #endif
    
    while (existencia)
    {
        for ( i = 0; i < 5; i++)
        {
            do
            {
                printf("Ingresa la calificacion %d del alumno %d: ", i + 1, contador_alumnos + 1);
                #if defined(_WIN32) || defined(_WIN64)
                    fflush(stdin);
                #elif __linux__
                    __fpurge(stdin);
                #endif
                scanf("%d", &calificaciones[contador_alumnos][i]);

                if (calificaciones[contador_alumnos][i] < 0 || calificaciones[contador_alumnos][i] > 100)
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
            } while (calificaciones[contador_alumnos][i] < 0 || calificaciones[contador_alumnos][i] > 100);
            
        }
        
        do
        {
            printf("Existen mas alumnos?\nS.Si\nN.No\n: ");

            #if defined(_WIN32) || defined(_WIN64)
                fflush(stdin);
            #elif __linux__
                __fpurge(stdin);
            #endif
            scanf(" %c", &respuesta);

            respuesta = tolower(respuesta);

            if (respuesta != 's' && respuesta != 'n')
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
            else if (respuesta == 'n')
            
                existencia = false;

        } while (respuesta != 's' && respuesta != 'n');

        contador_alumnos++;
    }

    for ( i = 0; i < contador_alumnos; i++)
    {
        suma = 0;

        for ( j = 0; j < 5; j++)
        
            suma += calificaciones[i][j];
        
        promedio_alumnos[i] = (float) suma / 5;
    }
    
    i = 0;
    
    while (i < contador_alumnos)
    {
        if (calificaciones[i][2] > calificacion_mayor)
        {
            alumno_calificacion_mayor = i + 1;
            calificacion_mayor = calificaciones[i][2];
        }
        
        i++;
    }

    for ( j = 0; j < 5; j++)
    {
        suma = 0;

        for ( i = 0; i < contador_alumnos; i++)
        
            suma += calificaciones[i][j];
        
        promedio_examenes[j] = suma / contador_alumnos;
    }
    
    for ( i = 0; i < 5; i++)
    {
        if (promedio_examenes[i] > promedio_mayor_examenes)
        {
            promedio_mayor_examenes = promedio_examenes[i];
            examen_mayor = i + 1;
        }
        
    }
    
    for ( i = 0; i < contador_alumnos; i++)
    
        printf("\nEl promedio del alumno %d es de %.2f\n", i + 1, promedio_alumnos[i]);
    
    printf("El alumno que obtuvo la mejor calificacion en el parcial #3 fue el alumno %d\n", alumno_calificacion_mayor);
    printf("El examen que obtuvo mejor promedio entre los alumnos, fue el parcial #%d con un promedio "
            "de %.2f\n", examen_mayor, promedio_mayor_examenes);
}