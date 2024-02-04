#include <stdio.h>
#include <locale.h>

int main(void)
{
    int categoria, horas_trabajadas, horas_extra;
    float sueldo, sueldo_nuevo;

    setlocale(LC_CTYPE, "spanish");
    
    printf("Ingresa el sueldo del trabajador: ");
    scanf("%f", &sueldo);

    printf("Ingresa las horas extra trabajadas: ");
    scanf("%d", &horas_extra);

    printf("Ingresa la categoría del trabajador: ");
    scanf("%d", &categoria);

    horas_trabajadas = horas_extra;
    
    if (horas_trabajadas > 30)
    
        horas_trabajadas = 30;
    
    switch (categoria)
    {
        case 1: 
            sueldo_nuevo = sueldo + horas_trabajadas * 30;
            break;
        
        case 2: 
            sueldo_nuevo = sueldo + horas_trabajadas * 40;
            break;

        case 3: 
            sueldo_nuevo = sueldo + horas_trabajadas * 50;
            break;

        case 4: 
            sueldo_nuevo = sueldo + horas_trabajadas * 70;
            break;

        default:
            sueldo_nuevo = sueldo;
            break;
    }
    printf("\nEl sueldo nuevo del trabajador será de: %.2f\n", sueldo_nuevo);
}