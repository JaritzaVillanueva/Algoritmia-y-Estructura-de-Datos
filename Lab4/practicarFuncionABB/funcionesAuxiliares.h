/* 
 * File:   funcionesAuxiliares.h
 * Author: Jaritza
 * Codigo: 20213699
 * Created on 31 de mayo de 2024, 11:21 AM
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H
#include "ArbolBinarioBusqueda.h"
#include "NodoArbol.h"

int nodoHoja(NodoArbol *nodo);
void insertarElemento(ArbolBinarioBusqueda &abb, int e);
void insertar2(ArbolBinarioBusqueda &abb, int e);
//
void inserta1(ArbolBinarioBusqueda &abb, int e);
void insertarRecursivo1(NodoArbol *&p, int e);
void buscarElemento(ArbolBinarioBusqueda &abb, int e);
//
int mayorElemento(NodoArbol *p);
//
int alturaABB(ArbolBinarioBusqueda abb);
int alturaRec(NodoArbol *p);
int maximoRec(int a, int b);
//
void imprimirAmplitud(ArbolBinarioBusqueda abb);
void amplituRecursivo(NodoArbol *p, int nivel);
#endif /* FUNCIONESAUXILIARES_H */

