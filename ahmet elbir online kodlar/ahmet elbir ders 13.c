/*
bir kutuphanedeki 11 raflı bir kitaplığa cesitli kitaplar yerlestirilecektir.
raflara hangi kitapların yerlestırılecegine,isimlerine gore hesaplanan birer unique kodla karar verilmektedir.

N harf uzunlugundaki bir kitap ismi için kod su sekilde hesaplanmaktadır.

kod-(ascııkodu(Kitap_ismi[0])(ascııkodu(Kitap_ismi[1])....ascııkodu(Kitap_ismi[i])..ascııkodu(Kitap_ismi[n])

raf_no-kod mod raf sayısı

kitap,koda denk gelen rafa yerleştirilecektir.

örnegin oğuz atayı"tutunamayanlar" kitabı:

RAF_No(tutunamayanlar)=84+117+116+117+110+97+109+97+121+97+114=(1494)
MOD 11=9.rafa yerleştirilecektir.

-ismi verilen kitabın raf numarasını belirleyerek listeye ekleyen

-kitaplığa eklenen tüm kitapların raf bilgilerini listeleyen 

-ismi verilen bir kitabı kitaplıkta arayıp bulunursa raf numarasını gösteren,bulunmasa kısa bir mesaj gösteren

bir algoritmayı C dilinde gercekleyiniz.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SHELF 11//shelf raf demek 

#define MAXSIZE 20//maxSıze kitabın isim uzunlugu olabiliyor

//bu yapı(struct) link list'dir çünkü kendisinden sonra gelicek olan elemanı işaret edicek pointerı da barındırıyor.
struct node{
	char name[MAXSIZE]; //kitap ismi
	int code;			//kod
	int index;			//raf no
	struct node *next;
};

typedef struct node List;


void insert(List **headRef,char bookName[]);//İnsert fonksiyonunda neden double point kullanıyorum ?
//Eger bi degisiklik kalıcı bir işlem yapıcaksam o zaman double point kullanmam gerekiyor.
//Double point olmazsa geri donuse gerek kalmaz.yani fonksiyonumuz void olabilir artık.


void search(List *head);
void display(List *head);
int findKey(char *s);


int main(){
	int opt;
	List *head=NULL;
	char bookName[MAXSIZE];
	
	while(1){
		printf("\nPress 1.Insert\t 2.Display \t3.Search\t4.Exit \n");
		scanf("%d",&opt);
		
		switch(opt){
			case 1:
				printf("\nEnter Book Name\n");
				scanf("%s",&bookName);//biz mesela seker portakalı yazsaydık burda sadece seker kelimesini alırdı 
				//bu yüzden scanf'i formatlamamız gerekiyor.gets ya da fscanf()fonksiyonları gibi;
				
				insert(&head,bookName);
				break;
				
				case 2:
				display(head);
				break;
				
				case 3:
				search(head);
				break;	
				
				case 4:
				exit(0);
					
				default:
				exit(1);
		}
	}
	return 0;
	
}

int findKey(char *s){//şimdi stringimizi buraya gönderdik.

	//eger stringım bos ise 0 don,degilse birinci karakterini al yani s'i al sonra s+1 den devam et
	return *s == 0 ? 0 : *s + findKey(s+1);//if(s==0)(return 0;)else(return *s+findKey(s+1);)
}


//Bu kitaplıgımıza kitap eklemek için.
//kitabın bilgilerini kullanıcıdan aldıktan sonra içine yazabilmemiz için yeni bir node olusturduk.
//bu node link list structına ait bir node.
void insert(List **headRef,char bookName[]){
	
	List *newnode =(List*)malloc(sizeof(List));//yeni bir node olusturacagımız için dinamik bellek allacotainonu yaptık.
	//ondan sonra yeni node'un içini gerekli bilgilerle dolduruyoruz.
	//burda null mı diye bir control yapabilirdik.
	
	int i,key;//burda i'miz bizim index'imiz key ise bizim kodumuzu olusturur.
	
	key=findKey(bookName);//burda kodu elde ediyoruz.//burda kitap ismini aldık mesela burdan bir key elde ettik key dedigimiz kitabın kitap ismindeki harflerin ascıı kodlarının toplamı yani  
	
	//ondan sonra i diye bir index elde ediyoruz bu da az once buldugumuz key'in shelf'e gore modunu aldıgımız zaman ortaya cıkıyor.bu index bu kitabı bizim hangi rafa koyucagımızı soylicek.o yuzden index'e i'yi yazdık.data mıza da key'i yazdık.sonra kitap ismini nodu'muzun içindeki bookname'e kaydettik.
	i=key%SHELF;//raf sayimiza boldugumuzde ise indeximizi bulmus oluyoruz.
	
	newnode->code=key;//bu kısımlarda esitleme yaptık.
	newnode->index=i;
	strcpy(newnode->name,bookName);//stringlerde direk esitleme yapamıyorduk.
	
	//sonra geldik newnode'un nextine çunku bi tane de next lazımdı,o ana kadar ki listenin birinci en bastaki elemanını newnode'un nextine koyuyoruz.bu ne demek oluyor.artık new node en bastakinden basla demek oluyor bu yani en basa ekledik listede biz bunu ondan sonra new node'u getirip yeniden listemizin adresine yazdıgımız zaman artık su newnode arkasından gelen sonraki listenin gerisi ilk satirdaki (*headRef) bu oluyor arkasından gelen listenin gerisi ile birlikte en basa eklenmıs newNode ile birlikte yeni bir liste olusuyor.yani new node 'u getirdik listenin en basına yazdık 
	//case 1: de insert içinde &head yapıyoruz burda neden adresini gönderiyoruz listenin çünkü listenin üzerinde mesela soyle dusunebilirsiniz mesela bir integer'ı gonderdigimiz bir fonksiyonun içinde degistirmek istiyoruz ve bu degisikligin kalıcı olmasının istiyoruz o zaman naparız o integer'ın adresini göndeririz demi.misal scanf.aynı sekilde ınserte de head'ın adresini gönderiyoruz.head'ımız ne surda tanımladıgımız bir linkli liste.structta tanımladıgımız bir node dıye dusunebilirsiniz.biz bunun içinde bir degisiklik yapmak istiyorsak onun adresini göndericez.insert cıft pointer'ı bu yüzden alıyor.linkli listenin birinci elemanı nedir.ilk elemanın oldugu yerin adresidir.
	//bizim bir menumuz var şimdi insert yapmak istedigimizde yukarıda tanımladıgımız ve en basında null atadıgımız yani içinin bos oldugunu soyledigimiz.listeyi gonderdik.liste bookName den olusan bilgilerle dolduruldu ve bize her seferinde bir tanecik data içine koydugumuz listemiz geri donuyor.
	newnode->next=(*headRef);//newnodun headin gösterdigi nodu gostermesini saglıyoruz.
	
	(*headRef) = newnode;//sonrada newnodu head'e esitliyoruz.yani artık head'ımız new node olmus oluyor.ve en basa head'i eklemis oluyorum.
}

//Peki search de napıyoruz:bir tane kitabın adını soylicez.
//O da varsa hangi raftta oldugunu soylicek.yoksa da yok dicek.
//Bunu nasıl yapıyoruz burda gördügünüz gibi listemizi sadece okuycaz.
//Yani onun içinde herhangi bir degisiklik yapmıcaz bu search fonksiyonu bitip bize geri dondugunde 
//Bu head'de bir degisiklik olmıcak biz sadece içine bakmak istiyoruz.
//O yuzden adresini göndermemize gerek yok.

void search(List *head){
	List *tempNode;//listeyi taramam gerekiyor bunun için gecici bir degisken tanımladık.
	char bookName[MAXSIZE];//kullanıcıdan bir kitap ismi isticegim için tekrar bir bookname dedik.
	
	//kullanıcıdan hangi kitabı aramak istedigini soruyoruz.onun key'ini de aynı yukarıdaki gibi olusturuyoruz.
	printf("\n Enter A Book Name to Search on Bookshelf\n");
	scanf("%s",&bookName);
	
	if(head==NULL){
		//burda ben liste bos olup olmadıgını kontrol ediyorum.liste eger bos ise benim herhangi bir eleman aramama gerek yok.
		printf("\n Book could not be Found");
	}
	
	else{
		//ilk once temp node' a bir head'i attık listemiz artık temp node'un içinde diye dusunun listenin içinde gezicez ondan sonra eger tempNode null degilse null olmadıgı muddetce ama aynı zamanda tempNode'un datası da bizim burda buldugumuz key'e esit olmadıgı surece link listteki bir sonraki elemana geciyoruz yani next'ine geciyoruz.bu while'ı ne zaman kırabiliriz.ya tempNode dedigimiz sey next yaptık next yaptık artık null oldu yani listemiz bitti ya bunda çıkar ya da tempNode'un datası key'e esitse çıkar bu while'dan peki neden cıktıgımızı hemen asagıda kkontrol etmemiz gerekiyor.biz bu while dan cıktık da neden cıktık.eger data key'e esit oldugu için cıktıysak ne demektir bu kitabımız orda bi yerde biz onu bulduk demektir.peki liste bittiyse de çıktıysak nedir  bu ne demektir liste bitti ama kitabı bulamadık demektir.yani bu durumda liste tamamen bossa ya da listenin sonuna kadar geldiysek kitabın bizim hesapladıgımız datayla burdaki data key birbirine esitse bu durumda napıyoruz bu tempNode'un index'inin bulundugu raftadır diyoruz 
		tempNode=head;//head'i tempnode'a esitliyorum neden cunku en basta listeyi gezicem.
		while(tempNode!=NULL && strcmp(tempNode->name,bookName)!=0)
			//temp nodu sürekli arttırıyorum.
			tempNode=tempNode->next;
		
		
		if(strcmp(tempNode->name,bookName)==0)
			//kitabı buldum ve hangi rafta buldugumu yazdırabilirim.
			printf("Book is on the %dth shelf\n",tempNode->index);
			
			
		
		if(tempNode==NULL)
			printf("\n Book is not in the Bookshelf\n");
		
	}
}
//display için de yine aynı şekilde burda da yine while dongusu yapıyoruz 
//Nodun içinde ilerliyerek node'ları yazdırıyoruz.
void display(List *node){
	while(node!=NULL){
		printf("%s(%d)->%d\n",node->name,node->code,node->index);
		node =node->next;
	}
}
//34.00
21.07
