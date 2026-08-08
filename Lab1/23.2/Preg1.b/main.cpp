/* 
 * File:   main.cpp
 * Author: PC
 *
 * Created on 7 de abril de 2024, 17:17
 */

#include <iostream>
using namespace std;
#define MAXCOL 10
#define MAXFIL 4

int m[4][2]; // Matriz para almacenar los movimientos del robot

void movimientos() {
    m[0][0] = 0; m[0][1] = 1;  // Movimiento a la derecha
    m[1][0] = 0; m[1][1] = -1; // Movimiento a la izquierda
    m[2][0] = 1; m[2][1] = 0;  // Movimiento hacia abajo
    m[3][0] = -1; m[3][1] = 0; // Movimiento hacia arriba
}

bool buscar(char letras[][MAXCOL], char palabra[], int n,int i,int j){
    char copia[n];
    bool primeraLetra = false, sigLetra = false;
    //copia
    for(int k = 0; k<n; k++){
        copia[k] = palabra [k];
    }
    
    //verificar la primera letra
    for(int k=0; k<n; k++){
        if(copia[k] == letras[i][j]){
            primeraLetra = true;
            copia[k] = '1';
        }
    }
    
    int ncol, nfil;
    if(primeraLetra == false) return false;
    for(int k=0; k<4; k++){
        nfil = i + m[k][0];
        ncol = j + m[k][1];
        int p;
        for(p = 1; p<n; p++){
            sigLetra = false;
            if(nfil>=MAXFIL || nfil<0 || ncol>=MAXCOL || ncol<0) break;
            //validar siguiente letra
            for(int w = 0; w<n ; w++){
                if(letras[nfil][ncol]==copia[w]){
                    sigLetra = true;
                    copia[w] = '1';
                    break;
                }
            }
            if(sigLetra == false) break;
            nfil = nfil + m[k][0];
            ncol = ncol + m[k][1];
        }
        if(p == n) return true;
        
        
    }
    return false;
}

void buscarPalabra(char letras[][MAXCOL], char palabra[], int n) {
    int validacion;
    for(int i=0; i<MAXFIL; i++){
        for(int j=0; j<MAXCOL;j++){
            validacion = buscar(letras,palabra, n, i, j);
            if(validacion){
                cout<<i<<","<<j<<" ";
            }
        }
    }
}

int main() {
    int n = 3; // número de letras de la palabra
    char letras[][MAXCOL]= {{'H', 'C', 'H', 'B', 'Y', 'S', 'O', 'S', 'O', 'H'},
                             {'S', 'C', 'S', 'S', 'Y', 'Q', 'O', 'S', 'Z', 'K'},
                             {'O', 'P', 'N', 'Y', 'O', 'K', 'F', 'H', 'C', 'K'},
                             {'O', 'B', 'N', 'I', 'Y', 'S', 'P', 'O', 'O', 'K'}};
    char palabra[] = {'H', 'S', 'O'};
    movimientos();
    buscarPalabra(letras, palabra, n);
    return 0;
}

