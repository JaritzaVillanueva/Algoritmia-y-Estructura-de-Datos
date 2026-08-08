#include <cstdlib>
#include <iostream>
#define N 10

using namespace std;

/*
 * 
 */

int buscarCentro(int arreglo[N],int inicio,int medio,int fin){
    int cuentaIzq, cuentaDer;
    if (arreglo[medio]<arreglo[medio+1]){
        /*Evaluo para la izquierda*/
        cuentaIzq = 1;
        for (int k=medio; k>=inicio; k--){
            if (arreglo[k-1]<arreglo[k]){
                cuentaIzq++;
            }
            else{
                break;
            }
        }
        /*Evaluo para la derecha*/
        cuentaDer = 1;
        for (int k=medio+1; k<=fin; k++){
            if (arreglo[k]<arreglo[k+1]){
                cuentaDer++;
            }
            else{
                break;
            }
        }
        return cuentaIzq + cuentaDer;
    }
    else{
        return 1;
    }
}

int buscaIncrementos(int arreglo[N],int inicio,int fin){
    if (inicio==fin){
        return 1;
    }
    int medio = (inicio+fin)/2;
    int incrementosIzq = buscaIncrementos(arreglo,inicio,medio);
    int incrementosDer = buscaIncrementos(arreglo,medio+1,fin);
    int incrementoCentro = buscarCentro(arreglo,inicio,medio,fin);
    if (incrementosIzq>=incrementosDer && incrementosIzq>=incrementoCentro){
        return incrementosIzq;
    }
    else {
        if (incrementosDer>=incrementosIzq && incrementosDer>=incrementoCentro){
            return incrementosDer;
        }
        else{
            return incrementoCentro;
        }
    }
}

int main(int argc, char** argv) {
    int arreglo[N] = {10,20,15,10,12,10,13,18};
    int n=10;
    int incrementos = buscaIncrementos(arreglo,0,n-1);
    cout << "Hay un incremento de " << incrementos << endl;
    cout << "Indice de incrementos es " << ((double)incrementos/n);
    
    return 0;
}