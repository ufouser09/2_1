dizi yap�s�n�n etkisiz kald�g� ya da yetersiz kald�g� cok yer var bunun en onemli sebebi su otomatik olarak kapasitesi degistirilemez bir dizi

ben bir dizinin boyutunu artt�rmak istiyorum mesela ben �al��ma an�nda dinam�k olarak yapam�yorum mesela bir dizinin kapasitesini genislettiginizde o dizinin i�erisindeki veri de silinmi� oluyor. 

diyelim dizide ortadaki eleman� silicez bu i�lem dizilerde cok verimsiz

biz acaba ilgili veriyi daha farkl� sekilde organize edemez miyiz

bir sossis gibi pe�i s�ra dizilmi�lerdir linked listler aradaki baglant�y� da pointerlar sa�l�yor

linked list'in her bir eleman� node diye bahsetti�imizin bir bile�eni oluyor

bir d���m kendi i�erisinde veri eleman� ve sonraki eleman�n bellekteki yerini g�stericek i�aretciden olusmakta
bir d���m�n iki parcas� var
birincisi veri
ikincisi sonraki d���m� g�steren i�aret

her bir d���m bellekte cok farkl� yerlerde yer alabilir
mesela birinci node 1000 adresinde yer al�rken ikinci dugum 2010 adresinde yer alabilir
yani bu elemanlar�n bellekte pe�i s�ra yer almalar�na bile gerek yok.
�unku zaten sonraki dugumu g�steren bir pointer'�m var.

bellekte nerede bos yer var ise git oraya d���m koy seklinde �al�sabiliyoruz.
yani birbirini pe�i s�ra takip eden bellek alanlar�na ihtiyac�m�z yok.

listenin sonunu nas�l i�aretliycez :bir sonraki d���m� g�steren pointer alan�na NULL koyarsak i�te o listenin sonunu i�aret etmi� olur.

bu listedeki ilk dugumun �zel bir ad� var:head node listenin ilk dugumu ilk dugumu mutlaka tutmak zorunday�z cunku ipin ucu nerden basl�yor bunu bilmemiz laz�m hep yoksa veriyi kaybetm�s oluruz.

head node'u her zaman i�in tutuyoruz.

boyle bir yap�yla eleman eklemek veya eleman silmek cok kolay

mesela ben bir dugumu silmek istiyorum tek yap�cag�m sey bir onceki dugume gidip onun next node isaretcisini next'in de next'i seklinde isaretlemek onu yap�nca art�k o dugumumuz bellekten gitti yapt�g�m�z sey sadece bir isaretcinin yerini degistirmek oldu halbuki bu bir dizi olsayd� butun sagdaki elemanlar� sola shift edicektik tabiki de bu yap�cag�m�z is linked list'lerde daha kolay

veya araya yeni bir dugum mu eklemek istiyoruz dizide olsa bi kere dizinin kapasitesini artt�rmam�z gerekiyor ki o da cok zor 

linked listte biz dugum eklemek istedigimiz zaman araya bir tane node'u kolayca koyabiliriz.boylece mevcut elemanlar� hicbir sekilde oynatmak zorunda kalmad�m.

dizinin en buyuk avantaj� belirli bir konumdaki elemana direk erisebiliyorsunuz.
dizinin i.eleman�na direk erisebiliyorsunuz.

ama linked listte ben 4.elemana erismek istersem head node tan itibaren 4 tane bellek i�aretcisi izlemek zorunday�m

dizilerin en buyuk avantaj� bu random access dedigimiz direk erisilebilme kolayl�g� onun d�s�nda bircok sey dizilerde zor.




#include <stdio.h>
#include <stdlib.h>

typedef struct Employee{
	char name[20],surname[20];//bunlar benim i� mant�g�mla ilgili veriler
	int ID;
	float salary;
	struct Employee *next;//ben asl�nda bu cal�sanlar� linked list veri yap�s�nda tutucag�m icin listedeki bir sonraki cal�san� tutacak dugumu de eklemis oldum.listede bir sonraki eleman� g�steren i�aret�i
	//yukardaki sat�r:bu veriyi tutucag�m yap�ya ili�kin bir eleman bunlar�  birbirinden ay�rmam daha dogru olabilir bunlar� dedigim yukardaki data kismi ile bir �st satirdaki node pointer�m.
}EMPLOYEE;

