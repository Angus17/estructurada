/*  
    Elabora un programa para que cada alumno lea su nombre, matricula, promedio, semestre

    Validar que la matricula sea mayor que cero, el nombre contenga solo letras y espacios
    el promedio este entre 0 y 100. El semestre esta entre 1 y 9

    La informacion se guardara en un archivo

    Mostrar al usuario el siguiente menu:

    1. Lectura de datos
    2. Lista de alumnos con promedio mayor o igual a 70. A partir del archivo
    3. Listado de alumnos del semestre



*/

/*  
    Hacer un programa que lea para varios alumnos, los datos anteriores, y guardarlos en un archivo

*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#if __linux__
    #include <stdio_ext.h>
#endif

void validar_errores_por_SO();
void limpiar_buffer_STDIN();
void limpiar_terminal();
void pausar_terminal();


int main(void)
{
    FILE *file;
    char nombres[50], fin;
    int promedios, matricula, semestre, contador_alumnos = 0;

    file = fopen("alumnos.txt", "w");

    if (file == NULL)
    
        puts("No se pudo abrir el archivo");
    
    else
    {
        // Windows: Ctrl + Z  Linux: Ctrl + D
        while (!feof(stdin))
        {
            printf("Escribe el nombre del alumno %d: ", contador_alumnos + 1);
            limpiar_buffer_STDIN();
            fgets(nombres, sizeof nombres, stdin);

            nombres[strcspn(nombres, "\n")] = '\0';

            printf("Ahora su matricula: ");
            scanf("%d", &matricula);

            printf("Su promedio: ");
            scanf("%d", &promedios);

            printf("Por ultimo su semestre: ");
            scanf("%d", &semestre);

            printf("?: ");
            limpiar_buffer_STDIN();
            fin = getchar();

            limpiar_terminal();
            
            
            
            fprintf(file,"%-20s %-20d  %-20d %-d", nombres, matricula, promedios, semestre);
            
            if (fin != -1)
            
                fprintf(file,"\n");

            contador_alumnos++;
        }

        fclose(file);
    }
}

// Limpia buffer STDIN tanto para sistemas Windows como para UNIX/Linux
void limpiar_buffer_STDIN()
{
    #if defined(_WIN32) || defined(_WIN64)
        fflush(stdin);
    #elif __linux__
        __fpurge(stdin);
    #endif
}

// Limpia terminal tanto para sistemas Windows como para UNIX/Linux
void limpiar_terminal()
{
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #elif __linux__
        system("clear");
    #endif
}

// Pausa la terminal tanto para sistemas Windows como para UNIX/Linux
void pausar_terminal()
{
    #if defined(_WIN32) || defined(_WIN64)
        system("pause");
    #elif __linux__
        printf("Presiona ENTER para continuar. . .");
        fflush(stdout);
        limpiar_buffer_STDIN();
        getchar();
    #endif
}

// Clasifica los mensajes de error tanto para Windows como para UNIX/Linux, cuando se ingresan datos incorrectos
void validar_errores_por_SO()
{
    #if defined(_WIN32) || defined(_WIN64)
        limpiar_terminal();

        printf("Dato/s ingresado/s no valido/s, verificar dato/s\n");
        pausar_terminal();
        limpiar_terminal();
    #elif __linux__
        limpiar_terminal();

        printf("Dato/s ingresado/s no valido/s, verificar dato/s\n");
        fflush(stdout);
        
        pausar_terminal();
        limpiar_terminal();
    #endif
}