/* 
uygulama-3
bir hastanenin acil servisinde kullanýlmak üzere bir kuyruk hazýrlanacaktýr.
kuyruk hastalarýn sýralarýný takip edebilmesi için kullanýlacaktýr.

hastalar hastaneye kayýt yaptýrmak için isim,soy isim,TC kimlik numarasý ve yaþ bilgilerini paylaþmalýdýr.

hastanelerde vakalar acil vaka olarak incelenmektedir.
bu dogrultuda asagýdaki ilkeleri gercekleyen kuyruk modelini olusturun.

1-yeni bir hasta geldiginde eger acil bir vaka degilse dogrudan kuyruga eklenmelidir.
asagýdaki ornekte ilk olarak 1'inci hasta gelir ardýndan 2,3,4 ve 5'inci hastalar gelir.

1...2...3...4...5

2-oncelikli bir hasta geldiginde ise listedeki son oncelikli hastadan sonraki sýraya yerlestýrýlmelidir.
listede hiç öncelikli hasta olmadýgýnda eklenecek oncelikli hasta listenin basýna eklenir.6'ýncý hasta onceliklidir ve listenin basýna eklenmistir.

6...1...2...3...4...5

ardýndan yeni bir oncelikli vaka geldiginde kuyruk asagýdaki gibi olmalýdýr.

6...7...1...2...3...4...5

3-hastalar doktora gorunmekten vazgectýklerýnde kuyruktan cýkarýlmalýdýr.
3'uncu hasta,hasta ismi kullanýlarak kuyruktan cýkarýlmýstýr.

6...7...1...2...4...5

4-kuyrukta bulunan hastalarýn bilgileri dosyada tutulmalýdýr.

5-istenildiginde kuyrukta bekleyenlerin bilgileri dosyadan okunmalýdýr.

*/
//-----bu dosyanýn adý uygulama.c main kodumuz burda yazýlýyor.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct_patient.h"
#include "file_opr.c"

#define MAX_SIZE 20
#define WARNING "malloc failed!"




Patient_Node* create_new_patient();
void insert_patient_to_list(Patient_Node *new_node,Patient_Node **head);
void delete_patient(char *name,Patient_Node **head);

//yeni hasta olusturma fonksiyonunda da öncelikle yeni bir node olusturuyoruz.
Patient_Node* create_new_patient(){
	Patient_Node *new_node;
	
//-----allocation memory for new patient
	new_node=(Patient_Node*)malloc(sizeof(Patient_Node));
	
	if(new_node==NULL){
		printf(WARNING);
		exit(1);
	}
	//kullanýcýdan verileri alýyoruz.
	//getting inputs from user
	printf("\nPlease enter patient informations...\n");
	printf("Name  :");
	scanf("%s",new_node->data.name);
	printf("surname:");
	scanf("%s",new_node->data.surname);
	printf("ID   :");
	scanf("%s",new_node->data.ID);
	printf("Age   :");
	scanf("%d",&new_node->data.age);
//-----asagýdaki printf'de patient'ýn önceliði varsa 1 degerini alýr eger onceliði yoksa 0 degerini alýr diyor.
	printf("if patient has a priorty enter 1 otherwise enter 0 for prior..\n");
	printf("prior :");
	scanf("%d",&new_node->data.prior);
	new_node->next=NULL;
//-----ve sonra yeni bir node olusturuyoruz.bu olusturdugumuz node insert_patient_to_list fonksiyonuna bi parametre olarak gidiyor yani
	return new_node;
	
} 
//this function is used for inserting new patient to list.
//-----eklemek istedigim zaman buraya geliyorum.yeni bir hasta eklemek istedigim zaman bu fonksiyonu kullanýyorum.

