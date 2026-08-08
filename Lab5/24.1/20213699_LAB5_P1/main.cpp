/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 15 de junio de 2024, 08:06
 */

#include <iostream>
#include <memory>
using namespace std;
#define N 5

//int buscaCandidato(int artistas[N][N],int n, int artista){
//    for(int i=0; i<n; i++){
//        if(artistas[artista][i] == 0 && i != artista){
//            return 0;
//        }
//    }
//    return 1;
//}
//
//int validarCandidato(int artistas[N][N],int n, int artista){
//    for(int i=0; i<n; i++){
//        if(artistas[i][artista] != 0){
//            return 0;
//        }
//    }
//    return 1;
//}

//int buscarBadSunny(int artistas[N][N],int n, int art){
//    if(art == n) return -1;
//    int candidato = buscaCandidato(artistas, n, art); //O(n)
//    int valida = validarCandidato(artistas, n, art); //O(n)
//    
//    if(candidato && valida) return art+1; //O(1)
//    else buscarBadSunny(artistas, n, art+1); //O(n)
//}

int recursion(int artistas[N][N],int n, int art1, int art2){
    if(art2 == n || art1 == n) return art1;
    if(artistas[art1][art2] == 0 && art1 != art2){
        return recursion(artistas, n, art1+1, art2); // descarto art1
    }
    else{
        return recursion(artistas, n, art1, art2+1); //descarto art2
    }
}

int buscarBadSunny(int artistas[N][N],int n, int art1, int art2){
    int candidato = recursion(artistas, n, art1, art2); //O(1)
    //validacion del candidato
    for(int i=0; i<n; i++){ //O(n)
        if(artistas[i][candidato] != 0){
            return -1;
        }
    }
    return candidato+1;
}


int main() {
    int n = 5;
    // 1 significa que fila0(artista1) conoce a columna1 (artista2)
    int artistas[N][N] = {{1,1,0,0,0},
                           {0,1,0,1,0},
                           {1,1,0,1,1},
                           {0,1,0,0,0},
                           {1,0,0,1,1}};
    int BadSunny = buscarBadSunny(artistas, n, 0, 0);
    if(BadSunny == -1){
        cout<<"Bad Sunny ya se fue de la fiesta"<<endl;
    }
    else cout<<"Bad Sunny aun esta en la fiesta y es el artista "<<BadSunny<<endl;
    return 0;
}

