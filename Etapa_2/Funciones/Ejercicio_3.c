/* 
    Un estacionamiento cobra $10 por las tres primeras horas
    a partir de ahi cobre $5 por cada hora extra. Si el auto dura
    mas de 24h cobra $300. Escriba un programa que calcule el pago para 5 autos
    Elabora una funcion que calcule el pago de cada auto

    Imprimir en forma tabular los resultados de cada auto y un total de
    cobros:

    Auto                Horas               Cobro
    1                     2                   $10
    2                     25                  $300      
    .                     .                     .
    5                     .                     .

    Total General: $970
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#if __linux__
    #include <stdio_ext.h>
#endif 

struct Automoviles_Estacionamiento
{
    int horas;
    int cobro;
};

int calcular_cobro_estacionamiento(int);
void validar_Sistema_Operativo(bool);

int main(void)
{
    int i;
    struct Automoviles_Estacionamiento datos[5];

    for ( i = 0; i < 5; i++)
    {
        do
        {
            printf("Cuantas horas estuvo estacionado el auto #%d: ", i + 1);

            #if defined(_WIN32) || defined(_WIN64)
                fflush(stdin);
            #elif __linux__
                __fpurge(stdin);
            #endif

            scanf("%d", &datos[i].horas);

            if (datos[i].horas <= 0)
            {
                #if defined(_WIN32) || defined(_WIN64)
                    validar_Sistema_Operativo(true);
                #elif __linux__
                    validar_Sistema_Operativo(false);
                #endif 
            }
            
        } while (datos[i].horas <= 0);

        datos[i].cobro = calcular_cobro_estacionamiento(datos[i].horas);
        
    }

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #elif __linux__
        system("clear");
    #endif

    printf("\t\t\tAuto\t\t\tHoras\t\t\tCobro\n\n");

    for ( i = 0; i < 5; i++)
    
        printf("\t\t\t%d\t\t\t%d\t\t\t%d\n", i + 1, datos[i].horas, datos[i].cobro);

}

int calcular_cobro_estacionamiento(int hours)
{
    int cobro = 10;

    if (hours > 3 && hours <= 24)
    
        cobro += (hours - 3) * 5;
    
    else if (hours > 24)
        
            cobro = 300;
        

    return cobro;
}

void validar_Sistema_Operativo(bool data)
{
    
    if (data)
    {
        system("cls");

        printf("Dato ingresado no valido, verificar dato");
        printf("\nPresiona la tecla ENTER para continuar. . . ");
        fflush(stdin);
        getchar();
        system("cls");
    }
    else
    {
        system("clear");

        printf("Dato ingresado no valido, verificar dato");
        fflush(stdout);
        
        printf("\nPresiona la tecla ENTER para continuar. . . ");
        fflush(stdout);
        __fpurge(stdin);
        getchar();
        
        system("clear");
    }
}