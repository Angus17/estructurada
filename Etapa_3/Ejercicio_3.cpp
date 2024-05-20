/*
    Elaborar un programa que le permita al usuario adivinar
    un numero contenido entre 1 y 100 generado aleatoriamente.

    Para cada numero indicado por el usuario, muestra alguno de los siguientes mensajes:

    - Adivinaste el numero
    - Muy bajo. Intenta de nuevo
    - Muy alto. Intenta de nuevo

Ademas, cuenta y muestra el numero de intentos que tardo el usuario para realizar el numero. Si lo hace en 10 o menos
, manda el mensaje "Lo hiciste excelente", si se tardó 20 o menos "Lo hiciste bien", si tarda mas de 20 indica "Lo puedes hacer mejor" 

- Elabora una funcion que reciba el numero y manda el mensaje correspondiente

*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#ifdef __linux__
    #include <stdio_ext.h>
#endif


using namespace std;

static bool adivinar_Numero(int &, int &, int &);

static void limpiar_buffer_STDIN();
static void limpiar_terminal();
static void pausar_terminal();


int main()
{
    int numero_a_ingresar, numero_aleatorio, intentos = 1;
    bool numero_adivinado = false, entrada_invalida;

    srand( time(NULL) );

    numero_aleatorio = rand() % 100 + 1;

    do
    {
        do
        {
            limpiar_terminal();

            cout << "Ingresa un numero: ";
            limpiar_buffer_STDIN();
            cin >> numero_a_ingresar;

            if ((entrada_invalida = cin.fail()))

                cin.clear();

            
        } while (entrada_invalida);
        

        numero_adivinado = adivinar_Numero(numero_a_ingresar, numero_aleatorio, intentos);
        
    } while (!numero_adivinado);
    

    return EXIT_SUCCESS;
}

static bool adivinar_Numero(int &numero_ingresado, int &numero_a_adivinar, int &total_intentos)
{

    if (numero_ingresado == numero_a_adivinar)
    {
        cout << "Adivinaste el numero!! en "<< total_intentos << " intentos" <<endl;

        if (total_intentos <= 10)
        
            cout << "Lo hiciste excelente!" << endl;
        
        else if (total_intentos <= 20)
            
                cout << "Lo hiciste bien!" << endl;
            
            else
            
                cout << "Puedes hacerlo mejor. . ." << endl;
        
        pausar_terminal();
        
        return true;
    }
    else if (numero_ingresado < numero_a_adivinar)
        
            cout << "MUY BAJO. Vuelve a intentarlo" << endl;
        else
        
            cout << "MUY ALTO. Vuelve a intentar" << endl;

    pausar_terminal();
        
    total_intentos++;
    return false;
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
