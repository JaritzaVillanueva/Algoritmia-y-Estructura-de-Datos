/* 
 * File:   funcionesLista.h
 * Author: ANA RONCAL
 * Created on 26 de septiembre de 2023, 04:52 PM
 */

#ifndef FUNCIONESLISTA_H
#define FUNCIONESLISTA_H

void construir(struct Lista &);

struct Nodo * crearNodo(struct Avion avion, struct Nodo * siguiente);
struct Avion retornaCabeza(const struct Lista & tad);
void insertarencola(struct Lista & tad, struct Avion avion);
const bool esListaVacia(const struct Lista &);
int longitud(const struct Lista &);

void eliminaCabeza(struct Lista &);
void eliminaCola(struct Lista);

void destruir(struct Lista &);
void imprime(const struct Lista &);

///// auxiliar////
void separarHora(int minTotal, int &hh,int &mm);
#endif /* FUNCIONESLISTA_H */

