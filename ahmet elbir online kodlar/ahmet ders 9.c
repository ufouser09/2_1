#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int id,age,grade;
	char name[20];
	
	
}STUDENT;
void liste_yaz(STUDENT* std,int N);
void ada_gore_sirala(STUDENT* ,int );
void nota_gore_sirala(STUDENT* ,int );
int main(){
	int N,i;
	STUDENT *std;
	printf("N degeri ");
	scanf("%d",&N);
	
	std=(STUDENT*)calloc(N,sizeof(STUDENT));
	if(std!=NULL){
		for(i=0;i<N;i++){
			//kullanýcýdan verileri okuduk.
			printf("%d. Ogrenci id",i);
			scanf("%d",&std[i].id);
			
			printf("%d.ogrenci adi",i);
			scanf("%s",std[i].name);//string oldugu için ampersant kullanmaya gerek yok
			
			printf("%d.ogrenci notu",i);
			scanf("%d",&std[i].grade);
			
			printf("%d.ogrenci yasý",i);
			scanf("%d",&std[i].age);
		}
		
		liste_yaz(std,N);
		nota_gore_sirala(std,N);
		liste_yaz(std,N);
		ada_gore_sirala(std,N);
		liste_yaz(std,N);
		free(std);
		
	}
	else{
		printf("Error");
		
		return 0;
	}
}
void nota_gore_sirala(STUDENT* std,int n){
	int i,j;
	STUDENT tmp;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1;j++){
			if(std[j].grade<std[j+1].grade){
				tmp=std[j];
				std[j]=std[j+1];
				std[j+1]=tmp;
			}
		}
	}
	
}
void liste_yaz(STUDENT* std,int N){
	int i;
	printf("ID\tAD\tNOT\tYAS\n ");
	for(i=0;i<N;i++){
		/*
		printf("%d.ogrenci id",i);
		scanf("%d",&std[i].id);
		
		printf("%d.ogrenci adi",i);
		scanf("%d",std[i].name);
			
		printf("%d.ogrenci notu",i);
		scanf("%d",&std[i].grade);
			
		printf("%d.ogrenci yasý",i);
		scanf("%d",&std[i].age);
	*/
	printf("%d\t%s\t%d\t%d\n",std[i].id,std[i].name,std[i].grade,std[i].age);
	}
	
}
void ada_gore_sirala(STUDENT* std,int n){
	int i,j;
	STUDENT tmp;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1;j++){
			if(strcmp(std[j].name,std[j+1].name)>1){
				tmp=std[j];
				std[j]=std[j+1];
				std[j+1]=tmp;
			}
		}
	}
	
}

