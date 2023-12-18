#include<stdio.h>
int main(int argc, char *argv[] ){
	int sayi1, sayi2,sayi3; int dizi[5];
	/*printf("%d:",argc);
	printf("\n%s:",argv[0]);
	printf("\n%s:",argv[1]);
	printf("\n%d:",atoi(argv[2])+3);*/
	
	/*scanf("%d",&sayi1);
	scanf("%d",&sayi2);
	scanf("%d",&sayi3);
	printf("%d -- %d---%d",sayi1,sayi2,sayi3);*/
	for(sayi1=0;sayi1<5;sayi1++){
		scanf("%d",&dizi[sayi1]);
		printf("%d-",dizi[sayi1]);
	}
	
}
/*
output
5
5-5
5-5
5-5
5-5
5-
*/
