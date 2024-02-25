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
    float promedio_general_semestre[9];
};

int main(void)
{
    float promedio_general_total[50], suma = 0.0;
    struct Datos_Estudiantes datos[50];
    int i, j, contador_estudiantes = 0, longitud_cadena, contador_caracteres;
    char respuesta_existencia, carrera_busqueda[30];
    bool existencia = false, carrera_encontrada = true;

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

        for ( i = 0; i < datos[contador_estudiantes].semestre - 1; i++)
        {
            do
            {
                printf("Ingresa el promedio general de su semestre %d del estudiante %s: ", i, datos[contador_estudiantes].nombre_alumno);

                #if defined(_WIN32) || defined(_WIN64)
                    fflush(stdin);
                #elif __linux__
                    __fpurge(stdin);
                #endif

                scanf("%f", &datos[contador_estudiantes].promedio_general_semestre[i]);

                if (datos[contador_estudiantes].promedio_general_semestre[i] < 0.0 || datos[contador_estudiantes].promedio_general_semestre[i] > 100.0)
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

            } while (datos[contador_estudiantes].promedio_general_semestre[i] < 0.0 || datos[contador_estudiantes].promedio_general_semestre[i] > 100.0);

        }
        
        
        do
        {
            carrera_encontrada = false;

            printf("Escribe la carrera que esta cursando %s: \n- Computacion\n - Matematicas\n - Seguridad"
                    "\n- Animacion\n- Fisica\n- Actuaria" , datos[contador_estudiantes].nombre_alumno);
            #if __linux__
                __fpurge(stdin);
            #elif defined(_WIN32) || defined(_WIN64)
                fflush(stdin);
            #endif 
            gets(datos[contador_estudiantes].carrera);

            j = 0;
            while (datos[contador_estudiantes].carrera[j] != '\0')
            {
                datos[contador_estudiantes].carrera[j] = tolower(datos[contador_estudiantes].carrera[j]);
                j++;
            }
            

            datos[contador_estudiantes].carrera[strcspn(datos[contador_estudiantes].carrera, "\n")] = '\0';
            longitud_cadena = strlen(datos[contador_estudiantes].carrera);

            j = 0;
            contador_caracteres = 0;

            while (datos[contador_estudiantes].carrera[j] != '\0')
            {
                if (isalpha(datos[contador_estudiantes].carrera[j]) || datos[contador_estudiantes].carrera[j] == 32)
                
                    contador_caracteres++;
                
                j++;
            }

            if (contador_caracteres == longitud_cadena && (strcmp(datos[contador_estudiantes].carrera, "computacion") == 0 || strcmp(datos[contador_estudiantes].carrera, "animacion") == 0 || strcmp(datos[contador_estudiantes].carrera, "fisica") == 0 || strcmp(datos[contador_estudiantes].carrera, "matematicas") == 0 || strcmp(datos[contador_estudiantes].carrera, "seguridad") == 0 || strcmp(datos[contador_estudiantes].carrera, "actuaria") == 0))
            
                carrera_encontrada = true;
            
            

        } while (longitud_cadena == 0 || contador_caracteres != longitud_cadena || !carrera_encontrada);
        
        do
        {
            printf("Existen mas estudiantes?\nS.Si\nN.No\n: ");
            #if defined(_WIN32) || defined(_WIN64)
                fflush(stdin);
            #endif
            scanf(" %c", &respuesta_existencia);

            respuesta_existencia = tolower(respuesta_existencia);

            if (respuesta_existencia != 's' && respuesta_existencia != 'n')
            {
                #if defined(_WIN32) || defined(_WIN64)
                    system("cls");

                    printf("Ingresa una respuesta válida\n");
                    system("pause");
                    system("cls");
                #elif __linux__
                    system("clear");

                    printf("Ingresa una respuesta válida");
                    fflush(stdout);
                    
                    printf("\nPresiona la tecla ENTER para continuar. . . ");
                    fflush(stdout);
                    while (getchar() != '\n');
                    getchar();
                    
                    system("clear");
                #endif
            }    
        } while (respuesta_existencia != 's' && respuesta_existencia != 'n');

        if (respuesta_existencia == 'n')
        
            existencia = false;
        
        


        contador_estudiantes++;
    }
    
    for ( i = 0; i < contador_estudiantes; i++)
    {
        suma = 0.0;

        for ( j = 0; j < datos[i].semestre - 1; j++)
        
            suma += datos[i].promedio_general_semestre[j];
        
        
        promedio_general_total[i] = suma / datos[i].semestre - 1;
    }

    for ( i = 0; i < contador_estudiantes; i++)
    {
        if (promedio_general_total[i] >= 90)
        {
            printf("El estudiante %s obtuvo un promedio general de %.2f, este fue su progreso:\n", datos[i].nombre_alumno, promedio_general_total[i]);

            for (j = 0; j < datos[i].semestre - 1; j++)
            
                printf("Semestre %d Promedio %.2f\n", j, datos[i].promedio_general_semestre[j]);
        }
    }
    
    for ( i = 0; i < contador_estudiantes; i++)
    {
        if (promedio_general_total[i] >= 90 && strcmp(datos[i].carrera, "computacion") == 0)
        {
            printf("El estudiante %s de la carrera de computacion obtuvo un promedio general de %.2f, este fue su progreso:\n", datos[i].nombre_alumno, promedio_general_total[i]);

            for (j = 0; j < datos[i].semestre - 1; j++)
            
                printf("Semestre %d Promedio %.2f\n", j, datos[i].promedio_general_semestre[j]);
        }
    }

    do
    {
        printf("De las carreras existentes, indique cual de las carreras desea buscar al alumno de promedio mayor: \n- Computacion\n - Matematicas\n - Seguridad"
                    "\n- Animacion\n- Fisica\n- Actuaria");

            #if __linux__
                __fpurge(stdin);
            #elif defined(_WIN32) || defined(_WIN64)
                fflush(stdin);
            #endif 
            gets(carrera_busqueda);

            j = 0;
            while (carrera_busqueda[j] != '\0')
            {
                carrera_busqueda[j] = tolower(carrera_busqueda[j]);
                j++;
            }
            

            carrera_busqueda[strcspn(carrera_busqueda, "\n")] = '\0';
            longitud_cadena = strlen(carrera_busqueda);

            j = 0;
            contador_caracteres = 0;

            while (carrera_busqueda != '\0')
            {
                if (isalpha(carrera_busqueda[j]) || carrera_busqueda[j] == 32)
                
                    contador_caracteres++;
                
                j++;
            }

            if (contador_caracteres == longitud_cadena && (strcmp(datos[contador_estudiantes].carrera, "computacion") == 0 || strcmp(datos[contador_estudiantes].carrera, "animacion") == 0 || strcmp(datos[contador_estudiantes].carrera, "fisica") == 0 || strcmp(datos[contador_estudiantes].carrera, "matematicas") == 0 || strcmp(datos[contador_estudiantes].carrera, "seguridad") == 0 || strcmp(datos[contador_estudiantes].carrera, "actuaria") == 0))
            
                carrera_encontrada = true;
            
            #if __linux__
                __fpurge(stdin);
            #elif defined(_WIN32) || defined(_WIN64)
                fflush(stdin);
            #endif 
            gets(datos[contador_estudiantes].carrera);

            j = 0;
            while (datos[contador_estudiantes].carrera[j] != '\0')
            {
                datos[contador_estudiantes].carrera[j] = tolower(datos[contador_estudiantes].carrera[j]);
                j++;
            }
            

            datos[contador_estudiantes].carrera[strcspn(datos[contador_estudiantes].carrera, "\n")] = '\0';
            longitud_cadena = strlen(datos[contador_estudiantes].carrera);

            j = 0;
            contador_caracteres = 0;

            while (datos[contador_estudiantes].carrera[j] != '\0')
            {
                if (isalpha(datos[contador_estudiantes].carrera[j]) || datos[contador_estudiantes].carrera[j] == 32)
                
                    contador_caracteres++;
                
                j++;
            }

            if (contador_caracteres == longitud_cadena && (strcmp(datos[contador_estudiantes].carrera, "computacion") == 0 || strcmp(datos[contador_estudiantes].carrera, "animacion") == 0 || strcmp(datos[contador_estudiantes].carrera, "fisica") == 0 || strcmp(datos[contador_estudiantes].carrera, "matematicas") == 0 || strcmp(datos[contador_estudiantes].carrera, "seguridad") == 0 || strcmp(datos[contador_estudiantes].carrera, "actuaria") == 0))
            
                carrera_encontrada = true;
            
            
    } while (longitud_cadena == 0 || contador_caracteres != longitud_cadena || !carrera_encontrada);
    
    for ( i = 0; i < contador_estudiantes; i++)
    {
        if (strcmp(carrera_busqueda, "computacion") == 0 && promedio_general_total[i] >= 90)
        
            printf("\n%s de la carrera de Computacion obtuvo %.2f durante su carrera\n", datos[i].nombre_alumno, promedio_general_total[i]);
        
        else if (strcmp(carrera_busqueda, "actuaria") == 0 && promedio_general_total[i] >= 90)
            
                printf("\n%s de la carrera de Actuaria obtuvo %.2f durante su carrera\n", datos[i].nombre_alumno, promedio_general_total[i]);
            
            else if(strcmp(carrera_busqueda, "seguridad") == 0 && promedio_general_total[i] >= 90)
                
                    printf("\n%s de la carrera de Seguridad obtuvo %.2f durante su carrera\n", datos[i].nombre_alumno, promedio_general_total[i]);
                
                else if (strcmp(carrera_busqueda, "fisica") == 0 && promedio_general_total[i] >= 90)
                    
                        printf("\n%s de la carrera de Fisica obtuvo %.2f durante su carrera\n", datos[i].nombre_alumno, promedio_general_total[i]);
                    
                    else if (strcmp(carrera_busqueda, "matematicas") == 0 && promedio_general_total[i] >= 90)
                        
                            printf("\n%s de la carrera de Matematicas obtuvo %.2f durante su carrera\n", datos[i].nombre_alumno, promedio_general_total[i]);
                        
                        else if (strcmp(carrera_busqueda, "animacion") == 0 && promedio_general_total[i] >= 90)
                        
                            printf("\n%s de la carrera de Animacion obtuvo %.2f durante su carrera\n", datos[i].nombre_alumno, promedio_general_total[i]);
    }
}