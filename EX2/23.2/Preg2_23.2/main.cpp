/* 
 * File:   main.cpp
 * Author: PC
 *
 * Created on 30 de junio de 2024, 11:22
 */

#include <iostream>
using namespace std;
#include "funcionesArbolesBinarios.h"
#include "ArbolBinario.h"
#include "funcionesCola.h"
#include "Cola.h"
#define N 8
#define M 6

bool verificaLetra(char *palabra, char letra){
    for(int i=0; palabra[i] != '\0'; i++){
        if(palabra[i] == letra) return true;
    }
    return false;
}

bool verificarFinal(char *arr){
    for(int i=0; arr[i] != '\0'; i++){
        if(arr[i] != ' ') return false;
    }
    return true;
}

int recursion(char *palabra, char *arr, NodoArbol *raiz){
    if(raiz == nullptr) return 0;
    bool hayLetra = verificaLetra(palabra, raiz->elemento);
    if(hayLetra){
        for(int i=0; arr[i] != '\0'; i++){
            if(arr[i] == raiz->elemento){
                arr[i] = ' ';
                break;
            }
        }
    }
    else return 0;
    // si llego a la hoja
    if(raiz->derecha == nullptr && raiz->izquierda==nullptr){
        if(verificarFinal(arr)){
            return 1;
        }
        else return 0;
    }
    
    return recursion(palabra, arr, raiz->izquierda) + recursion(palabra, arr, raiz->derecha);
    
}

int existePalbra(char palabra[],ArbolBinario arbol){
    char copia[N]{};
    for(int i=0; palabra[i]; i++){
        copia[i] = palabra[i];
    }
    return recursion(palabra, copia, arbol.raiz);
}

void amplitud(NodoArbol *ptr, int nivel){
    if(ptr == nullptr) return;
    if(nivel == 0){
        cout<<ptr->elemento<<" ";
    }
    else{
        amplitud(ptr->izquierda, nivel-1);
        amplitud(ptr->derecha, nivel-1);
    }
}

void imprimirAmplitud(ArbolBinario arbol){
    int alt = altura(arbol);
    for(int i=0; i<=alt; i++){
        amplitud(arbol.raiz, i);
        cout<<endl;
    }
}

void imprimirAmplitudIterativo(ArbolBinario arbol){
    if(esArbolVacio(arbol)) return;
    Cola cola;
    construir(cola);
    encolar(cola, arbol.raiz);
    encolar(cola, nullptr);
    
    while(longitud(cola)>1){
        NodoArbol * temp = desencolar(cola);
        if(temp != nullptr){
            cout<<temp->elemento<<" ";

            //encolar hijos
            if(temp->izquierda != nullptr){
                encolar(cola, temp->izquierda);
            }
            if(temp->derecha != nullptr){
                encolar(cola, temp->derecha);
            }
        }else{
            cout<<endl;
            encolar(cola, temp);
        }
    }
}


int main() {
    ArbolBinario arbol;
    construir(arbol);
    struct NodoArbol *t, *r, *g, *e, *e1, *d;
    t = crearNuevoNodoArbol(nullptr, 'T', nullptr);
    r = crearNuevoNodoArbol(nullptr, 'R', nullptr);
    e = crearNuevoNodoArbol(nullptr, 'E', nullptr);
    
    g = crearNuevoNodoArbol(t, 'G', nullptr);
    e1 = crearNuevoNodoArbol(r, 'E', g);
    d  = crearNuevoNodoArbol(e, 'D', e1);
    
    struct NodoArbol *o, *c, *c1, *i, *f, *t1, *a, *n;
    o = crearNuevoNodoArbol(nullptr, 'O', nullptr);
    f = crearNuevoNodoArbol(nullptr, 'F', nullptr);
    t1 = crearNuevoNodoArbol(nullptr, 'T', nullptr);
    
    c = crearNuevoNodoArbol(o, 'C', nullptr);
    c1 = crearNuevoNodoArbol(c, 'C', nullptr);
    
    a = crearNuevoNodoArbol(f, 'A', t1);
    n = crearNuevoNodoArbol(a, 'N', nullptr);
    i = crearNuevoNodoArbol(c1, 'I', n);
    
    //arbol
    plantarArbolBinario(arbol, d, 'L', i);
//    recorrerEnOrden(arbol);
//    imprimirAmplitud(arbol);
    imprimirAmplitudIterativo(arbol);
//    char palabra[][M] = {{'H','I','J','O','\0'},
//                            {'F', 'I', 'N', 'A', 'L','\0'},
//                            {'M','U','N','D','O','\0'},
//                            {'D', 'E', 'L', '\0'},
//                            {'D', 'I', 'A', '\0'},
//                            {'C', 'I', 'C', 'L', 'O', '\0'}};
//    cout<<"Mensaje oculto: "<<endl;
//    for(int i=0; i<M; i ++){
//        if(existePalbra(palabra[i], arbol)){
//            cout<<palabra[i]<<" ";
//        }
//    }
    
    return 0;
}

