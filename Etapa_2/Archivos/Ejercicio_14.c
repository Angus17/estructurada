/*  
    Para los alumnos guarda la sig. informacion

    en un archivo binario (acceso directo)

    -matricula 
    -Nombre
    -semestre
    -Promedio
    -Carrera

    Muestra:
    - Todos los alumnos (1000 alumnos maximo) fread()
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#ifdef __linux__
    #include <stdio_ext.h>
#endif 

bool validar_cadenas(char *);
void validar_errores_por_SO();
void limpiar_buffer_STDIN();
void limpiar_terminal();
void pausar_terminal();

struct Datos_Alumnos
{
    int matricula;
    char nombre[50];
    char carrera[10];
    int semestre;
    int promedio;
};

int main(void)
{
    FILE *file_alumnos;
    struct Datos_Alumnos datos;
    int contador_alumnos = 0, i = 0;
    char respuesta;
    bool cadena_valida;

    file_alumnos = fopen("alumnos.dat", "wb+");

    if (file_alumnos == NULL)
    
        puts("No pudo abrirse el archivo;");
    
    else
    {
        rewind(file_alumnos);
        
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

        while (respuesta == 's')
        {
            do
            {
                limpiar_terminal();

                printf("Escribe el nombre del alumno: ");
                limpiar_buffer_STDIN();
                fgets(datos.nombre, 50, stdin);

                datos.nombre[strcspn(datos.nombre, "\n")] = '\0';

                if (strlen(datos.nombre) == 0)
                {
                    puts("Ingresa una cadena valida, no puedes usar cadenas vacias");
                    pausar_terminal();
                    limpiar_terminal();
                }
                else
                {
                    cadena_valida = validar_cadenas(datos.nombre);

                    if (!cadena_valida)
                    
                        validar_errores_por_SO();
                    
                }
            } while (strlen(datos.nombre) == 0 || !cadena_valida);


            
            do
            {
                do
                {
                    limpiar_terminal();

                    printf("Matricula de %s: ", datos.nombre);
                    limpiar_buffer_STDIN();
                } while (scanf("%d", &datos.matricula) != 1);
                
                if (datos.matricula <= 0)
                
                    validar_errores_por_SO();
                
            } while (datos.matricula <= 0);
            

            do
            {
                do
                {
                    limpiar_terminal();

                    printf("Semestre de %s: ", datos.nombre);
                    limpiar_buffer_STDIN();
                } while (scanf("%d",&datos.semestre) != 1);

                if (datos.semestre < 1 || datos.semestre > 9)
                
                    validar_errores_por_SO();
            } while (datos.semestre < 1 || datos.semestre > 9);

            do
            {
                do
                {
                    limpiar_terminal();

                    printf("Promedio de %s: ", datos.nombre);
                    limpiar_buffer_STDIN();
                } while (scanf("%d", &datos.promedio) != 1);
                
                if (datos.promedio < 0 || datos.promedio > 100)
                
                    validar_errores_por_SO();

            } while (datos.promedio < 0 || datos.promedio > 100);

            
        
            printf("Escribe la carrera que esta cursando %s: ", datos.nombre);
            limpiar_buffer_STDIN();

            scanf(" %s", datos.carrera);

        
            
            fseek(file_alumnos, contador_alumnos * sizeof(struct Datos_Alumnos), SEEK_SET);
            fwrite(&datos, sizeof(struct Datos_Alumnos), 1, file_alumnos);

            do
            {
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

            contador_alumnos++;
        }

        limpiar_terminal();

        if (contador_alumnos != 0)
        {

            for ( i = 0; i < contador_alumnos; i++)
            {
                fseek(file_alumnos, i * sizeof(struct Datos_Alumnos), SEEK_SET);
                fread(&datos, sizeof(struct Datos_Alumnos), 1, file_alumnos);

                printf("\n%-30s %-20d %-20s %-20d %-d\n", datos.nombre, datos.matricula, datos.carrera, datos.semestre, datos.promedio);
            }
            
            pausar_terminal();
        }
        
        fclose(file_alumnos);
    }

    limpiar_terminal();
    puts("Operacion finalizada!");
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