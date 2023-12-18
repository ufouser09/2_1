#include <stdio.h>
#include <stdlib.h>
void free_matris(int **,int);
int **matris_compress(int **,int ,int ,int);
void enter_data(int **,int ,int);
void display_matris(char *,int **,int ,int );
int **matrix_allocate(int ,int );
int main(){
	int M,N;
	int **matris,**c_matrix;
	int i,j,counter=0;
	printf("M ve N ");
	scanf("%d %d",&M,&N);
	
	 matris=matrix_allocate(M,N);
	
	enter_data(matris,M,N);
	counter=count_data(matris,M,N);//dusuk baglasým yuksek uyum
	display_matris("orijinal matris\n",matris,M,N);
	c_matrix=matris_compress(matris,M,N,counter);  
	display_matris("compressed matrix\n",c_matrix,counter,3);
	
	free_matris(matris,M);
	free_matris(c_matrix,counter);
	return 0;
}
void free_matris(int **matris,int M){
	int i;
	for(i=0;i<M;i++){
		free(matris[i]);
	}
	free(matris);
}
int **matrix_allocate(int M,int N){
	int **m;
	int i;
	m=(int**)malloc(M*sizeof(int*));
	for(i=0;i<M;i++){
		m[i]=(int*)malloc(N*sizeof(int));
	}
	return m;
}
int **matris_compress(int **matris,int M,int N,int counter){
	int **m=matrix_allocate(counter,3);
	int i,j,k=0;
	
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			if(matris[i][j]!=0){
				m[k][0]=i;
				m[k][1]=j;
				m[k][2]=matris[i][j];
				k++; 
			}
			
		}
	}
	return m;
}
void enter_data(int **matris,int M,int N){
	int i,j;
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			printf("matris[%d][%d]",i,j);
			scanf("%d",&matris[i][j]);
			//(*(matris+i)+j) boyle olunca ampersanta gerek yok
		}
	}
}
void count_data(int **matris,int M,int N){
	int i,j;
	int c=0;
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			if(matris[i][j]!=0){
				c++;
			}
			
		}
	}
return c;
}

void display_matris(char *str,int **matris,int M,int N){
	int i,j;
	printf("%s",str);
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			printf("%3d",*(*(matris+i)+j));
		}
		printf("\n");
	}
}

