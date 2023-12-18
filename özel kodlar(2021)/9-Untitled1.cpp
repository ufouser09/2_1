#include <stdio.h>
#include <stdlib.h>
void swap(int *a,int *b){
	int tmp;
	tmp=*a;
	*a=*b;
	*b=tmp;
}
int getPosOfMin(int  *list,int n,int pos){
	int i,minIndex;
	minIndex=pos;
	for(i=pos+1;i<n;i++)
		if(*(list+i)<*(list+minIndex))
		minIndex=i;
		return minIndex;
	
	
}
void selectionSort(int *list,int n){
	int i,minPos,tmp;
	for(i=0;i<n-1;i++){
		minPos=getPosOfMin(list,n,i);
		swap(list+i,list+minPos);
		/*
			tmp=*(list+i);
				*(list+i)=*(list+minPos);
				*(list+minPos)=tmp;
				*/
	}
}
void printList(int *list,int n){
	int i;
	printf("\n");
	for(i=0;i<n;i++)
	printf("%5d",*(list+i));
	//printf("%5d",list[i]);
}
void bubbleSort(int *list,int n){
	int i,j,tmp;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(*(list+i)>*(list+j)){
				
				swap(list+i,list+j);
				/*
				tmp=*(list+i);
				*(list+i)=*(list+j);
				*(list+j)=tmp;
				*/
				/*
				tmp=list[i];
				list[i]=list[j];
				list[j]=tmp;
				*/
			}
		}
	}
}
int main(int argc,char *argv[]){
	
	int *p;
	int n,i;
	printf("kac eleman giriceksiniz?");
	scanf("%d",&n);
	p=(int*)malloc(n*sizeof(int));
	if(p==NULL){
		printf("bellek ayrilamadi.program sonlanýcak");
		exit(1);
	}
	for(i=0;i<n;i++){
		printf("%d.elemani girin:",(i+1));
		scanf("%d",p+i);
		//scanf("%d",&p[i]);
	}
	/*
	printf("sirasiz hali:\n");printList(p,n);
	bubbleSort(p,n);
	printf("sirali hali:\n");printList(p,n);
	*/
	printf("sirasiz hali:\n");printList(p,n);
	selectionSort(p,n);
	printf("sirali hali:\n");printList(p,n);
	
	
	
	free(p);
	printf("\n");
	system("pause");return 0;
}
