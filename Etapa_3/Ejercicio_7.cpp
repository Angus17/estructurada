/*

    Elabora un programa que para cada alumno lea su nombre,
    matricula, promedio y semestre, guardar cada registro en un
    archivo secuencial
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <string>
#include <cstring>
#ifdef __linux__
    #include <stdio_ext.h>
#endif

using namespace std;

static void leer_datos(string &, int &, float &, int &);
static bool existencia_registros(ifstream *);
static bool validar_cadenas(const string &);
static void convertir_cadena_a_minuscula(char *);

static void limpiar_buffer_STDIN();
static void limpiar_terminal();
static void pausar_terminal();
static void validar_errores_por_SO();

int main()
{
    int matricula, semestre;
    string nombre;
    float promedio;



    leer_datos(nombre, matricula, promedio, semestre);

    limpiar_terminal();
    cout << "Programa finalizado exitosamente!" << endl;

    return EXIT_SUCCESS;
}

static void leer_datos(string &name, int &id, float &average, int &semester)
{
    bool dato_invalido;
    string registro_leido;

    try
    {
        bool cadena_valida, existencia_registro;
        char salida[3];

        do
        {
            limpiar_terminal();

            cout << "Deseas ingresar datos? Si/No: ";
            limpiar_buffer_STDIN();
            cin.getline(salida, sizeof(salida), '\n');

            convertir_cadena_a_minuscula(salida);

            if (strlen(salida) == 0 || (strcmp(salida, "si") != 0 && strcmp(salida, "no") != 0))

                validar_errores_por_SO();

        } while (strlen(salida) == 0 || (strcmp(salida, "si") != 0 && strcmp(salida, "no") != 0));

        if (strcmp(salida, "si") == 0)
        {
            ifstream Lectura_Alumnos("./Alumnos.txt");

            if (!Lectura_Alumnos)

                existencia_registro = false;

            else
            {
                existencia_registro = existencia_registros(&Lectura_Alumnos);
                Lectura_Alumnos.close();
            }

            ofstream Registro_Alumnos("./Alumnos.txt", ios::app);

            if (!Registro_Alumnos)
            {
                cerr << "ERROR DE ARCHIVOS, INTENTE MAS TARDE. . ." << endl;

                exit(EXIT_FAILURE);
            }
            else
            {
                if (existencia_registro)
                {
                    Registro_Alumnos.seekp(0, ios::end);
                    Registro_Alumnos << endl;
                }

                while (strcmp(salida, "si") == 0)
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

                    name += ".";

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

                        if ((dato_invalido = cin.fail()) || (semester < 0 || semester > 10))
                        {
                            cin.clear();
                            validar_errores_por_SO();
                        }
                    } while (dato_invalido || (semester < 0 || semester > 10));

                    Registro_Alumnos << name << setw(name.length() + 10) << id << setw(10) << fixed << setprecision(2) << average << setw(10) << semester;
                    Registro_Alumnos.flush();

                    do
                    {
                        limpiar_terminal();

                        cout << "Deseas ingresar mas datos? Si/No" << endl << ": ";
                        limpiar_buffer_STDIN();
                        cin.getline(salida, sizeof(salida), '\n');

                        convertir_cadena_a_minuscula(salida);

                        if (strlen(salida) == 0 || (strcmp(salida, "si") != 0 && strcmp(salida, "no") != 0))

                            validar_errores_por_SO();

                    } while (strlen(salida) == 0 || (strcmp(salida, "si") != 0 && strcmp(salida, "no") != 0));

                    if (strcmp(salida, "no") != 0)

                        Registro_Alumnos << endl;
                }

                Registro_Alumnos.close();
            }
        }
    }
    catch (const bad_alloc &e)
    {
        cerr << "ERROR DE MEMORIA" << endl;

        exit(EXIT_FAILURE);
    }

}

static bool existencia_registros(ifstream *data_file)
{
    string registro;

    data_file->seekg(0, ios::beg);

    getline(*data_file, registro);

    if (!registro.empty())

        return true;

    return false;
}

static bool validar_cadenas(const string &caracter)
{

    for (char caracter_obtenido : caracter)
    {
        if (!isalpha(caracter_obtenido) && caracter_obtenido != 32)

            return false;

    }

    return true;
}

static void convertir_cadena_a_minuscula(char *caracter)
{
    while (*caracter != '\0')
    {
        *caracter = tolower(*caracter);
        caracter++;
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