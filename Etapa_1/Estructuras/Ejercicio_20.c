/* 
    Elaborar un programa en C tal que para N estudiantes almacene lo siguiente (utilizar estructura)
        - Nombre de alumnos. gets()
        - Matricula. Validar mayor que 0
        - Numero de semestre cursado. Entre 1 y 9
        - Promedio general ontenido en cada semestre cursado. Vaidar que sea entre 0 y 100,
        Guardar los promedios en un arreglo  unidimensional. a lo mas son 9 promedios
        - Carrera. Puede ser actuaria, computacion, Multimedia... etc.
    
    Una vez leido, validando cada dato y  guardado en un arreglo tipo estructura, obtener:

    a) Listar nombre y matricula de los estudiantes que obtenieron iun promedio genera mayor o igual a
    90. (Contar todos los promedios que lleva hasta ahora)

    b) Listar nombre y matricula deb los estudiantes de la carrera de computacion y que hayan tenido un 
    promedio general de 90 o mas
    
    c) Escribir el nombre y matricula de llos alumnos que tienen el mayor promedio de la carrera
    indicada por el usuario.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#if __linux__
    #include <stdio_ext.h>
#endif

struct Datos_Estudiantes
{
    char nombre_alumno[100], carrera[30];
    int semestre, matricula;
    float promedio_general_semestre;
};

int main(void)
{
    float promedio_general_total[50];
    struct Datos_Estudiantes datos[50];
    int i, j, contador_estudiantes = 0, longitud_cadena, contador_caracteres;
    float suma = 0.0;
    char respuesta_existencia;
    bool existencia = false;

    do
    {
        printf("Existen estudiantes?\nS.Si\nN.No\n: ");
        #if defined(_WIN32) || defined(_WIN64)
            fflush(stdin);
        #elif __linux__
            __fpurge(stdin);
        #endif
        scanf(" %c", &respuesta_existencia);

        respuesta_existencia = tolower(respuesta_existencia);

        #if defined(_WIN32) || defined(_WIN64)

            if (respuesta_existencia != 's' && respuesta_existencia != 'n')
            {
                system("cls");

                printf("Ingresa una respuesta válida\n");
                system("pause");
                system("cls");
            }
            else if (respuesta_existencia == 's')
            
                existencia = true;

        #elif __linux__
            
            if (respuesta_existencia != 's' && respuesta_existencia != 'n')
            {
                system("clear");

                printf("Ingresa una respuesta válida");
                fflush(stdout);
                
                printf("\nPresiona la tecla ENTER para continuar. . . ");
                fflush(stdout);
                while (getchar() != '\n');
                getchar();
                
                system("clear");
            }
            else if (respuesta_existencia == 's')
            
                existencia = true;
        #endif 
        
        
    } while (respuesta_existencia != 's' && respuesta_existencia != 'n');
    
    while (existencia)
    {
        do
        {
            printf("Escribe el nombre del estudiante %d: ", contador_estudiantes);
            #if defined(_WIN32) || defined(_WIN64)
                fflush(stdin);
            #elif __linux__
                __fpurge(stdin);
            #endif 
            gets(datos[contador_estudiantes].nombre_alumno);

            datos[contador_estudiantes].nombre_alumno[strcspn(datos[contador_estudiantes].nombre_alumno, "\n")] = '\0';
            longitud_cadena = strlen(datos[contador_estudiantes].nombre_alumno);

            j = 0;
            contador_caracteres = 0;

            while (datos[contador_estudiantes].nombre_alumno[j] != '\0')
            {
                if (isalpha(datos[contador_estudiantes].nombre_alumno[j]) || datos[contador_estudiantes].nombre_alumno[j] == 32)
                
                    contador_caracteres++;
                
                j++;
            }

        } while (longitud_cadena == 0 || contador_caracteres != longitud_cadena);

        do
        {
            printf("Ingresa la matricula del alumno %d: ", contador_estudiantes + 1);
        
            #if defined(_WIN32) || defined(_WIN64)
                fflush(stdin);
            #elif __linux__
                __fpurge(stdin);
            #endif

            scanf("%d", &datos[contador_estudiantes].matricula);

            if (datos[contador_estudiantes].matricula < 0)
            {
                #if defined(_WIN32) || defined(_WIN64)
                    system("cls");

                    printf("La matricula debe ser mayor a cero, verificar dato");
                    printf("\nPresiona la tecla ENTER para continuar. . . ");
                    fflush(stdin);
                    getchar();
                    system("cls");

                #elif __linux__
                    system("clear");

                    printf("La matricula debe ser mayor a cero, verificar dato");
                    fflush(stdout);
                    
                    printf("\nPresiona la tecla ENTER para continuar. . . ");
                    fflush(stdout);
                    __fpurge(stdin);
                    getchar();
                    
                    system("clear");

                #endif
            }

        } while (datos[contador_estudiantes].matricula < 0);

        do
        {
            printf("Ingresa el semestre que esta cursando actualmente %s: ", datos[contador_estudiantes].nombre_alumno);
            
            #if defined(_WIN32) || defined(_WIN64)
                fflush(stdin);
            #elif __linux__
                __fpurge(stdin);
            #endif

            scanf("%d", &datos[contador_estudiantes].semestre);

            if (datos[contador_estudiantes].semestre < 1 || datos[contador_estudiantes].semestre > 9)
            {
                #if defined(_WIN32) || defined(_WIN64)
                    system("cls");

                    printf("La matricula debe ser mayor a cero, verificar dato");
                    printf("\nPresiona la tecla ENTER para continuar. . . ");
                    fflush(stdin);
                    getchar();
                    system("cls");

                #elif __linux__
                    system("clear");

                    printf("La matricula debe ser mayor a cero, verificar dato");
                    fflush(stdout);
                    
                    printf("\nPresiona la tecla ENTER para continuar. . . ");
                    fflush(stdout);
                    __fpurge(stdin);
                    getchar();
                    
                    system("clear");

                #endif
            }

        } while (datos[contador_estudiantes].semestre < 1 || datos[contador_estudiantes].semestre > 9);

        do
        {
            printf("Ingresa el promedio general de su semestre %d del estudiante %s: ", datos[contador_estudiantes].semestre, datos[contador_estudiantes].promedio_general_semestre);

            #if defined(_WIN32) || defined(_WIN64)
                fflush(stdin);
            #elif __linux__
                __fpurge(stdin);
            #endif

            scanf("%f", &datos[contador_estudiantes].promedio_general_semestre);

            if (datos[contador_estudiantes].promedio_general_semestre < 0.0 || datos[contador_estudiantes].promedio_general_semestre > 100.0)
            {
                #if defined(_WIN32) || defined(_WIN64)
                    system("cls");

                    printf("La matricula debe ser mayor a cero, verificar dato");
                    printf("\nPresiona la tecla ENTER para continuar. . . ");
                    fflush(stdin);
                    getchar();
                    system("cls");

                #elif __linux__
                    system("clear");

                    printf("La matricula debe ser mayor a cero, verificar dato");
                    fflush(stdout);
                    
                    printf("\nPresiona la tecla ENTER para continuar. . . ");
                    fflush(stdout);
                    __fpurge(stdin);
                    getchar();
                    
                    system("clear");

                #endif
            }

        } while (datos[contador_estudiantes].promedio_general_semestre < 0.0 || datos[contador_estudiantes].promedio_general_semestre > 100.0);

        do
        {
            printf("Escribe la carrera que esta cursando: ", datos[contador_estudiantes].nombre_alumno);
            #if __linux__
                __fpurge(stdin);
            #endif 
            gets(datos[contador_estudiantes].nombre_alumno);

            datos[contador_estudiantes].nombre_alumno[strcspn(datos[contador_estudiantes].nombre_alumno, "\n")] = '\0';
            longitud_cadena = strlen(datos[contador_estudiantes].nombre_alumno);

            j = 0;
            contador_caracteres = 0;

            while (datos[contador_estudiantes].nombre_alumno[j] != '\0')
            {
                if (isalpha(datos[contador_estudiantes].nombre_alumno[j]) || datos[contador_estudiantes].nombre_alumno[j] == 32)
                
                    contador_caracteres++;
                
                j++;
            }

        } while (longitud_cadena == 0 || contador_caracteres != longitud_cadena);
        
        do
        {
            printf("Existen mas estudiantes?\nS.Si\nN.No\n: ");
            #if defined(_WIN32) || defined(_WIN64)
                fflush(stdin);
            #endif
            scanf(" %c", &respuesta_existencia);

            respuesta_existencia = tolower(respuesta_existencia);

            #if defined(_WIN32) || defined(_WIN64)

                if (respuesta_existencia != 's' && respuesta_existencia != 'n')
                {
                    system("cls");

                    printf("Ingresa una respuesta válida\n");
                    system("pause");
                    system("cls");
                }
                else if (respuesta_existencia == 's')
                
                    existencia = true;

            #elif __linux__
                
                if (respuesta_existencia != 's' && respuesta_existencia != 'n')
                {
                    system("clear");

                    printf("Ingresa una respuesta válida");
                    fflush(stdout);
                    
                    printf("\nPresiona la tecla ENTER para continuar. . . ");
                    fflush(stdout);
                    while (getchar() != '\n');
                    getchar();
                    
                    system("clear");
                }
                else if (respuesta_existencia == 'n')
                
                    existencia = false;
            #endif 
            
            
        } while (respuesta_existencia != 's' && respuesta_existencia != 'n');



        contador_estudiantes++;
    }
    
}