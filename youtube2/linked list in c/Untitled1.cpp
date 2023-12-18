https://www.youtube.com/watch?v=nGSVg-NLLUo&ab_channel=Y%C3%BCcelAlkan

linked list

baglý liste demektir.

dinamik boyutlu veri yapýsýdýr.program akýsý içerisinde linked list yapýsýnýn boyutu degisebilir.

linked list yapýsýnda her eleman,kendisinden sonraki elemaný iþaret eden bir veri içerir.

linked list:birden fazla elemaný bi arada tutan veri yapýsýdýr.


linked list ve array farklarý:
	dizilerin boyutlarý sabittir ancak baglý liste dinamik boyuta sahiptir.
	dizilerin boyutu program akýsý içerisinde degisemiyor.
	linked list'in boyutu program akýþý içerisinde degisebilir.
	
	diziler tanýmlanýrken boyutlarý belirtilmelidir.ancak baglý listede boyle bir durum soz konusu degildir.
	linked list yapýsýnda boyutunu belirtmek zorunda degilsiniz.
	
	diziye ait elemanlar bellekte ardýsýk olarak saklanýr.baglý listenin elemanlarý ise bellekte farklý konumlarda bulunabilirler.
	 
	dizilerde rastgele erisim vardýr.ancak baglý listede sýralý erisim vardýr.
	
	dizilerde silme ve elemanlarýn kaydýrýlmasý iþlemi zordur ancak baglý listede daha kolaydýr.
	
	diziler ayný türe ait verileri saklarken baglý listeler farklý türlere ait verileri saklayabilirler.
	
	
linked list uygulamasý gercekleþtirilirken listenin basýný ve sonunu gosteren iþaretçiler kullanýlýr.
ekleme ve silme iþlemleri sonrasinda head ve tail guncellenýr.

listenin basýný gostermek için genelde head sonu için genelde tail kullanýlýr.

ekleme ve silme iþlemleri sonucunda head ve tail etkilenirse bu yapýlarý guncellememiz gerekiyor.

linked list bosken head ve tail null olur yani herhangi bir degeri gostermicek 
listede bir eleman varken head ve tail dedigimiz yapýlar o elemaný gostericek 	

listede birden fazla eleman varsa head dedigimiz yapý listenin basýný tail dedigimiz yapý ise listenin sonunu gostermis olucak 
bu sekilde linked list yapýsýný istedigimiz kadar buyutup kucultme imkanýna sahibiz.



#include <stdio.h>
#include <stdlib.h>


//linked list yapýsýndaki elemanlar için bir struct yapýsý tanýmýlýcaz.
struct node{
	int data;
	struct node *next;
};

//HEAD & TAÝL
struct node *head=NULL;
struct node *tail=NULL;

int addNode(int data){
	
	//linked list is empty
	if(head==NULL){
		struct node *new = (struct node*)malloc(sizeof(struct node));
		new->data=data;
		new->next=NULL;
		
		head = tail = new;
	}
	//linked list's not empty
	else{
		struct node *new =(struct node *)malloc(sizeof(struct node));
		new->data = data;
		new->next = NULL;
		
		tail->next =new;
		
		tail =new;
	}
	
	
}

//Add node to head
int addNodeHead(int data){
	//linked list is empty
	if(head==NULL){
		struct node *new =(struct node *)malloc(sizeof(struct node));
		new->data=data;
		new->next=NULL;
		
		head = tail = new;
	}
	//linked list's not empty
	else{
		struct node *new =(struct node *)malloc(sizeof(struct node));
		new->data=data;
		//new->next=NULL;
		
		new->next=head;
		
		head=new;
	}
}
//print
int print(){
	printf("Linked list: ");
	struct node *index = head;
	
	while(index!=NULL){
		printf("%d - ",index->data);
		index=index->next;
	}
}
int delete(int data){
	struct node *prev =NULL;
	struct node index =head;
	
	//linked list is empty
	if(head==NULL){
		printf("linked list is empty \n");
		return 1;
	}
	//head
	if(head->data==data){
		struct node *t=head;
		head = head->next;
		free(t);
		return 1;
	}
	
	while(index!=NULL && index->data!=data){
		prev = index;
		index = index->next;
		
	}
	if(index==NULL){
		printf("data not found. \n");
		return 1;
	}
	prev->next = index->next;
	
	return 1;
	
}


int main(){
	
	addNode(10);
	addNode(14);
	addNode(16);
	addNode(19);
	
	addNodeHead(15);
	addNodeHead(7);
	
	addNode(30);
	
	print();
}
//34.01


