#include <iostream>
#include <cmath>
#define MAXCOL 5
#define MAXFIL 7

int m[8][2];


using namespace std;

void movimientos(){
	m[0][0]=-1; m[0][1]=0; 
	m[1][0]=-1; m[1][1]=1;
	m[2][0]=0;  m[2][1]=1;	
	m[3][0]=1;  m[3][1]=1;
	m[4][0]=1;  m[4][1]=0;
	m[5][0]=1;  m[5][1]=-1;	
	m[6][0]=0;  m[6][1]=-1;	
	m[7][0]=-1;  m[7][1]=-1;		
	
}
// B I C A
int buscaletra(char tablero[][MAXCOL],int i,int j,
	char palabra[],int n){
	int nfil,ncol;
	if(tablero[i][j]!=palabra[0]) return 0;
	
	for(int k=0;k<8;k++){
		nfil = i + m[k][0];
		ncol = j + m[k][1];
		int p;
		for(p=1;p<n;p++){
			if(nfil<0 || nfil>=MAXFIL || ncol<0 || ncol>=MAXCOL)		
				break;
			if(tablero[nfil][ncol]!=palabra[p])	
				break;
			nfil = nfil + m[k][0];
			ncol = ncol + m[k][1];	
		}
		if(p==n) return 1;
	}
	return 0;	
}


void buscapalabra(char tablero[][MAXCOL],char palabra[],int n){
	
	for(int i=0;i<MAXFIL;i++)
		for(int j=0;j<MAXCOL;j++)
			if(buscaletra(tablero,i,j,palabra,n))
				cout<< "La palabra empieza en:" << i << " " << j<< endl; 
	
}


int main(){
	int n=4;
	char palabra[]={'B','I','C','A'};
	char tablero[][MAXCOL]={{'J','I','R','Y','U'},
							{'D','B','I','C','0'},
							{'H','I','L','B','Q'},
							{'X','C','X','I','A'},
							{'B','A','C','A','S'},
							{'O','B','I','C','A'},
							{'E','C','D','I','R'}};
	movimientos();						
	buscapalabra(tablero,palabra,n);
							
	return 0;
}






