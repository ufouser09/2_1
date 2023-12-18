#include <stdio.h>
#include <stdlib.h>
void fillArray(int *dizi, int n);
void printArray(int *dizi, int n);
int main(){
	int *dizi;
	int *tmp;
	int N=1;
	dizi = (int*) malloc(N*sizeof(int));
	fillArray(dizi,N);
	printArray(dizi,N);
	do{
		printf("Yen, boyutu giriniz");
		scanf("%d",&N);
		//dizi=realloc(dizi,N*sizeof(int));// danger!
		//tmp = realloc(dizi,N*sizeof(int));// danger!
		if(N==0){
			printf("dizi serbest býrakýldý");
			return 0;
		}
		if(tmp!=NULL){
			dizi = tmp;
			printf("%p\n",dizi);
			fillArray(dizi,15);
			printArray(dizi,N);	
		}else{
			printf("Hata");
			return -1;
		}
		
	}
	while(N>=0);
	free(dizi);
}

void fillArray(int *dizi, int n){
	int i;
	for(i=0;i<n;i++){
		dizi[i]=i;
	}
}

void printArray(int *dizi, int n){
	int i;
	for(i=0;i<n;i++){
		printf("%3d ",dizi[i]);
	}
	printf("\n===============================\n");
}
//bu koda bi da bak
