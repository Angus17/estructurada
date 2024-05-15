/*
    Elabora un programa que para cada alumno lea su nombre, matricula, promedio y semestre.

    Validar que a matricula sea mayor a cero, el nombre contenga solo letras y espacios, el promedio
    entre 0 y 100. El semestre este entre 1 y 9.

    Se guardara en archivo secuencial

    1- Lectura de datos
    2- Listado de alumnos con promedio mayor o igual a 70. Desde el archivo
    3- Listado de alumnos del semestre indicado por el usuario. Desde el archivo
    4- Salir
*/

#include <iostream>
#include <filesystem>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstring>
#if defined(__linux__)
    #include <stdio_ext.h>
#endif

using namespace std;
using namespace filesystem;

static void leer_datos(ifstream &, ofstream &, const string *);
static void ver_promedios_mayores(ifstream &, const string *);
static void ver_alumnos_semestre(ifstream &, const string *);

static bool busqueda_promedios_mayores(ifstream &);
static bool busqueda_semestre_indicado(ifstream &, const int &);
static bool existencia_registros(ifstream &, const string *);
static bool validar_cadenas(const string &);
static void convertir_cadena_a_minuscula(string &);

static void limpiar_buffer_STDIN();
static void limpiar_terminal();
static void pausar_terminal();
static void validar_errores_por_SO();

int main()
{
    bool opcion_invalida, datos_leidos = false;
    string path = current_path();
    int opcion;

    path += "/Datos_Alumnos.txt";

    ifstream Existencias(path);

    if (Existencias)

        Existencias.close();

    ofstream Registros(path, ios::app);
    if (!Registros.is_open())
    {
        cerr << "ERROR DE ARCHIVOS, INTENTE MAS TARDE. . ." << endl;

        return EXIT_FAILURE;
    }
    else

        Registros.close();

    do
    {
        do
        {
            limpiar_terminal();

            cout << "* * * * * * * * * * * * MENU DE OPCIONES: * * * * * * * * * * * *\n"<< endl;
            cout << "1. Leer Datos" << endl;
            cout << "2. Alumnos promedio >= 70" << endl;
            cout << "3. Alumno de semestre indicado" << endl;
            cout << "4. Salir" << endl;
            cout << "Selecciona una opcion: " ;
            limpiar_buffer_STDIN();
            cin >> opcion;

            if ((opcion_invalida = cin.fail()) || (opcion < 1 || opcion > 4))
            {
                cin.clear();
                validar_errores_por_SO();
            }

        } while (opcion_invalida || (opcion < 1 || opcion > 4));

        limpiar_terminal();

        switch (opcion)
        {
            case 1:

                leer_datos(Existencias, Registros, &path);
                datos_leidos = true;

                break;

            case 2:

                datos_leidos = existencia_registros(Existencias, &path);

                if (!datos_leidos)

                    cout << "Aun no hay datos en el sistema" << endl;

                else

                    ver_promedios_mayores(Existencias, &path);

                break;
            case 3:

                datos_leidos = existencia_registros(Existencias, &path);

                if (!datos_leidos)

                    cout << "Aun no hay datos en el sistema" << endl;

                else

                    ver_alumnos_semestre(Existencias, &path);

                break;
        }

        if (opcion != 4)

            pausar_terminal();

    } while (opcion != 4);

    return EXIT_SUCCESS;
}

static void leer_datos(ifstream &Lectura_Alumnos, ofstream &Registro_Alumnos, const string *dir)
{
    string respuesta, name;
    bool registros_existentes, cadena_valida, dato_invalido;
    int id, average, semester;

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

    if (strcmp(respuesta.c_str(), "si") == 0)
    {
        Lectura_Alumnos.open(*dir);

        if (!Lectura_Alumnos.is_open())

            registros_existentes = false;

        else

            registros_existentes = existencia_registros(Lectura_Alumnos, dir);

        Registro_Alumnos.open(*dir, ios::app);

        if (!Registro_Alumnos.is_open())
        {
            cerr << "ERROR DE ARCHIVOS, INTENTE MAS TARDE" << endl;
            exit(EXIT_FAILURE);
        }

        if (registros_existentes)
        {
            Registro_Alumnos.seekp(0, ios::end);
            Registro_Alumnos << endl;
            Registro_Alumnos.flush();
        }

        while (strcmp(respuesta.c_str(), "si") == 0)
        {
            do
            {
                limpiar_terminal();

                cout << "Ingresa el nombre: ";
                limpiar_buffer_STDIN();
                getline(cin, name, '\n');

                if (!name.empty())

                    cadena_valida = validar_cadenas(name);

            } while (!cadena_valida || name.empty());

            name += "."; // Delimitador de cadena

            do
            {
                limpiar_terminal();

                cout << "Digita la matricula: ";
                limpiar_buffer_STDIN();
                cin >> id;

                if ((dato_invalido = cin.fail()) || id <= 0)
                {
                    cin.clear();
                    validar_errores_por_SO();
                }

            } while (dato_invalido || id <= 0);

            do
            {
                limpiar_terminal();

                cout << "Su promedio: " ;
                limpiar_buffer_STDIN();
                cin >> average;

                if ((dato_invalido = cin.fail()) || (average < 0.0f || average > 100.0f))
                {
                    cin.clear();
                    validar_errores_por_SO();
                }

            } while (dato_invalido || (average < 0.0f || average > 100.0f));

            do
            {
                limpiar_terminal();

                cout << "Semestre: " ;
                limpiar_buffer_STDIN();
                cin >> semester;

                if ((dato_invalido = cin.fail()) || (semester < 1 || semester > 9))
                {
                    cin.clear();
                    validar_errores_por_SO();
                }
            } while (dato_invalido || (semester < 1 || semester > 9));

            Registro_Alumnos << name << setw(name.length() + 10) << id << setw(10) << fixed << setprecision(2) << average << setw(10) << semester;
            Registro_Alumnos.flush();

            do
            {
                limpiar_terminal();

                cout << "Deseas ingresar mas datos? Si/No: ";
                limpiar_buffer_STDIN();
                getline(cin, respuesta, '\n');

                convertir_cadena_a_minuscula(respuesta);

                if (!respuesta.empty())
                {
                    convertir_cadena_a_minuscula(respuesta);

                    if (strcmp(respuesta.c_str(), "si") != 0 && strcmp(respuesta.c_str(), "no") != 0)

                        validar_errores_por_SO();

                }

            } while ((strcmp(respuesta.c_str(), "si") != 0 && strcmp(respuesta.c_str(), "no") != 0) || respuesta.empty());

            if (strcmp(respuesta.c_str(), "no") != 0)

                Registro_Alumnos << endl;
        }

        Registro_Alumnos.close();
    }
}

