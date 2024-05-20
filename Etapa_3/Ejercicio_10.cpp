#include <iostream>
#include <filesystem>
#include <clocale>
#include <regex>
#include <fstream>
#include <cstring>
#include <string>

#if defined(__linux__) && !defined(__ANDROID__)

    #include <stdio_ext.h>

#endif

using namespace std;
using namespace filesystem;

struct Datos_Empleados
{
    char nombre[70];
    int numero_empleado;
    float sueldo;
};

static void archivo_creado(ofstream &, const int *);
static void leer_datos(fstream &, struct Datos_Empleados *, int &);
static void actualizar_sueldo(fstream &, struct Datos_Empleados *);

static void contar_empleados(fstream &, int &, struct Datos_Empleados *);
static void convertir_cadena_a_minuscula(string &);
static bool buscar_clave_existente(fstream &, const int *, struct Datos_Empleados *);

static void limpiar_buffer_STDIN();
static void limpiar_terminal();
static void pausar_terminal();
static void validar_errores_por_SO();


int main()
{
    path path_actual = current_path();
    string respuesta;
    struct Datos_Empleados datos = {"", 0, 0.0};

    int opcion, total_empleados = 0;
    const int maximo_empleados = 50;
    bool dato_invalido;

    #if defined(_WIN32) || defined(_WIN64)

        setlocale(LC_CTYPE, "es_MX");
        path_actual += "\\Empleados.dat";

    #elif defined(__linux__) && !defined(__ANDROID__)

        setlocale(LC_CTYPE, "es_MX.UTF-8");
        path_actual += "/Empleados.dat";

    #endif


    ifstream Archivos_IN(path_actual, ios::binary);

    if (Archivos_IN.is_open())
    {
        Archivos_IN.close();

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

        if (strcmp(respuesta.c_str(), "si") == 0)
        {
            ofstream Archivos_OUT(path_actual, ios::binary);

            archivo_creado(Archivos_OUT, &maximo_empleados);

            Archivos_OUT.close();
        }
    }
    else
    {
        ofstream Archivos_OUT(path_actual, ios::binary);

        archivo_creado(Archivos_OUT, &maximo_empleados);

        Archivos_OUT.close();
    }

    fstream Empleados(path_actual, ios::in | ios::out | ios::binary);

    do
    {
        do
        {
            limpiar_terminal();

            cout << "* * * * * * * MENU DE OPCIONES * * * * * * *\n\n";
            cout << "1. Lectura de datos" << endl;
            cout << "2. Actualizacion de sueldo (dado # de emplead@)" << endl;
            cout << "3. Salir" << endl;
            cout << "\nSelecciona una pcion: ";

            limpiar_buffer_STDIN();

            cin >> opcion;

            if ((dato_invalido = cin.fail()) || (opcion < 1 || opcion > 3))
            {
                cin.clear();
                validar_errores_por_SO();
            }
        } while (dato_invalido || (opcion < 1 || opcion > 3));

        contar_empleados(Empleados, total_empleados, &datos);

        switch (opcion)
        {
            case 1:

                if (total_empleados < 50)

                    leer_datos(Empleados, &datos, total_empleados);

                else

                    cout << "No puedes registrar mas emplead@s. . ." << endl;

                break;

            case 2:

                if (total_empleados == 0)

                    cout << "Necesita registrar primero a l@s emplead@s. . ." << endl;

                else

                    actualizar_sueldo(Empleados, &datos);

                break;

            case 3:

                Empleados.close();

                break;
        }

        if (opcion != 3)

            pausar_terminal();


    } while (opcion != 3);

    return EXIT_SUCCESS;
}

static void archivo_creado(ofstream &file, const int *max_employees)
{
    Datos_Empleados data = {"", 0, 0.0};
    int i;

    for ( i = 0; i < *max_employees; i++)

        file.write(reinterpret_cast<const char *>(&data), sizeof(Datos_Empleados));

    cout << "ARCHIVO CREADO EXITOSAMENTE! " << endl;

    pausar_terminal();
    limpiar_terminal();
}


