#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
extern int a;
int b=6;
int aa;
//int c=66;
extern int h();
int main() {
	int aaa;
	 int c=666;
	printf("%d:\n",a);
	printf("%d:\n",aa);
	printf("%d:\n",aaa); //aaa has garbage value
	
	printf("%d:\n",b); 
	f();
	h();
	printf("****%d:\n",a);
	
	return 0;
}

void f(){
	extern int c;
	printf("%d:\n",b); 
	printf("%d:\n",c); 
}
//kodda bi sorun var bida bak
