#include <iostream>
#include <chrono>

using namespace std;

// Función para ordenar el arreglo usando el algoritmo de burbuja
void ordenar(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Intercambiar
                int aux = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;
            }
        }
    }
}

// Búsqueda secuencial
double secuencialOrd(int A[], int n, double dato) {
    int j = 0;
    while (j < n && A[j] < dato) {
        j++;
    }
    return (j >= n || A[j] == dato) ? (j + 1) : (-j - 1);
}

// Búsqueda binaria
double BusBinaria(int A[], int n, double dato) {
    int izq = 0, der = n - 1, m;
    while (izq <= der) {
        m = (izq + der) / 2;
        if (A[m] == dato) {
            return (m + 1); // Posición (1-indexed)
        } else if (A[m] < dato) {
            izq = m + 1;
        } else {
            der = m - 1;
        }
    }
    return -(izq + 1); // No encontrado
}

// Función para medir el tiempo de ejecución
double medirTiempo(double (*func)(int[], int, double), int arr[], int n, double dato, int repeticiones) {
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < repeticiones; ++i) {
        func(arr, n, dato);
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, std::micro> duration = end - start; // Medir en microsegundos
    return duration.count() / repeticiones; // Retornar tiempo promedio
}

int main() {
    srand(static_cast<unsigned>(time(0)));
    int n, opcion;

    cout << "Escriba el tamanio del arreglo: ";
    cin >> n;

    int arr1[10000]; // Se asume un tamaño máximo de 100 para el arreglo
    for (int i = 0; i < n; ++i) {
        arr1[i] = rand() % 201 - 100; // Genera números aleatorios entre -100 y 100
    }

    // Ordenar el arreglo
    ordenar(arr1, n);

    // Mostrar el arreglo ordenado
    for (int j = 0; j < n; j++) {
        cout << arr1[j] << "  ";
        if (j != 0 && j % 19 == 0) {
            cout << endl;
        }
    }
    cout << endl;

    cout << "\nEscribe el número que desea hallar: ";
    cin >> opcion;

    // Medir tiempo de búsqueda secuencial
    double posc1 = secuencialOrd(arr1, n, opcion);
    double tiempoOrdenada = medirTiempo(secuencialOrd, arr1, n, opcion, 100000); // Aumentar a 100000 repeticiones

    // Medir tiempo de búsqueda binaria
    double posc2 = BusBinaria(arr1, n, opcion);
    double tiempoBinaria = medirTiempo(BusBinaria, arr1, n, opcion, 100000); // Aumentar a 100000 repeticiones

    // Resultados
    cout << "\nResultado de la búsqueda secuencial: " << posc1 << " (Tiempo promedio: " << tiempoOrdenada << " microsegundos)" << endl;
    cout << "\nResultado de la búsqueda binaria: " << posc2 << " (Tiempo promedio: " << tiempoBinaria << " microsegundos)" << endl;

    return 0;
}