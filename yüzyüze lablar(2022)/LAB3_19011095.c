#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int id;
	char isim[15];
	char tip[2];

	
}USERS;
void getInfo(USERS* ,int );
void yazdir(USERS *,int );
void IdSirala(USERS* ,int );

int main(){
	USERS *c1;
	int N,i;
	printf("lutfen dizinin boyutunu giriniz\n");
	scanf("%d",&N);
	
	c1=(USERS*)calloc(N,sizeof(USERS));
	
	getInfo(c1,N);
	yazdir(c1,N);
	
	IdSirala(c1,N);
	yazdir(c1,N);
;

}
void getInfo(USERS* c1,int N){
	int i;
	printf("lutfen bilgileri giriniz\n");
	for(i=0;i<N;i++){
		printf("lutfen ismi giriniz\n");
		scanf("%s",c1[i].isim);
		
		printf("lutfen id giriniz\n");
		scanf("%d",&c1[i].id);
		
		printf("lutfen tipi giriniz\n");
		scanf("%s",c1[i].tip);
	}
}
void yazdir(USERS *c1,int N){
	int i;
	for(i=0;i<N;i++){
		
		printf("%d\t%s\t%s\n",c1[i].id,c1[i].isim,c1[i].tip);
	}
}
void IdSirala(USERS* c2,int N){
	int i,j;
	printf("ID SIRALI\n");
	USERS *tmp;
	USERS *tmp2;
	USERS *tmp3;
	for(i=0;i<N;i++){
		for(j=i+1;j<N;j++){
			if(strcmp(c2[i].tip,c2[j].tip)<0){
				strcpy(tmp2,c2[i].tip);
				strcpy(c2[i].tip,c2[j].tip);
				strcpy(c2[j].tip,tmp);
				
				strcpy(tmp3,c2[i].isim);
				strcpy(c2[i].isim,c2[j].isim);
				strcpy(c2[j].isim,tmp3);
					
					if(strcmp(c2[i].tip,c2[j].tip)==0){
					
					if(c2[i].id>c2[j].id ){
				
				
				
				tmp=c2[i].id;
				c2[i].id=c2[j].id;
				c2[j].id=tmp;
				
			}
			
		}
			}
		}
	}
	

}




