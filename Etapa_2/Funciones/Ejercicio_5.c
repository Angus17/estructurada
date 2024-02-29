/* 
    Para un grupo de N estudiantes (a lo mucho 50) ingresar sus 5 calificaciones 

    Mostrar el menu al siguiente usuario:

        Opciones:

        a) Lectura y validacion de datos
        b) listado de nombres y matricula con promedio >= 90
        c) listado de nombres y matricula con promedio >= 90 en computacion
        d) Listado de nombre y matricula de mayor promedio indicado por el usuario
        e) Salir

    De acuerdo a la opcion seleccionada por el usuario, hacer una llamada a funcion en cada opcion

    Tambien crear funciones para las validaciones que se deban realizar en la lectura de datos
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#if __linux__
    #include <stdio_ext.h>
#endif 

struct Datos_Estudiantes
{
    char nombre[100], carrera[30];
    int calificaciones[5], matricula;
};

void leer_datos(struct Datos_Estudiantes[]);
int calcular_promedios(struct Datos_Estudiantes[]);
void listar_alumnos_PromedioMayor(struct Datos_Estudiantes[]);
void calcular_promedios_mayores(struct Datos_Estudiantes[]);

bool validar_cadenas_con_espacios(char[]);
bool validar_cadenas_sin_espacios(char[]);

void validar_Sistema_Operativo();
void limpiar_buffer_STDIN();
void limpiar_terminal();
void pausar_terminal();


int main(void)
{
    char opcion;
    struct Datos_Estudiantes datos[50];
    bool datos_leidos = false, promedios_calculados = false;
    int retorno = 0;

    do
    {
        do
        {
            printf("    %-s: \n", "MENU DE OPCIONES");
            printf("a). Lectura de datos\n");
            printf("b). Calcular los promedios\n");
            printf("c). Listado de nombres y matricula para alumnos con promedio >= 90\n");
            printf("d). Listado de nombres y matricula para alumnos con promedio >= 90 en computacion\n");
            printf("e). Listado de nombre y matricula de mayor promedio indicado por el usuario\n");
            printf("f). Salir\n");
            printf("    %-s: ", "opcion");
            
            limpiar_buffer_STDIN();

            retorno = scanf(" %c", &opcion);

            if (opcion < 'a' || opcion > 'f')
            {
                validar_Sistema_Operativo();
                retorno--;
            }

        } while (retorno != 1);
        
        limpiar_terminal();

        switch (opcion)
        {
            case 'a':
                if (datos_leidos)
                
                    puts("Ya leiste los datos, ya puedes determinar promedios");
                
                else
                {
                    leer_datos(datos);
                    datos_leidos = true;
                }
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

    } while (opcion != 'e');
    



}

void leer_datos(struct Datos_Estudiantes data[])
{
    int  j, contador_estudiantes = 0;
    bool fin_alumnos = false, cadena_aceptada = false, carrera_encontrada;
    char respuesta;

    while (!fin_alumnos && contador_estudiantes < 50)
    {
        do
        {
            printf("Ingresa el nombre del estudiante %d: ", contador_estudiantes + 1);

            limpiar_buffer_STDIN();

            fgets(data[contador_estudiantes].nombre, 100, stdin);

            data[contador_estudiantes].nombre[strcspn(data[contador_estudiantes].nombre, "\n")] = '\0';

            if (strlen(data[contador_estudiantes].nombre) != 0)
            
                cadena_aceptada = validar_cadenas_con_espacios(data[contador_estudiantes].nombre);

            else if (strlen(data[contador_estudiantes].nombre) == 0 || !cadena_aceptada)
            
                    validar_Sistema_Operativo();

        } while (strlen(data[contador_estudiantes].nombre) == 0 || !cadena_aceptada);
        
        do
        {
            printf("Ahora ingresa la matricula de %s: ", data[contador_estudiantes].nombre);

            limpiar_buffer_STDIN();

            scanf("%d", &data[contador_estudiantes].matricula);

            if (data[contador_estudiantes].matricula < 0)
            
                validar_Sistema_Operativo();
            
        } while (data[contador_estudiantes].matricula < 0);
        
        do
        {
            carrera_encontrada = false;

            printf("Escribe la carrera que esta cursando %s: \n- Computacion\n- Matematicas\n- Seguridad"
                    "\n- Animacion\n- Fisica\n- Actuaria\n: " , data[contador_estudiantes].nombre);

            limpiar_buffer_STDIN();

            scanf(" %c", &data[contador_estudiantes].carrera);

            data[contador_estudiantes].carrera[strcspn(data[contador_estudiantes].carrera, "\n")] = '\0';

            if (strlen(data[contador_estudiantes].carrera) != 0)
            {
                
                cadena_aceptada = validar_cadenas_con_espacios(data[contador_estudiantes].carrera);

                if (cadena_aceptada && strcmp(data[contador_estudiantes].carrera, "computacion") == 0 || strcmp(data[contador_estudiantes].carrera, "animacion") == 0 || strcmp(data[contador_estudiantes].carrera, "fisica") == 0 || strcmp(data[contador_estudiantes].carrera, "matematicas") == 0 || strcmp(data[contador_estudiantes].carrera, "seguridad") == 0 || strcmp(data[contador_estudiantes].carrera, "actuaria") == 0)
                
                        carrera_encontrada = true;
                
                else
                {
                    puts("No fue encontrada la carrera que ingresaste");
                    pausar_terminal();
                }
                
            }
            else
            
                puts("No puedes manejar cadenas vacias");
            

        } while (strlen(data[contador_estudiantes].carrera) == 0 || !cadena_aceptada || !carrera_encontrada);
        
        
        contador_estudiantes++;
    }
    
    

}

bool validar_cadenas_con_espacios(char cadena[])
{
    int j = 0;
    bool caracteres_rechazados = false;

    while (cadena[j] != '\0' && !caracteres_rechazados)
    {
        if (!isalpha(cadena[j]) && cadena[j] != 32)
        
            caracteres_rechazados = true;
        
        j++;
    }

    return !caracteres_rechazados;
}

bool validar_cadenas_sin_espacios(char cadena[])
{
    int j = 0;
    bool caracteres_rechazados = false;

    while (cadena[j] != '\0' && !caracteres_rechazados)
    {
        if (!isalpha(cadena[j]))
        
            caracteres_rechazados = true;
        
        j++;
    }

    return !caracteres_rechazados;
}
/* --------------------------------------------------------------------- */
void limpiar_buffer_STDIN()
{
    #if defined(_WIN32) || defined(_WIN64)
        fflush(stdin);
    #elif __linux
        __fpurge(stdin);
    #endif
}

void limpiar_terminal()
{
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #elif __linux
        system("clear");
    #endif
}

void pausar_terminal()
{
    #if defined(_WIN32) || defined(_WIN64)
        system("pause");
    #elif __linux
        printf("Presiona ENTER para continuar. . .");
        fflush(stdout);
        limpiar_buffer_STDIN();
        getchar();
    #endif
}

void validar_Sistema_Operativo()
{
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");

        printf("Dato/s ingresado/s no valido/s, verificar dato/s");
        system("pause");
        system("cls");
    #elif __linux__
        system("clear");

        printf("Dato/s ingresado/s no valido/s, verificar dato/s");
        fflush(stdout);
        
        printf("\nPresiona la tecla ENTER para continuar. . . ");
        fflush(stdout);
        limpiar_buffer_STDIN();
        getchar();
        
        system("clear");
    #endif
}