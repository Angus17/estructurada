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


};

struct Datos_Clientes
{
    int numero_cliente; // Mayor a cero
    char nombre_cliente[50], rfc[13]; // Letras, espacios
    char correo_electronico[30];// @ y punto despues
    double descuento_cliente; // 0 - 1
    int anio, mes, dia; // 1950-2006 inclusive, 1-12 inclusive
    char direccion[100]; //letras, espacios, numeros
};

struct Datos_Empleados
{
    int numero_empleado; // 1000 - 10000
    char nombre_empleado[50]; // Letras, espacios
    

};

//FUNCIONES

int main(void)
{



}