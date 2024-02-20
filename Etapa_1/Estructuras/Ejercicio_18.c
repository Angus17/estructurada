/* 
        Elaborar un ejemplo en C ral que almacene para un deportista
        los siguientes datos:

        - Nombre
        - Edad
        - Peso
        - Altura

        Imprimir los datos al finalizar
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#ifdef __linux__
    #include <stdio_ext.h>
#endif 

struct Datos_deportistas
{
    char nombre[50];
    int edad;
    float peso, altura;

}Datos_deportistas;

int main(void)
{
    struct Datos_deportistas datos;
    int longitud_cadena, contador_cadenas = 0, j;

    do
    {
        printf("Escribe el nombre del deportista: ");
        #if __linux__
            __fpurge(stdin);
        #endif 
        gets(datos.nombre);

        datos.nombre[strcspn(datos.nombre, "\n")] = '\0';
        longitud_cadena = strlen(datos.nombre);

        j = 0;
        contador_cadenas = 0;
        while (datos.nombre[j] != '\0')
        {
            if (isalpha(datos.nombre[j]) || datos.nombre[j] == 32)
            
                contador_cadenas++;
            
            j++;
        }
        


    } while (longitud_cadena == 0 || contador_cadenas != longitud_cadena);

    do
    {
        printf("Ingresa ahora su edad: ");
        #if __linux__
            __fpurge(stdin);
        #elif defined(_WIN32)
            fflush(stdin);
        #endif 
        scanf("%d", &datos.edad);


    } while (datos.edad < 0);

    do
    {
        printf("Ingresa ahora su peso: ");
        #if __linux__
            __fpurge(stdin);
        #elif defined(_WIN32)
            fflush(stdin);
        #endif 
        scanf("%f", &datos.peso);


    } while (datos.edad < 0);

    do
    {
        printf("Ingresa ahora su altura: ");
        #if __linux__
            __fpurge(stdin);
        #elif defined(_WIN32)
            fflush(stdin);
        #endif 
        scanf("%f", &datos.altura);


    } while (datos.edad < 0);

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #elif __linux__
        system("clear");
    #endif

    printf("\nNombre del deportista: %s\n", datos.nombre);
    printf("Edad del deportista: %d\n", datos.edad);
    printf("Peso del deportista: %.2f\n", datos.peso);
    printf("Altura del deportista: %.2f\n", datos.altura);

}

/* Ahora hacer ejercicio 19 para 5 deportistas */