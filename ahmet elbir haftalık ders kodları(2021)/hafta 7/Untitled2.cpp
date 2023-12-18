#include <stdio.h>

typedef struct terim{
	int derece;
	double katsayi;
	struct terim *next;
}TERIM;

typedef struct polinom{
	TERIM *head;
	TERIM *last;
	int terimSayisi;	
}POLINOM;

int main(){
	POLINOM p1, p2;
	TERIM t1={1,1};
	TERIM t2={2,2};
	TERIM t3={3,3};
	TERIM *thead, *tmp;
	thead=&t3;
	t3.next = &t2;
	t2.next = &t1;
	t1.next = NULL;
	tmp=thead;
	while(tmp!=NULL){
		printf("Derece %d Katsayi %lf\n",tmp->derece,tmp->katsayi);
		tmp = tmp->next;
	}
	
	p1.head = &t1;
	t1.next = &t2;
	t2.next = &t3;
	t3.next = &t1;
	tmp = p1.head;
	while(tmp!=NULL){
		printf("Derece %d Katsayi %lf\n",tmp->derece,tmp->katsayi);
		tmp = tmp->next;
	}
	
	
}
/*
output:
Derece 3 Katsayi 3.000000
Derece 2 Katsayi 2.000000
Derece 1 Katsayi 1.000000
Derece 1 Katsayi 1.000000
Derece 2 Katsayi 2.000000
Derece 3 Katsayi 3.000000
Derece 1 Katsayi 1.000000
Derece 2 Katsayi 2.000000
Derece 3 Katsayi 3.000000
Derece 1 Katsayi 1.000000
Derece 2 Katsayi 2.000000
Derece 3 Katsayi 3.000000
Derece 1 Katsayi 1.000000
Derece 2 Katsayi 2.000000
Derece 3 Katsayi 3.000000
Derece 1 Katsayi 1.000000
Derece 2 Katsayi 2.000000
Derece 3 Katsayi 3.000000
Derece 1 Katsayi 1.000000
Derece 2 Katsayi 2.000000
Derece 3 Katsayi 3.000000
Derece 1 Katsayi 1.000000
Derece 2 Katsayi 2.000000
Derece 3 Katsayi 3.000000
Derece 1 Katsayi 1.000000
Derece 2 Katsayi 2.000000
Derece 3 Katsayi 3.000000
Derece 1 Katsayi 1.000000
Derece 2 Katsayi 2.000000
Derece 3 Katsayi 3.000000
Derece 1 Katsayi 1.000000
Derece 2 Katsayi 2.000000
Derece 3 Katsayi 3.000000
Derece 1 Katsayi 1.000000
Derece 2 Katsayi 2.000000
Derece 3 Katsayi 3.000000
Derece 1 Katsayi 1.000000
Derece 2 Katsayi 2.000000
Derece 3 Katsayi 3.000000
Derece 1 Katsayi 1.000000
Derece 2 Katsayi 2.000000
Derece 3 Katsayi 3.000000
Derece 1 Katsayi 1.000000
Derece 2 Katsayi 2.000000
Derece 3 Katsayi 3.000000
Derece 1 Katsayi 1.000000
Derece 2 Katsayi 2.000000
Derece 3 Katsayi 3.000000
Derece 1 Katsayi 1.000000
Derece 2 Katsayi 2.000000
Derece 3 Katsayi 3.000000
Derece 1 Katsayi 1.000000
Derece 2 Katsayi 2.000000
Derece 3 Katsayi 3.000000
Derece 1 Katsayi 1.000000
Derece 2 Katsayi 2.000000
Derece 3 Katsayi 3.000000
Derece 1 Katsayi 1.000000
Derece 2 Katsayi 2.000000
Derece 3 Katsayi 3.000000
Derece 1 Katsayi 1.000000
Derece 2 Katsayi 2.000000
Derece 3 Katsayi 3.000000

//boyle devam ediyor..
*/
