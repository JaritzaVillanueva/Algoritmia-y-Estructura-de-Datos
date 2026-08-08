/* 
 * File:   main.cpp
 * Author: PC
 *
 * Created on 21 de abril de 2024, 14:38
 */

#include <iostream>
using namespace std;
#include "Lista.h"
#include "Nodo.h"
#include "funciones.h"

void fusionar(Lista& lista1, Lista& lista2) {
    Nodo* nodo1 = lista1.cabeza;
    Nodo* nodo2 = lista2.cabeza;
    Nodo *ptr, *lista;
    
    //listas vacias
    if(esListaVacia(lista1)){
        lista1.cabeza = lista2.cabeza;
        lista1.longitud = lista2.longitud;
        return;
    }else if(esListaVacia(lista2)){
        return;
    }else{
        //Verificar inicio
        if (nodo1->elemento < nodo2->elemento){
            ptr = nodo1;
            nodo1 = nodo1->siguiente;
            lista = ptr;
        }
        else if(nodo1->elemento > nodo2->elemento){
            ptr = nodo2;
            nodo2 = nodo2->siguiente;
            lista = ptr;
        }
        else{
            ptr = nodo1;
            nodo1 = nodo1->siguiente;
//            nodo2 = nodo2->siguiente;
            lista = ptr;
        }
        int n = 1;
        //procesar los demas datos
        while (nodo1 != nullptr && nodo2 != nullptr) {

            if (nodo1->elemento < nodo2->elemento) {
                ptr->siguiente=nodo1;
                nodo1 = nodo1->siguiente;
            } else if (nodo1->elemento > nodo2->elemento) {
                ptr->siguiente=nodo2;
                nodo2 = nodo2->siguiente;
            } else { // Si los elementos son iguales, avanzar ambos nodos
                ptr->siguiente=nodo1;
                nodo1 = nodo1->siguiente;
//                nodo2 = nodo2->siguiente;
            }
            ptr = ptr->siguiente;
            n++;
        }

        // Agregar los elementos restantes de lista1
        while (nodo1 != nullptr) {
            ptr->siguiente = nodo1;
            nodo1 = nodo1->siguiente;
            ptr = ptr->siguiente;
            n++;
        }
    //    // Agregar los elementos restantes de lista2
        while (nodo2 != nullptr) {
            ptr->siguiente = nodo2;
            nodo2 = nodo2->siguiente;
            ptr = ptr->siguiente;
            n++;
        }

        // Asignar la nueva cabeza y longitud a la lista original
        lista1.cabeza = lista;
        lista1.longitud = n;
    }
}



void recursion(Nodo*& lista1, Nodo*& lista2) {
    // Caso base: lista1 es vacía, simplemente asignamos la lista2 a lista1
    if (lista1 == nullptr) {
        lista1 = lista2;
        return;
    }
    // Caso base: lista2 es vacía, no hay nada que hacer
    if (lista2 == nullptr) {
        return;
    }

    // Seleccionar el nodo con el menor elemento como el siguiente nodo
    if (lista1->elemento < lista2->elemento) {
        // Avanzar a la siguiente posición de lista1
        recursion(lista1->siguiente, lista2);
    } else if (lista1->elemento > lista2->elemento) {
        // Avanzar a la siguiente posición de lista2 y asignar el nodo actual como la cabeza de lista1
        Nodo* temp = lista2->siguiente;
        lista2->siguiente = lista1;
        lista1 = lista2;
        // Llamar recursivamente con la nueva lista1 y la lista2 restante
        recursion(lista1->siguiente, temp);
    } else {
        // Si los elementos son iguales, avanza lista 1 y llamar recursivamente
        recursion(lista1->siguiente, lista2);
    }
}

void fusionRecursion(Lista& lista1, Lista& lista2){
    recursion(lista1.cabeza, lista2.cabeza);
}

int main(int argc, char** argv) {
    Lista lunes, martes, miercoles, jueves, viernes;
    construir(lunes);
    construir(martes);
    construir(miercoles);
    construir(jueves);
    construir(viernes);
    //
    insertarAlFinal(lunes, 8, 6);
    insertarAlFinal(lunes, 10, 14);
    insertarAlFinal(lunes, 12, 1);
    //
    insertarAlFinal(martes,9, 3);
    insertarAlFinal(martes, 11, 8);
    //
    insertarAlFinal(miercoles, 8, 2);
    insertarAlFinal(miercoles, 9, 5);
    insertarAlFinal(miercoles, 10, 10);
    //
    insertarAlFinal(jueves, 14, 13);
    insertarAlFinal(jueves, 15, 9);
    insertarAlFinal(jueves, 16, 11);
    //
    insertarAlFinal(viernes, 17, 4);
    insertarAlFinal(viernes, 18, 12);
    insertarAlFinal(viernes, 19, 7);
    
    fusionRecursion(lunes, martes);
    fusionRecursion(lunes, miercoles);
    fusionRecursion(lunes, jueves);
    fusionRecursion(lunes, viernes);
    imprime(lunes);
    return 0;
}
