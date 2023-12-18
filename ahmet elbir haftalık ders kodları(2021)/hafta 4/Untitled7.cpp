#include<stdio.h>
int f();
int* g();
int* h();
int main(){
	int a;
	int *p;
	a=f();
	printf("%d:\n",a);
	p=g();
	printf("%d:\n",*p);
	p=h();
	printf("%d:\n",*(p+44));
	//a=g();
}

int f(){
	int x=6;
	return x;
}

int* g(){
	int *p;
	int x=7;
	int dizi[100];
	p=&x;	
	return dizi;
}

int* h(){
	 int dizi[100]={0};
	return dizi; // &dizi[0], &dizi, dizi
}
/*
output:
6:
6029427:
0:
*/
