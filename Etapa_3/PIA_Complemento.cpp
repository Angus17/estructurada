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
#include <iomanip>
#include <string>
#include <clocale>
#include <cstring>
#include <new>
#include <regex>
#include <cctype>
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
    char descripcion[200];
    int punto_reorden, precio_unitario;
};

struct File_Objects
{
    ifstream Archivos_IN;
    ofstream Archivos_OUT;
};

static void crear_archivo(ofstream &, const int *);
static void leer_datos(struct File_Objects &, path *, struct Datos_Articulos *, int &);
/* static void vender_productos(struct File_Objects &, path *, struct Datos_Articulos &);
static void actualizar_informaciones(); */
static void listar_productos(ifstream &, path *, struct Datos_Articulos &);
static void refrescar_contador(ifstream &, path *, struct Datos_Articulos &, int &);

static bool buscar_clave_existente(ifstream &, const int *, struct Datos_Articulos *);
// static bool verificar_cantidad(ifstream &, const int *, const int *, struct Datos_Articulos &);
static bool productos_resurtir(ifstream &, path *, struct Datos_Articulos &);

static void convertir_cadena_a_minuscula(string &);

static void validar_errores_por_SO();
static void limpiar_buffer_STDIN();
static void limpiar_terminal();
static void pausar_terminal();

int main()
{
    try
    {
        path path_actual = current_path();
        string respuesta;
        char opcion;
        int *contador_productos = new int;
        const int maximo_articulos = 100;
        Datos_Articulos datos;
        File_Objects files;

        setlocale(LC_CTYPE, "es_MX.UTF-8");

        #if defined(_WIN32) || defined(_WIN64)

            path_actual += "\\ventas.dat"

        #elif defined(__linux__) &&  !defined(__ANDROID__)

            path_actual += "/ventas.dat";

        #endif

        files.Archivos_IN.open(path_actual, ios::binary);
        files.Archivos_OUT.open(path_actual, ios::binary);

        if (files.Archivos_IN.is_open())
        {

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

                crear_archivo(files.Archivos_OUT, &maximo_articulos);

        }
        else
        {

            crear_archivo(files.Archivos_OUT, &maximo_articulos);

        }

        do
        {
            do
            {
                limpiar_terminal();

                cout << setw(20) <<"* * * * * * * * * * * * * MENU DE OPCIONES * * * * * * * * * * * * * * *\n\n";
                cout << setw(39) <<"a) Captura de datos" << endl;
                cout << setw(41) << "b) Venta de productos" << endl;
                cout << setw(54) << "c) Listado de productos a resurtir" << endl;
                cout << setw(57) << "d) Actualizar existencia de productos" << endl;
                cout << setw(56) << "e) Actualizar el precio de productos" << endl;
                cout << setw(73) << "f) Desplegar informacion de productos (dada la clave)" << endl;
                cout << setw(30) << "g) Salir\n\n";
                cout << setw(20) <<"* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n";

                limpiar_buffer_STDIN();

                cout << setw(46) << "Selecciona una opcion: ";
                cin.get(opcion);

                opcion = tolower(opcion);

                if (opcion < 'a' || opcion > 'g')

                    validar_errores_por_SO();

            } while (opcion < 'a' || opcion > 'g');

            limpiar_terminal();
            refrescar_contador(files.Archivos_IN, &path_actual, datos, *contador_productos);

            switch (opcion)
            {
                case 'a':

                    if (*contador_productos < maximo_articulos)

                        leer_datos(files, &path_actual, &datos, *contador_productos);

                    else

                        cout << "No puedes agregar más productos" << endl;

                    break;

                case 'b':

                    if (*contador_productos == 0)

                        cout << "No hay productos para vender. . ." << endl;

                    else

                        // vender_productos(files, &path_actual, datos);

                    break;

                case 'c':
                    
                    if (productos_resurtir(files.Archivos_IN, &path_actual, datos))
                    {
                        listar_productos(files.Archivos_IN, &path_actual, datos);
                    }
                    else
                    {
                        cout << "No hay productos que deban resurtirse. . ." << endl;
                    }
                    
                    break;
                case 'd':
                    
                    break;
                case 'e':
                    
                    break;
                case 'f':
                    
                    break;
                case 'g':
                    delete contador_productos;
                    break;
            }

            if (opcion != 'g')

                pausar_terminal();

        } while (opcion != 'g');


        return EXIT_SUCCESS;
    }
    catch(const bad_alloc& e)
    {
        cerr << "ERROR DE ALOCAMIENTO DE MEMORIA: " << e.what() << endl;

        return EXIT_FAILURE;
    }

}

