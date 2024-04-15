/*  
    Creacion  de archivo en blanco para los maximo 200 planetas

*/

#include <stdio.h>
#include <stdbool.h>

struct Datos_Planetas
{
    int clave_planeta;
    long long int dimension;
    char caracteristicas[100];
    bool posibilidad_vida;
};

int main(void)
{
    FILE *file_planetas;
    struct Datos_Planetas datos = {0,0LL, "\0", false};
    int i;

    file_planetas = fopen("datos_planetas.dat", "wb");

    if (file_planetas == NULL)
    
        puts("No se pudo abrir el archivo, operacion fallida");
    
    else
    {
        for ( i = 0; i < 200; i++)
        
            fwrite(&datos, sizeof(struct Datos_Planetas), 1, file_planetas);
        
        puts("Archivo creado exitosamente!");

        fclose(file_planetas);
    }
}