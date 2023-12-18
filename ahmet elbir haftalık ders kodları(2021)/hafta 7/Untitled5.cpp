#include <stdio.h>
#include <stdlib.h>
typedef struct{
	int derece;
	double katsayi;
}TERIM;

typedef struct{
	TERIM *terimler;
	int terimsayisi;	
}POLINOM;

int main(){
	srand(time(NULL));
	int N;
	int i;

	
	POLINOM *p2;
	printf("Terim sayisi giriniz"); scanf("%d",&N);
	p1.terimsayisi=N;
	p1.terimler = (TERIM*) malloc(p1.terimsayisi*sizeof(TERIM));
	
	for(i=0;i<p1.terimsayisi;i++){
		p1.terimler[i].derece = i;
		p1.terimler[i].katsayi = rand() %5;
	}
	
	for(i=0;i<p1.terimsayisi-1;i++){
		printf("%2.1lf X ^ %d + ",p1.terimler[i].katsayi, p1.terimler[i].derece);
	}
	printf("%2.1lf X ^ %d\n",p1.terimler[i].katsayi, p1.terimler[i].derece);
	
	for(i=p1.terimsayisi-1;i>0;i--){
		printf("%2.1lf X ^ %d + ",p1.terimler[i].katsayi, p1.terimler[i].derece);
	}
	printf("%2.1lf X ^ %d\n",p1.terimler[i].katsayi, p1.terimler[i].derece);
	
	for(i=0;i<p1.terimsayisi;i++){
		printf("%d. terimin katsayisi ve derecesi",i);
		scanf("%lf",&p1.terimler[i].katsayi);
		scanf("%d",&p1.terimler[i].derece);	
	}
	
	for(i=0;i<p1.terimsayisi-1;i++){
		printf("%2.1lf X ^ %d + ",p1.terimler[i].katsayi, p1.terimler[i].derece);
	}
	printf("%2.1lf X ^ %d\n",p1.terimler[i].katsayi, p1.terimler[i].derece);
	
	p2 = &p1;
	for(i=0;i<p2->terimsayisi-1;i++){
		printf("%2.1lf X ^ %d + ",p2->terimler[i].katsayi,(*p2).terimler[i].derece);
	}
	printf("%2.1lf X ^ %d\n",p2->terimler[i].katsayi,(*p2).terimler[i].derece);
	
	for(i=0;i<p1.terimsayisi;i++){
		printf("%d. terimin katsayisi ve derecesi",i);
		scanf("%lf",&p2->terimler[i].katsayi);
		scanf("%d",&p2->terimler[i].derece);	
	}
	
	for(i=0;i<p2->terimsayisi-1;i++){
		printf("%2.1lf X ^ %d + ",p2->terimler[i].katsayi,(*p2).terimler[i].derece);
	}
	printf("%2.1lf X ^ %d\n",p2->terimler[i].katsayi,(*p2).terimler[i].derece);
	
}
//bu kodda bi sorun var
