
/* 
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        En una empresa con N empleados se necesita obtener cierta informacion, por cada empleado 
        se ingresa los siguientes datos:

        - Clave (A o B)
        - Edad (0 a 65)
        - Sexo (F, f, M, m)
        - y sueldo > 0

        Hacer programa que calucle e imprima:

        a) Numero de hombres
        b) Numero de mujeres
        c) Numero de mujeres que ganan mas de $30,000
        d) Numero de hombres menores de 40 años que ganan menos de $40,000
        e) Numero de empleados mayores de 50 años
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Autor: Diego Leonardo Alejo Cantu
Fecha de actualizacion: 08/02/2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <stdbool.h>

int main(void)
{

    int contador_mujeres = 0, contador_hombres = 0, contador_mujeres_2 = 0, contador_hombres_2 = 0, empleados_50 = 0, edad, sueldo, contador_empleados = 0;
    char respuesta_existencia, clave, sexo;
    bool existencia = false;

    setlocale(LC_CTYPE, "spanish");

    do
    {
        printf("Existen empleados?\nS.Si\nN.No\n: ");
        #if defined(_WIN32) || defined(_WIN64)
            fflush(stdin);
        #endif
        scanf(" %c", &respuesta_existencia);

        respuesta_existencia = tolower(respuesta_existencia);

        #if defined(_WIN32) || defined(_WIN64)

            if (respuesta_existencia != 's' && respuesta_existencia != 'n')
            {
                system("cls");

                printf("Ingresa una respuesta válida\n");
                system("pause");
                system("cls");
            }
            else if (respuesta_existencia == 's')
            
                existencia = true;

        #elif __linux__
            
            if (respuesta_existencia != 's' && respuesta_existencia != 'n')
            {
                system("clear");

                printf("Ingresa una respuesta válida");
                fflush(stdout);
                
                printf("\nPresiona la tecla ENTER para continuar. . . ");
                fflush(stdout);
                while (getchar() != '\n');
                getchar();
                
                system("clear");
            }
            else if (respuesta_existencia == 's')
            
                existencia = true;
        #endif 
        
        
    } while (respuesta_existencia != 's' && respuesta_existencia != 'n');

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #elif __linux__
        system("clear");
    #endif 
    
    while (existencia)
    {
        do
        {
            printf("Ingresa la clave de el/la emplead@ %d\n- A\n- B\n: ", contador_empleados + 1);
            #if defined(_WIN32) || defined(_WIN64)
                fflush(stdin);
            #endif
            scanf(" %c", &clave);

            clave = tolower(clave);

            #if defined(_WIN32) || defined(_WIN64)
            
                if (clave != 'a' && clave != 'b')
                {
                    system("cls");

                    printf("Ingresa una respuesta válida");
                    system("pause");
                    system("cls");
                }
            #elif __linux__

                if (clave != 'a' && clave != 'b')
                {
                    system("clear");

                    printf("Ingresa una respuesta válida");
                    fflush(stdout);
                    
                    printf("\nPresiona la tecla ENTER para continuar. . . ");
                    fflush(stdout);
                    while (getchar() != '\n');
                    getchar();
                    
                    system("clear");
                }
            #endif 

        } while (clave != 'a' && clave != 'b');

        #if defined(_WIN32) || defined(_WIN64)
            system("cls");
        #elif __linux__
            system("clear");
        #endif 
        
        do
        {
            printf("Ingresa la edad de el/la emplead@ %d: ", contador_empleados + 1);
            scanf("%d", &edad);
            
            #if defined(_WIN32) || defined(_WIN64)

                if (edad < 0)
                {
                    system("cls");
                    printf("Ingresa una respuesta válida\n");
                    system("pause");
                    system("cls");
                }
                else if (edad < 18)
                    {
                        system("cls");

                        printf("No existen empleados menores de edad\n");
                        system("pause");
                        system("cls");
                    }
                    else if (edad > 65)
                        {
                            system("cls");

                            printf("No existen empleados mayores de 65 años\n");
                            system("pause");
                            system("cls");
                        }

            #elif __linux__
            
                if (edad < 0)
                {
                    system("clear");

                    printf("Ingresa una respuesta válida");
                    fflush(stdout);
                    
                    printf("\nPresiona la tecla ENTER para continuar. . . ");
                    fflush(stdout);
                    while (getchar() != '\n');
                    getchar();
                    
                    system("clear");
                }
                else if(edad < 18)
                    {
                        system("clear");

                        printf("No existen empleados menores de edad");
                        fflush(stdout);
                        
                        printf("\nPresiona la tecla ENTER para continuar. . . ");
                        fflush(stdout);
                        while (getchar() != '\n');
                        getchar();
                        
                        system("clear");
                    }
                    else if (edad > 65)
                        {
                            system("clear");

                            printf("No existen empleados mayores de 65 años");
                            fflush(stdout);
                            
                            printf("\nPresiona la tecla ENTER para continuar. . . ");
                            fflush(stdout);
                            while (getchar() != '\n');
                            getchar();
                            
                            system("clear");
                        }
            #endif 

        } while (edad < 0 || edad < 18 || edad > 65);
    
        #if defined(_WIN32) || defined(_WIN64)
            system("cls");
        #elif __linux__
            system("clear");
        #endif 

        do
        {
            printf("Ingresa el sexo de el/la emplead@ %d\nM.Hombre\nF.Mujer\n:  ", contador_empleados + 1);

            #if defined(_WIN32) || defined(_WIN64)
                fflush(stdin);
            #endif 
            scanf(" %c", &sexo);

            sexo = tolower(sexo);

            #if defined(_WIN32) || defined(_WIN64)

                if (sexo != 'f' && sexo != 'm')
                {
                    system("cls");

                    printf("Ingresa una respuesta válida para el sexo\n");
                    system("pause");
                    system("cls");
                }

            #elif __linux__
            
                if (sexo != 'f' && sexo != 'm')
                {
                    system("clear");

                    printf("Ingresa una respuesta válida para el sexo");
                    fflush(stdout);
                    
                    printf("\nPresiona la tecla ENTER para continuar. . . ");
                    fflush(stdout);
                    while (getchar() != '\n');
                    getchar();
                    
                    system("clear");
                }
                
            #endif 

        } while (sexo != 'f' && sexo != 'm');

        #if defined(_WIN32) || defined(_WIN64)
            system("cls");
        #elif __linux__
            system("clear");
        #endif 

        do
        {
            (sexo == 'm') ? printf("Ingresa el sueldo del empleado: ") : printf("Ingresa el sueldo de la empleada: ");
            
            scanf("%d", &sueldo);

                #if defined(_WIN32) || defined(_WIN64)

                    if (sueldo < 0)
                    {
                        system("cls");

                        printf("Ingresa una respuesta válida para el sueldo");
                        system("pause");
                        system("cls");
                    }
                #elif __linux__

                    if (sueldo < 0)
                    {
                        system("clear");

                        printf("Ingresa una respuesta válida para el sueldo");
                        fflush(stdout);
                        
                        printf("\nPresiona la tecla ENTER para continuar. . . ");
                        fflush(stdout);
                        while (getchar() != '\n');
                        getchar();
                        
                        system("clear");
                    }
                #endif 
            
        } while (sueldo < 0);
                

        do
        {
            printf("Existen más empleados?\nS.Si\nN.No\n: ");
            scanf(" %c", &respuesta_existencia); 
            
            (sexo == 'm')?printf("Ingresa el sueldo del empleado: "):printf("Ingresa el sueldo de la empleada: ");

            respuesta_existencia = tolower(respuesta_existencia);

            #if defined(_WIN32) || defined(_WIN64)

                if (respuesta_existencia != 's' && respuesta_existencia != 'n')
                {
                    system("cls");

                    printf("Ingresa una respuesta válida");
                    printf("\nPresiona la tecla ENTER para continuar. . . ");
                    fflush(stdin);
                    getchar();
                    
                    system("cls");
                }
                else if (respuesta_existencia == 'n')
                
                        existencia = false;

            #elif __linux__
                
                if (respuesta_existencia != 's' && respuesta_existencia != 'n')
                {
                    system("clear");

                    printf("Ingresa una respuesta valida");
                    fflush(stdout);
                    
                    printf("\nPresiona la tecla ENTER para continuar. . . ");
                    fflush(stdout);
                    while (getchar() != '\n');
                    getchar();
                    
                    system("clear");
                }
                else if (respuesta_existencia == 'n')
                
                        existencia = false;
                    
            #endif 

        } while (respuesta_existencia != 's' && respuesta_existencia != 'n');

        if (sexo == 'm' && edad < 40 && sueldo < 40000)
        {
            contador_hombres_2++;
            contador_hombres++;
        }
        else if (sexo == 'm')
            
                contador_hombres++;
            
            else if (sexo == 'f' && sueldo > 30000)
                {
                    contador_mujeres_2++;
                    contador_mujeres++;
                }
                else
                
                    contador_mujeres++;
                
        if (edad > 50)
        
            empleados_50++;
        
        contador_empleados++;

        #if defined(_WIN32) || defined(_WIN64)
        system("cls");
        #elif __linux__
            system("clear");
        #endif 
    }
    
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #elif __linux__
        system("clear");
    #endif 

    if (contador_empleados > 0)
    {
        printf("Hay un total de %d empleados hombres\n", contador_hombres);
        printf("Hay un total de %d empleadas mujeres\n", contador_mujeres);
        printf("Hay un total de %d empleadas mujeres que ganan mas de $30,000\n", contador_mujeres_2);
        printf("Hay un total de %d empleados hombres menores de 40 años que ganan menos de $40,000\n", contador_hombres_2);
        printf("Hay un total de %d emplead@s mayores de 50 años\n", empleados_50);

        #if defined(_WIN32) || defined(_WIN64)
            system("pause");
        #elif __linux__
            printf("\nPresiona la tecla ENTER para continuar. . . ");
            fflush(stdout);
            while (getchar() != '\n');
            getchar();
        #endif 
    }
    
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
        printf("\nOperacion finalizada! . . .\n");
    #elif __linux__
        system("clear");
        printf("\nOperacion finalizada! . . .\n");
        fflush(stdout);
    #endif 
}