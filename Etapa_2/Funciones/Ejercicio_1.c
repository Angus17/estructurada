/* 
    PROGRAMA QUE CALCULE EL AREA DE UN CIRCULO, CON FUNCIONES

*/

#include <stdio.h>
#if __linux__
    #include <stdio_ext.h>
#endif

float calcular_area_triangulo(float, float);

int main(void)
{
    float area, base, altura;

    do
    {
        printf("Escribe la medida de la base del triangulo: ");
        #if defined(_WIN32) || defined(_WIN64)
            rewind(stdin);
        #elif __linux__
            __fpurge(stdin);
        #endif
        scanf("%f", &base);
    } while (base <= 0);

    do
    {
        printf("Escribe la medida de la altura del triangulo: ");
        #if defined(_WIN32) || defined(_WIN64)
            rewind(stdin);
        #elif __linux__
            __fpurge(stdin);
        #endif
        scanf("%f", &altura);
    } while (altura <= 0);

    
    area = calcular_area_triangulo(base, altura);

    printf("\nEl area del triangulo es de %.2f\n", area);

}

float calcular_area_triangulo(float base_f, float altura_f)
{
    return base_f * altura_f / 2;
}