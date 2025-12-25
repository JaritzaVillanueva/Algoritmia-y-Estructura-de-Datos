/*
	* Author: Jaritza
	* Codigo: 20213699
*/

#include <iostream>
#include <cmath>
#define N 5
using namespace std;

void cargaBin(int n,int cromosoma[], int size){
	for(int i=0;i<size;i++) cromosoma[i] = 0;
	int aux, i = 0;
	while(n>0){
		cromosoma[i++] = n%2;
		n = n/2;
	}
}

int main(){
	const int size = 5;
	int pesos[size] = {1,2,4,12,1};
	int cromosoma[N];
	int peso = 15; //maximo 
	
	int combinaciones = pow(2,size);
	for(int i=1; i<combinaciones; i++){
		cargaBin(i, cromosoma, size);
		int pParcial = 0;
		for( int j=0; j<size; j++){
			if(cromosoma[j] == 1){
				pParcial += pesos[j];
			}
		}
		
		if(pParcial == peso){
			cout<<"Solucion "<<i<<endl;
			for(int i=0; i<size; i++){
				cout<<cromosoma[i]*pesos[i]<<" ";
			}
			cout<<endl;
		} 
	}
	return 0;
}
