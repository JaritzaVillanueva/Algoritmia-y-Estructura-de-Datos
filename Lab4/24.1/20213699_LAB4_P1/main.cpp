/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * NOMBRE: Jaritza Maribel Villanueva Huaraca
 * CODIGO: 20213699
 * Created on 1 de junio de 2024, 08:13
 */



#include <iostream>
using namespace std;
#include "funcionesArbolesBB.h"
#include "ArbolBinarioBusqueda.h"
#include "funcionesArbolesBinarios.h"

void plantarArbolBinarioNodo(struct NodoArbol *&raiz, struct NodoArbol * arbolIzquierdo,
                         int elemento, struct NodoArbol * arbolDerecho){
    
    struct NodoArbol * nuevoNodo = crearNuevoNodoArbol(arbolIzquierdo, elemento, arbolDerecho);
    raiz = nuevoNodo;
}

void recorrerAmplitud(struct NodoArbol *nodoAbb, struct NodoArbol *nodoAB, int nivel, struct NodoArbol *&result){
    if(esNodoVacio(nodoAbb)) return;
    if(nivel == 1){
        int sumaNodos = numeroNodosRecursivo(nodoAB);
        int numHojas = numeroHojasRecursivo(nodoAB);
        int elemento = nodoAbb->elemento + sumaNodos - numHojas;
        if(esNodoVacio(result)){
            plantarArbolBinarioNodo(result,nullptr,elemento, nullptr);
        }
    }
    else if(nivel>1){
        recorrerAmplitud(nodoAbb->izquierda, nodoAB->izquierda, nivel-1, result->izquierda);
        recorrerAmplitud(nodoAbb->derecha, nodoAB->derecha, nivel-1, result->derecha);
    }
}


void aplicar_arbol(struct ArbolBinarioBusqueda abb, struct ArbolBinario ab, struct ArbolBinario &result){
    int alturaABB = altura(abb.arbolBinario);
    
    for(int i=1; i<=alturaABB+1; i++){
        recorrerAmplitud(abb.arbolBinario.raiz, ab.raiz, i, result.raiz);
    }
}

bool recorrerRecusivoABB(struct NodoArbol * nodo){
    if(esNodoVacio(nodo))
        return true;
    if (not esNodoVacio(nodo->izquierda)){
        if(nodo->izquierda->elemento > nodo->elemento) return false;
    }
    if (not esNodoVacio(nodo->derecha)){
        if(nodo->derecha->elemento < nodo->elemento) return false;
    }
    return recorrerRecusivoABB(nodo->izquierda) and recorrerRecusivoABB(nodo->derecha);
}

bool verificarABB(struct ArbolBinario ab){
    recorrerRecusivoABB(ab.raiz);
}

bool verificarNumeroNodosPar(struct ArbolBinario ab){
    int sumNodos = sumarNodos(ab);
    if(sumNodos % 2 == 0) return true;
    else return false;
}

bool determinar_anomalias(ArbolBinario ab){
    bool esABB = verificarABB(ab);
    bool esNodoPar = verificarNumeroNodosPar(ab);
    return esABB and esNodoPar;
}

int main() {
    
    //creacion del arbol_paquetes
    ArbolBinarioBusqueda arbol_paquetes;
    construir(arbol_paquetes);
    //primer caso
//    plantarArbolBB(arbol_paquetes.arbolBinario.raiz, nullptr, 5, nullptr);
//    insertar(arbol_paquetes, 3);
//    insertar(arbol_paquetes, 9);
    
    //segundo caso
    plantarArbolBB(arbol_paquetes.arbolBinario.raiz, nullptr, 6, nullptr);
    insertar(arbol_paquetes, 3);
    insertar(arbol_paquetes, 9);
    
    //creacion del arbol_sistema
    ArbolBinario arbol_sistema;
    construir(arbol_sistema);
    
    //creacion de nodos para crear el AB
    NodoArbol *n1, *n2, *n3, *n4, *n5, *n6;
    n1 = crearNuevoNodoArbol(nullptr, 2, nullptr);
    n2 = crearNuevoNodoArbol(nullptr, 3, nullptr);
    n3 = crearNuevoNodoArbol(n1, 7, n2);
    n4 = crearNuevoNodoArbol(nullptr, 8, nullptr);
    plantarArbolBinario(arbol_sistema, n3, 1, n4); 
    
    //funcion b)
    ArbolBinario arbol_resultados;
    construir(arbol_resultados);
    aplicar_arbol(arbol_paquetes, arbol_sistema, arbol_resultados);
    
    //funcion c)
//    recorrerEnOrden(arbol_resultados);
    if(determinar_anomalias(arbol_resultados)){
        cout<<"SIN EVENTOS SOSPECHOSOS"<<endl;
    } else cout<<"ANOMALIA DETECTADA"<<endl;
    return 0;
}

