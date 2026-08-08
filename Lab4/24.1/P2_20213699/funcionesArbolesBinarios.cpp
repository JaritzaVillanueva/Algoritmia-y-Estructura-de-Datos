/* 
 * File:   funcionesArbolesBB.cpp
 * Author: ANA RONCAL
 * Created on 19 de septiembre de 2023, 10:46 AM
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include "ArbolBinario.h"
#include "Libro.h"
using namespace std;
#include "funcionesArbolesBinarios.h"

void construir(struct ArbolBinario & arbol){
    arbol.raiz = nullptr;
}

bool esNodoVacio(struct NodoArbol * nodo){
    return nodo == nullptr;
}

bool esArbolVacio(const struct ArbolBinario & arbol){
    return esNodoVacio(arbol.raiz);
}

struct NodoArbol * crearNuevoNodoArbol(struct NodoArbol * izquierdo, 
                               const char*cad, int elem, struct NodoArbol * derecho){
    struct NodoArbol * nuevoNodo = new struct NodoArbol;
    nuevoNodo->elemento.nivel = elem;
    nuevoNodo->elemento.titulo = new char[strlen(cad)+1];
    strcpy(nuevoNodo->elemento.titulo, cad);
    nuevoNodo->izquierda = izquierdo;
    nuevoNodo->derecha = derecho;
    int cant = 1;
    if(nuevoNodo->izquierda != nullptr) cant+=nuevoNodo->izquierda->numNodo;
    if(nuevoNodo->derecha != nullptr) cant+=nuevoNodo->derecha->numNodo;
    nuevoNodo->numNodo = cant;
    return nuevoNodo;
}

void plantarArbolBinario(struct ArbolBinario & arbol, struct NodoArbol * izquierdo,
                         const char*cad, int elem, struct NodoArbol * derecho){
    
    struct NodoArbol * nuevoNodo = crearNuevoNodoArbol(izquierdo, cad, elem, derecho);
    arbol.raiz = nuevoNodo;
    arbol.raiz->numNodo = nuevoNodo->numNodo; 
}

void plantarArbolBinario(struct ArbolBinario & arbol, struct ArbolBinario & arbolIzquierdo,
                         const char*cad, int elem, struct ArbolBinario & arbolDerecho){
    
    struct NodoArbol * nuevoNodo = crearNuevoNodoArbol(arbolIzquierdo.raiz, cad, elem, arbolDerecho.raiz);
    arbol.raiz = nuevoNodo;
    arbol.raiz->numNodo = nuevoNodo->numNodo; 
}

struct Libro raiz(struct NodoArbol * nodo){
    if (esNodoVacio(nodo)){
        cout<<"No se puede obtener ra�z de un �rbol vacio"<<endl;
        exit(1);
    }
    return nodo->elemento;
}

struct NodoArbol * hijoDerecho(const struct ArbolBinario & arbol){
    if (esArbolVacio(arbol)){
        cout<<"No se puede obtener ra�z de un �rbol vacio"<<endl;
        exit(1);
    }
    return arbol.raiz->derecha;
}

struct  NodoArbol * hijoIzquierdo(const struct ArbolBinario & arbol){
    if (esArbolVacio(arbol)){
        cout<<"No se puede obtener ra�z de un �rbol vacio"<<endl;
        exit(1);
    }
    
    return arbol.raiz->izquierda;
 }

void imprimeRaiz(const struct ArbolBinario & arbol){
    imprimeNodo(arbol.raiz);
}

void imprimeNodo(struct NodoArbol * nodo){
    cout<<left<<setw(13)<<nodo->elemento.titulo<<" "<<nodo->elemento.nivel<<", ";
}

void recorrerEnOrdenRecursivo(struct NodoArbol * nodo){
    if(not esNodoVacio(nodo)){
        recorrerEnOrdenRecursivo(nodo->izquierda);
        imprimeNodo(nodo);
        recorrerEnOrdenRecursivo(nodo->derecha);
    }
}

/*En árbol, se lleva a cabo visitando el hijo izquierdo del nodo, luego el nodo
 luego todos los restantes, comenzando por la raíz*/
void recorrerEnOrden(const struct ArbolBinario & arbol){
    /*Imprime en orden*/
    recorrerEnOrdenRecursivo(arbol.raiz);
    
}

