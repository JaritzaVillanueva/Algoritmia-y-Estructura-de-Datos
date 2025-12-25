/* 
 * Proyecto: Lab1_2019-1
 * File:   main.cpp
 * Author: Jaritza
 * Codigo: 20213699
 * Created on 30 de agosto de 2023, 01:28 PM
 */

#include <iostream>
#include <cmath>
using namespace std;

void cargarBin(int num, int cromo[], int n){
    int res, i=0;
    for(int k=0; k<n; k++) cromo[k]=0;
    while(num>0){
        res = num%2;
        num=num/2;
        cromo[i]=res;
        i++;
    }
}

int main() {
    int paq[][2] = {{8,15}, {2,20}, {10,5}, {10,10}, {5,8}, {5,5}};
    int n = 6, pparcial, pesoMax = 0, opcion, peso, comb;
    int cromo[n];
    double maxGanancia = 0, ganancia;
    
    cout<<"Ingresa valor del peso definido: ";
    cin>>peso;
    
    opcion = (int)pow(2,n);
    for(int i=0;i<opcion;i++){
        pparcial = 0;
        ganancia = 0.0;
        cargarBin(i, cromo, n);
        for(int j=0; j<n; j++){
            pparcial += (paq[j][0]*cromo[j]);
            ganancia += (paq[j][1]*cromo[j]);
        }
        if(pparcial>=pesoMax and ganancia>=maxGanancia and pparcial<=peso){
            pesoMax=pparcial;
            comb=i;
            maxGanancia = ganancia;
        }
    }
    
    cout<<"La solucion es: "<<endl;
    cout<<"Articulos: ";
    cargarBin(comb, cromo, n);
    for(int i=0; i<n; i++) {
        if(cromo[i]==1) cout<<i+1<<" ";
    }
    cout<<endl;
    cout<<"Ganancia Total: "<<maxGanancia<<endl;
    return 0;
}

