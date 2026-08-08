/* 
 * File:   main.cpp
 * Author: PC
 *
 * Created on 16 de mayo de 2024, 15:52
 */

#include <iostream>
#include <cmath>
using namespace std;
#include "Lista.h"
#include "funciones.h"

int sumarNodos(struct Lista lista){
    int suma = 0;
    if(esListaVacia(lista)) return 0;
    Nodo *rec = lista.cabeza;
    while(rec != nullptr){
        suma += rec->elemento;
        rec = rec->siguiente;
    }
    return suma;
}

void copiaLista(Lista &L1, Lista L2){
    L1.cabeza = nullptr;
    L1.longitud = 0;
    
    if(esListaVacia(L2)){
        return;
    }
    else{
        Nodo *rec = L2.cabeza;
        while(rec != nullptr){
            insertarAlFinal(L1, rec->elemento);
            rec = rec->siguiente;
        }
    }
    
}

void cargaBin(int num, int *cromo, int n, int base){
    for(int i=0; i<n; i++) cromo[i] = 0;
    int i = 0, aux;
    while(num>0){
        aux = num % base;
        cromo[i] = aux;
        num = num / base;
        i++;
    }
}

bool verificar(int *cromo, int max1, int max2, int max3, int max4, int *arrSumaTotal, int m, int n){
    int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
    int sumaTortu[n] = {}, cantTortu[n] = {};
    for(int i=0; i<m; i++){
        if(cromo[i] != 0){
            sumaTortu[cromo[i]-1] += arrSumaTotal[i];
            cantTortu[cromo[i]-1]++;
        }
        else return false;
    }
    for(int i=0; i<n; i++){
        if(cantTortu[i]<1 or cantTortu[i]>2) return false;
        if(i == 0){
            if(sumaTortu[i]>max1) return false;
        }
        if(i == 1){
            if(sumaTortu[i]>max2) return false;
        }
        if(i == 2){
            if(sumaTortu[i]>max3) return false;
        }
        if(i == 3){
            if(sumaTortu[i]>max4) return false;
        }
    }
    return true;
}

void bubleMenorMayor(Lista &LS){
    Nodo *recorrido,*anterior,*soporte;
    Nodo *inter1,*inter2,*aux;
    for (int i = 0; i <= LS.longitud - 2; i++) {
        recorrido = LS.cabeza;
        anterior = nullptr;
        for (int k = 0; k <= LS.longitud - i - 2; k++) {
            if (recorrido->siguiente->elemento < recorrido->elemento){
                
                soporte = anterior;
                inter1 = aux = recorrido;
                inter2 = recorrido->siguiente;
                
                if(soporte == nullptr)LS.cabeza = inter2;
                else soporte->siguiente = inter2;
                inter1->siguiente = inter2->siguiente;
                inter2->siguiente = aux;
                recorrido = inter2;
                anterior = inter1;
            }
            anterior = recorrido;
            recorrido = recorrido->siguiente;
            
        }
    }
}

void bubleMayorMenor(Lista &LS){
    Nodo *recorrido,*anterior,*soporte;
    Nodo *inter1,*inter2,*aux;
    for (int i = 0; i <= LS.longitud - 2; i++) {
        recorrido = LS.cabeza;
        anterior = nullptr;
        for (int k = 0; k <= LS.longitud - i - 2; k++) {
            if (recorrido->siguiente->elemento > recorrido->elemento){
                
                soporte = anterior;
                inter1 = aux = recorrido;
                inter2 = recorrido->siguiente;
                
                if(soporte == nullptr)LS.cabeza = inter2;
                else soporte->siguiente = inter2;
                inter1->siguiente = inter2->siguiente;
                inter2->siguiente = aux;
                recorrido = inter2;
                anterior = inter1;
            }
            anterior = recorrido;
            recorrido = recorrido->siguiente;
            
        }
    }
    
}

