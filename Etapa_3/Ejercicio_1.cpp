#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    const int num_productos = 8, num_vendedores = 4;
    int i, j, suma = 0, ventas[num_vendedores + 1][num_productos + 1] = {0};

    for ( i = 0; i < num_vendedores; i++)
    {
        for ( j = 0; j < num_productos; j++)
        {
            do
            {
                cout << "Ingresa el numero de ventas del producto " << j + 1 << " del vendedor: " << i + 1 << ": ";
                cin >> ventas[i][j];
            } while (ventas[i][j] < 0);
        }
    }

    cout << "\n\n";

    // Calculo suma de ventas por vendedor
    for ( i = 0; i < num_vendedores; i++)
    {
        suma = 0;

        for ( j = 0; j < num_productos; j++)

            suma += ventas[i][j];

        ventas[i][num_productos] = suma; // Almacena la suma de ventas por producto en la última columna
    }

    // Calculo suma de ventas por producto
    for ( j = 0; j < num_productos; j++)
    {

        int suma = 0;

        for ( i = 0; i < num_vendedores; i++)

            suma += ventas[i][j];

        ventas[num_vendedores][j] = suma; // Almacena la suma de ventas por vendedor  en la última fila
    }

    // Calculo del total general
    for ( i = 0; i < num_vendedores; i++)

        suma += ventas[i][num_productos];

    ventas[num_vendedores][num_productos] = suma;

    // Imprimir toda la tabla de ventas
    cout << setw(12) << "Producto";

    for ( i = 0; i < num_vendedores; i++)

        cout << setw(12) << "Vendedor " << i + 1;

    cout << setw(12) << "Total\n";

    for ( j = 0; j <= num_productos; j++)
    {
        if (j < num_productos)

            cout << setw(12) << "Producto " << j + 1;

        else

            cout << setw(12) << "Total";


        for ( i = 0; i <= num_vendedores; i++)

            cout << setw(12) << ventas[i][j];

        cout << endl;
    }

    return EXIT_SUCCESS;
}