static void crear_archivo( ofstream &file_object, const int *max_articles)
{
    int i = 0;
    Datos_Articulos data = {0, 0, "", 0, 0};

    for ( i = 0; i < *max_articles; i++)

        file_object.write(reinterpret_cast<const char *>(&data), sizeof(Datos_Articulos));

    cout << "ARCHIVO CREADO EXITOSAMENTE! " << endl;

    pausar_terminal();
    limpiar_terminal();
}

static void leer_datos(struct File_Objects &file, path *path_dir, struct Datos_Articulos *data, int &total_productos)
{
    string respuesta;
    regex regex_expresion("^[A-Za-z ]+$");
    bool dato_invalido, clave_existente, descripcion_valida;
    int clave_producto;

    do
    {
        limpiar_terminal();

        cout << "Desea capturar datos de articulos? Si/No: " ;
        limpiar_buffer_STDIN();
        getline(cin, respuesta, '\n');

        convertir_cadena_a_minuscula(respuesta);

        if (respuesta.empty() || (strcmp(respuesta.c_str(), "si") != 0 && strcmp(respuesta.c_str(), "no") != 0))

            validar_errores_por_SO();

    } while (respuesta.empty() || (strcmp(respuesta.c_str(), "si") != 0 && strcmp(respuesta.c_str(), "no") != 0));

    if (strcmp(respuesta.c_str(), "si") == 0)
    {

        while (strcmp(respuesta.c_str(), "si") == 0 && total_productos < 100)
        {
            do
            {
                limpiar_terminal();

                cout << "Ingresa la clave del producto: " ;
                limpiar_buffer_STDIN();
                cin >> clave_producto ;

                if ((dato_invalido = cin.fail()) || clave_producto < 1)
                {
                    cin.clear();
                    validar_errores_por_SO();
                }
                else
                {
                    clave_existente = buscar_clave_existente(file.Archivos_IN, &clave_producto, data);

                    if (clave_existente)
                    {
                        limpiar_terminal();
                        cout << "La clave ya está registrada en el sistema. . ." << endl;
                        pausar_terminal();
                    }
                }

            } while (dato_invalido || clave_existente || clave_producto < 1);

            data->clave = clave_producto;

            do
            {
                limpiar_terminal();

                cout << "Descripcion del producto: ";
                limpiar_buffer_STDIN();
                cin.getline(data->descripcion, sizeof(data->descripcion) - 1);

                if (!(descripcion_valida = regex_match(data->descripcion, regex_expresion)))

                    validar_errores_por_SO();

            } while (!descripcion_valida);

            strcat(data->descripcion, "."); // Delimitador de string

            do
            {
                limpiar_terminal();

                cout << "Cuantos hay en existencia?: " ;
                limpiar_buffer_STDIN();
                cin >> data->existencia ;

                if ((dato_invalido = cin.fail()) || data->existencia < 1)
                {
                    cin.clear();
                    validar_errores_por_SO();
                }

            } while (dato_invalido || data->existencia < 1);

            do
            {
                limpiar_terminal();

                cout << "Punto de reorden: " ;
                limpiar_buffer_STDIN();
                cin >> data->punto_reorden;

                if ((dato_invalido = cin.fail()) || data->punto_reorden < 0)
                {
                    cin.clear();
                    validar_errores_por_SO();
                }

            } while (dato_invalido || data->punto_reorden < 0);

            do
            {
                limpiar_terminal();

                cout << "Precio: " ;
                limpiar_buffer_STDIN();
                cin >> data->precio_unitario;

                if ((dato_invalido = cin.fail()) || data->precio_unitario < 0)
                {
                    cin.clear();
                    validar_errores_por_SO();
                }

            } while (dato_invalido || data->precio_unitario < 0);

            file.Archivos_OUT.seekp((data->clave - 1) * sizeof(Datos_Articulos) + offsetof(Datos_Articulos, clave), file.Archivos_OUT.beg);
            file.Archivos_OUT.write(reinterpret_cast<const char *>(&data->clave), sizeof(int));

            file.Archivos_OUT.seekp((data->clave - 1) * sizeof(Datos_Articulos) + offsetof(Datos_Articulos, existencia), file.Archivos_OUT.beg);
            file.Archivos_OUT.write(reinterpret_cast<const char *>(&data->existencia), sizeof(int));

            file.Archivos_OUT.seekp((data->clave - 1) * sizeof(Datos_Articulos) + offsetof(Datos_Articulos, descripcion), file.Archivos_OUT.beg);
            file.Archivos_OUT.write(reinterpret_cast<const char *>(&data->descripcion), sizeof(data->descripcion));

            file.Archivos_OUT.seekp((data->clave - 1) * sizeof(Datos_Articulos) + offsetof(Datos_Articulos, punto_reorden), file.Archivos_OUT.beg);
            file.Archivos_OUT.write(reinterpret_cast<const char *>(&data->punto_reorden), sizeof(int));

            file.Archivos_OUT.seekp((data->clave - 1) * sizeof(Datos_Articulos) + offsetof(Datos_Articulos, precio_unitario), file.Archivos_OUT.beg);
            file.Archivos_OUT.write(reinterpret_cast<const char *>(&data->precio_unitario), sizeof(int));

            total_productos++;

            if (total_productos < 100)
            {
                do
                {
                    limpiar_terminal();

                    cout << "Desea capturar más datos de artículos? Si/No: " ;
                    limpiar_buffer_STDIN();
                    getline(cin, respuesta, '\n');

                    convertir_cadena_a_minuscula(respuesta);

                    if (respuesta.empty() || (strcmp(respuesta.c_str(), "si") != 0 && strcmp(respuesta.c_str(), "no") != 0))

                        validar_errores_por_SO();

                } while (respuesta.empty() || (strcmp(respuesta.c_str(), "si") != 0 && strcmp(respuesta.c_str(), "no") != 0));
            }
            else
            {
                limpiar_terminal();
                cout << "NO HAY ESPACIO PARA MAS PRODUCTOS. . ." << endl;
                pausar_terminal();
            }
        }

        file.Archivos_OUT.close();
        file.Archivos_IN.close();
    
    }

}

