/* 
Elaborar un programa que para cada pelicula lea la siguiente informacion: 
- Clave de pelicula
- Descripcion
- Categoria (A: Drama, B: Suspenso, C: Misterio, D: Infantil)
- Inventario

A lo mas son 50 claves de peliculas.

Mostrar el siguiente Menu:

1.- Leer Datos y guardarlos en archivo secuencial
2.- Mostrar las peliculas de la categoria indicada por el usuario (desde el archivo secuencial)
3.- Leero datos y guardarlos en archivo de acceso directo
4.- Mostrar las peliculas de la categoria indicada por el usuario
5.- Actualizar el inventario de la pelicula desde el archivo directo
6.- Salir

Utilizar una estructura para los datos del archivo
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <locale.h>
#include <stdbool.h>
#include <ctype.h>
#ifdef __linux__
    #include <stdio_ext.h>
#endif

#define BYTES_MAXIMO 1000

struct Datos_Peliculas
{
    int clave;
    char descripcion[200], categoria;
    int inventario;
};

void crear_archivo_binario(FILE *, const char *);

void validar_errores_por_SO();
void limpiar_buffer_STDIN();
void limpiar_terminal();
void pausar_terminal();

int main(void)
{
    struct Datos_Peliculas datos;
    FILE *file_peliculas_secuencial, *file_peliculas_binario;
    char *ruta_archivo_peliculas_secuencial, *ruta_archivo_peliculas_directo;
    ruta_archivo_peliculas_secuencial = (char *) malloc(sizeof(char) * BYTES_MAXIMO);
    ruta_archivo_peliculas_directo = (char *) malloc(sizeof(char) * BYTES_MAXIMO);

    if (ruta_archivo_peliculas_secuencial == NULL || ruta_archivo_peliculas_directo == NULL)
    {
        fprintf(stderr, "ERROR AL ASIGNAR MEMORIA. . .");
        fflush(stderr);
    }
    else
    {
        getcwd(ruta_archivo_peliculas_secuencial, sizeof(ruta_archivo_peliculas_secuencial) * BYTES_MAXIMO);
        strcat(ruta_archivo_peliculas_secuencial, "/Peliculas_Sec.dat");

        getcwd(ruta_archivo_peliculas_directo, sizeof(ruta_archivo_peliculas_directo) * BYTES_MAXIMO);
        strcat(ruta_archivo_peliculas_directo, "/Peliculas_Bin.dat");

        file_peliculas_binario = fopen(ruta_archivo_peliculas_directo, "rb");

        if (file_peliculas_secuencial == NULL || file_peliculas_secuencial == NULL)
            crear_archivo_binario(file_peliculas_binario, ruta_archivo_peliculas_directo);
        else
        {

        }
    }
}

void crear_archivo_binario(FILE *peliculas_binario, const char *directorio)
{
    struct Datos_Peliculas data = {0, "", '\0', 0};

    peliculas_binario = fopen(directorio, "wb");

    if (peliculas_binario)
    {
        fprintf(stderr, "ERROR DE ARCHIVO, INTENTE MAS TARDE. . .");
        fflush(stderr);
    }
    else
    {
        int i;

        for ( i = 0; i < 50; i++)
        
            fwrite(&data, sizeof(struct Datos_Peliculas), 1, peliculas_binario);

        printf("Espacio binario creado exitosamente!");
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

        printf("Dato/s ingresado/s no válido/s, verificar dato/s\n");
        pausar_terminal();
        limpiar_terminal();
    #elif __linux__
        limpiar_terminal();

        printf("Dato/s ingresado/s no válido/s, verificar dato/s\n");
        fflush(stdout);
        pausar_terminal();
        limpiar_terminal();
    #endif
}
