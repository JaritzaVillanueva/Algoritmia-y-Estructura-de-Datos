/* 
 * Proyecto: Grafos_MAtrizyListasAdyacencia
 * File:   main.cpp
 * Author: Jaritza
 * Codigo: 20213699
 * Created on 17 de junio de 2024, 11:27 AM
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;
#define N 4
#define M 3

void generarMAtrizAdyacencia(int matriz[N][N], vector<vector<int>> &matrizAdyacencia, int numVertices){
    //voy a recorrer una matriz definida a una matriz dinamica
    for(int i=0; i<numVertices; i++){
        vector<int> camino; // creacion de cada fila
        for(int j=0; j<numVertices; j++){
            camino.push_back(matriz[i][j]); // y en cada camino de la fila guardo el valor de la amtriz original (Guardar valores de la fila)
        }
        matrizAdyacencia.push_back(camino); // y lugo a la mattriz final, le voy agregar la fila que he generado
    }
}

void generarListaAdyacencia(int aristas[M][N], int numAristas, vector<vector<int>> &listaAdyacencia){
//    listaAdyacencia.resize(numAr)
    for(int i=0; i<numAristas; i++){
        int u = aristas[i][0];
        int v = aristas[i][1];
        
        
    }
}

int main(int argc, char** argv) {
    //representacion del grafo en matriz de adyecencia
    //funciona, siempre y cuando, el grafo no se pueda agregar vertices
    
    //RECORDAR: la matrices SE TRABAJAN DE MANERA DINAMICA
    int matriz[N][N] = {{0,0,0,1},
                        {0,0,1,0},
                        {0,1,0,1},
                        {1,0,1,0}};
    
    
    //forma mas sencilla
    //grafo dirigido
    int aristas[M][2] = {{0,3},{1,2},{2,3}};
    
    vector<vector<int>> matrizAdyacencia; // creacion de matriz con vectores
    vector<vector<int>> listaAdyacencia; // creacion de lista de vectores
    int numVertices = N;
    int numAristas = M;
    
    generarMAtrizAdyacencia(matriz, matrizAdyacencia, numVertices);
    
    //impresion de la mtriz de adyacencia
    cout<<"Matriz de adyacencia (Dinamica)"<<endl;
    for(int i=0; i<numVertices; i++){
        for(int j=0; j<numVertices; j++){
            cout<<matrizAdyacencia[i][j]<<" ";
        }
        cout<<endl;
    }
    
    vector<vector<int>> listaAdyacencia(numVertices); //constructor en el cual defino que sera numVertices filas
    
    generarListaAdyacencia(aristas, numAristas, listaAdyacencia);
    return 0;
}

