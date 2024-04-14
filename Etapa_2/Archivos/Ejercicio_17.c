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
3.- Leer datos y guardarlos en archivo de acceso directo
4.- Mostrar las peliculas de la categoria indicada por el usuario
5.- Actualizar el inventario de la pelicula desde el archivo directo (solicitando clave)
6.- Salir

Utilizar una estructura para los datos del archivo
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
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
    char descripcion[200], categoria[3];
    int inventario;
};

struct Files_Requeridos
{
    FILE *file_peliculas_secuencial;
    FILE *file_peliculas_binario;
};

struct Directorios
{
    char *ruta_archivo_peliculas_secuencial; 
    char *ruta_archivo_peliculas_directo;
};

struct Total_Datos
{
    int total_peliculas_secuencial;
    int total_peliculas_binario;
};

struct Campos
{
    struct Datos_Peliculas data;
    struct Files_Requeridos files;
    struct Directorios pwd;
    struct Total_Datos total;
};

void leer_datos(struct Campos *, struct Total_Datos *, const int *);
void mostrar_pelicula( struct Files_Requeridos *, const int *);
void actualizar_inventario(FILE *, const int *);

bool buscar_existencia_categoria( struct Files_Requeridos *,struct Datos_Peliculas, const int *, const char *);
bool contar_existencias(struct Files_Requeridos *, struct Datos_Peliculas, struct Total_Datos *, const int *);

bool verificar_clave_repetida(FILE *, const int *, const int *);
bool validar_cadenas(const char *);
bool crear_archivos(FILE *, FILE *, struct Directorios *);
void convertir_cadena_a_minuscula(char *);

void validar_errores_por_SO();
void limpiar_buffer_STDIN();
void limpiar_terminal();
void pausar_terminal();

