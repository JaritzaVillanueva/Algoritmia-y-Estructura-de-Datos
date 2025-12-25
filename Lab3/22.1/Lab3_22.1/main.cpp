/* 
 * Proyecto: Lab3_22.1
 * File:   main.cpp
 * Author: Jaritza
 * Codigo: 20213699
 * Created on 29 de septiembre de 2023, 08:46 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;
#define N 10

int max(int a, int b) { return (a > b)? a : b; } 
int max2(int a, int b, int c) { return max(max(a, b), c); } 
  
int merge(int arr[], int l, int m, int h) 
{ 	int i;
    int left_sum = 1; 
    for (i = m; i > l; i--) 
    { 
        if (arr[i] > arr[i-1]) ++left_sum; 
        else
			break;  
    } 
  
    int right_sum = 1; 
    for (i = m+1; i < h; i++) 
    { 
        if (arr[i+1] >arr[i] ) ++right_sum; 
        else 
        	break;
    } 
  
	if(arr[m]<arr[m+1])
 		return right_sum+left_sum;
 	return 1;
} 
  
int maxSubArraySum(int arr[], int ini, int fin) 
{ 
	int der,izq,centro;
	if(ini==fin)
		return 1;
		
	int medio = (ini+fin)/2;
	izq=maxSubArraySum(arr,ini,medio);
	der=maxSubArraySum(arr,medio+1,fin);
	centro=merge(arr,ini,medio,fin);
	//printf("%d %d %d\n",izq,centro,der);
	return max2(izq,der,centro);
} 
  
/*Driver program to test maxSubArraySum*/
int main() 
{ 
   int arr[] = {9,10,11,13,8,10,13,18}; 
  // int arr[] = {7,2,9,10,16,10,13,8,2,10}; 
   int n = 8; 
   int max_sum = maxSubArraySum(arr, 0, n-1); 
   cout << max_sum; 
   return 0; 
} 