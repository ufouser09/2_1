//linked list- sona eleman ekleme

traverse iþlemi

traverse dolasma anlamýna gelir.
belirli þekilde tasarlanmýþ bir veri yapýsý üzerinde aranýlan noktayý bulmayý hedefler.

//biz veri yapýlarýnda abstract data types dedigimiz soyut bir veri tipi üretiyoruz.
yani mantiksal bir veri tutma þekli üretiyoruz.

bu dizilerde veri tutmaya benzemiyor.
bizim býrdaki dugumleri dolasmamýz için traverse dedigimiz bir dolasma islemi yapmamýz gerekiyor.

dizilerdeki gibi dizinin suyuncu indisine eris diyemiyoruz bilgisayara 
linked list'ler diziler gibi calýsmaz.
bu yüzden traverse iþlemi yapmak zorundayiz.

traverse iþlemi baglý listelerde dugumu bulmak ya da düðümdeki degeri bulmak için yapýlýyor.

baglý liste yapýsýnda traverse iþlemi dugum bulmak için yapýlýr.

dugum aranýyorsa aranýlan dugum,isaret edilen dugume esit oldugunda bulunur.

mantýk su sekilde calýsýyor:eger bir dugum aranýyorsa aranýlan dugum isaret edilen dugume esit oldugunda bulunmus oluyor.

linked listlerde her bir dugum bir sonraki dugumu isaret ediyor.
yani bu sayede bir sonraki isaret edilen dugum aradýgýmýz dugum ise dugumu bulmus oluyoruz.yok eger deger atanýyorsa o dugumun üzerine gelip degerini sorgulamamýz gerekiyor.



algoritma 
ilk dugumu gecici dugume esitle 
isaret edilen dugumu bul 
gecici dugumu isaret edilen dugume esitle


bunun algoritmasý su sekýlde
bi tane sahte dugum üretiyoruz bu dugume baslangýc dugumunu atýyoruz
baslangýc dugumunden sonra bir while dongusune giriyoruz.
while dongusu her defasýnda kendini bir sonraki dugume esitliyor.
yani her adýmda temp=temp->next diyoruz her adýmda
mesela a dugumunden basladýk ya donguye giriyor.
dongude a dugumu b dugumune esitleniyor.
daha sonra c dugumune d dugumune e dugumune.
bu sekilde bir donguye giriyor.
dongude bir sart belirtiyoruz o sarta geldigi zaman dongu duruyor donguden cýkýyoruz.
traverse islemini bu sekilde yapýyoruz temelde.

soyle bir ornek yapalým mesela 
A=17
B=21
C=9
D=37
E=5

temel þart:37 sayýsýna sagip dügümü bul

1.adým:temp adlý dugumu olustur.deger olarak baslangýc dugumunu ata.
2.adým:temp->data(17)aranýlan degere esit degil
3.adým:temp degerine temp->next(B)degerini ata
4.adým:temp->data(21)aranýlan degere esit degil
5.adým:temp degerine temp->next(C)degerini ata
6.adým:temp->data(9)aranýlan degere esit degil
7.adým:temp degerine temp->next(D)degerini ata
8.adým:temp->data degeri aranýlan degere esit.

donguden cýkar
temp degerini dondur.hangý dugumde oldugu bilinsin diye

SONA ELEMAN EKLEME 
tek yönlü baðlý listede sona eleman ekleme iþlemi için son dugum bulunmalýdýr.

son dugum traverse iþlemi ile bulunur.
traverse þartý dugumun pointer degiskeninin degeri null olmalýdýr.
tek yonlu baglý listelerde son dugumun next degeri null dýr.
null oldumu son dugumdeyim demektir.
bulunam dugum geri dondurulecektýr

yani son dugumu buluyoruz son dugumun next degerine yeni degerimizi ekliyoruz.

A=17
B=21
C=9
D=37
E=5
f=99

son dugum bulunur.
son dugumun pointer degiskenine yeni dugum atanýr.
yeni dugumun pointer degiskenine null degeri atanýr.





#include <stdio.h>
#include <stdlib.h>//malloc fonksiyonu için

//bir tane struct yapýsý duzenliycez bu struct yapýsý benim dugumumu belirtecek 

struct node{
	int data;
	struct node *next;
};
struct node* start=NULL;//bu beným baslangýc dugumum 
struct node* temp=NULL;			//bu da benim gecici dugumum
struct node* q=NULL;

