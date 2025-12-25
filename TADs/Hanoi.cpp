/* 
 * Proyecto: Hanoi
 * File:   main.cpp
 * Author: Jaritza
 * Codigo: 20213699
 * Created on 13 de octubre de 2023, 03:26 PM
 */

#include <iostream>
using namespace std;

void hanoi(int n, char A, char B, char C){
    if (n == 0) return; //caso base: si en el inicio no hay mas aros
    hanoi(n-1,A, C, B);
    cout<<"Mover disco de A a C"<<endl;
    hanoi(n-1,B,A,C);
}

int main() {
     
    /*
     * n = numero de aros
     * A = primera pila(inicio)
     * B = segunda pila ( intermedia)
     * C = tercera pila (final)
     */
    hanoi(3,'A','B','C');
    
    return 0;
}

