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
#include <locale.h>
#include <ctype.h>
#include <string.h>
#if __linux__
    #include <stdio_ext.h>
#endif 

struct Datos_Estudiantes
{
    char nombre[100], carrera[30];
    int calificaciones[6], matricula;
};

int leer_validar_datos(struct Datos_Estudiantes[], int);
int calcular_promedios(struct Datos_Estudiantes[], int);
void listar_alumnos_PromedioMayor(struct Datos_Estudiantes[], int);
void buscar_alumnos_PromedioMayor_carrera(struct Datos_Estudiantes[], int);
void listar_alumnos_promedio_mayor_carreras(struct Datos_Estudiantes[], char[], int);

bool buscar_existencia_promediosMayores(struct Datos_Estudiantes[], char[], int);
bool existencia_alumnos_por_carrera(struct Datos_Estudiantes[], char[], int);
bool validar_cadenas_con_espacios(char[]);
bool validar_cadenas_sin_espacios(char[]);

void convertir_cadenas_a_minusculas(char[]);

void validar_Sistema_Operativo();
void limpiar_buffer_STDIN();
void limpiar_terminal();
void pausar_terminal();

int main(void)
{
    char opcion;
    struct Datos_Estudiantes datos[50];
    bool datos_leidos = false, promedios_calculados = false, alumnos_computacion = false;
    bool existencia_promedios_mayores = false;
    int retorno = 0, i, cantidad_alumnos = 0;

    setlocale(LC_ALL, "spanish");

    do
    {
        limpiar_terminal();

        do
        {
            printf("\n    %-s: \n\n", "MENU DE OPCIONES");
            puts("a). Lectura y validación de datos");
            puts("b). Calcular los promedios");
            puts("c). Listado de nombres y matrícula para alumnos con promedio >= 90");
            puts("d). Listado de nombres y matrícula para alumnos con promedio >= 90 en Computación");
            puts("e). Listado de nombre y matrícula de mayor promedio indicado por el usuario");
            puts("f). Salir");
            printf("    %-s: ", "opción");
            
            limpiar_buffer_STDIN();

            retorno = scanf(" %c", &opcion);

            opcion = tolower(opcion);

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
                    if (cantidad_alumnos > 50)
                    
                        puts("No puede registrar más alumnos, ha alcanzado el límite máximo");
                    
                    else
                    {
                        cantidad_alumnos = leer_validar_datos(datos, cantidad_alumnos);

                        if (!datos_leidos)
                        
                            datos_leidos = true;
                            
                        for ( i = 0; i < cantidad_alumnos; i++)
                        
                            datos[i].carrera[0] = toupper(datos[i].carrera[0]);
                        
                        limpiar_terminal();
                        puts("Se agregaron los datos correctamente!");
                        
                    }
            break;

            case 'b':
                if (!datos_leidos)
                
                    puts("Necesitas leer todos los datos de estudiantes para obtener promedios");

                else if (promedios_calculados)
                    
                        puts("Ya fueron calculados los promedios");
                    
                    else 
                    {
                        for ( i = 0; i < cantidad_alumnos; i++)
                            
                            datos[i].calificaciones[5] = calcular_promedios(datos, i);
                        
                        promedios_calculados = true;
                        puts("Promedios calculados satisfactoriamente!");
                    }
            break;

            case 'c':
                if (!datos_leidos)
                
                    puts("Te falta leer los datos de los estudiantes y calcular los promedios");
                
                else if (!promedios_calculados)
                    
                        puts("Necesitas calcular los promedios para proceder");
                    
                    else
                    
                        listar_alumnos_PromedioMayor(datos, cantidad_alumnos);
                    
                
            break;

            case 'd':
                if (!datos_leidos)
                
                    puts("Te falta leer los datos de los estudiantes y calcular los promedios");
                
                else if (!promedios_calculados)
                    
                        puts("Necesitas calcular los promedios para proceder");
                    
                    else
                    {
                        alumnos_computacion = existencia_alumnos_por_carrera(datos, "Computacion", cantidad_alumnos);
                        existencia_promedios_mayores = buscar_existencia_promediosMayores(datos, "Computacion", cantidad_alumnos);

                        if (!alumnos_computacion)
                        
                            puts("El sistema no encontró alumn@s de la carrera de Computación");
                        
                        else if (!existencia_promedios_mayores)
                            
                                puts("El sistema no encontró alumn@s de Computación con promedio >= 90");
                            
                            else
                            
                                listar_alumnos_promedio_mayor_carreras(datos, "Computacion", cantidad_alumnos);

                    }
                        
            break;

            case 'e':
                if (!datos_leidos)
                
                    puts("Te falta leer los datos de los estudiantes y calcular los promedios");
                
                else if (!promedios_calculados)
                    
                        puts("Necesitas calcular los promedios para proceder");
                    
                    else
                    
                        buscar_alumnos_PromedioMayor_carrera(datos, cantidad_alumnos);
                    
            break;
        }

        if (opcion != 'f')
        
            pausar_terminal();

    } while (opcion != 'f');
}

