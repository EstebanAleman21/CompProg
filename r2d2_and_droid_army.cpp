#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Estructura SparseTable para procesar rangos y obtener el máximo valor en subrangos
struct SparseTable
{
    vector<vector<int> > table; // Tabla de sparse para almacenar máximos por rangos
    vector<int> log2;           // Vector para almacenar los logaritmos en base 2 de los tamaños de subrangos

    // Función para inicializar la SparseTable a partir de un array
    void init(const vector<int> &arr)
    {
        int arraySize = arr.size();                                // Tamaño del array
        log2.resize(arraySize + 1);                                // Redimensionamos el vector de logaritmos
        table.assign(arraySize, vector<int>(__lg(arraySize) + 1)); // Asignamos espacio a la tabla sparse

        // Calculamos los logaritmos en base 2 para cada tamaño
        for (int i = 2; i <= arraySize; i++)
        {
            log2[i] = log2[i / 2] + 1;
        }

        // Inicializamos la tabla sparse en el nivel 0 con los valores originales del array
        for (int i = 0; i < arraySize; i++)
        {
            table[i][0] = arr[i];
        }

        // Llenamos la tabla sparse para cada potencia de 2
        for (int j = 1; (1 << j) <= arraySize; j++)
        {
            for (int i = 0; i + (1 << j) <= arraySize; i++)
            {
                // Calculamos el máximo para cada rango usando el valor anterior
                table[i][j] = max(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    // Función para consultar el máximo en un rango dado
    int query(int left, int right) const
    {
        int intervalLength = right - left + 1; // Longitud del rango a consultar
        int powerOfTwo = log2[intervalLength]; // Potencia de 2 más cercana a la longitud del rango
        // Retorna el máximo entre dos bloques que cubren el rango
        return max(table[left][powerOfTwo], table[right - (1 << powerOfTwo) + 1][powerOfTwo]);
    }
};

// Función que verifica si un subarreglo es válido, es decir, si la suma de los máximos en el rango está dentro del límite de disparos permitidos
bool isValidSubarray(int left, int right, const vector<SparseTable> &sparseTables, int detailTypes, int maxShots)
{
    int sumOfMaximums = 0; // Suma de los máximos en el rango
    for (int i = 0; i < detailTypes; i++)
    {
        // Suma los máximos de cada tipo de detalle (es decir, cada columna en las tablas sparse)
        sumOfMaximums += sparseTables[i].query(left, right);
    }
    // Verifica si la suma está dentro del límite de disparos permitidos
    return sumOfMaximums <= maxShots;
}

int main()
{
    int numDroids, detailTypes, maxShots;
    cin >> numDroids >> detailTypes >> maxShots; // Lectura del número de droides, tipos de detalles y disparos máximos permitidos

    // Matriz que almacena los detalles de cada droide
    vector<vector<int> > droidDetails(numDroids, vector<int>(detailTypes));
    for (int i = 0; i < numDroids; i++)
    {
        for (int j = 0; j < detailTypes; j++)
        {
            cin >> droidDetails[i][j]; // Leemos los detalles de cada droide
        }
    }

    // Inicializamos las tablas sparse para cada tipo de detalle (cada columna en la matriz de droides)
    vector<SparseTable> sparseTables(detailTypes);
    for (int j = 0; j < detailTypes; j++)
    {
        vector<int> column(numDroids); // Extraemos cada columna para construir la tabla sparse
        for (int i = 0; i < numDroids; i++)
        {
            column[i] = droidDetails[i][j];
        }
        sparseTables[j].init(column); // Inicializamos la tabla sparse para cada columna
    }

    // Variables para almacenar la longitud máxima de un subarreglo válido y los disparos óptimos
    int maxSubarrayLength = 0;
    vector<int> optimalShots(detailTypes, 0); // Disparos óptimos para cada tipo de detalle
    for (int left = 0, right = 0; right < numDroids; right++)
    {
        // Ajustamos el límite izquierdo hasta que el subarreglo sea válido
        while (left <= right && !isValidSubarray(left, right, sparseTables, detailTypes, maxShots))
        {
            left++;
        }
        // Si encontramos un subarreglo más largo, actualizamos la longitud máxima y los disparos óptimos
        if (right - left + 1 > maxSubarrayLength)
        {
            maxSubarrayLength = right - left + 1;
            for (int i = 0; i < detailTypes; i++)
            {
                optimalShots[i] = sparseTables[i].query(left, right); // Guardamos los máximos óptimos de cada tipo de detalle
            }
        }
    }

    // Imprimimos los disparos óptimos para cada tipo de detalle
    for (int i = 0; i < detailTypes; i++)
    {
        cout << optimalShots[i] << " ";
    }
    cout << endl;

    return 0;
}
