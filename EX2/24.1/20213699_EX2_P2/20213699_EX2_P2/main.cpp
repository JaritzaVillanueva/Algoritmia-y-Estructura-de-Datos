/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 6 de julio de 2024, 10:07
 */

#include <iostream>

#include "ArbolBinarioBusqueda.h"
#include "funcionesArbolesBB.h"
#include "funcionesArbolesBinarios.h"
using namespace std;
#define N 3
#define M 9

void amplitud(struct NodoArbol * raiz, int nivel, int pesos[M][N], int combinaciones[N][N]){
    if(raiz == nullptr) return;
    if(nivel == 1){
        bool encontrado = false;
        int indice;
        for(int i=0; i<M; i++){
            for(int k=0; k<N; k++){
                if(pesos[i][k] == raiz->elemento){
                    
                }
            }
        }
    }
    else if(nivel > 1){
        amplitud(raiz->izquierda, nivel-1, pesos, combinaciones);
        amplitud(raiz->derecha, nivel-1, pesos, combinaciones);
    }
}

void cambios(struct ArbolBinarioBusqueda emociones, int pesos[M][N], int combinaciones[N][N]){
    int alt = altura(emociones.arbolBinario);
    for(int i=1; i<= alt; i++){
        cout<<"Nivel "<<i<<" - ";
        amplitud(emociones.arbolBinario.raiz, i, pesos, combinaciones);
        cout<<endl;
    }
}

int main() {
    ArbolBinarioBusqueda emociones;
    construir(emociones);
    //Ingresar datos arboles
    insertar(emociones, 180);
    insertar(emociones, 120);
    insertar(emociones, 250);
    insertar(emociones, 100);
    insertar(emociones, 150);
    insertar(emociones, 80);
    insertar(emociones, 90);
    insertar(emociones, 140);
    insertar(emociones, 160);
    insertar(emociones, 230);
    insertar(emociones, 280);
    insertar(emociones, 200);
    insertar(emociones, 240);
    insertar(emociones, 260);
    //emociones
    int pesos[M][N] = {{180, 200, 0},
                        {140, 230, 80},
                        {240, 100, 0},
                        {280,0,0},
                        {250,0,0},
                        {260, 120, 0},
                        {160, 240, 0},
                        {120, 80, 0},
                        {150, 230, 90}};
    /*
        Alegría 0
        Tristeza 1
        Temor 2
        Furia 3
        Desagrado 4
        Ansiedad 5
        Envidia 6
        Vergüenza 7 
        Aburrimiento 8 

     */
    int combinaciones[N][N] = {{0, 8, 1},
                                {4, 1, 2},
                                {2, 7, 8}};
    int n = 3;
    cambios(emociones, pesos, combinaciones);
    return 0;
}

