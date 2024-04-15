/* 
    Elabora un programa que lea un numero y la potencia a la que desea elevar

    El programa debera funcionar para 5 valores
*/

#include <stdio.h>
#if __linux__
    #include <stdio_ext.h>
#endif

int elevar_potencia(int, int);

int main(void)
{
    int i, numero, potencia;

    for ( i = 0; i < 5; i++)
    {
        do
        {
            printf("Ingresa numero positivo [%d]: ", i + 1);
            scanf("%d", &numero);
        } while (numero < 0);

        do
        {
            printf("A que potencia positiva quieres elevar: ");
            scanf("%d", &potencia);
        } while (numero < 0);

        printf("El resultado de %d a la %d es de: %d\n\n", numero, potencia, elevar_potencia(numero, potencia));
    }
}

int elevar_potencia(int numero_f, int potencia_f)
{
    int potencia_retorno = 1, i;

    for ( i = 1; i <= potencia_f; i++)
    
        potencia_retorno *= numero_f;
    
    return potencia_retorno;
}