void recorrerEnPreOrdenRecursivo(struct NodoArbol * nodo){
    if(not esNodoVacio(nodo)){
        imprimeNodo(nodo);
        recorrerEnPreOrdenRecursivo(nodo->izquierda);
        recorrerEnPreOrdenRecursivo(nodo->derecha);
    }
}

/*recorrido descendente, se lleva a cabo visitando cada nodo, seguido de sus hijos,
 luego todos los restantes, comenzando por la raíz*/
void recorrerPreOrden(const struct ArbolBinario & arbol){
    recorrerEnPreOrdenRecursivo(arbol.raiz);
   
}

void recorrerEnPostOrdenRecursivo(struct NodoArbol * nodo){
    if(not esNodoVacio(nodo)){
        recorrerEnPostOrdenRecursivo(nodo->izquierda);
        recorrerEnPostOrdenRecursivo(nodo->derecha);
        imprimeNodo(nodo);
    }
}

/*recorrido ascendente, se lleva a cabo visitando los hijos, y luego el nodo
 luego todos los restantes, comenzando por la raíz*/
void recorrerPostOrden(const struct ArbolBinario & arbol){
  
    recorrerEnPostOrdenRecursivo(arbol.raiz);
    
}

int maximo(int a, int b){
    return a>=b ? a: b;
}

int alturaRecursivo(struct NodoArbol * nodo){
    if(esNodoVacio(nodo))
        return 0;
    else if(esNodoVacio(nodo->izquierda) and esNodoVacio(nodo->derecha))
        return 0; 
    else
        return 1 + maximo( alturaRecursivo(nodo->izquierda), alturaRecursivo(nodo->derecha));
}

int altura(const struct ArbolBinario & arbol){
    return alturaRecursivo(arbol.raiz); //como el arbol ha sido construido no va apuntar a nullptr
}

int numeroNodosRecursivo(struct NodoArbol * nodo){
    if(esNodoVacio(nodo))
        return 0;
    else
        return 1 + numeroNodosRecursivo(nodo->izquierda) + numeroNodosRecursivo(nodo->derecha);   
}

/*Determina el número de elementos del árbol*/
int numeroNodos(const struct ArbolBinario & arbol){
    return numeroNodosRecursivo(arbol.raiz);
}

int numeroHojasRecursivo(struct NodoArbol * nodo){
    if(esNodoVacio(nodo))
        return 0;
    else if ( esNodoVacio(nodo->izquierda) and esNodoVacio(nodo->derecha) )
        return 1;
    else
        return numeroHojasRecursivo(nodo->izquierda) + numeroHojasRecursivo(nodo->derecha);
}

int numeroHojas(const struct ArbolBinario & arbol){
    return numeroHojasRecursivo(arbol.raiz);
}

int esEquilibradoRecursivo(struct NodoArbol * nodo){
    if(esNodoVacio(nodo))
        return 1;
    else{
        int alturaHijoIzquierdo = alturaRecursivo(nodo->izquierda);
        int alturaHijoDerecho = alturaRecursivo(nodo->derecha);
        int diferencia = abs(alturaHijoIzquierdo - alturaHijoDerecho);
        return diferencia<=1 and 
               esEquilibradoRecursivo(nodo->izquierda) and 
               esEquilibradoRecursivo(nodo->derecha);
    }        
}

int esEquilibrado(const struct ArbolBinario & arbol ){
    return esEquilibradoRecursivo(arbol.raiz);
}

int esHoja(const struct ArbolBinario & arbol){
    if(esArbolVacio(arbol))
        return 0;
    else
        return esNodoVacio(arbol.raiz->izquierda) and esNodoVacio(arbol.raiz->derecha);
}

void destruirArbolBinario(struct ArbolBinario & arbol){
    destruirRecursivo(arbol.raiz, nullptr);
    arbol.raiz->numNodo--;
    arbol.raiz = nullptr;
}

void destruirRecursivo(struct NodoArbol * nodo, struct NodoArbol * padre){
    if(not (esNodoVacio(nodo))){
        
        destruirRecursivo(nodo->izquierda, nodo);
        if(padre != nullptr){
            padre->numNodo--;
        }
        destruirRecursivo(nodo->derecha, nodo);
        if(padre != nullptr){
            padre->numNodo--;
        }
        delete nodo;
    }
}


