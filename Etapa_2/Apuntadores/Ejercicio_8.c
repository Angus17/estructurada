/*  
    Para un grupo de estados de la Republica, se conoce la cantidad de lluvia que se obtuvo 
    mensualmente el año anterior.

    Elabora un programa con el siguiente menu:

    a. Lectura de datos
    b. Calculo de promedio
    c. Estado con mayor lluvia considerando el promedio
    d. Estado con mayor lluvia en Mayo. 
    e. Imprimir desde una funcion los estados, la cantidad de lluvia y 
    su proomedio en forma tabular
    f. Salir

    Opcion a. El nombre del estado se guardara en un arreglo de apuntadores. Validar la cantidad
    de lluvia

    Elabora una funcion para cada opcion del meny y realizar llamadas por referencia
*/

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#if __linux__
    #include <stdio_ext.h>
#endif

bool validar_cadenas(char *);
void leer_datos(char *[], int []);
void calcular_promedio_lluvias(int *);
void validar_Sistema_Operativo();
void limpiar_buffer_STDIN();
void limpiar_terminal();
void pausar_terminal();



int main(void)
{
    char opcion, *estados_lluvias[32];
    bool *promedios_calculados = false;
    int lluvias[12];

    do
    {
        do
        {
            puts("**************************************");
            puts("            MENU DE OPCIONES");
            puts("************************** * * * * * * * * * * * *");
            puts("a. Lectura de Datos ");
            puts("b. Calculo de promedio ");
            puts("c. Estado con mayor lluvia considerando el promedio ");
            puts("d. Estado con mayor lluvia en Mayo ");
            puts("e. Impresion de datos obtenidos ");
            puts("f. Salir");
            puts("Selecciona una opcion: ");

            limpiar_buffer_STDIN();

            scanf(" %c", &opcion);
            opcion = tolower(opcion);

        } while (opcion < 'a' || opcion > 'f');

        switch (opcion)
        {
            case 'a':
            
            break;

            case 'b':

            break;

            case 'c':

            break;

            case 'd':

            break;

            case 'e':

            break;
        }
        
    } while (opcion != 'f');

    limpiar_terminal();

    puts("Operacion finalizada !");
    
}

void leer_datos(char *estados[], int lluvias_f[])
{
    bool cadena_valida;
    int i;

    do
    {
        puts("Escriba el estado de la Republica para ingresar datos de lluvias: ");

        limpiar_buffer_STDIN();

        fgets(*estados, 30, stdin);

        cadena_valida = validar_cadenas(*estados);
        
        if (!cadena_valida)
        
            validar_Sistema_Operativo();
        
    } while (!cadena_valida);

    for ( i = 0; i < 12; i++)
    {
        do
        {
            printf("Cuantas lluvias hubieron el mes %d del anio pasado en %s: ", i + 1, *estados);

            limpiar_buffer_STDIN();

            
        } while ();
        
        estados++;
    }
    
    

}

bool validar_cadenas(char *caracter)
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