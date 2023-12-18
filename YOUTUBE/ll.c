//linked list- sona eleman ekleme

traverse i�lemi

traverse dolasma anlam�na gelir.
belirli �ekilde tasarlanm�� bir veri yap�s� �zerinde aran�lan noktay� bulmay� hedefler.

//biz veri yap�lar�nda abstract data types dedigimiz soyut bir veri tipi �retiyoruz.
yani mantiksal bir veri tutma �ekli �retiyoruz.

bu dizilerde veri tutmaya benzemiyor.
bizim b�rdaki dugumleri dolasmam�z i�in traverse dedigimiz bir dolasma islemi yapmam�z gerekiyor.

dizilerdeki gibi dizinin suyuncu indisine eris diyemiyoruz bilgisayara 
linked list'ler diziler gibi cal�smaz.
bu y�zden traverse i�lemi yapmak zorundayiz.

traverse i�lemi bagl� listelerde dugumu bulmak ya da d���mdeki degeri bulmak i�in yap�l�yor.

bagl� liste yap�s�nda traverse i�lemi dugum bulmak i�in yap�l�r.

dugum aran�yorsa aran�lan dugum,isaret edilen dugume esit oldugunda bulunur.

mant�k su sekilde cal�s�yor:eger bir dugum aran�yorsa aran�lan dugum isaret edilen dugume esit oldugunda bulunmus oluyor.

linked listlerde her bir dugum bir sonraki dugumu isaret ediyor.
yani bu sayede bir sonraki isaret edilen dugum arad�g�m�z dugum ise dugumu bulmus oluyoruz.yok eger deger atan�yorsa o dugumun �zerine gelip degerini sorgulamam�z gerekiyor.



algoritma 
ilk dugumu gecici dugume esitle 
isaret edilen dugumu bul 
gecici dugumu isaret edilen dugume esitle


bunun algoritmas� su sek�lde
bi tane sahte dugum �retiyoruz bu dugume baslang�c dugumunu at�yoruz
baslang�c dugumunden sonra bir while dongusune giriyoruz.
while dongusu her defas�nda kendini bir sonraki dugume esitliyor.
yani her ad�mda temp=temp->next diyoruz her ad�mda
mesela a dugumunden baslad�k ya donguye giriyor.
dongude a dugumu b dugumune esitleniyor.
daha sonra c dugumune d dugumune e dugumune.
bu sekilde bir donguye giriyor.
dongude bir sart belirtiyoruz o sarta geldigi zaman dongu duruyor donguden c�k�yoruz.
traverse islemini bu sekilde yap�yoruz temelde.

soyle bir ornek yapal�m mesela 
A=17
B=21
C=9
D=37
E=5

temel �art:37 say�s�na sagip d�g�m� bul

1.ad�m:temp adl� dugumu olustur.deger olarak baslang�c dugumunu ata.
2.ad�m:temp->data(17)aran�lan degere esit degil
3.ad�m:temp degerine temp->next(B)degerini ata
4.ad�m:temp->data(21)aran�lan degere esit degil
5.ad�m:temp degerine temp->next(C)degerini ata
6.ad�m:temp->data(9)aran�lan degere esit degil
7.ad�m:temp degerine temp->next(D)degerini ata
8.ad�m:temp->data degeri aran�lan degere esit.

donguden c�kar
temp degerini dondur.hang� dugumde oldugu bilinsin diye

SONA ELEMAN EKLEME 
tek y�nl� ba�l� listede sona eleman ekleme i�lemi i�in son dugum bulunmal�d�r.

son dugum traverse i�lemi ile bulunur.
traverse �art� dugumun pointer degiskeninin degeri null olmal�d�r.
tek yonlu bagl� listelerde son dugumun next degeri null d�r.
null oldumu son dugumdeyim demektir.
bulunam dugum geri dondurulecekt�r

yani son dugumu buluyoruz son dugumun next degerine yeni degerimizi ekliyoruz.

A=17
B=21
C=9
D=37
E=5
f=99

son dugum bulunur.
son dugumun pointer degiskenine yeni dugum atan�r.
yeni dugumun pointer degiskenine null degeri atan�r.





