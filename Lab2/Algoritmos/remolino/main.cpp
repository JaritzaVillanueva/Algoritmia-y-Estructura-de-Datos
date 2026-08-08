/* 
 * File:   main.cpp
 * Author: PC
 *
 * Created on 12 de abril de 2024, 19:04
 */

#include <iostream>
using namespace std;
#define M 5
#define N 4

void impresion1(int tablero[N][M],int topeY,int x, int y){
    if(y>=topeY) return;
    cout<<tablero[x][y]<<" ";
    impresion1(tablero, topeY, x, y+1);
}

void impresion2(int tablero[N][M],int topeX,int x, int y){
    if(x>=topeX) return;
    cout<<tablero[x][y]<<" ";
    impresion2(tablero, topeX, x+1, y);
}

void impresion3(int tablero[N][M], int topY, int x, int y){
    if(y<topY) return;
    cout<<tablero[x][y]<<" ";
    impresion3(tablero, topY, x, y-1);
}

void impresion4(int tablero[N][M], int topeX, int x, int y){
    if(x<topeX) return;
    cout<<tablero[x][y]<<" ";
    impresion4(tablero, topeX, x-1, y);
}

void remolino(int tablero[N][M],int n, int m, int x, int y){
    if(y>=m || x>=n) return;
    impresion1(tablero, m, x, y);
    impresion2(tablero, n, x+1, m-1);
    impresion3(tablero, y, n-1, m-2);
    impresion4(tablero, x+1, n-2, y);
    remolino(tablero, n-1, m-1, x+1, y+1);
}

int main() {
    int n = 4, m = 5, num = 1;
    int tablero[N][M];
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            tablero[i][j] = num++;
        }
    }
    remolino(tablero, n, m, 0, 0);
    return 0;
}

