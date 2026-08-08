/* 
 * File:   main.cpp
 * Author: PC
 *
 * Created on 4 de mayo de 2024, 23:32
 */

#include <iostream>
using namespace std;
#define N 36

int posibleCodigo(int registo[N],int lineas[N], int inicio, int fin, int numReg){
//    if (inicio>fin) return 0;
    if (inicio == fin){
        if(numReg == registo[inicio]) return lineas[inicio];
        else return 0;
    }
    int medio = (inicio+fin)/2;
    int codIzq = posibleCodigo(registo, lineas, inicio, medio, numReg);
    int codDer = posibleCodigo(registo, lineas, medio+1, fin, numReg);
    return codIzq + codDer;
}

int main() {
    int registo[N] = {-1, -2, -3, -4, -5, -6, -7, -8, 1,-9, 2, -10, -11, 1, 2, -12, -13, -14, -15, -16, -17, 1, -18, -19, -20, 1, 2, -21, -22, -23};
    int lineas[N] = {10, 5, 8, 9, 8, 1, 10,5,2,8,2,3, 4, 2, 1, 4, 8, 1, 1, 2, 4, 3, 5, 3, 8, 3, 3, 8, 5, 3};
    int n = 36, r1 = 1, r2 = 2;
    //registro 1
    int reg1 = posibleCodigo(registo, lineas, 0, n-1, r1);
    //registro 2
    int reg2 = posibleCodigo(registo, lineas, 0, n-1, r2);
    
    cout<<"Para el virus de registro 1, se obtienen "<<reg1<<" coincidencias en total."<<endl;
    cout<<"Para el virus de registro 2, se obtienen "<<reg2<<" coincidencias en total."<<endl;
    if(reg1 == 0 && reg2 == 0){
        cout<<"Por lo que se considera que el archivo no cuenta con coidog malicioso"<<endl;
    }else{
        if(reg1 == reg2){
            cout<<"Por lo que se considera que el archivo cuenta con código malicioso, específicamente de ambos virus de registros."<<endl;
        }
        else{
            cout<<"Por lo que se considera que el archivo cuenta con código malicioso, específicamente del virus de registro ";
            if(reg1>reg2) cout<<r1<<endl;
            else cout<<r2<<endl;
        }
    }
    return 0;
}

