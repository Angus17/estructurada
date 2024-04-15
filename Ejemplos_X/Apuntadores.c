#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    long long int numero_1, numero_2, *ap_num, *ap_num_2, suma, resta, multiplicacion, potencia;
    double division;

    printf("Ingresa el primer numero: ");
    scanf("%lld", &numero_1);

    printf("Ingresa el segundo numero: ");
    scanf("%lld", &numero_2);

    ap_num = &numero_1;
    ap_num_2 = &numero_2;

    suma = *ap_num + *ap_num_2;
    resta = *ap_num - *ap_num_2;
    multiplicacion = *ap_num * *ap_num_2;
    division = (double)(*ap_num) / (*ap_num_2);
    potencia = pow(*ap_num, *ap_num_2);

    printf("\nLa suma es de: %lld\n", suma);
    printf("La resta es de: %lld\n", resta);
    printf("La multiplicacion es de: %lld\n", multiplicacion);
    printf("La division es de: %.5f\n", division);
    printf("La potencia es de: %lld\n", potencia);
    /* printf("%lld\t%lld", sizeof(float), sizeof(double)); */

    system("pause");
    system("cls");
}