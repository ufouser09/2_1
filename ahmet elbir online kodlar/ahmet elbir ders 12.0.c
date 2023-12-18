#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//head degiskenimiz gloabal bir degiskendi.
//biz kodlama yaparken global degisken kullanmaktan kacýnýrýz çunku bunun bazý zararlarý var.

typedef struct Employee {
	
	char name[21];
	char surname[21];
	char id[11];
	struct Employee *next;//----------->bu struct linked list türünde olacagý için bir sonraki elemanýn adresini tutucak.
}EMPLOYEE;

//Kayýtlarý listelerken mesela once adý yaz sonra id'yi yaz falan dicez
//Boyle ayný iþi yapan ama kucuk detaylarla yapan bir fonksiyon pointer yapýcaz.

EMPLOYEE *createNode();
void addRecord(EMPLOYEE **phead);
void removeRecord(EMPLOYEE **phead);
void printRecords(EMPLOYEE *head,void(*fptr)(EMPLOYEE*));
void printfNameFirst(EMPLOYEE *emp);
void printIdFirst(EMPLOYEE *emp);

int main(){
	EMPLOYEE *head=NULL;
	//Butun pointer degiskenler yukarýdaki verileri saklamaz o veriye ait adres saklar. 
	
	//Biz linked listlerde ekle cýkarma listeleme yapýcaz ama bunlarý belirli þartlara göre degistiricez:
	//mesela ada göre sirala ya da ilk önce surname yaz falan dicez.
	
	int choice=0;
	
	while(choice!=3){
		
		printf("1-Add \n2-Remove\n3-Exit");
		scanf("%d",&choice);
		
		switch(choice){
			
			case 1:addRecord(&head);//Adrecord'u cagýrýrken burda yaptýgým siralama algoritmasý head'i güncellicek.
			//basa ekle sona ekle ortaya ekle bunlarý biz yapýcaz.
			//adrecord'da head'in adresini çaðýrcaz çünkü head'in gösterdigi deger fonksiyon içerisinde degisecek 
			//ben bunu soyle de yapabilirdim mesela head=addRecord();
			//ama ben void bir method istedigim için boyle istedim.
			//yani hem gitsin parametre olarak hem de degissin...............................................
			
			
			printRecords(head,printfIdFirst);//Kayýtlarý yazdýrma fonksiyonu çaðýrdýk burda 
			break;
			
			
			case 2:removeRecord(&head);
			printRecords(head,printNameFirst);//Kayýtlarý yukarýda ID ye gore yazdýk burda name'e gore yaptýk.
			break;
		
		}
	}	
}
//Void olmýcak bu,EMPLOYEE türünde bir pointer dondursun.
//Bu sayede nolur yani createNode sayesinde basa ekle sona ekle ada göre ekle 
//yani nasýl eklicekseniz bu fonksyion her biri için caðýrýlýp tekar tekrar malloc'lar falan yazýlmaz.
EMPLOYEE *createNode(){
	
	EMPLOYEE *emp;
	
	//EMPLOYEE cast ettik 
	emp=(EMPLOYEE*)malloc(sizeof(EMPLOYEE));//-----------------------(1)-----------------------------------------------------------
																																	
																																	
	//sonra surdan kullanýcýdan verilerimizi de alalým. 
	//burda degerleri okuduk.
	
	printf("enter id,name and surname,respectively\n");
	scanf("%s %s %s\n",&emp->id,&emp->name,&emp->surname);
	//þimdi ben employee'nýn adresini biliyorum employee'nin gösterdigi yerdeki ID partýnýn alanýný bilmiyorum 
	//dolayýsýyla ampersant koymazsak hata alýrýz.
	//git employee'nin gösterdigi yerdeki ID adres alanýnýn adresini getir demek için burda ampersant kullanmamýz gerekiyor.
	//ayný þekilde employee name'i getir.sonra ayný sekilde employee surname'i getir.bu bilgi alýndiktan sonra sunu diyebiliriz.
	
	
	printf("eleman olusturuldu\n");
	
	return emp;
}


