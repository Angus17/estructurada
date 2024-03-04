/*  
    Elabora un programa que mediante una funcion indique si en una cadena dada por
    el usuario (validar que sea solo letras y esacios)
    , se encuentra una letra (validar mayuscula o minuscula) indicada por el

    Los datos y la impresion se realizaran desde main

    La llamada a la funcion sera por referencia
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#if __linux__
    #include <stdio_ext.h>
#endif

bool validar_caracteres(char *);
bool buscar_caracteres(char *, char);
void validar_Sistema_Operativo();
void limpiar_buffer_STDIN();
void limpiar_terminal();
void pausar_terminal();


int main(void)
{
    char cadena[30], letra;
    bool cadena_correcta = false, caracter_encontrado = false;

    do
    {
        puts("Ingresa una cadena: ");
        
        limpiar_buffer_STDIN();

        fgets(cadena, 30, stdin);

        cadena[strcspn(cadena, "\n")] = '\0';

        cadena_correcta = validar_caracteres(cadena);

        if (!cadena_correcta)
        
            validar_Sistema_Operativo();

    } while (!cadena_correcta);

    do
    {
        puts("Ingrese un caracter el cual desee buscar: ");

        limpiar_buffer_STDIN();

        scanf(" %c", &letra);

        caracter_encontrado = buscar_caracteres(cadena, letra);

        if (!caracter_encontrado)
        
            validar_Sistema_Operativo();
            
        else
        
            puts("Caracter encontrado!");
        
    } while (!caracter_encontrado);
    
}

bool validar_caracteres(char *caracter)
{
    bool cadena_correcta = true;

    while (*caracter != '\0' && cadena_correcta)
    {
        if (!isalpha(*caracter) && *caracter != 32)
        
            cadena_correcta = false;

        caracter++;
    }
    
    return cadena_correcta;
}

bool buscar_caracteres(char *caracter, char caracter_a_buscar)
{
    bool caracter_encontrado = false;

    while (*caracter != '\0' && !caracter_encontrado)
    {
        if (caracter_a_buscar == *caracter)
        
            caracter_encontrado = true;

        caracter++;
    }
    

    return caracter_encontrado;

}

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
void validar_Sistema_Operativo()
{
    #if defined(_WIN32) || defined(_WIN64)
        limpiar_terminal();

        printf("Dato/s ingresado/s no valido/s, verificar dato/s");
        pausar_terminal();
        limpiar_terminal();
    #elif __linux__
        limpiar_terminal();

        printf("Dato/s ingresado/s no valido/s, verificar dato/s");
        fflush(stdout);
        
        printf("\nPresiona la tecla ENTER para continuar. . . ");
        fflush(stdout);
        limpiar_buffer_STDIN();
        getchar();
        
        limpiar_terminal();
    #endif
}