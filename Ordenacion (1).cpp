#include <iostream>
#include <chrono>

using namespace std;

void interdirder(int a[], int b) {
    int aux;
    for (int i = 0; i < b - 1; i++) {
        for (int j = 0; j < b - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                aux = a[j];
                a[j] = a[j + 1];
                a[j + 1] = aux;
            }
        }
    }
}

void ShellSort(int A[], int b) {
    int c = b;
    while (c > 0) {
        c = c / 2;
        int cen = 1;
        while (cen == 1) {
            cen = 0;
            int i = 0;
            while (i + c <= b - 1) {
                if (A[i + c] < A[i]) {
                    int aux = A[i];
                    A[i] = A[i + c];
                    A[i + c] = aux;
                    cen = 1;
                }
                i++;
            }
        }
    }
}

void medirTiempo(void (*func)(int[], int), int arr[], int n, int repeticiones) {
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < repeticiones; ++i) {
        func(arr, n);
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, std::micro> duration = end - start; // Medir en microsegundos
    cout << "Tiempo promedio: " << duration.count() / repeticiones << " microsegundos" << endl; // Mostrar tiempo promedio
}

int main() {
    srand(time(0));
    int n;
    cout << "Escriba el tamanio del arreglo: ";
    cin >> n;

    int arr1[n];
    int arr2[n];
    
    for (int i = 0; i < n; ++i) {
        arr1[i] = rand() % 201 - 100;
        arr2[i] = arr1[i];
        cout << arr1[i] << "  ";
        if (i != 0 && i % 19 == 0) {
            cout << endl;
        }
    }
    cout << endl;

    cout << "1.- Ordenacion por burbuja" << endl;
    medirTiempo(interdirder, arr1, n, 10000); // Medir tiempo para burbuja

    cout << "2.- Ordenacion por Shellsort" << endl;
    medirTiempo(ShellSort, arr2, n, 10000); // Medir tiempo para Shellsort

    return 0;
}