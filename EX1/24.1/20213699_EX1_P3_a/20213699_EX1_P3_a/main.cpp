

/* 
 * File:   main.cpp
 * Author: Jaritza Villanueva
 *
 * Created on 18 de mayo de 2024, 08:06 AM
 */

#include <iostream>
using namespace std;
#define N 7

void merge1(int Id[N],int nivelImpacto[N], int nivelRiesgo[N],int inicio,int medio,int fin){
    int aux_ID[N], aux_Impacto[N], aux_Riesgo[N];
    int m, p, q;
    m = inicio;
    for(p = inicio, q = medio+1; p<=medio && q<=fin; m++){
        if(Id[p]<Id[q]){
            aux_ID[m] = Id[p];
            aux_Impacto[m] = nivelImpacto[p];
            aux_Riesgo[m] = nivelRiesgo[p];
            p++;
        }
        else{
            aux_ID[m] = Id[q];
            aux_Impacto[m] = nivelImpacto[q];
            aux_Riesgo[m] = nivelRiesgo[q];
            q++;
        }
    }
    //lo restante
    while(p<=medio){
        aux_ID[m] = Id[p];
        aux_Impacto[m] = nivelImpacto[p];
        aux_Riesgo[m] = nivelRiesgo[p];
        p++;
        m++;
    }
    while(q<=fin){
        aux_ID[m] = Id[q];
        aux_Impacto[m] = nivelImpacto[q];
        aux_Riesgo[m] = nivelRiesgo[q];
        q++;
        m++;
    }
    //pasar los valores
    for(int i=inicio; i<=fin; i++){
        Id[i]=aux_ID[i];
        nivelImpacto[i]=aux_Impacto[i];
        nivelRiesgo[i]=aux_Riesgo[i];
    }
}

void merge2(int Id[N],int nivelImpacto[N], int nivelRiesgo[N],int inicio,int medio,int fin){
    int aux_ID[N], aux_Impacto[N], aux_Riesgo[N];
    int m, p, q;
    m = inicio;
    for(p = inicio, q = medio+1; p<=medio && q<=fin; m++){
        if(nivelImpacto[p]<=nivelImpacto[q]){
            if(nivelImpacto[p] == nivelImpacto[q]){
                if(nivelRiesgo[p]<nivelRiesgo[q]){
                    aux_ID[m] = Id[p];
                    aux_Impacto[m] = nivelImpacto[p];
                    aux_Riesgo[m] = nivelRiesgo[p];
                    p++;
                }
                else{
                    aux_ID[m] = Id[q];
                    aux_Impacto[m] = nivelImpacto[q];
                    aux_Riesgo[m] = nivelRiesgo[q];
                    q++;
                }
            }
            else{
                aux_ID[m] = Id[p];
                aux_Impacto[m] = nivelImpacto[p];
                aux_Riesgo[m] = nivelRiesgo[p];
                p++;
            }
        }
        else{
            aux_ID[m] = Id[q];
            aux_Impacto[m] = nivelImpacto[q];
            aux_Riesgo[m] = nivelRiesgo[q];
            q++;
        }
    }
    //lo restante
    while(p<=medio){
        aux_ID[m] = Id[p];
        aux_Impacto[m] = nivelImpacto[p];
        aux_Riesgo[m] = nivelRiesgo[p];
        p++;
        m++;
    }
    while(q<=fin){
        aux_ID[m] = Id[q];
        aux_Impacto[m] = nivelImpacto[q];
        aux_Riesgo[m] = nivelRiesgo[q];
        q++;
        m++;
    }
    //pasar los valores
    for(int i=inicio; i<=fin; i++){
        Id[i]=aux_ID[i];
        nivelImpacto[i]=aux_Impacto[i];
        nivelRiesgo[i]=aux_Riesgo[i];
    }
}

