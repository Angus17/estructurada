/*  
    Elabora un programa para que cada alumno lea su nombre, matricula, promedio, semestre

    Validar que la matricula sea mayor que cero, el nombre contenga solo letras y espacios
    el promedio este entre 0 y 100. El semestre esta entre 1 y 9

    La informacion se guardara en un archivo

    Mostrar al usuario el siguiente menu:

    1. Lectura de datos
    2. Lista de alumnos con promedio mayor o igual a 70. A partir del archivo
    3. Listado de alumnos del semestre indicado por el usuario. A partir el archivo
    4. Salir

    Usar funciones

    NO USAR ARREGLOS NI ESTRUCTURAS

    PENDIENTE
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#if __linux__
    #include <stdio_ext.h>
#endif

//Funciones del menu
void leer_datos(FILE *);
void listar_empleados(FILE *);
void listar_empleados_sueldo_mayor(FILE *);

// Validaciones y verificaciones
bool validar_cadenas(char *);
bool verificar_existencia_archivo(FILE *);
bool buscar_existencias_empleados(FILE *);
bool buscar_existencias_sueldo_mayor(FILE *, int);
bool verificar_existencia_registros(FILE *);

// Funciones adicionales para el sistema
void validar_errores_por_SO();
void limpiar_buffer_STDIN();
void limpiar_terminal();
void pausar_terminal();

int main(void)
{
    FILE *file_alumnos = NULL;
    char opcion;

    do
    {
        limpiar_terminal();
        do
        {
            puts("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
            printf("\n%45s\n\n", "MENU DE OPCIONES");
            puts("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
            puts("a. Leer datos");
            puts("b. Lista de alumnos con promedio mayor o igual a 70.");
            puts("c. Listado de alumnos del semestre indicado por el usuario.");
            puts("d. Salir");
            printf("Selecciona una opcion: ");

            limpiar_buffer_STDIN();

            scanf("%c", &opcion);
            opcion = tolower(opcion);

            if (opcion < 'a' || opcion > 'd')
            
                validar_errores_por_SO();
            
        } while (opcion < 'a' || opcion > 'd');
        
        switch (opcion)
        {
            case 'a':
                leer_datos(file_alumnos);
            break;

            case 'b':
                if (!verificar_existencia_archivo(file_alumnos))
                
                    puts("No existe el registro de alumn@s");
                
                else
                
                    listar_empleados(file_alumnos);
            break;

            case 'c':
                if (!verificar_existencia_archivo(file_alumnos))
                
                    puts("No existe el registro de alumn@s");
                
                else
                
                    listar_empleados_sueldo_mayor(file_alumnos);

            break;

            case 'd':
            break;
        }

        if (opcion != 'd')
        
            pausar_terminal();

    } while (opcion != 'd');
}

void leer_datos(FILE *archivo)
{
    int matricula, promedio, semestre;
    static int contador_alumnos = 0;
    char nombre[50], respuesta;
    bool cadena_valida;

    archivo = fopen("datos_alumnos.txt", "a+");

    if (archivo == NULL)
    
        puts("No pudo abrirse el archivo");
    
    else
    {
        do
        {
            puts("Existen alumn@s?");
            puts("S. Si");
            puts("N. No");
            printf(": ");

            limpiar_buffer_STDIN();

            scanf(" %c", &respuesta);

            respuesta = tolower(respuesta);

            if (respuesta != 's' && respuesta != 'n')
            
                validar_errores_por_SO();

        } while (respuesta != 's' && respuesta != 'n');

        if ((contador_alumnos != 0 && respuesta != 'n') || verificar_existencia_registros(archivo))
        
            fprintf(archivo, "\n");

        while (respuesta == 's')
        {

            do
            {
                limpiar_terminal();

                printf("Escribe el nombre del alumno: ");
                limpiar_buffer_STDIN();
                fgets(nombre, 50, stdin);

                nombre[strcspn(nombre, "\n")] = '\0';

                if (strlen(nombre) == 0)
                {
                    puts("Ingresa una cadena valida, no puedes usar cadenas vacias");
                    pausar_terminal();
                    limpiar_terminal();
                }
                else
                {
                    cadena_valida = validar_cadenas(nombre);

                    if (!cadena_valida)
                    
                        validar_errores_por_SO();
                    
                }
            } while (strlen(nombre) == 0 || !cadena_valida);
            
            do
            {
                do
                {
                    limpiar_terminal();

                    printf("Matricula de %s: ", nombre);
                    limpiar_buffer_STDIN();
                } while (scanf("%d", &matricula) != 1);

                if (matricula < 0)
                
                    validar_errores_por_SO();

            } while (matricula < 0);
            
            
            do
            {
                do
                {
                    limpiar_terminal();

                    printf("Promedio de %s: ", nombre);
                    limpiar_buffer_STDIN();
                } while (scanf("%d", &promedio) != 1);

                if (promedio < 0 || promedio > 100)
                
                    validar_errores_por_SO();

            } while (promedio < 0 || promedio > 100);

            do
            {
                do
                {
                    limpiar_terminal();

                    printf("Semestre de %s: ", nombre);
                    limpiar_buffer_STDIN();
                } while (scanf("%d", &semestre) != 1);

                if (semestre < 1 || semestre > 9)
                
                    validar_errores_por_SO();
                
            } while (semestre < 1 || semestre > 9);
            
            fprintf(archivo, "%-20s  %-20d  %-20d  %-d", nombre, matricula, promedio, semestre);

            do
            {
                limpiar_terminal();

                puts("Existen mas alumn@s?");
                puts("S. Si");
                puts("N. No");
                printf(": ");

                limpiar_buffer_STDIN();

                scanf(" %c", &respuesta);

                respuesta = tolower(respuesta);

                if (respuesta != 's' && respuesta != 'n')
                
                    validar_errores_por_SO();
                    
            } while (respuesta != 's' && respuesta != 'n');

            if (respuesta != 'n')
            
                fprintf(archivo, "\n");

            contador_alumnos++;
        }

        fclose(archivo);
    }
}

void listar_empleados(FILE *archivo)
{
    int promedio, matricula, semestre;
    char nombre[50];

    archivo = fopen("datos_alumnos.txt", "r");

    if (archivo == NULL)
    
        puts("No se pudo abrir el archivo, regresando al menu. . .");
    
    else if (!buscar_existencias_empleados(archivo))
        
            puts("No existen alumn@s con promedio mayor");
        
        else
        {
            printf("\n%-20s %-20s %-20s %-20s\n", "NOMBRE", "MATRICULA", "PROMEDIO", "SEMESTRE");

            while (fscanf(archivo, "%50[^0-9] %d %d %d", nombre, &matricula, &promedio, &semestre) != EOF)
            {
                if (promedio >= 70)
                
                    printf("%-20s %-20d %-20d %-20d\n", nombre, matricula, promedio, semestre);
            }
            
            fclose(archivo);
        }
    
}

void listar_empleados_sueldo_mayor(FILE *archivo)
{
    int promedio, matricula, semestre, busqueda;
    char nombre[50];

    archivo = fopen("datos_alumnos.txt", "r");

    if (archivo == NULL)
    
        puts("No se pudo abrir el archivo, regresando al menu. . .");
    else
    {
        do
        {
            do
            {
                puts("De que semestre desea buscar alumnos?: ");
                limpiar_buffer_STDIN();
            } while (scanf("%d", &busqueda) != 1);
            
            if (busqueda < 1 || busqueda > 9)
            
                validar_errores_por_SO();
        } while (busqueda < 1 || busqueda > 9);
        
        if (buscar_existencias_sueldo_mayor(archivo, busqueda))
        {
            printf("\n%-20s %-20s %-20s %-20s\n", "NOMBRE", "MATRICULA", "PROMEDIO", "SEMESTRE");

            while (fscanf(archivo, "%50[^0-9] %d %d %d", nombre, &matricula, &promedio, &semestre) != EOF)
            {
                if (semestre == busqueda)
                
                    printf("%-20s %-20d %-20d %-20d\n", nombre, matricula, promedio, semestre);
            }
        }
        else
        
            puts("No existe registros de alumn@s en el semestre indicado");

        fclose(archivo);
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

bool verificar_existencia_archivo(FILE *archivo)
{
    archivo = fopen("datos_alumnos.txt", "r");

    if (archivo == NULL)
    
        return false;
    
    else
    {
        fclose(archivo);
        return true;
    }
}

bool buscar_existencias_empleados(FILE *archivo)
{
    char nombre[50];
    int matricula, promedio, semestre;

    while (fscanf(archivo, "%50[^0-9] %d %d %d", nombre, &matricula, &promedio, &semestre) != EOF)
    {
        if (promedio >= 70)
        {
            rewind(archivo);
            return true;
        }
    }

    rewind(archivo);
    fclose(archivo);
    return false;
}

bool buscar_existencias_sueldo_mayor(FILE *archivo, int semestre_busqueda)
{
    char nombre[50];
    int matricula, promedio, semestre;

    while (fscanf(archivo, "%50[^0-9] %d %d %d", nombre, &matricula, &promedio, &semestre) != EOF)
    {
        if (semestre == semestre_busqueda)
        {
            rewind(archivo);
            return true;
        }
    }

    rewind(archivo);
    fclose(archivo);
    return false;
}

bool verificar_existencia_registros(FILE *archivo)
{
    char nombre[50];
    int matricula, promedio, semestre;

    if (fscanf(archivo, "%50[^0-9] %d %d %d", nombre, &matricula, &promedio, &semestre) == 4)
    {
        rewind(archivo);
        return true;
    }
    else
    
        return false;
    

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