void sonaEkle(int veri){		//kendisine verilen parametreyi baglý liste içinde en sona ekliycek

	struct node* eklenecek=(struct node*)malloc(sizeof(struct node));
	eklenecek->data=veri;//bu ve asagýdaki benim eklenecek olan dugumum ama asýl soru nereye eklenecek.
	eklenecek->next=NULL;
	
	if(start==NULL){
		start=eklenecek;//eger hiçbir þey yoksa benim start düðümüm eklenecek dugum olsun.
	}
	else{
	q=start;//sondaki elemaný bulmak için bir tane gecici degere start degerini atadým.
	while(q->next!=NULL){//bu dongu bana sondaki dugumu buldurcak
		
		q=q->next;//gecici degere geciciden sonraki degeri ekledim
		
	}	
	q->next=eklenecek;//bunu yaparak sona bir tane eleman eklemiþ oldu.
	}
}
void yazdir(){
	q=start;//ben start degerini neden sureklý bir degiskene atýyorum cunku start degerini bozmamak için.
			//baglý liste yapýsýnda start degerini sürekli elimde tutmalýyým.	
	while(q->next!=NULL){
		printf("%d->",q->data);
		q=q->next;
		//bu haldeyken son nodumuzu yazdýrmayýz.
	}
	printf("%d",q->data);
}

int main(){
	int secim;
	while(1==1){
		printf("bir tane sayi girin\n");
		scanf("%d",&secim);
		sonaEkle(secim);
		yazdir();
	}
}

//LÝNKED LÝST BASA ELEMAN EKLEME

ekleme olmadan önceki start elemaný ikinci eleman olacaktýr.
eklenecek olan eleman için dugum olusturulur.
yeni dugumun next degeri start elemanýna atanýr.
yeni dugum start elemaný olarak güncellenir.


eklenecek eleman için dugum olusturuyoruz.
yeni dugumun next degerini start yapýyoruz.
bundan sonra start degerini guncellememiz gerekiyor.
ve yeni dugum start elemaný olmasý lazým


#include <stdio.h>
#include <stdlib.h>//malloc fonksiyonu için

//bir tane struct yapýsý duzenliycez bu struct yapýsý benim dugumumu belirtecek 

struct node{
	int data;
	struct node *next;
};
struct node* start=NULL;//bu beným baslangýc dugumum 
struct node* temp=NULL;			//bu da benim gecici dugumum
struct node* q=NULL;

void sonaEkle(int veri){		//kendisine verilen parametreyi baglý liste içinde en sona ekliycek

	struct node* eklenecek=(struct node*)malloc(sizeof(struct node));
	eklenecek->data=veri;//bu ve asagýdaki benim eklenecek olan dugumum ama asýl soru nereye eklenecek.
	eklenecek->next=NULL;
	
	if(start==NULL){
		start=eklenecek;//eger hiçbir þey yoksa benim start düðümüm eklenecek dugum olsun.
	}
	else{
	q=start;//sondaki elemaný bulmak için bir tane gecici degere start degerini atadým.
	while(q->next!=NULL){//bu dongu bana sondaki dugumu buldurcak
		
		q=q->next;//gecici degere geciciden sonraki degeri ekledim
		
	}	
	q->next=eklenecek;//bunu yaparak sona bir tane eleman eklemiþ oldu.
	}
}
void yazdir(){
	q=start;//ben start degerini neden sureklý bir degiskene atýyorum cunku start degerini bozmamak için.
			//baglý liste yapýsýnda start degerini sürekli elimde tutmalýyým.	
	while(q->next!=NULL){
		printf("%d->",q->data);
		q=q->next;
		//bu haldeyken son nodumuzu yazdýrmayýz.
	}
	printf("%d",q->data);
}
void basaEkle(int basa){//bu parametre için daha dogrusu bu deger için bir dugum olusturmamýz gerekiyor.
	struct node *basaGelecek=(struct node*)malloc(sizeof(struct node));
	basaGelecek->data=basa;
	basaGelecek->next=start;
	start=basaGelecek;
}
int main(){
	int secim;
	while(1==1){
		printf("\n1-sona eleman ekle");
		printf("\n2-basa eleman ekle");
		printf("\n Yapmak istediginiz islemi secin\n");
	}
}

//4.31


