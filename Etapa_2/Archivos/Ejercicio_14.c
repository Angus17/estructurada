/*  
    Para los alumnos guarda la sig. informacion

    en un archivo binario (acceso directo)

    -matriculafread()
    -Nombre
    -semestre
    -Promedio
    -Carrera

    Muestra:
    - Todos los alumnos (1000 alumnos maximo)
*/

#include <stdio.h>
#include <stdbool.h>

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
    int contador_alumnos = 0, i;
    char respuesta;
    bool cadena_valida;

    file_alumnos = fopen("alumnos.dat", "ab+");

    if (file_alumnos == NULL)
    
        puts("No pudo abrirse el archivo;");
    
    else
    {
        rewind(file_alumnos);

        for ( i = 0; i < 1000; i++)
        
            fwrite(&datos, sizeof(struct Datos_Alumnos), 1, file_alumnos);
        
        puts("Archivo creado con exito");
        
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

        rewind(file_alumnos);

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
                limpiar_terminal();

                printf("Matricula de %s: ", datos.nombre);
                limpiar_buffer_STDIN();
            } while (scanf("%d", &datos.matricula) != 1);
            
        }
        
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