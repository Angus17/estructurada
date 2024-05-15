#include <stdio.h>
#include <stdio_ext.h>
#include <regex.h>

int main(void)
{
    char correo[100];
    char regex[] = "^[A-Za-z0-9._-]+@[a-z]+\\.[a-z]{2,}$";

    regex_t regular;

    int reg_ex = regcomp(&regular, regex, REG_EXTENDED);

    // regcomp(puntero a estructura regex, cadena regex a compilar, macro indicadoor);
    /* 
        REG_EXTENDED: Esta constante indica que la expresión regular utiliza la sintaxis extendida 
                    de expresiones regulares POSIX.
        REG_ICASE: Esta constante indica que la coincidencia debe ser insensible a mayúsculas y 
                    minúsculas.
        REG_NOSUB: Esta constante indica que no se necesita almacenar información sobre las 
                    subcadenas coincidentes.
        REG_NEWLINE: Esta constante indica que el punto (.) en la expresión regular también 
                    debe coincidir con caracteres de nueva línea.
    
     */
    if (!reg_ex)
    {
        do
        {
            
            printf("Ingresa un correo: ");
            __fpurge(stdin);
            scanf(" %s", correo);

            reg_ex = regexec(&regular, correo, 0, NULL, 0);

            /*
                regecex(puntero a estructura regex, cadena a evaluar, );
            
            
            */

        } while (reg_ex);
    }
    else
    {
        puts("No compiló");
    }
    
    
    regfree(&regular);
}