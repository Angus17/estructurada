
/* 
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
        Para un grupo de 50 alumnos que se conoce la matricula,
        sexo, semestre y promedio, obtener:

        1- Matricula y mayor promedio de las mujeres
        2- Matrucula y mayor promedio de los hombres
        3- promedio de CANTIDAD de alumnos de 1er, 4to, 6to, 8vo semestre
        
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Autor: Diego Leonardo Alejo Cantu
Fecha de actualizacion: 07/02/2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{

    int matricula, matricula_mayor_1, matricula_mayor_2, semestre[50], i;
    char sexo;
    float promedio[50], promedio_mayor_1 = 0, promedio_mayor_2 = 0;

    #if defined(WIN_32) || defined(WIN_64)

        for ( i = 0; i < 50 ; i++)
        {
            
            {
                printf("\nIngresa la matricula de el/la alumn@ %d: ", i + 1);
                scanf("%d", &matricula);

                if (matricula <= 0)
                {
                    system("cls");
                    printf("Ingresa una matricula valida");
                    system("pause");
                    system("cls");
                }
                
            } while (matricula <= 0);

            system("cls");

            do
            {
                printf("\nIngresa el sexo de el/la alumn@ %d\nH\nM\n: ", i + 1);
                scanf(" %c", &sexo);

                sexo = tolower(sexo);

                if (sexo != 'h' && sexo != 'm')
                {
                    system("cls");
                    printf("Ingresa un dato valido para el sexo de el/la alumn@");
                    system("pause");
                    system("cls");
                }
                
            } while (sexo != 'h' && sexo != 'm');

            system("cls");

            do
            {
                printf("\nEn que semmestre se encuentra el/la alumn@ %d\n: ", i + 1);
                scanf("%d", &semestre[i]);

                if (semestre[i] < 0 || semestre[i] > 10)
                {
                    system("cls");
                    printf("Ingresa un semestre valido");
                    system("pause");
                    system("cls");
                }
            } while (semestre[i] < 0 || semestre[i] > 10);

            system("cls");
            
            do
            {
                printf("\nIngresa el promedio de el/la alumn@ %d\n: ", i + 1);
                scanf("%f", &promedio[i]);

                if (promedio[i] < 0.0 || promedio[i] > 100.0)
                {
                    system("cls");
                    printf("El promedio es inexistente, ingresa un dato valido");
                    system("pause");
                    system("cls");
                }
            } while (promedio[i] < 0.0 || promedio[i] > 100.0);

            system("cls");

            /* Caso 1 Promedio mayor de mujeres*/
            
            if (promedio[i] > promedio_mayor_1 && sexo == 'm')
            {
                promedio_mayor_1 = promedio[i];
                matricula_mayor_1 = matricula;
            }

            /* Caso 2 Promedio mayor de hombres*/
            if (promedio[i] > promedio_mayor_2 && sexo == 'h')
            {
                promedio_mayor_2 = promedio[i];
                matricula_mayor_2 = matricula;
            }
        }
        printf("De las mujeres, el promedio mayor fue de %.2f con la alumna de matricula %d\n", promedio_mayor_1, matricula_mayor_1);
        printf("De los hombres, el promedio mayor fue de %.2f con el alumno de matricula %d\n", promedio_mayor_2, matricula_mayor_2);

        printf("\nPromedio de alumnos de 1er semestre:\n");
        for ( i = 0; i < 50; i++)
        {
            if (semestre[i] == 1)
                printf("%.2f\n", promedio[i]);
            
        }

        printf("\nPromedio de alumnos de 4to semestre:\n");
        for ( i = 0; i < 50; i++)
        {
            if (semestre[i] == 4)
                printf("%.2f\n", promedio[i]);
            
        }

        printf("\nPromedio de alumnos de 6to semestre:\n");
        for ( i = 0; i < 50; i++)
        {
            if (semestre[i] == 6)
                printf("%.2f\n", promedio[i]);
            
        }

        printf("\nPromedio de alumnos de 8vo semestre:\n");
        for ( i = 0; i < 50; i++)
        {
            if (semestre[i] == 8)
                printf("%.2f\n", promedio[i]);
            
        }
        
    #elif __linux__

        for ( i = 0; i < 50 ; i++)
        {
            do
            {
                printf("\nIngresa la matricula de el/la alumn@ %d: ", i + 1);
                scanf("%d", &matricula);

                if (matricula <= 0)
                {
                    system("clear");

                    printf("Ingresa una matricula valida");
                    fflush(stdout);
                    
                    printf("\nPresiona la tecla ENTER para continuar. . . ");
                    fflush(stdout);
                    while (getchar() != '\n');
                    getchar();
                    
                    system("clear");
                }
                
            } while (matricula <= 0);

            system("clear");

            do
            {
                printf("\nIngresa el sexo de el/la alumn@ %d\nH\nM\n: ", i + 1);
                scanf(" %c", &sexo);

                sexo = tolower(sexo);

                if (sexo != 'h' && sexo != 'm')
                {
                    system("clear");
                    
                    printf("Ingresa un dato valido para el sexo de el/la alumn@\n");
                    fflush(stdout);
                    
                    printf("\nPresiona la tecla ENTER para continuar. . . ");
                    fflush(stdout);
                    while (getchar() != '\n');
                    getchar();
                    
                    system("clear");
                }
                
            } while (sexo != 'h' && sexo != 'm');

            system("clear");

            do
            {
                if (sexo == 'h')
                
                    printf("\nEn que semestre se encuentra el alumno: ");
                
                else
                
                    printf("\nEn que semestre se encuentra la alumna: ");

                scanf("%d", &semestre[i]);

                if (semestre[i] < 0 || semestre[i] > 10)
                {
                    system("clear");
                    
                    printf("Ingresa un semestre valido");
                    fflush(stdout);
                    
                    printf("\nPresiona la tecla ENTER para continuar. . . ");
                    fflush(stdout);
                    while (getchar() != '\n');
                    getchar();
                    
                    system("clear");
                }
            } while (semestre[i] < 0 || semestre[i] > 10);

            system("clear");
            
            do
            {
                if (sexo == 'h')
                
                    printf("\nIngresa el promedio de el alumno: ");
                
                else
                
                    printf("\nIngresa el promedio de la alumna: ");
                    
                scanf("%f", &promedio[i]);

                if (promedio[i] < 0.0 || promedio[i] > 100.0)
                {
                    system("clear");
                    
                    printf("El promedio es inexistente, ingresa un dato valido");
                    fflush(stdout);
                    
                    printf("\nPresiona la tecla ENTER para continuar. . . ");
                    fflush(stdout);
                    while (getchar() != '\n');
                    getchar();
                    
                    system("clear");
                }
            } while (promedio[i] < 0.0 || promedio[i] > 100.0);

            system("clear");

            /* Caso 1 Promedio mayor de mujeres*/
            
            if (promedio[i] > promedio_mayor_1 && sexo == 'm')
            {
                promedio_mayor_1 = promedio[i];
                matricula_mayor_1 = matricula;
            }

            /* Caso 2 Promedio mayor de hombres*/
            if (promedio[i] > promedio_mayor_2 && sexo == 'h')
            {
                promedio_mayor_2 = promedio[i];
                matricula_mayor_2 = matricula;
            }
        }
        printf("De las mujeres, el promedio mayor fue de %.2f con la alumna de matricula %d\n", promedio_mayor_1, matricula_mayor_1);
        printf("De los hombres, el promedio mayor fue de %.2f con el alumno de matricula %d\n", promedio_mayor_2, matricula_mayor_2);

        printf("\nPromedio de alumnos de 1er semestre:\n");
        for ( i = 0; i < 50; i++)
        {
            if (semestre[i] == 1)
                printf("%.2f\n", promedio[i]);
            
        }

        printf("\nPromedio de alumnos de 4to semestre:\n");
        for ( i = 0; i < 50; i++)
        {
            if (semestre[i] == 4)
                printf("%.2f\n", promedio[i]);
            
        }

        printf("\nPromedio de alumnos de 6to semestre:\n");
        for ( i = 0; i < 50; i++)
        {
            if (semestre[i] == 6)
                printf("%.2f\n", promedio[i]);
            
        }

        printf("\nPromedio de alumnos de 8vo semestre:\n");
        for ( i = 0; i < 50; i++)
        {
            if (semestre[i] == 8)
                printf("%.2f\n", promedio[i]);
            
        }

    #endif // DEBUG
}