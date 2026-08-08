/* 
 * File:   main.cpp
 * Author: Jaritza
 *
 * Created on 15 de mayo de 2024, 19:09
 */

#include <iostream>
#include <cmath>
using namespace std;
#define N 3
#define M 12

void cargaBin(int num, int arr[], int n, int base){
    for(int i=0; i<n; i++)arr[i] = 0;
    int i=0, aux;
    while(num>0){
        aux = num % base;
        arr[i] = aux;
        num = num / base;
        i++;
    }
}

bool estaTipoArma(int guerrero[], int tipo){
    for(int i=1; i<4; i++){
        if(guerrero[i] == tipo) return true;
    }
    return false;
}

bool verificar(int guerrero[N][4],char armaCar[M],int arma[M][2],
        char requisito[M][3], int m, int n, int cromo[M]){
    int sumPoder[n]{};
    for(int i=0; i<m; i++){
        if(cromo[i] != 0) sumPoder[cromo[i]-1] += arma[i][0];
        if(cromo[i]>0){
            if(!estaTipoArma(guerrero[cromo[i]-1], arma[i][1])) return false;
        }
        
        for(int j=0; j<n; j++){
            if(requisito[i][j] == '0') break;
            if(cromo[i]>0){
                for(int k=0; k<i ; k++){
                    if(requisito[i][j] == armaCar[k]){
                        if(cromo[i] != cromo[k]) return false;
                    }
                }
            }
        }
    }
    for(int i =0; i<n; i++){
        if(guerrero[i][0] > sumPoder[i]) return false;
    }
    return true;
}

int main() {
    int guerrero[N][4] ={{120, 2, 0, 0},
                          {160, 1, 3, 0},
                          {80, 3, 0, 0}};
    char armaCar[M]={'Z', 'P', 'R', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L'};
    int arma[M][2]= {{60, 3}, {80,1},{38,2}, {25, 2}, {49, 2}, {57, 1}, {68, 3},
    {35, 2}, {62, 2}, {42, 2}, {36, 1}, {54, 3}};
    char requisito[M][3] = {{'0', '0', '0'},
                          {'Z', '0', '0'},
                          {'0', '0', '0'},
                          {'R', '0', '0'},
                          {'0', '0', '0'},
                          {'0', '0', '0'},
                          {'0', '0', '0'},
                          {'Z', 'E', '0'},
                          {'R', '0', '0'},
                          {'0', '0', '0'},
                          {'Z', '0', '0'},
                          {'0', '0', '0'}};
    //Solucion del problema
    int m = 12, n = 3, solucion = 0, cromo[M];
    int opcion = pow(n+1, m);
    for(int i=0; i<opcion; i++){
        cargaBin(i, cromo, m, n+1);
        //Verificacion de la combinacion
        if(verificar(guerrero,armaCar,arma,requisito, m,n, cromo)){
            solucion = i ;
            break;
        }
    }
    
    //imprimir respuesta
    if(solucion!=0){
        cargaBin(solucion, cromo, m, n+1);
        for(int i=0; i<n; i++){
            cout<<"Guerrero "<<i+1<<endl;
            cout<<"Poder: "<<guerrero[i][0]<<endl;
            cout<<"Armas en mochila para vencerlo: ";
            for(int j=0; j<m; j++){
                if(cromo[j] == i+1){
                    cout<<armaCar[j]<<" ";
                }
            }
            cout<<endl;
        }
    }
    else cout<<"No existe solucion"<<endl;
    return 0;
}

