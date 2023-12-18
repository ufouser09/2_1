#include <stdio.h>
// a1 X ^ n + a2 X ^n-1 ...+ an X ^ 0  
typedef struct polinom1{
	double katsayi;
	int derece;
}POLINOM;

int main(){
	POLINOM p1,p3={4.5,6};
	POLINOM *p2;
	int N=5;
	int i;
	printf("%lf %d",p3.katsayi,p3.derece);
	
	p1.derece=0;
	p1.katsayi=0;
	printf("%2.2lf X ^ %d\n",p1.katsayi,p1.derece);
	printf("Derece ve katsayi giriniz\n");
	scanf("%d",&p1.derece);
    scanf("%lf",&p1.katsayi);
    printf("%2.2lf X ^ %d\n",p1.katsayi,p1.derece);
	p2=&p1;
	p2->derece=33;
	(*p2).katsayi=7;
	printf("%2.2lf X ^ %d\n",p2->katsayi,p2->derece);
	printf("%p %p %p %p %p\n",&p1, p2, &p1.derece,&p2->katsayi,&p1.katsayi);
	
	printf("Derece ve katsayi giriniz\n");
	scanf("%d",&p2->derece);
    scanf("%lf",&p2->katsayi);
    printf("%2.2lf X ^ %d\n",p2->katsayi,p2->derece);
    printf("Derece ve katsayi giriniz\n");
	scanf("%d",&(*p2).derece);
    scanf("%lf",&(*p2).katsayi);
    printf("%2.2lf X ^ %d\n",p2->katsayi,p2->derece);
    
    printf("%p %p %p %p %p\n",&p1, p2, &p1.derece,&(*p2).katsayi,&p1.katsayi);
    
    
    
    
    
	
}
/*
output:
4.500000 60.00 X ^ 0
Derece ve katsayi giriniz
3
2
2.00 X ^ 3
7.00 X ^ 33
000000000062FE00 000000000062FE00 000000000062FE08 000000000062FE00 000000000062FE00
Derece ve katsayi giriniz
2
3
3.00 X ^ 2
Derece ve katsayi giriniz
4
3
3.00 X ^ 4
000000000062FE00 000000000062FE00 000000000062FE08 000000000062FE00 000000000062FE00

*/