int main(void)
{
    struct Campos datos;
    int opcion;
    const int archivo_secuencial = 1, archivo_binario = 2;

    setlocale(LC_ALL, "es_MX.UTF-8");

    datos.pwd.ruta_archivo_peliculas_secuencial = malloc(sizeof(char) * BYTES_MAXIMO);
    datos.pwd.ruta_archivo_peliculas_directo = malloc(sizeof(char) * BYTES_MAXIMO);

    if (datos.pwd.ruta_archivo_peliculas_secuencial == NULL || datos.pwd.ruta_archivo_peliculas_directo == NULL)
    
        fprintf(stderr, "ERROR AL ASIGNAR MEMORIA. . .");
    
    else
    {
        getcwd(datos.pwd.ruta_archivo_peliculas_secuencial, sizeof(datos.pwd.ruta_archivo_peliculas_secuencial) * BYTES_MAXIMO);
        strcat(datos.pwd.ruta_archivo_peliculas_secuencial, "/Files_Requeridos/Peliculas_Sec.txt");

        getcwd(datos.pwd.ruta_archivo_peliculas_directo, sizeof(datos.pwd.ruta_archivo_peliculas_directo) * BYTES_MAXIMO);
        strcat(datos.pwd.ruta_archivo_peliculas_directo, "/Files_Requeridos/Peliculas_Bin.dat");

        if (crear_archivos(datos.files.file_peliculas_binario, datos.files.file_peliculas_secuencial, &datos.pwd))
        {
            datos.total.total_peliculas_binario = 0;
            datos.total.total_peliculas_secuencial = 0;

            datos.files.file_peliculas_secuencial = fopen(datos.pwd.ruta_archivo_peliculas_secuencial, "a+");
            datos.files.file_peliculas_binario = fopen(datos.pwd.ruta_archivo_peliculas_directo, "rb+");

            do
            {
                do
                {
                    limpiar_terminal();

                    printf( "%88s\n", "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
                    printf("\n%16s%45s%28s\n\n", "* *", "MENÚ DE OPCIONES", "* *");
                    printf("%88s\n", "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
                    printf("\n%50s\n", "1) Leer Datos (SECUENCIAL)");
                    printf("\n%82s\n", "2) Mostrar película por categoría ingresada (SECUENCIAL)");
                    printf("\n%47s\n", "3) Leer Datos (BINARIO)");
                    printf("\n%79s\n", "4) Mostrar película por categoría ingresada (BINARIO)");
                    printf("\n%71s\n", "5) Actualizar el inventario por clave (BINARIO)");
                    printf("\n%32s\n", "6) Salir");
                    printf("\n%40s: ", "Opción");

                    limpiar_buffer_STDIN();
                    
                    scanf("%d", &opcion);

                    if (opcion < 1 || opcion > 6)
                    
                        validar_errores_por_SO();
                    
                } while (opcion < 1 || opcion > 6);

                limpiar_terminal();

                switch (opcion)
                {
                    case 1:
                        contar_existencias(&datos.files, datos.data, &datos.total, &archivo_secuencial);

                        if (datos.total.total_peliculas_secuencial < 50)
                        
                            leer_datos(&datos, &datos.total, &archivo_secuencial);
                        
                        else
                        
                            puts("Has alcanzado el límite máximo de películas. . .");
                        
                        break;

                    case 2:
                        if (contar_existencias(&datos.files, datos.data, &datos.total, &archivo_secuencial) && datos.total.total_peliculas_secuencial > 0)
                        
                            mostrar_pelicula(&datos.files, &archivo_secuencial);
                        
                        else
                        
                            puts("No hay datos disponibles para mostrar. . .");
                        
                        
                        break;

                    case 3:
                        contar_existencias(&datos.files, datos.data, &datos.total, &archivo_binario);
                        
                        if (datos.total.total_peliculas_binario < 50)
                        
                            leer_datos(&datos, &datos.total, &archivo_binario);
                        
                        else
                        
                            puts("Has alcanzado el límite máximo de películas. . .");
                        
                        
                        break;

                    case 4:
                        if (contar_existencias(&datos.files, datos.data, &datos.total, &archivo_binario) && datos.total.total_peliculas_binario > 0)
                    
                            mostrar_pelicula(&datos.files, &archivo_binario);
                        
                        else
                        
                            puts("No hay datos disponibles para mostrar. . .");
                        
                        break;
                        
                    case 5:
                        if (contar_existencias(&datos.files, datos.data, &datos.total, &archivo_binario) && datos.total.total_peliculas_binario > 0)
                    
                            actualizar_inventario(datos.files.file_peliculas_binario, &archivo_binario);
                        
                        else
                        
                            puts("No hay datos disponibles para mostrar y modificar. . .");
                        
                        break;

                    case 6:

                        free(datos.pwd.ruta_archivo_peliculas_directo);
                        free(datos.pwd.ruta_archivo_peliculas_secuencial);

                        fflush(datos.files.file_peliculas_binario);
                        fclose(datos.files.file_peliculas_binario);

                        fflush(datos.files.file_peliculas_secuencial);
                        fclose(datos.files.file_peliculas_secuencial);

                        break;
                }

                if (opcion != 6)
                
                    pausar_terminal();

            } while (opcion != 6);
            
            limpiar_terminal();

            puts("Operacion finalizada con éxito");
            return EXIT_SUCCESS;
        }
        else
        {
            free(datos.pwd.ruta_archivo_peliculas_secuencial);
            free(datos.pwd.ruta_archivo_peliculas_directo);

            return EXIT_FAILURE;
        }
    }
}

void leer_datos(struct Campos *campo, struct Total_Datos *total, const int *tipo_archivo)
{
    char respuesta[3];
    bool clave_repetida, descripcion_valida = false;
    static int contador = 0;

    do
    {
        limpiar_terminal();

        printf("Desea ingresar datos? Si/No: ");
        limpiar_buffer_STDIN();
        scanf(" %s", respuesta);

        convertir_cadena_a_minuscula(respuesta);

        if (strcmp(respuesta, "si") != 0 && strcmp(respuesta, "no") != 0)
        
            validar_errores_por_SO();

    } while (strcmp(respuesta, "si") != 0 && strcmp(respuesta, "no") != 0);

    if ((contador != 0 && strcmp(respuesta, "si") == 0) || contar_existencias(&campo->files, campo->data, &campo->total, tipo_archivo))
    {
        fprintf(campo->files.file_peliculas_secuencial, "\n");
        fflush(campo->files.file_peliculas_secuencial);
    }
    while (strcmp(respuesta, "si") == 0 && campo->total.total_peliculas_secuencial < 50)
    {
        do
        {
            do
            {
                limpiar_terminal();

                printf("Ingresa la clave de la película: ");
                limpiar_buffer_STDIN();
            } while (scanf("%d", &campo->data.clave) != 1);
            
            if ((campo->data.clave >= 1 && campo->data.clave <= 100) && contar_existencias(&campo->files, campo->data, &campo->total, tipo_archivo) && *tipo_archivo == 1)
            
                clave_repetida = verificar_clave_repetida(campo->files.file_peliculas_secuencial, &campo->data.clave, tipo_archivo);

            else if ((campo->data.clave >= 1 && campo->data.clave <= 100) && contar_existencias(&campo->files, campo->data, &campo->total, tipo_archivo) && *tipo_archivo == 2)
                
                    clave_repetida = verificar_clave_repetida(campo->files.file_peliculas_binario, &campo->data.clave, tipo_archivo);
                
            
            if (clave_repetida)
            {
                puts("La clave ya existe en el sistema. . .");
                pausar_terminal();
            }
            else if (campo->data.clave < 1 || campo->data.clave > 100)
                
                    validar_errores_por_SO();
                
            
        } while (clave_repetida || campo->data.clave < 1 || campo->data.clave > 100);
        
        do
        {
            limpiar_terminal();

            printf("Escribe una descripción de la película: ");
            limpiar_buffer_STDIN();
            fgets(campo->data.descripcion, sizeof(campo->data.descripcion), stdin);

            campo->data.descripcion[strcspn(campo->data.descripcion, "\n")] = '\0';

            if (strlen(campo->data.descripcion) != 0)
            {
                descripcion_valida = validar_cadenas(campo->data.descripcion);

                if (!descripcion_valida)
                
                    validar_errores_por_SO();
            }
            
        } while (!descripcion_valida || strlen(campo->data.descripcion) == 0);
        
        *(campo->data.categoria + 0) = '-';

        do
        {
            limpiar_terminal();

            printf("A qué categoría pertenece?\n\n - A: Drama\n - B: Suspenso\n - C: Misterio\n - D: Infantil\n\nSelecciona: ");
            limpiar_buffer_STDIN();
            scanf(" %c", (campo->data.categoria + 1));

            *(campo->data.categoria + 1) = toupper(*(campo->data.categoria + 1));

            if (*(campo->data.categoria + 1) != 'A' && *(campo->data.categoria + 1) != 'B' && *(campo->data.categoria + 1) != 'C' && *(campo->data.categoria + 1) != 'D')
            
                validar_errores_por_SO();
            
        } while (*(campo->data.categoria + 1) != 'A' && *(campo->data.categoria + 1) != 'B' && *(campo->data.categoria + 1) != 'C' && *(campo->data.categoria + 1) != 'D');
        
        do
        {
            do
            {
                limpiar_terminal();

                printf("Cuántas películas existen en el inventario?: ");
                limpiar_buffer_STDIN();
            } while (scanf("%d", &campo->data.inventario) != 1);
            
            if (campo->data.inventario < 1)
            
                validar_errores_por_SO();
            
        } while (campo->data.inventario < 1);
        
        contador++;

        switch (*tipo_archivo)
        {
            case 1:
                total->total_peliculas_secuencial += contador;

                fprintf(campo->files.file_peliculas_secuencial, "%-20d %-50s %-20s %-d", campo->data.clave, campo->data.descripcion, campo->data.categoria, campo->data.inventario);
                fflush(campo->files.file_peliculas_secuencial);

                if (total->total_peliculas_secuencial < 50)
                {
                    do
                    {
                        limpiar_terminal();

                        printf("Desea ingresar más datos? Si/No: ");
                        limpiar_buffer_STDIN();
                        scanf(" %s", respuesta);

                        convertir_cadena_a_minuscula(respuesta);

                        if (strcmp(respuesta, "si") != 0 && strcmp(respuesta, "no") != 0)
                        
                            validar_errores_por_SO();

                    } while (strcmp(respuesta, "si") != 0 && strcmp(respuesta, "no") != 0);
                    
                }
                else
                
                    puts("No puedes ingresar mas campos, límite alcanzado. . .");
                
                if (campo->total.total_peliculas_secuencial < 50 && strcmp(respuesta, "no") != 0)
                {
                    fprintf(campo->files.file_peliculas_secuencial, "\n");
                    fflush(campo->files.file_peliculas_secuencial);
                }
                break;
            
            case 2:

                total->total_peliculas_binario += contador;

                fseek(campo->files.file_peliculas_binario, (campo->data.clave - 1) * sizeof(campo->data), SEEK_SET);
                fwrite(&campo->data, sizeof(campo->data), 1, campo->files.file_peliculas_binario);

                fflush(campo->files.file_peliculas_binario);

                if (total->total_peliculas_binario < 50)
                {
                    do
                    {
                        limpiar_terminal();

                        printf("Desea ingresar más datos? Si/No: ");
                        limpiar_buffer_STDIN();
                        scanf(" %s", respuesta);

                        convertir_cadena_a_minuscula(respuesta);

                        if (strcmp(respuesta, "si") != 0 && strcmp(respuesta, "no") != 0)
                        
                            validar_errores_por_SO();

                    } while (strcmp(respuesta, "si") != 0 && strcmp(respuesta, "no") != 0);
                    
                }
                else
                
                    puts("No puedes ingresar mas campos, límite alcanzado. . .");
                
                break;
        }
    }

}

void mostrar_pelicula( struct Files_Requeridos *files_datos, const int *tipo_archivo)
{
    char categoria;
    struct Datos_Peliculas data;

    do
    {
        limpiar_terminal();

        printf("De qué categoría desea mostrar películas?\n- A: Drama\n - B: Suspenso\n - C: Misterio\n - D: Infantil\n\n Selecciona: ");
        limpiar_buffer_STDIN();
        scanf(" %c", &categoria);

        categoria = toupper(categoria);

        if (categoria != 'A' && categoria != 'B' && categoria != 'C' && categoria != 'D')
        
            validar_errores_por_SO();
        
    } while (categoria != 'A' && categoria != 'B' && categoria != 'C' && categoria != 'D');

    switch (*tipo_archivo)
    {
        case 1:
            if (buscar_existencia_categoria(files_datos, data, tipo_archivo, &categoria))
            {
                rewind(files_datos->file_peliculas_secuencial);

                printf("\n\n%-20s %-50s %-20s %s\n\n", "CLAVE", "DESCRIPCIÓN", "CATEGORÍA", "INVENTARIO");
                while (fscanf(files_datos->file_peliculas_secuencial, "%d %200[^-] %s %d", &data.clave, data.descripcion, data.categoria, &data.inventario) != EOF)
                {
                    if (*(data.categoria + 1) == categoria)
                    
                        printf("%-20d %-50s %-20.3s %-d\n", data.clave, data.descripcion, data.categoria, data.inventario);
                    
                }
                
            }
            else
            
                puts("No existen películas de la categoría ingresada. . .");
            
            break;
        
        case 2:
            if (buscar_existencia_categoria(files_datos, data, tipo_archivo, &categoria))
            {
                rewind(files_datos->file_peliculas_binario);

                printf("\n\n%-20s %-50s %-20s %-s\n\n", "CLAVE", "DESCRIPCIÓN", "CATEGORÍA", "INVENTARIO");
                while (fread(&data, sizeof(struct Datos_Peliculas), 1, files_datos->file_peliculas_binario) == 1)
                {
                    if (*(data.categoria + 1) == categoria)
                    
                        printf("%-20d %-50s %-20.3s %-d\n", data.clave, data.descripcion, data.categoria, data.inventario);
                    
                }
            }
            else
            
                puts("No existen películas de la categoría ingresada. . .");
            
            break;
    }
}

void actualizar_inventario(FILE *file_peliculas_binario, const int *tipo_archivo)
{
    struct Datos_Peliculas data;
    bool clave_inexistente = false;
    char respuesta[3];
    int posicion, inventario_leido;

    do
    {
        limpiar_terminal();

        printf("Desea actualizar inventarios? Si/No: ");
        limpiar_buffer_STDIN();
        scanf(" %s", respuesta);

        convertir_cadena_a_minuscula(respuesta);

        if (strcmp(respuesta, "si") != 0 && strcmp(respuesta, "no") != 0)
        
            validar_errores_por_SO();

    } while (strcmp(respuesta, "si") != 0 && strcmp(respuesta, "no") != 0);

    while (strcmp(respuesta, "si") == 0 && !clave_inexistente)
    {
        do
        {
            do
            {
                limpiar_terminal();

                printf("Ingresa la clave de la película a modificar inventario: ");
                limpiar_buffer_STDIN();
            } while (scanf("%d", &data.clave) != 1);
            
            if (data.clave > 0 && (clave_inexistente = !verificar_clave_repetida(file_peliculas_binario, &data.clave, tipo_archivo)))
            
                puts("No existe la clave en el sistema. . .");

            else if (data.clave < 1)
            
                validar_errores_por_SO();
            
        } while (data.clave < 1);

        if (!clave_inexistente)
        {
            posicion = ((data.clave - 1) * sizeof(struct Datos_Peliculas)) + offsetof(struct Datos_Peliculas, inventario);

            fseek(file_peliculas_binario, posicion, SEEK_SET);
            fread(&inventario_leido, sizeof(int), 1, file_peliculas_binario);

            do
            {
                do
                {
                    limpiar_terminal();

                    printf("INVENTARIO EN EXISTENCIA: %d\n\n", inventario_leido);
                    printf("Cuántas películas existen ahora en el inventario?: ");
                    limpiar_buffer_STDIN();
                } while (scanf("%d", &data.inventario) != 1);
                
                if (data.inventario < 1)
                
                    validar_errores_por_SO();
                
            } while (data.inventario < 1);
            
            fseek(file_peliculas_binario, posicion, SEEK_SET);
            fwrite(&data.inventario, sizeof(int), 1, file_peliculas_binario);

            limpiar_terminal();
            puts("Inventario actualizado!! . . .");
            pausar_terminal();

            do
            {
                limpiar_terminal();

                printf("Desea actualizar más inventarios? Si/No: ");
                limpiar_buffer_STDIN();
                scanf(" %s", respuesta);

                convertir_cadena_a_minuscula(respuesta);

                if (strcmp(respuesta, "si") != 0 && strcmp(respuesta, "no") != 0)
                
                    validar_errores_por_SO();

            } while (strcmp(respuesta, "si") != 0 && strcmp(respuesta, "no") != 0);
        }
    }
}

bool buscar_existencia_categoria( struct Files_Requeridos *files_datos, struct Datos_Peliculas data, const int *tipo_archivo, const char *categoria_buscada)
{
    switch (*tipo_archivo)
    {
        case 1:
            rewind(files_datos->file_peliculas_secuencial);

            while (fscanf(files_datos->file_peliculas_secuencial, "%d %200[^-] %s %d", &data.clave, data.descripcion, data.categoria, &data.inventario) != EOF)
            {
                if (*(data.categoria + 1) == *categoria_buscada)
                
                    return true;

            }
            
            break;
    
        case 2:
            rewind(files_datos->file_peliculas_binario);

            while (fread(&data, sizeof(struct Datos_Peliculas), 1, files_datos->file_peliculas_binario) == 1)
            {
                if (*(data.categoria + 1) == *categoria_buscada)
                
                    return true;
            }
            
            break;
    }

    return false;
}

bool verificar_clave_repetida(FILE *file_datos, const int *clave_ingresada, const int *opcion)
{
    struct Datos_Peliculas data;

    switch (*opcion)
    {
        case 1:

            rewind(file_datos);

            while (fscanf(file_datos, "%d %200[^-] %s %d", &data.clave, data.descripcion, data.categoria, &data.inventario) != EOF)
            {

                if (data.clave == *clave_ingresada)
        
                    return true;
                
            }

            break;
            
        case 2:

            fseek(file_datos, (*clave_ingresada - 1) * sizeof(struct Datos_Peliculas), SEEK_SET);
            fread(&data, sizeof(struct Datos_Peliculas), 1, file_datos);

            if (data.clave == *clave_ingresada)
            
                return true;

            break;
    }
    
    return false;
}

bool contar_existencias(struct Files_Requeridos *files, struct Datos_Peliculas data, struct Total_Datos *total, const int *tipo_archivo)
{
    int contador = 0;

    rewind(files->file_peliculas_secuencial);

    while (fscanf(files->file_peliculas_secuencial, "%d %200[^-] %s %d", &data.clave, data.descripcion, data.categoria, &data.inventario) != EOF)
    {
        if (data.clave != 0)
        {
            contador++;
            total->total_peliculas_secuencial = contador;
        }
        
    }
    
    rewind(files->file_peliculas_binario);

    contador = 0;

    while (fread(&data, sizeof(struct Datos_Peliculas), 1, files->file_peliculas_binario) == 1)
    {
        if (data.clave != 0)
        {
            contador++;
            total->total_peliculas_binario = contador;
        }
        
    }
    
    switch (*tipo_archivo)
    {
        case 1:
            if (total->total_peliculas_secuencial > 0)
            
                return true;
            
            break;
        
        case 2:
            if (total->total_peliculas_binario > 0)
            
                return true;
            
            break;
    }
    
    return false;
}

bool validar_cadenas(const char *caracter)
{
    while (*caracter != '\0')
    {
        if (!isalpha(*caracter) && *caracter != 32)
        
            return false;
        
        caracter++;
    }
    
    return true;
}

bool crear_archivos(FILE *peliculas_binario, FILE *peliculas_secuencial, struct Directorios *pwd)
{

    int i;
    struct Datos_Peliculas data = {0, "", "", 0};

    peliculas_binario = fopen(pwd->ruta_archivo_peliculas_directo, "rb");
    peliculas_secuencial = fopen(pwd->ruta_archivo_peliculas_secuencial, "r");

    if (peliculas_binario == NULL && peliculas_secuencial == NULL)
    {

        peliculas_binario = fopen(pwd->ruta_archivo_peliculas_directo, "wb");
        peliculas_secuencial = fopen(pwd->ruta_archivo_peliculas_secuencial, "w");

        if (peliculas_binario == NULL || peliculas_secuencial == NULL)
        
            fprintf(stderr, "ERROR DE ARCHIVOS, INTENTE MAS TARDE. . .");
        
        else
        {
            for ( i = 0; i < 50; i++)

                fwrite(&data, sizeof(struct Datos_Peliculas), 1, peliculas_binario);

            fclose(peliculas_binario);
            fclose(peliculas_secuencial);

            printf("Espacio binario y secuencial creados exitosamente!\n\n");
            pausar_terminal();
            return true;
        }

        return false;
    }
    else if (peliculas_binario == NULL)
        {
            peliculas_binario = fopen(pwd->ruta_archivo_peliculas_directo, "wb");

            if (peliculas_binario == NULL || peliculas_secuencial == NULL)
        
                fprintf(stderr, "ERROR DE ARCHIVO, INTENTE MAS TARDE. . .");
        
            else
            {
                for ( i = 0; i < 50; i++)

                    fwrite(&data, sizeof(struct Datos_Peliculas), 1, peliculas_binario);

                fclose(peliculas_binario);

                printf("Espacio binario creado exitosamente!\n\n");
                pausar_terminal();

                return true;
            }

            return false;
        }
        else if (peliculas_secuencial == NULL)
            {
                peliculas_secuencial = fopen(pwd->ruta_archivo_peliculas_secuencial, "w");

                if (peliculas_secuencial == NULL)
                
                    fprintf(stderr, "ERROR DE ARCHIVO, INTENTE MAS TARDE. . .");
                
                else
                {
                    fclose(peliculas_secuencial);

                    printf("Espacio secuencial creado exitosamente!\n\n");
                    pausar_terminal();

                    return true;
                }
                
                return false;
            }
            else
            {
                char respuesta[3];

                do
                {
                    printf("Desea ingresar todos los registros de nuevo? Si/No: ");
                    limpiar_buffer_STDIN();
                    scanf(" %s", respuesta);

                    convertir_cadena_a_minuscula(respuesta);

                    if (strcmp(respuesta, "si") != 0 && strcmp(respuesta, "no") != 0)
                    
                        validar_errores_por_SO();

                } while (strcmp(respuesta, "si") != 0 && strcmp(respuesta, "no") != 0);
                
                if (strcmp(respuesta, "si") == 0)
                {
                    peliculas_binario = freopen(pwd->ruta_archivo_peliculas_directo, "wb", peliculas_binario);
                    peliculas_secuencial = freopen(pwd->ruta_archivo_peliculas_secuencial, "w", peliculas_secuencial);

                    if (peliculas_binario == NULL || peliculas_secuencial == NULL)
                    
                        fprintf(stderr, "ERROR DE ARCHIVOS, INTENTE MAS TARDE. . .");
                    
                    else
                    {
                        for ( i = 0; i < 50; i++)

                            fwrite(&data, sizeof(struct Datos_Peliculas), 1, peliculas_binario);

                        printf("Espacio binario y secuencial recreados exitosamente!\n\n");
                        pausar_terminal();
                        return true;
                    }

                    return false;
                }

                fclose(peliculas_binario);
                fclose(peliculas_secuencial);

                return true;
            }
}

void convertir_cadena_a_minuscula(char *caracter)
{
    while (*caracter != '\0')
    {
        *caracter = tolower(*caracter);
        caracter++;
    }
}

// Limpia buffer STDIN tanto para sistemas Windows como para UNIX/Linux
void limpiar_buffer_STDIN()
{
    #if defined(_WIN32) || defined(_WIN64)
        rewind(stdin);
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