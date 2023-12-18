#include <stdio.h>
#include <stdlib.h>





int *fonksiyon(int *dizi,int k){
	
	int m;
	if(dizi[k]%2==0){
	
	m=dizi[k]/2;
	

	}
	else{
		m=3*dizi[k]+1;
	}		
	k++;
	
	return m;
	
}











int main(){
	int *dizi;
	int size=2,i,j;
	
	dizi=(int*)malloc(size*sizeof(int));
	if(dizi==NULL){
		printf("bellekte yer ayrilmadi\n");
		return -1;
	}
	printf("lutfen dizinizin ilk elemanini giriniz\n");
	scanf("%d",&dizi[i]);
	
	i=0;
	while(dizi[i]!=1){
	if(i+1>=size){
	size=2*size;
	dizi=(int*)realloc(dizi,(size)*sizeof(int));
	if(dizi==NULL){
		printf("bellekte yer ayrilmadi\n");
		return -1;
	}
}
	dizi[i+1]=fonksiyon(dizi,i);
	for(j=0;j<=i;j++){
		printf("%d\t",dizi[j]);
	}
	
	printf("\n");
	printf("\teleman sayisi=%d\tboyut=%d\t",i+1,size);
	i++;
	
	
}
	
	
	
	
}
