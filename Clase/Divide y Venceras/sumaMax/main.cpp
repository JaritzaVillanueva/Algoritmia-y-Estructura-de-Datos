/* 
 * File:   main.cpp
 * Author: PC
 *
 * Created on 4 de mayo de 2024, 22:14
 */

#include <iostream>
#include <memory>
using namespace std;
#define N 8

int sumaCentro(int arr[N], int inicio, int medio, int fin){
    int sumMAxIzq = -9999;
    int sumIzq =0 ;
    for(int i=medio; i>=inicio; i--){
        sumIzq += arr[i];
        if(sumMAxIzq<sumIzq){
            sumMAxIzq=sumIzq;
        }
    }
    int sumMAxDer = -9999;
    int sumDer =0 ;
    for(int i=medio+1; i<=fin; i++){
        sumDer += arr[i];
        if(sumMAxDer<sumDer){
            sumMAxDer=sumDer;
        }
    }
    return sumMAxDer + sumMAxIzq;
}

int sumaMax(int arr[N], int inicio, int fin){
    if(inicio == fin) return arr[inicio];
    int medio = (inicio+fin)/2;
    int sumIzq = sumaMax(arr, inicio, medio);
    int sumaDer = sumaMax(arr, medio+1, fin);
    int sumCentro = sumaCentro(arr, inicio, medio, fin);
    if(sumaDer>=sumIzq && sumaDer>=sumCentro){
        return sumaDer;
    }else if(sumCentro>=sumIzq && sumCentro>=sumaDer){
        return sumCentro;
    }else return sumIzq;
}

int main() {
    int numeros[N] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int n = 8;
    cout<<sumaMax(numeros, 0, n-1);
    return 0;
}