// Lectura y validacion de datos
int leer_validar_datos(struct Datos_Estudiantes data[], int alumnos)
{
    int j;
    bool fin_alumnos = false, cadena_aceptada = false, carrera_encontrada;
    char respuesta;

    while (!fin_alumnos && alumnos < 50)
    {
        limpiar_terminal();

        do
        {
            limpiar_terminal();

            printf("Ingresa el nombre del estudiante %d: ", alumnos + 1);

            limpiar_buffer_STDIN();

            fgets(data[alumnos].nombre, 100, stdin);

            data[alumnos].nombre[strcspn(data[alumnos].nombre, "\n")] = '\0';

            if (strlen(data[alumnos].nombre) != 0)
            {
                cadena_aceptada = validar_cadenas_con_espacios(data[alumnos].nombre);

                if (!cadena_aceptada)
                
                    validar_Sistema_Operativo();
            }
            else
            {
                puts("El campo del nombre no puede estar vacio");
                pausar_terminal();
            }


        } while (strlen(data[alumnos].nombre) == 0 || !cadena_aceptada);
        
        do
        {
            limpiar_terminal();

            do
            {
                printf("Ahora ingresa la matrícula de %s: ", data[alumnos].nombre);

                limpiar_buffer_STDIN();
                
            } while (scanf("%d", &data[alumnos].matricula) != 1);

            if (data[alumnos].matricula < 0)
            
                validar_Sistema_Operativo();
            
        } while (data[alumnos].matricula < 0);
        
        do
        {
            carrera_encontrada = false;

            do
            {
                limpiar_terminal();

                printf("Escribe la carrera que esta cursando %s (SIN ACENTOS): \n- Computación\n- Matemáticas\n- Seguridad"
                        "\n- Animación\n- Física\n- Actuaría\n: " , data[alumnos].nombre);

                limpiar_buffer_STDIN();

                scanf(" %s", data[alumnos].carrera); 

                if (strlen(data[alumnos].carrera) != 0)
                {
                    cadena_aceptada = validar_cadenas_con_espacios(data[alumnos].carrera);
                    
                    if (!cadena_aceptada)
                
                        validar_Sistema_Operativo();
                }
                else
                {
                    puts("No puedes manejar cadenas vacias");
                    pausar_terminal();
                }

                
            } while (!cadena_aceptada || strlen(data[alumnos].carrera) == 0);

            convertir_cadenas_a_minusculas(data[alumnos].carrera);

            if  (
                    strcmp(data[alumnos].carrera, "computacion") == 0 || 
                    strcmp(data[alumnos].carrera, "animacion") == 0 ||
                    strcmp(data[alumnos].carrera, "fisica") == 0 || 
                    strcmp(data[alumnos].carrera, "matematicas") == 0 || 
                    strcmp(data[alumnos].carrera, "seguridad") == 0 || 
                    strcmp(data[alumnos].carrera, "actuaria") == 0
                    
                )
            
                    carrera_encontrada = true;
            
            else
            {
                puts("No fue encontrada la carrera que ingresaste");
                pausar_terminal();
            }
            

        } while (!carrera_encontrada);
        
        for ( j = 0; j < 5; j++)
        {
            do
            {
                do
                {
                    printf("Registra la calificacion %d de %s: ", j + 1, data[alumnos].nombre);

                    limpiar_buffer_STDIN();

                } while (scanf("%d", &data[alumnos].calificaciones[j]) != 1);

                if (data[alumnos].calificaciones[j] < 0 || data[alumnos].calificaciones[j] > 100)
                
                    validar_Sistema_Operativo();
                
            } while (data[alumnos].calificaciones[j] < 0 || data[alumnos].calificaciones[j] > 100);
            
        }
        
        do
        {
            puts("Existen mas alumnos?");
            puts("S.Si");
            puts("N.No");

            limpiar_buffer_STDIN();

            scanf(" %c", &respuesta);

            respuesta = tolower(respuesta);

            if (respuesta != 's' && respuesta != 'n')
            
                validar_Sistema_Operativo();
            
        } while (respuesta != 's' && respuesta != 'n');
        
        if (respuesta == 'n')
        
            fin_alumnos = true;

        else if (alumnos == 50)
            {
                limpiar_terminal();
                puts("Alcanzaste el máximo número de estudiantes a registrar");
                pausar_terminal();
            }

        alumnos++;
    }

    return alumnos;
}