//buraya gelen þey bir head pointer adresi 
void addRecord(EMPLOYEE **phead){

	//þimdi yeni bir kayýt olusturacagým zaman öncelikle belli alanlar okuycam 
	//bu belli okudugum alanlar olusturdugumuz struct elemanýna ve bu olusturdugumuz struct elemaný
	//listenin içerisinde kalýcý halde olmasý için belleðin heap bölgesinde olusturmasý lazým 
	//bellegýn heap bolgesinde olusturmak için 
	//ne kullanmam gerekiyor.---------------------------(1)
	
	//dynamýc memory allocation kullanmam gerekiyor.
	//bu employee gecici bir pointer kullandýk.
	//employee pointer'ýnýn gösterecegi adrese bellegin heap bolgesinden bir degisken olusturalým 
	//yukarýdaki return iþleminden sonra(yani createNode fonksiyonunun sonundaki return'den bahsediyor.) 
	//buraya gelen deger ne ise buraya aktarýlacak 
	EMPLOYEE *emp=createNode();
	
	
	//Degerleri okuduktan sonra geldik bu iki satýra.
	//Þimdi emp'nin kendi içinde bir next alaný var mý var bu next alaný head'in tabi burdaki phead'den bahsediyoruz.
	//Emp'nin next alaný yani emp burayý gösteriyor.
	//Bunun next'i phead'in içerisindeki degeri göstericek phead'in içerisindeki deger neydi suan 100.
	//yaný burasý 100 nolu adresi göstersin diyorum.bu ne demek oluyor.
	//ana programdaki yani bu nasýl burayý iþaret ediyorsa bu da burayý iþaret ediyo demektir.
	//sonra phead'in gösterdigi adrestteki deger demektir bu phead nereyi gösteriyor burayý gösteriyor.
	//bu NULL bunun gösterdigi adrestteki degere 300 yazýcakmýsýz yani emp'nin adresini yazýcaz demektir.
	//burda da bunu yazýyoruz.þimdi bu burayý gösteriyor.bu 100 nolu adreste su an için head'i gösteriyor.
	//sanki bir cýrcular durum var gibi.bi sonra bi tane daha kayýr ekliyelim hadi fonksiyon bi da çaðýrýldý fonksiyon cagýrýldýktan sonra head'imiz artýk null degil head bir adres gösteriyor.
	//ama head'in adresi sabit çünü burda main içerisinde tanýmladýk herhangi bir þekilde main fonksiyonu daha tamamlanmadý hala head degiskeni stack bolgesinde yasýyor.
	//Suraya geldik hala phead 100'u gostericek ayný degisken yeni bir emp olusturuldu hatta yeni olusturulunca sunun içerisini su dali kopardýk artýk yeni bir emp olusturulduktan sonra bir bellekte yer acýldý buraya 500 nolu adresi diyelim bu artýk bu sey artýk 500'u gostericek bunun kendine göre degerleri okundu emp'nin next'i yaný surasý phead'in gösterdigi degeri gosteriyomus.phead 100'u gosteriyodu burasý da 300'ü gosteriyor.yani suraya 300 yaz dicekmiþ.buraya 300 yaz diyerek artýk napýyoruz.biz burayý gösteriyoruz.sonra emp'yi de head'in gösterdigi yerdeki degere ata diyoruz.surasý da 500 olucakmýs.naptýk bu buraan koptu.bu artýk buraya geldi.cýrcular olma durumu nedir.head burayý göstericek bu dugumu göstericek.bu burayý göstericek bunun en son adresini null yapmadýk da basa dondurduk.þimdi bunu birazdan yazdýrma kýsmýna gelince detayýna bakarýz.
	//employee'nin next'i eþittir head olsun 
	emp->next=*phead;
	
	//sonra head'i de emp olsun diyorum. 
	*phead=emp; 
	
}
//þimdi baslnagýcta bir head'ýmýz var head degiskenimiz var 
//head'in kendine gore 100 diye bir adresi var
//ilk basta içerisi neyi gösteriyor.
//program açýlýnca null gosteriyor.

