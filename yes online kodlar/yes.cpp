dizi yapýsýnýn etkisiz kaldýgý ya da yetersiz kaldýgý cok yer var bunun en onemli sebebi su otomatik olarak kapasitesi degistirilemez bir dizi

ben bir dizinin boyutunu arttýrmak istiyorum mesela ben çalýþma anýnda dinamýk olarak yapamýyorum mesela bir dizinin kapasitesini genislettiginizde o dizinin içerisindeki veri de silinmiþ oluyor. 

diyelim dizide ortadaki elemaný silicez bu iþlem dizilerde cok verimsiz

biz acaba ilgili veriyi daha farklý sekilde organize edemez miyiz

bir sossis gibi peþi sýra dizilmiþlerdir linked listler aradaki baglantýyý da pointerlar saðlýyor

linked list'in her bir elemaný node diye bahsettiðimizin bir bileþeni oluyor

bir düðüm kendi içerisinde veri elemaný ve sonraki elemanýn bellekteki yerini göstericek iþaretciden olusmakta
bir düðümün iki parcasý var
birincisi veri
ikincisi sonraki düðümü gösteren iþaret

her bir düðüm bellekte cok farklý yerlerde yer alabilir
mesela birinci node 1000 adresinde yer alýrken ikinci dugum 2010 adresinde yer alabilir
yani bu elemanlarýn bellekte peþi sýra yer almalarýna bile gerek yok.
çunku zaten sonraki dugumu gösteren bir pointer'ým var.

bellekte nerede bos yer var ise git oraya düðüm koy seklinde çalýsabiliyoruz.
yani birbirini peþi sýra takip eden bellek alanlarýna ihtiyacýmýz yok.

listenin sonunu nasýl iþaretliycez :bir sonraki düðümü gösteren pointer alanýna NULL koyarsak iþte o listenin sonunu iþaret etmiþ olur.

bu listedeki ilk dugumun özel bir adý var:head node listenin ilk dugumu ilk dugumu mutlaka tutmak zorundayýz cunku ipin ucu nerden baslýyor bunu bilmemiz lazým hep yoksa veriyi kaybetmýs oluruz.

head node'u her zaman için tutuyoruz.

boyle bir yapýyla eleman eklemek veya eleman silmek cok kolay

mesela ben bir dugumu silmek istiyorum tek yapýcagým sey bir onceki dugume gidip onun next node isaretcisini next'in de next'i seklinde isaretlemek onu yapýnca artýk o dugumumuz bellekten gitti yaptýgýmýz sey sadece bir isaretcinin yerini degistirmek oldu halbuki bu bir dizi olsaydý butun sagdaki elemanlarý sola shift edicektik tabiki de bu yapýcagýmýz is linked list'lerde daha kolay

veya araya yeni bir dugum mu eklemek istiyoruz dizide olsa bi kere dizinin kapasitesini arttýrmamýz gerekiyor ki o da cok zor 

linked listte biz dugum eklemek istedigimiz zaman araya bir tane node'u kolayca koyabiliriz.boylece mevcut elemanlarý hicbir sekilde oynatmak zorunda kalmadým.

dizinin en buyuk avantajý belirli bir konumdaki elemana direk erisebiliyorsunuz.
dizinin i.elemanýna direk erisebiliyorsunuz.

ama linked listte ben 4.elemana erismek istersem head node tan itibaren 4 tane bellek iþaretcisi izlemek zorundayým

dizilerin en buyuk avantajý bu random access dedigimiz direk erisilebilme kolaylýgý onun dýsýnda bircok sey dizilerde zor.




#include <stdio.h>
#include <stdlib.h>

typedef struct Employee{
	char name[20],surname[20];//bunlar benim iþ mantýgýmla ilgili veriler
	int ID;
	float salary;
	struct Employee *next;//ben aslýnda bu calýsanlarý linked list veri yapýsýnda tutucagým icin listedeki bir sonraki calýsaný tutacak dugumu de eklemis oldum.listede bir sonraki elemaný gösteren iþaretçi
	//yukardaki satýr:bu veriyi tutucagým yapýya iliþkin bir eleman bunlarý  birbirinden ayýrmam daha dogru olabilir bunlarý dedigim yukardaki data kismi ile bir üst satirdaki node pointerým.
}EMPLOYEE;

