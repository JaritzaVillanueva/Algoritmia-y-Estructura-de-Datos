/* 
 * File:   main.cpp
 * Author: PC
 *
 * Created on 4 de julio de 2024, 21:17
 */

#include <iostream>
using namespace std;
#include "Pila.h"
#include "funcionesPila.h"
#define N 6

void DFS(int matriz[N][N], int inicio, int fin, char arr[N]){
    bool visitado[N];
    for(int i=0; i<N; i++) visitado[i] = false;
    
    Pila porVisitar;
    construir(porVisitar);
    //Inicializar
    apilar(porVisitar, inicio);
    
    visitado[inicio] = true;
    while(!esPilaVacia(porVisitar)){
        int actual = desapilar(porVisitar);
        cout<<arr[actual];
        if(actual == fin){
            return;
        }else cout<<" -> ";
        //adyacentes
        for(int i=N-1; i>=0; i--){
            if(!visitado[i] && matriz[actual][i] == 1){
                apilar(porVisitar, i);
                visitado[i] = true;
            }
        }
    }
}

int main() {
    int matriz[N][N] = {{0, 0, 1, 1, 0, 0},
                        {0, 0, 1, 0, 0, 1},
                        {1, 1, 0, 0, 1, 0},
                        {1, 0, 0, 0, 1, 0},
                        {0, 0, 1, 1, 0, 1},
                        {0, 1, 0, 0, 1, 0}};
    int numV = N;
    char letras[N] = {'a', 'b', 'c', 'd', 'e', 'f'};
    DFS(matriz, 0, 5, letras);
    return 0;
}

