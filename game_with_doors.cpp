#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int t; // número de casos de prueba

int main()
{
    cin >> t; // leer la cantidad de casos de prueba
    while (t--)
    {
        int izq1, izq2, der1, der2; // izq1 y der1 definen el primer intervalo, izq2 y der2 definen el segundo intervalo
        cin >> izq1 >> der1 >> izq2 >> der2;

        // Si el primer intervalo empieza después del segundo o si empiezan al mismo tiempo y el primer intervalo termina después,
        // entonces intercambiamos los intervalos para trabajar siempre con el primero empezando antes.
        if (izq1 > izq2 || (izq1 == izq2 && der1 > der2))
        {
            swap(izq1, izq2);
            swap(der1, der2);
        }

        // Caso donde no hay intersección entre los intervalos.
        if (der1 < izq2)
            cout << "1\n"; // Intervalos independientes
        // Caso donde los intervalos son exactamente iguales.
        else if (izq1 == izq2 && der1 == der2)
            cout << der1 - izq1 << endl; // Intervalos idénticos
        // Caso donde los intervalos tienen el mismo inicio o el mismo final.
        else if ((izq1 == izq2 && der1 != der2) || (der1 == der2 && izq1 != izq2))
            cout << der1 - izq2 + 1 << endl; // Coinciden en un extremo
        // Caso donde el segundo intervalo está completamente contenido dentro del primero.
        else if (izq1 < izq2 && der2 < der1)
            cout << der2 - izq2 + 2 << endl; // Segundo intervalo contenido en el primero
        // Caso general donde hay intersección pero no total contención.
        else
            cout << der1 - izq2 + 2 << endl; // Los intervalos se intersectan parcialmente
    }
}