//surda fonksiyon içerisine geldigimizde  headpp diye bi tan degiskenimiz var.
//head pointer yani addrecord fonksiyonundaki parametre.buraya gelen sey.
//burasý pointer oldugu için burayý 2.dereceden pointer yaptýk.
//addRecord içindeki fonksiyonumuzun parametresi double pointer olucak.
//cunku adresi geliyor adresi geldigi için buranýn 2.derece pointer olmasý lazým.buraya gelcek olan þey 100 gelicek 
//sonra bir emp diye bir þey olusturduk pointer.emp neyi tutucak malloc ile bellegin heap bolgesinde olusturulmus bir struct elemanýnýn adresini tutucak 
//iþte bu struct elemaný ornegün 300 nolu adreste tutulsun bu 300 no'lu adresi göstermek için emp içine 300 yazýldý.





//kayýt silme kýsmý:yine ayný þekilde bir head degiskenini alýcaz.
//silmek istedigimiz kisinin ID sine göre silicez genellikle ID uzerinden silinir.
void removeRecord(EMPLOYEE **phead){
	//burda bir ID degiskeni tanýmladýk.silme iþlemi yaparken þöyle bir þey yapýcaz aradýgým dugumler içerisinde 
	//yani söyle bir durum var bunlar birbirini gösteriyor.mesela 2.yi siliceksem burdaki su dugum artýk surdaki baglantý napýcak suraya gidicek 
	//dolayýsýyla benim sunu tutmam gerekiyor.bi yandan da sunu tutmam gerekiyor.yani buraya geldigimde silicegim elemaný buldugumda 
	//bir öncekinin next'i ile bir sonrakini linklemem gerekiyor sadece.onun için 2 tane degiskene ihtiyacým var burda.
	
	char id[11];
	//birincisi current pointer diyelim.bu head üzerinden baslayýp arama yapmamý saglýcak bir þey olucak bunu boyle dereferans ile .
	EMPLOYEE *current=*phead;
	//bir digeri de EMPLOYEE arama iþlemi yaparken kullanýcagým pointer þimdilik bu null olucak.
	EMPLOYEE *prev=NULL;
	//ve arama yaparken bi tane integer found degiskeni kullanalým bulana kadar arama durumunda bir de 
	int found=0;
	
	//kaldýrýlacak silinecek kiþinin adý
	printf("enter id of the employee to be remove");
	scanf("%s",id);
	
	
	
	//2 tane þartým olucak burda eger bulursam tekrar aramasýn diye þimdi current eleman yani sürekli next next diye gidicez NULL dan farklý oldugu muddetce ayný zamanda ve bulunmadýgý muddetce aramaya devam et demek istiyorum.
	while(current!=NULL && !found){
		
		//sonra bir string karsýlastýrmasý yapýcam iþte current elemaný gösterdigi yerdeki ID degeri tabi bunu karþýlastýrmak için strcmp kullanmak en dogrusu current 'ýn gösterdigi yerdeki ID degeri bizim surda girdigimiz ID'ye eþitse yani bulduysak öncelikle found=1 diyelim.
		if(strcmp(current->id,id)==0){
			found=1;
			
			//þimdi burda öncelikle yapýcagýmýz sey onceki dugumu kontrol edicez.yani pev dugumunu kontrol edicez.prev dugumunun null olmasý durumunda mesela ilk elemanda bulduk head'i dogrudan silme durumumuz var.bir sonraki adresini kontrol etmek için þurda þöyle bir kontrol diyelim.mesela ilk elemanda bulduk.su head'in pointer'ýný phead tabi gösterdigi yerin adresini phead eþittir current elemanýnýn next'ine bi sonraki elemana dogru aktarýyoruz.phead'im eþittir current next diyorum eger boyle bir durum yoksa 
			if(prev==NULL){
				*phead=current->next;//phead'imiz current next'imiz nereyi gosteriyorsa artýk orayý gosteriyor.
			}
			
			//boyle bir durum yoksa ne demek ilk elemaný degil baska bir elemaný siliceksem o zaman napýcam previous'u bi yerde saklamam lazým.prev'in next'i eþittir current'in next'i diyebiliriz.bu iþlemi yaparak aslýnda silmiþ oluyorum.yani aradaki dugumu devreden cýkardým.tabi buldugum için napýcam ordaki current elemanýnýn gösterdigi yerdeki bellek alanýný serbest býrakmam gerekiyor.eger bu iþlem yanlýssa yani bulmadýysak.
			else{
				prev->next=current->next;
			}
			free(current);
		}
		
		//bu durumda yapýcagýmýz sey ne olur.su anký elemaný previous olarak yani en son kaldýgým bi önceki eleman olarak alýcam.yani prev eþittir current olucak current'ý da bi sonraki elemana göndercem.current eþittir.niye current üzerinde gezdim.head'i kaybetmemek için bu ancak ya dizinin sonuna kadar ki burda basa donme durumu da var aslýnda bi þekilde bu bu þekilde aramaya devam edicek.
		else{
			prev=current;
			current=current->next;
		}
	}
	
}
//þimdi bu fonksiyonu çaðýrdýgýmda bana phead geliyor.su an için phead'in adresi 100.
//þimdi current diye bir degiskenim var prev diye bir baska degiskenim var.
//head'in gösterdigi yerdeki adresin degeri yani head'in gösterdigi yerdeki deger neymiþ 500 olucakmýþ.
//EMPLOYEE *current=*phead  bu satýrda bunu yaptýk.
//prev olusturduk burasý null olucakmýþ.
//sonra found demiþ iþte bir ID girin demiþ.ID girildi.
//su arada bi dugum daha olsun burasý da 800 olsun bu 800 burayý gostersin head'de nereyi göstericek.
//Boyle 3 tane listedeki eleman olsun.
//oncelikle biz diyelim ki suradaki bir ID'ye karsýlýk gelen bir sey bulduk.
//þimdi donguye giriyoruz.current'ýn ID'si þimdi current dedigimiz sey neyi göstericek.
//current da burayý gostericek.
//bu girdigim ID burdaki ID'ye esit oldugunu kabul edelim.yani su sart dogru oldu.
//found'ý 1 yaptýk.
//previous su an null mu:evet.null oldugu için phead'i napýyorum current'ýn nextine current'ýn nexti ne demek current burayý gösteriyor.
//bunun nexti de 500'ü gösteriyor.sonra phead'in gosterdigi adrese git 500 yap yani git surayý 500 yap dedi 500 yapýnca noldu su bag gitti.
//tekrar burayý gosterdi.dedi ki su current'ý free et.

