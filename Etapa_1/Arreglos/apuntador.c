#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char input[100];  // Tamaño máximo de la línea de entrada
    int valores[100]; // Tamaño máximo de valores

    printf("Ingrese los valores separados por espacios: ");
    
    // Leer toda la línea
    fgets(input, sizeof(input), stdin);

    int n = 0; // Contador de valores

    // Analizar la línea para extraer los valores
    char *token = strtok(input, " ");
    while (token != NULL && n < 100)
    {
        valores[n++] = atoi(token); // Convertir el token a entero
        token = strtok(NULL, " ");
    }

    // Mostrar los valores ingresados
    printf("Los valores ingresados son: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", valores[i]);
    }

    return 0;
}
