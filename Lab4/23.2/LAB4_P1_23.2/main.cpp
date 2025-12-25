/* 
 * Proyecto: LAB4_2023_2
 * File:   main.cpp
 * Author: Jaritza
 * Codigo: 20213699
 * Created on 29 de noviembre de 2023, 11:25 PM
 */

#include <iostream>

#include "ArbolBinarioBusqueda.h"
#include "funcionesArbolesBB.h"
#include "ArbolBinario.h"
#include "funcionesArbolesBinarios.h"
#include "NodoArbol.h"
using namespace std;

struct NodoArbol * busca_primer_ancestro_comun(struct NodoArbol * raiz, int numMenor, int numMay){
    
    if(esNodoVacio(raiz))
        return nullptr;
    if (numMenor < raiz->elemento && numMay < raiz->elemento){
        return busca_primer_ancestro_comun(raiz->izquierda, numMenor, numMay);
    }
    else if(numMenor>raiz->elemento && numMay>raiz->elemento){
        return busca_primer_ancestro_comun(raiz->derecha, numMenor, numMenor);
    }
    else{
        return raiz;
    }
}

void insertarAB_Izq(struct NodoArbol * &raiz, int elemento){
   struct NodoArbol * nuevoNodo = crearNuevoNodoArbol(nullptr, elemento, nullptr);
   raiz->izquierda = nuevoNodo;
}

void insertarAB_Der(struct NodoArbol * &raiz, int elemento){
    
   struct NodoArbol * nuevoNodo = crearNuevoNodoArbol(nullptr, elemento, nullptr);
   raiz->derecha = nuevoNodo;
}

void suma_parcial (struct NodoArbol * &p, struct NodoArbol * q){
    if(!esNodoVacio(p)){
        suma_parcial(p->izquierda, q->izquierda);
        if(!esNodoVacio(q)){
            p->elemento = p->elemento + q->elemento;
        }
        else{
            p->elemento = p->elemento + 0;
        }
        suma_parcial(p->derecha, q->derecha);
    }
}

bool verificaABB(struct NodoArbol * pR){
    if(pR){
        if((pR->izquierda && pR->elemento <= pR->izquierda->elemento) || 
                (pR->derecha && pR->elemento >= pR->derecha->elemento)) return false;
        else return verificaABB(pR->izquierda) && verificaABB(pR->derecha);
    }
    else{
        return true;
    }
}

bool suma_parcial_arboles(struct ArbolBinarioBusqueda arbol1, struct ArbolBinario arbol2,
        struct NodoArbol * comun){
    
    suma_parcial(comun, arbol2.raiz);
    
    return verificaABB(comun);
}

int main() {
    struct ArbolBinarioBusqueda arbolToken;
    struct ArbolBinario arbolSistema;
    struct NodoArbol *comun, *PIzq, * PDer;
    construir(arbolToken);
    insertarRecursivo(arbolToken.arbolBinario.raiz, 5);
    insertarRecursivo(arbolToken.arbolBinario.raiz, 2);
    insertarRecursivo(arbolToken.arbolBinario.raiz, 1);
    insertarRecursivo(arbolToken.arbolBinario.raiz, 3);
    insertarRecursivo(arbolToken.arbolBinario.raiz, 4);
    insertarRecursivo(arbolToken.arbolBinario.raiz, 12);
    insertarRecursivo(arbolToken.arbolBinario.raiz, 8);
    insertarRecursivo(arbolToken.arbolBinario.raiz, 18);
    recorrerEnPreOrdenRecursivo(arbolToken.arbolBinario.raiz);
    cout<<endl;
    
    int numMenor=1, numMay = 4;
    comun = busca_primer_ancestro_comun(arbolToken.arbolBinario.raiz, numMenor, numMay);
    
    if(comun != NULL){
        cout<<"El primer ancestro comun: "<<comun->elemento<<endl;
    }
    
    construir(arbolSistema);
    plantarArbolBinario(arbolSistema, NULL, 4, NULL);
    
    //llenar el lado izquierdo del arbol binario
    insertarAB_Izq(arbolSistema.raiz, -2);
    PIzq = arbolSistema.raiz->izquierda; //2
    insertarAB_Izq(PIzq, -3);
    insertarAB_Der(PIzq, -1);
    insertarAB_Der(PIzq->derecha, 0);
    
    //llenar el lado derecho del arbol binario
    insertarAB_Der(arbolSistema.raiz, 6);
    PDer = arbolSistema.raiz->derecha; //6
    insertarAB_Izq(PDer, 5);
    insertarAB_Der(PDer, 7);
    
    bool validacion;
    
    validacion = suma_parcial_arboles(arbolToken, arbolSistema, comun);
    
    if(validacion){
        cout<<"Acceso otorgado"<<endl;
    }
    else{
        cout<<"Acceso denegado"<<endl;
    }
    
    return 0;
}

