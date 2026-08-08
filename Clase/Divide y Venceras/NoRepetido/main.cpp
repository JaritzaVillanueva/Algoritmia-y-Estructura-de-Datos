/* 
 * File:   main.cpp
 * Author: Jaritza Villanueva
 *
 * Created on 4 de mayo de 2024, 20:24
 */

#include <iostream>
using namespace std;
#define N 11

int noRepetido(int arr[N], int inicio,int fin){
    //caso base
    if(inicio>fin) return -1;
    if(inicio == fin) return arr[inicio];
    
    int medio = (inicio+fin)/2;
    //implmentacion
    if(medio % 2 == 0){
        if(arr[medio] == arr[medio+1]){
            return noRepetido(arr, medio+2, fin);
        }
        else return noRepetido(arr, inicio, medio);
    }
    else{
        if(arr[medio-1] == arr[medio]){
            return noRepetido(arr, medio+1, fin);
        }
        else return noRepetido(arr, inicio, medio-1);
    }
}

int main() {
    int numeros[N] = {1, 1, 3, 3, 4, 4, 5, 5, 7, 8, 8};
    int n = 11;
    cout<<noRepetido(numeros, 0, n-1);
    return 0;
}

