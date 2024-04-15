#include <stdio.h>

int calcular_algoritmo_euclides(int, int);

int main(void)
{
    int numero_1, numero_2;

    printf("Numero 1: ");
    scanf("%d", &numero_1);

    printf("Numero 2: ");
    scanf("%d", &numero_2);

    printf("El M.C.D es: %d\n", calcular_algoritmo_euclides(numero_1, numero_2));
}

int calcular_algoritmo_euclides(int dividendo, int divisor)
{
    static int residuo;

    if (divisor == 0)
    
        return dividendo; 
    
    residuo = dividendo % divisor;
    dividendo = divisor;
    divisor = residuo;

    return calcular_algoritmo_euclides(dividendo, divisor);
}