/* 
 * File:   main.cpp
 * Author: PC
 *
 * Created on 7 de abril de 2024, 11:35
 */

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
#define N 4

void cargaBin(int num, int n, int arr[]){
    for(int i=0; i<n;i++) arr[i] = 0;
    int i=0, aux;
    while(num>0){
        aux = num % 2;
        arr[i] = aux;
        num = num / 2;
        i++;
    }
}

int main(int argc, char** argv) {
    int p = 100, n = 4, max = 0, peso;
    int pesos[][N]={{20,20,20,20},
                    {10,30,10,30},
                    {10,10,10,10},
                    {15,15,15,15}};
    int valores[][N] = {{10,10,10,50},
                        {80,10,10,20},
                        {20,20,20,20},
                        {50,50,50,50}};
    int cromo1[n], cromo2[n], cromo3[n], cromo4[n], mejorPeso[n][n]{}, maxValo[n][n]{};
    int opcion = pow(2,n);
    for(int i=0; i<opcion; i++){
        
        cargaBin(i,n, cromo1);
        for(int j=0; j<opcion; j++){
            cargaBin(j, n, cromo2);
            for(int k=0; k<opcion; k++){
                cargaBin(k, n, cromo3);
                for(int h = 0; h<opcion; h++){
                    cargaBin(h, n, cromo4);
                    int pParcial = 0, ValParcial = 0;
                    int solPeso[n][n]{}, solVal[n][n]{};
                    //cromo 1
                    for(int l = 0; l<n; l++){
                        if(cromo1[l] == 1){
                            pParcial += pesos[0][l];
                            ValParcial += valores[0][l];
                            solPeso[0][l] = pesos[0][l];
                            solVal[0][l] = valores[0][l];
                        }
                    }

                    //cromo 2
                    for(int l = 0; l<n; l++){
                        if(cromo2[l] == 1){
                            pParcial += pesos[1][l];
                            ValParcial += valores[1][l];
                            solPeso[1][l] = pesos[1][l];
                            solVal[1][l] = valores[1][l];
                        }
                    }
                    
                    //cromo 3
                    for(int l = 0; l<n; l++){
                        if(cromo3[l] == 1){
                            pParcial += pesos[2][l];
                            ValParcial += valores[2][l];
                            solPeso[2][l] = pesos[2][l];
                            solVal[2][l] = valores[2][l];
                        }
                    }
                    
                    //cromo 4
                    for(int l = 0; l<n; l++){
                        if(cromo4[l] == 1){
                            pParcial += pesos[3][l];
                            ValParcial += valores[3][l];
                            solPeso[3][l] = pesos[3][l];
                            solVal[3][l] = valores[3][l];
                        }
                    }
                    
                     if(pParcial == p){
                        if(max<ValParcial){
                            max =ValParcial;
                            peso = pParcial;
                            
                            for(int q = 0; q<n; q++){
                                for(int t = 0; t<n; t++){
                                    mejorPeso[q][t] = solPeso[q][t];
                                    maxValo[q][t] = solVal[q][t];
                                }
                            }
                        }
                    }
                }
                
            }
        }
    }
    
    //impresion
    cout<<"Pesos Finales: "<<endl;
    for(int q = 0; q<n; q++){
        for(int t = 0; t<n; t++){
            cout<<right<<setw(2)<<mejorPeso[q][t]<<" ";
        }
        cout<<endl;
    }
    cout<<peso<<endl;
    
    cout<<"Valores Finales: "<<endl;
    for(int q = 0; q<n; q++){
        for(int t = 0; t<n; t++){
            cout<<right<<setw(2)<<maxValo[q][t]<<" ";
        }
        cout<<endl;
    }
    cout<<max<<endl;
    
    return 0;
}

