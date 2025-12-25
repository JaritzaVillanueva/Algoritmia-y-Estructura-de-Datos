/* 
 * Proyecto: Lab1_2019-2_Preg1
 * File:   main.cpp
 * Author: Jaritza
 * Codigo: 20213699
 * Created on 30 de agosto de 2023, 10:07 PM
 */

#include <iostream>
#include <cmath>
using namespace std;

void cargarBin(int num, int cromo[], int n){
    int res, i=0;
    for(int j=0; j<n; j++) cromo[j]=0;
    while(num>0){
        res=num%2;
        num=num/2;
        cromo[i]=res;
        i++;
    }
}

int main() {
    int n=8, preds, comb, opcion;
    double costoParcial, costoMAX = 0, costo=250, gananciaMAX = 0, ganancia;
    int proy[][6]={{1,80,150,0,0,0}, {2,20,80,0,0,0}, {3,100,300,1,2,0}, {4,100,150,0,0,0}, 
    {5,50,80,0,0,0}, {6,10,50,2,0,0}, {7,50,120,6,0,0}, {8,50,150,6,0,0}};
    int cromo[n], cromoFinal[n];
    
    opcion = (int)pow(2,n);
    for(int i=0;i<opcion;i++){
        cargarBin(i, cromo, n);
        costoParcial =0;
        ganancia =0;
        
        for(int j=0;j<n;j++){
            costoParcial += cromo[j]*proy[j][1];
            ganancia += cromo[j]*proy[j][2];
            if(costoParcial>costo) break;
            else {
                if (proy[j][3] != 0 and cromo[j]==1){
                    if(cromo[proy[j][3]-1]== 0 and proy[j][3] != 0) break;
                    if(cromo[proy[j][4]-1]== 0 and proy[j][4] != 0) break;
                    if(cromo[proy[j][5]-1]== 0 and proy[j][5] != 0) break;
                }
                if(ganancia>gananciaMAX){
                    gananciaMAX = ganancia;
                    for(int k=0;k<n;k++) cromoFinal[k]=cromo[k];
                }
                
            }
        }
        if(costoParcial>=costoMAX and ganancia>=gananciaMAX and costoParcial<=costo){
            costoMAX=costoParcial;
            gananciaMAX=ganancia;
            for(int k=0;k<n;k++){
                cromoFinal[k]=cromo[k];
            }
        }
        
    }
    cout<<"La mejor solucion es con los proyectos: ";
    for(int i=0;i<8;i++){
        if(cromoFinal[i]==1)cout<<i+1<<" ";
    }
    cout<<"La mejor ganancia es: "<<gananciaMAX;
    return 0;
}

