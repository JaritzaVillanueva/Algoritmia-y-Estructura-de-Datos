/* 
 * Proyecto: Preg2
 * File:   main.cpp
 * Author: Jaritza
 * Codigo: 20213699
 * Created on 25 de marzo de 2024, 12:10 PM
 */

#include <iostream>
using namespace std;
#define N 2
#define M 2

int robot(int tablero[],int n ,int m,int i, int j){
    // i = fila , j = columna
    // colocamos un numero grande negativo para ya que estamos buscando la ruta mayor
    int derecha = -99999, abajo = -99999, total = 0;
    //caso base
    if(i == n-1 && j == n-1) return tablero[i][j]; // cuando llegue a la ultima posicion
    if(j<m-1){
        derecha = robot(tablero, n ,m , i, j+1);
    }
    if(i<n-1){
        abajo = robot(tablero, n, m, i+1, j);
    }
    if(derecha < abajo ) total = abajo + tablero[i][j];
    else total = derecha + tablero[i][j];
    return total;
}
int main() {
    int tablero[N][M] = {{3,5},{-2,4}};
    int n = 2, m= 2;
    cout<< robot(tablero, n , m, 0, 0);
    return 0;
}

