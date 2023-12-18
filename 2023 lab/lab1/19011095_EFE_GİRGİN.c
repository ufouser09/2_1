#include <stdio.h>
#include <stdlib.h>
void sirala(int dizi[],int max1,int max2,int max3,int min1,int min2,int min3,int N){
	int i;
	int toplam1=0;
	int toplam2=0;
	for(i=0;i<N;i++){
		if(dizi[i]>max3){
			if(dizi[i]>max2){
				if(dizi[i]>max1){
					max3=max2;
					max2=max1;
					max1=dizi[i];
				}
				else{
					max3=max2;
					max2=dizi[i];
					
				}
			}else{
				max3=dizi[i];
			}
			
			
		}
	}
	for(i=0;i<N;i++){
	
		if(dizi[i]<=min3){
			if(dizi[i]<=min2){
				if(dizi[i]<=min1){
					min3=min2;
					min2=min1;
					min1=dizi[i];
				}
				else{
					min3=min2;
					min2=dizi[i];
				}
			}else{
				min3=dizi[i];
			}
		}
		
	}
		printf("en buyuk 3 ogrencimiz(buyukten kucuge)=%d %d %d\n",max1,max2,max3);
		toplam1=max1+max2+max3;
		printf("en buyuk sayilarin toplamý=%d\n",toplam1);
		
		printf("en kucuk 3 öðrencimiz(kucukten buyuge)=%d %d %d\n",min1,min2,min3);
		toplam2=min1+min2+min3;
		printf("en kucuk sayilarin toplamý=%d\n",toplam2);
	
}

int main(){
	int N;
	int i;
	int max1,max2,max3,min1,min2,min3;
	do{
		printf("lutfen dizinin boyutunu giriniz\n");
		scanf("%d",&N);
	}while(N<6);
	
	int dizi[N];
	
	printf("lutfen diziyi giriniz\n");
	for(i=0;i<N;i++){
		scanf("%d",&dizi[i]);
	}
	//en buyuk max1,en kucuk min1;
	max1=dizi[0];
	max2=dizi[0];
	max3=dizi[0];
	min1=dizi[0];
	min2=dizi[0];
	min3=dizi[0];
	
	sirala(dizi,max1,max2,max3,min1,min2,min3,N);
	
	
	
	
}

