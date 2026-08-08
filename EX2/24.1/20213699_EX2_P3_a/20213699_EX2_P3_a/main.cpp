/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 6 de julio de 2024, 08:06
 */

#include <iostream>

using namespace std;
#define V 6
#define MAX 99999

//, int matrizNiv[V][V], int &sum, int can
void calcularCamino(int predecesor[V], int j, int matrizNiv[V][V], double &sum, int &cant){
    //en caso lo que se guardo fue el origen del camino
    if(predecesor[j] == -1){
        return;
    }
    calcularCamino(predecesor, predecesor[j], matrizNiv, sum, cant);
    //calculo de los datos
    sum += matrizNiv[j][predecesor[j]];
    cant++;
}

void imprimirSolucion(int latencias[V], int inicio, int predecesor[V], int matrizNiv[V][V]){
    for(int i=0; i<V; i++){
        cout<< "Servidor: "<< i + 1<< " Latencia: "<<latencias[i]<<" Seguridad Promedio: ";
        double sumatoria = 0;
        int cantidad = 0;
        //recorremos los precesores para calcular la sumatoria y la cantidad que ha recorrido
        calcularCamino(predecesor, i, matrizNiv, sumatoria, cantidad);
        if(sumatoria == 0) cout<<"0";
        else cout<<sumatoria/cantidad;
        cout<<endl;
    }
}

int calculaMinima(int latencias[V], bool visitados[V]){
    int indice, minLat = MAX;
    for(int i = 0; i<V; i++){
        if(!visitados[i] && latencias[i] < minLat){
            minLat = latencias[i];
            indice = i;
        }
    }
    return indice;
}

void solucion(int matrizAdy[V][V], int inicio, int matrizNiv[V][V]){
    int latencias[V];
    bool visitados[V];
    //arreglo para guardar los vertices que ha ido recorriendo el camino
    //se guardaran los indices
    int predecesor[V];
    //inicializacion
    for(int i=0; i<V; i++){
        latencias[i] = MAX;
        visitados[i] = false;
        predecesor[i] = -1; 
    }
    
    latencias[inicio] = 0;
    for(int i=0; i<V-1; i++){
        int minLat = calculaMinima(latencias, visitados);
        visitados[minLat] = true;
        
        for(int k=0; k<V; k++){
            
            if(!visitados[k] &&
                    matrizAdy[minLat][k] &&
                    latencias[minLat] != MAX &&
                    (latencias[minLat] + matrizAdy[minLat][k])<latencias[k]){
                latencias[k] = latencias[minLat] + matrizAdy[minLat][k];
                predecesor[k] = minLat;
            }
        }
    }
    imprimirSolucion(latencias, inicio, predecesor, matrizNiv);
}

int main() {
    //primer caso
//    int matrizAdy[V][V] = {{0, 0, 0, 3, 0, 0},
//                        {0, 0, 1, 0, 3, 0},
//                        {0, 1, 0, 2, 5, 7},
//                        {3, 0, 2, 0, 7, 0},
//                        {0, 3, 5, 7, 0, 2},
//                        {0, 0, 7, 0, 2, 0}};
//    int matrizNiv[V][V] = {{0, 0, 0, 9, 0, 0},
//                        {0, 0, 7, 0, 8, 0},
//                        {0, 7, 0, 7, 5, 7},
//                        {9, 0, 7, 0, 7, 0},
//                        {0, 8, 5, 7, 0, 9},
//                        {0, 0, 7, 0, 9, 0}};
    //segundo caso
    int matrizAdy[V][V] = {{0, 0, 0, 3, 0, 0},
                            {0, 0, 3, 0, 3, 0},
                            {0, 3, 0, 2, 5, 7},
                            {3, 0, 2, 0, 7, 0},
                            {0, 3, 5, 7, 0, 2},
                            {0, 0, 7, 0, 2, 0}};
    int matrizNiv[V][V] = {{0, 0, 0, 9, 0, 0},
                            {0, 0, 7, 0, 8, 0},
                            {0, 7, 0, 7, 5, 7},
                            {9, 0, 7, 0, 7, 0},
                            {0, 8, 5, 7, 0, 9},
                            {0, 0, 7, 0, 9, 0}};
    solucion(matrizAdy, 0, matrizNiv);
    return 0;
}

