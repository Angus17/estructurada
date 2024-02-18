/* 
        PROGRAMA QUE IMPRIMA LOS 255 CARACTERES DE LA TABLA ASCII

 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i;

    for ( i = 0; i < 256; i++)
    
        printf(" %c ", i);
    system("pause");
}