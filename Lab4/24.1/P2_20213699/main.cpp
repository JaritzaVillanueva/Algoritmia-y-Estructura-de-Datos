/* 
 * File:   main.cpp
 * NOMBRE: Jaritza Maribel Villanueva Huaraca
 * CODIGO: 20213699
 * Created on 3 de julio de 2024, 22:06
 */

#include <iostream>
#include <cstring>
using namespace std;
#include "NodoArbol.h"
#include "ArbolBinario.h"
#include "funcionesArbolesBinarios.h"
#include "Cola.h"
#include "funcionesCola.h"

bool verificarPrincipal(struct NodoArbol * ptr){
    return strcmp(ptr->elemento.titulo, "Principal") == 0 && ptr->elemento.nivel == 10;
}

void recorrerAmplitud(struct NodoArbol * raiz){
    if(raiz == nullptr) return;
    Cola cola;
    construir(cola);
    int aux = 0, principal;
    if(verificarPrincipal(raiz)){
        cout<<"El nivel es: "<<aux<<endl;
        return;
    }
    encolar(cola, raiz);
    encolar(cola, nullptr);
    while(longitud(cola)>1){
        struct NodoArbol * temp = desencolar(cola);
        if(temp != nullptr){
            if(verificarPrincipal(temp)){
                principal = aux;
            }
            imprimeNodo(temp);
            //añadir hijos
            if(temp->izquierda != nullptr) encolar(cola, temp->izquierda);
            if(temp->derecha != nullptr) encolar(cola, temp->derecha);
        }else{
            cout<<endl;
            encolar(cola, temp);
            aux++;
        }
    }
    cout<<endl;
    cout<<"El nivel es: "<<principal<<endl;
}

void eliminarErrores(struct NodoArbol * &raiz, int lado){
    if(lado == 0){
//        raiz->numNodo -= raiz->izquierda->numNodo;
        destruirRecursivo(raiz->izquierda, raiz);
        raiz->izquierda = nullptr;
    }
    else{
//        raiz->numNodo -= raiz->derecha->numNodo; 
        destruirRecursivo(raiz->derecha, raiz);
        raiz->derecha = nullptr;
    }
    raiz->numNodo--;
}

int main() {
    ArbolBinario libro;
    construir(libro);
    NodoArbol * s111, * s112, *s11, *s12, *c1;
    
    s111 = crearNuevoNodoArbol(nullptr, "Seccion1.1.1", 4, nullptr);
    s112 = crearNuevoNodoArbol(nullptr, "Seccion1.1.2", 2, nullptr);
    s11 = crearNuevoNodoArbol(s111, "Seccion1.1", 6, s112);
    s12 = crearNuevoNodoArbol(nullptr, "Principal", 10, nullptr);
    c1 = crearNuevoNodoArbol(s11, "Capitulo1", 8, s12);
    
    NodoArbol * s21, * s22, *c2;
    s21 = crearNuevoNodoArbol(nullptr, "Seccion2.1", 3, nullptr);
    s22 = crearNuevoNodoArbol(nullptr, "Seccion2.2", 4, nullptr);
    c2 = crearNuevoNodoArbol(s21, "Capitulo2", 8, s22);
    
    plantarArbolBinario(libro, c1, "Titulo", 7, c2);
    recorrerAmplitud(libro.raiz);
    //0: izq ; 1 : der
    eliminarErrores(libro.raiz, 1);
    recorrerAmplitud(libro.raiz);
    return 0;
}

