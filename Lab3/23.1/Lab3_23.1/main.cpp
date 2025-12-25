/* 
 * Proyecto: Lab3_23.1
 * File:   main.cpp
 * Author: Jaritza
 * Codigo: 20213699
 * Created on 13 de octubre de 2023, 04:21 PM
 */

#include <iostream>

#include "Lista.h"
#include "funcionesLista.h"
#include "Nodo.h"
using namespace std;

void imprimirResultado(Lista CatA){
    Nodo *p;
    p = CatA.cabeza;
    for(int i=0; i<CatA.longitud;i++){
        cout<<setw(2)<<p->categoria<<" ";
    }
    cout<<endl;
    for(int i=0; i<CatA.longitud; i++){
        cout<<p->nivelImpacto<<" ";
    }
}

void reorganizar(Lista &L1, Lista &L2){
    if(L1.cola->nivelImpacto>=L2.cabeza->nivelImpacto){
        L1.cola->siguiente=L2.cabeza;
        L1.cola = L2.cola;
    }
    else{
        if(L2.cola->nivelImpacto > L2.cabeza->nivelImpacto){
            L2.cola->siguiente = L1.cabeza;
            L1.cabeza = L2.cabeza;
        }
        else{
            
        }
    }
}

int main() {
    Lista CatA, CatB, CatC, CatD, CatE;
    int numA, numB, numC, numD, numE;
    
    construir(CatA);
    construir(CatB);
    construir(CatC);
    construir(CatD);
    construir(CatE);
    
    cout<<"Numero de PSI para A:";
    cin>>numA;
    cout<<"Ingresa el nivel de impacto: ";
    for(int i=0;i <numA;i ++){
        int nivelImpac;
        cin>>nivelImpac;
        insertarAlFinal(CatA, nivelImpac, 'A');
    }
    
    cout<<"Numero de PSI para B:";
    cin>>numB;
    cout<<"Ingresa el nivel de impacto: ";
    for(int i=0;i <numB;i ++){
        int nivelImpac;
        cin>>nivelImpac;
        insertarAlFinal(CatB, nivelImpac, 'B');
    }
    
    cout<<"Numero de PSI para C:";
    cin>>numC;
    cout<<"Ingresa el nivel de impacto: ";
    for(int i=0;i <numC;i ++){
        int nivelImpac;
        cin>>nivelImpac;
        insertarAlFinal(CatC, nivelImpac, 'C');
    }
    
    cout<<"Numero de PSI para D:";
    cin>>numD;
    cout<<"Ingresa el nivel de impacto: ";
    for(int i=0;i <numD;i ++){
        int nivelImpac;
        cin>>nivelImpac;
        insertarAlFinal(CatD, nivelImpac, 'D');
    }
    
    cout<<"Numero de PSI para E:";
    cin>>numE;
    cout<<"Ingresa el nivel de impacto: ";
    for(int i=0;i <numE;i ++){
        int nivelImpac;
        cin>>nivelImpac;
        insertarAlFinal(CatE, nivelImpac, 'E');
    }
    
    reorganizar(CatA, CatB);
    
    imprimirResultado(CatA);
    return 0;
}

