/* 
 * Proyecto: Pregunta_2
 * File:   main.cpp
 * Author: Jaritza
 * Codigo: 20213699
 * Created on 25 de marzo de 2024, 10:20 AM
 */

#include <iostream>
#include <cmath>
using namespace std;
#define N 12
#define M 4
#define H 24

void cargaBin(int num, int n, int arr[]){
    int i=0, aux;
    while(num>0){
        aux = num % 2;
        arr[i] = aux;
        num = num / 2;
        i++;
    }
}

int main() {
    int cromo[N]{};
    int pedidos[N][M] = {{100,4,8,2},{101,2,10,2},{102,3,10,2},{103,1,13,2},{104,3,15,2},
    {105,1,10,2},{106,4,16,1},{107,2,8,2},{108,3,14,1},{109,2,18,2},{110,1,18,2},{111,4,14,2}};
    int n =12, cantPed1, cantPed2, cantPed3, cantPed4, hayCruce=0;
    // dos estados: entregan o no entregan
    int comb = pow(2, n);
    for(int i=1; i<comb; i++){
        cargaBin(i, n, cromo);
        cantPed1 = 0, cantPed2 = 0, cantPed3 = 0, cantPed4 = 0;
        //para evitar que existan cruces se inicializa horas
        int horas[H]{};
        // k es el pedido
        for(int k = 0; k<n; k++){
            if(cromo[k] == 1){
                if(pedidos[k][1] == 1) cantPed1++;
                if(pedidos[k][2]==2) cantPed2++;
                if(pedidos[k][3]==3) cantPed3++;
                if (pedidos[k][4]==4) cantPed4++;
                //para que me interesa la hora,la iteracion comienza desde la hora de inicio
                for(int l=pedidos[k][2]; l < pedidos[k][2] + pedidos[k][3];l++){
                    if(horas[l] == 0) horas[l] = 1;
                    else hayCruce = 1;
                    break;
                }
            }
            if( hayCruce == 1) break;
        }
        //Verifica la condicion
        if(cantPed1>=2 && cantPed2>=2 && cantPed3>=1 && cantPed4>=1 && hayCruce == 0){
            cout<<"Solucion"<<i+1<<endl;
            for( int j=0; j< n; j++){
                if(cromo[j]==1){
                    cout<<pedidos[j][0]<<" "<<pedidos[j][1]<<endl;
                }
            }
        }
    }
    
    return 0;
}