#include <stdio.h>
#include <stdlib.h>//malloc fonksiyonu i�in

//bir tane struct yap�s� duzenliycez bu struct yap�s� benim dugumumu belirtecek 

struct node{
	int data;
	struct node *next;
};
struct node* start=NULL;//bu ben�m baslang�c dugumum 
struct node* temp=NULL;			//bu da benim gecici dugumum
struct node* q=NULL;

void sonaEkle(int veri){		//kendisine verilen parametreyi bagl� liste i�inde en sona ekliycek

	struct node* eklenecek=(struct node*)malloc(sizeof(struct node));
	eklenecek->data=veri;//bu ve asag�daki benim eklenecek olan dugumum ama as�l soru nereye eklenecek.
	eklenecek->next=NULL;
	
	if(start==NULL){
		start=eklenecek;//eger hi�bir �ey yoksa benim start d���m�m eklenecek dugum olsun.
	}
	else{
	q=start;//sondaki eleman� bulmak i�in bir tane gecici degere start degerini atad�m.
	while(q->next!=NULL){//bu dongu bana sondaki dugumu buldurcak
		
		q=q->next;//gecici degere geciciden sonraki degeri ekledim
		
	}	
	q->next=eklenecek;//bunu yaparak sona bir tane eleman eklemi� oldu.
	}
}
void yazdir(){
	q=start;//ben start degerini neden surekl� bir degiskene at�yorum cunku start degerini bozmamak i�in.
			//bagl� liste yap�s�nda start degerini s�rekli elimde tutmal�y�m.	
	while(q->next!=NULL){
		printf("%d->",q->data);
		q=q->next;
		//bu haldeyken son nodumuzu yazd�rmay�z.
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

//L�NKED L�ST BASA ELEMAN EKLEME

ekleme olmadan �nceki start eleman� ikinci eleman olacakt�r.
eklenecek olan eleman i�in dugum olusturulur.
yeni dugumun next degeri start eleman�na atan�r.
yeni dugum start eleman� olarak g�ncellenir.


eklenecek eleman i�in dugum olusturuyoruz.
yeni dugumun next degerini start yap�yoruz.
bundan sonra start degerini guncellememiz gerekiyor.
ve yeni dugum start eleman� olmas� laz�m


#include <stdio.h>
#include <stdlib.h>//malloc fonksiyonu i�in

//bir tane struct yap�s� duzenliycez bu struct yap�s� benim dugumumu belirtecek 

struct node{
	int data;
	struct node *next;
};
struct node* start=NULL;//bu ben�m baslang�c dugumum 
struct node* temp=NULL;			//bu da benim gecici dugumum
struct node* q=NULL;

void sonaEkle(int veri){		//kendisine verilen parametreyi bagl� liste i�inde en sona ekliycek

	struct node* eklenecek=(struct node*)malloc(sizeof(struct node));
	eklenecek->data=veri;//bu ve asag�daki benim eklenecek olan dugumum ama as�l soru nereye eklenecek.
	eklenecek->next=NULL;
	
	if(start==NULL){
		start=eklenecek;//eger hi�bir �ey yoksa benim start d���m�m eklenecek dugum olsun.
	}
	else{
	q=start;//sondaki eleman� bulmak i�in bir tane gecici degere start degerini atad�m.
	while(q->next!=NULL){//bu dongu bana sondaki dugumu buldurcak
		
		q=q->next;//gecici degere geciciden sonraki degeri ekledim
		
	}	
	q->next=eklenecek;//bunu yaparak sona bir tane eleman eklemi� oldu.
	}
}
void yazdir(){
	q=start;//ben start degerini neden surekl� bir degiskene at�yorum cunku start degerini bozmamak i�in.
			//bagl� liste yap�s�nda start degerini s�rekli elimde tutmal�y�m.	
	while(q->next!=NULL){
		printf("%d->",q->data);
		q=q->next;
		//bu haldeyken son nodumuzu yazd�rmay�z.
	}
	printf("%d",q->data);
}
void basaEkle(int basa){//bu parametre i�in daha dogrusu bu deger i�in bir dugum olusturmam�z gerekiyor.
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


