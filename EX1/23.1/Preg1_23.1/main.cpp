/* 
 * File:   main.cpp
 * Author: PC
 *
 * Created on 17 de mayo de 2024, 08:49
 */

#include <iostream>
#include <cstddef>
using namespace std;
#include "Lista.h"
#include "funciones.h"

void insertarOrdenado(Lista &lista, int elem){
    Nodo *nodo = crearNodo(elem, nullptr);
    if(esListaVacia(lista)){
        lista.cabeza = nodo;
    }
    else{
        Nodo *rec = lista.cabeza, *anterior = nullptr;
        while(rec != nullptr && elem>rec->elemento){
            anterior = rec;
            rec = rec->siguiente;
        }
        if(anterior == nullptr){
            nodo->siguiente = lista.cabeza;
            lista.cabeza = nodo;
        }
        else{
            nodo->siguiente = rec;
            anterior->siguiente = nodo;
        }
    }
    lista.longitud++;
}

void separarListas(Lista &guerreros, Lista &Bowser, Lista &Peach, Lista &DonKey){
    if(esListaVacia(guerreros)) return;
    Nodo *rec = guerreros.cabeza;
    while(rec != nullptr){
        int num = rec->elemento;
        int equipo = num % 10;
        if(equipo == 1){
            insertarOrdenado(Bowser, num/10);
            Bowser.ataqueTotal += (num/10);
        }
        else if(equipo == 2){
            insertarOrdenado(Peach, num/10);
            Peach.ataqueTotal += (num/10);
        }
        else{
            insertarOrdenado(DonKey, num/10);
            DonKey.ataqueTotal += (num/10);
        }
        rec = rec->siguiente;
    }
}

void fusionarListas(Lista &L1, Lista &L2){
    Nodo *rec1 = L1.cabeza;
    Nodo *rec2 = L2.cabeza;
    Nodo *ptr, *cabeza;
    int ataque;
    if(esListaVacia(L1)){
        L1.cabeza = L2.cabeza;
        L1.longitud = L2.longitud;
    }
    if(esListaVacia(L2)) return;
    
    if(rec1->elemento<=rec2->elemento){
        ptr = rec1;
        ataque = rec1->elemento;
        rec1 = rec1->siguiente;
        
    }
    else{
        ptr = rec2;
        ataque = rec2->elemento;
        rec2 = rec2->siguiente;
        
    }
    int n = 1;
    cabeza = ptr;
    while(rec1 != nullptr && rec2 != nullptr){
        if(rec1->elemento<=rec2->elemento){
            ptr->siguiente = rec1;
            ataque += rec1->elemento;
            rec1 = rec1->siguiente;
        }
        else{
            ptr->siguiente = rec2;
            ataque += rec2->elemento;
            rec2 = rec2->siguiente;
        }
        n++;
        ptr = ptr->siguiente;
    }
    //agregar lo restante
    while(rec1 != nullptr){
        ptr->siguiente = rec1;
        ataque += rec1->elemento;
        ptr = ptr->siguiente;
        rec1 = rec1->siguiente;
    }
    while(rec2 != nullptr){
        ptr->siguiente = rec2;
        ataque += rec2->elemento;
        ptr = ptr->siguiente;
        rec2 = rec2->siguiente;
    }
    
    L1.cabeza = cabeza;
    L1.longitud = n;
    L1.ataqueTotal = ataque;
}

void simularBatalla(int n, Lista &Bowser, Lista &Peach, Lista &DonKey){
    bool ingresoAyuda = false;
    while(true){
        cout<<"Iniciar la batalla:"<<endl;
        cout<<"Ejercito 1 - Bowser: ";
        imprime(Bowser);
        cout<<"Ejercito 2 - Peach: ";
        imprime(Peach);
        
        Nodo *recB = Bowser.cabeza;
        Nodo *recP = Peach.cabeza; 
        int i = 0, ganador, perdedor, equipo;
        while(recB != nullptr && recP != nullptr && i<n){
            cout<<"Pelea "<<i+1<<": "<<recB->elemento<<" vs "<<recP->elemento<<", ";
            if(recB->elemento<recP->elemento){
                ganador = recP->elemento;
                perdedor = recB->elemento;
                equipo = 1;
                Bowser.ataqueTotal -= perdedor;
            }
            else{
                ganador = recB->elemento;
                perdedor = recP->elemento;
                equipo = 2;
                Peach.ataqueTotal -= perdedor;
            }
            cout<<"gana "<<ganador<<endl;
            recB = recB->siguiente;
            recP = recP->siguiente;
            
            if(equipo == 1){
                eliminaNodo(Bowser, perdedor);
            } else eliminaNodo(Peach, perdedor);
            
            i++;
        }
        cout<<"Nivel de Ataque Total del Ejercito 1: "<<Bowser.ataqueTotal<<endl;
        cout<<"Nivel de Ataque Total del Ejercito 2: "<<Peach.ataqueTotal<<endl;
        
        if(Peach.ataqueTotal <= Bowser.ataqueTotal && ingresoAyuda == false){
            fusionarListas(Peach, DonKey);
            ingresoAyuda = true;
            cout<<"El ejercito de DonKey Kong se une al ejercito de Peach."<<endl<<endl;
        }
        else{
            cout<<"Ya no se puede unir nadie al ejercito de Peach."<<endl<<endl;
        }
        
        if(esListaVacia(Peach) || esListaVacia(Bowser)){
            if(esListaVacia(Peach)) cout<<"Gana la batalla Bowser"<<endl;
            else cout<<"Gana la batlla Peach."<<endl;
            break;
        }
    }
}

int main() {
    Lista guerreros, Bowser, Peach, DonKey;
    construir(guerreros);
    construir(Bowser);
    construir(Peach);
    construir(DonKey);
    
    int n, numGue;
    cout<<"Ingrese el valor de n: ";
    cin>>n;
    cout<<"Ingrese la cantidad total de guerreros: ";
    cin>>numGue;
    for(int i=0; i<numGue; i++){
        int num;
        char c;
        cin>>num>>c;
        insertarAlFinal(guerreros, num);
    }
    
    separarListas(guerreros, Bowser, Peach, DonKey);
    cout<<endl<<"Los ejercitos formados son:"<<endl;
    
    cout<<"Ejercito 1 - Bowser: ";
    imprime(Bowser);
    cout<<"Nivel de Ataque Total del Ejercito 1: "<<Bowser.ataqueTotal<<endl<<endl;
    
    cout<<"Ejercito 2 - Peach: ";
    imprime(Peach);
    cout<<"Nivel de Ataque Total del Ejercito 2: "<<Peach.ataqueTotal<<endl<<endl;
    
    cout<<"Ejercito 3 - DonKey Kong: ";
    imprime(DonKey);
    cout<<"Nivel de Ataque Total del Ejercito 3: "<<DonKey.ataqueTotal<<endl<<endl;
    
//    fusionarListas(Peach, DonKey);
//    imprime(Peach);
//    cout<<Peach.ataqueTotal;
    
    simularBatalla(n, Bowser, Peach, DonKey);
    return 0;
}

