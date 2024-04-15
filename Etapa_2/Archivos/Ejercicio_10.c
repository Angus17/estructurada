/*  
    Elabora un programa para que cada alumno lea su nombre, matricula, promedio, semestre

    Validar que la matricula sea mayor que cero, el nombre contenga solo letras y espacios
    el promedio este entre 0 y 100. El semestre esta entre 1 y 9

    La informacion se guardara en un archivo

    Mostrar al usuario el siguiente menu:

    1. Lectura de datos
    2. Lista de alumnos con promedio mayor o igual a 70. A partir del archivo
    3. Listado de alumnos del semestre



*/

/*  
    Hacer un programa que lea para varios alumnos, los datos anteriores, y guardarlos en un archivo

*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *file;
    char *nombres;
    int promedios, matricula, semestre;

    file = fopen("alumnos.txt", "r");

    if (file == NULL)
    
        puts("No se pudo abrir el archivo");
    
    else
    {
        nombres = malloc(sizeof nombres);

        while (fscanf(file, "%50[^0-9] %d %d %d", nombres, &matricula, &promedios, &semestre) != EOF)
        
            printf("%-20s %-20d %-20d %-20d\n", nombres, matricula, promedios, semestre);
        
        free(nombres);
        fclose(file);
    }
}