/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Jaritza Villanueva
 *
 * Created on 18 de mayo de 2024, 10:10 AM
 */

#include <iostream>
using namespace std;
#include "Lista.h"
#include "funciones.h"
#define N 6

int main() {
    //Crecion de los tipos de Producto
    int n = 4;
    Lista arrProductos[n];
    char tipoProducto[n];
    for(int i=0; i<n; i++){
        construir(arrProductos[i]);
    }
    cout<<"Rellenar datos iniciales"<<endl;
    for(int i=0; i<n; i++){
        int num;
        cout<<"Tipo de Producto: ";
        cin>>tipoProducto[i];
        cout<<"Calorias de los productos "<<tipoProducto[i]<<": ";
        int k=0;
        while(true){
            //maximo 6
            if(k == 6){
                cout<<"Llego al limite"<<endl;
                break;
            }
            cin>>num;
            if(num == 0) break; // verificacion de parada
            insertarAlFinal(arrProductos[i], num);
            k++;
        }
    }
    
    //Ingresar Formula
    cout<<"FORMULA A PROBAR: "<<endl;
    int numTipoFor;
    cout<<"Ingrese el numero de tipo de productos que utilizara: ";
    cin>>numTipoFor;
    if(numTipoFor<2) 
        cout<<"Numero invalido"<<endl;
    else{
        char arrParaFormula[numTipoFor];
        int arrcantProd[numTipoFor], arrTotalMaxima[numTipoFor];
        for(int i=0; i<numTipoFor; i++){
            cout<<"Tipo de Producto: ";
            cin>>arrParaFormula[i];
            cout<<"Cantidad de Productos del Tipo "<<arrParaFormula[i]<<": ";
            cin>>arrcantProd[i];
            cout<<"Total de calorias maxima de todos los productos "<<arrParaFormula[i]<<": ";
            cin>>arrTotalMaxima[i];
        }
    }
    return 0;
}

