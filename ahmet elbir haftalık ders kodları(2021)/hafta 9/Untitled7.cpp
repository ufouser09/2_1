#include <stdio.h>
typedef union {
	struct{
		char a,b;
	}c;
	int x;
	double y;	
}u;
int main(){
	int x;
	printf("Sizeof(char)=%d\n",sizeof(char));
	printf("Sizeof(int)=%d\n",sizeof(int));
	printf("Sizeof(double)=%d\n",sizeof(double));
	printf("Sizeof(u)=%d\n",sizeof(u));
	u element;
	element.c.a='a';
	element.c.b='b';
	x=getchar();
	printf("%c %c %d %lf\n",element.c.a,element.c.b,element.x,element.y);
	element.x=5;//0000000...1001
	printf("%c %c %d %lf\n",element.c.a,element.c.b,element.x,element.y);
	element.y=4.4;
	printf("%c %c %d %lf\n",element.c.a,element.c.b,element.x,element.y);
	fflush(stdin);
	x=getchar();
}
