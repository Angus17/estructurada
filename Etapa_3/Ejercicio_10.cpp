#include <iostream>
#include <filesystem>
#include <fstream>
#include <cstring>
#include <string>
#ifdef __linux__
    #include <stdio_ext.h>
#endif

using namespace std;
using namespace filesystem;

struct Datos_Empleados
{
    string nombre;
    int numero_empleado;
    float sueldo;
};

static void archivo_creado(fstream &, const string *, int &);
static bool existencia_registros(fstream &, struct Datos_Empleados *, const string *);
static void leer_datos(fstream &, struct Datos_Empleados *);

static void contar_empleados(fstream &, int &);
static bool clave_existente(fstream &, int &, int &);
static void convertir_cadena_a_minuscula(string &);

static void limpiar_buffer_STDIN();
static void limpiar_terminal();
static void pausar_terminal();
static void validar_errores_por_SO();


int main()
{
    string path = current_path();
    struct Datos_Empleados datos = {"", 0, 0.0};
    int opcion;
    bool dato_invalido;

    path += "Datos_Empleados.dat";

    fstream Empleados(path, ios::in | ios::out | ios::binary);

    if (!Empleados.is_open())
    {
        cerr << "ERROR DE ARCHIVOS, INTENTE MAS TARDE. . ." << endl;

        return EXIT_FAILURE;
    }

    Empleados.close();

    do
    {
        do
        {
            cout << "* * * * * * * MENU DE OPCIONES * * * * * * *" << endl;
            cout << "1. Archivo en blanco" << endl;
            cout << "2. Lectura de datos" << endl;
            cout << "3. Actualizacion de sueldo (dado # de emplead@)" << endl;
            cout << "4. Salir" << endl;
            cout << "Opcion: ";

            limpiar_buffer_STDIN();

            cin >> opcion;

            if ((dato_invalido = cin.fail()) || (opcion < 1 || opcion > 4))
            {
                cin.clear();
                validar_errores_por_SO();
            }
        } while (dato_invalido || (opcion < 1 || opcion > 4));

        switch (opcion)
        {
            case 1:

                archivo_creado(Empleados, &path);

                break;
            case 2:
                break;
            case 3:
                if (existencia_registros(Empleados, &datos, &path))
                {
                    
                }
                else

                    cout << "No hay datos en el sistema. . ." << endl;

                break;
        }
        if (opcion != 4)

            pausar_terminal();


    } while (opcion != 4);

    return EXIT_SUCCESS;
}

static void archivo_creado(fstream &file, const string *dir)
{
    int i;
    string respuesta;
    bool registros;
    struct Datos_Empleados data = {"", 0, 0.0};

    file.open(*dir, ios::in | ios::out | ios::binary);

    if (!file.is_open())

        cerr << "ERROR DE ARCHIVO, INTENTE MAS TARDE. . ." << endl;

    else if ((registros = existencia_registros(file, &data, dir)))
        {
            do
            {
                limpiar_terminal();

                cout << "Desea recrear el espacio de nuevo? Si/No: ";
                limpiar_buffer_STDIN();
                getline(cin, respuesta, '\n');

                if (!respuesta.empty())
                {
                    convertir_cadena_a_minuscula(respuesta);

                    if (strcmp(respuesta.c_str(), "si") != 0 && strcmp(respuesta.c_str(), "no") != 0)

                        validar_errores_por_SO();

                }
            } while ((strcmp(respuesta.c_str(), "si") != 0 && strcmp(respuesta.c_str(), "no") != 0) || respuesta.empty());
        }

    if (!registros || strcmp(respuesta.c_str(), "si") == 0)
    {
        file.clear();
        file.seekp(0 , ios::beg);

        for ( i = 0; i < 50; i++)

            file.write(reinterpret_cast<const char *>(&data), sizeof(data));

        cout << "ENTORNO CREADO EXITOSAMENTE!" << endl;
    }
}

static void leer_datos(fstream &file, struct Datos_Empleados *data, int &empleados)
{
    string respuesta;
    bool dato_invalido;

    do
    {
        limpiar_terminal();

        cout << "Desea ingresar datos? Si/No: ";
        limpiar_buffer_STDIN();
        getline(cin, respuesta, '\n');

        if (!respuesta.empty())
        {
            convertir_cadena_a_minuscula(respuesta);

            if (strcmp(respuesta.c_str(), "si") != 0 && strcmp(respuesta.c_str(), "no") != 0)

                validar_errores_por_SO();

        }
    } while ((strcmp(respuesta.c_str(), "si") != 0 && strcmp(respuesta.c_str(), "no") != 0) || respuesta.empty());

    while (strcmp(respuesta.c_str(), "si") == 0 && empleados < 50)
    {
        do
        {
            limpiar_terminal();

            cout << "Numero de emplead@: ";
            limpiar_buffer_STDIN();
            cin >> data->numero_empleado;

            if ((dato_invalido = cin.fail()) || (data->numero_empleado < 1 || data->numero_empleado > 50))
            {
                cin.clear();
                validar_errores_por_SO();
            }
        } while (dato_invalido || (data->numero_empleado < 1 || data->numero_empleado > 50));

        empleados++;
    }

}

static bool existencia_registros(fstream &file, struct Datos_Empleados *data, const string *dir)
{
    file.open(*dir, ios::in | ios::binary);

    if (!file.is_open())

        cerr << "ERROR DE ARCHIVO, INTENTE MAS TARDE. . ." << endl;

    else
    {

        file.clear();
        file.seekg(0 , ios::beg);

        while (file.read(reinterpret_cast<char *>(data), sizeof(*data)))
        {
            if (data->numero_empleado != 0)
            {
                return true;
            }
        }

        return false;
    }

}

static void contar_empleados(fstream &file, int &total_empleados)
{
    struct Datos_Empleados data;



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
    rewind(stdin)
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