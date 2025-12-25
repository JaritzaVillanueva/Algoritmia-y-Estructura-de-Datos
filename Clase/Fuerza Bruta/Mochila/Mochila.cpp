/* 
 * File:   Mochila.cpp
 * Author: Jaritza
 * Codigo: 20213699
 * Created on 30 de agosto de 2023, 12:49 PM
 */

#include <iostream>
#include <cmath>
using namespace std;

void cargaBin(int num,int cromo[],int n){
    int res, i=0;
    for(int k=0;k<n;k++) cromo[k] = 0;
    
    while(num>0){
        res = num % 2;
        num = num/2;
        cromo[i]=res;
        i++;
    }
}

int main(){
    const int n = 5; 
    int peso = 15, maxpeso = 0, mcomb, opcion, pfinal;
    int cromo[n];
    int paq[] = {1,2,4,12,1};
    
    opcion = (int)pow(2,n);
    for(int i=0;i<opcion;i++){
        int pparcial = 0;
        cargaBin(i, cromo, n);
        for(int j=0;j<n;j++){
            pparcial += (cromo[j]*paq[j]);
        }
        if(maxpeso<=pparcial && pparcial<=peso){
            maxpeso = pparcial;
            mcomb = i;
            pfinal = pparcial;
            cout<<mcomb<<endl;
        }
    }
    
    cout<<"La solucion es: "<<mcomb<<endl;
    cargaBin(mcomb, cromo, n);
    for(int k=0; k<n; k++) cout <<cromo[k]*paq[k]<<" ";
    cout<<endl;
    cout<<"Peso final :"<<pfinal;
    return 0;
}