#include <stdio.h>
typedef struct {
	unsigned int d;
	unsigned int m;
	unsigned int y;
}DATE;  // 12 byte 96 bit

typedef struct {
	unsigned int d;
	unsigned int m;
	unsigned int y;
}DATE1;

typedef struct {
	unsigned int d:5;
	unsigned int m:4;
	unsigned int y:11;
}MYDATE;  // 4 byte 32 bit

int main(){
	int gun, ay, yil;
	printf("Size of (DATE)=%d ",sizeof(DATE));
	printf("Size of (MYDATE)=%d ",sizeof(MYDATE));
	
	DATE d;
	printf("Enter day month and year");
	scanf("%d %d %d",&d.d,&d.m,&d.y);
	printf("%d %d %d",d.d,d.m,d.y);
	
	MYDATE d2, d3;
	printf("Enter day month and year");
	//scanf("%d %d %d",&d2.d,&d2.m,&d2.y); illegal because we cannot take address of bitfilds
	scanf("%d %d %d",&gun,&ay,&yil);
	if(gun>=1 && gun <=31 && ay>=1 && ay<=13){
		d2.d=gun;
		d2.m=ay;
		d2.y=yil;
	}
	
	MYDATE d4[10];
	
}
