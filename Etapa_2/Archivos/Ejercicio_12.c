/*  
    Elaborar un programa que para cada empleado lea: numero de empleado, nombre, 
    categoria, y sueldo

    Validarque el umero y sueldo sean ayor a cero y categoria A, B, C y D
    L informacion se guardara en un archivo secuencial

    1. Dar de alta empleado
    2. Listado de los empleados en forma tabular
    3. Listado con empleados cuyo sueldo es mayor a 10,000 en forma tabular
    4. Mostrar los datos de un empleado indicado por el usuario (ingresar nombre)
    5. Salir

    En main utilizar llamadas a funciones por referencia, para cada una de las opciones
    del menu
*/


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
#if __linux__
    #include <stdio_ext.h>
#endif

//Funciones del menu
void leer_datos_empleados(FILE *);
void listar_empleados(FILE *);
void listar_empleados_sueldo_mayor(FILE *);
void mostrar_empleado_usuario(FILE *);

// Validaciones y verificaciones
bool validar_cadenas(char *);
bool verificar_existencia_archivo(FILE *);
bool buscar_existencias_empleados(FILE *, char *);
bool buscar_existencias_sueldo_mayor(FILE *);
bool verificar_existencia_registros(FILE *);

// Funciones adicionales para el sistema
void validar_errores_por_SO();
void limpiar_buffer_STDIN();
void limpiar_terminal();
void pausar_terminal();