EMPLOYEE *head;//linked listte ilk d���m� her zaman i�in tutmam�z gerekiyor.ipin ucunu kac�rmam�z gerekiyor.yoksa veriyi kaybederiz.bu y�zden gloabal degisken olarak bu listenin ilk dugumunu s�rekli tutuyorum.ya bunu gloabal degisken olarak tutucam ya da main i�erisinde tan�mlarsam employee ile ilgili i�lem yapt�g�m her fonksiyona listenin bas�n� da ayr�ca g�ndermem gerekecek.ayn� seyi tekrar tekrar g�ndermek yerine bir global degisken olarak bir global i�aretci tutmayi tercih ettim.
//yukardaki sat�r basl� bas�na employee turunden bir pointer ve bunu da global degisken olarak tutuyorum ma�n i�erisinde ve tan�mlad�g�m her fonksiyon i�erisinde buna erisebilicem

//bu yukar�da gordugunuz struct yap�s� kusurlu cunku bu struct hem i�inde veri var hem de dugum pointer'�m�z var ama ben baska bir veri yap�s�na ge�mek istedigimde sistemi komple degistirmek zorunda kal�r�m onun yerine bir alternatifi var soyle yapabiliriz.


//iki ayr� struct tan�ml�ycam birincisi sadece cal�san ile ilgili verileri i�eren EMPLOYEE struct'� daha sonra bu employee turunden veriyi i�erecek linked list dugumleri i�in ayr� bir struct daha tan�mlad�m bunun i�erisinde yukarda tan�mlad�g�m employee turunden bir data sonra yeni olusturdugum liste dugumu t�r�nde bir sonraki dugumun i�aretcisi seklinde tan�m yapmak ve benim bundan sonra global pointer olarak tan�mlasam daha g�zel olurdu 
//ben belki linked list veri yap�s�n� degistiricem o yuzden boyle yapt�k
#include <stdio.h>
typedef struct {
	char name[20],surname[20];
	int ID;
	float salary;
}EMPLOYEE;

typedef struct emp_node{
	EMPLOYEE data;
	struct emp_node *next;
	
}EMP_NODE;

EMP_NODE *head;


//�imdi diyelim ki bu cal�sanlar listesindeki butun elemanlar�n listelemek i�in bir fonksiyon haz�rl�yal�m.once bir eleman� yazmak i�in fonksiyonu haz�rl�yal�m ki ondan sonra listedeki tum elemanlar� tek tek dola��p her birini yazd�ral�m �eklinde ikinci bir fonksiyonumuzu da bir oncekinden yararlanarak daha kolay haz�rl�yabilirim.

//bir eleman� bast�r�cam daha cok call by reference ile cag�rmay� terc�h ediyorum.burda sadece yazd�r�cam

void printElementP(EMPLOYEE *emp){//parametre olarak ilgili struct turunden bir pointer al�yor o yuzden ben pointer olarak verdigim i�in uye alanlar� ok operatoru ile erismem gerekiyor.ekrana yazd�r�yorum
	printf("Employee %d %s has a salary of %f\n",emp->ID,emp->name,emp->surname,emp->salary);//bu bir dugumunun eleman�n�n verisini yazd�rmak i�in kullan�lan fonksiyondu
}//printElemanP istedigimiz bir eleman� yazd�rmak i�in kullan�r�z printList ise kendi i�inde tum elemanlar� yazd�r�r zaten
//�imdi listenin bas�ndan baslay�p tum elemanlar�n� dolas�p her birini ekrana yazd�rmay� yarayan fonksiyona gecelim 
void printList(){
	int j;//birinci cal�san ikinci cal�san diye say� da yazmak istiyorum o yuzden for dongusu yapt�m yoksa while dongusu de kurabilirdik.
	//listede birinci dugumu yazd�ktan sonra s�radaki dugume ilerlemem gerekiyor bunun i�in for i�inde yaz�lan �eyleri yazd�k
	
	EMPLOYEE *p;//ben head'i hi� ellememek degistirmemek istiyorum bu yuzden biz ayr�ca bir employee pointer'� olusturduk.
	
	//forun i�indeki degiskenimiz ilk dugumden basl�ycak pointer null olmad�g� surece bir sonraki dugume otomat�k olarak gidicez ya donguden ne zaman c�k�cak gidicek bir sonraki dugum kalmad�g� s�rece
	for(j=0,p=head;p!=NULL;p=p->next,j++)
	printf("%d-th person:%d\t%s\t%f\n",j+1,p->ID,p->name,p->surname,p->salary);
}

