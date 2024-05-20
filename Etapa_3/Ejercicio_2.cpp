/*  
    Elabora un programa que contenga una funcion que calcule la distancia entre dos puntos 
    {(x1, y1)} y {(x2, y2)}

    El usuario puede dar varios pares de pintos u a cada uno de ellos se indicara la distancia
*/

#include <iostream>
#include <cmath>
#include <string>

#ifdef __linux__
    #include <stdio_ext.h>
#endif

using namespace std;

void limpiar_terminal();
void pausar_terminal();

static void calcular_distancia(int &, int &, int &, int &, float &);

int main()
{
    int punto_x1, punto_x2, punto_y1, punto_y2;
    float distancia;
    char respuesta;

    do
    {
        cout << "Ingresa el punto X_1: ";
        cin >> punto_x1;

        cout << "Ingresa el punto Y_1: ";
        cin >> punto_y1;

        cout << "Ingresa el punto X_2: ";
        cin >> punto_x2;

        cout << "Ingresa el punto Y_2: ";
        cin >> punto_y2;

        limpiar_terminal();

        calcular_distancia(punto_x1, punto_x2, punto_y1, punto_y2, distancia);

        cout << "La distancia de los puntos ( " << punto_x1<< ", " << punto_y1 << " ) y el punto ( " << punto_x2 << ", " << punto_y2 << " ) es de: " << distancia << endl;

        pausar_terminal();
        limpiar_terminal();

        cout << "Desea calcular mas distancias? :"<< endl << "S/N"<< endl << ": ";
        cin >> respuesta;

    } while (respuesta != 'n');

    return EXIT_SUCCESS;
}

static void calcular_distancia(int &x1, int &x2, int &y1, int &y2, float &distancia_total)
{
    distancia_total = static_cast<float>( sqrt(abs(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)))) );

}

// Limpia buffer STDIN tanto para sistemas Windows como para UNIX/Linux
void limpiar_buffer_STDIN()
{
    #if defined(_WIN32) || defined(_WIN64)
        rewind(stdin);
    #elif __linux__
        __fpurge(stdin);
    #endif
}


// Limpia terminal tanto para sistemas Windows como para UNIX/Linux
void limpiar_terminal()
{
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #elif __linux__
        system("clear");
    #endif
}

// Pausa la terminal tanto para sistemas Windows como para UNIX/Linux
void pausar_terminal()
{
    #if defined(_WIN32) || defined(_WIN64)
        system("pause");
    #elif __linux__
        cout << "Presiona ENTER para continuar. . .";
        fflush(stdout);
        limpiar_buffer_STDIN();
        cin.get();
    #endif
}