EMPLOYEE *head;//linked listte ilk düðümü her zaman için tutmamýz gerekiyor.ipin ucunu kacýrmamýz gerekiyor.yoksa veriyi kaybederiz.bu yüzden gloabal degisken olarak bu listenin ilk dugumunu sürekli tutuyorum.ya bunu gloabal degisken olarak tutucam ya da main içerisinde tanýmlarsam employee ile ilgili iþlem yaptýgým her fonksiyona listenin basýný da ayrýca göndermem gerekecek.ayný seyi tekrar tekrar göndermek yerine bir global degisken olarak bir global iþaretci tutmayi tercih ettim.
//yukardaki satýr baslý basýna employee turunden bir pointer ve bunu da global degisken olarak tutuyorum maýn içerisinde ve tanýmladýgým her fonksiyon içerisinde buna erisebilicem

//bu yukarýda gordugunuz struct yapýsý kusurlu cunku bu struct hem içinde veri var hem de dugum pointer'ýmýz var ama ben baska bir veri yapýsýna geçmek istedigimde sistemi komple degistirmek zorunda kalýrým onun yerine bir alternatifi var soyle yapabiliriz.


//iki ayrý struct tanýmlýycam birincisi sadece calýsan ile ilgili verileri içeren EMPLOYEE struct'ý daha sonra bu employee turunden veriyi içerecek linked list dugumleri için ayrý bir struct daha tanýmladým bunun içerisinde yukarda tanýmladýgým employee turunden bir data sonra yeni olusturdugum liste dugumu türünde bir sonraki dugumun iþaretcisi seklinde taným yapmak ve benim bundan sonra global pointer olarak tanýmlasam daha güzel olurdu 
//ben belki linked list veri yapýsýný degistiricem o yuzden boyle yaptýk
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


//þimdi diyelim ki bu calýsanlar listesindeki butun elemanlarýn listelemek için bir fonksiyon hazýrlýyalým.once bir elemaný yazmak için fonksiyonu hazýrlýyalým ki ondan sonra listedeki tum elemanlarý tek tek dolaþýp her birini yazdýralým þeklinde ikinci bir fonksiyonumuzu da bir oncekinden yararlanarak daha kolay hazýrlýyabilirim.

//bir elemaný bastýrýcam daha cok call by reference ile cagýrmayý tercýh ediyorum.burda sadece yazdýrýcam

void printElementP(EMPLOYEE *emp){//parametre olarak ilgili struct turunden bir pointer alýyor o yuzden ben pointer olarak verdigim için uye alanlarý ok operatoru ile erismem gerekiyor.ekrana yazdýrýyorum
	printf("Employee %d %s has a salary of %f\n",emp->ID,emp->name,emp->surname,emp->salary);//bu bir dugumunun elemanýnýn verisini yazdýrmak için kullanýlan fonksiyondu
}//printElemanP istedigimiz bir elemaný yazdýrmak için kullanýrýz printList ise kendi içinde tum elemanlarý yazdýrýr zaten
//þimdi listenin basýndan baslayýp tum elemanlarýný dolasýp her birini ekrana yazdýrmayý yarayan fonksiyona gecelim 
void printList(){
	int j;//birinci calýsan ikinci calýsan diye sayý da yazmak istiyorum o yuzden for dongusu yaptým yoksa while dongusu de kurabilirdik.
	//listede birinci dugumu yazdýktan sonra sýradaki dugume ilerlemem gerekiyor bunun için for içinde yazýlan þeyleri yazdýk
	
	EMPLOYEE *p;//ben head'i hiç ellememek degistirmemek istiyorum bu yuzden biz ayrýca bir employee pointer'ý olusturduk.
	
	//forun içindeki degiskenimiz ilk dugumden baslýycak pointer null olmadýgý surece bir sonraki dugume otomatýk olarak gidicez ya donguden ne zaman cýkýcak gidicek bir sonraki dugum kalmadýgý sürece
	for(j=0,p=head;p!=NULL;p=p->next,j++)
	printf("%d-th person:%d\t%s\t%f\n",j+1,p->ID,p->name,p->surname,p->salary);
}

