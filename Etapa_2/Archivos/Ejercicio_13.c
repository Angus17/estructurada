/*  
    Crear el archivo binario para los maximo 1000 alumnos
*/

#include <stdio.h>

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
    struct Datos_Alumnos datos = {0,"", "", 0, 0};
    int i;

    file_alumnos = fopen("alumnos.dat", "wb");

    if (file_alumnos == NULL)
    
        puts("No se pudo abrir el archivo, operacion fallida");
    
    else
    {
        rewind(file_alumnos);

        for ( i = 0; i < 1000; i++)
        
            fwrite(&datos, sizeof(struct Datos_Alumnos), 1, file_alumnos);
        
        puts("Archivo creado exitosamente!");

        fclose(file_alumnos);
    }
}