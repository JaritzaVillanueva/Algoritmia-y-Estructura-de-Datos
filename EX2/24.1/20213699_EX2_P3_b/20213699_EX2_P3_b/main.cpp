/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 6 de julio de 2024, 09:00
 */

#include <iostream>

#include "Lista.h"
#include "funcionesLista.h"

using namespace std;


void mover(struct Nodo *&rec, int &num){
    if(num == 0) return;
    rec = rec->siguiente;
    num--;
    mover(rec, num);
}

void reduccionPersonal(Lista &empleados, int num){
    int cant = longitud(empleados);
    Nodo *rec = empleados.cabeza;
    while(empleados.longitud != 1){ //O(longitud)
        int k = num-1;
        mover(rec, k); // O(1)
        Nodo *eliminar = rec;
        rec = rec->siguiente;
        eliminaNodo(empleados, eliminar->elemento);
    }
    cout<<"En una lista de "<<cant<<" empleados, para k = "<<num<<", el elegido es: ";
    imprime(empleados);
}

int main() {
    Lista empleados;
    construir(empleados);
    for(int i=0; i<5; i++){
        insertarAlFinal(empleados, i+1);
    }
    reduccionPersonal(empleados, 2);
    
    Lista empleados1;
    construir(empleados1);
    for(int i=0; i<7; i++){
        insertarAlFinal(empleados1, i+1);
    }
    reduccionPersonal(empleados1, 3);
    
    Lista empleados2;
    construir(empleados2);
    for(int i=0; i<10; i++){
        insertarAlFinal(empleados2, i+1);
    }
    reduccionPersonal(empleados2, 7);
    return 0;
}