//-----þimdi new_node ve head parametremizi kullanarak þimdi bir ekleme yapýcaz.
void insert_patient_to_list(Patient_Node *new_node,Patient_Node **head){
//-----if head equals to NULL,new patient will be the head of list.
//-----þimdi bizim listemizde su anda bosken hiçbir head'imiz yok link list'in basýný ifade eden bir node'umuz yok.o zaman ben ne eklersem ekliyim bu benim listemin basý olucak.o yuzden head ifadem yani listenin basýný ifade eden degiskenim eger NULL ise direk priority'si var mý yok mu kontrol etmeden direk o hastayý listenin basý olarak esitliyorum.ve ekleme fonksiyonumdan geri donuyorum.
//-----bu arada en basta node'umuzun head'ini olusturuyoruz yukarýda ve bu head'i global bir degisken olarak degilde fonksiyonlarýmýza parametre olarak gönderiyoruz.mesela yukarýda patient_node'un head pointer'ýný olusturmusuz.ekleme fonksiyonumuzda adresiyle gönderiyoruz case 1'de.parametre olarak da case1'de create_new_patient()fonksiyonunu alýyor.
	
//-----liste tamamen bossa eklememizi asagýdaki gibi yaptýk.
		if((*head)==NULL){
			(*head)=new_node;
			return;
		}
//-----liste tamamen bos degilse yani bir head'imiz varsa nasýl ilerlicez
		Patient_Node *var_head=(*head);
		Patient_Node *last_prior=(*head);
		Patient_Node *temp;
		
//-----check the new patient priorty,has it high priorty.
//-----sonra kotrol ediyoruz bu yeni hastanýn prioritisini eger prioritisini 0 dan farklý derse zaten prioritimiz için öncelik yoksa 0 onceligi varsa da 1 degerini alýr.eger hasta olustururken patient'ýn önceligi var ise 1 degeri giricez.onceligi yok ise 0 degeri giricez.kullanýcýdan daha veriyi alirken.
//-----ondan sonra burda kontrol ediyoruz eger hastanýn priritisi var ise
		if(new_node->data.prior !=0){
			
//-----buraya geliyoruz ne diyor.yani bastan kontrol edicez listenin basýnda prioritisi olan bir hasta var mý varsa o benim ilk last_prioriti diye bir degiskenim var ya ona esit olucak eger ondan sonraki node da prioritisi 1 ise bu sefer last_prior'imi ikinciye esitlicem yani 1.indextte bulunan hastaya iþaretlemiþ olucam.bir sonrakininde prioritisi yuksek ise bu sefer 3.eleman benim prioritisi yuksek olan hastam olucak yani last priorim olucak çünkü onun ardýna ekleme yapýcam ya o yuzden listedeki en uctaký .bu iþlemde bunu yapýyorum.
//-----detect the last patient with high priorty.
//-----priority için önceliði yoksa 0 onceliði varsa da 1 degerini alýcak.
			while(var_head != NULL){
				if(var_head->data.prior !=0){
					last_prior=var_head;
				}
					var_head=var_head->next;
				
				
			}
			
			
			
			
			
			//yukarýdaki iþlemi yaptýktan sonra öncelikle sunu yapýyoruz.bakalým hala head yani listenin basýndaki ifade last prior mu yoksa degisti mi bu diye bunu kontrol ediyoruz.eger last_prior hala listenin basýndaki ifadeye esitse o zaman sunu kontrol ediyorum 
			//we set the initial last prior as head node.
			//check is the last prior still head of the still.
			if(last_prior==(*head)){
				
				
				//if head of least has not high priorty,new patient will be head of list.
				//listenin basýndaki elemanýn prioritisi var mý yok mu cunku biz initial olarka biz last_prior'u yukarýda head olarak iþaretledik.yani listede hiç prioritisi olan hasta yoksa bu hala head olarak kalmýs olucak listede e öyle olunca da eklememizi biz head'in sonrasýna yapýcak þekilde ayarlamýstýk.yani last prioritinin bi sonrasina ekleme yapýcaz.ve last prior head'e esitse ve head'in prioritisi yoksa o zaman orda bir karýsýklýk olucak.yani bir tane onceliksiz hasta sonra öncelikli hasta sonra önceliksiz hasta diye devam edicek sekilde bir sýkýntý yasýyabiliriz.bunu kontrol altýna almak için de bunu kontrol ediyoruz.last prior hala head'e esit mi eger head'e esitse napýcaz oncelikli hastayý ben yeni head yapýcaz ama eger head'e esit degilse last_prior o zaman elde ettiðim last_prior'un bir sonrakine ekleme yapýcaz.
			if((*head)->data.prior==0){
				//head'in degerini bir temprorary degiskende tutuyoruz.
				temp=(*head);
				//sonra yeni head'imiz new_node oluyor.yani yeni hastamýz öncelikli olan hastamýz sonra yeni nodun bi sonra iþaret ettiði node da temproray de tuttugumuz eski listenin basý olucak.eger tam tersi ise yani head'e esit degilse o zaman bir sonraki iþaret ettiði veriye yeni hastayý ekliycez. 
				(*head)=new_node;
				new_node->next=temp;
			}
			else{
				//else,new patient will be added after the last prior.
				//last prior'ýn iþaret ettiði bir sonraki ifadeyi temp te tutuyorum sonra last_prior'ýn bi sonra iþaret ettiði yere yeni hastamý ekliyorum sonra yeni hastanýn iþaret ettiði yere de bir onceki temp te tuttugum degeri eklemis oluyorum.
				temp=last_prior->next;
				last_prior->next=new_node;
				new_node->next=temp;
			}	
			
			}
			else{
				//burda da else durumu bu neyin else'i
				//eþit degilse yine burda da ekleme yapýcaz
				//else,new patient will be added after the last prior.
				temp=last_prior->next;
				last_prior->next=new_node;
				new_node->next=temp;
			}
		}
		//bu hasta prioritisi olmayan bir hasta ise o zaman napýcaz direk listenin son elemanýný bulucaz.asagýdaki while sayesinde   
		else{
			while(var_head->next!=NULL){
				var_head=var_head->next;
			}
			var_head->next=new_node;
		}

	
}
//hastalarý isimleri ile birlikte silicez.aslýnda tc numaralarýyla silmek daha iyi olurdu çunku birden fazla ahmet olabilir.
//parametre olarak hem ismi alýyo hem de listenin basýný alýcak haliyle çunku listede arama yapýcaz ismini buldugumuz hastayý silicez listeden.
void delete_patient(char *name,patient_Node **head){
	//su anda patient'in tuttugu veri null var_head'de bizim listemizin basýný isaret ediyor.
	//var_head null olana kadar biz listede arama yapýyoruz.
	//strcmp komutu eger 0 donerse iki stringin birbirine esit oldugunu ifade ediyor.
	//var head'in ismiyle var head'in iþaret ettigi data'nýn ismini ve bizim kullanýcýdan aldýgýmýz ismi compare ediyoruz.eger bu deger 0'a esitse fonksiyonun return'u bu hastayý bulduk demektir.sonra patient'i var_head'e eþitliyoruz.çünkü buldugumuz hastanýn bilgileri hepsi burda tutulmus.
	//sonra bu dongu bittigi zaman patient artýk arama yaptýgýmýz isimdeki hastanýn bilgilerini tutuyor.o zmaan napýcaz sunu kontrol ediyoruz.buldugumuz hasta listenin basýndaki hasta mý degil mi ona bakýyoruz.eger basýndaki hasta ise yeni head'imiz head'in bi sonra iþaret ettiði hasta olucak ama eger bas degil ise
	Patient_Node *patient=NULL,*var_head;
	var_head=(*head);
	while(var_head !=NULL){
		//if patient's name and entered name is equal,variable patient keeps patient that will delete.
		if(strcmp(var_head->data.name,name)==0)//0 means,two string is equal.
		patient = var_head;
		
		var_head=var_head->next;
	}
	//if patient is the head of list,new head will be the head->next.
	if(patient ==(*head)){
		(*head)=(*head)->next;//artýk head dedigimiz yer onceden headin gosterdigi yer
		
	}
	else{
		//patient'ýn null olup olmadýgýný kontrol ediyoruz çünkü hiç listede olmayan bir eleman da olabilir. eger oyleyse zaten listede bulunamadý diye print ediyoruz ve donuyoruz.eger boyle bir durum yoksa listede buluyoruz bu degiskeni ve hastayý napýyoruz o node'u aradan cýkartýyoruz yani var_head'in next'i o hastanýn nextinin nextine iþaret ediyor
		//if patient is NULL,there is no patient in list with entered name.
		if(patient==NULL){
			printf("\nCould not find the element with %s",name);
			return;
		}
		var_head=(*head);
		//finding patient in list.
		while(var_head->next !=patient){
			var_head=var_head->next;
		}
		//yani burda tekrar arama yapmamýzýný sebebi su patient'tan onceki aslýnda  bizim buldugumuz patient'ý býr onceki node'a set ediyoruz.var_head'in next'i patient olana kadar bu dongu calýsacak oldugu anda burdan cýkacak yani bu aslýnda wihle ' girmeyip silmek istedigim nodun bir onceki nodu aslýnda yani dolayýsýyla var_head'in iþaret ettigi bi sonraki iþaret ettirmek istedigim verinin yerine iþaret ettigi nodun bi sonra isaret ettiðini almýs olucam(31.29) 
		//when we delete the patient,previous node's next node will be the patient's next node.
		var_head->next=var_head->next->next;
		free(patient);
	}
}

