/* 
 * File:   main.cpp
 * Author: PC
 *
 * Created on 10 de mayo de 2024, 18:15
 */

#include <iostream>
using namespace std;
#define N 10

int encontrarCima(int productos[N],int inicio, int fin){
    if(inicio == fin) return inicio;
    int medio = (inicio+fin)/2;
    if(productos[medio]<=productos[medio+1]){
        return encontrarCima(productos, medio+1, fin);
    }
    else{
        return encontrarCima(productos, inicio, medio);
    }
}

void buscarIzquierda(int productos[],int stock[], int inicio, int fin, int solicitado, int &posIzq,int &valorIzq){
    if(inicio == fin){
        if (productos[inicio] == solicitado){
            valorIzq = stock[inicio];
            posIzq = inicio;
        }
        else{
            valorIzq = 0;
            posIzq = -1;
        }
        return;
    }
    if(inicio>fin){
        valorIzq = 0;
        posIzq = -1;
        return;
    }
    
    int medio = (inicio + fin)/2;
    if(productos[medio] == solicitado){
        valorIzq = stock[medio];
        posIzq = medio;
        return;
    }
    else{
        if(productos[medio]>solicitado){
            buscarIzquierda(productos, stock, inicio, medio-1, solicitado, posIzq, valorIzq);
        }
        else{
            buscarIzquierda(productos, stock, medio+1, fin, solicitado, posIzq, valorIzq);
        }
    }
}

void buscarDerecha(int productos[],int stock[], int inicio, int fin, int solicitado, int &posDer, int &valorDer){
    if(inicio == fin){
        if (productos[inicio] == solicitado){
            valorDer = stock[inicio];
            posDer = inicio;
        }
        else{
            valorDer = 0;
            posDer = -1;
        }
        return;
    }
    if(inicio>fin){
        valorDer = 0;
        posDer = -1;
        return;
    }
    
    int medio = (inicio + fin)/2;
    if(productos[medio] == solicitado){
        valorDer = stock[medio];
        posDer = medio;
        return;
    }
    else{
        if(productos[medio]>solicitado){
            buscarDerecha(productos, stock, medio+1, fin, solicitado, posDer, valorDer);
        }
        else buscarDerecha(productos, stock, inicio, medio-1, solicitado, posDer, valorDer); 
    }
}

void encontrarStock(int productos[N], int stock[N],int n, int solicitado){
    int posIzq, posDer, valorIzq, valorDer;
    //hallar la posicion del mayor
    int mayor = encontrarCima(productos,0 , n-1);
    //cout<<mayor;
    //hallar por derecha o por izquierda (se elige un intervalo)
    buscarIzquierda(productos, stock, 0, mayor, solicitado, posIzq, valorIzq);
    buscarDerecha(productos, stock, mayor+1, n-1, solicitado, posDer, valorDer);
    int totalCajas = valorIzq+valorDer;
    if(totalCajas==0){
        if(posDer == -1) cout<<"No existe el producto seleccionado"<<endl;
        else cout<<"No hay cajas para el producto "<<solicitado<<endl;
    }
    else{
        cout<<"La cantidad de Stock del producto "<<solicitado<<" es: "<<totalCajas<<" cajas."<<endl;
        if(posDer != -1 && posIzq != -1)
            cout<<"Se encuentran en las posiciones: "<<posIzq<<" y "<<posDer<<" dentro del almacen"<<endl;
        else{
            if(posDer != -1)
                cout<<"Se encuentra en la posicion: "<<posDer<<" dentro del almacen"<<endl;
            else 
                cout<<"Se encuentra en la posicion: "<<posIzq<<" dentro del almacen"<<endl;
        }
    }
}

int main() {
    int productos[N] = {10,15,20,80,1000,200,100,50,20,10};
    int stock[N] = {20,20,30,10,10,10,20,20,20,10};
    int n = 10, solicitado = 200, cajasTotal;
    encontrarStock(productos, stock, n, solicitado);
    return 0;
}