// static void vender_productos(struct File_Objects &file, path *path_dir, struct Datos_Articulos &data)
// {
//     string respuesta;
//     bool clave_existente, dato_invalido, cantidad_existente;
//     int clave, cantidad;

//     do
//     {
//         limpiar_terminal();

//         cout << "Desea realizar una venta? Si/No: " ;
//         limpiar_buffer_STDIN();
//         getline(cin, respuesta, '\n');

//         convertir_cadena_a_minuscula(respuesta);

//         if (respuesta.empty() || (strcmp(respuesta.c_str(), "si") != 0 && strcmp(respuesta.c_str(), "no") != 0))

//             validar_errores_por_SO();

//     } while (respuesta.empty() || (strcmp(respuesta.c_str(), "si") != 0 && strcmp(respuesta.c_str(), "no") != 0));

//     if (strcmp(respuesta.c_str(), "si") == 0)
//     {
//         file.open(*path_dir, ios::in | ios::out | ios::binary);

//         if (!file.is_open())

//             cerr << "ERROR CON LA LECTURA DEL FICHERO. . ." << endl;

//         else
//         {
//             while (strcmp(respuesta.c_str(), "si") == 0)
//             {
//                 do
//                 {
//                     limpiar_terminal();
//                     cout << "Ingresa la clave del producto: " ;
//                     limpiar_buffer_STDIN();
//                     cin >> clave ;

//                     if ((dato_invalido = cin.fail()) || clave < 1)
//                     {
//                         cin.clear();
//                         validar_errores_por_SO();
//                     }
//                     else
//                     {
//                         clave_existente = buscar_clave_existente(file, &clave, data);

//                         if (!clave_existente)
//                         {
//                             limpiar_terminal();
//                             cout << "La clave ya está registrada en el sistema. . ." << endl;
//                             pausar_terminal();
//                         }
//                     }

//                 } while (dato_invalido || !clave_existente || data.clave < 1);

//                 do
//                 {
//                     limpiar_terminal();

//                     cout << "Ingresa la cantidad a vender: " ;
//                     limpiar_buffer_STDIN();
//                     cin >> cantidad ;

//                     if ((dato_invalido = cin.fail()) || cantidad < 1)
//                     {
//                         cin.clear();
//                         validar_errores_por_SO();
//                     }
//                     else
//                     {
//                         cantidad_existente = verificar_cantidad(file, &clave, &cantidad, data);

//                         if (!cantidad_existente)
//                         {
//                             limpiar_terminal();
//                             cout << "No manejamos la cantidad que ingresó. . ." << endl;
//                             pausar_terminal();
//                         }
//                     }

//                 } while (dato_invalido || !cantidad_existente || data.clave < 1);

