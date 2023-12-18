#include <stdio.h>
#include <stdlib.h>
//a1x^n | a2x^(n-1)........aNx^0
//b1x^m+ b2x^(m-1).........bNx^0

//INNER struct ya da nested struct
//2 tane polinom üzerinden çarpma bölme toplama çýkarma iþlemleri yapan bir iþlem yapmak istiyoruz.
//polinom bir terimler dizisidir.
//her bir terimde katsayý ve exponent olarak 2 tane degisken tutuyoruz.
struct term{
	int coeff;
	int expo;
};
typedef struct term TERM;
//polinom da kac tane terim olucagýný ve terimler dizisinin pointer'ýný tutuyor.
typedef struct poly
{
	int N;
	TERM *terms;
}POLY;

//typedef struct poly POLY;

void readPoly(POLY *);
void displayPoly(POLY *);
POLY *toplam(POLY *,POLY *);
POLY *fark(POLY *,POLY *);
void mySort(POLY *pt);


int main(){
	POLY p1,p2,*p3;
	//birinci polinom'un terim sayisi'ni aldik.
	printf("Birinci Polinom terimi saiyisi giriniz:");
	scanf("%d",&p1.N);
	//ikinci polinomun terim sayisini aldik.
	printf("ikinci Polinom terim sayisi giriniz:");
	scanf("%d",&p2.N);
	
	//kac tane terim saklýycaksam burda terimler kadar malloc yapýyorum.
	p1.terms=(TERM*)malloc(p1.N*sizeof(TERM));
	
	p2.terms=(TERM*)malloc(p2.N*sizeof(TERM));
	
	//eger herhangi bir null deger olursa program basarýsýz diyip programi kapatiyoruz.
	if(!(p1.terms || p2.terms)){
		printf("Basarisiz");
		return 0;
	}
	//sonra p1 ve p2 terimlerinin degerlerini okuycam.
	readPoly(&p1);
	readPoly(&p2);
	//sonra siraliycam.
	mySort(&p1);
	mySort(&p2);
	//siraladiktan sonra ekrana bastýrýyoruz.
	displayPoly(&p1);
	displayPoly(&p2);
	//2 polinom'u topluyoruz.
	p3=toplam(&p1,&p2);
	//toplamlarý bir sýraliyorum.
	mySort(p3); 
	printf("toplam\n");
	displayPoly(p3);
	p3=fark(&p1,&p2);
	mySort(p3);
	printf("fark\n");
	displayPoly(p3);
	//polinomlarý free ederiz.
	free(p1.terms);
	free(p2.terms);
	
	return 0;
	
}
//burda polinomumuzu siraliyoruz.
void mySort(POLY *pt){//polinom hangisi siralancaksa onun pointerý geliyor buraya
	int i,j;
	TERM temp;
	int max=pt->N;//terim sayisini alicam
	
	for(i=0;i<max-1;i++){
		for(j=0;j<(max-1-i);j++){
			//derecesine göre siraliyoruz derecesi en büyük olan terim en basa gelcek þekilde.
			//-> kullanýyoruz aþaðýda neden çünkü yukarýda benim pointerým var.
			if(pt->terms[j].expo>pt->terms[j+1].expo){
				
				temp=pt->terms[j];
				pt->terms[j]=pt->terms[j+1];
				pt->terms[j+1]=temp;
			}
		}
	}
	//displayPoly(p1);
}
//burda elemanlari kullanicidan aliyoruz.
void readPoly(POLY *pt){
	int i;
	int max=(*p1).N;//p1->N
	printf("\n sirali olarak dereceleri ve katsayilari giriniz\n");
	for(i=0;i<max;i++){
		printf("derece giriniz(%d):",i+1);
		scanf("%d",&(pt->terms[i]).expo);
		
		printf("katsayisi giriniz(%d):",i+1);
		scanf("%d",&(pt->terms[i]).coeff);
	}
}
//burda elemanlari ekrana yazdiriyoruz.
void displayPoly(POLY *pt){
	int i;
	int max=p1->N;
	for(i=max-1;i>0;i--)
	printf("%d(x^%d)+",pt->terms[i].coeff,pt->terms[i].expo);
	printf("%d(x^%d)",pt->terms[i].coeff,pt->terms[i].expo);
	printf("\n");
}
//2 tane polinom'u toplucaz yeni bir polinom allocate edilecek ve allocate edilen bu yeni polinom'un adresi return edilecek.
POLY *toplam(POLY *p1,POLY *p2){//burdan böyle bir þey döndürüyosak bu döndürecegimiz pointer yani p3 dinamik memory allokasyonu ile olusturulmasý gerekir.veya static olarak yazilmasý gerekir.
	//öncelikle polinomlarýn exponansiyellerine bakýyorum yani hangisi daha büyük derecede
	//en buyuk derecesini bir a diye aldým bir b diye aldým.
	int a=p1->terms[p1->N-1].expo;
	int b=p2->terms[p2->N-1].expo;
	
	int i,c,max=1+((a>b)?a:b);
	POLY *p3;
	//burdaki ara iþlemleri daha kolay yapmak için bir dizi üretiyorum.
	//diyorum ki bu dizinin içerisinde polinomun derecelerini ve coeff larýný saklayýp toplama iþlemini ona göre yapýyým
	int *res=(int *)calloc (max,sizeof(int));
	
	//p1'in derecelerine göre katsayýlarý bu diziye sakladým.
	//yani 7.derecenin kat sayýsý kaç,3.derecenin kat sayýsý kaç
	for(i=0;i<p1->Mi++){
		res[p1->terms[i].expo]+=p1->terms[i].coeff;
		
		}
		//buna da p2 nin katsayýlarýný ekledýgým zaman noluyor polinomlarýn katsayýlarý toplanmýs oluyor.
	for(i=0;i<p2->N;i++){
		res[p2->terms[i].expo] += p2->terms[i].coeff;
		//c dedigim sey de kac tane 0 dan farkli deger var.
		//yani x^4 mesela 2'sinde de 0 o zaman bunu yazmamam gerekir.
	for(c=0,i=0;i<max;i++)
		c+=(res[i]!=0);
		
		//bir polinom olusturuyorum 1 elemanlý ve bu polinomun terim sayýsýný surdaki c kadar olusturuyorum.içinde kaç tane terim olucagýný söyledigim için.ve bu c kadar terimin içerisine ordaki res dizisini okuyarak yeni polinomumu olusturuyorum. 
	p3 =(POLY *)malloc(sizeof(POLY));
		p3->terms=(TERM *)malloc(c*sizeof(TERM));
		
		p3->N=c;
		
		for(c=0,i=max-1;i>=0;i--)
		if(res[i]){
			p3->terms[c].expo=i;
			p3->terms[c].coeff=res[i];
			c++;
		}
		free(res);
		return p3;
	}
	
	
	
}
POLY *fark(POLY *p1,POLY *p2){
	int a=p1->terms[p1->N-1].expo;
	int b=p2->terms[p2->N-1].expo;
	int i,c,max=1+((a>b)?a:b);
	
	int *res=(int*)calloc(max,sizeof(int));
	
	for(i=0;i<p1->N;i++)
		res[p1->terms[i].expo] +=p1->terms[i].coeff;
		
	for(i=0;i<p2->N;i++)
		res[p2->terms[i].expo] -=p2->terms[i].coeff;
		
	for(c=0,i=0;i<max;i++)
		c += (res[i]!=0);	
		
	POLY *p3 =(POLY*)malloc(sizeof(POLY));
	p3->terms =(TERM*)malloc(c*sizeof(TERM));
	
	p3->N=c;
	for(c=0,i=max-1;i>=0;i--)
		if(res[i]){
			p3->terms[c].expo=i;
			p3->terms[c].coeff=res[i];
			c++;
		}
		free(res);
		return p3;
}
