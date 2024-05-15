#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#ifdef __linux__
    #include <stdio_ext.h>
#endif


using namespace std;
using namespace chrono;
using namespace this_thread;

void repeticiones_tiempo(int *, int *, const string *);

static void limpiar_buffer_STDIN();
static void limpiar_terminal();
static void pausar_terminal();
static void validar_errores_por_SO();

int main()
{
    string cadena[3];
    thread hilos[3];
    bool dato_invalido;
    int repeticion[3], retardo[3];

    cout << "Ingresa la cadena 1: ";
    limpiar_buffer_STDIN();

    getline(cin, *(cadena + 0), '\n');

    do
    {
        limpiar_terminal();

        cout << "Cuantas veces quieres repetir?: ";
        limpiar_buffer_STDIN();
        cin >> *(repeticion + 0);

        if ((dato_invalido = cin.fail()))
        {
            cin.clear();
            validar_errores_por_SO();
        }
        else if (*(repeticion + 0) < 0)

                validar_errores_por_SO();

    } while (dato_invalido || *(repeticion + 0) < 0);

    do
    {
        limpiar_terminal();

        cout << "Retardo: ";
        limpiar_buffer_STDIN();
        cin >> *(retardo + 0);

        if ((dato_invalido = cin.fail()))
        {
            cin.clear();
            validar_errores_por_SO();
        }
        else if (*(retardo + 0) < 0)

                validar_errores_por_SO();

    } while (dato_invalido || *(retardo + 0) < 0);

    limpiar_terminal();

    cout << "Ingresa la cadena 2: ";
    limpiar_buffer_STDIN();
    getline(cin, *(cadena + 1), '\n');

    do
    {
        limpiar_terminal();

        cout << "Cuantas veces quieres repetir?: ";
        limpiar_buffer_STDIN();
        cin >> *(repeticion + 1);

        if ((dato_invalido = cin.fail()))
        {
            cin.clear();
            validar_errores_por_SO();
        }
        else if (*(repeticion + 1) < 0)

                validar_errores_por_SO();

    } while (dato_invalido || *(repeticion + 1) < 0);

    do
    {
        cout << "Retardo: ";
        limpiar_buffer_STDIN();
        cin >> *(retardo + 1);

        if ((dato_invalido = cin.fail()))
        {
            cin.clear();
            validar_errores_por_SO();
        }
        else if (*(retardo + 1) < 0)

                validar_errores_por_SO();

    } while (dato_invalido || *(retardo + 1) < 0);

    limpiar_terminal();

    cout << "Ingresa la cadena 3: ";
    limpiar_buffer_STDIN();
    getline(cin, *(cadena + 2), '\n');

    do
    {
        cout << "Cuantas veces quieres repetir?: ";
        limpiar_buffer_STDIN();
        cin >> *(repeticion + 2);

        if ((dato_invalido = cin.fail()))
        {
            cin.clear();
            validar_errores_por_SO();
        }
        else if (*(repeticion + 2) < 0)

                validar_errores_por_SO();

    } while (dato_invalido || *(repeticion + 2) < 0);

    do
    {
        cout << "Retardo: ";
        limpiar_buffer_STDIN();
        cin >> *(retardo + 2);

        if ((dato_invalido = cin.fail()))
        {
            cin.clear();
            validar_errores_por_SO();
        }
        else if (*(retardo + 2) < 0)

                validar_errores_por_SO();

    } while (dato_invalido);

    limpiar_terminal();

    *(hilos + 0) = thread(repeticiones_tiempo, repeticion, retardo, cadena);

    *(hilos + 1) = thread(repeticiones_tiempo, repeticion + 1, retardo + 1, cadena + 1);

    *(hilos + 2) = thread(repeticiones_tiempo, repeticion + 2, retardo + 2, cadena + 2);


    (*(hilos + 0)).join();
    (*(hilos + 1)).join();
    (*(hilos + 2)).join();

    return EXIT_SUCCESS;
}

void repeticiones_tiempo(int *repeticion, int *espera, const string *cadena)
{
    int i;

    for ( i = 0; i < *repeticion; i++)
    {
        cout << *cadena << endl;
        sleep_for(milliseconds(*espera));
    }
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