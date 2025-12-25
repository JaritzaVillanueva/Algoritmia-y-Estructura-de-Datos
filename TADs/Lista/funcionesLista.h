/* 
 * File:   funcionesLista.h
 * Author: Jaritza
 * Codigo: 20213699
 * Created on 1 de abril de 2024, 10:50 AM
 */

#ifndef FUNCIONESLISTA_H
#define FUNCIONESLISTA_H

void construir(struct Lista &);
void insertarAlInicioArchivo(const char*, struct Lista &);

void insertarAlInicio(struct Lista & tad, int elemento);
void insertarAlFinal(struct Lista & tad, int elemento);
void insertarEnOrden(struct Lista & tad, int elemento);

void imprime(struct Lista tad);

const bool esListaVacia(const struct Lista & tad);


#endif /* FUNCIONESLISTA_H */

