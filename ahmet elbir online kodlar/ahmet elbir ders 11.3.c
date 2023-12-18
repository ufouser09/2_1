#include <stdio.h>

typedef struct cmp{
	int r:5;
	int i:3;
}CMP;

typedef union{
	struct {
		char c1,c2;
	}s;
	long j;
	float x;
}U;


int main(){
	
	
	//CMP s;
	//scanf("%d",&s.r);//bunlar hata verir bu bit field alanýnýn adresi alýnamaz.peki çözum ne çözum gecici degisken kullanmak.
	//scanf("%d",&s.i);
	/*
	CMP s[5];
	int x;
	scanf("%d",&x);
	if(x>=0 && x <32){
		s[4].r=x;
	}
	scanf("%d",&s.i);//illegal */
	U example;
	example.s.c1='a';
	example.s.c2='b';
	printf("%c\n",example.s.c1);
	printf("%d",example.j);
	example.x=5.56;
	printf("%c\n",example.s.c1);
	printf("%ld",example.j);
	
}
