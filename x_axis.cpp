#include <iostream>
#include <algorithm> // Para usar la función std::sort

using namespace std;

int main()
{
    int t; // Número de casos de prueba
    cin >> t;

    while (t--)
    {
        int x1, x2, x3;
        cin >> x1 >> x2 >> x3;

        // Ordenamos los tres puntos para que x1 <= x2 <= x3
        int arr[3] = {x1, x2, x3};
        sort(arr, arr + 3);

        // El mejor punto es el que minimiza la distancia total, que es el punto medio.
        // En este caso, como tenemos solo 3 puntos, el punto que minimiza la distancia es arr[1].
        int optimal_point = arr[1];

        // Calculamos f(a)
        int result = abs(arr[0] - optimal_point) + abs(arr[1] - optimal_point) + abs(arr[2] - optimal_point);

        cout << result << endl;
    }

    return 0;
}
