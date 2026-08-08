/* 
 * File:   Lista.h
 * Author: ANA RONCAL
 * Created on 26 de septiembre de 2023, 04:51 PM
 */

#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"
struct Lista {
    struct Nodo * cabeza; /*apunta al inicio de la lista*/
    struct Nodo * cola;
    int longitud = 0; /*guarda la longitud de la lista*/
    struct Nodo * Prio1 = nullptr;
    struct Nodo * Prio2 = nullptr;
    struct Nodo * Prio3 = nullptr;
};

#endif /* LISTA_H */