static void leer_datos(fstream &file, struct Datos_Empleados *data, int &empleados)
{
    string respuesta;
    regex regex_expresion("^[A-Za-z ]+$");
    bool dato_invalido, clave_existente, nombre_valido;
    int clave;

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
            cin >> clave;

            if ((dato_invalido = cin.fail()) || (clave < 1 || clave > 50))
            {
                cin.clear();
                validar_errores_por_SO();
            }
            else
            {
                clave_existente = buscar_clave_existente(file, &clave, data);

                if (clave_existente)
                {
                    limpiar_terminal();
                    cout << "El numero de empleado ingresado ya existe en el sistema. . ." << endl;
                    pausar_terminal();
                }
            }
        } while (dato_invalido || clave_existente || (clave < 1 || clave > 50));

        data->numero_empleado = clave;

        do
        {
            limpiar_terminal();

            cout << "Nombre de emplead@: ";
            limpiar_buffer_STDIN();
            cin.getline(data->nombre, sizeof(data->nombre));

            if (!(nombre_valido = regex_match(data->nombre, regex_expresion)))

                validar_errores_por_SO();

        } while (!nombre_valido);

        do
        {
            limpiar_terminal();

            cout << "Sueldo: ";
            limpiar_buffer_STDIN();
            cin >> data->sueldo;

            if ((dato_invalido = cin.fail()) || data->sueldo < 0.0)
            {
                cin.clear();
                validar_errores_por_SO();
            }

        } while (dato_invalido || data->sueldo < 0.0);

        empleados++;

        file.clear();
        file.seekp((data->numero_empleado - 1) * sizeof(Datos_Empleados), ios::beg);
        file.write(reinterpret_cast<const char *>(data), sizeof(Datos_Empleados));

        if (empleados < 50)
        {
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

        }
        else
        {
            limpiar_terminal();
            cout << "Has alcanzado el limite maximo de registro de emplead@s. . ." << endl;
        }
    }

}

static void actualizar_sueldo(fstream &file, struct Datos_Empleados *data)
{
    string respuesta;
    bool clave_existente, dato_invalido;
    int clave;
    float sueldo;

    do
    {
        limpiar_terminal();

        cout << "Desea actualizar un sueldo? Si/No: ";
        limpiar_buffer_STDIN();
        getline(cin, respuesta, '\n');

        if (!respuesta.empty())
        {
            convertir_cadena_a_minuscula(respuesta);

            if (strcmp(respuesta.c_str(), "si") != 0 && strcmp(respuesta.c_str(), "no") != 0)

                validar_errores_por_SO();

        }
    } while ((strcmp(respuesta.c_str(), "si") != 0 && strcmp(respuesta.c_str(), "no") != 0) || respuesta.empty());

    if (strcmp(respuesta.c_str(), "si") == 0)
    {
        do
        {
            limpiar_terminal();

            cout << "Numero de emplead@: ";
            limpiar_buffer_STDIN();
            cin >> clave;

            if ((dato_invalido = cin.fail()) || (clave < 1 || clave > 50))
            {
                cin.clear();
                validar_errores_por_SO();
            }
            else
            {
                clave_existente = buscar_clave_existente(file, &clave, data);

                if (!clave_existente)
                {
                    limpiar_terminal();
                    cout << "El numero de empleado ingresado NO existe en el sistema. . ." << endl;
                    pausar_terminal();
                }
            }
        } while (dato_invalido || !clave_existente || (clave < 1 || clave > 50));

        do
        {
            limpiar_terminal();

            cout << "Sueldo nuevo: ";
            limpiar_buffer_STDIN();
            cin >> sueldo;

            if ((dato_invalido = cin.fail()) || sueldo < 0.0)
            {
                cin.clear();
                validar_errores_por_SO();
            }

        } while (dato_invalido || sueldo < 0.0);

        file.clear();

        file.seekp((clave - 1) * sizeof(Datos_Empleados) + offsetof(Datos_Empleados, sueldo), ios::beg);
        file.write(reinterpret_cast<const char *>(&sueldo), sizeof(sueldo));

        limpiar_terminal();

        cout << "SUELDO ACTUALIZADO CORRECTAMENTE !" << endl;
    }
}

static void contar_empleados(fstream &file, int &total_empleados, struct Datos_Empleados *data)
{
    file.clear();

    file.seekg(0, ios::beg);

    while (file.read(reinterpret_cast<char *>(data), sizeof(Datos_Empleados)))
    {
        if (data->numero_empleado != 0)

            total_empleados++;

    }

}

static bool buscar_clave_existente(fstream &file_employees, const int *clave, struct Datos_Empleados *data_employees)
{
    file_employees.clear();
    file_employees.seekg((*clave - 1) * sizeof(Datos_Empleados), ios::beg);
    file_employees.read(reinterpret_cast<char *>(data_employees), sizeof(Datos_Empleados));

    if (*clave == data_employees->numero_empleado)

        return true;

    return false;
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