void intercalar(Lista &L1, Lista &L2){
    if(esListaVacia(L1)){
        L1.cabeza = L2.cabeza;
        L1.longitud = L2.longitud;
        return;
    }
    if(esListaVacia(L2)) return;
    
    Nodo *rec1 = L1.cabeza;
    Nodo *rec2 = L2.cabeza;
    Nodo *ptr = nullptr, *copia = nullptr;
    //inicio
    ptr = rec1;
    rec1 = rec1->siguiente;
    copia = ptr;
    int n = 1;
    while(rec1 != nullptr && rec2 != nullptr){
        ptr->siguiente = rec2;
        rec2 = rec2->siguiente;
        ptr = ptr->siguiente;
        
        
        ptr->siguiente = rec1;
        rec1 = rec1->siguiente;
        ptr = ptr->siguiente;
        n += 2;
    }
    
    while(rec1!= nullptr){
        ptr->siguiente = rec1;
        rec1 = rec1->siguiente;
        ptr = ptr->siguiente;
        n++;
    }
    
    while(rec2!= nullptr){
        ptr->siguiente = rec2;
        rec2 = rec2->siguiente;
        ptr = ptr->siguiente;
        n++;
    }
    
    L1.cabeza = copia;
    L1.longitud = n;
}

void fusionIntercalado(Lista &L1, Lista &L2){
    bubleMenorMayor(L1);
    bubleMayorMenor(L2);
    intercalar(L1,L2);
}

void imprimirSolucion(int numTortugas, int numCamiones, int solucion, Lista *arrCamiones){
    cout<<endl;
    cout<<"Resultado:"<<endl;
    if(solucion != 0){
        cout<<"Las tortugas completaron su mision."<<endl<<endl;
        int cantTortu[numTortugas]{};
        Lista solucionTortuga[numTortugas]{};
        for(int i=0; i<numTortugas; i++){
            construir(solucionTortuga[i]);
        }
        int posicion[numTortugas]{}, cromo[numCamiones];
        cargaBin(solucion, cromo, numCamiones, numTortugas+1);
        for(int i=0; i<numCamiones; i++){
            if(cromo[i]!=0){
                cantTortu[cromo[i]-1]++;
                if(cantTortu[cromo[i]-1]>1){
                    fusionIntercalado(arrCamiones[posicion[cromo[i]-1]], arrCamiones[i]);
                    copiaLista(solucionTortuga[cromo[i]-1], arrCamiones[posicion[cromo[i]-1]]);
                    continue;
                }
                posicion[cromo[i]-1]=i;
                copiaLista(solucionTortuga[cromo[i]-1], arrCamiones[i]);
            }
        }
        
        //imprimir lo resto
        cout<<"Los camiones a salvar son:"<<endl;
        cout<<"Leonardo: ";
        imprime(solucionTortuga[0]);
        cout<<"Rafael: ";
        imprime(solucionTortuga[1]);
        cout<<"Donatelo: ";
        imprime(solucionTortuga[2]);
        cout<<"Miguel Angel: ";
        imprime(solucionTortuga[3]);
        
    }
    else cout<<"Las tortugas no completaron su mision."<<endl;
}

int main() {
    int numCamiones, capMaxL, capMaxR, capMaxD, capMaxM;
    cout<<"Ingrese la cantidad de camiones: ";
    cin>>numCamiones;
    cout<<"Ingrese la capacidad maxima de carga de Leonardo: ";
    cin>>capMaxL;
    cout<<"Ingrese la capacidad maxima de carga de Rafael: ";
    cin>>capMaxR;
    cout<<"Ingrese la capacidad maxima de carga de Donatelo: ";
    cin>>capMaxD;
    cout<<"Ingrese la capacidad maxima de carga de Miguel Angel: ";
    cin>>capMaxM;
    
    Lista arrCamiones[numCamiones]{};
    for(int i=0; i<numCamiones; i++){
        construir(arrCamiones[i]);
        cout<<"Ingrese los pesos del Bus Nro. "<<i+1<<": ";
        int num;
        while(true){
            cin>>num;
            if(num == 0) break;
            insertarAlFinal(arrCamiones[i], num);
        }
    }
    
    int arrSumaTotal[numCamiones]{};
    for(int i=0; i<numCamiones; i++){
        int suma;
        suma = sumarNodos(arrCamiones[i]);
        arrSumaTotal[i] = suma;
    }

    int cromo[numCamiones], numTortugas = 4, solucion = 0;
    int opcion = pow(numTortugas+1, numCamiones);
    for(int i=214; i<opcion; i++){
        cargaBin(i, cromo, numCamiones, numTortugas+1);
        if(verificar(cromo, capMaxL, capMaxR, capMaxD, capMaxM, arrSumaTotal, numCamiones, numTortugas)){
            solucion = i;
            break;
        }
    }
    
    imprimirSolucion(numTortugas, numCamiones, solucion, arrCamiones);
    return 0;
}

