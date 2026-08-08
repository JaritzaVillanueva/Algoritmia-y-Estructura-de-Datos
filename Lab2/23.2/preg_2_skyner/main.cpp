/* 
 * File:   main.cpp
 * Author: Jaritza Villanueva
 *
 * Created on 12 de abril de 2024, 14:13
 */

#include <iostream>

using namespace std;
#define M 7

 int skyner(int x, int y, int tablero[][M],int n){
    //casos bases
     //Encontraron al skynner
     if(x == n) return y+1;
     //no hubo nada
     if(y == n) return 0;
     
     //procedimiento
     if(tablero[x][y] == 0){
         skyner(x+1, y, tablero, n);
     }else{
         skyner(0, y+1, tablero, n);
     }
}

int main(int argc, char** argv) {
    int n, result;
    cout<<"Ingresa el valor de n: ";
    cin>>n;
    int servidores[M][M];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>servidores[i][j];
        }
    }
    
    result = skyner(0,0,servidores, n);
    if(result != 0)
        cout<<"SkyNerd ha sido detectado en el servidor: "<<result<<endl;
    else cout<<"SkyNerd no esta en la red."<<endl;
    
    return 0;
}

