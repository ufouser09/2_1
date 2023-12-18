#include <stdio.h>
#include "menu.h"
int sirala(int A[],int min1,int min2,int max1,int max2,int N){
	int toplam=0;
	int i;
	
	
	max1=A[0];
	max2=A[0];
	min1=A[0];
	min2=A[0];
	for(i=0;i<N;i++){
		if(min2>A[i]){
			
			if(min1>A[i]){
				min2=min1;
				min1=A[i];
			}else{
				min2=A[i];
			}
			
		}
	}
	for(i=0;i<N;i++){
		if(max2<A[i]){
			
			if(max1<A[i]){
				max2=max1;
				max1=A[i];
			}
			else{
				max2=A[i];
			}
			
		}
	}
	toplam=max1+max2+min1+min2;
	
	return toplam;
}

