/* 
    Para un grupo de N estudiantes (a lo mucho 50) ingresar sus 5 calificaciones 

    Mostrar el menu al siguiente usuario:

        Opciones:

        a) Lectura y validacion de datos
        b) listado de nombres y matricula con promedio >= 90
        c) listado de nombres y matricula con promedio >= 90 en computacion
        d) Listado de nombre y matricula de mayor promedio indicado por el usuario
        e) Salir

    De acuerdo a la opcion seleccionada por el usuario, hacer una llamada a funcion en cada opcion

    Tambien crear funciones para las validaciones que se deban realizar en la lectura de datos
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#if __linux__
    #include <stdio_ext.h>
#endif 

void validar_Sistema_Operativo();
void limpiar_buffer_STDIN();
void limpiar_terminal();
void pausar_terminal();


int main(void)
{
    char opcion;
    bool datos_leidos = false;
    int retorno = 0;

    do
    {
        do
        {
            printf("    %-s: \n", "MENU DE OPCIONES");
            printf("a). Lectura de datos\n");
            printf("b). Listado de nombres y matricula para alumnos con promedio >= 90\n");
            printf("c). Listado de nombres y matricula para alumnos con promedio >= 90 en computacion\n");
            printf("d). Listado de nombre y matricula de mayor promedio indicado por el usuario\n");
            printf("e). Salir\n");
            printf("    %-s: ", "opcion");
            
            limpiar_buffer_STDIN();

            retorno = scanf(" %c", &opcion);

            if (opcion < 'a' || opcion > 'e')
            {
                validar_Sistema_Operativo();
                retorno--;
            }

        } while (retorno != 1);
        
    } while (opcion != 'e');
    



}


void limpiar_buffer_STDIN()
{
    #if defined(_WIN32) || defined(_WIN64)
        fflush(stdin);
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

void validar_Sistema_Operativo()
{
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");

        printf("Dato ingresado no valido, verificar dato");
        printf("\nPresiona la tecla ENTER para continuar. . . ");
        fflush(stdin);
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