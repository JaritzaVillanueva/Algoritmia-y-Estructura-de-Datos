/* 
 * File:   funcionesAuxiliares.cpp
 * Author: Jaritza
 * Codigo: 20213699
 * Created on 31 de mayo de 2024, 11:21 AM
 */

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include "ArbolBinarioBusqueda.h"
#include "funcionesArbolesBinarios.h"
#include "funcionesABB.h"
#include "funcionesAuxiliares.h"


int nodoHoja(NodoArbol *nodo){
    if(esNodoVacio(nodo))
        return 0;
    else
        return esNodoVacio(nodo->izquierda) and esNodoVacio(nodo->derecha);
}

//insertar iterativo
void insertarElemento(ArbolBinarioBusqueda &abb, int e){
    NodoArbol *rec = abb.arbolBinario.raiz, *ant = nullptr, *nuevoNodo, *extra;
    plantarArbolBB(nuevoNodo, nullptr, e, nullptr);
    if(esArbolVacio(abb.arbolBinario)){
        abb.arbolBinario.raiz = nuevoNodo;
    }
    else{
        while(rec != nullptr){
            //si el recorrido es menor que elemento
            if(rec->elemento < e){
                if(nodoHoja(rec)){
                    rec->derecha = nuevoNodo;
                    break;
                }
                else{
                    if(rec->derecha == nullptr){
                        rec->derecha = nuevoNodo;
                        break;
                    }
                    if(rec->derecha->elemento > e){
                        nuevoNodo->derecha = rec->derecha;
                        rec->derecha = nuevoNodo;
                        break;
                    }
                    ant = rec;
                    rec = rec->derecha;
                }
            }
            //si el recorrido es mayor que elemento
            else{
                if(nodoHoja(rec)){
                    rec->izquierda = nuevoNodo;
                    break;
                }
                else{
                    if(rec->izquierda->elemento < e){
                        nuevoNodo->izquierda = rec->izquierda;
                        rec->izquierda = nuevoNodo;
                        break;
                    }
                    ant = rec;
                    rec = rec->izquierda;
                }
            }
        }
    }
}

//insertar iterativo
void insertar2(ArbolBinarioBusqueda &abb, int e){
    NodoArbol *p, *q, *pq;
    plantarArbolBB(p, nullptr, e, nullptr);
    if(esArbolVacio(abb.arbolBinario)){
        abb.arbolBinario.raiz = p;
    }
    else{
        q = abb.arbolBinario.raiz;
        pq=nullptr;
        while(q != nullptr){
            pq = q;
            if(q->elemento > e){
                q = q->izquierda;
            }else{
                q = q->derecha;
            }
        }
        //colocar el nodo
        if(pq->elemento > e){
            pq->izquierda = p;
        }
        else{
            pq->derecha = p;
        }
    }
}

//insertar recursivo
void insertarRecursivo1(NodoArbol *&p, int e){
    if(esNodoVacio(p)){
        plantarArbolBB(p, nullptr, e, nullptr);
        return;
    }
    else{
        if(p->elemento<e){
            insertarRecursivo1(p->derecha, e);
        }
        else insertarRecursivo1(p->izquierda, e);
    }
}
void inserta1(ArbolBinarioBusqueda &abb, int e){
    insertarRecursivo1(abb.arbolBinario.raiz, e);
}

//buscarElemento
void buscarElemento(ArbolBinarioBusqueda &abb, int e){
    NodoArbol *p;
    if(esArbolVacio(abb.arbolBinario)){
        cout<<"El arbol es vacio"<<endl;
    }
    else{
        p = abb.arbolBinario.raiz;
        while(p != nullptr){
            if(p->elemento == e){
                cout<<"Se encontro el numero"<<endl;
                return;
            }
            else if(p->elemento < e){
                p = p->derecha;
            }
            else p = p->izquierda;
        }
        cout<<"No se encontro el numero"<<endl;
    }
}

//buscar Mayor

int mayorElemento(NodoArbol *p){
    if(p->derecha == nullptr){
        return p->elemento;
    }
    return mayorElemento(p->derecha);
}

//altura

int alturaABB(ArbolBinarioBusqueda abb){
    return alturaRec(abb.arbolBinario.raiz);
}

int alturaRec(NodoArbol *p){
    if(esNodoVacio(p)) return 0;
    else if(p->derecha == nullptr && p->izquierda == nullptr){
        return 0;
    }
    else
        return 1 + maximoRec(alturaRec(p->izquierda), alturaRec(p->derecha));
}

int maximoRec(int a, int b){
    if(a>=b) return a;
    else return b;
}

//imprimir amplitud recursion
void imprimirAmplitud(ArbolBinarioBusqueda abb){
    int altura = alturaABB(abb);
    for(int i=1; i<=altura; i++){
        amplituRecursivo(abb.arbolBinario.raiz, i);
        cout<<endl; // se para la impresion por niveles
    }
}

void amplituRecursivo(NodoArbol *p, int nivel){
    if( p == nullptr) return;
    if (nivel == 1){
        cout<< p->elemento<<" ";
    }else if(nivel>1){
        amplituRecursivo(p->izquierda, nivel-1);
        amplituRecursivo(p->derecha, nivel-1);
    }
}