static void ver_promedios_mayores(ifstream &Lectura_Alumnos, const string *dir)
{
    string registro, name;
    int id, average, semester;

    Lectura_Alumnos.open(*dir);

    if (!Lectura_Alumnos.is_open())

        cerr << "ERROR DE ARCHIVOS DE LECTURA, INTENTE MAS TARDE. . ." << endl;

    else if (busqueda_promedios_mayores(Lectura_Alumnos))
        {
            Lectura_Alumnos.clear();
            Lectura_Alumnos.seekg(0, ios::beg);

            cout <<  "NOMBRE:" << setw(35) << "MATRICULA:" << setw(25) << "PROMEDIO:" << setw(25) << "SEMESTRE:"<< endl << endl;
            while (getline(Lectura_Alumnos, registro))
            {
                istringstream ss(registro);
                getline(ss, name, '.'); // Leer el nombre hasta el delimitador '.'
                ss >> id >> average >> semester;

                if (average >= 70)

                    cout << name << setw(name.length()) << id << setw(20) << average << setw(25) << semester << endl;

            }

            Lectura_Alumnos.close();
        }
        else

            cout << "NO EXISTEN ALUMNOS CON PROMEDIOS MAYORES, EN EL SISTEMA. . ." << endl;

}

static void ver_alumnos_semestre(ifstream &Lectura_Alumnos, const string *dir)
{
    string registro, name;
    bool dato_invalido;
    int id, average, semester, semestre_ingresado;

    Lectura_Alumnos.open(*dir);

    if (!Lectura_Alumnos.is_open())

        cerr << "ERROR DE ARCHIVOS DE LECTURA, INTENTE MAS TARDE. . ." << endl;

    else
    {
        do
        {
            limpiar_terminal();

            cout << "Semestre a buscar: " ;
            limpiar_buffer_STDIN();
            cin >> semestre_ingresado;

            if ((dato_invalido = cin.fail()) || (semestre_ingresado < 1 || semestre_ingresado > 9))
            {
                cin.clear();
                validar_errores_por_SO();
            }
        } while (dato_invalido || (semestre_ingresado < 1 || semestre_ingresado > 9));

        limpiar_terminal();

        if (busqueda_semestre_indicado(Lectura_Alumnos, semestre_ingresado))
        {
            Lectura_Alumnos.clear();
            Lectura_Alumnos.seekg(0, ios::beg);

            limpiar_terminal();

            cout << "ALUMNOS ENCONTRADOS:" << endl << endl;

            cout <<  "NOMBRE:" << setw(35) << "MATRICULA:" << setw(25) << "PROMEDIO:" << setw(25) << "SEMESTRE:"<< endl << endl;

            while (getline(Lectura_Alumnos, registro))
            {
                istringstream ss(registro);
                getline(ss, name, '.'); // Leer el nombre hasta el delimitador '.'
                ss >> id >> average >> semester;

                if (semestre_ingresado == semester)

                    cout << name << setw(name.length()) << id << setw(20) << average << setw(25) << semester << endl;

            }

            Lectura_Alumnos.close();
        }
        else

            cout << "NO EXISTEN ALUMNOS EN EL SEMESTRE INDICADO. . ." << endl;

    }
}

static bool busqueda_promedios_mayores(ifstream &Lectura)
{
    string registro, name;
    int id, average, semester;

    Lectura.clear();
    Lectura.seekg(0, ios::beg);

    while (getline(Lectura, registro))
    {
        istringstream ss(registro);
        getline(ss, name, '.'); // Leer el nombre hasta el delimitador '.'
        ss >> id >> average >> semester;

        if (average >= 70)

            return true;
    }

    return false;
}

static bool busqueda_semestre_indicado(ifstream &Lectura, const int &semestre)
{
    string registro, name;
    int id, average, semester;

    Lectura.clear();
    Lectura.seekg(0, ios::beg);

    while (getline(Lectura, registro))
    {
        istringstream ss(registro);
        getline(ss, name, '.'); // Leer el nombre hasta el delimitador '.'
        ss >> id >> average >> semester;

        if (semester == semestre)

            return true;
    }

    return false;

}

static bool existencia_registros(ifstream &data_file, const string *dir)
{
    string registro;

    data_file.open(*dir);

    if (data_file.is_open())
    {
        data_file.clear();
        data_file.seekg(0, ios::beg);

        getline(data_file, registro);

        if (!registro.empty())
        {
            data_file.close();
            return true;
        }
    }

    return false;
}

static bool validar_cadenas(const string &cadena)
{
    for (char caracter_obtenido : cadena)
    {
        if (!isalpha(caracter_obtenido) && caracter_obtenido != 32)

            return false;

    }

    return true;
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