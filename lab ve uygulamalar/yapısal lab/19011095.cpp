#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int N,i,j;
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
			matris[i][j]=(rand%100)+1;
		}
	}
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			print("%d",matris[i][j]);
		}
	}
	
	for (int i = 0; i < N; i++){
		free(matris[i]);
	}
	free(matris);
	
	return 0;
}
