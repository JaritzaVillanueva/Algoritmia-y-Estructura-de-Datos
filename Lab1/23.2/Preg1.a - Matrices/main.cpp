#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void cargaBin(int num, int n, int arr[]) {
    for (int i = 0; i < n; i++) arr[i] = 0;
    int i = 0, aux;
    while (num > 0) {
        aux = num % 2;
        arr[i] = aux;
        num = num / 2;
        i++;
    }
}

int main() {
    int p = 100, n, max = 0;

    cout << "Ingrese el valor de n: ";
    cin >> n;

    int pesos[n][n];
    int valores[n][n];
    int mejorPeso[n][n]{}, maxValo[n][n]{};
    int opcion = pow(2, n);
    int cromo[n][n]; // Matriz para almacenar los cromosomas

    // Llenar la matriz de pesos y valores
    cout << "Ingrese la matriz de pesos:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> pesos[i][j];
        }
    }

    cout << "Ingrese la matriz de valores:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> valores[i][j];
        }
    }

    for (int i = 0; i < opcion; i++) {
        cargaBin(i, n, cromo[0]);

        for (int j = 0; j < opcion; j++) {
            cargaBin(j, n, cromo[1]);

            for (int k = 0; k < opcion; k++) {
                cargaBin(k, n, cromo[2]);

                for (int h = 0; h < opcion; h++) {
                    cargaBin(h, n, cromo[3]);

                    int pParcial = 0, ValParcial = 0;
                    int solPeso[n][n]{}, solVal[n][n]{};

                    for (int l = 0; l < n; l++) {
                        for (int m = 0; m < n; m++) {
                            if (cromo[l][m] == 1) {
                                pParcial += pesos[l][m];
                                ValParcial += valores[l][m];
                                solPeso[l][m] = pesos[l][m];
                                solVal[l][m] = valores[l][m];
                            }
                        }
                    }

                    if (pParcial == p) {
                        if (max < ValParcial) {
                            max = ValParcial;

                            for (int q = 0; q < n; q++) {
                                for (int t = 0; t < n; t++) {
                                    mejorPeso[q][t] = solPeso[q][t];
                                    maxValo[q][t] = solVal[q][t];
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    //impresion
    cout<<"Pesos Finales: "<<endl;
    for(int q = 0; q<n; q++){
        for(int t = 0; t<n; t++){
            cout<<right<<setw(2)<<mejorPeso[q][t]<<" ";
        }
        cout<<endl;
    }
    
    cout<<"Valores Finales: "<<endl;
    for(int q = 0; q<n; q++){
        for(int t = 0; t<n; t++){
            cout<<right<<setw(2)<<maxValo[q][t]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
