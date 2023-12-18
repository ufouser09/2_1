#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}NODE;

NODE *head=NULL;//yine mantýgýmýz ayný head global bir degisken bunu daha sonra degistircez.

NODE *create_node();
void insert_at_begin(int d);
void insert_at_end(int d);
void traverse();
void delete_from_begin();
void delete_from_end();
int main(){
	int data;
	
	int i=0;
	
	while(i!=6){
		
		printf("Enter choice\n1-Insert begin\n2-Insert end\n 3 -traverse\n");
		printf("4-Delete begin\n5-Delete end\n 6-Exit");
		scanf("%d",&i);
		
		if(i==1){
			printf("Enter data");
			scanf("%d",&data);
			insert_at_begin(data);
		}
		else if(i==2){
			printf("Enter data");
			scanf("%d",&data);
			insert_at_end(data);
		}
		else if(i==3){
			traverse();
		}
		else if(i==4){
			delete_from_begin();
		}
		else if(i==5){
			delete_from_end();
		}
	}
	head=NULL;
	free(head);
	
	
}

void delete_from_begin(){
//Bastan bir elemaný silmek ne demek:
//head bir elemaný iþaret ediyor ve ben bu head'in gösterdigi elemaný silicegim demektir.
//head'in gösterdigi elemaný silerken once suna bakýcam head acaba bir yeri gösteriyor mu yani null mu degil mi ona bakarým.
//eger null degilse o zaman da su durum ortaya çýkar.
//listenin 2. veya 3.elemanlarý olabilir demek olur.
//ben linked list'i gezmek için node türünde temprorary degisken olusturuyorum.
	
	NODE *tmp;//þimdilik bu bos duracak.
	
	int n;//hangi elemaný sildigimi göstermek için bir tane degisken tutalým,yani su deger silindi gibisinden.
	
	if(head==NULL){//eger head dugumumuz eþit null ise linked listimiz bostur.
		printf("list is empty");
		return;//void de return kullanýlmaz degil voidte bir degisken return edilmez.
		//void pointer olursa return edilir ona sonraki konularda gelicez.
	}
	n=head->data;//head'in gösterdiði yerdeki datayý al dersem bu bana data'yý vericektir.
	
	tmp=head->next;//burda tmp degiskenine head'in next'ini atýyorum head'in nexti ne demek yani head hangi dugumu gosteriyor bu gosterdigi dugumu alýyorum yani ve bu dugumu tmp ye atýyorum.
	
	
	free(head);//bu fonksiyonda yaptýgýmýz iþ bastan bir eleman silmek.en bastaki dugumumuze de head diyoruz.head'in gösterdiði yerdeki düðümü serbest býrakýyoruz.
	//head'in gösterdiði yerin next'ini tutuyoruz bi yerde ama.
	
	head=tmp;//ilk basta head'in gosterdiði ikinci dugumumuz artýk bizim head'imiz oldu.head'imizi guncelledil burda.
	
	printf("%d was deleted",n);//silinen elemaný boyle gösteriyoruz.silinen eleman da n 'dir.
	
}

void delete_from_end(){
	//listede sondan silerken þuna dikkat etmemiz gerekir.
	//listede son elemaný silerken mesela sondan bir önceki elemanýn son eleman olarak iþaretlenmesi için
	//head'den itibaren arama yaparken bir yedek degisken kullanýcam.bu yedek degisken sürekli bir önceki,
	//yani birisi bir sonrakine giderken birisi bir önceki düðümü tutacak ta ki next null'u görene kadar null'u gördü mü
	//bu arama iþlemi de bitecek.ben de 2 tane pointer olucak birisi arama yaptýgým pointer birisi de bir öncekinin pointer'ý olucak 
	//çünkü bu diziler tek yönlü tek yönlü dizi oldugu için böyle bir þeye ihtiyacým var.arama bittiði zaman son elemaný free edicez 
	//ve sondan bir önceki elemaným ise null'u göstericek ve bu iþlemi tamamlýycaz.
	//bir de silme iþlemini sondan yaparken suna dikkat edicez bir tane elemanýmýz varsa o da head'imizdir.
	//çünkü listede bir eleman varsa 
	//burda yine node türünde 2 tane deðiþkene ihtiyacýmýz var.
	//yani sondan eleman silerken 2 tane þeye dikkat edicez birisi head'imiz null mu ikincisi headimizin gosterdigi dugum null mu.
	
	NODE *tmp,*u;
	
	int n;//hangi elemaný sildigimizi göstermek için yine n degiskenini kullanýyoruz.
	
	if(head==NULL){
		printf("List is empty");
		return;
	}
	if(head->next==NULL){//head'in next'inin null olmasý durumu var
		n=head->data;//n'in hangi datayý sakladýgýný alalým.
		free(head);
		head=NULL;
		printf("%d was deleted",n);
		return;
	}
	//eger yukarýdaki de degilse birden fazla eleman varsa yani döngüyle arama yapýcaz.
	tmp=head;//head'i kaybetmemek için boyle bir þey yaptýk.
	while(tmp->next!=NULL){
		u=tmp;
		tmp=tmp->next;//tmp'yi güncelledik.
		
	}
	n=tmp->data;//hangi veriyi sildigimiz görmek adýna
	u->next=NULL;
	free(tmp);//ilgili düðümü bellekten temizlemek için bunu dicez.
	printf("%d was deleted",n);
	
}
void insert_at_begin(int d){
	NODE *tmp=create_node();
	//tmp->data=d;
	
	if(head==NULL){
		head=tmp;
		head->next=NULL;
		head->data=d;//instead of //tmp->data=d;
	}
	else{
		tmp->next=head;
		head=tmp;
		head->data=d;//inplage of//tmp->data=d;
	}
	
}
