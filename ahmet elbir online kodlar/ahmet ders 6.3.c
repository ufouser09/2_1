/*
uygulama:sieve of erotoshenes algoritmasýný kullanýlarak kullanýcý tarafýndan girilen tam sayinin altýnda kalan butun asal sayýlarý hesaplayan program asagýda belirtilen maddelere uyarak yazýnýz.
1-altýnda kalan butun asal sayýlarýn hesaplanacagý tam sayi kullanýcý tarafýndan girilecektir(n sayisi)
2-hesaplama sonucunda elde edilen asal sayýlar yeni bir dizide tutulacaktýr(boyut 1xn)
3-program cýktýsý asagýda gösterildigi gibi olmalýdýr.

sieve of eratoshenes algoritmasý 
bu metot verilen bir tam sayinin altýnda kalan butun asal sayýlarý bulmak için kullanýlýr.
oncelikle verilen tam sayiya n denilir ise 2 den n ye kadar olan tum tam sayýlar sýrasýyla bir listeye yazýlýr ve o anda kontrol edilen asal sayýya a denilir ise a^2<n esitligi saglanana kadar a sayýsýnýn katlarý bu listeden elenir.eleme iþlemine baslamadan once a sayisi listede kontrol edilmemis en kucuk sayidir ve eleme iþlemi tamamlandýktan sonra henuz kontrol edilmemis en kucuk sayi a sayisinin yeni degeri olur.baslangýcta tum sayilarin asal oldugu kabul edilir ve a degeri 2 ile baslar 

ÖRNEK 
10 a kadar olan tum asal sayýlarý sieve of erotoshenes algoritmasini kullanarak bulunuz.
n=10;

2  3  4  5  6  7  8  9  10

baslangýcta tum sayilar asal sayi olarak kabul edildiginden listenin en kucuk asal sayisi 2^2<=10 esitligini sagladýgý için 2 olur ve 2 nin katý olan tum sayilar lýsteden elenir

n=10,a=2

2  3   4x  5  6x  7  8x   9  10x 


listede kontrol edilmemis en kucuk asal sayi 3^2<=10 esitligini sagladýgý için 3 olur ve 3 un katý olan tum sayilar listeden elenir.

n=10,a=3;

2  3  4x  5  6x  7  8x  9x  10x

listede kontrol edilmemis en kucuk asal sayý aslýnda 5 dir ancak 5^2<=10 olmadýgý için hesaplama bu adýmda sonlanýr
10 a kadar olan tum asal sayýlar 2 3 5 7 olarak bulunur.


*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
 
int main(int argc,char *argv[]){ 
	setLocale(LC_ALL,"Turkýsh");
	//konsoldan turkce karakter girebilmek için bunu yazdýk
	int n,i,j,prime_count,*primes;
	
	char *prime_states;
	printf("sieve of eratoshenes algoritmasýnýn kullanrak asal sayý\nolusturmak için bir tamsayisi giriniz: ");
	scanf("%d",&n);
	n--;//1 zaten asal degil o yuzden
	prime_states=(char*)malloc(n*size(char));
	
	if(prime_states==NULL){
		printf("bellekte alan olusturulmadý.");
		exit(0);
	}
	 
	for(i=0;i<n;i++){
		prime_states[i]=1;//1 =asal sayi demektir  
	}
	
	for(i=0;(i+2)*(i+2)<=n+1;i++){
		if(prime_states[i]==1){
			for(j=(i+2)*(i+2);j<=n+1;j+=i+2){
				prime_states[j-2]=0;
				
				
			}
		}
	}
	prime_count=0;
	for(i=0;i<n;i++){
		if(prime_states[i]==1){
			prime_count++;
		}
		
		
	}
	primes=(int *)malloc(prime_count*sizeof(int));
	if(primes==NULL){
		printf("bellekte alan olusturalamadý.");
		exit(0);
	}
	j=0;
	for(i=0;i<n;i++){
		if(prime_states[i]==1){
				primes[j]=i+2;
				j++;
		}
	}
	 
	 printf("Program cýktýsý-\n0-%d arasýndaki asal sayilar:",n+1);
	 
	 for(i=0;i<prime_count;i++){
	 	if(i%10==0){
	 		printf("\n");
	 		if(i==prime_count-1){
	 			printf("%5d",primes[i]);
			 }
			 else{
			 	printf("%5d,",primes[i]);
			 }
		 }
	 }
	 free(prime_states);
	 free(primes);
	 
	 
	
	return 0;
}