int main(void)
{
    FILE *file_empleados = NULL;
    char opcion;

    setlocale(LC_ALL, "es_MX.UTF-8");

    do
    {
        limpiar_terminal();
        do
        {
            puts("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
            printf("\n%45s\n\n", "MENÚ DE OPCIONES");
            puts("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
            puts("a. Dar de alta emplead@s");
            puts("b. Lista de l@s emplead@s");
            puts("c. Lista con empleados cuyo sueldo es mayor a 10,000");
            puts("d. Mostrar los datos de un empleado indicado por el usuario");
            puts("e. Salir");
            printf("Selecciona una opción: ");

            limpiar_buffer_STDIN();

            scanf("%c", &opcion);
            opcion = tolower(opcion);

            if (opcion < 'a' || opcion > 'd')
            
                validar_errores_por_SO();
            
        } while (opcion < 'a' || opcion > 'd');
        
        switch (opcion)
        {
            case 'a':
                leer_datos_empleados(file_empleados);
            break;

            case 'b':
                if (!verificar_existencia_archivo(file_empleados))
                
                    puts("No existe el registro de emplead@s");
                
                else
                
                    listar_empleados(file_empleados);
            break;

            case 'c':
                if (!verificar_existencia_archivo(file_empleados))
                
                    puts("No existe el registro de emplead@s");
                
                else
                
                    listar_empleados_sueldo_mayor(file_empleados);

            break;

            case 'd':
                if (!verificar_existencia_archivo(file_empleados))
                
                    puts("No existe el registro de emplead@s");
                
                else
                
                    mostrar_empleado_usuario(file_empleados);
            break;
        }

        if (opcion != 'e')
        
            pausar_terminal();

    } while (opcion != 'e');
}

void leer_datos_empleados(FILE *archivo)
{
    int sueldo, numero_empleado;
    static int contador_empleados = 0;
    char nombre[50], respuesta, categoria;
    bool cadena_valida;

    archivo = fopen("datos_empleados.txt", "a+");

    if (archivo == NULL)
    
        puts("No pudo abrirse el archivo");
    
    else
    {
        do
        {
            puts("Existen emplead@s?");
            puts("S. Sí");
            puts("N. No");
            printf(": ");

            limpiar_buffer_STDIN();

            scanf(" %c", &respuesta);

            respuesta = tolower(respuesta);

            if (respuesta != 's' && respuesta != 'n')
            
                validar_errores_por_SO();

        } while (respuesta != 's' && respuesta != 'n');

        if ((contador_empleados != 0 && respuesta != 'n') || verificar_existencia_registros(archivo))
        
            fprintf(archivo, "\n");

        while (respuesta == 's')
        {

            do
            {
                limpiar_terminal();

                printf("Escribe el nombre del/la emplead@: ");
                limpiar_buffer_STDIN();
                fgets(nombre, 50, stdin);

                nombre[strcspn(nombre, "\n")] = '\0';

                if (strlen(nombre) == 0)
                {
                    puts("Ingresa una cadena válida, no puedes usar cadenas vacías");
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

                    printf("# de empleado de %s: ", nombre);
                    limpiar_buffer_STDIN();
                } while (scanf("%d", &numero_empleado) != 1);

                if (numero_empleado <= 0)
                
                    validar_errores_por_SO();

            } while (numero_empleado <= 0);
            
            
        
        
            do
            {
                limpiar_terminal();

                printf("Categoría de %s (A-D)", nombre);
                limpiar_buffer_STDIN();
                scanf(" %c", &categoria);

                categoria = toupper(categoria);

                if (categoria < 'A' || categoria > 'D')
                
                    validar_errores_por_SO();

            } while (categoria < 'A' || categoria > 'D');

        

            do
            {
                do
                {
                    limpiar_terminal();

                    printf("Sueldo de %s: ", nombre);
                    limpiar_buffer_STDIN();
                } while (scanf("%d", &sueldo) != 1);

                if (sueldo <= 0)
                
                    validar_errores_por_SO();
                
            } while (sueldo <= 0);
            
            fprintf(archivo, "%-20d %-20s %-20c %-d", numero_empleado, nombre, categoria, sueldo);

            do
            {
                limpiar_terminal();

                puts("Existen más emplead@s?");
                puts("S. Sí");
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

            contador_empleados++;
        }

        fclose(archivo);
    }
}

void listar_empleados(FILE *archivo)
{
    int numero_empleado, sueldo;
    char nombre[50], categoria;

    archivo = fopen("datos_empleados.txt", "r");

    if (archivo == NULL)
    
        puts("No se pudo abrir el archivo, regresando al menú. . .");

    else
    {
        printf("\n%-20s %-20s %-20s %-20s\n", "# EMPLEAD@", "NOMBRE", "CATEGORÍA", "$UELDO");

        while (fscanf(archivo, "%d %50[^A-D] %c %d", &numero_empleado, nombre, &categoria, &sueldo) != EOF)
        
            printf("%-20d %-20s %-20c %-d\n", numero_empleado, nombre, categoria, sueldo);
        
        
        fclose(archivo);
    }

}

void listar_empleados_sueldo_mayor(FILE *archivo)
{
    int sueldo, numero_empleado, busqueda;
    char nombre[50], categoria;

    archivo = fopen("datos_empleados.txt", "r");

    if (archivo == NULL)
    
        puts("No se pudo abrir el archivo, regresando al menú. . .");
    else
    {
        
        if (buscar_existencias_sueldo_mayor(archivo))
        {
            printf("\n%-20s %-20s %-20s %-20s\n", "# EMPLEAD@", "NOMBRE", "CATEGORÍA", "$UELDO");

            while (fscanf(archivo, "%d %50[^A-D] %c %d", &numero_empleado, nombre, &categoria, &sueldo) != EOF)
            
                printf("%-20d %-20s %-20c %-d\n", numero_empleado, nombre, categoria, sueldo);
            
        
        }
        else
        
            puts("No existe registros de alumn@s en el semestre indicado");

        fclose(archivo);
    }
    
}

void mostrar_empleado_usuario(FILE *archivo)
{
    int sueldo, numero_empleado;
    char nombre[50], categoria, busqueda[50];

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
    archivo = fopen("datos_empleados.txt", "r");

    if (archivo == NULL)
    
        return false;
    
    else
    {
        fclose(archivo);
        return true;
    }
}

bool buscar_existencias_empleados(FILE *archivo, char *nombre_empleado)
{
    char nombre[50], categoria;
    int sueldo, numero_empleado;

    while (fscanf(archivo, "%d %50[^A-D] %c %d", &numero_empleado, nombre, &categoria, &sueldo) != EOF)
    {
        if (nombre_empleado == nombre)
        {
            rewind(archivo);
            return true;
        }
    }

    rewind(archivo);
    fclose(archivo);
    return false;
}

bool buscar_existencias_sueldo_mayor(FILE *archivo)
{
    char nombre[50], categoria;
    int sueldo, numero_empleado;

    while (fscanf(archivo, "%d %50[^A-D] %c %d", &numero_empleado, nombre, &categoria, &sueldo) != EOF)
    {
        if (sueldo > 10000)
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