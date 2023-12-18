#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//boyle bir noktalar formatýnda noktalarýn kordinatlarýný içeren bir dosyam var.Bunlarý okuycam ve bunlarý linked list içerisine alýcaz.
//linked list içerisinde iþlemler yapýp orjýne en yakýn,en uzak gibi senaryolarla buna calýscaz.

//Oncelikle yapýcagýmýz sey bunun struct'ýrýný olusturmak daha sonra fonksiyonlarýný yazmak.
//burda bir nokta struct'ýrýmýz olsun.
//Bir linked list þeklinde olucagý için içerisindeki her bir noktanýn bir sonraki degerini de tutmak istiyorum.
struct Nokta{
	int x,y;
	struct Nokta *next;
};
typedef struct Nokta NOKTA;

//bir de en uzak noktanýn bilgilerini isticem.bunun için de soyle bir þey yapmak istiyorum.
typedef struct EnUzak{
 	int d;//en uzak noktanýn distance'si.
 	NOKTA *pt;//bir de bu hangi noktaysa bu distance'sý gösteren bir pointer tutucam.yani yukarýdaki elemanlardan bir tanesinin pointer'ýný tutucam.
 }ENUZAKNOKTA;
 
 //NOKTA türünde pointer donduren bir fonksiyonumuz olsun burda sadece dosyanýn adýný verelim.
 NOKTA* dosyadanOku(char*);
 //listeyi yazdýralým hatta listeyi iki türlü yazdýralým.
 void listeYaz(NOKTA*);
 //bu versiyon 2 de recursive yazdýrýcaz.
 void listeYazRec(NOKTA*);
 //parametre olarak nokta turunde bir pointer alsýn.
 NOKTA* enUzakNoktaBul(NOKTA *,int*);
 
 ENUZAKNOKTA *enUzakNoktaBulv2(NOKTA *);
 
 int main(){
 	//okunacak dosyanýn adýnný kullanýcýdan alýyoruz.
 	char dosyaAdi[30];
 	NOKTA *head;//------------------------(1)
 	
 	//max isminde býr dugumum olsun
	NOKTA *max;
 	ENUZAKNOKTA *n;
 	int d;
 	printf("Okunacak dosyanýn adi");
 	scanf("%[^\n]s",dosyaAdi);
 	
 	//dosyadan oku fonksyonuna dosyanýn adýný gondericem.
 	//okuma iþlemini bitirdikten sonra bir linked list yazýcak.o linked list'te bana head lazým.
 	//yani bir donus degeri olsun diyorum.head diye bir þey olusturuyorum burda head'e aktarýlacak.
 	//bunu yapmak için de NOKTA turunde bir pointer yazmam lazým.----------------------(1)
 	head=dosyadanOku(dosyaAdi);
 	//Dosyadan okuduktan sonra bu listeyi alalým ekrana yazdýralým.
 	//listeYaz'a head'i gonderiyorum.
 	listeYaz(head);
 	printf("Recursive printf\n");
 	listYazRec(head);
 	
 	//bu max'a en uzak nokta bul'dan return gelicek.ben ona ne göndercem.head'i göndericem bir de integer olarak bir degiskneim olucak,bu d'nin adresini gönderiyor.
 	//bu sayede boyle yaparak napabiliriz aslýnda fonksiyonlarda birden fazla veriyi dolaylý olarak return edebiliyoruz.
 	//normalde burda bi tane veri dondurulebilir.
	 max=enUzakNoktaBul(head,&d);
 	printf("en buyuk uzaklýk degeri:%d\n",d);
 	printf("en uzak nokta(%d,%d)\n",max->x,max->y);
 	
	//ayný þekilde dondurdugu sey ne olsun yine bunu max'ýn içerisine alabilir miyiz alamayýz.onun için napýcaz su turden enuzaknokta turunden n isimli bir pointer olusturuyorum.bu n isimli pointer daha once malloc ile asagýda olusturulmus bir adres alanýný tutacak ve bu n'nin degerlerini surda oldugu gibi yazýcaz 
 	n = enUzakNoktaBulv2(head);	
 	printf("en buyuk uzaklýk degeri_v2:%d\n",n->d);
 	printf("en uzak nokta(%d,%d)_v2\n",n->pt->x,n->pt->y);
	
 	
 }
 
 //NOKTA türünde bir pointer dondurcek.
 //parametre olarak ne alcak:bi tane karakter dizi alýcak.
 Nokta* dosyadanOku(char *dosyaAdi){
 	//oncelikle bizim FILE pointer'ýna ihtiyacýmýz var.
 	FILE *fp;
 	//þimdi linked list'ten okurken þöyle bir þey yapalým:
 	//dizinin basýndan sonuna surekli git git yapmýylaým her defasýnda basa don sonra sona git olmasýn
 	//ben hem head'i tutayým hem de en son dugumu tutuyým.
 	//sureklý sona eklýyelim yaný.
 	//ama sona eklemek için surekli bastan arama da yapmýyalým.
 	
 	//ilk basta head'imiz NULL.
 	//bi tane end dugumumuz olucak.
 	//bi tane de tmp pointer'ýmýz olsun.
 	NOKTA *head=NULL,*end,*tmp;
 	//file pointer eþittir fopen
 	fp=fopen(dosyaAdi,"r");
 	if(fp==NULL){
 		printf("Dosya acilamadi");
 		
	 }
	 else{
	 	//þimdi gelelim dosyayý acmaya.bi kere burda yapýcagýmýz iþ dosyanýn sonuna kadar gitmek.while dongusu ile butun elemanlarý okucaz.
	 	//bu iþlem bittikten sonra dondurcegýmýz sey nolucak return diyelim head'i dondurecez.
	 	//while'ýn altýnda da okucaz.
	 	//dosyayý zaten yukarýda actýk.
	 	//bu while'ýn içinde okuycaz sonra linked list'e eklicez.
	 	while(!feof(fp)){
	 		//once bir dugum olusturalým tmp için bir tek elemanlý dugum olusturalým.
	 		//cunku bu linked list'in her defasýnda býr eleman okuyunca olusturdugum bir dugum olucak.
	 		//asagýdaki gibi bir dugum olusturduk.
	 		//daha sonra fscanf ile bu dugume veri okuyorum.
	 		tmp=(NOKTA*) malloc(sizeof(NOKTA));
	 		//file pointer'dan oku.
	 		fscanf(fp,"%d %d\n",&tmp->x,&tmp->y);
	 		//tmp'nin next'ini default olarak null yap.
	 		//sýmdý bu dugum olustu.
	 		tmp->next=NULL;
	 		//soyle bir algoritma dusunelim eger head'ým NULL ise yani hiç eleman yoksa ilk basta napýcak ilk dugum olarak bunu eklicek.
	 		//ve ilk dugum de son dugum de dogrudan tmp'nýn bulundugu adresi gostericek.
	 		//artýk tmp malloc ile olusturuldugu için heap bolgesinde bir þey yani fiziksel olarak program yasadýgý muddetce var olan bir þey.hatta bazý durumlarda program crash etse bile calýsýyor.garbage olarak kalýyor.
	 		//ilk adýmda head'imiz null oldugunda ilk eleman olarak bu geldi.
	 		
	 		if(head==NULL){
	 			head=end=tmp;
			 }
			 //eger ilk eleman null degilse end'imiz onceden vardý bi yeri gösteriyodu end'ýn next'ini dogrudan tmp yap diyorum.
			 //end'i de guncelle 
			 //ama bize lazým olan butun listeye erismek için gereklý olan sey surdaki head dugumumuz.-------------------------->(2)
			 else{
			 	end->next=tmp;//artýk end'imizin next'i yeni ekledigimiz dugumu gostericek.
			 	end=end->next;//bir dugum ekledigimiz için son dugumu tutan node'umuz bir ileri gidicek.
			 }
		 }
		 //Dosyamýzý kapatýr.
		 fclose(fp);
	 }
	 return head;//------------------>(2)
 }
 //ne lazým bize parametre olarak NOKTA turunde head pointer'ýmýz lazým burda liste uzerinde gezinecegimiz için ikinci bir pointer daha gerekiyor.
 //ve bunu head'e atýyoruz dogrudan----------->(3) tmp uzerinden gezinecegiz.
 void listeYaz(NOKTA *head){
 	NOKTA *tmp=head;//------------------>(3)
 	
 	printf("noktalar listesi\n");
 	
 	//tmp NULL dan farklý ise 
 	while(tmp!=NULL){
 		printf("(%d,%d)->",tmp->x,tmp->y);
 		tmp=tmp->next;
	 }
	 //sonunu göstersin diye yaptýk.
	 printf("null");
 }
 //yukarýdaki klasýk iteratif algoritma bi de bunun recursive'ini yazalým.
 //recursive methodlarýn özelliði neydi kendini cagýracak.
 //yine burda bana head'in tmp dugumu lazým.
 void listeYazRec(NOKTA *head){
 	NOKTA *tmp=head;
 	
	//eger tmp NULL'dan farklý ise yani son dugume ulasmamýssak.
 	//ulasmamýssak demek ki suan aradaki herhangi bir yerdeyiz.
 	if(tmp!=NULL){
 		//oncelikle napýcaz dugumu yazdýracaz.
 		printf("(%d,%d)->",tmp->x,tmp->y);
 		//sonra bir sonraki dugume gecmek için fonksiyonumu tekrar cagýracam.
 		//þimdi ilk gelen head dugum ilk eleman null olmadýgý için yazýldý sonra tmp'nin next'i diyerek ikinci eleamaný head'mýs gibi cagýracaz.iþte bu tmp olucak null degilse.en son bi yerde bu null olucak yani if'in içerisinden cýkýcaz.	 
 		listeYazRec(tmp->next);
	 }
	 //o zaman da sunu yapalým.
	 else{
	 	printf("null");
	 	
	 }
 }
 //en uzak noktanýn bulundugu dugumu alýp bu dugumu dogrudan yukarýdaki structer elemanýye return etmek istiyorum.
 //buraya bir parametre olarak bir head gelicek ve ben burda maximum distance'ý bulmak için soyle bir yani kacsa o deger o degeri bulmak için boyle bir deger istiyorum.yani parametre alýcam.
 NOKTA *enUzakNoktaBul(NOKTA *head,int *dmax){
 	//bir tane yine tmp dugumumuz olucak ilk basta bunu head'e esitlicez.bir de en buyugun oldugu max dugumum olsun diyorum.
 	//artýk her þey linked list'te oldugu için napýcaz tekrar dosyaya gitmicez.
	NOKTA *tmp=head,*max;
	//bir distance için soyle bir þey tutalým.
 	int d=0;
 	while(tmp!=NULL){
 		//bulundugumuz dugumun oncelikle distance'sini hesaplýyalým.
 		d=pow(tmp->x,2)+pow(tmp->y,2);
 		if(d>*dmax){
 			*dmax=d;
 			//maxýmum dugumum de tmp olsun.
 			max=tmp;
		 }
		 //yukarýdaki iþlemden sonra bir sonraki dugume gecelim.
		 tmp=tmp->next;
	 }
	 //bu iþlemler bittiginde return edicegim sey maxýmum dugumun bulundugu hangi dugumse onun pointer'ýný return ediyorum.
	 //dmax degeriyle de parametre olarak degeri degistirip bir call by reference mantýgýyla bu iþi yapýyoruz.
	 return max;
 }
 //ikinci bir method yazalým bu sefer buldugumuz en uzak nokta.
 //biz parametre olarak buraya sadece head almak istiyoruz.
 //oncelikle dondurecegimiz sey enUzaknokta turunden bir þey olucak.
 ENUZAKNOKTA *enUzakNoktaBulv2(NOKTA *head){
 	//NOKTA turunde bir pointer'ýmýz var.
 	//buna tmp dedik head'i atadýk.bi tane de max bu max'ý sunun içinde saklýcaz.bunu saklýyabilmem için burdan return edicegim seyin.
 	//sureklý yasamasý lazým.scop kurallarýndan ve duration kurallarýndan hatýrlýyalým.
 	//sureklý yasamasý için napmam lazým.
 	//2 þey yapabilirim.
 	//bunlardan bir tanesi malloc gibi bir þey kullanýcam ne için en uzak nokta için.
 	//bir digeri ne olabilir.bir digeri de 
 	//bellekte soyle bir duzen var :bilgisayarýnýzýn programýnýzýn için  ayýrdýgý bellekte bi yerde program memory saklanýyor.programýnýzýn hangi programsa ilgili kodlarýnýn bulundugu sey ,bi yerde static ve global variables bir yerde initialized variable,bir yerde stack,bir yerde de heap bolgesi var.biliyorum ki stack bolgesi kýsýtlý limitli ve bir methodda bir degisken tanýmlarsam integer gibi karakter gibi.bu tanýmladýgým sey stack bolgesinde tanýmlanýr eger dynamýc memory kullanmadýysam.o method veya fonksiyon tamamlanýnca o degiskene ulasamama olasýlýgým cok yuksek yani tekrar onun yerine baska bir yer tahsis edilir.dolayýsýyla heap bolgesinden yer tahsis edebilirim.napýyoduk program kaldýgý muddetce bu iþ yapýlabiliyordu.heap bolgesinden yer almak için de dinamýc memory alloccasyonu fonksiyonlarýný kullanmam gerekiyordu.veya static gloabal variables dedigimiz static ile bu iþi yapabiliriz.static de napýyor bir degiskeni bir defa olusturuyor program kapanana kadar saklýyabiliyoruz.
 	//tabi biz burda static kullanmýcaz.iþte bu iþin 2 farklý yolu var burda dynamýc memory allocation ile bu iþi yapalým.
 	
 	NOKTA *tmp=head,*max;
 	
 	
 	//enuzaknokta isminde bir pointer olusturuyorum.ptr eþittir en uzak nokta türünde pointerima soyle bir.1 eleamnlý bir þey olucak bu niye bi tane eleman cunku en uzak nokta bir tane gidicez bir tane elemanlýk yer acýcaz ve bunun pointer'ý stack bolgesinde saklancak tabi ama eþitliðin sagýndaki kýsým heap bolgesinde var edilen bir bellek hucresinin adresi ben bunu ptr ile burda saklýyorum ne zaman bunu return edersem.ptr'yi return edicem isin sonunda.bunu return ettigim yer neresi ise neresi olursa olsun gidicek orda saklanýcak ptr'nýn kendisi eþitliðin sol tarafý stack bolgesindedir ama eþitliðin sagýndaknden gelen deger heap bolgesindedir.dolayýsýyla ptr'nýn fonksiyon bitince bir hukmu kalmýyor.sadece dondurdugu pointer adresi her zaman yasayabilen bir adres
 	ENUZAKNOKTA *ptr=(ENUZAKNOKTA*)malloc(sizeof(ENUZAKNOKTA*));
 	//yine d=0 diye bir þey saklayalým
 	int d=0;
 	//bi tane de gecici bir degisken hangisi en buyuktur diye bir dmax dýyem.gecici degiskeni ben karsýlastýrma yaparken kullanýcam.
 	int dmax=0;
 	//tmp null dan farklý iken 
 	while(tmp!=NULL){
 		d=pow(tmp->x,2)+pow(tmp->y,2);
 		if(d>dmax){
 			dmax=d;
 			max=tmp;
		 }
		 //bir sonraki dugume gitmek için yaptýk
		 tmp=tmp->next;
		 //bu dongu tamamlandýgýnda elýmde en fazla uzaklýga sahýp dugumun adres bilgisi ve tabi ne var max uzerinde adres bilgisi d uzerinde de deger bilgisi var.o zaman diyoruz ki.
		 
	 }
	 //o zaman diyoruz ki ptr'nin d'sine dmax'ý yazýcaz
	 ptr->d =dmax;
	 //ptr içindeki pt'yede max isimli dugumumuzu alýcaz 
	 ptr->pt=max;
	 
 	//daha sonra ben bu ptr'yi return edicem 
 	return ptr;
 }  
   
   
   48.39
