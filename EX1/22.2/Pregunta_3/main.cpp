/* 
 * Proyecto: Pregunta_3
 * File:   main.cpp
 * Author: Jaritza
 * Codigo: 20213699
 * Created on 22 de abril de 2024, 09:31 AM
 */

#include <iostream>
#include <cmath>
using namespace std;
#include "Cola.h"
#include "Lista.h"
#include "Nodo.h"
#include "Pila.h"
#include "funcionesCola.h"
#include "funcionesLista.h"
#include "funcionesPila.h"

bool esPrimo(int num){
    for(int i=2; i<=sqrt(num); i++){
        if(num % i == 0) return false;
    }
    return true;
}

Lista generaListaCriba(int n){
    Lista lista;
    construir(lista);
    for(int i=2; i<=n; i++){
        insertarAlFinal(lista, i);
    }
    return lista;
}

void recursion(Nodo * ptr){
    if(ptr == nullptr) return;
    
    Nodo *p = ptr;
    Cola tachado;
    if(esPrimo(ptr->elemento)){
        Nodo *temp = ptr, *q;
        q = temp->siguiente;
        p = p->siguiente;
        
        while(p != nullptr){
            if(p->elemento % temp->elemento == 0) {
                encolar(tachado, p->elemento);
                q->siguiente = p->siguiente;
            }
            p = p->siguiente;
        }
        recursion(temp->siguiente);
    }
    else{
        int num = ptr->elemento;
        encolar(tachado, num);
        recursion(ptr->siguiente);
    }
}

void cribaAlgoritmo(Lista &criba){
    recursion(criba.cabeza);
}

int main() {
    Lista criba;
    int n = 15;
    criba = generaListaCriba(n);
    cribaAlgoritmo(criba);
    return 0;
}

