#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct complex{
	int reel;
	int sanal;
}CMP;
#define N 3
int enbuyuk_bul2(CMP *c,int n);
CMP enbuyuk_bul3(CMP *c,int n);
int main(){
	CMP c0;//structla bu iþlemi yapabiliriz
	int i;
	CMP *c1,**c2,*c3;//structla bu iþlemi yapabiliriz
	CMP C3[10];//structla bu iþlemi yapabiliriz
	c1= (CMP*)malloc(N*sizeof(CMP));
	//c1=(struct complex*)malloc(N*sizeof(struct complex));(yukardaki iþlemi boyle de yapabiliriz ama biz yukardakini tercih ediyoruz.)
	for(i=0;i<N;i++){
		printf("%d.reel part",i);
		scanf("%d",&c1[i].reel);
		
		printf("%d.sanal part",i);
		scanf("%d",&c1[i].sanal);
	}
	i=enbuyuk_bul2(c1,N);
	printf("En buyuk =%d---> %d + %di",i,c1[i].reel,c1[i].sanal);
	c0=enbuyuk_bul3(c1,N);
	printf("%p",&c0);
	printf("En buyuk bul 2 =%d + %di",c0.reel,c0.sanal);
	free(c1);
}
CMP enbuyuk_bul3(CMP *c,int n){
	int i,maxI=0,tmp=0,tmp2=0;
	CMP c2;
	for(i=0;i<N;i++){
		tmp=pow(c[i].reel,2)+pow(c[i].sanal,2);
		tmp2=pow(c[maxI].reel,2)+pow(c[maxI].sanal,2);
		if(tmp>tmp2){
			maxI=i;
		}
	}
	printf("%p",&c2);
	c2.reel=c[maxI].reel;
	c2.sanal=c[maxI].sanal;
	return c2;
	
}
int enbuyuk_bul2(CMP *c,int n){
	int i,maxI=0,tmp=0,tmp2=0;
	CMP c2;//bu static bir elemandýr.
	for(i=0;i<N;i++){
		tmp=pow(c[i].reel,2)+pow(c[i].sanal,2);
		tmp2=pow(c[maxI].reel,2)+pow(c[maxI].sanal,2);
		
		if(tmp>tmp2){
			maxI=i;
		}
	}
	c2.reel=c[i].reel;
	c2.sanal=c[i].sanal;
	return c2;	
}
