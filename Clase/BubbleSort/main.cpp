/* 
 * File:   main.cpp
 * Author: PC
 *
 * Created on 16 de mayo de 2024, 21:57
 */

#include <iostream>
using namespace std;
#include "Lista.h"
#include "funciones.h"

void bubleMenorMayor(Lista &L1){
    if (esListaVacia(L1)) return;

    for (int i = 0; i < L1.longitud - 1; ++i) {
        bool cambio = false;
        Nodo* anterior = nullptr;
        Nodo* actual = L1.cabeza;

        while (actual->siguiente != nullptr) {
            Nodo* siguiente = actual->siguiente;

            if (actual->elemento > siguiente->elemento) {
                // Intercambiar nodos
                if (anterior == nullptr) {
                    L1.cabeza = siguiente;
                } else {
                    anterior->siguiente = siguiente;
                }
                actual->siguiente = siguiente->siguiente;
                siguiente->siguiente = actual;

                // Actualizar punteros
                anterior = siguiente;
                cambio = true;
            } else {
                // Avanzar al siguiente nodo
                anterior = actual;
                actual = siguiente;
            }
        }

        if (!cambio) break;
    }
}

int main(int argc, char** argv) {
    Lista lista;
    construir(lista);
    insertarAlFinal(lista, 89);
    insertarAlFinal(lista, 46);
    insertarAlFinal(lista, 68);
    insertarAlFinal(lista, 50);
    insertarAlFinal(lista, 29);
    insertarAlFinal(lista, 34);
    insertarAlFinal(lista, 17);
    imprime(lista);
    bubleMenorMayor(lista);
    imprime(lista);
    return 0;
}

