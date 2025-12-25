/* 
 * File:   funcionesLista.cpp
 * Author: Jaritza
 * Codigo: 20213699
 * Created on 1 de abril de 2024, 10:50 AM
 */

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include "Lista.h"
#include "Nodo.h"
#include "funcionesLista.h"

void construir(struct Lista & tad){
    tad.cabeza = nullptr;
    tad.longitud = 0;
}

const bool esListaVacia(const struct Lista & tad){
    return tad.cabeza == nullptr;
}

void insertarAlInicio(struct Lista & tad, int elemento){
    struct Nodo * nuevoNodo = new struct Nodo;
    nuevoNodo->elemento = elemento;
    nuevoNodo->siguiente = tad.cabeza;
    
    tad.cabeza = nuevoNodo;
    tad.longitud++;
}

void insertarAlFinal(struct Lista & tad, int elemento){
    
}

void imprime(struct Lista tad){
    cout.precision(2);
    cout<<fixed;
    if(esListaVacia(tad)){
       cout<<"La lista esta vacia no se puede mostrar"<<endl; 
    }
    else{
        struct Nodo * ptr = tad.cabeza;
        int estaImprimiendoLaCabeza = 1;
        cout<<"[";
        
        while(ptr != nullptr){
            if(!estaImprimiendoLaCabeza) cout <<", ";
            estaImprimiendoLaCabeza = 0;
            cout<<ptr->elemento;
            ptr = ptr->siguiente;
        }
        cout<< "] "<<endl;
    }
}