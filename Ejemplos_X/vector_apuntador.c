#include <stdio.h>

int main(void)
{
    int vector[5] = {1,2,3,4,5}, *numero_1 = vector, *numero_2 = vector + 2;

    numero_1 += 3;
    numero_2 -= 2;

    printf("\nEl numero 1 del vector: %d\n", *numero_1);
    printf("El numero 2 del vector: %d\n", *numero_2);
}