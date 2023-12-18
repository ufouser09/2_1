#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int main() {
	int N,i,j,satir,sutun;
	int** matris;
	
	printf("lutfen dizinin satir ve sutun sayisini giriniz\n ");
	scanf("%d",&N);
	srand(time(0));
	
	matris=(int**)malloc(N*sizeof(int*));
	if(matris==NULL){
		printf("bellekte yer ayrilmadi");
		return -1;
	}
	
	for(i=0;i<N;i++){
		matris[i]=(int*)malloc(N*sizeof(int));
		if(matris[i]==NULL){
			printf("bellekte yer ayrilmadi\n");
			return -1;
		}
	}
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			matris[i][j]=(rand()%100)+1;
		}
	}
	
	matris=(int**)realloc(matris,(N+1)*sizeof(int*));
	if(matris==NULL){
		printf("bellekte yer ayrilmadi");
		return -1;
	}
	
	for(i=0;i<N+1;i++){
		matris[i]=(int*)realloc(matris[i],(N+1)*sizeof(int));
		if(matris[i]==NULL){
			printf("bellekte yer ayrilmadi\n");
			return -1;
		}
	}
	
	
	for(i=0;i<N;i++){
		satir=0;
		sutun=0;
		for(j=0;j<N;j++){
			satir=satir+matris[i][j];
			sutun=sutun+matris[j][i];	
			printf("%d\n",matris[N][i]);
			printf("%d\n",matris[N][j]);
		}
		matris[i][N]=satir;
		matris[N][i]=sutun;
		printf("\n");
	}
	
	for(i=0;i<N+1;i++){
		for(j=0;j<N+1;j++){
			printf("%d ",matris[i][j]);
		}
		printf("\n");
	}
	
	for (i = 0; i < N; i++){
		free(matris[i]);
	}
	free(matris);
	
	
	return 0;
}
