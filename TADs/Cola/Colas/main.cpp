/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 21 de agosto de 2023, 11:57 AM
 */

#include <iostream>
#include "Cola.h"
#include "Pila.h"

using namespace std;
#include "funcionesCola.h"
#include "funcionesPila.h"

/*
 * IMPLEMENTACIÓN DE UNA COLA
 * ALGORITMIA Y ESTRUCTURA DE DATOS 2024-1
 */

/* Ordena los elementos de la cola de forma ascendente utilizando recursión */
void ordenacolarec(Cola &Cola1, int n)
{
    int mayor, i, aux;
    i = 1;
    
    // Caso base: si la cola está vacía o solo tiene un elemento, no se hace nada
    if (esColaVacia(Cola1) || n == 1)
        return;

    // Se extrae el primer elemento y se asume que es el mayor
    mayor = desencolar(Cola1);

    // Se recorre la cola hasta el elemento n-1
    while (i < n)
    {
        // Se extrae el siguiente elemento
        aux = desencolar(Cola1);
        // Si el elemento actual es mayor que el almacenado en 'mayor', se intercambian
        if (aux > mayor)
        {
            // El elemento actual se encola, se actualiza 'mayor' y se procede al siguiente elemento
            encolar(Cola1, mayor);
            mayor = aux;
        }
        else
            // Si no, se encola el elemento actual y se procede al siguiente elemento
            encolar(Cola1, aux);
        i++;
    }

    // Se ordenan los elementos restantes de la cola (n-1)
    ordenacolarec(Cola1, n - 1);

    // Se vuelve a encolar el elemento mayor al final de la cola
    encolar(Cola1, mayor);
}

/* Ordena los elementos de la cola de forma ascendente utilizando bucles */
void ordenacola(Cola &Cola1)
{
    int menor, i, j, aux;
    int n = Cola1.lista.longitud;
    j = n;
    
    // Bucle principal para recorrer todos los elementos de la cola
    while (j > 0)
    {
        i = 1;
        // Se extrae el primer elemento y se asume que es el menor
        menor = desencolar(Cola1);
        // Bucle interno para comparar con los elementos restantes
        while (i < j)
        {
            // Se extrae el siguiente elemento
            aux = desencolar(Cola1);
            // Si el elemento actual es menor que 'menor', se actualiza 'menor'
            if (aux < menor)
            {
                // El elemento actual se encola, se actualiza 'menor' y se procede al siguiente elemento
                encolar(Cola1, menor);
                menor = aux;
            }
            else
                // Si no, se encola el elemento actual y se procede al siguiente elemento
                encolar(Cola1, aux);
            i++;
        }
        // Se vuelven a encolar los elementos que se habían extraído
        for (i = j; i < n; i++)
        {
            // Se extraen y encolan los elementos para mantener el orden original
            aux = desencolar(Cola1);
            encolar(Cola1, aux);
        }
        // Se encola el menor elemento al final de la cola
        encolar(Cola1, menor);
        j--;
    }
}

int main(int argc, char** argv) {
    
    Cola cola;
    construir(cola);
    cout<<"La cola estÃ¡ vacÃ­a: "<<esColaVacia(cola)<<endl;
    encolar(cola, 8);
    encolar(cola, 21);
    encolar(cola, 10);
    imprime(cola);
    desencolar(cola);
    imprime(cola);
    encolar(cola, 15);
    encolar(cola, 7);
    imprime(cola);
    //ordenacola(cola);
    ordenacolarec(cola,cola.lista.longitud);
    imprime(cola);
    return 0;
}

