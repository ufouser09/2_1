#include<stdio.h>

int main(){
	int i;
	float f;
	char c;
	
	void *ptr;
	ptr=&i;
	*(int*)ptr=10;
	printf("Integer value:%d",i);
	ptr=&f;
	*(float*)ptr=11.5;
	printf("\nfloat value:%f",f);
	ptr=&c;
	*(char*)ptr='s';
	printf("\nchar value:%c",c);
	printf("----%c",*(char*)ptr);
}

