/* 
 * Proyecto: Preg2
 * File:   main.cpp
 * Author: Jaritza
 * Codigo: 20213699
 * Created on 8 de abril de 2024, 10:28 AM
 */

#include <iostream>
#include <iomanip>
using namespace std;
#define M 6
#define N 6

//En este caso 
void movimiento(){
    
}

int cuentaHorizontal(int **tablero,int x,int m, int y){
    //caso base
    if(y >= m) return 0;
    else tablero[x][y] + cuentaHorizontal(tablero, x, m, y+1);
}

int cuentasVertical(int **tablero, int y,int n,int x){
    //caso base
    if(x >= n) return 0;
    else tablero[x][y] + cuentasVertical(tablero, y, n, x+1);
}

int cuentaLineas(int **tablero, int n,int m,int x,int y,int dx,int dy){
    int minas;
    if(y>=m || y<0 || x>=n || x<0){
        //caso base
        //si me muevo de manera horizontal, debo 
        if(dx == 0){
            minas = cuentaHorizontal(tablero, x, m, 0); // pasamos x y m, la posicion y el tope horizontal. El 0 es la posicion de y inicial ya que se desea buscar el 1 en toda esa linea horizontal
        }
        else{
            //aqui me muevo de forma vertical
            minas = cuentasVertical(tablero, y, n, 0);
        }
        return minas;
    }
    else{
        if( dx == 0){
            minas = cuentasVertical(tablero, y, n, 0);
        }
        else{
            minas = cuentaHorizontal(tablero, x, m, 0);
        }
        minas = minas - tablero[x][y];
        return minas + cuentaLineas(tablero, n, m, x+dx, y+dy, dx, dy);
    }
}

int main() {
    int tablero[N][M] = {{0,0,0,1,0,1},
    {0,0,1,0,0,0},
    {0,1,0,0,0,1},
    {1,0,0,0,0,0},
    {0,1,0,0,0,0},
    {0,0,0,0,1,0}};
    
    int n = 6, m =6, x=3, y=2;
    int dx = 0, dy = 1; //el mov lo realizamos en funcion del desplazamiento, en este caso es derecha
    
    cout<<cuentaLineas(tablero, n, m, x, y, dx, dy);
    return 0;
}