//listedeki her eleman için gerektikce yeni bir bellek ayýrmasý sorumlulugu da bizde ve bu belleði ayýrdýktan sonra o ilgili yeni çalýsanýn degerlerini okumak ondan sonra baglý listeyle listenin sonuna eklýyorsan biraz daha kolay iþte ilgili ekleme komutlarýnýn yürütmek de bizde bu nedenle aþaðýdaki fonksiyonu görelim.
//bu çalýsanla ilgili butun bilgileri alsýn
//o calýsanýn bellekte saklanmasý için gerekli dugume yer ayýrsýn ve ondan sonra bu yeni dugumu listenin sonuna eklesin bu isleri yapýcak create_list_element fonksiyonuna ihtiyacýmýz var.
//olusturucagým yeni dugume bir iþaretci dondurmem gerekiyor 
//geriye ilgili çalýsan yapýsý turunden bir pointer geri dondurecek 
//yeni olusturacagým calýsan ile ilgili bir gecici pointer tanýmlamam gerekiyor.
//kisinin verilerini ID'sýný ve maasýný tutmak için gecýcý degiskenler tutmusum

EMPLOYEE* create_list_element( ) {
				
				EMPLOYEE *emp; int i; float s;
				
				emp = (EMPLOYEE*) malloc( sizeof( EMPLOYEE ) );//bu satýrda yeni bir calýsan dugumu sisteme ekleyebilmek için bi kere o kadarlýk yer ayýrmam gerekiyor.malloc komutuyla yapýyorum zaten bir eleman yer ayýrcam o yuzden calloc'a hiç ihtiyacýmýz yok burada içerisini bosaltmasýna da gerek yok o yuzden malloc tamamen yeterli bu asamada ne kadarlýk yer ayýrcam iþte benim bu EMPLOYEE yapým ne kadar byte tutuyorsa o kadarlýk yer ayýrmýs olucam ve malloc'un dondurdugu void pointer da EMPLOYEE yapýsýna cevirmek zorundayým tip donusumu yapmak zorundayým boylelikle bir yeni bir calýsaný alacak kadar bir yer ayýrmýs oldum.ama ayýramadýysam iþte bellek kalmadý hatasý verip programdan cýkýyorum.
				
				
				if( emp == NULL ) {
				
				printf("create_employee: out of memory."); 
				exit(1);
				}
				printf("Enter name of the person: "); 
				scanf("%s", emp->name);//burdaki satirda ilgili employee dugumunun name uyesine dogrudan scanf ile veri girisi yapabildik.ama ilgili kisinin ID sini ilk once onu gecici degiskene atamam kullanýcýnýn girdigi veriyi ondan sonra o verinin degerini ilgili struct field'ýna aktarmam gerekiyor.bu zorunlu.
				//bir struct yapýsýnda pointer olmayan yapýlara dogrudan erisemiyoruz.bu yüzden orda ampersant mutlaka koymam gerekiyor.
				//bir struct içerisindeki pointer olmayan primitive normal veri alanlarýna gecici degisken uzerinden veri aktarmamýz gerekiyor.
				//can’t get non-pointer struct fields directly in some platforms
				printf("Enter ID of the person: ");
				scanf("%d", &i);
				emp->ID = i;
				
				printf("Enter salary of the person: ");
				scanf("%f", &s);
				
				emp->salary = s;
				emp->next=NULL; 
				return emp;
				//biz burada yeni dugumu listenin sonuna ekleme kýsmýný burda kodlamadýk cunku bu fonksiyonun amacý ilgili dugumu olusturmak ben belki calýsanlarýmý maasa göre sýralý tutuyorum belki o yzuden ben bu yeni elemaný listenin en sonuna eklemicem ortalarda bi yerlerde de eklemek zorunda olabilirim.listenin basýna da eklemek isteyebilirim.o yuzden o iþi orda kodlamýyorum.burda sadece ilgili dugumu olusturmak bellekte yer ayýrmak ilgili degerleri içine yazmak ve olusturdugum bu yeni dugumu geriye dondurmek seklinde iþlem yapýyorum o yuzden create_list_element demisiz listeye ekleme yok listeye ekleme iþini biraz sonra bakýcaz
				
				//bu fonksiyon bellekte yer ayýrýyor fakat elemaný listeye eklemiyor bunu ayrý bir fonksiyonda yapýcaz
}
//yukarýdaki kodda ID'i direk scanf ile alamýyoruz

