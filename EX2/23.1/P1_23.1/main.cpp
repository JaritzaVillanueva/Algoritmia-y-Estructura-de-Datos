/* 
 * File:   main.cpp
 * Author: PC
 *
 * Created on 4 de julio de 2024, 10:44
 */

#include <iostream>

#include "ArbolBinarioBusqueda.h"
#include "funcionesArbolesBinarios.h"
#include "funcionesArbolesBB.h"
using namespace std;
#define N 10

struct NodoArbol * rotacionDerecha(struct NodoArbol * nodo){
    NodoArbol * nodoIzq = nodo->izquierda;
    nodo->izquierda = nodoIzq->derecha;
    nodoIzq->derecha = nodo;
    return nodoIzq;
}

struct NodoArbol * rotacionIzquierda(struct NodoArbol * nodo){
    NodoArbol * nodoDer = nodo->derecha;
    nodo->derecha = nodoDer->izquierda;
    nodoDer->izquierda = nodo;
    return nodoDer;
}

struct NodoArbol * rotacionDobleDerecha(struct NodoArbol * nodo){
    nodo->izquierda = rotacionIzquierda(nodo->izquierda);
    return rotacionDerecha(nodo);
}

struct NodoArbol * rotacionDobleIzquierda(struct NodoArbol * nodo){
    nodo->derecha = rotacionDerecha(nodo->derecha);
    return rotacionIzquierda(nodo);
}

struct NodoArbol * balancearNodo(struct NodoArbol * nodo){
    int altIzq = alturaRecursivo(nodo->izquierda);
    int altDer = alturaRecursivo(nodo->derecha);
    int diferencia = altIzq - altDer;
    
    if(diferencia > 1){
        if(alturaRecursivo(nodo->izquierda->izquierda) >= alturaRecursivo(nodo->izquierda->derecha)){
            nodo = rotacionDerecha(nodo);
        }else{
            nodo = rotacionDobleDerecha(nodo);
        }
    }else if(diferencia < -1){
        if(alturaRecursivo(nodo->derecha->derecha) >= alturaRecursivo(nodo->derecha->izquierda)){
            nodo = rotacionIzquierda(nodo);
        }else{
            nodo = rotacionDobleIzquierda(nodo);
        }
    }
    
    return nodo;
}

void insertarABB(struct ArbolBinarioBusqueda &arbol, int e){
    if(esArbolVacio(arbol)){
        plantarArbolBB(arbol.arbolBinario.raiz, nullptr, e, nullptr);
        return;
    }
    if(buscaArbol(arbol, e)){
        int maximo = maximoNodoABB(arbol);
        e += maximo;
    }
    NodoArbol * nuevo = crearNuevoNodoArbol(nullptr, e, nullptr);
    insertar(arbol, e);
}

struct NodoArbol * balancearArbol(struct NodoArbol * raiz){
    if(raiz == nullptr){
        return nullptr;
    }
    raiz->izquierda = balancearArbol(raiz->izquierda);
    raiz->derecha = balancearArbol(raiz->derecha);
    
    raiz = balancearNodo(raiz);
    return raiz;
}

int main() {
    ArbolBinarioBusqueda token;
    construir(token);
    insertarABB(token, 2);
    insertarABB(token, 5);
    insertarABB(token, 2);
    insertarABB(token, 1);
    insertarABB(token, 5);
    insertarABB(token, 6);
    insertarABB(token, 3);
    insertarABB(token, 4);
    recorrerEnOrden(token.arbolBinario);
    token.arbolBinario.raiz = balancearArbol(token.arbolBinario.raiz);
    
    return 0;
}

