#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int enbuyuk_bul(int **matris,int N);
void liste_yazdir(int **matris,int N);
int main(){
	int **matris;
	int N,i,j;
	
	printf("N degeri");
	scanf("%d",&N);
	
	matris=(int**)malloc(N*sizeof(int*));
	for(i=0;i<N;i++){
		matris[i]=(int*)malloc(2*sizeof(int));
	}
	for(i=0;i<N;i++){
		printf("%d. reel part",i);
		scanf("%d",&matris[i][0]);
		
		printf("%d. sanal part",i);
		scanf("%d",&matris[i][1]);
	}
	liste_yazdir(matris,N);
	i=enbuyuk_bul(matris,N);
	printf("en buyuk deger=%d.satirdadir",i);
	for(i=0;i<N;i++){
		free(matris[i]);
	}
	free(matris);
}
int enbuyuk_bul(int **matris,int N){
	int i,maxI=0,tmp=0,tmp2=0;
	for(i=0;i<N;i++){
		tmp=matris[i][0]*matris[i][0]+matris[i][1]*matris[i][1];
		tmp2=matris[maxI][0]*matris[maxI][0]+matris[maxI][1]*matris[maxI][1];
		if(tmp>tmp2){
			maxI=i;
		}
	}
	return maxI; 
}
void liste_yazdir(int **matris,int N){
	int i;
	for(i=0;i<N;i++){
		 printf("%d -> %d",i,matris[i][0]);
		 if(matris[i][1]!=0){
		 	if(matris[i][1]>0){
		 		printf(" + ");
			 }
			 else{
			 	printf(" - ");
			 }
			 printf("%di\n",abs(matris[i][1]));
		 } 
		 printf("\n");
	}
}

