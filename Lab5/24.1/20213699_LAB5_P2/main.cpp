/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * NOMBRE: Jaritza Maribel Villanueva Huaraca
 * CODIGO: 20213699
 * Created on 15 de junio de 2024, 08:06
 */

#include <iostream>

using namespace std;
#define N 5
#define M 7

void merge(char arr[], int inicio, int medio,int fin){
    char aux[fin+1];
    int m, p, q;
    m = inicio;
    for(p = inicio, q = medio+1; p<=medio && q<=fin; m++){
        if(arr[p]<=arr[q]){
            aux[m] = arr[p];
            p++;
        }
        else{
            aux[m] = arr[q];
            q++;
        }
    }
    //sobra en p
    while(p<=medio){
        aux[m] = arr[p];
        p++;
        m++;
    }
    //sobra en q
    while(q<=fin){
        aux[m] = arr[q];
        q++;
        m++;
    }
    //pasar a la fila
    for(int i=inicio; i<=fin; i++){
        arr[i] = aux[i];
    }
}

//Parte a)
void ordenarFila(char arr[], int inicio, int fin){
    if(inicio == fin) return;
    int medio = (inicio+fin)/2;
    ordenarFila(arr, inicio, medio);
    ordenarFila(arr, medio+1, fin);
    merge(arr, inicio, medio, fin);
}

//Parte b)
void ordenarMatriz(char letras[N][M], int n, int m){
    for(int i=0; i<n; i++){
        ordenarFila(letras[i], 0, m-1);
    }
}

//Parte c)
char buscarPlatoFila(char arr[], int inicio, int fin){
    if(inicio>fin) return '0';
    if ( inicio == fin) return arr[inicio];
    int medio = (inicio+fin)/2;
    if(medio % 2 == 0){
        if(arr[medio] == arr[medio+1]){
            return buscarPlatoFila(arr, medio+2, fin);
        }
        else{
            return buscarPlatoFila(arr, inicio, medio);
        }
    }
    else{
        if(arr[medio] == arr[medio-1]){
            return buscarPlatoFila(arr, medio+1, fin);
        }
        else{
            return buscarPlatoFila(arr, inicio, medio-1);
        }
    }
}

//Parte d)
int buscarLasagna(char letras[N][M],int n,int m){
    for(int i=0; i<n; i++){
        char diferente = buscarPlatoFila(letras[i], 0, m-1);
        if(diferente == 'L'){
            return i+1;
        }
    }
    return 0;
}

int main() {
    int n = 5, m = 7;
    char letras[N][M] = {{'C', 'O', 'C', 'V', 'O', 'V', 'J'},
                            {'F', 'J', 'A', 'F', 'A', 'J', 'Y'},
                            {'W', 'G', 'L', 'W', 'G', 'S', 'S'},
                            {'S', 'I', 'S', 'M', 'M', 'I', 'Q'},
                            {'O', 'B', 'B', 'O', 'F', 'X', 'F'}};
    
    //Parte e)
    ordenarMatriz(letras, n, m);
    int lasagna = buscarLasagna(letras, n, m);
    if(lasagna) cout<<"Se encontro la lasagna"<<endl;
    else cout<<"No se encontro lasagna"<<endl;
    
    return 0;
}

