
/* 
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        En una empresa con N empleados se necesita obtener cierta informacion, por cada empleado 
        se ingresa los siguientes datos:

        - Clave (A o B)
        - Edad (0 a 65)
        - Sexo (F, f, M, m)
        - y sueldo > 0

        Hacer programa que calucle e imprima:

        a) Numero de hombres
        b) Numero de mujeres
        c) Numero de mujeres que ganan mas de $30,000
        d) Numero de hombres menores de 40 años que ganan menos de $40,000
        e) Numero de empleados mayores de 50 años
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Autor: Diego Leonardo Alejo Cantu
Fecha de actualizacion: 08/02/2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int main(void)
{

    int contador_mujeres = 0, contador_hombres = 0, contador_mujeres_2 = 0, contador_hombres_2 = 0, empleados_50 = 0, i, edad, sueldo, contador_empleados = 0;
    char respuesta_existencia, clave, sexo;
    bool existencia = false;

    do
    {
        printf("Existen empleados?\nS.Si\nN.No\n: ");
        #if defined(_WIN32) || defined(_WIN64)
            fflush(stdin);
        #endif
        scanf(" %c", &respuesta_existencia);
        #if __linux__
            while (getchar() != '\n')
        #endif

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
            printf("Ingresa la clave de el/la emplead@ %d: ", contador_empleados + 1);
            #if defined(_WIN32) || defined(_WIN64)
                fflush(stdin);
            #endif
            scanf("%c", &clave);
            #if __linux__
                while (getchar() != '\n')
            #endif

            clave = tolower(clave);

            #if defined(_WIN32) || defined(_WIN64)
            
                if (clave != 'a' && clave != 'b')
                {
                    system("cls");

                    printf("Ingresa una respuesta valida");
                    
                    printf("\nPresiona la tecla ENTER para continuar. . . ");
                    fflush(stdin);
                    getchar();
                    
                    system("cls");
                }
            #elif __linux__

                if (clave != 'a' && clave != 'b')
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

        } while (clave != 'a' && clave != 'b');
        
        do
        {
            printf("Ingresa la edad de el/la emplead@ %d:", contador_empleados + 1);
            scanf("%d", &edad);
            
            #if defined(_WIN32) || defined(_WIN64)

                if (edad < 0)
                {
                    system("cls");

                    printf("Ingresa una respuesta valida");
                    printf("\nPresiona la tecla ENTER para continuar. . . ");
                    fflush(stdin);
                    getchar();
                    
                    system("cls");
                }
                else if (edad < 18)
                    {
                        system("cls");

                        printf("No existen empleados menores de edad");
                        printf("\nPresiona la tecla ENTER para continuar. . . ");
                        fflush(stdin);
                        getchar();
                        
                        system("cls");
                    }
                    else if (edad > 65)
                        {
                            system("cls");

                            printf("No existen empleados mayores de 65 años");
                            printf("\nPresiona la tecla ENTER para continuar. . . ");
                            fflush(stdin);
                            getchar();
                            
                            system("cls");
                        }

            #elif __linux__
            
                if (edad < 0)
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
                else if(edad < 18)
                    {
                        system("clear");

                        printf("No existen empleados menores de edad");
                        fflush(stdout);
                        
                        printf("\nPresiona la tecla ENTER para continuar. . . ");
                        fflush(stdout);
                        while (getchar() != '\n');
                        getchar();
                        
                        system("clear");
                    }
                    else if (edad > 65)
                        {
                            system("clear");

                            printf("No existen empleados mayores de 65 años");
                            fflush(stdout);
                            
                            printf("\nPresiona la tecla ENTER para continuar. . . ");
                            fflush(stdout);
                            while (getchar() != '\n');
                            getchar();
                            
                            system("clear");
                        }
            #endif 

        } while (edad < 0 || edad < 18 || edad > 65);

    
    
        #if defined(_WIN32) || defined(_WIN64)
            system("cls");
        #elif __linux__
            system("clear");
        #endif 


        do
        {
            
        } while (sexo != 'f' && sexo != 'm');
        

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
                    
                        #if defined(_WIN32) || defined(_WIN64)
                            system("cls");
                        #elif __linux__
                            system("clear");
                        #endif 
                    }
            #endif 

        } while (respuesta_existencia != 's' && respuesta_existencia != 'n');

    }
    
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #elif __linux__
        system("clear");
    #endif 

    
    
    printf("\nOperacion finalizada! . . .\n");
}