//                 file.clear();
//                 file.seekg((clave - 1) * sizeof(Datos_Articulos), ios::beg);
//                 file.read(reinterpret_cast<char *>(&data), sizeof(Datos_Articulos));

//                 cout << "\nPrecio total: $" << data.precio_unitario * cantidad << endl;

//                 data.existencia -= cantidad;

//                 file.clear();
//                 file.seekp((clave - 1) * sizeof(Datos_Articulos) + offsetof(Datos_Articulos, existencia), ios::beg);
//                 file.write(reinterpret_cast<char *>(&data.existencia), sizeof(int));

//                 do
//                 {
//                     limpiar_terminal();

//                     cout << "Desea realizar otra venta? Si/No: " ;
//                     limpiar_buffer_STDIN();
//                     getline(cin, respuesta, '\n');

//                     convertir_cadena_a_minuscula(respuesta);

//                     if (respuesta.empty() || (strcmp(respuesta.c_str(), "si") != 0 && strcmp(respuesta.c_str(), "no") != 0))

//                         validar_errores_por_SO();

//                 } while (respuesta.empty() || (strcmp(respuesta.c_str(), "si") != 0 && strcmp(respuesta.c_str(), "no") != 0));
//             }
//         }
//     }
// }

static void listar_productos(ifstream &file, path *dir, struct Datos_Articulos &data)
{
    file.open(*dir, ios::in | ios::binary);

    if (!file.is_open())

        cerr << "OCURRIÓ UN ERROR DE FICHERO. . ." << endl;

    else
    {
        file.clear();
        file.seekg(0, ios::beg);

        cout << setw(20) << "CLAVE" << setw(20) << "EXISTENCIA" << setw(25) << "DESCRIPCION" << setw(30) << "PUNTO_REORDEN" << setw(10) << "$ UNITARIO";
        
        while (file.read(reinterpret_cast<char *>(&data), sizeof(Datos_Articulos)))
        {
            if (data.existencia <= data.punto_reorden && data.clave != 0)
            {
                cout << setw(20) << data.clave
                << setw(20) << data.existencia
                << setw(25) << data.descripcion
                << setw(30) << data.punto_reorden
                << setw(10) << fixed << setprecision(2) << data.precio_unitario;
            }
        }

        file.close();
    }
}

static void refrescar_contador(ifstream &file, path *path_dir, struct Datos_Articulos &data, int &total)
{
    file.clear();
    file.seekg(0, ios::beg);

    while (file.read(reinterpret_cast<char *>(&data), sizeof(Datos_Articulos)))
    {
        if (data.clave != 0)

            total++;

    }
}

static bool buscar_clave_existente(ifstream &file_articles, const int *clave, struct Datos_Articulos *data_articles)
{
    file_articles.clear();
    file_articles.seekg((*clave - 1) * sizeof(Datos_Articulos), file_articles.beg);
    

    if (*clave == data_articles->clave)

        return true;

    return false;
}

static bool verificar_cantidad(ifstream &file_articles, const int *id, const int *amount, struct Datos_Articulos &data_articles)
{
    file_articles.clear();
    file_articles.seekg((*(id) - 1) * sizeof(Datos_Articulos), ios::beg);
    file_articles.read(reinterpret_cast<char *>(&data_articles), sizeof(Datos_Articulos));

    if (*amount >= data_articles.existencia)

        return true;

    return false;
}

static bool productos_resurtir(ifstream &file, path *dir, struct Datos_Articulos &data)
{
    file.open(*dir, ios::in | ios::binary);

    if (!file.is_open())
    {
        cerr << "OCURRIÓ UN ERROR DE FICHERO. . ." << endl;
        return false;
    }

    file.clear();
    file.seekg(0, ios::beg);

    while (file.read(reinterpret_cast<char *>(&data), sizeof(Datos_Articulos)))
    {
        if (data.existencia <= data.punto_reorden && data.clave != 0)
        {
            file.close();
            return true;
        }
    }

    file.close();
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
    rewind(stdin);
#elif defined(__linux__) && !defined(__ANDROID__)
    __fpurge(stdin);
#endif
}

// Limpia terminal tanto para sistemas Windows como para UNIX/Linux
static void limpiar_terminal()
{
#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#elif defined(__linux__) && !defined(__ANDROID__)
    system("clear");
#endif
}

// Pausa la terminal tanto para sistemas Windows como para UNIX/Linux
static void pausar_terminal()
{
#if defined(_WIN32) || defined(_WIN64)
    system("pause");
#elif defined(__linux__) && !defined(__ANDROID__)
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