//bizim ilk once bu elemaný hangi dugumden sonraya eklýcegimizi bulmamýz gerekiyor.bu amacla p gecici pointer'ým var 

void add_element(EMPLOYEE *e){//eklicegimiz eleman bir dugum olarak fonksiyonuma geldi bunu listenin sonuna eklicek oncelikle listenin sonuna erisebilmemiz lazým  listenin sonuna erisebilmek için basýndan baslayýp sonuna kadar ilerlemem lazým bu yüzden dolasmakta kullanýcagým bir pointera ihhtiyacým var yalnýz her olasýlýgý dusunmemiz lazým.þimdi soyle bir þey de var benim listem bos da olabilir bos olursa benim head iþaretim null olmus olacak eger head null ise artýk eklenecek eleman benim listemin basýdýr head=e diyorum ve return diyorum fonksiyon bitiyor baska bir þey yapmama gerek yok artýk eklediðim ilk eleman olmus oldu bu e listemin basý olmus oldu ve fonksiyonumuz bitti.aksi takdirde benim listemin sonuna eriþmem gerekiyor.listenin sonuna erisebilmek için ise listenin basýndan baslayýp baktýgým dugum eger bir next pointer var ise yani null degilse o zaman bir sonraki dugume gecis yapabilmek için su an baktýgým iþaretci eþittir baktýgým dugumun sonraki iþaretcisidir diyerekten ilerlemem gerekiyor.gövde içerisine herhangi bir þey kodlamama gerek yok noktalý virgul diyip for dongusunu bitirebilirim nolmus oldu p iþaretcim surekli her iterasyonda p'nin nextine atanmýs oldu ne zamana kadar p'nin nexti null olmadýgý surece yani bu sekilde bu dongunun sonunda p artýk benim listemin sonunu tutuyor artýk simdi elemaný nereye eklicegimi buldum suan listenin sonunu gösteren p dugumunun sonuna eklemem gerekiyor.bunun için yapýcagým tek þey artýk listemin sonunu gösteren bu pointer'ýnýn next elemanýyla point ettiði elemaný eklemek istedigim dugum olmasýný saglamam yetiyor.eger dugumu olustururken dugumun sonraki elemanýna null demeseydim for dan sonra kodlamam gerekirdi yani bir listenin null terminated olmasý da önemli bu sekilde bir elemaný ekleyebiliyorum.  
EMPLOYEE *p;

// if the 1st element (head) has not been created, create it now:
//1. eleman (kafa) oluþturulmadýysa, þimdi oluþturun:

if(head == NULL){ 
	head=e; 
	return;
 				}
// otherwise, find the last element in the list:
//aksi takdirde, listedeki son öðeyi bulun:

//Span through each element testing to see whether p.next is NULL. 
//p.next öðesinin NULL olup olmadýðýný görmek için her bir öðe testini gözden geçirin.

//If not NULL, p.next must point to another element. 
//NULL deðilse, p.next baþka bir öðeye iþaret etmelidir.

//If NULL, we have found the end of the list and we end the loop.
//NULL ise listenin sonunu bulmuþ oluyoruz ve döngüyü sonlandýrýyoruz.
 
for (p=head; p->next != NULL; p=p->next); // null statement

// append a new structure to the end of the list
//listenin sonuna yeni bir yapý ekle
p->next=e;

}



