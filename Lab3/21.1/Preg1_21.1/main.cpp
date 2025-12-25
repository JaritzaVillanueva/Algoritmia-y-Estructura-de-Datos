/* 
 * Proyecto: Preg1_21.1
 * File:   main.cpp
 * Author: Jaritza
 * Codigo: 20213699
 * Created on 6 de mayo de 2024, 02:22 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;
#define N 7
#define M 6

void merge(char empresas[N],int acciones[N], int inicio,int medio,int fin){
    char aux_Empresas[N];
    int aux_acciones[N], m, q, p;
    m = inicio;
    for(p = inicio, q = medio+1; p <=medio && q <=fin; m++){
        if(acciones[p]<acciones[q]){
            aux_acciones[m] = acciones[p];
            aux_Empresas[m] = empresas[p];
            p++;
        }
        else{
            aux_acciones[m] = acciones[q];
            aux_Empresas[m] = empresas[q];
            q++;
        }
    }
    //restante de p
    while(p<=medio){
        aux_acciones[m] = acciones[p];
        aux_Empresas[m] = empresas[p];
        m++;
        p++;
    }
    //restante de q
    while(q<=fin){
         aux_acciones[m] = acciones[q];
        aux_Empresas[m] = empresas[q];
        q++;
        m++;
    }
    //pasar al original
    for(int i=inicio; i<=fin; i++){
        empresas[i] = aux_Empresas[i];
        acciones[i] = aux_acciones[i];
    }
}

void mergeSort(char empresas[N],int acciones[N], int inicio, int fin){
    if(inicio == fin) return;
    int medio = (inicio+fin)/2;
    mergeSort(empresas, acciones, inicio, medio);
    mergeSort(empresas, acciones, medio+1, fin);
    merge(empresas, acciones, inicio, medio, fin);
}

double calcularIBd(int acciones[N],int n){
    double suma = 0, promedio;
    for(int i=0; i<n; i++){
        suma += acciones[i];
    }
    promedio = suma/n;
    return promedio;
}

void venta(int acciones[N], int inicio, int fin, double IBd, int &suma, char arrEmpresas[N], int &n, char empresas[N], int arrAcciones[N]){
    if(inicio == fin){
        if(acciones[inicio]>IBd){
            suma += acciones[inicio];
            arrEmpresas[n] = empresas[inicio];
            arrAcciones[n] = acciones[inicio];
            n++;
        }
        return;
    }
    int medio = (inicio + fin)/2;
    venta(acciones, inicio, medio, IBd, suma, arrEmpresas, n, empresas, arrAcciones);
    venta(acciones, medio+1, fin, IBd, suma, arrEmpresas, n, empresas, arrAcciones);
    
}

void compra(int acciones[N], int inicio, int fin, double IBd, int &suma, char arrEmpresas[N], int &n, char empresas[N], int arrAcciones[N]){
    if(inicio == fin){
        if(acciones[inicio]<=IBd){
            suma += acciones[inicio];
            arrEmpresas[n] = empresas[inicio];
            arrAcciones[n] = acciones[inicio];
            n++;
        }
        return;
    }
    int medio = (inicio + fin)/2;
    compra(acciones, inicio, medio, IBd, suma, arrEmpresas, n, empresas, arrAcciones);
    compra(acciones, medio+1, fin, IBd, suma, arrEmpresas, n, empresas, arrAcciones);
    
}

void tomarDecision(char empresas[N], int acciones[M][N], int n,int m, double IBm){
    cout.precision(3);
    cout<<fixed;
    for(int i=0;i<m; i++){
        char arrEmpresas[N]{};
        int monto = 0, numAcciones = 0, arrAcciones[N]{};
        double IBd;
        IBd = calcularIBd(acciones[i], n);
        // comprar: precios <= IBd
        //vender: precios > IBd
        if(IBd>IBm){
            venta(acciones[i], 0, n-1, IBd, monto, arrEmpresas, numAcciones, empresas, arrAcciones);
            cout<<i+1<<" "<<right<<setw(8)<<IBd<<setw(8)<<"Vende"<<setw(5)<<monto<<"  ";
        }
        else{
            compra(acciones[i], 0, n-1, IBd, monto, arrEmpresas, numAcciones, empresas, arrAcciones);
            cout<<i+1<<" "<<right<<setw(8)<<IBd<<setw(8)<<"Compra"<<setw(5)<<monto<<"  ";
        }
        mergeSort(arrEmpresas, arrAcciones, 0, numAcciones-1);
        for(int j=0; j<numAcciones; j++){
            cout <<arrEmpresas[j]<<" ";
        }
        cout<<endl;
    }
}

int main(int argc, char** argv) {
    char empresas[N] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    int acciones[M][N] = {{8, 4, 5, 6, 7, 1, 2},
                          {3, 4, 5, 7, 1, 2, 6},
                          {5, 6, 5, 2, 1, 6, 8},
                          {3, 4, 5, 6, 2, 1, 9},
                          {3, 4, 5, 4, 5, 3, 2},
                          {3, 4, 4, 8, 9, 7, 6}};
    int n = 7, m = 6;
    double IBm = 4.2;
    tomarDecision(empresas, acciones, n, m, IBm);
    return 0;
}

