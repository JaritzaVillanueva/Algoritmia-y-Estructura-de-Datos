/* 
 * File:   main.cpp
 * Author: PC
 *
 * Created on 10 de mayo de 2024, 21:10
 */

#include <iostream>
using namespace std;
#define N 11

void repetidos(int productos[],int stock[], int inicio, int fin,int arr[],int &prod,int &suma){
    if(productos[inicio] == productos[fin]){
        if(inicio+1 != fin){
            int n = 0;
            for(int i=inicio; i<=fin; i++){
                arr[n++]=i;
                suma+=stock[i];
            }
            prod = productos[inicio];
        }
        else{
            prod = -1;
        }
        return;
    }
    
    int medio = (inicio+fin)/2;
    if(medio % 2 == 1){
        if(productos[medio] == productos[medio-1] && productos[medio] != productos[medio+1]){
            repetidos(productos, stock, medio+1, fin, arr, prod, suma);
        }
        else repetidos(productos, stock, inicio, medio+1, arr, prod, suma);
    }
    else{
        if(productos[medio] == productos[medio+1] && productos[medio] != productos[medio-1]){
            repetidos(productos, stock, medio, fin, arr, prod, suma);
        }
        else repetidos(productos, stock, inicio, medio, arr, prod, suma);
    }
    
    
}

void solucion(int productos[],int stock[],int n){
    int arr[3]{}, producto, suma = 0;
    //numero repetido
    repetidos(productos, stock, 0, n-1, arr, producto, suma);
    if(producto != -1){
        cout<<"Las cajas se encuentran en las posiciones ";
        for(int i=0; i<3; i++) cout<<arr[i]<<" ";
        cout<<endl;
        cout<<"Son delk producto "<<producto<<endl;
        cout<<"Su stock suma: "<<suma<<endl;
    }
}

int main(int argc, char** argv) {
    int productos[N] = {1,1,2,2,4,4,5,5,5,6,6};
    int stock[N] = {20,20,30,10,10,10,20,20,20,10,10};
    int n = 11;
    solucion(productos, stock, n);
    return 0;
}

