/* 
 * File:   main.cpp
 * Author: Jaritza Villanueva
 *
 * Created on 4 de mayo de 2024, 19:05
 */

#include <iostream>
using namespace std;
#define N 10

int calcularCentro(int arr[N],int inicio,int medio,int fin){
    int cuentaIzq, cuentaDer;
    if(arr[medio]<arr[medio+1]){
        cuentaIzq=1;
        for(int i=medio; i>=inicio; i--){
            if(arr[i-1]<arr[i]) cuentaIzq++;
            else break;
        }
        cuentaDer = 1;
        for(int i=medio+1; i<=fin; i++){
            if(arr[i]<arr[i+1]) cuentaDer++;
            else break;
        }
        return cuentaDer + cuentaIzq;
    }
    return 1;
}

int calcularIntervalo(int arr[N], int inicio, int fin){
    if(inicio == fin) return 1;
    int medio = (inicio+fin)/2;
    int cuentaDer = calcularIntervalo(arr, inicio, medio);
    int cuentaIzq = calcularIntervalo(arr, medio+1, fin);
    int cuentaCentro = calcularCentro(arr, inicio, medio, fin);
    if(cuentaCentro>= cuentaDer && cuentaCentro>=cuentaIzq){
        return cuentaCentro;
    }else if(cuentaDer>=cuentaCentro && cuentaDer>=cuentaIzq){
        return cuentaDer;
    }
    else return cuentaIzq;
}

int main() {
    //ingreso de datos
    int dias[N]{}, n;
    cout<<"Ingrese el numero de dias: ";
    cin>>n;
    cout<<"Listan de cifras: ";
    for(int i=0; i<n; i++){
        cin>>dias[i];
    }
    //implementacion
    int resultado = calcularIntervalo(dias, 0, n-1);
    cout<<"El intervalo maximo de incrementos es: ";
    cout<<resultado<<endl;
    cout<<"El intervalo es: "<<(double)resultado/n<<endl;
    return 0;
}