//listedeki her eleman i�in gerektikce yeni bir bellek ay�rmas� sorumlulugu da bizde ve bu belle�i ay�rd�ktan sonra o ilgili yeni �al�san�n degerlerini okumak ondan sonra bagl� listeyle listenin sonuna ekl�yorsan biraz daha kolay i�te ilgili ekleme komutlar�n�n y�r�tmek de bizde bu nedenle a�a��daki fonksiyonu g�relim.
//bu �al�sanla ilgili butun bilgileri als�n
//o cal�san�n bellekte saklanmas� i�in gerekli dugume yer ay�rs�n ve ondan sonra bu yeni dugumu listenin sonuna eklesin bu isleri yap�cak create_list_element fonksiyonuna ihtiyac�m�z var.
//olusturucag�m yeni dugume bir i�aretci dondurmem gerekiyor 
//geriye ilgili �al�san yap�s� turunden bir pointer geri dondurecek 
//yeni olusturacag�m cal�san ile ilgili bir gecici pointer tan�mlamam gerekiyor.
//kisinin verilerini ID's�n� ve maas�n� tutmak i�in gec�c� degiskenler tutmusum

EMPLOYEE* create_list_element( ) {
				
				EMPLOYEE *emp; int i; float s;
				
				emp = (EMPLOYEE*) malloc( sizeof( EMPLOYEE ) );//bu sat�rda yeni bir cal�san dugumu sisteme ekleyebilmek i�in bi kere o kadarl�k yer ay�rmam gerekiyor.malloc komutuyla yap�yorum zaten bir eleman yer ay�rcam o yuzden calloc'a hi� ihtiyac�m�z yok burada i�erisini bosaltmas�na da gerek yok o yuzden malloc tamamen yeterli bu asamada ne kadarl�k yer ay�rcam i�te benim bu EMPLOYEE yap�m ne kadar byte tutuyorsa o kadarl�k yer ay�rm�s olucam ve malloc'un dondurdugu void pointer da EMPLOYEE yap�s�na cevirmek zorunday�m tip donusumu yapmak zorunday�m boylelikle bir yeni bir cal�san� alacak kadar bir yer ay�rm�s oldum.ama ay�ramad�ysam i�te bellek kalmad� hatas� verip programdan c�k�yorum.
				
				
				if( emp == NULL ) {
				
				printf("create_employee: out of memory."); 
				exit(1);
				}
				printf("Enter name of the person: "); 
				scanf("%s", emp->name);//burdaki satirda ilgili employee dugumunun name uyesine dogrudan scanf ile veri girisi yapabildik.ama ilgili kisinin ID sini ilk once onu gecici degiskene atamam kullan�c�n�n girdigi veriyi ondan sonra o verinin degerini ilgili struct field'�na aktarmam gerekiyor.bu zorunlu.
				//bir struct yap�s�nda pointer olmayan yap�lara dogrudan erisemiyoruz.bu y�zden orda ampersant mutlaka koymam gerekiyor.
				//bir struct i�erisindeki pointer olmayan primitive normal veri alanlar�na gecici degisken uzerinden veri aktarmam�z gerekiyor.
				//can�t get non-pointer struct fields directly in some platforms
				printf("Enter ID of the person: ");
				scanf("%d", &i);
				emp->ID = i;
				
				printf("Enter salary of the person: ");
				scanf("%f", &s);
				
				emp->salary = s;
				emp->next=NULL; 
				return emp;
				//biz burada yeni dugumu listenin sonuna ekleme k�sm�n� burda kodlamad�k cunku bu fonksiyonun amac� ilgili dugumu olusturmak ben belki cal�sanlar�m� maasa g�re s�ral� tutuyorum belki o yzuden ben bu yeni eleman� listenin en sonuna eklemicem ortalarda bi yerlerde de eklemek zorunda olabilirim.listenin bas�na da eklemek isteyebilirim.o yuzden o i�i orda kodlam�yorum.burda sadece ilgili dugumu olusturmak bellekte yer ay�rmak ilgili degerleri i�ine yazmak ve olusturdugum bu yeni dugumu geriye dondurmek seklinde i�lem yap�yorum o yuzden create_list_element demisiz listeye ekleme yok listeye ekleme i�ini biraz sonra bak�caz
				
				//bu fonksiyon bellekte yer ay�r�yor fakat eleman� listeye eklemiyor bunu ayr� bir fonksiyonda yap�caz
}
//yukar�daki kodda ID'i direk scanf ile alam�yoruz

