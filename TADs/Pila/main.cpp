/* 
 * File:   main.cpp
 * Author: cueva.r
 *
 * Created on 25 de septiembre de 2023, 12:30 PM
 */
#include "funcionesPila.h"
#include "Pila.h"

using namespace std;

void pasapila(Pila &pila1,Pila &pila2){
    int valor,aux,n;
    
    while(!esPilaVacia(pila1)){
        valor = desapilar(pila1);
        n=0;
        while(!esPilaVacia(pila1)){
            apilar(pila2,valor);
            valor = desapilar(pila1);
            n++;
        }
        while(!esPilaVacia(pila2) && n>0){
            aux = desapilar(pila2);
            apilar(pila1,aux);
            n--;
        }
        apilar(pila2,valor);
    }
}


int main(int argc, char** argv) {
    
    Pila pila1,pila2;
    construir(pila1);
    construir(pila2);
    
    apilar(pila1,20);
    apilar(pila1,15);
    apilar(pila1,10);
    apilar(pila1,5);
    apilar(pila1,2);
    
    imprimir(pila1);
    

    return 0;
}

