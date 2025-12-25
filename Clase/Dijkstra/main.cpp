/* 
 * Proyecto: Dijkstra
 * File:   main.cpp
 * Author: Jaritza
 * Codigo: 20213699
 * Created on 24 de junio de 2024, 10:59 AM
 */

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#define V 5
#define MAX 1000

//COMPLEJIDAD (V^2)

//Fuerza bruta
int recorrer(int grafo[V][V], int inicio, int fin){
    int min = MAX; //valor minimo (por ello, comenzamos con un valor maximo)
    
    //caso base;
    if(inicio == fin){
        return 0;
    }
    
    //inicio + 1: para comenzar con la siguiente ciudad, porque no ese necesario 
    //verificar en el mismo inicio
    //se coloca v porque probara con todos los vertices
    for(int i=inicio+1; i<V; i++){
        if(grafo[inicio][i]){
            int distancia = grafo[inicio][i] + recorrer(grafo, i, fin);
            if(distancia<min){
                min = distancia;
            }
        }
    }
    return min;
}

void imprimirSolucion(int distancias[V]){
    for(int i=0; i<V; i++){
        cout<<"Ciudad: "<<i<<" - "<<distancias[i]<<endl;
    }
}

int buscarMinima(int distancias[], bool visitados[]){
    int min = 1000;
    for(int i=0; i<V; i++){
        if(distancias[i]<min && visitados[i] == false){
            min = i;
        }
    }
    return min;
}

void dijkstra(int grafo[V][V], int inicio){
    //necesito 2 conceptos: las distancias, fue visitado o no ?
    int distancias[V];
    bool visitados[V];
    
    //INICIAR VALORES
    //si me quiero quedar con el menor camino, necesito inciiar las distancias con el mayor posible
    for(int i=0; i<V;i++){
        distancias[i] = MAX;
        visitados[i] = false;
    }
    
    //primero inicio con el inicio
    distancias[inicio] = 0;
    
    
    //en el peor de los casos pasaria por todos
    for(int j=0; j<V-1;j++){
        //Tener en cuenta el idMenor debe tener visitado: false
        int idMenor = buscarMinima(distancias, visitados);
        
        visitados[idMenor] = true;
        for(int k=0; k<V; k++){
            //veerificar que no se visito y que existe camino
            //que la distancia no es el maximo establecido por default
            // 
            if(!visitados[k] && grafo[idMenor][k] && distancias[idMenor]!= MAX &&
                    (distancias[idMenor] + grafo[idMenor][k] < distancias[k])){
                distancias[k] = distancias[idMenor] + grafo[idMenor][k];
                
            }
        }
    }
    imprimirSolucion(distancias);
}

int main(int argc, char** argv) {
    //Grafo por matriz de adyacencia
    int grafo[V][V] = {{0, 3, 0, 7, 0},
                        {3, 0, 4, 2, 0},
                        {0, 4, 0, 5, 6},
                        {7, 2, 5, 0, 4},
                        {0, 0, 6, 4, 0}};
    // sin Dijkstra
    cout <<recorrer(grafo, 0, 4);
    cout<<endl;
    //con Dijkstra
    dijkstra(grafo, 0);
    return 0;
}

