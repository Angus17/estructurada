/*
Genera el siguiente menú:

a - Lectura de trabajadores
b - Trabajadores de contabilidad
c - Trabajadores con sueldo mayor a 15,000
d - Salir

En la lectura opción a se solicitará el número del empleado (validar mayor a cero),
su nombre (validar solo letras y espacios), departamento (validar solo letras y espacios) y sueldo.
Generar un archivo secuencial con dicha información.

En la opción b y c mostrar toda la información del trabajador de acuerdo a la condición indicada 
y en forma tabular
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include <stdbool.h>


struct trabajadores
{
    float sueldo;
    char nombre[50];
    int n_empleado;
    char departamento[20];
};

//Prototipo de funcion
void trabajadores(struct trabajadores t[ ], FILE *D, char arch[ ], int *);
void trabajadores_contabilidad(struct trabajadores t[ ], int);
void trabajadores_sueldo_mayor(struct trabajadores t[ ], int);

int main(void)
{
    #if defined(_WIN32) || defined(_WIN64)
        puts("\nBIENVENID@ USUARI@ WINDOWS\n\n");
    #elif defined(_linux_)
        puts("\nBIENVENID@ USUARI@ LINUX\n\n");
    #elif defined(_APPLE_) 
        puts("\nBIENVENID@ USUARI@ MacOS\n\n");
    #else
        puts("\nBIENVENID@ USUARI@ ANDROID");
    #endif

    setlocale(LC_ALL, "spanish");

    char archivo[30] = "Datos_empleados.dat";
    FILE *datos = NULL;
    struct trabajadores empleado[100];
    char opcion;
    bool acceso = false;
    int empleados = 0, *puntero;

    puntero = &empleados;

    do
    {
        do
        {
        puts("\nMENÚ DE OPCIONES:");
        puts("a. Lectura de trabajadores");
        puts("b. Trabajadores de contabilidad");
        puts("c. Trabajadores con sueldo mayor a $15,000");
        puts("d. Salir");
        puts("Selecciona una opción: ");
        fflush(stdin);
        }while(scanf("%c",&opcion) != 1);


        switch (opcion)
        {
            case 'a':
                acceso = false;
                trabajadores(empleado, datos, archivo, puntero);
                acceso = !acceso; // True
                break;

            case 'b':
                if(acceso)
                
                    trabajadores_contabilidad(empleado, empleados);
                
                else
                {
                    puts("ERROR! primero debe capturar la lectura de trabajadores, se le retornará al menú");
                    system("pause");
                    system("cls");
                }
                break;
            
            case 'c':
                if (acceso)
                
                    trabajadores_sueldo_mayor(empleado, empleados);
                
                else
                {
                    puts("ERROR! aun no ha llenado los campos necesarios, se le retornará al menú");
                    system("pause");
                    system("cls");
                }
                break;

            
        }
    } while (opcion != 'd' && opcion != 'D');
    
}

void trabajadores(struct trabajadores t[ ], FILE *D, char arch[ ], int *empleados_max)
{
    int i = 0, j = 0, contador = 0, contador_2 = 0, longitud = 0, longitud_2 = 0;
    char copia[50];
    char salida;

    if((D = fopen(arch, "w")) == NULL )
    {
        puts("ERROR!, OCURRIÓ UN PROBLEMA Y NO PUEDE ABRIRSE EL ARCHIVO ");
    }
    else
    {
        fprintf(D, "\t\t\t%s", "DATOS DE TRABAJADORES\n\n");
        fprintf(D, "%-s\t\t %-s\t\t %-s\t\t %-s\n", "#Empleado:", "Nombres:", "Departamento:", "Sueldos:");

        while (!feof(stdin)) //Se terminara cuando el usuario teclee Ctrl + Z (Para Windows), y Ctrl + D Para Unix/Linux/MacOs
        {
        
            do
            {
                printf("Cuál es su número de empleado? (empleado %d): ", i + 1);
                fflush(stdin);
                scanf("%d",&t[i].n_empleado);

                printf("Digite el nombre del empleado #%d: ", t[i].n_empleado);
                fflush(stdin);
                gets(t[i].nombre);

                t[i].nombre[strcspn(t[i].nombre, "\n")] = '\0';
                strcpy(copia, t[i].nombre);
                longitud = strlen(copia);

                if(longitud == 0)
                {
                    puts("\nERROR! LA CADENA NO PUEDE ESTAR VACÍA\n");
                    system("pause");
                    system("cls");
                }
                else
                {
                    j = 0;
                    contador = 0;

                    while (copia[j] != '\0')
                    {
                        if (isalpha(copia[j]) || copia[j] == 32)
                        
                            contador++;
                        
                        
                        j++;
                    }

                    printf("A qué departamento pertenece el empleado #%d: ", t[i].n_empleado);
                    fflush(stdin);
                    gets(t[i].departamento);

                    t[i].departamento[strcspn(t[i].departamento, "\n")] = '\0';
                    strcpy(copia, t[i].departamento);
                    longitud_2 = strlen(copia);

                    if(longitud_2 == 0)
                    {
                        puts("\nERROR! LA CADENA NO PUEDE ESTAR VACIA\n");
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        j = 0;
                        contador_2 = 0;

                        while (copia[j] != '\0')
                        {
                            if (isalpha(copia[j]) || copia[j] == 32)
                            
                                contador_2++;
                            j++;
                        }
                        
                        puts("Por último digite su sueldo: ");
                        fflush(stdin);
                        scanf("%f", &t[i].sueldo);
        
                    }
                }
                
            } while (t[i].n_empleado < 0 || (longitud != contador) || (longitud_2 != contador_2) || t[i].sueldo < 0 || longitud == 0 || longitud_2 == 0 );
            
            fscanf(D, "%d %s %s %f", &t[i].n_empleado, t[i].nombre, t[i].departamento, &t[i].sueldo);
            fprintf(D, "\n%-d \t\t\t%-20s \t%-20s \t%-10.2f", t[i].n_empleado, t[i].nombre, t[i].departamento, t[i].sueldo);

            system("cls");

            printf("Existen más empleados?\n(Sí = Enter)\n(No = CTRL + Z)\n");
            fflush(stdin);
            scanf("%c", &salida);
            
            i++;
        }
        
        *empleados_max = i;
        
        fclose(D);        
    }
}

void trabajadores_contabilidad(struct trabajadores t[ ], int e_totales)
{
    int i = 0;

    puts("\nEMPLEADOS DEL DEPARTAMENTO DE CONTABILIDAD\n");
    for ( i = 0; i < e_totales; i++)
    {
        if (strcmp(t[i].departamento, "Contabilidad") == 0 || strcmp(t[i].departamento, "contabilidad") == 0 || strcmp(t[i].departamento, "CONTABILIDAD") == 0)
        
            printf("%-d\t\t%-30s\t\t%-30s\t%-.2f\n", t[i].n_empleado, t[i].nombre,t[i].departamento, t[i].sueldo);

    }
    
}

void trabajadores_sueldo_mayor(struct trabajadores t[ ], int e_totales)
{
    int i = 0;

    puts("\nEMPLEADOS CON SUELDO MAYOR A 15,000\n");
    for ( i = 0; i < e_totales; i++)
    {
        if(t[i].sueldo > 15000)
        {
            printf("%-d\t\t%-30s\t\t%-30s\t%-.2f\n", t[i].n_empleado, t[i].nombre,t[i].departamento, t[i].sueldo);
        }
    }
}