/* 
    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
        PROGRAMA QUE DETERMINE EL NUMERO MAYOR DE DOS NUMEROS ENTEROS

                Fecha de actualizacion: 27-01-2024 
                    
                *********************************
                    Programacion Estructurada
                *********************************
    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 */

#include <stdio.h>

main()
{
    int numero_1, numero_2;

    printf("Escribe el primer numero: ");
    scanf("%d", &numero_1);

    printf("Escribe el segundo numero: ");
    scanf("%d", &numero_2);

    if (numero_1 > numero_2)
    
        printf("El numero %d es mayor que %d\n",numero_1, numero_2);
    

    if (numero_2 > numero_1)
    
        printf("El numero %d es mayor que %d\n",numero_2, numero_1);
    
}
