/* 
 * Proyecto: practicarFuncionABB
 * File:   main.cpp
 * Author: Jaritza
 * Codigo: 20213699
 * Created on 31 de mayo de 2024, 10:37 AM
 */

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include "funcionesAuxiliares.h"
#include "ArbolBinarioBusqueda.h"
#include "funcionesABB.h"

int main(int argc, char** argv) {
    ArbolBinarioBusqueda abb;
    construir(abb);
    inserta1(abb, 15);
    inserta1(abb, 8);
    inserta1(abb, 20);
    inserta1(abb, 7);
    inserta1(abb, 10);
    inserta1(abb, 9);
    inserta1(abb, 4);
    inserta1(abb, 16);
    inserta1(abb, 28);
    inserta1(abb, 17);
    inserta1(abb, 25);
    inserta1(abb, 30);
    enOrden(abb);
    cout<<endl;
    inserta1(abb, 24);
    inserta1(abb, 26);
    enOrden(abb);
    cout<<endl;
    buscarElemento(abb, 15);
    buscarElemento(abb, 27);
    cout<<mayorElemento(abb.arbolBinario.raiz)<<endl;
    cout<<alturaABB(abb)<<endl;
    imprimirAmplitud(abb);
    return 0;
}

