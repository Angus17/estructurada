/* 
        Elaborar un ejemplo en C tal que almacene para 5 deportista
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

};

int main(void)
{
    struct Datos_deportistas datos[5];
    int longitud_cadena, contador_cadenas = 0, j, i;

    for ( i = 0; i < 5; i++)
    {
        
        do
        {
            printf("Escribe el nombre del deportista: ");
            #if __linux__
                __fpurge(stdin);
            #endif 
            gets(datos[i].nombre);

            datos.nombre[strcspn(datos[i].nombre, "\n")] = '\0';
            longitud_cadena = strlen(datos[i].nombre);

            j = 0;
            contador_cadenas = 0;
            while (datos[i].nombre[j] != '\0')
            {
                if (isalpha(datos[i].nombre[j]) || datos.nombre[j] == 32)
                
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
            scanf("%d", &datos[i].edad);


        } while (datos[i].edad < 0);

        do
        {
            printf("Ingresa ahora su peso: ");
            #if __linux__
                __fpurge(stdin);
            #elif defined(_WIN32)
                fflush(stdin);
            #endif 
            scanf("%f", &datos[i].peso);


        } while (datos[i].edad < 0);

        do
        {
            printf("Ingresa ahora su altura: ");
            #if __linux__
                __fpurge(stdin);
            #elif defined(_WIN32)
                fflush(stdin);
            #endif 
            scanf("%f", &datos[i].altura);


        } while (datos[i].edad < 0);

        #if defined(_WIN32) || defined(_WIN64)
            system("cls");
        #elif __linux__
            system("clear");
        #endif
    }
    

    printf("\nNombre del deportista: %s\n", datos.nombre);
    printf("Edad del deportista: %d\n", datos.edad);
    printf("Peso del deportista: %.2f\n", datos.peso);
    printf("Altura del deportista: %.2f\n", datos.altura);

}

/* Ahora hacer ejercicio 19 para 5 deportistas */