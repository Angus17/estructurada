#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool Buscar_numeros_primos(int);
 
int main(void)
{
    long int numero_a_buscar;

    printf("Ingresa el numero: ");
    scanf("%ld", &numero_a_buscar);

    for (int i = 1; i <= numero_a_buscar; i++)
    {
        if (Buscar_numeros_primos(i))
        
            printf("%d  ", i);
        
    }
    

    return 0;
}

bool Buscar_numeros_primos(int numero)
{
    if (numero == 2)
    
        return true;
    
    else if (numero < 2 || numero % 2 == 0)
    
        return false;
    
        else
        {
            for (int i = 3; i <= sqrt(numero) ; i += 2)
            {
                if (numero % i == 0)
                
                    return false;
                
                
            }

            return true;
        }
}