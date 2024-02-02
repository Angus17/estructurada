#include <stdio.h>
#include <stdlib.h>

void llenar_arreglo(int [][5]);
void mostrar_arreglo(int [][5]);

int main(void)
{
    int numbers[4][5];

    llenar_arreglo(numbers);
    mostrar_arreglo(numbers);
}

void llenar_arreglo(int values[][5])
{
    int i, j;

    for ( i = 1; i < 5; i++)
    {
        for ( j = 1; j < 6; j++)
        
            values[i - 1][j - 1] = i * j;
        
    }
    
}

void mostrar_arreglo(int values[][5])
{
    int i, j;

    for ( i = 0; i < 4; i++)
    {
        for ( j = 0; j < 5; j++)
        
            printf("%d ", values[i][j]);
        
        printf("\n");
    }
}