// Calculo de promedios
int calcular_promedios(struct Datos_Estudiantes data[], int index)
{
    int j, suma = 0;

    for ( j = 0; j < 5; j++)
    
        suma += data[index].calificaciones[j];
    
    return suma / 5;
}

// Modulo para imprimir datos de alumn@s con promedios >= 90
void listar_alumnos_PromedioMayor(struct Datos_Estudiantes data[], int alumnos)
{
    int i;

    for (i = 0; i < alumnos; i++)
    {
        if (data[i].calificaciones[5] >= 90)
        
            printf("- Alumn@: %s\n Matrícula: %d\n Carrera: %s\n Promedio: %d\n\n", data[i].nombre, data[i].matricula,data[i].carrera, data[i].calificaciones[5]);
        
    }
    
}

// Modulo para imprimir datos de alumn@s de x carrera indicada por el user, con promedio >= 90
void buscar_alumnos_PromedioMayor_carrera(struct Datos_Estudiantes data_f[], int alumnos_f)
{
    bool existencia = false, cadena_aceptada = false, carrera_encontrada = false, existencia_promedios_mayores = false;
    char busqueda[30];

    do
    {
        do
        {
            limpiar_terminal();

            puts("- Computación");
            puts("- Física");
            puts("- Matemáticas");
            puts("- Actuaría");
            puts("- Animación");
            puts("- Seguridad");
            puts("Escribe la carrera que desee buscar alumnos con promedio >= 90 (SIN ACENTOS): ");

            limpiar_buffer_STDIN();

            scanf(" %s", busqueda); 

            if (strlen(busqueda) != 0)
            {
                cadena_aceptada = validar_cadenas_con_espacios(busqueda);

                if (!cadena_aceptada)
            
                    validar_Sistema_Operativo();
                
            }
            else
            {
                puts("No puedes manejar cadenas vacías");
                pausar_terminal();
            }

        } while (!cadena_aceptada || strlen(busqueda) == 0);

        convertir_cadenas_a_minusculas(busqueda);

        if  (
                strcmp(busqueda, "computacion") == 0 || 
                strcmp(busqueda, "animacion") == 0 ||
                strcmp(busqueda, "fisica") == 0 || 
                strcmp(busqueda, "matematicas") == 0 || 
                strcmp(busqueda, "seguridad") == 0 || 
                strcmp(busqueda, "actuaria") == 0
                
            )
        
                carrera_encontrada = true;
        
        else
        {
            puts("No fué encontrada la carrera que ingresaste");
            pausar_terminal();
        }
    } while (!carrera_encontrada);

    busqueda[0] = toupper(busqueda[0]);
    limpiar_terminal();
    
    existencia = existencia_alumnos_por_carrera(data_f, busqueda, alumnos_f);
    existencia_promedios_mayores = buscar_existencia_promediosMayores(data_f, busqueda, alumnos_f);

    if (!existencia)
    
        printf("No existen alumnos de la carrera de %s\n", busqueda);
    
    else if (!existencia_promedios_mayores)
        
            printf("El sistema no encontró alumnos con promedio >= 90 en la carrera de %s\n", busqueda);
        
        else
        
            listar_alumnos_promedio_mayor_carreras(data_f, busqueda, alumnos_f);
        
    
}