//bizim ilk once bu eleman� hangi dugumden sonraya ekl�cegimizi bulmam�z gerekiyor.bu amacla p gecici pointer'�m var 

void add_element(EMPLOYEE *e){//eklicegimiz eleman bir dugum olarak fonksiyonuma geldi bunu listenin sonuna eklicek oncelikle listenin sonuna erisebilmemiz laz�m  listenin sonuna erisebilmek i�in bas�ndan baslay�p sonuna kadar ilerlemem laz�m bu y�zden dolasmakta kullan�cag�m bir pointera ihhtiyac�m var yaln�z her olas�l�g� dusunmemiz laz�m.�imdi soyle bir �ey de var benim listem bos da olabilir bos olursa benim head i�aretim null olmus olacak eger head null ise art�k eklenecek eleman benim listemin bas�d�r head=e diyorum ve return diyorum fonksiyon bitiyor baska bir �ey yapmama gerek yok art�k ekledi�im ilk eleman olmus oldu bu e listemin bas� olmus oldu ve fonksiyonumuz bitti.aksi takdirde benim listemin sonuna eri�mem gerekiyor.listenin sonuna erisebilmek i�in ise listenin bas�ndan baslay�p bakt�g�m dugum eger bir next pointer var ise yani null degilse o zaman bir sonraki dugume gecis yapabilmek i�in su an bakt�g�m i�aretci e�ittir bakt�g�m dugumun sonraki i�aretcisidir diyerekten ilerlemem gerekiyor.g�vde i�erisine herhangi bir �ey kodlamama gerek yok noktal� virgul diyip for dongusunu bitirebilirim nolmus oldu p i�aretcim surekli her iterasyonda p'nin nextine atanm�s oldu ne zamana kadar p'nin nexti null olmad�g� surece yani bu sekilde bu dongunun sonunda p art�k benim listemin sonunu tutuyor art�k simdi eleman� nereye eklicegimi buldum suan listenin sonunu g�steren p dugumunun sonuna eklemem gerekiyor.bunun i�in yap�cag�m tek �ey art�k listemin sonunu g�steren bu pointer'�n�n next eleman�yla point etti�i eleman� eklemek istedigim dugum olmas�n� saglamam yetiyor.eger dugumu olustururken dugumun sonraki eleman�na null demeseydim for dan sonra kodlamam gerekirdi yani bir listenin null terminated olmas� da �nemli bu sekilde bir eleman� ekleyebiliyorum.  
EMPLOYEE *p;

// if the 1st element (head) has not been created, create it now:
//1. eleman (kafa) olu�turulmad�ysa, �imdi olu�turun:

if(head == NULL){ 
	head=e; 
	return;
 				}
// otherwise, find the last element in the list:
//aksi takdirde, listedeki son ��eyi bulun:

//Span through each element testing to see whether p.next is NULL. 
//p.next ��esinin NULL olup olmad���n� g�rmek i�in her bir ��e testini g�zden ge�irin.

//If not NULL, p.next must point to another element. 
//NULL de�ilse, p.next ba�ka bir ��eye i�aret etmelidir.

//If NULL, we have found the end of the list and we end the loop.
//NULL ise listenin sonunu bulmu� oluyoruz ve d�ng�y� sonland�r�yoruz.
 
for (p=head; p->next != NULL; p=p->next); // null statement

// append a new structure to the end of the list
//listenin sonuna yeni bir yap� ekle
p->next=e;

}



