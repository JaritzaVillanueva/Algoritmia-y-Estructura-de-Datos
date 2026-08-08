

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 18 de mayo de 2024, 09:07 AM
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "Cola.h"
#include "funcionesCola.h"

void llenarAvion(struct Avion &ai, int num, int ini){
    ai.numero = num;
    ai.minIniTotal = ini;
    ai.minIniNueva = ini;
}

void ordenarColaLlegada (struct Cola &cola, int n){
    if(n<=1)return;
    struct Avion max, aux;
    //comenzamo desde 1 porque ya desencolamos un valor (max)
    int i=1;
    max = desencolar(cola);
    while(i<n){
        aux = desencolar(cola);
        //verificacion
        if(aux.minIniTotal>max.minIniTotal){
            //primero, encolamos porque si realizamos el cambio, se nos pierde el valor
            encolar(cola, max);
            max = aux;
        }
        else encolar(cola, aux);
        i++;
    }
    //disminuimos la longitud a analizar
    ordenarColaLlegada(cola, n-1);
    //al final encolamos el max de todos
    encolar(cola, max);
}

void actualizarDato(struct Cola &cola, int n,int numAvion, int min){
    if(n<=1)return;
    struct Avion aux;
    int i=1;
    while(i<n){
        //desencolamos un valor
        aux = desencolar(cola);
        //si es el ambio que queremos lo modificamos
        if(aux.numero == numAvion){
            aux.minIniNueva = min;
        }
        //volvemos a encolar
        encolar(cola, aux);
        i++;
    }
    actualizarDato(cola, n-1, numAvion, min);
}

void ordenarColaLlegadaNueva(struct Cola &cola, int n){
    if(n<=1)return;
    struct Avion max, aux;
    int i=1;
    max = desencolar(cola);
    while(i<n){
        aux = desencolar(cola);
        //la misma tematica que la otr funcion pero aqui la verificacion es en 
        //la hora de llegada nueva
        if(aux.minIniNueva>max.minIniNueva){
            encolar(cola, max);
            max = aux;
        }
        else encolar(cola, aux);
        i++;
    }
    ordenarColaLlegadaNueva(cola, n-1);
    encolar(cola, max);
}

int main() {
    //1. construccion y guardar datos
    Cola aeropuerto;
    construir(aeropuerto);
    struct Avion a1, a2, a3, a4, a5;
    //una funcion para llenar la estructura
    llenarAvion(a1, 2101, 55);
    llenarAvion(a2, 1102, 105);
    llenarAvion(a3, 4111, 30);
    llenarAvion(a4, 2105, 82);
    llenarAvion(a5, 3108, 325);
    
    //encolamos la estructura
    encolar(aeropuerto, a1);
    encolar(aeropuerto, a2);
    encolar(aeropuerto, a3);
    encolar(aeropuerto, a4);
    encolar(aeropuerto, a5);
    cout<<right<<setw(30)<<"AEROPUERTO AURORA"<<endl;
    
    //2. Ordenar datos
    ordenarColaLlegada(aeropuerto, aeropuerto.lista.longitud);
    cout<<left<<"HORA DE LLEGADA:"<<endl;
    cout<<left<<setw(10)<<"Avion"<<setw(18)<<"Hora de llegada"<<setw(20)<<"Nueva hora de llegada"<<endl;
    imprime(aeropuerto);
    cout<<endl;
    //3. Actualiza
    actualizarDato(aeropuerto, aeropuerto.lista.longitud, 2101, 15);
    actualizarDato(aeropuerto, aeropuerto.lista.longitud, 2105, 130);
//    imprime(aeropuerto);
    
    //4. Orenar por Nueva Hora Llegada
    cout<<left<<"NUEVA HORA DE LLEGADA:"<<endl;
    cout<<left<<setw(10)<<"Avion"<<setw(18)<<"Hora de llegada"<<setw(20)<<"Nueva hora de llegada"<<endl;
    ordenarColaLlegadaNueva(aeropuerto, aeropuerto.lista.longitud);
    imprime(aeropuerto);
    return 0;
}

