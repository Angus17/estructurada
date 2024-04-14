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

int calcular_promedio(int[3][6], int);
void validar_errores_por_SO();
void limpiar_buffer_STDIN();
void limpiar_terminal();
void pausar_terminal();

int main(void)
{
    int opcion, calificaciones[3][6], i, j;
    bool datos_leidos = false, promedios_calculados = false;

    do
    {
        limpiar_terminal();

        do
        {
            printf("    %-s: \n", "MENU DE OPCIONES");
            printf("1. Lectura de datos\n");
            printf("2. Calculo de promedio\n");
            printf("3. Imprimir resultado\n");
            printf("4. Salir\n");
            printf("    %-s: ", "opcion");
            
            limpiar_buffer_STDIN();

            scanf("%d", &opcion);

            if (opcion < 1 || opcion > 4)
            
                validar_errores_por_SO();
            
        } while (opcion < 1 || opcion > 4);
        
        limpiar_terminal();

        switch (opcion)
        {
            case 1:
                if (datos_leidos)
                
                    puts("Ya leiste los datos, procede a calcular los promedios");
                
                else
                {
                    for ( i = 0; i < 3; i++)
                    {
                        for ( j = 0; j < 5; j++)
                        {
                            do
                            {
                                printf("Calificacion %d alumn@ %d: ", j + 1, i + 1);
                                
                                limpiar_buffer_STDIN();

                                scanf("%d", &calificaciones[i][j]);

                                if (calificaciones[i][j] < 0 || calificaciones[i][j] > 100)
                                
                                    validar_errores_por_SO();
                                
                            } while (calificaciones[i][j] < 0 || calificaciones[i][j] > 100);
                        }

                        limpiar_terminal();
                    }

                    datos_leidos = true;
                }
                
            break;

            case 2:
                if (!datos_leidos)
                
                    puts("Necesitas ingresar las calificaciones para obtener el promedio");

                else if (promedios_calculados)
                    
                        puts("Ya calculaste los promedios, ya puedes imprimir resultados");
                    
                    else
                    {
                        for ( i = 0; i < 3; i++)
                        
                            calificaciones[i][5] = calcular_promedio(calificaciones, i);
                        
                        promedios_calculados = true;
                        puts("Promedios calculados con exito!");
                    }
            break;

            case 3:
                if (!datos_leidos)
                
                    puts("Necesitas leer los datos primero y luego calcular promedios, para imprimir resultados");
                
                else if (!promedios_calculados)
                    
                        puts("Te falta calcular los promedios para poder imprimir resultados");
                    
                    else
                    {
                        for ( i = 0; i < 3; i++)
                        {
                            printf("Calificaciones del alumn@ %d: ", i + 1);
                            for ( j = 0; j < 5; j++)
                            
                                printf(" %d ", calificaciones[i][j]);
                            
                            printf("\n");
                        }
                        
                        for ( i = 0; i < 3; i++)
                        
                            printf("Alumn@ %d promedio de %d\n", i + 1, calificaciones[i][5]);
                    }
            break;
        }

        if (opcion != 4)
        
            pausar_terminal();

    } while (opcion != 4);
}

int calcular_promedio(int calificaciones_f[3][6], int index)
{
    int j, suma = 0;

    for ( j = 0; j < 5; j++)
    
        suma += calificaciones_f[index][j];

    return suma / 5;
}


void limpiar_buffer_STDIN()
{
    #if defined(_WIN32) || defined(_WIN64)
        rewind(stdin);
    #elif __linux
        __fpurge(stdin);
    #endif
}

void limpiar_terminal()
{
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #elif __linux
        system("clear");
    #endif
}

void pausar_terminal()
{
    #if defined(_WIN32) || defined(_WIN64)
        system("pause");
    #elif __linux
        printf("Presiona ENTER para continuar. . .");
        fflush(stdout);
        limpiar_buffer_STDIN();
        getchar();
    #endif
}

void validar_errores_por_SO()
{
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");

        printf("Dato ingresado no valido, verificar dato");
        printf("\nPresiona la tecla ENTER para continuar. . . ");
        rewind(stdin);
        getchar();
        system("cls");
    #elif __linux__
        system("clear");

        printf("Dato ingresado no valido, verificar dato");
        fflush(stdout);
        
        printf("\nPresiona la tecla ENTER para continuar. . . ");
        fflush(stdout);
        __fpurge(stdin);
        getchar();
        
        system("clear");
    #endif
}