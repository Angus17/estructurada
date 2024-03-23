/*  
    Elabora un programa que lee los siguientes datos.

    - Clave del planeta. Validar el numero entre 1 y 200
    - Dimension
    - Caracteristicas
    - Posibilidad de vida (dato bool)

    Leer y validar los datos mediante una estructura. Guardar los datos 
    en un archivo de acceso directo
    
    Elabora un menu:

    a.- Lectura de datos
    b.- Mostrar datos de planeta en particular 
    c.- Mostrar en forma tabular todos los planetas y sus datos que tienen posibilidad
    de vida

    d.- Mostrar en forma tabular todos los planetas y sus datos que en sus caracteristicas contienen la palabra
    agua.

    e .- Salir

    Validar la opcion indicada por el usuario
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>
#include <ctype.h>
#ifdef __linux__
    #include <stdio_ext.h>
#endif

struct Datos_Planetas
{
    int clave_planeta;
    long long int dimension;
    char caracteristicas[50];
    bool posibilidad_vida;
};

void leer_datos(FILE *, struct Datos_Planetas, int *);
void mostrar_planeta(FILE *, struct Datos_Planetas);
void mostrar_planetas_con_vida(FILE *, struct Datos_Planetas );
void mostrar_planetas_con_agua(FILE *, struct Datos_Planetas );

bool verificar_clave_repetida(FILE *, struct Datos_Planetas, int *);
bool encontrar_planeta(FILE *, struct Datos_Planetas, int *, int *);
bool buscar_planeta_vida(FILE *, struct Datos_Planetas);
bool buscar_planeta_agua(FILE *, struct Datos_Planetas);
bool validar_cadenas(char *);
bool existencia_archivo_datos(FILE *, struct Datos_Planetas);
void convertir_cadena_a_minuscula(char *);

void validar_errores_por_SO();
void limpiar_buffer_STDIN();
void limpiar_terminal();
void pausar_terminal();

int main(void)
{
    FILE *file_planetas;
    char opcion;
    int index = 0;
    struct Datos_Planetas datos;

    setlocale(LC_ALL, "es_MX.UTF-8");

    file_planetas = fopen("datos_planetas.dat", "rb");

    if (file_planetas == NULL)
    
        puts("No existe el archivo para almacenar los datos del programa. . .");
    
    else
    {
        file_planetas = freopen("datos_planetas.dat", "ab+", file_planetas);

        if (file_planetas == NULL)
        
            puts("Ocurrió un error al abrir el archivo. . .");
        
        else
        {
            do
            {
                do
                {
                    limpiar_terminal();

                    puts("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
                    printf("\n%45s\n\n", "MENÚ DE OPCIONES");
                    puts("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
                    puts("a. Lectura de datos");
                    puts("b. Datos de planeta (especificado por el usuario)");
                    puts("c. Planetas con posibilidad de vida");
                    puts("d. Planetas con Agua");
                    puts("e. Salir");
                    printf("Selecciona una opción: ");

                    limpiar_buffer_STDIN();

                    scanf(" %c", &opcion);
                    opcion = tolower(opcion);

                    if (opcion < 'a' || opcion > 'e')
                    
                        validar_errores_por_SO();

                } while (opcion < 'a' || opcion > 'e');

                limpiar_terminal();

                switch (opcion)
                {
                    case 'a':
                        if (index < 200)
                        
                            leer_datos(file_planetas, datos, &index);
                        
                        else
                        
                            puts("Ya no hay espacio para más datos. . .");

                        break;

                    case 'b':

                        if (!existencia_archivo_datos(file_planetas, datos))
                        
                            puts("Necesitas leer primero los datos de los planetas");
                        
                        else
                        
                            mostrar_planeta(file_planetas, datos);

                        break;

                    case 'c':

                        if (!existencia_archivo_datos(file_planetas, datos))
                        
                            puts("Necesitas leer primero los datos de los planetas");
                        
                        else
                        
                            mostrar_planetas_con_vida(file_planetas, datos);
                        
                        break;

                    case 'd':

                        if (!existencia_archivo_datos(file_planetas, datos))
                        
                            puts("Necesitas leer primero los datos de los planetas");
                        
                        else
                        
                            mostrar_planetas_con_agua(file_planetas, datos);
                        
                        break;

                    case 'e':

                        fclose(file_planetas);

                        break;
                }
                
                if (opcion != 'e')
                
                    pausar_terminal();

            } while (opcion != 'e');

            limpiar_terminal();
            
            puts("Operación finalizada con éxito");
        }
    }
}

void leer_datos(FILE *archivo_planetas, struct Datos_Planetas data, int *total_planetas)
{
    char respuesta[2], respuesta_vida[2];
    static int contador_planetas = 0;
    bool clave_repetida = false, cadena_valida;

    

    do
    {
        puts("Desea ingresar datos de planetas? Si/No");
        printf(": ");

        limpiar_buffer_STDIN();

        scanf(" %s", respuesta);

        convertir_cadena_a_minuscula(respuesta);

        if (strcmp(respuesta, "si") != 0 && strcmp(respuesta, "no") != 0)
        
            validar_errores_por_SO();

    } while (strcmp(respuesta, "si") != 0 && strcmp(respuesta, "no") != 0);

    while (strcmp(respuesta, "si") == 0 && contador_planetas < 200)
    {
        do
        {
            do
            {
                limpiar_terminal();

                puts("Ingresa la clave del planeta: ");
                limpiar_buffer_STDIN();
            } while (scanf("%d", &data.clave_planeta) != 1);
            
            if ((contador_planetas > 0 || existencia_archivo_datos(archivo_planetas, data)) && (data.clave_planeta >= 1 && data.clave_planeta <= 200))
            
                clave_repetida = verificar_clave_repetida(archivo_planetas, data, &data.clave_planeta);

            if (clave_repetida)
            {
                puts("La clave que ingresó ya fué utilizada");
                pausar_terminal();
            }
            else if (data.clave_planeta > 200 || data.clave_planeta < 1)
                
                    validar_errores_por_SO();
            

        } while (data.clave_planeta > 200 || data.clave_planeta < 1 || clave_repetida);

        do
        {
            do
            {
                limpiar_terminal();

                puts("Ingresa la dimensión ( radio en cm ) del planeta: ");
                limpiar_buffer_STDIN();
            } while (scanf("%lld", &data.dimension) != 1);
            
            if (data.dimension <= 0)
            
                validar_errores_por_SO();

        } while (data.dimension <= 0);

        do
        {
            limpiar_terminal();

            puts("Qué características tiene el planeta en cuestion?: ");
            limpiar_buffer_STDIN();
            fgets(data.caracteristicas, 50, stdin);

            data.caracteristicas[strcspn(data.caracteristicas, "\n")] = '\0';

            if (strlen(data.caracteristicas) == 0)
            {
                puts("Cadena vacía, ingresa datos");
                pausar_terminal();
            }
            else
            {
                cadena_valida = validar_cadenas(data.caracteristicas);

                if (!cadena_valida)
                
                    validar_errores_por_SO();
                
            }
        } while (strlen(data.caracteristicas) == 0 || !cadena_valida);

        do
        {
            limpiar_terminal();

            puts("Hay posibilidad de vida en ese planeta?: ");
            puts("- Si");
            puts("- No");
            printf(": ");

            limpiar_buffer_STDIN();

            scanf(" %s", respuesta_vida);

            convertir_cadena_a_minuscula(respuesta_vida);

            if (strcmp(respuesta_vida, "si") != 0 && strcmp(respuesta_vida, "no") != 0)
            
                validar_errores_por_SO();
            
            
        } while (strcmp(respuesta_vida, "si") != 0 && strcmp(respuesta_vida, "no") != 0);

        if (strcmp(respuesta_vida, "si") == 0)
        
            data.posibilidad_vida = true;
        
        else
        
            data.posibilidad_vida = false;
        
        fseek(archivo_planetas, contador_planetas * sizeof(struct Datos_Planetas), SEEK_SET);
        fwrite(&data, sizeof(struct Datos_Planetas), 1, archivo_planetas);


        contador_planetas++;
        
        if (contador_planetas < 200)
        {
            do
            {
                limpiar_terminal();

                puts("Desea ingresar más datos de planetas? Si/No");
                printf(": ");

                limpiar_buffer_STDIN();

                scanf(" %s", respuesta);

                convertir_cadena_a_minuscula(respuesta);

                if (strcmp(respuesta, "si") != 0 && strcmp(respuesta, "no") != 0)
                
                    validar_errores_por_SO();

            } while (strcmp(respuesta, "si") != 0 && strcmp(respuesta, "no") != 0);
        }
        else
        {
            limpiar_terminal();
            puts("Alcanzaste el límite máximo de datos");
        }
    }

    *total_planetas = contador_planetas;
}

void mostrar_planeta(FILE *archivo_planetas, struct Datos_Planetas data)
{
    int index_apuntador = 0, clave_busqueda;

    do
    {
        do
        {
            limpiar_terminal();
            puts("Que planeta desea buscar? Ingresa su clave: ");
            limpiar_buffer_STDIN();
        } while (scanf("%d", &clave_busqueda) != 1);

        if (clave_busqueda < 1 || clave_busqueda > 200)
        
            validar_errores_por_SO();

    } while (clave_busqueda < 1 || clave_busqueda > 200);

    if (encontrar_planeta(archivo_planetas, data, &clave_busqueda, &index_apuntador))
    {
        fseek(archivo_planetas, index_apuntador * sizeof(struct Datos_Planetas), SEEK_SET);
        fread(&data, sizeof(struct Datos_Planetas), 1, archivo_planetas);

        printf("\n%-30s %-30s %-50s %-s\n", "CLAVE PLANETA", "DIMENSIÓN (RADIO CM)", "CARACTERÍSTICAS", "VIDA?");

        if (data.posibilidad_vida)
        
            printf("\n%-30d %-30lld %-50s %-s\n", data.clave_planeta, data.dimension, data.caracteristicas, "SI");
        
        else
        
            printf("\n%-30d %-30lld %-50s %-s\n", data.clave_planeta, data.dimension, data.caracteristicas, "NO");

    }
    else
    
        puts("No se encontró su busqueda en el sistema. . .");

}

void mostrar_planetas_con_vida(FILE *archivo_planetas, struct Datos_Planetas data)
{
    
    if (buscar_planeta_vida(archivo_planetas, data))
    {
        rewind(archivo_planetas);

        printf("%-30s %-30s %-50s %-s\n", "CLAVE PLANETA", "DIMENSIÓN (RADIO CM)", "CARACTERÍSTICAS", "VIDA?");

        while (fread(&data, sizeof(struct Datos_Planetas), 1 , archivo_planetas) > 0)
        {
            if (data.posibilidad_vida)
            
                printf("\n%-30d %-30lld %-50s %-s\n", data.clave_planeta, data.dimension, data.caracteristicas, "SI");
            
        }
        
    }
    else
    
        puts("No existen planetas con posibilidad de vida");
    
}

void mostrar_planetas_con_agua(FILE *archivo_planetas, struct Datos_Planetas data)
{
    if (buscar_planeta_agua(archivo_planetas, data))
    {
        rewind(archivo_planetas);

        printf("%-30s %-30s %-50s %-s\n", "CLAVE PLANETA", "DIMENSIÓN (RADIO CM)", "CARACTERÍSTICAS", "VIDA?");

        while (fread(&data, sizeof(struct Datos_Planetas), 1, archivo_planetas) > 0)
        {
            if (strstr(data.caracteristicas, "agua") != NULL || strstr(data.caracteristicas, "Agua") != NULL)
            
                printf("\n%-30d %-30lld %-50s %-s\n", data.clave_planeta, data.dimension, data.caracteristicas, "SI");
            
        }
    }
    else
    
        puts("No existen planetas cuyas características contengan \"agua\"");

}

void convertir_cadena_a_minuscula(char *caracter)
{
    while (*caracter != '\0')
    {
        *caracter = tolower(*caracter);
        caracter++;
    }
}

bool verificar_clave_repetida(FILE *archivo_planetas, struct Datos_Planetas data, int *clave_ingresada)
{
    rewind(archivo_planetas);

    while (fread(&data, sizeof(struct Datos_Planetas), 1, archivo_planetas) > 0)
    {
        if (data.clave_planeta == *clave_ingresada)
        
            return true;
        
    }

    return false;

}

bool encontrar_planeta(FILE *archivo_planetas, struct Datos_Planetas data, int *busqueda, int *apuntador_index)
{
    int index = 0;

    rewind(archivo_planetas);

    while (fread(&data, sizeof(struct Datos_Planetas), 1, archivo_planetas) > 0)
    {
        if (data.clave_planeta == *busqueda)
        
            return true;

        index++;
        *apuntador_index = index;
    }

    return false;
}

bool buscar_planeta_vida(FILE *archivo_planetas, struct Datos_Planetas data)
{
    rewind(archivo_planetas);

    while (fread(&data, sizeof(struct Datos_Planetas), 1, archivo_planetas) > 0)
    {
        if (data.posibilidad_vida)
        
            return true;

    }
    
    return false;
}

bool buscar_planeta_agua(FILE *archivo_planetas, struct Datos_Planetas data)
{
    rewind(archivo_planetas);

    while (fread(&data, sizeof(struct Datos_Planetas), 1, archivo_planetas) > 0)
    {
        if (strstr(data.caracteristicas, "agua") != NULL || strstr(data.caracteristicas, "agua") != NULL)
        
            return true;

    }
    
    return false;
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

bool existencia_archivo_datos(FILE *archivo_planetas, struct Datos_Planetas data)
{
    rewind(archivo_planetas);
    
    fread(&data, sizeof(struct Datos_Planetas), 1, archivo_planetas);
    
    if (data.clave_planeta != 0)
    
        return true;

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