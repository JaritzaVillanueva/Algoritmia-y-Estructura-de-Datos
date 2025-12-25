/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 30 de mayo de 2025, 05:05 PM
 */

#include <iostream>
#include "ArbolBinarioBusqueda.h"
using namespace std;
#include "funcionesABB.h"

/*
 * ESTRUCTURA ÁRBOL BINARIO 2024-1
 */
int main(int argc, char** argv) {

    struct ArbolBinarioBusqueda arbol;

    construir(arbol);

    insertar(arbol, 100);
    insertar(arbol, 50);
    insertar(arbol, 200);
    insertar(arbol, 30);
    insertar(arbol, 75);
    insertar(arbol, 201);
    insertar(arbol, 1500);
    insertar(arbol, 150);
    enOrden(arbol);
    cout << endl;
    cout <<"Se encuentra 201 en el árbol: "<<buscaArbol(arbol, 201)<<endl;
    eliminarNodo(arbol, 100);
    cout <<"Se encuentra 100 en el árbol: "<<buscaArbol(arbol, 100)<<endl;
    enOrden(arbol);
    
    destruirArbolBB(arbol);
   
    return 0;
}

