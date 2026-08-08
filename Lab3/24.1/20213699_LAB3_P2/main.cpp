/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 11 de mayo de 2024, 08:02 AM
 */

#include <iostream>
using namespace std;
#define N 17
/*
 * NOMBRE: Jaritza Maribel Villanueva Huaraca
 * CODIGO: 20213699
 */

int encontrarInicio(int zona[], int inicio, int fin){
    //caso base si no hubo radiacion
    if(inicio>=fin){
        return -1; //no encontro ninguna posicion
    }
    int medio = (inicio +fin)/2;
    //si esta en zona de radiacion
    if(zona[medio]>0){
        return encontrarInicio(zona, inicio, medio-1);
    }
    else{
        //si el siguiente es menor que 0 entonces sigue en zona sin radiacion
        if(zona[medio+1]<0) return encontrarInicio(zona, medio+1, fin);
        //caso base 2
        //encontro el punto inicial
        else return medio;
    }
}

int hallarMaximo1(int zona[], int inicio, int fin){
    if(inicio == fin) return zona[inicio];
    if(inicio>fin) return -1;
            
    int medio = (inicio+fin)/2;
    if(medio % 2 == 1){
        if(zona[medio] == zona[medio-1] && zona[medio] != zona[medio+1]){
            return hallarMaximo1(zona, inicio, medio);
        }
        else return hallarMaximo1(zona, medio, fin);
    }
    else{
        if(zona[medio] == zona[medio+1] && zona[medio] != zona[medio-1]){
            return hallarMaximo1(zona, inicio, medio-1);
        }
        else{
            return hallarMaximo1(zona, medio+1, fin);
        }
    }
}

int hallarMaximo2(int zona[], int inicio, int fin){
    if(inicio == fin) return zona[inicio];
    if(inicio>fin) return -1;
            
    int medio = (inicio+fin)/2;
    if(medio % 2 == 1){
        if(zona[medio] == zona[medio-1] && zona[medio] != zona[medio+1]){
            return hallarMaximo2(zona, medio, fin);
        }
        else return hallarMaximo2(zona, inicio, medio-1);
    }
    else{
        if(zona[medio] == zona[medio+1] && zona[medio] != zona[medio-1]){
            return hallarMaximo2(zona, inicio, medio-1);
        }
        else{
            return hallarMaximo2(zona, medio, fin);
        }
    }
}

void solucion(int zona[],int n){
    //encontrar el inicio de la radiacion (posicion)
    int posIniRadiacion = encontrarInicio(zona, 0, n-1);
    //Se busca la radiacion maxima siguiendo el sin pareja
     //Cabe resaltar que se realiza si la posicion es par o impar, ya que al trabajar
    //con una subregion, en el arreglo original comienza con indices diferentes y eso
    //afecta a que si las posicion son realmente pares o no y con ello cambia el analisis
    // de los subgrupos a tomar para el siguiente proceso
    int radiacionMaxima;
    if(posIniRadiacion%2 ==1 ){
        //posIniRadicion + 1 porque ya no contamos el 0
        radiacionMaxima = hallarMaximo2(zona, posIniRadiacion+1, n-1);
    }
    else radiacionMaxima = hallarMaximo1(zona, posIniRadiacion+1, n-1);
    
//    impresion de solucion
    cout<<"El resultado sera: "<<endl;
    if(posIniRadiacion!=-1){
        cout<<"La radiacion empieza a "<<posIniRadiacion+1<<" km. ";
        cout<<"Potencia maxima "<<radiacionMaxima<<" megatones";
    }
    else cout<<"No hubo radiacion"<<endl;
}
int main() {
//    int zona[N] = {0, -1, 0, -1, 0, 1, 1, 2, 2, 3, 2, 2, 1, 1};
//    int n = 14;
    int zona[N] = {-1, 0, -1, 0, 1, 1, 2, 2, 3, 3, 4, 3, 3, 2, 2, 1, 1};
    int n = 17;
    solucion(zona, n);
    return 0;
}

