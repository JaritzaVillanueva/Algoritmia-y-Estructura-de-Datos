/* 
 * File:   main.cpp
 * NOMBRE: Jaritza Maribel Villanueva Huaraca
 * CODIGO: 20213699
 * Created on 17 de mayo de 2024, 15:36
 */

#include <iostream>
#include <cstring>
using namespace std;
#include "Cola.h"
#include "funcionesCola.h"
#include "funcionesLista.h"

int calculaEdad(int fecha){
    return (20240705 - fecha)/10000;
}

void encolaPrioridad(struct Cola &c, int fecha, const char *cod){
    Nodo * nodo = crearNodo(fecha, cod, nullptr);
    int edad = calculaEdad(fecha);
    if(esColaVacia(c)){
        c.lista.cabeza = nodo;
        c.lista.cola = nodo;
        
        if(edad>80) c.lista.Prio1 = nodo;
        else if(edad<10) c.lista.Prio2 = nodo;
        else c.lista.Prio3 = nodo;
    }
    else{
        if(edad>80){
            if(c.lista.Prio1 == nullptr){
                nodo->siguiente = c.lista.cabeza;
                c.lista.cabeza = nodo;
                c.lista.Prio1 = nodo;
            }else{
                nodo->siguiente = c.lista.Prio1->siguiente;
                c.lista.Prio1->siguiente = nodo;
                c.lista.Prio1 = nodo;
            }
        }
        else if(edad<10){
            if(c.lista.Prio2 == nullptr){
                if(c.lista.Prio1 == nullptr){
                    nodo->siguiente = c.lista.cabeza;
                    c.lista.cabeza = nodo;
                }
                else{
                    nodo->siguiente = c.lista.Prio1->siguiente;
                    c.lista.Prio1->siguiente = nodo;
                    if(c.lista.Prio3 == nullptr){
                        c.lista.cola = nodo;
                    }
                }
                c.lista.Prio2 = nodo;
            }
            else{
                nodo->siguiente = c.lista.Prio2->siguiente;
                c.lista.Prio2->siguiente = nodo;
                if(c.lista.Prio3 == nullptr){
                    c.lista.cola = nodo;
                }
                c.lista.Prio2 = nodo;
            }
        }
        else{
            if(c.lista.Prio3 == nullptr){
                c.lista.cola->siguiente = nodo;
                c.lista.cola = nodo;
            }
            else{
                c.lista.Prio3->siguiente = nodo;
                c.lista.cola = nodo;
            }
            c.lista.Prio3 = nodo;
        }
    }
    c.lista.longitud++;
}

void ordenaRec(Cola &cola, int n){
    if(esColaVacia(cola)) return;
    int max, aux;
    max = desencolar(cola);
    int i = 1;
    while(i<n){
        aux = desencolar(cola);
        if(aux>max){
            encolar(cola, max, "0");
            max = aux;
        }
        else encolar(cola, aux, "0");
        i++;
    }
    ordenaRec(cola, n-1);
    encolar(cola, max, "0");
}

int main() {
    Cola pacientes, pacientesPrio;
    construir(pacientes);
    cout<<"Ingreso normal: "<<endl;
    encolar(pacientes, 19430530, "BXQ778");
    encolar(pacientes, 20140420, "HRP112");
    encolar(pacientes, 19750626, "PRL625");
    encolar(pacientes, 19491022, "MKP157");
    encolar(pacientes, 20200513, "ARH749");
    encolar(pacientes, 19300214, "HRQ931");
    imprime(pacientes);
    
    ordenaRec(pacientes, pacientes.lista.longitud);
    imprime(pacientes);
    
    construir(pacientesPrio);
    cout<<endl<<"Ingreso por prioridad: "<<endl;
    encolaPrioridad(pacientesPrio, 19430530, "BXQ778");
    encolaPrioridad(pacientesPrio, 20140420, "HRP112");
    encolaPrioridad(pacientesPrio, 19750626, "PRL625");
    encolaPrioridad(pacientesPrio, 19491022, "MKP157");
    encolaPrioridad(pacientesPrio, 20200513, "ARH749");
    encolaPrioridad(pacientesPrio, 19300214, "HRQ931");
    imprime(pacientesPrio);
    return 0;
}

