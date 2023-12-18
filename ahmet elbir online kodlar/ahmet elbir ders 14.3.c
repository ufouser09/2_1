//RECURSÝON ile alakalý bir ornek 
//linked list ve binary search treelerde traverse yaparken bu yaptýklarýmýz iþe yarar recursiondan faydalanabiliyoruz.
//sizeof(a)/sizeof(a[1]) bunun anlamý nedir.sizeof(a) nedir arrayýn boyutu
#include <stdio.h>
#define MAX(a) sizeof(a)

//ilk parametre dizinin ilk elemanýný pointer olarak alabiliriz.bir i degeri gelicek bi tane de n degeri gelicek.birisi ilk eleman birisi son eleman þimdi burdaki i degeri n'den kucuk oldugu muddetce reverse cagýrýyorum bu reverse'u cagýrdýgýmda array cagýrýcam ,i+1'i cagýrýcam ve n'i cagýrýcam 
//þimdi ilk basta i'miz sýfýr.n de 5 olarak geldi i kucuk mu 5 den evet napýyo 1 e 5 i cagýrýyo 1 e 5i cagýrýnca 1 kucuk mu 5 ten evet 2 5 cagýrýyo 3'e 5'i cagýrýyo o 4 'ü 5 'i cagýrýyo sonra bi da cagýryo 5 e 5 i cagýrýyo bunu cagýrdýktan sonra 5 kucuk mu 5 ten hayýr hayýr oldugu için bu kýsýmdan donuyor burdan dondukten sonra yani 5 e 5 den dondu 4 e 5 in bu satýrýna geri geldi sonra array'in i'sini yazdý arrayin i'si kac 4 yani son eleman bu son elemaný ekrana yazdý bunu yazdýktan sonra if den cýkýyo return etmýs oluyor sonra bunu kim cagýrdý stack mantýgý ile dusuncez.4 e 5 ten cýktýktan sonra noldu 3 e 5 i cagýrcaz sonra arrayýn 3.sunu yazdýrýyor falan boyle devam ediyor bu sekilde ekrana terstten yazdýrýyoruz.bi orjinal diziyi bozmadan yapýcaz bir de swap iþlemi yaparak bunu yapalým buna da reverse2 diyelim.bu gercek anlamda bir reverse olucak   
void reverse(int *ar,int i,int n){
	if(i<n){
		reverse(ar,i+1,n);
		printf("%d",ar[i]);
	}
}
//yine integer array alýcaz.integer i'yi alýcaz.integer n'i alýcaz 
void reverse2(int *ar,int i,int n){
	int tmp;
	//while'daki i<N gibi dusunebiliriz.cunku burda recursive bir dongu yapýyoruz.
	if(i<N){
		//tmp'ye dizinin birinci elemanýný alýyorum.
		tmp=ar[i];
		ar[i]=ar[n];
		ar[n]=tmp;
		reverse(ar,i+1,n-1);
	}
}


int main(){
	int a[]={1,2,3,4,5};
	int N=MAX(a)/MAX(a[1]);
	for(i=0;i<N;i++){
		//diziyi þöyle ekrana yazdýralým.
		printf("%d-",a[i]);
	}
	printf("\n");
	
	reverse(a,0,N);
	//burda gönderirken artýk N-1 olucak çünkü yer degisimi olucak oraya kadar gitmicez.
	reverse2(a,0,N-1);
	return 0;
}
2.00
