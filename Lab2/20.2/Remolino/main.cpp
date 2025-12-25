/* 
 * Proyecto: Remolino
 * File:   main.cpp
 * Author: Jaritza
 * Codigo: 20213699
 * Created on 8 de abril de 2024, 11:03 AM
 */

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#define N 5
#define M 5


void impresion1(int tablero[N][M],int x,int y,int m){
    if(y>=m) return;
    cout<<tablero[x][y]<<" ";
    impresion1(tablero, x, y+1, m);
}

void impresion2(int tablero[N][M],int y,int x,int n){
    if(x>=n) return;
    cout<<tablero[x][y]<<" ";
    impresion2(tablero, y, x+1, n);
}

void impresion3(int tablero[N][M],int x,int y, int limy){
    if(y<limy) return;
    cout<<tablero[x][y]<<" ";
    impresion3(tablero, x, y-1, limy);  
}

void impresion4(int tablero[N][M], int x, int y, int limx){
    if(x<limx) return;
    cout<<tablero[x][y]<<" ";
    impresion4(tablero,x-1,y,limx);
}

void imprimirTablero(int tablero[N][M], int n, int m, int x, int y){
    //caso base
    // (0,0) -> m = 5
    // (1,1) -> m = 4
    // (2,2) -> m = 3
    // (3,3) -> m = 2 --> error
    if(y<m && x<n){
        impresion1(tablero, x, y, m);
        impresion2(tablero, m-1, y+1, n); // es y+1 porque ya imprimio el ultimo del horizontal
        impresion3(tablero, n-1, m-2, y);
        impresion4(tablero, n-2, y, x+1);
        imprimirTablero(tablero, n-1, m-1, x+1,y+1);
    }
}

int main() {
    int tablero[N][M]{};
    int n = 5, m = 5, valor = 1;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n;j++){
            tablero[i][j] = valor ++;
        }
    }
    imprimirTablero(tablero, n, m, 0,0);
    
    return 0;
}

