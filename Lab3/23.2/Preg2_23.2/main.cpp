/* 
 * File:   main.cpp
 * Author: PC
 *
 * Created on 5 de mayo de 2024, 11:31
 */

#include <iostream>
using namespace std;
#define N 11
#define M 8
#define P 5
#define R 8

char imprimeRepetido(char arr[N], int inicio , int fin){
    if(arr[inicio]==arr[fin]){
        if(inicio+1<fin){
            return arr[inicio];
        }
        return 0;
    }
    //implementacion
    int medio = (inicio+fin)/2;
    if(medio % 2 == 1){
        if(arr[medio]==arr[medio-1] and arr[medio]!=arr[medio+1]){
            return imprimeRepetido(arr, medio+1, fin);
        }
        else return imprimeRepetido(arr, inicio, medio+1);
    }
    else{
        if(arr[medio] == arr[medio+1] and arr[medio] != arr[medio-1]){
            return imprimeRepetido(arr, medio, fin);
        }
        else return imprimeRepetido(arr, inicio, medio);
    }
    
}

void repetidos(char arr[M][N], int n, int m){
    for(int i=0; i<m; i++){
        char letra = imprimeRepetido(arr[i], 0, n-1);
        if(letra != 0){
            cout<<"La fila "<<i+1<<" tiene una "<<letra<<" adicional."<<endl;
        }
    }
}

int precioAlto(int arr[P], int inicio, int fin){
    int medio = (inicio+fin)/2;
    if(arr[medio]>arr[medio-1] and arr[medio]>arr[medio+1]) 
        return medio+1;
    
    if(arr[medio]<arr[medio-1]){
            return precioAlto(arr, inicio, medio);
    }
    else return precioAlto(arr, medio, fin);
}

void mayoresPrecios(int arr[R][P], int p, int r){
    for(int i=0; i<r; i++){
        int num = precioAlto(arr[i], 0, p-1);
        cout<<"En la fila "<<i+1<<", el pasajero del asiento "<<num<<" tiene el bocadito mas caro que sus 2 vecinos"<<endl;
    }
}

int main() {
    char letras[M][N] = {{'O', 'O', 'C', 'C', 'A', 'A', 'E', 'E', 'R', 'R', 'R'},
                      {'C', 'C', 'A', 'A', 'R', 'R', 'E', 'E', 'B', 'B', ' '},
                      {'R', 'R', 'E', 'E', 'C', 'C', 'F', 'F', 'A', 'A', ' '},
                      {'E', 'E', 'F', 'F', 'A', 'A', 'A', 'B', 'B', 'R', 'R'},
                      {'C', 'C', 'C', 'A', 'A', 'R', 'R', 'O', 'O', 'E', 'E'},
                      {'O', 'O', 'C', 'C', 'A', 'A', 'R', 'R', 'E', 'E', ' '},
                      {'A', 'A', 'F', 'F', 'R', 'R', 'E', 'E', 'O', 'O', ' '},
                      {'E', 'E', 'A', 'A', 'O', 'O', 'B', 'B', 'F', 'F', ' '}};
    int n = 11, m = 8;
    repetidos(letras, n , m);
    
    int precios[R][P]= {{1, 2, 3, 2, 1},
                     {2, 3, 2, 2, 1},
                     {1, 2, 2, 5, 3},
                     {2, 5, 3, 3, 1},
                     {2, 2, 3, 2, 1},
                     {1, 2, 3, 2, 1},
                     {3, 5, 2, 1, 1},
                     {2, 3, 2, 1, 1}};
    int p = 5, r = 8;
    mayoresPrecios(precios, p, r);
    return 0;
}

