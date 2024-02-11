
/* 
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        Para un grupo de N alumnos, se require que calcule e imprima
        la matricula  el promedio de las 5 calificaciones de cada alumno

        Tambien obtener el promedio de todo el grupo
        validar que la calificacion sea entre 0 y 100
        
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Autor: Diego Leonardo Alejo Cantu
Fecha de actualizacion: 08/02/2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int main(void)
{

    int matricula, calificacion, suma = 0, suma_grupal = 0, contador_alumnos = 0, i;
    float promedio, promedio_grupal;
    char respuesta_existencia;
    bool existencia = false;

    do
    {
        printf("Existen alumnos?\nS.Si\nN.No\n: ");
        scanf(" %c", &respuesta_existencia);

        respuesta_existencia = tolower(respuesta_existencia);

        #if defined(_WIN32) || defined(_WIN64)

            if (respuesta_existencia != 's' && respuesta_existencia != 'n')
            {
                system("cls");

                printf("Ingresa una respuesta valida");
                printf("\nPresiona la tecla ENTER para continuar. . . ");
                fflush(stdin);
                getchar();
                
                system("cls");
            }
            else if (respuesta_existencia == 's')
            
                existencia = true;

        #elif __linux__
            
            if (respuesta_existencia != 's' && respuesta_existencia != 'n')
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
            else if (respuesta_existencia == 's')
            
                existencia = true;
        #endif 
        
        
    } while (respuesta_existencia != 's' && respuesta_existencia != 'n');

    #if defined(_WIN32) || defined(_WIN64)
            system("cls");
    #elif __linux__
        system("clear");
    #endif 
    
    while (existencia)
    {
        do
        {
            printf("Ingresa la matricula del alumn@ %d: ", contador_alumnos + 1);
            scanf("%d", &matricula);

            #if defined(_WIN32) || defined(_WIN64)
            
                if (matricula < 0)
                {
                    system("cls");

                    printf("Ingresa una respuesta valida");
                    
                    printf("\nPresiona la tecla ENTER para continuar. . . ");
                    fflush(stdin);
                    getchar();
                    
                    system("cls");
                }
            #elif __linux__

                if (matricula < 0)
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

        } while (matricula < 0);
        
        for ( i = 1; i < 6; i++)
        {
            do
            {
                printf("Ingresa la calificacion %d del alumn@ %d: ", i, contador_alumnos + 1);
                scanf("%d", &calificacion);
                
                #if defined(_WIN32) || defined(_WIN64)

                    if (calificacion < 0 ||  calificacion > 100)
                    {
                        system("cls");

                        printf("Ingresa una respuesta valida");
                        printf("\nPresiona la tecla ENTER para continuar. . . ");
                        fflush(stdin);
                        getchar();
                        
                        system("cls");
                    }

                #elif __linux__
                
                    if (calificacion < 0 ||  calificacion > 100)
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

            } while (calificacion < 0 ||  calificacion > 100);

            suma += calificacion;
            if (i == 5)
            
                promedio = suma / i;
        }
        
        #if defined(_WIN32) || defined(_WIN64)
            system("cls");
        #elif __linux__
            system("clear");
        #endif 

        printf("Alumno %d matricula %d", contador_alumnos + 1, matricula);
        printf("\nSu promedio es de %.2f\n\n", promedio);

        do
        {
            printf("Existen alumnos?\nS.Si\nN.No\n: ");
            scanf(" %c", &respuesta_existencia);

            respuesta_existencia = tolower(respuesta_existencia);

            #if defined(_WIN32) || defined(_WIN64)

                if (respuesta_existencia != 's' && respuesta_existencia != 'n')
                {
                    system("cls");

                    printf("Ingresa una respuesta valida");
                    printf("\nPresiona la tecla ENTER para continuar. . . ");
                    fflush(stdin);
                    getchar();
                    
                    system("cls");
                }
                else if (respuesta_existencia == 'n')
                
                        existencia = false;

                    else

                        suma = 0;

            #elif __linux__
                
                if (respuesta_existencia != 's' && respuesta_existencia != 'n')
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
                else if (respuesta_existencia == 'n')
                
                        existencia = false;

                    else
                    {
                        suma = 0;
                        
                        #if defined(_WIN32) || defined(_WIN64)
                            system("cls");
                        #elif __linux__
                            system("clear");
                        #endif 
                    }
            #endif 

        } while (respuesta_existencia != 's' && respuesta_existencia != 'n');

        suma_grupal += promedio;
        contador_alumnos++;
    }
    
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #elif __linux__
        system("clear");
    #endif 

    if (contador_alumnos != 0)
    {
        promedio_grupal = suma_grupal / contador_alumnos;
        printf("\nEl promedio grupal de l@s %d alumn@s es de: %.2f\n", contador_alumnos, promedio_grupal);
    }
    
    
    printf("\nOperacion finalizada! . . .\n");
}