/*  
    Elaborar un programa que para una compañia que tiene cuatro vendedores, que pueden
    ofrecer hasta 8 productos cada uno. Cada vendedor reporta el monto de venta que tuvo o no
    , para cada producto.

    Calcular el total de ventas por vendedor y guardarlo en un arreglo unidimensional
    Calcular el total de ventas por producto y guardarlo en un arreglo unidimensional

    Al final imprime en forma tabular lo siguiente:

    Cada columna representa un vendedor y en las filas los productos

    Imprimir en esa misma tabla los totales previamente calculados
    validar que la venta sea mayor o igual que cero
*/


#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int ventas[5][6], suma = 0, i, j;

    for ( i = 0; i < 4; i++)
    {
        for ( j = 0; j < 5; j++)
        {
            do
            {
                cout <<"Ingresa el numero de ventas del producto "<< j + 1 << " del vendedor: "<< i + 1 << ": ";
                cin >> ventas[i][j];
            } while (ventas[i][j] < 0);
        }
        
    }
    
    cout<< "\n\n";

    // Calculo suma de productos
    for ( i = 0; i < 4; i++)
    {
        suma = 0;

        for ( j = 0; j < 5; j++)
        
            suma += ventas[i][j];
        
        ventas[i][5] = suma;
    }

    // Calculo suma por vendedores

    for ( i = 0; i < 5; i++)
    {
        suma = 0;

        for ( j = 0; j < 4; j++)
        
            suma += ventas[j][i];
        
        ventas[4][i] = suma;
    }
    
    cout << "VENDEDOR 1:" << setw(22) << "VENDEDOR 2:" << setw(22) << "VENDEDOR 3:"<< setw(22) << "VENDEDOR 4:"<< setw(22) << "TOTAL:\n\n";
    for ( i = 0; i < 5; i++)
    {
        if (i == 4)
        {
            cout<< endl;
            cout << "TOTAL : ";

            // CORREGIR
            for ( j = 0; j < 5; i++)
            
                cout << ventas[i][j] << setw(10);
            
        }
        else
        {
            for ( j = 0; j < 6; j++)
            {
                if (j == 0)
                
                    cout<< ventas[i][j];
                
                else
                
                    cout<< ventas[i][j] << setw(18) ;
                
                
            }
        }
        

        cout << endl;
    }

    return EXIT_SUCCESS;
}