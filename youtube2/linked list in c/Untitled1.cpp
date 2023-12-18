https://www.youtube.com/watch?v=nGSVg-NLLUo&ab_channel=Y%C3%BCcelAlkan

linked list

bagl� liste demektir.

dinamik boyutlu veri yap�s�d�r.program ak�s� i�erisinde linked list yap�s�n�n boyutu degisebilir.

linked list yap�s�nda her eleman,kendisinden sonraki eleman� i�aret eden bir veri i�erir.

linked list:birden fazla eleman� bi arada tutan veri yap�s�d�r.


linked list ve array farklar�:
	dizilerin boyutlar� sabittir ancak bagl� liste dinamik boyuta sahiptir.
	dizilerin boyutu program ak�s� i�erisinde degisemiyor.
	linked list'in boyutu program ak��� i�erisinde degisebilir.
	
	diziler tan�mlan�rken boyutlar� belirtilmelidir.ancak bagl� listede boyle bir durum soz konusu degildir.
	linked list yap�s�nda boyutunu belirtmek zorunda degilsiniz.
	
	diziye ait elemanlar bellekte ard�s�k olarak saklan�r.bagl� listenin elemanlar� ise bellekte farkl� konumlarda bulunabilirler.
	 
	dizilerde rastgele erisim vard�r.ancak bagl� listede s�ral� erisim vard�r.
	
	dizilerde silme ve elemanlar�n kayd�r�lmas� i�lemi zordur ancak bagl� listede daha kolayd�r.
	
	diziler ayn� t�re ait verileri saklarken bagl� listeler farkl� t�rlere ait verileri saklayabilirler.
	
	
linked list uygulamas� gercekle�tirilirken listenin bas�n� ve sonunu gosteren i�aret�iler kullan�l�r.
ekleme ve silme i�lemleri sonrasinda head ve tail guncellen�r.

listenin bas�n� gostermek i�in genelde head sonu i�in genelde tail kullan�l�r.

ekleme ve silme i�lemleri sonucunda head ve tail etkilenirse bu yap�lar� guncellememiz gerekiyor.

linked list bosken head ve tail null olur yani herhangi bir degeri gostermicek 
listede bir eleman varken head ve tail dedigimiz yap�lar o eleman� gostericek 	

listede birden fazla eleman varsa head dedigimiz yap� listenin bas�n� tail dedigimiz yap� ise listenin sonunu gostermis olucak 
bu sekilde linked list yap�s�n� istedigimiz kadar buyutup kucultme imkan�na sahibiz.



#include <stdio.h>
#include <stdlib.h>


//linked list yap�s�ndaki elemanlar i�in bir struct yap�s� tan�m�l�caz.
struct node{
	int data;
	struct node *next;
};

//HEAD & TA�L
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


