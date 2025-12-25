/* 
 * Proyecto: LAB5_P1_21.1
 * File:   main.cpp
 * Author: Jaritza
 * Codigo: 20213699
 * Created on 1 de diciembre de 2023, 02:52 PM
 */

#include <iostream>
using namespace std;

int maxG = 0;
int matGanancia[10][12];
int solParcial[12];
int tamArr[10];
int indG = 0;
int indSol = 0;

int calculoMax(int i,int n,int ganancia[],int gParcial){
    if(i >= n){
        if(gParcial>maxG){
            maxG = gParcial;
            indSol = 0;
            for(int j=0; j<indG; j++){
                matGanancia[indSol][j]=solParcial[j];
            }
            tamArr[indSol]=indG;
            indSol++;
        }
        else if(gParcial == maxG){
            for(int j=0; j<indG; j++){
                matGanancia[indSol][j] = solParcial[j];
            }
            tamArr[indSol]=indG;
            indSol++;
        }
        return 0;
    }
    
    solParcial[indG++] = i;
    
    if(calculoMax(i+3, n, ganancia, gParcial + ganancia[i])) return 1;
    else{
        indG--;
        calculoMax(i+1, n, ganancia, gParcial);
    }
    return 0;
}

int main() {
    int ganancia[] = {3,6,1,2,4,5,18,10,13,7,15,2};
    int n = 12;
    calculoMax(0,n,ganancia, 0);
    cout<<maxG<<endl;
    for(int i=0;i<indSol;i++){
        for(int j=0; j<tamArr[i]; j++){
            cout<<"Proyecto "<<matGanancia[i][j]+1<<": "<<ganancia[matGanancia[i][j]]<<" k"<<endl;
        }
        cout<<endl;
    }
}