//-----oncelikle main'de biz napýcaz kac tane iþlemimiz var.
//-----kullanýcý girebilicez.ya da hasta ekliycez kuyruga,
//-----ondan sonra ismiyle bu hastayý silebilicez.
//-----sonra ben her istedigimde dosyadan bu listeyi print edebilicem.
//-----3 tane ana iþlemimiz var.ekleme yapma çýkarma yapma ve 
//-----görüntüleme bunlar için bir dongu olusturmusuz.
//-----her seferinde kullanýcýdan eklemek istiyorsa 1-silmek istiyorsa
//----- 2-print etmek istiyosa da 3 verisini alarak okuyarak secimlerimizi bu sefer switch case yapýsý ile degerlendiriyoruz.
int main(){
	char name[MAX_SIZE];
	int choose=1;
	
//-----head node specify the head of list.
	Patient Node *head=NULL;
	
	while(choose>0){
		printf("\nFor entering new patient press 1..\n");
		printf("For deleting patient with name press 2..\n");
		printf("For reading list from the file press 3..\n");
		printf("For exit press 0..\n");
		printf("\nPlease enter your choice:");
		scanf("%d",&choose);
		case 1:
//-----eklemek istedigim zaman ben asagýdaki fonksiyonu çalýstýrýyormusum.
			insert_patient_to_list(create_new_patient(),&head);
			printListWithAllInformations(&head);
			break;
			
			case 2:
				printf("\nEnter patient name that want to delete:");
				scanf("%s",name);
				delete_patient(name,&head);
				printListWithAllInformations(&head);
				break;
				
				
					case 3:
						read_file();
						break;
	}
}
return 0;
//31.29
