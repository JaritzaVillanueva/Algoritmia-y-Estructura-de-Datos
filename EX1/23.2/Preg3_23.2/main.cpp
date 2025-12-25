/* 
 * Proyecto: Preg3_23.2
 * File:   main.cpp
 * Author: Jaritza
 * Codigo: 20213699
 * Created on 6 de mayo de 2024, 10:51 AM
 */

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include "funcionesLista.h"
#include "funcionesPila.h"
#include "funcionesCola.h"
#include "Cola.h"
#include "Lista.h"
#include "Pila.h"

void apilarFaja(Cola &faja,Pila &pilaPrincipal,Pila &pilaAux1,Pila &pilaAux2){
    int aux, cont;
    while(!esColaVacia(faja)){
        int peso = desencolar(faja);
        cont = 0; //contador de movimientos al momento de desapila la pila principaly lo apilo al aux1
        //caso para apilar el elemento
        //1. pila vacia : se apila directamente
        //2. no esta vacia
        //puede que la cima sea menor o igual al elemento que se va a ingresar
        if(peso<=cima(pilaPrincipal) || esPilaVacia(pilaPrincipal)){
            apilar(pilaPrincipal, peso);
        }
        else{
            while(!esPilaVacia(pilaPrincipal) && peso>cima(pilaPrincipal)){
                aux = desapilar(pilaPrincipal);
                apilar(pilaAux1, aux);
                if(cont>0){
                    hanoi(cont, pilaAux2, pilaAux1, pilaPrincipal);
                }
                //contabilizo el numero de elementos que se encuentran en el aux1
                cont++;
                hanoi(cont, pilaAux1, pilaAux2, pilaPrincipal);
            }
            apilar(pilaPrincipal, peso);
            hanoi(cont, pilaAux2, pilaPrincipal, pilaAux1);
        }
    }
}

void hanoi2(int n,Pila &origen, Pila &destino,Pila &aux1,Pila &aux2){
    if(n == 0){
       return; 
    }
    if(n== 1){
        apilar(destino, desapilar(origen));
        return;
    }
    hanoi2(n-2, origen, aux1, aux2, destino);
    //se sacan 2 elemento y se utilizan las otras 2 pilas como auxiliares
    apilar(aux2, desapilar(origen));
    apilar(destino, desapilar(origen));
    apilar(aux1, desapilar(aux2));
    hanoi2(n-2, aux1, destino, origen, aux2);
}

void apilar2(Cola &faja,Pila &pilaPrincipal,Pila &pilaAux1,Pila &pilaAux2, Pila &pilaAux3){
    int peso, cont, aux;
    while(!esColaVacia(faja)){
        peso = desencolar(faja);
        cont = 0;
        if(esPilaVacia(pilaPrincipal) || peso =cima(pilaPrincipal)){
            apilar(pilaPrincipal, peso);
        }
        else{
            while(!esPilaVacia(pilaPrincipal) && peso>cima(pilaPrincipal)){
                aux = desapilar(pilaPrincipal);
                apilar(pilaAux1, aux);
                if(cont>0){
                    hanoi2(cont, pilaAux2, pilaAux1, pilaPrincipal, pilaAux3);
                }
                cont++;
                hanoi2(cont, pilaAux1, pilaAux2, pilaPrincipal, pilaAux3);
            }
            apilar(pilaPrincipal, peso);
            //siempre vamos a ordenar a aux2 y luego se pasa a la principal ya ordenado
            hanoi2(cont, pilaAux2, pilaPrincipal, pilaAux1, pilaAux3);
        }
    }
}

int main(int argc, char** argv) {
    Cola faja;
    Pila pilaPrincipal, pilaAux1, pilaAux2, pilaAux3;
    construir(faja);
    encolar(faja, 2);
    encolar(faja, 8);
    encolar(faja, 10);
    encolar(faja, 8);
    encolar(faja, 5);
    encolar(faja, 3);
    cout<<"La faja es: ";
    imprime(faja);
    
    construir(pilaPrincipal);
    construir(pilaAux1);
    construir(pilaAux2);
    construir(pilaAux3);
    
    apilarFaja(faja, pilaPrincipal, pilaAux1, pilaAux2);
    apilar2(faja, pilaPrincipal, pilaAux1, pilaAux2, pilaAux3);
    return 0;
}

