#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int numero_1, numero_2, *ap_num, *ap_num_2, suma, resta, multiplicacion, potencia;
    float division;

    printf("Ingresa el primer numero: ");
    scanf("%d", &numero_1);

    printf("Ingresa el segundo numero: ");
    scanf("%d", &numero_2);

    ap_num = &numero_1;
    ap_num_2 = &numero_2;

    suma = *ap_num + *ap_num_2;
    resta = *ap_num - *ap_num_2;
    multiplicacion = *ap_num * *ap_num_2;
    division = *ap_num / *ap_num_2;
    potencia = pow(*ap_num, *ap_num_2);

    printf("\nLa suma es de: %d\n", suma);
    printf("La resta es de: %d\n", resta);
    printf("La multiplicacion es de: %d\n", multiplicacion);
    printf("La division es de: %.2f\n", division);
    printf("La potencia es de: %d\n", potencia);
}