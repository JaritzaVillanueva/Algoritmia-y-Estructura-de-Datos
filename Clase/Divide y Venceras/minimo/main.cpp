/* 
 * File:   main.cpp
 * Author: Jaritza Villanueva
 *
 * Created on 17 de mayo de 2024, 20:55
 */

#include <iostream>
using namespace std;
#define N 6

int minimo(int arr[N], int inicio, int fin){
    if(inicio == fin) return arr[inicio];
    int medio = (inicio+fin)/2;
    
    int menorIzq = minimo(arr, inicio, medio);
    int menorDer = minimo(arr, medio+1, fin);
    
    if(menorIzq <= menorDer) return menorIzq;
    else return menorDer;
}

int main(int argc, char** argv) {
    int arr[N] = {5, 6, 1, 2, 3, 4};
    int n=6;
    cout<<minimo(arr, 0, n-1);
    return 0;
}