int main(){
	EMPLOYEE *p,*q;
	int val, j;
	for(j=0; j<2; j++)
	add_element( create_list_element());//2 kere eleman ekle fonksiyonunu cagýrýcam ama once ilgili elemaný olusturup ondan sonra o olusturdugum elemaný dugum olarakta listeme ekliycem burada iki kere bu fonksiyon çalýsmýs olucak.öncelikle bu iki elemanlý listemi olusturduktan sonra acaba listemi dogru olusturabilmiþ miyim bi yazdýrayým.þimdi yeni bir eleman olusturalim sonra daha evvelki 1 ve 2 nin arasýna koyalým þimdi 3.elemaný olusturabilmek için gecici pointer'ým var.benim add_element fonksiyonum aslýnda listenin sonuna ekliyor listenin sonuna degilde ortaya bir yerlere ekleme iþlemini maýn içerisinde bir yerlerde yapýcam.bunu yapabilmek için yeni bir liste elemaný olusturuyorum ondan sonra nereye eklemem gerektigini bulucam ve q içinde tutucam bunu 
	for(j=0, p=head; p != NULL; p=p->next, j++)
	//for(p=head; p != NULL; p=p->next)
	{
	printf("%d-th person: ",(j+1)); printElementP(p);
	}
	
	// CREATE A NEW ELEMENT AND INSERT IT IN
//YENÝ BÝR ÖÐE OLUÞTURUN VE ONU EKLEYÝN

// BETWEEN THE 1st AND 2nd ELEMENTS IN THE LIST:
//LÝSTEDEKÝ 1. VE 2. ELEMENTLER ARASINDA:

p=create_list_element();
q=head; //to keep the first element, head::ilk elemaný tutmak için, baþ
insert_after(p, q); //and we insert p, after q::ve q'dan sonra p'yi ekleriz:
printList( );
return 0;

//araya eleman ekleme linked listte dizilere göre daha fazla avantajý var
//araya eleman ekleme
//araya eleman ekliceksem p dugumu ile ve dugumu arasýna bir eleman ekliceksem benim p dugumunu onceki dugumumu bilmem gerekiyor cunku text pointerý tek yonlu linked list
//tek yonlu linked listte hangi elemandan sonra hangi elemaný eklicegim sonucta iki elemandan bahsetmis olduk bu yüzden 2 tane pointer'ým var
insert after fonksiyonu q'yu p den sonra eklicek þimdi burda bazý hatalara karsý onceden kontrol yapmam yararlý olabilir bi kere p ve q ayný dugum olmamalý onun dýsýnda bu iki dugumden herhangi biri null olmamalý
ondan sonra sýmdý bu tek yonlu ya tek yonlu linked listte bir kýsýr dongu olusturmamam lazým sýmdý q'yu pden sonra eklemeye calýsýyorum ama q nun next pointer'ýda p
þimdi p den sonra da q'yu eklicem ama sunu da unutmamalýyým p'nýn q eklenmeden onceki halinde bir sonra nereyi gösteriyodu onu da unutmamam lazým
p den sonra q yu degil q den sonra p yý koy
q dan sonra p yý koymak için q'nun p'yi koymadan onceki next iþaretcisi neymýs onu mutlaka saklamak gerekiyor.
bu yüzden sýmdý p benim yeni dugumum yeni dugum olusturdugumda next pointer'ým null dý 
ben madem q dan sonra p yi koyucam 
þimdi q'nun nextini kaybetmemem gerekiyor.
eger q nun next'i p diye bir komutu ilk basta verirsem o zaman ipin ucunu aradaki iliþkileri kesmis olurum bu nedenle ben ilk once yeni eklicegim dugumu ve q'nun next pointer'ýný kaybetmemem gerekiyor demiþtim ya onu atýyorum ondan sonra q nun next'ine p dugumunu veriyorum bunlarýn sýrasini degistirirsem zincirin ucu kacýyor artýk  


/* To insert an element in a linked list, you must specify where you want the new element inserted.
Baðlantýlý bir listeye öðe eklemek için, yeni öðenin eklenmesini istediðiniz yeri belirtmeniz gerekir.

The following function accepts 2 pointer arguments, p and q,and inserts the structure pointed by p,just after the structure pointed by q. 
Aþaðýdaki iþlev, p ve q olmak üzere 2 iþaretçi argümanýný kabul eder ve p ile gösterilen yapýyý, q ile gösterilen yapýnýn hemen arkasýna ekler.

*/
void insert_after(EMPLOYEE *p, EMPLOYEE *q){
// if p and q are same or NULL, or if p already follows q, report that:
//p ve q ayný veya NULL ise veya p zaten q'yu takip ediyorsa, þunu bildirin:
if(p==NULL || q==NULL || p==q || q->next == p){
printf("insert_after(): Bad arguments \n");
return;
}
p->next = q->next;
q->next = p;
} 


