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
#define N 8
/*
 * NOMBRE: Jaritza Maribel Villanueva Huaraca
 * CODIGO: 20213699
 */

int acumulacionCentro(int paquetes[],int inicio,int medio,int fin){
    int suma = 0, sumMenorDer = 9999, sumMenorIzq=9999;
    //halla la suma menor por el lado izquierdo
    for(int i=medio; i>=inicio; i--){
        suma += paquetes[i];
        if(suma<sumMenorDer){
            sumMenorDer = suma;
        }
    }
    //halla la suma mayor por el lado izquierdo
    suma = 0;
    for(int i=medio+1; i<=fin; i++){
        suma += paquetes[i];
        if(suma<sumMenorIzq){
            sumMenorIzq = suma;
        }
    }
    return sumMenorIzq + sumMenorDer;
}

int acumulacionNegativa(int paquetes[], int inicio, int fin){
    //caso base
    if(inicio == fin){
        return paquetes[inicio];
    }
    
    //implementacion
    int medio = (inicio + fin)/2;
    int sumIzq = acumulacionNegativa(paquetes, inicio, medio);
    int sumDer = acumulacionNegativa(paquetes, medio+1, fin);
    int centroSum = acumulacionCentro(paquetes, inicio, medio, fin);
    if(sumIzq<= sumDer && sumIzq<= centroSum){
        return sumIzq;
    }
    else{
        if(sumDer<=sumIzq && sumDer<=centroSum){
            return sumDer;
        }
        else return centroSum;
    }
}

int main() {
    int paquetes[N] = {2, 5, -6, 2, 3, -1, -5, 6 };
    int n = 8;
    cout<<acumulacionNegativa(paquetes, 0, n-1);
    return 0;
}

