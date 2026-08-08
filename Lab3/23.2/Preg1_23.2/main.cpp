/* 
 * File:   main.cpp
 * Author: PC
 *
 * Created on 5 de mayo de 2024, 15:13
 */

#include <iostream>
using namespace std;
#define N 10
#define M 3

int mayorProd(int arr[N], int inicio, int fin){
    if(inicio == fin) return arr[inicio];
    int medio = (inicio+fin)/2;
    int mayorIzq = mayorProd(arr, inicio, medio);
    int mayorDer = mayorProd(arr, medio+1, fin);
    if(mayorDer>=mayorIzq) return mayorDer;
    else return mayorIzq;
}

int cuentaCentro(int arr[N], int inicio,int medio,int fin, int mayProd){
    if(arr[medio] == mayProd){
        int cuentaIzq, cuentaDer;
        //si estan para la derecha
        if(arr[medio] == arr[medio+1]){
            cuentaDer = 1;
            for(int i = medio+1; i<=fin; i++){
                if(arr[i] == arr[i+1]) cuentaDer++;
                else break;
            }
            cuentaIzq = 1;
            for(int i=medio; i>=inicio; i--){
                if(arr[i] == arr[i-1]) cuentaIzq++;
                else break;
            }
            return cuentaDer + cuentaIzq;
        }
        //si estan para la izquierda
        else if(arr[medio] == arr[medio-1]){
            cuentaDer = 1;
            for(int i = medio; i<=fin; i++){
                if(arr[i] == arr[i+1]) cuentaDer++;
                else break;
            }
            cuentaIzq = 1;
            for(int i=medio-1; i>=inicio; i--){
                if(arr[i] == arr[i-1]) cuentaIzq++;
                else break;
            }
            return cuentaDer + cuentaIzq;
        }
        //solo uno en el centro
        else return 1;
    }
    else return 0;
}

int mayorPico(int arr[N], int inicio, int fin, int mayProd){
    if(inicio == fin){
        if(arr[inicio] == mayProd)
            return 1;
        else return 0;
    }
    //implementacion
    int medio = (inicio+fin)/2;
    int mayDer = mayorPico(arr, inicio, medio, mayProd);
    int mayIzq = mayorPico(arr, medio +1, fin, mayProd);
    int mayCentro = cuentaCentro(arr, inicio, medio, fin, mayProd);
    if(mayDer>=mayCentro and mayDer>=mayIzq){
        return mayDer;
    }
    else{
        if(mayCentro>=mayDer and mayCentro >= mayIzq){
            return mayCentro;
        }
        else return mayIzq;
    }
}

void solucionSplinter(int pedidos[M][N],int n,int m){
    int menor = 9999, empresaElegida;
    for(int i=0; i<m; i++){
        int mayProd = mayorProd(pedidos[i], 0, n-1);
        int mayPico = mayorPico(pedidos[i], 0, n-1, mayProd);
        if(menor>=mayPico){
            menor = mayPico;
            empresaElegida = i + 1;
        }
    }
    cout<<"La empresa seleccionada es "<<empresaElegida<<" con un pico de "<<menor<<" horas."<<endl;
}

int main() {
    int pedidos[M][N] = {{15, 12, 10, 17, 15, 18, 18, 18, 12, 16},
                         {14, 17, 17, 17, 17, 12, 14, 14, 12, 12},
                         {16, 18, 20, 20, 15, 18, 16, 18, 18, 16}};
    int n = 10, m = 3;
    solucionSplinter(pedidos, n, m);
    return 0;
}

