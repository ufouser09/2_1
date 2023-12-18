#include <stdio.h>
#include "menu.h"
#include "sirala.c"
int main(){
	int N,i;
	int sonuc=0;
	printf("lutfen dizinin boyutunu giriniz\n");
	scanf("%d",&N);
	
	int A[N];
	
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	int max1,max2,min1,min2;
	
	
	max1=A[0];
	max2=A[0];
	min1=A[0];
	min2=A[0];
	
	sonuc=sirala(A,min1,min2,max1,max2,N);
	
	printf("%d",sonuc);
	
}
