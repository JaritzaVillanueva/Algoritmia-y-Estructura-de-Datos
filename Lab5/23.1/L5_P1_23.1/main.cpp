/* 
 * Proyecto: L5_P1_23.1
 * File:   main.cpp
 * Author: Jaritza
 * Codigo: 20213699
 * Created on 1 de diciembre de 2023, 06:48 PM
 */

#include <iostream>
using namespace std;
#define MAX 10
int lista[MAX];//Arreglo donde voy armando mis soluciones, es donde pondré/sacaré los controles/proyectos que voy analizando
int x = 0, y = 0;
int max_retorno = 0; // Variable para almacenar el retorno máximo
int mejor_solucion[MAX]; // Arreglo para almacenar el mejor conjunto de proyectos

// Función que verifica si el elemento en la posición k cumple con las restricciones previas
int valida(int k, int n, int pre[][3], int pro[]) {
    int i, cont = 0;
    if (pre[k][0] == -1) {
        return 1; // Si no tiene predecesores, retorna 1
    }
    for (i = 0; i < 3; i++) {
        if (pre[k][i] == -1) {
            break; // Si se encuentra un predecesor igual a -1, se termina la búsqueda
        }
        for (int j = 0; j < n; j++) {
            if (pre[k][i] == lista[j]) {
                cont++; // Si el predecesor está en la solución, se incrementa el contador
                break; // Se encontró el predecesor, se termina la búsqueda
            }
        }
    }
    if (cont == i) {
        return 1; // Si se encontraron todos los predecesores, cumple con las restricciones previas
    }
    return 0; // No cumple con las restricciones previas
}

// Función recursiva que realiza el empaquetado de los elementos
void empaca(int i, int n, int peso, int p[], int pre[][3], int proy[], int retorno[]) {
    if (i == n || peso < 0)
        return; // Caso base: si se ha alcanzado el final del arreglo o el peso disponible es negativo, retorna

    if (p[i] == peso && valida(i, y, pre, proy)) {
        // Si el peso actual es igual al peso disponible y cumple con las restricciones previas
        lista[y] = proy[i]; // Se agrega el elemento a la lista de solución
        int z;
        int retorno_total = 0; // Variable para almacenar el retorno total de la solución actual
        for (z = 0; z <= y; z++) {
            cout << "P" << lista[z]+1 << " ";
            retorno_total += retorno[lista[z]]; // Calcula el retorno total sumando los retornos individuales de los proyectos
        }
        cout << " - Retorno de inversión: " << retorno_total << endl;

        /*if (retorno_total > max_retorno) {
            max_retorno = retorno_total; // Actualiza el máximo retorno de inversión
            for (z = 0; z <= y; z++) {
                mejor_solucion[z] = lista[z]; // Almacena el conjunto de proyectos con el máximo retorno de inversión
            }
            mejor_solucion[z] = -1; // Marca el final del conjunto de proyectos con -1
        }*/
    }

    lista[y++] = proy[i]; // Se agrega el elemento a la lista de solución
    if (valida(i, y, pre, proy)) {
        empaca(i + 1, n, peso - p[i], p, pre, proy, retorno); // Llamada recursiva con el peso actual reducido por el peso del proyecto
    }
    y--; // Retrocede en el arreglo de solución (backtracking)
    empaca(i + 1, n, peso, p, pre, proy, retorno); // Llamada recursiva con el mismo peso actual
}

int main() {
    int proye[] = {0, 1, 2, 3, 4, 5, 6, 7}; // Arreglo de los elementos a empaquetar
    int costo[] = {32, 8, 40, 40, 20, 4, 20, 20}; // Arreglo de los pesos de los elementos
    int prede[][3] = {
        {-1, -1, -1},   // Proyecto 0 no tiene predecesores
        {-1, -1, -1},   // Proyecto 1 no tiene predecesores
        {0, 1, -1},     // Proyecto 2 tiene predecesores 0 y 1
        {-1, -1, -1},   // Proyecto 3 no tiene predecesores
        {-1, -1, -1},   // Proyecto 4 no tiene predecesores
        {1, -1, -1},    // Proyecto 5 tiene predecesores 1
        {5, -1, -1},    // Proyecto 6 tiene predecesores 5
        {5, -1, -1}     // Proyecto 7 tiene predecesores 5
    };
    int retorno[] = {60, 32, 120, 60, 32, 20, 48, 60}; // Arreglo de retorno de inversión de cada proyecto
    int n = 8; // Tamaño de los arreglos
    int presupuesto = 100; // Peso disponible

    empaca(0, n, presupuesto, costo, prede, proye, retorno); // Llamada a la función de empaquetado

    /*cout << "Conjunto de proyectos con mayor retorno de inversión: ";
    for (int i = 0; mejor_solucion[i] != -1; i++) {
        cout << "P" << mejor_solucion[i] << " ";
    }
    cout << "- Retorno de inversión: " << max_retorno << endl;
*/
    return 0;
}