int main(){
	EMPLOYEE *p,*q;
	int val, j;
	for(j=0; j<2; j++)
	add_element( create_list_element());//2 kere eleman ekle fonksiyonunu cag�r�cam ama once ilgili eleman� olusturup ondan sonra o olusturdugum eleman� dugum olarakta listeme ekliycem burada iki kere bu fonksiyon �al�sm�s olucak.�ncelikle bu iki elemanl� listemi olusturduktan sonra acaba listemi dogru olusturabilmi� miyim bi yazd�ray�m.�imdi yeni bir eleman olusturalim sonra daha evvelki 1 ve 2 nin aras�na koyal�m �imdi 3.eleman� olusturabilmek i�in gecici pointer'�m var.benim add_element fonksiyonum asl�nda listenin sonuna ekliyor listenin sonuna degilde ortaya bir yerlere ekleme i�lemini ma�n i�erisinde bir yerlerde yap�cam.bunu yapabilmek i�in yeni bir liste eleman� olusturuyorum ondan sonra nereye eklemem gerektigini bulucam ve q i�inde tutucam bunu 
	for(j=0, p=head; p != NULL; p=p->next, j++)
	//for(p=head; p != NULL; p=p->next)
	{
	printf("%d-th person: ",(j+1)); printElementP(p);
	}
	
	// CREATE A NEW ELEMENT AND INSERT IT IN
//YEN� B�R ��E OLU�TURUN VE ONU EKLEY�N

// BETWEEN THE 1st AND 2nd ELEMENTS IN THE LIST:
//L�STEDEK� 1. VE 2. ELEMENTLER ARASINDA:

p=create_list_element();
q=head; //to keep the first element, head::ilk eleman� tutmak i�in, ba�
insert_after(p, q); //and we insert p, after q::ve q'dan sonra p'yi ekleriz:
printList( );
return 0;

//araya eleman ekleme linked listte dizilere g�re daha fazla avantaj� var
//araya eleman ekleme
//araya eleman ekliceksem p dugumu ile ve dugumu aras�na bir eleman ekliceksem benim p dugumunu onceki dugumumu bilmem gerekiyor cunku text pointer� tek yonlu linked list
//tek yonlu linked listte hangi elemandan sonra hangi eleman� eklicegim sonucta iki elemandan bahsetmis olduk bu y�zden 2 tane pointer'�m var
insert after fonksiyonu q'yu p den sonra eklicek �imdi burda baz� hatalara kars� onceden kontrol yapmam yararl� olabilir bi kere p ve q ayn� dugum olmamal� onun d�s�nda bu iki dugumden herhangi biri null olmamal�
ondan sonra s�md� bu tek yonlu ya tek yonlu linked listte bir k�s�r dongu olusturmamam laz�m s�md� q'yu pden sonra eklemeye cal�s�yorum ama q nun next pointer'�da p
�imdi p den sonra da q'yu eklicem ama sunu da unutmamal�y�m p'n�n q eklenmeden onceki halinde bir sonra nereyi g�steriyodu onu da unutmamam laz�m
p den sonra q yu degil q den sonra p y� koy
q dan sonra p y� koymak i�in q'nun p'yi koymadan onceki next i�aretcisi neym�s onu mutlaka saklamak gerekiyor.
bu y�zden s�md� p benim yeni dugumum yeni dugum olusturdugumda next pointer'�m null d� 
ben madem q dan sonra p yi koyucam 
�imdi q'nun nextini kaybetmemem gerekiyor.
eger q nun next'i p diye bir komutu ilk basta verirsem o zaman ipin ucunu aradaki ili�kileri kesmis olurum bu nedenle ben ilk once yeni eklicegim dugumu ve q'nun next pointer'�n� kaybetmemem gerekiyor demi�tim ya onu at�yorum ondan sonra q nun next'ine p dugumunu veriyorum bunlar�n s�rasini degistirirsem zincirin ucu kac�yor art�k  


/* To insert an element in a linked list, you must specify where you want the new element inserted.
Ba�lant�l� bir listeye ��e eklemek i�in, yeni ��enin eklenmesini istedi�iniz yeri belirtmeniz gerekir.

The following function accepts 2 pointer arguments, p and q,and inserts the structure pointed by p,just after the structure pointed by q. 
A�a��daki i�lev, p ve q olmak �zere 2 i�aret�i arg�man�n� kabul eder ve p ile g�sterilen yap�y�, q ile g�sterilen yap�n�n hemen arkas�na ekler.

*/
void insert_after(EMPLOYEE *p, EMPLOYEE *q){
// if p and q are same or NULL, or if p already follows q, report that:
//p ve q ayn� veya NULL ise veya p zaten q'yu takip ediyorsa, �unu bildirin:
if(p==NULL || q==NULL || p==q || q->next == p){
printf("insert_after(): Bad arguments \n");
return;
}
p->next = q->next;
q->next = p;
} 


