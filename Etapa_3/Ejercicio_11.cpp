/*

    Elaborar un programa en Lenguaje C++, tal que para N productos
    (a lo mas pueden ser 100 ), almacene los siguientes datos
    (utilizar una estructura).

    - Clave (mayor a cero)
    - Existencia (mayor a cero)
    - Minimo a mantener en existencia. Punto de reorden (mayor o igual de cero)
    - Precio unitario (mayor que 0)
    
    Mostrar el siguiente menu:
    
    a) Captura de datos
    b) Llevar a cabo la venta de los productos (clave y cantidad vendida)
    . Actualizar el campo de existencia y no se puede vender mas de los que
    hay. Mostrarle el total a pagar del cliente.

    c) Listado de productos a resurtir. considerando  su punto de reorden 
    (clave de producto, descripcion, existencia, y punto de reorden)

    d) Actualizar la existencia de N productos (Clave_art, cantidad)

    e) Actualizar el precio de N productos (clave_art, porcentaje de incremento(.1, .08))

    f) Desplegar la informacion de N productos (Clave) Muestre en forma 
    tabular todos los datos

    g) Salir

    Utilizar menu de opciones, funciones a tu criterio
    RToda la informacion escribir y leer en archivo de acceso
    directo. Agregar excepciones y expresiones regulares
*/

#include <iostream>
#include <string>
#include <cstring>
#include <regex>
#include <fstream>
#include <filesystem>

#if defined(__linux__) && !defined(_ANDROID_)

    #include <stdio_ext.h>

#endif

using namespace std;
using namespace filesystem;

struct Datos_Articulos
{
    int clave, existencia;
    int punto_reorden, precio_unitario;
};

static bool crear_archivo(fstream &,string *, const int *);
static void leer_datos(struct Datos_Articulos *&);

static void convertir_cadena_a_minuscula(string &);

static void validar_errores_por_SO();
static void limpiar_buffer_STDIN();
static void limpiar_terminal();
static void pausar_terminal();


int main()
{
    string path_actual = current_path();
    const int maximo_articulos = 100;

    path_actual += "/ventas.dat";

    fstream Articulos(path_actual, ios::out | ios::in | ios::binary);

    if (!Articulos)
    {
        cerr << "ERROR AL CREAR EL FICHERO. . ." << endl;

        return EXIT_FAILURE;
    }

    crear_archivo(Articulos, &path_actual, &maximo_articulos);
    Articulos.close();

    return EXIT_SUCCESS;
}

static bool crear_archivo(fstream &file_object, string *dir, const int *max_articles)
{
    string respuesta;
    int i = 0;
    struct Datos_Articulos data = {0, 0, 0, 0};

    file_object.open(*dir, ios::in | ios::out);

    file_object.clear();

    file_object.seekg(0, file_object.end);

    if (file_object.tellg() > 0)
    {
        file_object.seekg(0, file_object.beg);

        do
        {
            limpiar_terminal();

            cout << "Desea recrear los datos del fichero? Si/No: ";
            limpiar_buffer_STDIN();
            getline(cin, respuesta, '\n');

            convertir_cadena_a_minuscula(respuesta);

            if (respuesta.empty() || (strcmp(respuesta.c_str(), "si") != 0 && strcmp(respuesta.c_str(), "no") != 0))

                validar_errores_por_SO();

        } while (respuesta.empty() || (strcmp(respuesta.c_str(), "si") != 0 && strcmp(respuesta.c_str(), "no") != 0));
    }

    if (file_object.tellg() == 0 || strcmp(respuesta.c_str(), "si") == 0)
    {
        file_object.clear();
        file_object.seekp(0, file_object.beg);

        for ( i = 0; i < *max_articles; i++)

            file_object.write(reinterpret_cast<const char *>(&data), sizeof(struct Datos_Articulos));
    }
}

static void convertir_cadena_a_minuscula(string &cadena)
{
    for (char caracter_obtenido : cadena)
    {
        if (!islower(caracter_obtenido))

            caracter_obtenido = tolower(caracter_obtenido);

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
    printf("Presiona ENTER para continuar. . .");
    fflush(stdout);
    limpiar_buffer_STDIN();
    getchar();
#endif
}

// Clasifica los mensajes de error tanto para Windows como para UNIX/Linux, cuando se ingresan datos incorrectos
static void validar_errores_por_SO()
{
#if defined(_WIN32) || defined(_WIN64)
    limpiar_terminal();

    printf("Dato/s ingresado/s no válido/s, verificar dato/s\n");
    pausar_terminal();
    limpiar_terminal();
#elif __linux__
    limpiar_terminal();

    printf("Dato/s ingresado/s no válido/s, verificar dato/s\n");
    fflush(stdout);

    pausar_terminal();
    limpiar_terminal();
#endif
}