/* 
 * File:   main.cpp
 * Author: Jaritza Villanueva
 *
 * Created on 17 de mayo de 2024, 21:41
 */

#include <iostream>
using namespace std;
#define N 11

int maximo(int arr[N], int inicio, int fin){
    if(inicio == fin) return arr[inicio];
    int medio = (inicio+fin)/2;
    
    int mayorIzq = maximo(arr, inicio, medio);
    int mayorDer = maximo(arr, medio+1, fin);
    
    if(mayorIzq >= mayorDer) return mayorIzq;
    else return mayorDer;
}

int main() {
    int arr[N] = {8, 10, 20, 80, 100, 200, 400, 500, 3, 2, 1};
    int n = 11;
    cout<<maximo(arr, 0, n-1);
    return 0;
}

