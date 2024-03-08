/*  
    Elabora un programa que mediante una funcion, eleve un numero indicado por el 
    usuario, a la potencia tambien indicada por el. Validar que los numeros sean
    mayor a cero.

    Los datos y la impresion se realizan desde main

    La llamada a la funcion es por referencia
*/

#include <stdio.h>
#include <stdlib.h>
#if __linux__
    #include <stdio_ext.h>
#endif 

void elevar_numero(int, int, int *);
void validar_errores_por_SO();
void limpiar_buffer_STDIN();
void limpiar_terminal();
void pausar_terminal();

int main(void)
{
    int potencia, valor, numero, resultado;

    do
    {
        puts("Escribe un numero positivo: ");

        limpiar_buffer_STDIN();

        valor = scanf("%d", &numero);

        if (numero < 0 || valor != 1)
        
            validar_errores_por_SO();
        
        
    } while (numero < 0 || valor != 1);

    do
    {
        puts("A que potencia deseas elevarlo?: ");

        limpiar_buffer_STDIN();

        valor = scanf("%d", &potencia);

        if (potencia < 0 || valor != 1)
        
            validar_errores_por_SO();
        
    } while (potencia < 0 || valor != 1);
    
    elevar_numero(numero, potencia, &resultado);
    
    printf("El numero %d elevado a la %d es: %d\n", numero, potencia, resultado);
}


void elevar_numero(int NumeroP, int potencia_f, int *resultado_f)
{
    int i, resultado = 1;

    for (i = 1; i <= potencia_f; i++)
    
        resultado *= NumeroP;
    
    *resultado_f = resultado;
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