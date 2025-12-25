/* 
 * Proyecto: EX2_P1_23.1
 * File:   main.cpp
 * Author: Jaritza
 * Codigo: 20213699
 * Created on 30 de noviembre de 2023, 11:47 PM
 */

#include <iostream>
#include "ArbolBinarioBusqueda.h"
#include "funcionesArbolesBB.h"
#include "ArbolBinario.h"
#include "funcionesArbolesBinarios.h"
using namespace std;

void insertarRecur(struct NodoArbol *& raiz, int elemento){
    if(raiz == nullptr)
        plantarArbolBB(raiz, nullptr, elemento, nullptr);
    else{
        if(buscaArbolRecursivo(raiz, elemento)){
            int max;
            max = maximoABBRecursivo(raiz);
            elemento += max;
        }
        
        if (raiz->elemento > elemento)
            insertarRecursivo(raiz->izquierda, elemento);
        else
            insertarRecursivo(raiz->derecha, elemento);
    }
}

void rotacionIzq(struct NodoArbol *& p){
    NodoArbol *sup = p;
    p = p->derecha;
    sup->derecha = p->izquierda;
    p->izquierda = sup;
}
void rotacionDer(struct NodoArbol *& p){
    NodoArbol *sup = p;
    p = p->izquierda;
    sup->izquierda = p->derecha;
    p->derecha = sup;
}
                    
struct NodoArbol * balancear_recursivo(struct NodoArbol *& raiz){
    if(raiz != nullptr){
        raiz->izquierda = balancear_recursivo(raiz->izquierda);
        raiz->derecha = balancear_recursivo(raiz->derecha);
        
        int altIzq = alturaRecursivo(raiz->izquierda);
        int altDer = alturaRecursivo(raiz->derecha);
        int dif = abs(altDer-altIzq);
        if(dif>1){
            if(altDer<altIzq){
                if(alturaRecursivo(raiz->izquierda->izquierda) >= alturaRecursivo(raiz->izquierda->derecha)){
                    rotacionDer(raiz);
                }
                else{
                    rotacionIzq(raiz->izquierda);
                    rotacionDer(raiz);
                }
            }
            else{
               if(alturaRecursivo(raiz->derecha->derecha) >= alturaRecursivo(raiz->derecha->izquierda)){
                        rotacionIzq(raiz);
               }
               else{
                  rotacionDer(raiz->derecha);
                  rotacionIzq(raiz);
               }
            }
        }
    }
    return raiz;
}

void balancea_arbol(struct ArbolBinarioBusqueda &arbol){
    struct NodoArbol *p = arbol.arbolBinario.raiz;
    p = balancear_recursivo(p);
    arbol.arbolBinario.raiz = p;
}

void sumaParciales(struct NodoArbol * A1, struct NodoArbol * A2, struct NodoArbol * &Resul){
    if(A1 && A2){
        plantarArbolBB(Resul, nullptr, A1->elemento+A2->elemento, nullptr);
        sumaParciales(A1->izquierda, A2->izquierda, Resul->izquierda);
        sumaParciales(A1->derecha, A2->derecha, Resul->derecha);
    }
    else if(A1){
        plantarArbolBB(Resul, nullptr, A1->elemento, nullptr);
        sumaParciales(A1->izquierda, A2, Resul->izquierda);
        sumaParciales(A1->derecha, A2, Resul->derecha);
    }
    else if(A2){
        plantarArbolBB(Resul, nullptr, A2->elemento, nullptr);
        sumaParciales(A1, A2->izquierda, Resul->izquierda);
        sumaParciales(A1, A2->derecha, Resul->derecha);
    }
    else return;
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

bool suma_Arboles(struct ArbolBinarioBusqueda arbol1, struct ArbolBinarioBusqueda arbol2){
    struct ArbolBinarioBusqueda arbolResul;
    construir(arbolResul);
    sumaParciales(arbol1.arbolBinario.raiz, arbol2.arbolBinario.raiz, arbolResul.arbolBinario.raiz);
    
    enOrden(arbolResul);
    cout<<endl;
    if(verificaABB(arbolResul.arbolBinario.raiz)) return true;
    else return false;
    
}

int main(int argc, char** argv) {
    struct ArbolBinarioBusqueda token, sistema1, sistema2;
    construir(token);
    
    insertarRecur(token.arbolBinario.raiz, 2);
    insertarRecur(token.arbolBinario.raiz, 5);
    insertarRecur(token.arbolBinario.raiz, 2);
    insertarRecur(token.arbolBinario.raiz, 1);
    insertarRecur(token.arbolBinario.raiz, 5);
    insertarRecur(token.arbolBinario.raiz, 6);
    insertarRecur(token.arbolBinario.raiz, 3);
    insertarRecur(token.arbolBinario.raiz, 4);
    
    balancea_arbol(token);
    enOrden(token);
    cout<<endl;
    
    construir(sistema1);
    insertarRecursivo(sistema1.arbolBinario.raiz, 4);
    insertarRecursivo(sistema1.arbolBinario.raiz, 1);
    insertarRecursivo(sistema1.arbolBinario.raiz, 2);
    insertarRecursivo(sistema1.arbolBinario.raiz, 3);
    insertarRecursivo(sistema1.arbolBinario.raiz, 6);
    insertarRecursivo(sistema1.arbolBinario.raiz, 5);
    insertarRecursivo(sistema1.arbolBinario.raiz, 7);
    enOrden(sistema1);
    cout<<endl;
    
    construir(sistema2);
    insertarRecursivo(sistema2.arbolBinario.raiz, 3);
    insertarRecursivo(sistema2.arbolBinario.raiz, 1);
    insertarRecursivo(sistema2.arbolBinario.raiz, 2);
    insertarRecursivo(sistema2.arbolBinario.raiz, 5);
    insertarRecursivo(sistema2.arbolBinario.raiz, 4);
    insertarRecursivo(sistema2.arbolBinario.raiz, 6);
    insertarRecursivo(sistema2.arbolBinario.raiz, 7);
    enOrden(sistema2);
    cout<<endl;
    
    if(suma_Arboles(token, sistema2)) cout<<"Acceso otorgado"<<endl;
    else cout<<"Acceso denegado"<<endl;
    return 0;
}