// Modulo para listar datos de alumn@s con promedio >= 90 dependiendo de la carrera 
void listar_alumnos_promedio_mayor_carreras(struct Datos_Estudiantes data[], char carrera[], int alumnos)
{
    int i = 0;

    if (strcmp(carrera, "Computacion") == 0)
    {
        for ( i = 0; i < alumnos; i++)
        {
            if (strcmp(data[i].carrera, "Computacion") == 0 && data[i].calificaciones[5] >= 90)
            
                printf("- Alumn@: %s\n Matrícula: %d\n Carrera: %s\n Promedio: %d\n\n", data[i].nombre, data[i].matricula,data[i].carrera, data[i].calificaciones[5]);
            
        }
        
    }
    else if (strcmp(carrera, "Fisica") == 0)
        {
            for ( i = 0; i < alumnos; i++)
            {
                if (strcmp(data[i].carrera, "Fisica") == 0 && data[i].calificaciones[5] >= 90)
                
                    printf("- Alumn@: %s\n Matricula: %d\n Carrera: %s\n Promedio: %d\n\n", data[i].nombre, data[i].matricula,data[i].carrera, data[i].calificaciones[5]);
                
            }
        }
        else if (strcmp(carrera, "Matematicas") == 0)
            {
                for ( i = 0; i < alumnos; i++)
                {
                    if (strcmp(data[i].carrera, "Matematicas") == 0 && data[i].calificaciones[5] >= 90)
                    
                        printf("- Alumn@: %s\n Matricula: %d\n Carrera: %s\n Promedio: %d\n\n", data[i].nombre, data[i].matricula,data[i].carrera, data[i].calificaciones[5]);
                    
                }
            }
            else if (strcmp(carrera, "Actuaria") == 0)
                {
                    for ( i = 0; i < alumnos; i++)
                    {
                        if (strcmp(data[i].carrera, "Actuaria") == 0 && data[i].calificaciones[5] >= 90)
                        
                            printf("- Alumn@: %s\n Matricula: %d\n Carrera: %s\n Promedio: %d\n\n", data[i].nombre, data[i].matricula,data[i].carrera, data[i].calificaciones[5]);
                        
                    }
                }
                else if (strcmp(carrera, "Seguridad") == 0)
                    {
                        for ( i = 0; i < alumnos; i++)
                        {
                            if (strcmp(data[i].carrera, "Seguridad") == 0 && data[i].calificaciones[5] >= 90)
                            
                                printf("- Alumn@: %s\n Matricula: %d\n Carrera: %s\n Promedio: %d\n\n", data[i].nombre, data[i].matricula,data[i].carrera, data[i].calificaciones[5]);
                            
                        }
                    }
                    else
                    {
                        for ( i = 0; i < alumnos; i++)
                        {
                            if (strcmp(data[i].carrera, "Animacion") == 0 && data[i].calificaciones[5] >= 90)
                            
                                printf("- Alumn@: %s\n Matricula: %d\n Carrera: %s\n Promedio: %d\n\n", data[i].nombre, data[i].matricula,data[i].carrera, data[i].calificaciones[5]);
                            
                        }
                    }
}

