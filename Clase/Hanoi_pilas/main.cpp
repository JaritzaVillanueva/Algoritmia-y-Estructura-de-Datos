/* 
 * File:   main.cpp
 * Author: PC
 *
 * Created on 26 de abril de 2024, 15:25
 */

#include <iostream>
using namespace std;
#include "funcionesPila.h"
#include "Pila.h"

void hanoi(int n, Pila &desde, Pila &hacia, Pila &auxiliar){
    //caso base
    if(n == 1){
        apilar(hacia, desapilar(desde));
        return;
    }
    // llevo los n - 1 de A a C
    hanoi(n-1, desde, auxiliar, hacia);
    apilar(hacia, desapilar(desde));
    // Ahora lo de C lo regreso a A, para que inicie nuevamente ya que 
    //el objetivo es pasar los elemento mayores y jugar hasta el menor elemento
    hanoi(n-1,auxiliar, hacia, desde);
}

int main() {
    Pila A, B, C;
    construir(A);
    for(int i = 4; i>=1; i--){
        apilar(A,i);
    }
    construir(B);
    construir(C);
    hanoi(4, A, B, C);
    imprimir(A);
    imprimir(B);
    return 0;
}

