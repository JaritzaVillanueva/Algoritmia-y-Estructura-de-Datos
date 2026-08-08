/* 
 * File:   main.cpp
 * Author: Jaritza Villanueva
 *
 * Created on 4 de mayo de 2024, 21:02
 */

#include <iostream>
using namespace std;
#define N 7

int encontrarCero(int arr[N], int inicio, int fin){
    if(inicio>fin) return -1;
    if(inicio == fin){
        if (arr[inicio] == 0) return 1;
    }
    int medio = (inicio+fin)/2;    
    //implementcion
    if(arr[medio] == 0){
        if(arr[medio-1]!=0){
            return fin - medio + 1;
        }
        else return encontrarCero(arr, inicio, medio-1) + (fin - medio + 1);
    }
    return encontrarCero(arr, medio +1, fin);
    
}

int main(int argc, char** argv) {
    int arreglo[N] = {1, 1, 1, 1, 1, 1, 1};
    int n = 7;
    cout<<encontrarCero(arreglo, 0, n-1);
    return 0;
}

