#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void print_matrix(int **, int N);
int main(){
	int N;
	int *p=&N;
	int i;
	for(i=0;i<50;i++){
		printf("%d %d\n",i,*(p+i));
		*(p+i)=i;
	}
	/*int **matris, **tmp;
	int i, j;
	int s=0;
	
	printf("N=?"); scanf("%d",&N);
	matris = (int**) malloc(N*sizeof(int*));
	for(i=0;i<N;i++){
		matris[i] = (int*) malloc(N*sizeof(int));
	}
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			matris[i][j]=rand()%5 + 1;
		}
	}
	print_matrix(matris, N-1);
	
	tmp = (int**) realloc(matris,(N+1)*sizeof(int*));
	if(tmp!=NULL){
		matris=tmp;
	}
	matris[N]=(int*)malloc((N)*sizeof(int));
	for(i=0;i<N-2;i++){
		matris[i] = (int*) realloc(matris[i],(N+1)*sizeof(int));
	} 
	
	for(i=0;i<N;i++){
		matris[N][i]=matris[i][N]=0;
		for(j=0;j<N;j++){
			matris[i][N] += matris[i][j];
			matris[N][i] += matris[j][i];	
		}
		s = s + matris[i][N] + matris[N][i];
	}
	matris[N][N] = s;
	
	print_matrix(matris, N);
	*/
	
}

void print_matrix(int **matris, int N){
	int i, j;
	for(i=0;i<=N;i++){
		for(j=0;j<=N;j++){
			printf("%3d ",matris[i][j]);
		}
		printf("\n");
	}
}
/*
0 0
1 6487564
*/

