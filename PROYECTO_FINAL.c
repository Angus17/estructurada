#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <regex.h>
#include <stdbool.h>
#include <ctype.h>
#ifdef __linux__
    #include <stdio_ext.h>
#endif

struct Datos_Articulos
{
    int numero_articulo, numero_proveedor, punto_reorden; // Mayor a cero, proveedores a lo mucho 10
    char descripcion_articulo[100]; // Validar letras, numeros, espacios
    long int inventario; //Mayor o igual a cero
    double precio_compra, precio_venta;
};

struct Datos_Proveedores
{
    int numero_proveedor; //mayor a cero
    char nombre_proveedor[50], rfc[13]; // Letras, espacios; 13 caracteres
    char correo_electronico[30];// @ y punto despues
    int anio, mes, dia; //  >=1950, 1-12 inclusive
    char direccion_proveedor[200]; //letras, espacios, numeros
    double descuento, saldo_por_pagar; // Campo calculado
};

struct Datos_Clientes
{
    int numero_cliente; // Mayor a cero
    char nombre_cliente[50], rfc[13]; // Letras, espacios
    char correo_electronico[30];// @ y punto despues
    double descuento_cliente; // 0 - 1
    int anio, mes, dia; // 1950-2006 inclusive, 1-12 inclusive
    char direccion_cliente[200]; //letras, espacios, numeros
};

struct Datos_Empleados
{
    int numero_empleado; // 1000 - 10000
    char nombre_empleado[50]; // Letras, espacios
    char correo_electronico[30];// @ y punto despues
    int anio, mes, dia; // 1990 - actual, 
    char direccion_empleado[200]; //letras, espacios, numeros
};
//FUNCIONES

void validar_errores_por_SO();
void limpiar_buffer_STDIN();
void limpiar_terminal();
void pausar_terminal();

int main(void)
{
    FILE *file_articulos, *file_proveedor, *file_clientes, *file_empleados;
    struct Datos_Clientes clientes;
    struct Datos_Empleados empleados;
    struct Datos_Proveedores proveedores;
    struct Datos_Articulos articulos;
    int opcion;

    setlocale(LC_CTYPE, "es_MX.UTF-8");

    file_articulos =  fopen("Files_muebleria/articulos.dat", "rb+");
    file_clientes = fopen("Files_muebleria/clientes.dat", "rb+");
    file_empleados = fopen("Files_muebleria/empleados.dat", "rb+");
    file_proveedor = fopen("Files_muebleria/proveedores.dat", "rb+");

    if (file_articulos == NULL || 
        file_clientes == NULL || 
        file_empleados == NULL || 
        file_proveedor == NULL)
    
        puts("Ocurrió un error al abrir un fichero. . .");
    
    else
    {
        do
        {
            do
            {
                limpiar_terminal();

                puts("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
                printf("\n%45s\n\n", "MENÚ DE OPCIONES");
                puts("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
                puts("1) Articulos");
                puts("2) Clientes");
                puts("3) Empleados");
                puts("4) Proveedores");
                puts("5) Ventas");
                puts("6) Compras");
                puts("7) Control de inventario");
                puts("8) Reportes");
                puts("9) Salir");
                printf("%10s: ", "Opcion");

                limpiar_buffer_STDIN();

                scanf("%d", &opcion);

                if (opcion < 1 || opcion > 9)
                
                    validar_errores_por_SO();

            } while (opcion < 1 || opcion > 9);

            switch (opcion)
            {
                case 1:

                break;

                case 2:

                break;

                case 3:

                break;

                case 4:

                break;

                case 5:

                break;

                case 6:

                break;

                case 7:

                break;

                case 8:

                break;

                case 9:
                    fclose(file_clientes);
                    fclose(file_articulos);
                    fclose(file_empleados);
                    fclose(file_proveedor);
                break;
            }
            
        } while (opcion != 9);
    }
    

}

// Limpia buffer STDIN tanto para sistemas Windows como para UNIX/Linux
void limpiar_buffer_STDIN()
{
    #if defined(_WIN32) || defined(_WIN64)
        fflush(stdin);
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
        printf("Presiona ENTER para continuar. . .");
        fflush(stdout);
        limpiar_buffer_STDIN();
        getchar();
    #endif
}

// Clasifica los mensajes de error tanto para Windows como para UNIX/Linux, cuando se ingresan datos incorrectos
void validar_errores_por_SO()
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