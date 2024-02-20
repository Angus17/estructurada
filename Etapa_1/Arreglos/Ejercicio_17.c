/* 
    -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
        Para un grupo de N alumnos se tiene las 5 calificaciones de
        sus parciales. Utilizar ciclo while para leer datos. Se desea conocer:

        a) El promedio de sus calificaciones de cada uno de los N alumnos(guardarlos en
        arreglo unidimensional)
        b) El alumno que obtuvo la mejor calificacion en el 3er parcial
        c) El alumno que obtuvo la mayor calificacion en el 1er y 5to parcial
        d) Dado un numero que identifica a un alumno (renglon), mostrar en que examen
        logró la mayor calificacion
        e) En que examenes fue el mas alto el promedio de los N alumnos. El promedio de 
        cada examen guardarlo en un arreglo
        
        Validar que la calificacion se encuentre entre 0 y 100

        Autor: Diego Leonardo Alejo Cantu
        Fecha: 19-02-2024
    -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
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
    int calificaciones[20][5], suma = 0, contador_alumnos = 0, matricula[20], i, j, calificacion_mayor_3 = 0, alumno_mejor_calificacion_3, calificacion_mayor_1 = 0, calificacion_mayor_5 = 0, matricula_consulta, posicion_alumno = -1, alumno_examen_mayor = 0, alumno_examenes_mayor, alumno_examen_promedio_alto, examen_promedio_alto;
    float promedio_alumnos[20], promedio_examenes[5], examenes_promedio_alto = 0.0;
    bool existencia = false, existencia_alumno = false;
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
    
    while (existencia && contador_alumnos < 20)
    {
        do
        {
            printf("Ingresa la matricula del alumno %d: ", contador_alumnos + 1);
        
            #if defined(_WIN32) || defined(_WIN64)
            fflush(stdin);
            #elif __linux__
                __fpurge(stdin);
            #endif

            scanf("%d", &matricula[contador_alumnos]);

            if (matricula[contador_alumnos] < 0)
            {
                #if defined(_WIN32) || defined(_WIN64)
                    system("cls");

                    printf("La matricula debe ser mayor a cero, verificar dato");
                    printf("\nPresiona la tecla ENTER para continuar. . . ");
                    fflush(stdin);
                    getchar();
                    system("cls");

                #elif __linux__
                    system("clear");

                    printf("La matricula debe ser mayor a cero, verificar dato");
                    fflush(stdout);
                    
                    printf("\nPresiona la tecla ENTER para continuar. . . ");
                    fflush(stdout);
                    __fpurge(stdin);
                    getchar();
                    
                    system("clear");

                #endif
            }

        } while (matricula[contador_alumnos] < 0);

        #if defined(_WIN32) || defined(_WIN64)
            system("cls");
        #elif __linux__
            system("clear");
        #endif
        
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
        
        #if defined(_WIN32) || defined(_WIN64)
            system("cls");
        #elif __linux__
            system("clear");
        #endif

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

    if (contador_alumnos > 0)
    {
        /* a */
        for ( i = 0; i < contador_alumnos; i++)
        {
            suma = 0;

            for ( j = 0; j < 5; j++)
            
                suma += calificaciones[i][j];
            
            promedio_alumnos[i] = (float) suma / 5;
        }
        

        /* b */
        i = 0;
        
        while (i < contador_alumnos)
        {
            if (calificaciones[i][2] > calificacion_mayor_3)
            {
                alumno_mejor_calificacion_3 = i + 1;
                calificacion_mayor_3 = calificaciones[i][2];
            }
            
            i++;
        }

        /* c */
        i = 0;

        while (i < contador_alumnos)
        {
            if (calificaciones[i][0] > calificacion_mayor_1 && calificaciones[i][4] > calificacion_mayor_5)
            {
                calificacion_mayor_1 = calificaciones[i][0];
                calificacion_mayor_5 = calificaciones[i][4];
                alumno_examenes_mayor = i;
            }
            
            i++;
        }

        /* d */
        do
        {
            printf("Escribe la matricula del alumno que desee consultar parcial con"
                " mayor calificacion:\n");

            for ( i = 0; i < contador_alumnos; i++)
            
                printf("- %d\n", matricula[i]);
            
            #if defined(_WIN32) || defined(_WIN64)
                fflush(stdin);
            #elif __linux__
                __fpurge(stdin);
            #endif

            scanf("%d", &matricula_consulta);

            i = 0;

            while (i < contador_alumnos && !existencia_alumno)
            {
                if (matricula_consulta == matricula[i])
                {
                    posicion_alumno = i;
                    existencia_alumno = true;
                }

                i++;
            }

            if (!existencia_alumno)
            {
                #if defined(_WIN32) || defined(_WIN64)
                    system("cls");

                    printf("Verifica que la matricula ingresada sea la correcta");
                    printf("\nPresiona la tecla ENTER para continuar. . . ");
                    fflush(stdin);
                    getchar();
                    system("cls");

                #elif __linux__
                    system("clear");

                    printf("Verifica que la matricula ingresada sea la correcta");
                    fflush(stdout);
                    
                    printf("\nPresiona la tecla ENTER para continuar. . . ");
                    fflush(stdout);
                    __fpurge(stdin);
                    getchar();
                    
                    system("clear");

                #endif
            }

        } while (!existencia_alumno);
        

        for ( i = 0; i < 5; i++)
        {
            if (calificaciones[posicion_alumno][i] > alumno_examen_mayor)
            {
                alumno_examen_mayor = calificaciones[posicion_alumno][i];
                alumno_examen_promedio_alto = i + 1;
            }
        }


        /* e */
        for ( j = 0; j < 5; j++)
        {
            suma = 0;

            for ( i = 0; i < contador_alumnos; i++)
            
                suma += calificaciones[i][j];
            
            promedio_examenes[j] = suma / contador_alumnos;
        }

        for ( i = 0; i < 5; i++)
        {
            if (promedio_examenes[i] > examenes_promedio_alto)
            {
                examenes_promedio_alto = promedio_examenes[i];
                examen_promedio_alto = i + 1;
            }
            
        }
        
        for ( i = 0; i < contador_alumnos; i++)
        {
            for ( j = 0; j < 5; j++)
            
                printf("[%d] ", calificaciones[i][j]);
            
            printf("\n");
        }
        
        printf("\nEl promedio de los alumnos es el siguiente: \n");

        for ( i = 0; i < contador_alumnos; i++)
        
            printf("\nAlumno %d matricula %d promedio de %.2f\n", i + 1, matricula[i], promedio_alumnos[i]);
        
        printf("\nEl alumno que obtuvo la mejor calificacion en el 3er parcial fue el alumno %d\n", alumno_mejor_calificacion_3);

        printf("\nEl alumno que obtuvo la mejor calificacion en el 1er y 5to parcial fue el alumno %d con matricula %d\n", alumno_examenes_mayor + 1, matricula[alumno_examenes_mayor]);

        printf("\nDado el alumno que busco el usuario, el examen el cual obtuvo mayor calificacion fue el examen %d con una calificacion de %d\n", alumno_examen_promedio_alto, calificaciones[posicion_alumno][alumno_examen_promedio_alto - 1]);

        printf("\nEl examen el cual obtuvo un mayor promedio de los %d alumnos fue el examen %d con un promedio de %.2f\n", contador_alumnos,examen_promedio_alto, promedio_examenes[examen_promedio_alto - 1] );
    }
    else
    
        printf("\nNo hay alumnos, operacion finalizada\n");
        
}
