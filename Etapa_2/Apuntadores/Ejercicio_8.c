/*  
    Para un grupo de estados de la Republica, se conoce la cantidad de lluvia que se obtuvo 
    mensualmente el año anterior.

    Elabora un programa con el siguiente menu:

    a. Lectura de datos
    b. Calculo de promedio
    c. Estado con mayor lluvia considerando el promedio
    d. Estado con mayor lluvia en Mayo. 
    e. Imprimir desde una funcion los estados, la cantidad de lluvia y 
    su promedio en forma tabular
    f. Salir

    Opcion a. El nombre del estado se guardara en un arreglo de apuntadores. Validar la cantidad
    de lluvia

    Elabora una funcion para cada opcion del menu y realizar llamadas por referencia
*/

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#if __linux__
    #include <stdio_ext.h>
#endif

void leer_datos(char *[], int (*)[13], int *);
void calcular_promedio_lluvias(int (*)[13], int *, int *);
void estado_mayor_lluvia_promedio(char *[], int (*)[13], int *);
void estado_mayor_lluvia_Mayo(char *[], int (*)[13], int *);
void imprimir_resultados(char *[], int (*)[13], int *, int *);
bool validar_cadenas(char *);
bool verificar_estado(char *[], char *, int *);


void validar_errores_por_SO();
void limpiar_buffer_STDIN();
void limpiar_terminal();
void pausar_terminal();



