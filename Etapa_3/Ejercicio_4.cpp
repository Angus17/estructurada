/*
    Elabora un programa que realice los siguientes calculos:

    Area de triangulo, area de circulo, area de rectangulo

    Solicita y valida los datos de entrada desde main, para posteriormente ejecutar en paralelo los tres calculos
    y mostrar el resultado

    Elabora una funcion para caa una de los calculos e impresion de datos
*/

#include <iostream>
#include <thread>
#include <chrono>
#ifdef __linux__
    #include <stdio_ext.h>
#endif

using namespace std;
using namespace chrono;

static void area_triangulo(int *, int *);
static void area_circulo(int *, const int *);
static void area_rectangulo(int *, int *);

static void limpiar_buffer_STDIN();
static void limpiar_terminal();
static void pausar_terminal();
static void validar_errores_por_SO();

int main()
{
    bool dato_invalido;
    int base_triangulo, base_rectangulo, radio_circulo, altura_triangulo, altura_rectangulo;
    const int pi = 3.1416;

    do
    {
        limpiar_terminal();

        cout << "Ingresa el valor de la base del triangulo: ";
        limpiar_buffer_STDIN();
        cin >> base_triangulo;

        if ((dato_invalido = cin.fail()) || base_triangulo <= 0)
        {
            cin.clear();
            validar_errores_por_SO();
        }

    } while (dato_invalido || base_triangulo <= 0);

    do
    {
        limpiar_terminal();

        cout << "Ingresa el valor de la altura del triangulo: ";
        limpiar_buffer_STDIN();
        cin >> altura_triangulo;

        if ((dato_invalido = cin.fail()) || altura_triangulo <= 0)
        {
            cin.clear();
            validar_errores_por_SO();
        }

    } while (dato_invalido || altura_triangulo <= 0);

    do
    {
        limpiar_terminal();

        cout << "Ingresa el valor de la base del rectangulo: ";
        limpiar_buffer_STDIN();
        cin >> base_rectangulo;

        if ((dato_invalido = cin.fail()) || base_rectangulo <= 0)
        {
            cin.clear();
            validar_errores_por_SO();
        }

    } while (dato_invalido || base_rectangulo <= 0);

    do
    {
        limpiar_terminal();

        cout << "Ingresa el valor de la altura del rectangulo: ";
        limpiar_buffer_STDIN();
        cin >> altura_rectangulo;

        if ((dato_invalido = cin.fail()) || altura_rectangulo <= 0)
        {
            cin.clear();
            validar_errores_por_SO();
        }

    } while (dato_invalido || altura_rectangulo <= 0);

    do
    {
        limpiar_terminal();

        cout << "Ingresa el radio del circulo: ";
        limpiar_buffer_STDIN();
        cin >> radio_circulo;

        if ((dato_invalido = cin.fail()) || radio_circulo <= 0)
        {
            cin.clear();
            validar_errores_por_SO();
        }

    } while (dato_invalido || radio_circulo <= 0);

    limpiar_terminal();

    thread triangulo(area_triangulo, &base_triangulo, &altura_triangulo);
    thread circulo(area_circulo, &radio_circulo, &pi);
    thread rectangulo(area_rectangulo, &base_rectangulo, &altura_rectangulo);

    triangulo.join();
    circulo.join();
    rectangulo.join();

    return EXIT_SUCCESS;
}

static void area_triangulo(int *base, int *altura)
{
    float resultado = (float) ((*base) * (*altura) / 2);

    cout << "El area del triangulo es de: " << resultado << endl;
    this_thread::sleep_for(milliseconds(1000));
}

static void area_circulo(int *radio, const int *pi)
{
    float resultado = static_cast<float>((*pi)) * (*radio) * (*radio);

    cout << "El area del circulo es de: " << resultado << endl;
    this_thread::sleep_for(milliseconds(1000));
}

static void area_rectangulo(int *base, int *altura)
{
    float resultado = (float) ((*base) * (*altura) / 2);

    cout << "El area del rectangulo es de: " << resultado << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
}

// Limpia buffer STDIN tanto para sistemas Windows como para UNIX/Linux
static void limpiar_buffer_STDIN()
{
    #if defined(_WIN32) || defined(_WIN64)
        rewind(stdin);
    #elif __linux__
        __fpurge(stdin);
    #endif
}


// Limpia terminal tanto para sistemas Windows como para UNIX/Linux
static void limpiar_terminal()
{
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #elif __linux__
        system("clear");
    #endif
}

// Pausa la terminal tanto para sistemas Windows como para UNIX/Linux
static void pausar_terminal()
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

// Clasifica los mensajes de error tanto para Windows como para UNIX/Linux, cuando se ingresan datos incorrectos
static void validar_errores_por_SO()
{
    #if defined(_WIN32) || defined(_WIN64)
        limpiar_terminal();

        cerr << "Dato/s ingresado/s no válido/s, verificar dato/s" << endl;
        pausar_terminal();
        limpiar_terminal();
    #elif __linux__
        limpiar_terminal();

        cerr << "Dato/s ingresado/s no válido/s, verificar dato/s" << endl;
        fflush(stdout);
        pausar_terminal();
        limpiar_terminal();
    #endif
}