//degilse kýsmýna gectik tekrar basa gecti kaydýmýz silindi tabi tekrar basa donmedik buldugumuz için donguden çýktý gitti.
//sonra bu fonksiyon tekrar cagýrýldý.bu fonksiyon tekrar cagýrýldýgýnda kim cagýrýyor bunu main cagýrýyor.
//maýn'den head'le cagýrýyor.head'in hala program kapanmadýgý için head'in adresi hala 100 sonra current'ýmýz var 
//current'ýmýza bu sefer neyi atadýk phead'i atadýk.yani phead'in gösterdigi adres.su an 500'du.bu da burayý gösteriyor olsun.burda da null var.
//ID girelim girdik bir ID iþte surdaki ID ye eþit olucak bi þey yapalým þimdi de.
//sýmdý current'ýn ID'sý ID'ye eþit mý hayýr.hayýr oldugu için geliyorum su else kýsmýna diyorum ki current'ý prev'e ata current'ýn içindeki deger ne 500.bunu 500'e atadýk.
//)artýk bu da burayý gösteriyor.current'ý current'ýn next'ine ata current burayý gösteriyor.bunun next'i nereyi gösteriyor.burasý 300 olucakmýs demek ki.
//bu ne oldu bu artýk burayý gösterdi.donduk basa tekrar girilen ID ID ye eþit mi evet.bulduk olarak iþaretledik.previous null'a eþit mi previous null' a eþit degil 
//þu kýsma geldik.diyo ki prev'in next'ine.prev nereyi gösteriyor burayý gösteriyor.bunun next'i nereyi gösteriyor.surayý gosteriyor.bu prev'in gösterecegi next alaný.
//prev'in next'ine dedigimiz sey su alan current'ýn next'ine atanýcakmýs.
//current'ýn next'inde ne var.100 var.current'ýn next'inde 100 var.suraya getir dýyoruz.yani bu napýacak burdaki baglantýyý kopardýk.
//bu burayý göstericek þimdi.bu burayý gösterince bu da burayý gösteriyor.bu ilk adýmda bunu yaptýk.sonra bu cýktýktan sonra current'ý diyo ki free et.
//current'ý free etmek ne demek burdaki dugumu yok et.burdaki dugum yok olunca surdaki baglantý tamamen gitmiþ oluyor.
//ondan sonra ne kaldý else kýsmýnda herhangi bir þey kalmadý dongu bitti.bu buldugumuz için.fonksiyon bitti ve maine geri donduk.ekle ve sil bu kadar.
//naptýk çift pointer kullanarak head'in gosterdigi kýsmý dinamik olarak degistirdik.

