#include <iostream>
#include <cmath>

using namespace std;

// Convierte el entero 'num' a su representación binaria en el arreglo 'arr'
void cargaBin(int num, int n, int arr[]) {
    for (int i = 0; i < n; i++) {
        arr[i] = 0;
    }
    int i = 0;
    while (num > 0 && i < n) {
        arr[i++] = num % 2; 
        num = num / 2;     
    }
}

int main() {
    int M, N;

    cout << "Ingrese la cantidad de camiones (M): ";
    cin >> M;
    cout << "Ingrese la cantidad de paquetes (N): ";
    cin >> N;

    // Arreglos dinámicos estándar en C++
    int* camiones = new int[M];
    int* paquetes = new int[N];

    cout << "\nCapacidad de los camiones:" << endl;
    for (int i = 0; i < M; i++) {
        cout << "Camion " << i + 1 << ": ";
        cin >> camiones[i];
    }

    cout << "\nPeso de los paquetes:" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Paquete " << i + 1 << ": ";
        cin >> paquetes[i]; 
    }

    int* combo = new int[N];
    int totalComb = pow(2, N);

    int mejorDiferencia = -1;
    int mejorVacioMax = -1;
    int mejorVacioMin = -1;
    int mejorComb = -1;

    // Evaluación de combinaciones (0 = Camión 1, 1 = Camión 2)
    for (int i = 0; i < totalComb; i++) {
        cargaBin(i, N, combo);

        int pesoCamion1 = 0;
        int pesoCamion2 = 0;

        for (int j = 0; j < N; j++) {
            if (combo[j] == 0) {
                pesoCamion1 += paquetes[j];
            } else {
                pesoCamion2 += paquetes[j];
            }
        }

        // Verificar que ningún camión sobrepase su capacidad
        if (pesoCamion1 <= camiones[0] && pesoCamion2 <= camiones[1]) {
            int vacio1 = camiones[0] - pesoCamion1;
            int vacio2 = camiones[1] - pesoCamion2;

            int vacioMax = (vacio1 > vacio2) ? vacio1 : vacio2;
            int vacioMin = (vacio1 < vacio2) ? vacio1 : vacio2;
            int diferencia = vacioMax - vacioMin;

            // Seleccionar la combinación que minimice la diferencia de vacíos
            if (mejorDiferencia == -1 || diferencia < mejorDiferencia) {
                mejorDiferencia = diferencia;
                mejorVacioMax = vacioMax;
                mejorVacioMin = vacioMin;
                mejorComb = i;
            }
        }
    }

    // Impresión de resultados
    if (mejorComb != -1) {
        cargaBin(mejorComb, N, combo);
        cout << "Asignacion optima de paquetes:" << endl;
        for (int j = 0; j < N; j++) {
            cout << "  Paquete " << j + 1 << " (peso " << paquetes[j] 
                 << ") -> Camion " << combo[j] + 1 << endl;
        }
        cout << "\nVacio Maximo: " << mejorVacioMax << endl;
        cout << "Vacio Menor: " << mejorVacioMin << endl;
        cout << "Resultado (Vacio maximo - Vacio menor): " << mejorDiferencia << endl;
    } else {
        cout << "No existe ninguna combinacion valida dentro del limite de capacidad." << endl;
    }

    return 0;
}
