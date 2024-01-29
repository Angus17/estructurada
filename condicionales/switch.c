/* 
    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
        PROGRAMA QUE SEÑALE SI EL CARACTER INGRESADO PERTENECE DE LA
                            {a...d}

                Fecha de actualizacion: 27-01-2024 
                    
                *********************************
                    Programacion Estructurada
                *********************************
    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 */

#include <stdio.h>

int main(void)
{
    char letter;

    printf("Escribe una letra de la \'a\' a la \'d\': ");
    scanf("%c", &letter);
    
    switch (letter)
    {
        case 'a':
            printf("Ingresaste la letra \'a\'\n");
            break;
        case 'b':
            printf("Ingresaste la letra \'b\'\n");
            break;
        case 'c':
            printf("Ingresaste la letra \'c\'\n");
            break;
        case 'd':
            printf("Ingresaste la letra \'d\'\n");
            break;
        
        default:
            printf("La letra que ingresaste no pertenece al conjunto esperado\n");
            break;
    }

    return 0;
}