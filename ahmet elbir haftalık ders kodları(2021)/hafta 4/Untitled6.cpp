#include <stdio.h>
#include <stdlib.h>
int main(){
	int i,j,N, M;
	scanf("%d %d",&N, &M);
	int **matris;
	matris= (int**) malloc(N*sizeof(int*));
	for(i=0;i<N;i++){
		matris[i] = (int*) malloc(M*sizeof(int));
	}
	
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			matris[i][j]=5;
		}
	}
	
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			printf("%5d-",(*(matris+i)+j));
		}
		
		printf("\n");
	}
	printf("\n");
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			printf("%5d",*(*(matris+i)+j));
		}
		
		printf("\n");
	}
}
/*
output:
5
5
2036880-2036884-2036888-2036892-2036896-
2036912-2036916-2036920-2036924-2036928-
2036944-2036948-2036952-2036956-2036960-
2036976-2036980-2036984-2036988-2036992-
2037008-2037012-2037016-2037020-2037024-

    5    5    5    5    5
    5    5    5    5    5
    5    5    5    5    5
    5    5    5    5    5
    5    5    5    5    5
*/
