#include <stdio.h>
#include <math.h>

int main(void)
{
    int entero_y;

    printf("Escribe un numero: ");
    scanf("%d", &entero_y);

    if (entero_y <= 11)
    
        entero_y += 50;
    
    else if (entero_y <= 33)
        
            entero_y *= entero_y -10;
        
        else if (entero_y <= 64)
            
                entero_y = pow(entero_y,3) + (entero_y * entero_y) - 10;
            
            else
            
                entero_y = 0;
            
            
    printf("\nEl nuevo numero es: %d\n", entero_y);
}
