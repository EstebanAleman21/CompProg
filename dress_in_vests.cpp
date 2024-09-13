#include <iostream>  // Para la entrada y salida estándar
#include <vector>    // Para usar el contenedor de vectores
#include <algorithm> // Para usar las funciones de ordenación

using namespace std;

int main()
{
    // Declaramos las variables para el número de soldados (n), el número de chalecos (m),
    // y los valores de tolerancia de tamaño (x, y)
    int n, m, x, y;

    // Entrada de los valores n (soldados), m (chalecos), x (tolerancia por debajo), y (tolerancia por encima)
    cin >> n >> m >> x >> y;

    // Creamos dos vectores: uno para los deseos de los soldados y otro para los tamaños de los chalecos
    vector<int> soldiers(n);
    vector<int> vests(m);

    // Leemos los tamaños deseados por los soldados
    for (int i = 0; i < n; ++i)
    {
        cin >> soldiers[i];
    }

    // Leemos los tamaños de los chalecos disponibles
    for (int i = 0; i < m; ++i)
    {
        cin >> vests[i];
    }

    // Vector para almacenar los pares de soldados y chalecos que se pueden emparejar
    vector<pair<int, int> > pairs;

    // Usaremos dos punteros: 'i' para recorrer los soldados y 'j' para recorrer los chalecos
    int i = 0, j = 0;

    // Mientras no hayamos terminado de recorrer a todos los soldados y chalecos
    while (i < n && j < m)
    {
        // Verificamos si el chaleco actual (vests[j]) cumple con el rango permitido para el soldado actual (soldiers[i])
        if (vests[j] >= soldiers[i] - x && vests[j] <= soldiers[i] + y)
        {
            // Si el chaleco es adecuado, guardamos el par de soldado (i+1) y chaleco (j+1)
            pairs.push_back({i + 1, j + 1});
            // Pasamos al siguiente soldado y chaleco
            ++i;
            ++j;
        }
        else if (vests[j] < soldiers[i] - x)
        {
            // Si el chaleco es demasiado pequeño para el soldado actual, pasamos al siguiente chaleco
            ++j;
        }
        else
        {
            // Si el chaleco es demasiado grande, pasamos al siguiente soldado
            ++i;
        }
    }

    // Imprimimos el número máximo de soldados que se pueden equipar con chalecos
    cout << pairs.size() << endl;

    // Imprimimos los pares de soldado y chaleco que se lograron emparejar
    for (const auto &p : pairs)
    {
        cout << p.first << " " << p.second << endl; // p.first es el índice del soldado, p.second es el índice del chaleco
    }

    return 0; // Fin del programa
}
