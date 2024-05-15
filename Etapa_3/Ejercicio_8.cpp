#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;
using namespace filesystem;

int main()
{
    int semestre, matricula;
    string registro, nombre;
    float promedio;

    ifstream Lectura_Alumnos("./Alumnos.txt");

    if (!Lectura_Alumnos)
    {
        cerr << "NO EXISTEN REGISTROS EN EL SISTEMA!" << endl;
        return EXIT_FAILURE;
    }
    else
    {
        while (getline(Lectura_Alumnos, registro))
        {
            // cout << registro << endl;
            istringstream ss(registro);
            // ss >> ws; // espacios en blanco
            getline(ss, nombre, '.'); // Leer el nombre hasta el siguiente tabulador
            ss >> matricula >> promedio >> semestre;

            cout << left << setw(25) << nombre << setw(10) << matricula << setw(10) << promedio << setw(10) << semestre << endl;
        }

        Lectura_Alumnos.close();
    }

    return EXIT_SUCCESS;
}