void merge3(int Id[N],int nivelImpacto[N], int nivelRiesgo[N],int inicio,int medio,int fin){
    int aux_ID[N], aux_Impacto[N], aux_Riesgo[N];
    int m, p, q;
    m = inicio;
    for(p = inicio, q = medio+1; p<=medio && q<=fin; m++){
        if(nivelRiesgo[p]<=nivelRiesgo[q]){
            //Si los niveles de riesgo son iguales
            if(nivelRiesgo[p] == nivelRiesgo[q]){
                if(nivelImpacto[p] <= nivelImpacto[q]){
                    //si los niveles de Impacto son iguales
                    if(nivelImpacto[p] == nivelImpacto[q]){
                        //se verifica por el ID
                        if(Id[p]<Id[q]){
                            aux_ID[m] = Id[p];
                            aux_Impacto[m] = nivelImpacto[p];
                            aux_Riesgo[m] = nivelRiesgo[p];
                            p++;
                        }
                        else{
                            aux_ID[m] = Id[q];
                            aux_Impacto[m] = nivelImpacto[q];
                            aux_Riesgo[m] = nivelRiesgo[q];
                            q++;
                        }
                    }
                    // si p es menor que q
                    else{
                        aux_ID[m] = Id[p];
                        aux_Impacto[m] = nivelImpacto[p];
                        aux_Riesgo[m] = nivelRiesgo[p];
                        p++;
                    }
                }
                // si q es mmenor que p
                else{
                    aux_ID[m] = Id[q];
                    aux_Impacto[m] = nivelImpacto[q];
                    aux_Riesgo[m] = nivelRiesgo[q];
                    q++;
                }
            }
            //si p es menor que q
            else{
                aux_ID[m] = Id[p];
                aux_Impacto[m] = nivelImpacto[p];
                aux_Riesgo[m] = nivelRiesgo[p];
                p++;
            }
        }
        //si q es menor que p
        else{
            aux_ID[m] = Id[q];
            aux_Impacto[m] = nivelImpacto[q];
            aux_Riesgo[m] = nivelRiesgo[q];
            q++;
        }
    }
    //lo restante
    while(p<=medio){
        aux_ID[m] = Id[p];
        aux_Impacto[m] = nivelImpacto[p];
        aux_Riesgo[m] = nivelRiesgo[p];
        p++;
        m++;
    }
    while(q<=fin){
        aux_ID[m] = Id[q];
        aux_Impacto[m] = nivelImpacto[q];
        aux_Riesgo[m] = nivelRiesgo[q];
        q++;
        m++;
    }
    //pasar los valores
    for(int i=inicio; i<=fin; i++){
        Id[i]=aux_ID[i];
        nivelImpacto[i]=aux_Impacto[i];
        nivelRiesgo[i]=aux_Riesgo[i];
    }
}

void mergeSort(int Id[N],int nivelImpacto[N],int nivelRiesgo[N], int inicio, int fin, int cat){
    if (inicio == fin){
        return;
    }
   
    int medio = (inicio + fin) /2;
    mergeSort(Id, nivelImpacto, nivelRiesgo, inicio, medio, cat);
    mergeSort(Id, nivelImpacto, nivelRiesgo, medio+1, fin, cat);
    //Se utiliza la misma funcion. el orden varia segun el merge
    /* 1: por Nivel Riesgo, 2: impato, 3 : ID*/
    if(cat == 1){
        merge1(Id, nivelImpacto, nivelRiesgo, inicio, medio, fin);
    }
    if(cat == 2){
        merge2(Id, nivelImpacto, nivelRiesgo, inicio, medio, fin);
    }
    if(cat == 3){
        merge3(Id, nivelImpacto, nivelRiesgo, inicio, medio, fin);
    }
}

void imprimir(int Id[N],int nivelImpacto[N],int nivelRiesgo[N], int n, int cat){
        for(int i=0; i<n; i++){
            cout<<Id[i]<<"-"<<nivelImpacto[i]<<"-"<<nivelRiesgo[i]<<"  ";
        }
        if(cat == 1) cout<<"por ID de Riesgo"<<endl;
        else if(cat == 2) cout<<"por Impacto"<<endl;
        else if(cat == 3)cout<<"por Nivel de Riesgo"<<endl;
        else cout<<endl;
}

int main() {
    int Id[N] = {4,1,5,7,6,3,2};
    int nivelImpacto[N] = {1,2,3,2,3,2,1};
    int nivelRiesgo[N] = {3,4,9,2,6,6,2};
    int n = 7;
    
    cout<<"Lista de riesgo: (ID - Impacto - Nivel de riesgo)"<<endl;
    imprimir(Id, nivelImpacto, nivelRiesgo, n, 0);
    /* 1: por Nivel Riesgo, 2: impato, 3 : ID*/
    mergeSort(Id, nivelImpacto, nivelRiesgo, 0, n-1, 3);
    imprimir(Id, nivelImpacto, nivelRiesgo, n, 3);
    
    mergeSort(Id, nivelImpacto, nivelRiesgo, 0, n-1, 2);
    imprimir(Id, nivelImpacto, nivelRiesgo, n, 2);
    
    mergeSort(Id, nivelImpacto, nivelRiesgo, 0, n-1, 1);
    imprimir(Id, nivelImpacto, nivelRiesgo, n, 1);
    
    
    return 0;
}

