/*
	* Author: Jaritza
	* Codigo: 20213699
*/

#include <iostream>
#include <cmath>
#define N 10 //cantidad maxima en un cromosoma
using namespace std;
/*
En este caso:
 bahia1		bahia2		bahia3
 cromo1		cromo2		cromo3
 
 entonces abria 3 cromos
 Por tanto:
 for cromo1
 	for cromo2
 		for cromo3
*/

void cargaBin(int n,int cromosoma[], int size){
	for(int i=0;i<size;i++) cromosoma[i] = 0;
	int aux, i = 0;
	while(n>0){
		cromosoma[i++] = n%2;
		n = n/2;
	}
}

int main(){
	int n = 4;
	int bahias [3][4]= {{2,5,6,10},
						{7,8,15,3},
						{11,9,6,4}
						};
	int m = 5;
	int cromo1[N], cromo2[N], cromo3[N];
	int c = 20; //maximo 
	int solucion = -1;
	
	int combinaciones = pow(2,n);
	//combinaciones bahia1
	for(int i=0; i<combinaciones; i++){ //esta bien que inicie con 0, porque puede que ningun valor de bahia1 sea aceptable
		cargaBin(i, cromo1, n);
		for( int j=0;j<combinaciones;j++){
			cargaBin(i, cromo2, n);
			for( int k = 0; k<combinaciones; k++){
				cargaBin(i, cromo3, n);
				//evaluar condiciones de las 3 bahias
				int peso = 0;
				int cantProd = 0;
				//evaluar condiciones de la bahia 1
				for(int l = 0; l<n; l++){
					if(cromo1[l] == 1){
						peso += bahias[0][l];
						cantProd++;
					}
				}
				//evaluar condiciones de la bahia 2
				for(int l = 0; l<n; l++){
					if(cromo2[l] == 1){
						peso += bahias[1][l];
						cantProd++;
					}
				}
				//evaluar condiciones de la bahia 3
				for(int l = 0; l<n; l++){
					if(cromo3[l] == 1){
						peso += bahias[2][l];
						cantProd++;
					}
				}
				
				//evaluar condicion general
				if(peso == c && cantProd == m){
					solucion = 1;
					cout<<"bahia 1: ";
					for(int i=0; i < n; i++){
						cout<<cromo1[i]*bahias[0][i]<<" ";
					}
					cout<<"bahia 2: ";
					for(int i=0; i < n; i++){
						cout<<cromo2[i]*bahias[1][i]<<" ";
					}
					cout<<"bahia 3: ";
					for(int i=0; i < n; i++){
						cout<<cromo3[i]*bahias[2][i]<<" ";
					}
					cout<<endl;
					//break;
				}
			}
		}
	}
	return 0;
}