//þimdi su printNameFirst alanlarýný da yazalým.





-----------------
|		500		|				
|				|				
-----------------


-----------------
|		500		|
|				|
-----------------

-----------------
|		500		|
|				|
-----------------














//þimdi bunu cagýracak printRecord çünkü bu fonksiyon dogrudan  çaðrýlmýyo hiçbir þekilde.
//cagýrýlacak sey ne aslýnda kayýtlarý yazdýrmak ne aslýnda dizinin basýndan basla sonuna kadar git ben asagýdaki fonksiyonlar için ayrý ayrý while dongusu yazmama gerek yok.her þey ayný ilerliyor.bunun için daha generics bir fonksiyon yazýyorum.
//bir head'i alýyorum bir de head ile birlikte burda hangi fonksiyonu çaðýracaksam onun pointer'ýný alýcam.pointer tanýmý bu iki fonksiyonu da prototopi ile yazýcaz.void turunde bir pointer tanýmý gelicek iste buna *fptr diyelim fonksiyon pointer oldugunu soyliyelim.ve burda parametre olarak kullanýlacak olan sey bu fonksiyonlarda EMPLOYEE þeklinde bir pointer kullanýlacak boyle bir prototip aldým.bu prototipi aktarýlacak degisken nereye geliyor.sunun adresi su degiskene geliyor.gelelim bunun içerisine yazalým.

//printRecord çaðýrýlacak þey ne aslýnda
void printRecords(EMPLOYEE *head,void (*fptr)(EMPLOYEE*)){
	//tmp eleman olusturuyoruz gezinmek için bu elemana da direk head'i atayabiliriz.
	EMPLOYEE *tmp=head;
	
	while(tmp!=NULL){
		//ne yap her bir gordugun dugumde fptr'yi cagýr.neyle cagýr nasýl parametre istiyosam onla cagýr.
		fptr(tmp);
		//su tmp'yi de guncelle
		tmp=tmp->next;
	}
}

//oncelikle bu bir void bir method
void printfNameFirst(EMPLOYEE *emp){
	printf("%s %s %s\n",emp->name,emp->id,emp->surname);
}
//bir de printIDfirst yazalým ikisini de kullanalým.sýmdý burda herhangi bir head uzerinde degisiklik yapmýcaz.head üzerinde degisiklik yapmýcagýmýz için burda dogrudan head'in kendisini adresini göndermeden ki kendisini gondermek daha dogru.pointer'ýný alýp napabiliriz burda tabi burda sadece bir degisken yazýcam onun için diyorum ki tek bir pointerla bu iþi yapabiliriz.
//Bunu birazdan fonksiyon pointer'ý olan baska bir fonksiyon cagýracak 
void printfIdFirst(EMPLOYEE *emp){
	printf("%s %s %s\n",emp->id,emp->name,emp->surname);
}
//calýsmanýz için soru istersek neler yapýlabilir.
//mesela ID ye gore arayý ekle ada gore arayý ekle veya sona ekle dogrudan basa ekle diyebilirsiniz.bunu cesitlendirebilirsiniz.bunu cesitlendirirkende addRecord'un ilk 4 satýrý ayný olucak 



