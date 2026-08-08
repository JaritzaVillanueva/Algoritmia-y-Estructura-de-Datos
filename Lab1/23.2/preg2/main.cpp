/* 
 * File:   main.cpp
 * Author: Jaritza Villanueva
 *
 * Created on 24 de marzo de 2024, 20:00
 */

#include <iostream>
#include <cmath>
using namespace std;
#define N 8
#define MAX 40

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
    int control[][5] ={{32,0,0,0,60},{8,0,0,0,32},{40,1,2,0,120},{40,0,0,0,60},
    {20,0,0,0,32},{4,2,0,0,20},{16,6,0,0,48},{16,6,0,0,60}};
    int cromo[N]{}, MaxSolucion[N]{};
    int p = 100, opcion, n = 8, max=0;
    
    cout<<"soluciones:"<<endl;
    opcion = pow(2,n);
    for(int i = 1; i<opcion; i++){
        bool NoCumple = false;
        cargaBin(i, n, cromo);
        int inversion = 0, beneficio = 0;
        for(int j = 0; j<n ; j++){
            inversion += control[j][0]*cromo[j];
            beneficio += control[j][4]*cromo[j];
            //verificar si tiene requisitos
            if (cromo[j] == 1 && control[j][1] != 0){
                if(control[j][1] != 0 && cromo[control[j][1]-1] == 0){
                    NoCumple = true;
                    break;
                }
                if(control[j][2] != 0 && cromo[control[j][2]-1] == 0){
                    NoCumple = true;
                    break;
                }
                if(control[j][3] != 0 && cromo[control[j][3]-1] == 0){
                    NoCumple = true;
                    break;
                }
            }
        }
        
        //impresion de todas las soluciones
        if(NoCumple == false){
            if(inversion == p){
                cout<<"solucion "<<i<<endl;
                for(int k=0; k < n; k++){
                    if(cromo[k] == 1) cout<<k+1<<" ";
                }
                cout<<endl;
                cout<<"Beneficio: "<<beneficio*1000;
                cout<<endl;
                if(max<beneficio){
                    max = beneficio;
                    for(int k=0; k<n; k++) MaxSolucion[k] = cromo[k];
                }
            }
        }
    }
    for(int i=0; i<MAX; i++) cout.put('-');
    cout<<endl;
    cout<<"La solucion con mayor ganancia:";
    for(int i=0;i<n;i++){
        if(MaxSolucion[i] == 1) cout<<i+1<<" ";
    }
    cout<<endl;
    cout<<"Beneficio maximo: "<<max*1000;
    return 0;
}

