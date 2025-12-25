/* 
 * Proyecto: Lab5_2021-2_Preg2
 * File:   main.cpp
 * Author: Jaritza
 * Codigo: 20213699
 * Created on 3 de noviembre de 2023, 11:48 PM
 */

#include <iostream>
using namespace std;
#define MAXN 100
#define MAXM 100
int mov[8][2];
int movCor[4][2]; //la plancha solo se puede cortar de manera horizontal y vertical
void movimientos(){
    // x y
    mov[0][0]=0; mov[0][1]=1;
    mov[1][0]=1; mov[1][1]=1;
    mov[2][0]=1; mov[2][1]=0;
    mov[3][0]=1; mov[3][1]=-1;
    mov[4][0]=0; mov[4][1]=-1;
    mov[5][0]=-1; mov[5][1]=-1;
    mov[6][0]=-1; mov[6][1]=0;
    mov[7][0]=-1; mov[7][1]=1;
}
void generarMov(){
    movCor[0][0]=0;movCor[0][1]=1;
    movCor[1][0]=1;movCor[1][1]=0;
    movCor[2][0]=-1;movCor[2][1]=0;
    movCor[3][0]=0;movCor[3][1]=-1;
}

bool validaPosicion(int tablero[][MAXM], int posX, int posY,int  n,int  m){
    if(posX >= 0 && posY >= 0 && posX<m && posY<n && tablero[posY][posX]);
}

bool rodeado(int tablero[][], int posX, int posY,int  n,int  m){
    int nPoX, nposY;
    for(int i=0;i<8; i++){
        nPoX = posX + mov[i][0];
        nposY = posY + mov[i][1];
        if(validaPosicion(tablero, nPoX, nposY, n, m)) return false;
    }
    return true;
}

void buscarSolucion(int movimientos[][], int n, int m, int c, int posX, 
        int posY, int num, int max){
    if(rodeado(tablero, posX, posY, n, m)){
        
    }
}
int main() {
    int n, m, c;
    int tablero[MAXN][MAXM], max = 0;
    
    
    cout<<"Ingresar N = ";
    cin>>n;
    cout<<"Ingresar M = ";
    cin>>m;
    cout<<"Ingresar c = ";
    cin>>c;
    if(c>1 && c<5){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                tablero[n][m] = 0;
            }
        }
        
        movimientos();
        generarMov();
        buscarSolucion(tablero, 0, -1, 1, max);
        imprimirPlancha(tablero, n, m, c, 0, -1, 1, max);
        cout<<"Total de listones = "<<max;
    }
    else "El valor de c no se encuentra en el rango <1;5>"<<endl;
    return 0;
}

