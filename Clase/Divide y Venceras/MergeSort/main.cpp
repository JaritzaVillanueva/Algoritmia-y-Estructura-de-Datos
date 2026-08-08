/* 
 * File:   main.cpp
 * Author: PC
 *
 * Created on 14 de junio de 2024, 16:50
 */

#include <iostream>
using namespace std;
#define N 7

void merge(int arr[],int inicio, int medio, int fin){
    int aux[fin+1];
    int m, p, q;
    m = inicio;
    for(p = inicio, q = medio+1; p<=medio && q <=fin; m++){
        if(arr[p]<arr[q]){
            aux[m] = arr[p];
            p++;
        }
        else{
            aux[m] = arr[q];
            q++;
        }
    }
    //sobrantes de p
    while(p<=medio){
        aux[m] = arr[p];
        p++;
        m++;
    }
    //sobrantes de q
    while(q<=fin){
        aux[m] = arr[q];
        q++;
        m++;
    }
    
    //pasar al arreglo original
    for(int i=inicio; i<=fin; i++){
        arr[i] = aux[i];
    }
}

void mergeSort(int arr[], int inicio, int fin){
    if(inicio == fin) return;
    int medio = (inicio+fin)/2;
    mergeSort(arr, inicio, medio);
    mergeSort(arr, medio+1, fin);
    merge(arr, inicio, medio, fin);
}

int main() {
    int arr[N] = {38, 27, 43, 3, 9, 82, 10};
    int n = 7;
    mergeSort(arr, 0, n-1);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