int main(void)
{
    char opcion, *estados_lluvias[32];
    bool promedios_calculados = false, datos_leidos = false;
    int i, numero_datos_leidos = 0, datos_lluvias_anual[32][13], suma_lluvia[32];

    for ( i = 0; i < 32; i++)
    
        estados_lluvias[i] = malloc(sizeof estados_lluvias[i]); // Inicializando el arreglo de apuntadores
    
    do
    {
        limpiar_terminal();
        do
        {
            puts("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
            printf("\n%45s\n\n", "MENU DE OPCIONES");
            puts("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
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
        
        limpiar_terminal();

        switch (opcion)
        {
            case 'a':
                if (numero_datos_leidos != 32)
                {
                    promedios_calculados = false;
                    leer_datos(estados_lluvias, datos_lluvias_anual, &numero_datos_leidos);
                    
                    if (numero_datos_leidos != 0)
                    
                        datos_leidos = true;
                }
                else
                
                    puts("Has alcanzado el limite de datos, no puedes ingresar mas informacion");

            break;

            case 'b':
                if (!datos_leidos)
                
                    puts("Necesitas leer todos los datos de registros de lluvias");
                
                else if (promedios_calculados)
                    
                        puts("Ya has calculado todos los promedios por ahora");
                    
                    else
                    {
                        calcular_promedio_lluvias(datos_lluvias_anual, &numero_datos_leidos, suma_lluvia);
                        puts("Promedios calculados exitosamente !");
                        promedios_calculados = true;
                    }
            break;

            case 'c':
            if (!datos_leidos)
            
                puts("Necesitas leer todos los datos de registros de lluvias");
            
            else if (!promedios_calculados)
                
                    puts("Aun no has calculado todos los promedios existentes");
                
                else
                
                    estado_mayor_lluvia_promedio(estados_lluvias, datos_lluvias_anual, &numero_datos_leidos);
                
            

            break;

            case 'd':
                if (!datos_leidos)
                
                    puts("Necesitas leer todos los datos de registros de lluvias");
                
                else if (!promedios_calculados)
                    
                        puts("Aun no has calculado todos los promedios existentes");
                    
                    else
                    
                        estado_mayor_lluvia_Mayo(estados_lluvias, datos_lluvias_anual, &numero_datos_leidos);
                    
            break;

            case 'e':
                if (!datos_leidos)
                
                    puts("Necesitas leer todos los datos de registros de lluvias");
                
                else if (!promedios_calculados)
                    
                        puts("Aun no has calculado todos los promedios existentes");
                    
                    else
                    
                        imprimir_resultados(estados_lluvias, datos_lluvias_anual, &numero_datos_leidos, suma_lluvia);
                    
            break;

            case 'f':
                //RECORDAR liberar la memoria RAM reservada
                for ( i = 0; i < 32; i++)
                
                    free(estados_lluvias[i]);
                
            break;
        }
        
        if (opcion != 'f')
            pausar_terminal();

    } while (opcion != 'f');

    limpiar_terminal();

    puts("Operacion finalizada exitosamente !");
    
}

void leer_datos(char *estados[], int (*lluvias)[13], int *datos_ya_registrados)
{
    bool cadena_valida, estado_existente;
    char respuesta;
    int j;

    do
    {
        puts("Desea ingresar datos? ");
        puts("S. Si");
        puts("N. No ");
        printf(": ");

        limpiar_buffer_STDIN();

        scanf(" %c", &respuesta);
        respuesta = tolower(respuesta);

        if (respuesta != 's' && respuesta != 'n')
        
            validar_errores_por_SO();

    } while (respuesta != 's' && respuesta != 'n');
    
    while (respuesta == 's' && *datos_ya_registrados < 32)
    {
        do
        {
            printf("Escriba el estado #%d de la Republica para ingresar datos de lluvias: ", *datos_ya_registrados + 1);

            limpiar_buffer_STDIN();

            fgets(*(estados + *datos_ya_registrados), 50, stdin);
            
            estados[*datos_ya_registrados][strcspn(estados[*datos_ya_registrados], "\n")] = '\0';

            if (strlen(*(estados + *datos_ya_registrados)) != 0)
            {
                cadena_valida = validar_cadenas(*(estados + *datos_ya_registrados));
                estado_existente = verificar_estado(estados, *(estados + *datos_ya_registrados), datos_ya_registrados);

                if (!cadena_valida)
                
                    validar_errores_por_SO();
                else if (estado_existente)
                    {
                        printf("%s ya existe en el sistema, ingresa un estado diferente\n", estados[*datos_ya_registrados]);
                        pausar_terminal();
                        limpiar_terminal();
                    }
            }
            else
            
                puts("Cadena vacía, ingresa una cadena valida");
                
        } while (!cadena_valida || estado_existente || strlen(*(estados + *datos_ya_registrados)) == 0);

        for ( j = 0; j < 12; j++)
        {
            do
            {
                printf("Cuantas lluvias hubieron el mes %d del anio pasado en %s: ", j + 1, *(estados + *datos_ya_registrados));

                limpiar_buffer_STDIN();

                scanf("%d", &lluvias[*datos_ya_registrados][j]);

                if (lluvias[*datos_ya_registrados][j] < 0)
                
                    validar_errores_por_SO();

            } while (lluvias[*datos_ya_registrados][j] < 0);
        }

        do
        {
            puts("Desea ingresar mas datos? ");
            puts("S. Si");
            puts("N. No ");
            printf(": ");

            limpiar_buffer_STDIN();

            scanf(" %c", &respuesta);
            respuesta = tolower(respuesta);

            if (respuesta != 's' && respuesta != 'n')
            
                validar_errores_por_SO();

        } while (respuesta != 's' && respuesta != 'n');

        if (*datos_ya_registrados == 32)
        {
            puts("Has alcanzado el limite maximo de datos");
            pausar_terminal();
        }
        
        limpiar_terminal();

        (*datos_ya_registrados)++;
    }
}

void calcular_promedio_lluvias(int (*lluvias)[13], int *datos_ya_registrados, int *cantidad_lluvia)
{
    int i, j;

    for ( i = 0; i < *datos_ya_registrados; i++)
    {
        *cantidad_lluvia = 0;

        for ( j = 0; j < 12; j++)
        
            *cantidad_lluvia += (*(lluvias + i))[j];
        
        (*(lluvias + i))[13] = *cantidad_lluvia / 12;
        cantidad_lluvia++;
    }
}

void estado_mayor_lluvia_promedio(char *estados[], int (*lluvias)[13], int *datos_ya_registrados)
{
    int mayor_lluvias = 0, i, estado_indice;

    for ( i = 0; i < *datos_ya_registrados; i++)
    {
        if ((*(lluvias + i))[13] > mayor_lluvias)
        {
            mayor_lluvias = (*(lluvias + i))[13];
            estado_indice = i;
        }
    }
    
    printf("El estado con mayor lluvia reportada en el anio anterior, fue %s con un promedio de %d lluvias\n", *(estados + estado_indice), mayor_lluvias);
}

void estado_mayor_lluvia_Mayo(char *estados[], int (*lluvias)[13], int *datos_ya_registrados)
{
    int i, cantidad_lluvias = 0, indice_estado_mayor;

    for ( i = 0; i < *datos_ya_registrados; i++)
    {
        if ((*(lluvias + i))[4]  > cantidad_lluvias)
        {
            cantidad_lluvias = (*(lluvias + i))[4];
            indice_estado_mayor = i;
        }
    }

    printf("El estado que registró mayor número de lluvias en el mes de Mayo fué %s con %d lluvias\n", *(estados + indice_estado_mayor), cantidad_lluvias);
}

void imprimir_resultados(char *estados[], int (*lluvias)[13], int *datos_ya_registrados, int *cantidad_lluvia)
{
    int i;

    printf("%-34s  %-34s  %-34s\n\n", "ESTADOS", "# LLUVIA", "PROMEDIO LLUVIA");

    for ( i = 0; i < *datos_ya_registrados; i++)
    
        printf("%-34s   %-34d   %-34d\n", *(estados + i), *(cantidad_lluvia + i), (*(lluvias + i))[13]);

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

bool verificar_estado(char *estados[], char *busqueda, int *datos_ya_registrados)
{
    bool coincidencia = false;
    int i = 0;

    while (!coincidencia && i < *datos_ya_registrados)
    {
        if (strcmp(busqueda, *(estados + i)) == 0)
        
            coincidencia = true;

        i++;
    }
    
    return coincidencia;
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