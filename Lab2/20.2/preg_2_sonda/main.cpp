/* 
 * File:   main.cpp
 * Author: Jaritza Villanueva
 *
 * Created on 12 de abril de 2024, 16:25
 */

#include <iostream>
using namespace std;
#define N 6
#define M 6


int contarHorizontal(int tablero[][M],int m,int x, int y){
    int contador = 0;
    if(y >= m) return 0;
   
    return tablero[x][y] + contarHorizontal(tablero, m, x, y+1);
}

int contarVertical(int tablero[][M],int n,int x, int y){
    if(x>=n) return 0;
    return tablero[x][y] + contarVertical(tablero, n, x+1, y);
}     

int sonda(int x, int y,int tablero[][M], int dx, int dy, int n, int m){
    int contador;
    if(x>=m || y>=n || x<0 || y<0){ // lñuego de todo su movimiento falta la suma de esa misma fila en movimiento
        if(dx == 0){ // movimiento horizontal, falta la suma horizontal
            contador = contarHorizontal(tablero, m, x, 0);
        }
        else{ //movimiento n vertical, falta la suma vertical
            contador = contarVertical(tablero, n, 0, y);
        }
        return contador;
        
    }
    else{//si no esta fuera
        //si solo se moviliza de manera horizontal, por ende deberia de buscar de forma vertical
        if(dx == 0){
            contador = contarVertical(tablero, n, 0, y);
        }
        else{
            contador = contarHorizontal(tablero, m, x, 0);
        }
        contador = contador - tablero[x][y];
        return contador + sonda(x+dx, y+dy, tablero, dx, dy, n, m); // al final se suma lo que se hallo en uno con los demas
    }
}



int main() {
    int tablero[N][M] = {{0, 0, 0, 1, 0, 1},
                         {0, 0, 1, 0, 0, 0},
                         {0, 1, 0, 0, 0, 1},
                         {1, 0, 0, 0, 0, 0},
                         {0, 1, 0, 0, 0, 0},
                         {0, 0, 0, 0, 1, 0}};
    int n = 6, m = 6, x = 3, y = 2;
    cout<<sonda(3, 2, tablero, 0, 1, n, m)<<" unidades"<<endl;
    
    return 0;
}

