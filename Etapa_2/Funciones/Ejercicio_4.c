/*  
    Elabora un programa que para 3 alumnos lea sus 5 calificaciones.
    Validar que se encuentren entre 0 y 100

    El programa funcionara de la siguiente manera:
        Menu de Opciones
    1. Lectura de datos
    2. Calculo de promedio
    3. Imprimir resultado
    4. Salir

        opcion: 

    Validar que la opcion se encuentra entre 1 y 4
    Elaborar una funcion para la opcion 2
    Los datos se guardaran en un arreglo bidimensional.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#if __linux__
    #include <stdio_ext.h>
#endif 

int calcular_promedio(int[][6]);
void validar_Sistema_Operativo(bool);

int main(void)
{
    int opcion, calificaciones[3][6], i, j;

    do
    {
        do
        {
            printf("%-10s: \n", "MENU DE OPCIONES");
            printf("1. Lectura de datos\n");
            printf("2. Calculo de promedio");
            printf("3. Imprimir resultado");
            printf("4. Salir");
            printf("%-10s: ", "opcion");
            
            scanf("%d", &opcion);

            if (opcion < 1 || opcion > 4)
            {
                #if defined(_WIN32) || defined(_WIN64)
                    validar_Sistema_Operativo(true);
                #elif __linux__
                    validar_Sistema_Operativo(false);
                #endif 
            }
            
        } while (opcion < 1 || opcion > 4);
        
        switch (opcion)
        {
            case 1:
                for ( i = 0; i < 3; i++)
                {
                    for ( j = 0; j < 5; j++)
                    {
                        do
                        {
                            printf("Calificacion %d alumn@ %d:", j + 1, i + 1);
                            
                            #if defined(_WIN32) || defined(_WIN64)
                                fflush(stdin);
                            #elif __linux__
                                __fpurge(stdin);
                            #endif

                            scanf("%d", &calificaciones[i][j]);

                            if (calificaciones[i][j] < 0 || calificaciones[i][j] > 100)
                            {
                                #if defined(_WIN32) || defined(_WIN64)
                                    validar_Sistema_Operativo(true);
                                #elif __linux__
                                    validar_Sistema_Operativo(false);
                                #endif 
                            }
                            
                        } while (calificaciones[i][j] < 0 || calificaciones[i][j] > 100);
                        
                    }
                    
                }
            break;

            case 2:
                for ( i = 0; i < 3; i++)
                
                    calificaciones[5][i] = calcular_promedio(calificaciones);
                
            break;

            case 3:
            break;
        }
    } while (opcion != 4);
}

int calcular_promedio(int calificaciones[][6])
{
    int i, j, suma = 0;

    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 5; j++)
        
            suma += calificaciones[i][j];
    }

    return suma / 5;
}

void validar_Sistema_Operativo(bool data)
{
    if (data)
    {
        system("cls");

        printf("Dato ingresado no valido, verificar dato");
        printf("\nPresiona la tecla ENTER para continuar. . . ");
        fflush(stdin);
        getchar();
        system("cls");
    }
    else
    {
        system("clear");

        printf("Dato ingresado no valido, verificar dato");
        fflush(stdout);
        
        printf("\nPresiona la tecla ENTER para continuar. . . ");
        fflush(stdout);
        __fpurge(stdin);
        getchar();
        
        system("clear");
    }
}