// Modulo que analiza los datos existentes en busca de promedios >= 90 en x carrera indicada por el user
bool buscar_existencia_promediosMayores(struct Datos_Estudiantes data[], char carrera[], int alumnos)
{
    int i = 0;
    bool existencia = false;

    if (strcmp(carrera, "Computacion") == 0)
    {
        while (!existencia && i < alumnos)
        {
            if (strcmp(data[i].carrera, "Computacion") == 0 && data[i].calificaciones[5] >= 90)
            
                existencia = true;

            i++;
        }
        
    }
    else if (strcmp(carrera, "Fisica") == 0)
        {
            while (!existencia && i < alumnos)
            {
                if (strcmp(data[i].carrera, "Fisica") == 0 && data[i].calificaciones[5] >= 90)
            
                    existencia = true;
                
                
                i++;
            }
        }
        else if (strcmp(carrera, "Matematicas") == 0)
            {
                while (!existencia && i < alumnos)
                {
                    if (strcmp(data[i].carrera, "Matematicas") == 0 && data[i].calificaciones[5] >= 90)
            
                        existencia = true;
                
                    i++;
                }
            }
            else if (strcmp(carrera, "Actuaria") == 0)
                {
                    while (!existencia && i < alumnos)
                    {
                        if (strcmp(data[i].carrera, "Actuaria") == 0 && data[i].calificaciones[5] >= 90)
            
                            existencia = true;
                
                        i++;
                    }
                }
                else if (strcmp(carrera, "Seguridad") == 0)
                    {
                        while (!existencia && i < alumnos)
                        {
                            if (strcmp(data[i].carrera, "Seguridad") == 0 && data[i].calificaciones[5] >= 90)
            
                                existencia = true;
                
                            i++;
                        }
                    }
                    else
                    {
                        while (!existencia && i < alumnos)
                        {
                            if (strcmp(data[i].carrera, "Animacion") == 0 && data[i].calificaciones[5] >= 90)
            
                                existencia = true;
                
                            i++;
                        }
                    }
    
    return existencia;
}

// Modulo que analiza los datos existentes en busca de existencia de alumnos en la carrera indicada por el user
bool existencia_alumnos_por_carrera(struct Datos_Estudiantes data[], char carrera[], int alumnos)
{
    int i = 0;
    bool existencia = false;

    if (strcmp(carrera, "Computacion") == 0)
    {
        while (!existencia && i < alumnos)
        {
            if (strcmp(data[i].carrera, "Computacion") == 0)
            
                existencia = true;

            i++;
        }
        
    }
    else if (strcmp(carrera, "Fisica") == 0)
        {
            while (!existencia && i < alumnos)
            {
                if (strcmp(data[i].carrera, "Fisica") == 0)
            
                    existencia = true;
                
                
                i++;
            }
        }
        else if (strcmp(carrera, "Matematicas") == 0)
            {
                while (!existencia && i < alumnos)
                {
                    if (strcmp(data[i].carrera, "Matematicas") == 0)
            
                        existencia = true;
                
                    i++;
                }
            }
            else if (strcmp(carrera, "Actuaria") == 0)
                {
                    while (!existencia && i < alumnos)
                    {
                        if (strcmp(data[i].carrera, "Actuaria") == 0)
            
                            existencia = true;
                
                        i++;
                    }
                }
                else if (strcmp(carrera, "Seguridad") == 0)
                    {
                        while (!existencia && i < alumnos)
                        {
                            if (strcmp(data[i].carrera, "Seguridad") == 0)
            
                                existencia = true;
                
                            i++;
                        }
                    }
                    else
                    {
                        while (!existencia && i < alumnos)
                        {
                            if (strcmp(data[i].carrera, "Animacion") == 0)
            
                                existencia = true;
                
                            i++;
                        }
                    }
    
    return existencia;
}

// Modulo que valida que todas las cadenas de caracteres recibidas, sean tipo char y con espacios
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

// Modulo que valida que todas las cadenas de caracteres recibidas, sean tipo char y con espacios
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

// Modulo que convierte toda una cadena de caracteres(tipo char), a minusculas, para validaciones
void convertir_cadenas_a_minusculas(char cadena[])
{
    int j = 0;

    while (cadena[j] != '\0')
    {
        if (!islower(cadena[j]))
        
            cadena[j] = tolower(cadena[j]);
        
        j++;
    }
}

/* --------------------------------------------------------------------- */

// Limpia buffer STDIN tanto para sistemas Windows como para UNIX/Linux
void limpiar_buffer_STDIN()
{
    #if defined(_WIN32) || defined(_WIN64)
        fflush(stdin);
    #elif __linux
        __fpurge(stdin);
    #endif
}

// Limpia terminal tanto para sistemas Windows como para UNIX/Linux
void limpiar_terminal()
{
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #elif __linux
        system("clear");
    #endif
}

// Pausa la terminal tanto para sistemas Windows como para UNIX/Linux
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

// Clasifica los mensajes de error tanto para Windows como para UNIX/Linux, cuando se ingresan datos incorrectos
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