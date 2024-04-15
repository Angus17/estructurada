#include <stdio.h>

int calcular_multiplicacion_china(int, int);

int main(void)
{
    int numero_1, numero_2;

    printf("Numero 1: ");
    scanf("%d", &numero_1);

    printf("Numero 2: ");
    scanf("%d", &numero_2);

    printf("Resultado de la multiplicacion: %d\n", calcular_multiplicacion_china(numero_1, numero_2));
}

int calcular_multiplicacion_china(int x, int y)
{
    static int resultado = 0;

    if (y == 0)
    
        return resultado;
    
    else if (y % 2 != 0)
        
            resultado += x;

    x *= 2;
    y /= 2;
    
    return calcular_multiplicacion_china(x, y);
}