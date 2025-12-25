/* 
 * Archivo:   main.cpp
 * Autor: Jaritza
 * Código: 20213699
 * Created on 3 de noviembre de 2023, 11:38
 */

#include <iostream>

#include "funcionesArbolesBB.h"
#include "ArbolBinarioBusqueda.h"
#include "funcionesArbolesBinarios.h"

using namespace std;

//funcion adicional

int minimoLote(struct NodoArbol *nodo){
    if(esNodoVacio(nodo)) exit(1);
    if(esNodoVacio(nodo->izquierda)){
        return nodo->lote;
    }
    minimoLote(nodo->izquierda);
}

struct NodoArbol *minimoRecursivo(struct NodoArbol * nodo){
    if(esNodoVacio(nodo)){
        return NULL;
    }
    if(esNodoVacio(nodo->izquierda))
        return nodo;
    minimoABBRecursivo(nodo->izquierda);
}

struct NodoArbol * buscarNodo(struct NodoArbol * nodo, int dato){
    if(esNodoVacio(nodo)){
        return NULL;
    } 
    if(comparaABB(nodo->lote, dato) == 0)
        return nodo;
    if(comparaABB(nodo->lote, dato) == 1)
        return buscarNodo(nodo->izquierda, dato);
    else
        if(comparaABB(nodo->lote, dato) == -1) return buscarNodo(nodo->derecha, dato);
}

void fusionarRecursion(struct NodoArbol *nodo1, struct NodoArbol *nodo2){
    
    struct NodoArbol *aux;
    int lote, cant;
    aux = nodo2;
    
    //caso base
    if(nodo2 == NULL) return;
    if(aux){
        fusionarRecursion(nodo1, aux->izquierda);
        fusionarRecursion(nodo1, aux->derecha);
        
        lote = aux->lote;
        cant = aux->cant;
        
        struct NodoArbol *p;
        p=buscarNodo(nodo1, lote);
        if(p){
            p->cant += cant;
        }
        else{
            insertarRecursivo(nodo1, lote, cant);
        }
        nodo2 = NULL;
    }
}

void fusion(struct ArbolBinarioBusqueda &A, struct ArbolBinarioBusqueda &B){
    if(numeroNodos(A.arbolBinario)>numeroNodos(B.arbolBinario)){
        fusionarRecursion(A.arbolBinario.raiz, B.arbolBinario.raiz);
        B.arbolBinario.raiz = NULL;
    }
    else{
        fusionarRecursion(B.arbolBinario.raiz, A.arbolBinario.raiz);
        A.arbolBinario.raiz = NULL;
    }
} 

void despacharRecursion (struct NodoArbol *&nodo, int cant){
    int falta, lote;
    struct NodoArbol *aux;
    if(cant == 0)  return; // caso base
    aux = nodo;
    aux = minimoRecursivo(aux);
    if(aux->cant <= cant){
        falta = cant - aux->cant;
        lote = aux->lote;
        nodo = borraNodoRecursivo(nodo, lote);
        despacharRecursion(nodo, falta);
    }
    else aux->cant = aux->cant - cant;
}

void despachar(struct ArbolBinarioBusqueda &A, int cant){
    despacharRecursion(A.arbolBinario.raiz, cant);
}

//main
int main() {
    struct ArbolBinarioBusqueda A, B;
    construir(A);
    construir(B);
    
    insertar(A, 20180211, 20);
    insertar(A, 20170810, 20);
    insertar(A, 20180409, 10);
    insertar(A, 20170620, 20);
    
    insertar(B, 20180211, 10);
    insertar(B, 20170811, 5);
    insertar(B, 20180410, 15);
    
    cout<<"Impresion INORDEN"<<endl;
    cout<<"Arbol A:"<<endl;
    enOrden(A);
    cout<<"Arbol B:"<<endl;
    enOrden(B);
    cout<<endl;
    cout<<"Impresion PREORDEN"<<endl;
    cout<<"Arbol A:"<<endl;
    preOrden(A);
    cout<<"Arbol B:"<<endl;
    preOrden(B);
    
    cout<<endl<<endl;
    fusion(A,B);
    enOrden(A);
    
    cout<<endl<<endl;
    cout<< minimoLote(A.arbolBinario.raiz)<<endl;
    
    despachar(A, 35);
    
    return 0;
}

