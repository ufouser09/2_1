#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int real;
	int imag;
}COMPLEX;

COMPLEX *karmasik_sayi_uret(int);
void dizi_yazdir(COMPLEX *c,int N);
int main(){
	srand(time(NULL));
	COMPLEX *c1;
	
	int N;
	printf("eleman sayisi giriniz\n");
	scanf("%d",&N);
	
	c1=karmasik_sayi_uret(N);
	dizi_doldur(c1,N);
	dizi_yazdir(c1,N);
	Complex C2=karmasik_sayi_uret2();//her zaman structlarda dogru olmaz
	
	/*printf("%d - %d\n",c1.real,c1.imag);
	c1=karmasik_sayi_uret();
	printf("%d -%d \n",c1.real,c1.imag);*/
	free(c1);
}
COMPLEX *karmasik_sayi_uret(int N){
	COMPLEX *c=malloc(N*sizeof(COMPLEX));
	if(c!=NULL){
		printf("basarili");
		
	}
	return c;
}
COMPLEX karmasik_sayi_uret2(){
	COMPLEX c;
	c.imag=0;
	c.real=0;
	return c;
}
void dizi_doldur(COMPLEX *c,int N){
	int i=0;
	for(i=0;i<N;i++){
		c[i].real=rand()%10;
		c[i].imag=rand()%10;
	}
}
void dizi_yazdir(COMPLEX *c,int N){
	int i=0;
	COMPLEX *tmp=c;
	for(i=0;i<N;i++){
		printf("\n%d + %di",c[i].real,c[i].imag);
	}
	printf("\nYazdirma_2");
	for(i=0;i<N;i++){
		printf("\n%d + %di",tmp->real,tmp->imag);
		tmp++;
	}
	//bunu da yapmak mumkun.
	/*for(i=0;<N;i++){
		printf("%d + %di\n",*(c+i).real,*(c+i).imag);
	}*/
}


