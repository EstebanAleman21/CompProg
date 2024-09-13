#include <iostream>
#include <vector>
using namespace std;

// Función para aplicar la Criba de Eratóstenes y encontrar los primos hasta n
vector<int> sieve(int n)
{
    vector<int> primes(n + 1, 1); // Inicializamos todos los números como primos
    primes[0] = primes[1] = 0;    // 0 y 1 no son primos
    for (int i = 2; i * i <= n; ++i)
    {
        if (primes[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                primes[j] = 0; // Marcamos los múltiplos de i como no primos
            }
        }
    }
    return primes;
}

int main()
{
    int n;
    cin >> n;

    // Aplicamos la Criba de Eratóstenes para obtener los primos hasta n
    vector<int> primes = sieve(n);

    // Vector para contar el número de divisores primos distintos
    vector<int> divisorCount(n + 1, 0);

    // Contamos cuántos divisores primos tiene cada número
    for (int i = 2; i <= n; ++i)
    {
        if (primes[i])
        { // Si i es primo
            for (int j = i; j <= n; j += i)
            {
                divisorCount[j]++; // Incrementamos el contador de divisores primos de j
            }
        }
    }

    // Contamos cuántos números tienen exactamente 2 divisores primos distintos
    int almostPrimes = 0;
    for (int i = 2; i <= n; ++i)
    {
        if (divisorCount[i] == 2)
        {
            almostPrimes++;
        }
    }

    // Imprimimos el resultado
    cout << almostPrimes << endl;

    return 0;
}
