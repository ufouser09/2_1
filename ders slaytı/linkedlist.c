Array structure is not efficient enough because:
//Dizi yap�s� yeterince verimli de�ildir ��nk�:

They cannot be resized automatically	
//Otomatik olarak yeniden boyutland�r�lamazlar

You need to allocate memory for worst-case, which is a waste of memory
//Haf�za kayb� olan en k�t� durum i�in haf�za ay�rman�z gerekir.

Insertions are hard
//Eklemeler zordur

You need to shift elements
//��eleri kayd�rman�z gerekiyor

A more efficient data structure is a Linked list:
//Daha verimli bir veri yap�s� Ba�lant�l� listedir:
		
A linked list is a chain of structures that are linked one to another,like sausages.	
//Ba�lant�l� liste, sosisler gibi birbirine ba�l� bir yap� zinciridir.

In the simplest linked-list scheme, each structure contains an extra member which is a pointer to the next structure in the list.
//En basit ba�lant�l� liste �emas�nda, her yap�, listedeki bir sonraki yap�ya i�aret eden fazladan bir �ye i�erir.

You will learn about lists and other data structures in the next term in the namesake course
//Listeleri ve di�er veri yap�lar�n� sonraki d�nemde ada��l�k kursunda ��reneceksiniz.

We will use the Employee struct as the data element AND the node.
//�al��an yap�s�n� veri ��esi VE d���m olarak kullanaca��z.

Advantage: This will keep things a little bit simpler.
//Avantaj: Bu, i�leri biraz daha kolayla�t�racakt�r.

Definition:
//Tan�m:
		
		
#include <stdio.h>
		typedef struct Employee {
			char name[20], surname [20];
			int ID; 
			float salary; 
			struct Employee *next;
		} EMPLOYEE;
		
		EMPLOYEE *head;


We can also define our node structure as follows
//D���m yap�m�z� da a�a��daki gibi tan�mlayabiliriz.

Advantage: This will keep the struct related with the problem domain separate from the struct related with data representation.
//Avantaj: Bu, problem alan�yla ilgili yap�y�, veri sunumuyla ilgili yap�dan ayr� tutacakt�r.

Left to students as an exercise
//Al��t�rma olarak ��rencilere b�rak�ld�	

#include <stdio.h>
			typedef struct {
				char name[20], surname [20];
				int ID; 
				float salary; 
			} EMPLOYEE;
			
			typedef struct emp_node {
				EMPLOYEE data;
				struct emp_node *next;
			} EMP_NODE;
			
			EMP_NODE *head;
	
	
Printing the information of an employee and the entire list:
//Bir �al��an�n bilgilerini ve t�m listeyi yazd�rma:
			
			
	void printElementP( EMPLOYEE *emp ) {
		printf("Employee %d %s has a salary of %f\n",emp->ID, emp->name, emp->salary );
		
	}
	void printList( ) {
		int j; EMPLOYEE *p;
		for(j=0, p=head; p != NULL; p=p->next, j++)
		printf("%d-th person: %d\t%s\t%f\n",j+1, p->ID, p->name, p->salary);

	}

We will need functions to allocate memory for an employee,creating an employee, �
//Bir �al��an i�in bellek ay�rmak, bir �al��an yaratmak i�in fonksiyonlara ihtiyac�m�z olacak �



				EMPLOYEE* create_list_element( ) {
				
				EMPLOYEE *emp; int i; float s;
				
				emp = (EMPLOYEE*) malloc( sizeof( EMPLOYEE ) );
				
				if( emp == NULL ) {
				
				printf("create_employee: out of memory."); 
				exit(1);
				}
				printf("Enter name of the person: "); 
				scanf("%s", emp->name);
				//can�t get non-pointer struct fields directly in some platforms
				printf("Enter ID of the person: ");
				scanf("%d", &i);
				emp->ID = i;
				
				printf("Enter salary of the person: ");
				scanf("%f", &s);
				
				emp->salary = s;
				emp->next=NULL; 
				return emp;
}


� and adding her/him to the list.
//� ve onu listeye eklemek.

The create_list_element() function allocates memory,but it doesn't link the element to the list.
For this, we need an additional function, add_element():
//create_list_element() i�levi belle�i ay�r�r, ancak ��eyi listeye ba�lamaz.
//Bunun i�in ek bir i�leve ihtiyac�m�z var, add_element():
		
� code will continue in the next slide
//� kod bir sonraki slaytta devam edecek



void add_element(EMPLOYEE *e){
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



� We may need to fire an employee (deleting a node):
/* To delete an element in a linked list,you need to find the element before the one you are deleting so that you can bond the list back together after removing one of the links.
Ba�lant�l� bir listedeki bir ��eyi silmek i�in, sildi�iniz ��eden �nceki ��eyi bulman�z gerekir, b�ylece ba�lant�lardan birini kald�rd�ktan sonra listeyi tekrar birle�tirebilirsiniz.


You also need to use the free() func,to free up the memory used by the deleted element.
Ayr�ca, silinen ��e taraf�ndan kullan�lan belle�i bo�altmak i�in free() i�levini kullanman�z gerekir.

 */

			void delete_element(EMPLOYEE *goner){
		EMPLOYEE *p;
		
		if(goner == head)
		
		head=goner->next;
		
		else // find element preceding the one to be deleted:
		
		for(p=head; (p!=NULL) && (p->next != goner);
		p=p->next); 
		
		if(p == NULL){
		
		printf("delete_element(): could not find the element \n"); return;
		
		}
		p->next=p->next->next;
		free(goner);
		}



� We may need to search an employee:
/* Finding an Element in the Linked List:
Ba�lant�l� Listede Bir ��e Bulma:

There is no easy way to create a general-purpose find() function because you usually search for an element based on one of its data fields(e.g. person's name), which depends on the structure being used.
Genel ama�l� bir find() i�levi olu�turman�n kolay bir yolu yoktur, ��nk� bir ��eyi genellikle kullan�lan yap�ya ba�l� olan veri alanlar�ndan birine (�rne�in, ki�inin ad�) g�re arars�n�z.

To write a general-purpose find() function, you can use function pointers(will be studied later).
Genel ama�l� bir find() i�levi yazmak i�in i�lev i�aret�ilerini kullanabilirsiniz(daha sonra incelenecektir).

The following function, based on the personalstat structure,searches for an element, whose name field matches with the given argument.
Personalstat yap�s�n� temel alan a�a��daki i�lev, ad alan� verilen ba��ms�z de�i�kenle e�le�en bir ��eyi arar.
*/

EMPLOYEE* find(char *name) {
EMPLOYEE *p;
for(p=head; p!= NULL; p=p->next)
if(strcmp(p->name, name) == 0) // returns 0, if 2 strings are same
return p;
return NULL;
}





We may need to put a new employee between two existing people (inserting a node in between) :
//Mevcut iki ki�inin aras�na yeni bir �al��an koymam�z gerekebilir (araya bir d���m ekleyerek):
	
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



� Let�s put them all together and make a demonstration:
//Hepsini bir araya getirelim ve bir g�steri yapal�m:
	int main(){
	EMPLOYEE *p,*q;
	int val, j;
	for(j=0; j<2; j++)
	add_element( create_list_element());
	for(j=0, p=head; p != NULL; p=p->next, j++)
	//for(p=head; p != NULL; p=p->next)
	{
	printf("%d-th person: ",(j+1)); printElementP(p);
	}







� Demonstration cont�d:
// CREATE A NEW ELEMENT AND INSERT IT IN
//YEN� B�R ��E OLU�TURUN VE ONU EKLEY�N

// BETWEEN THE 1st AND 2nd ELEMENTS IN THE LIST:
//L�STEDEK� 1. VE 2. ELEMENTLER ARASINDA:

p=create_list_element();
q=head; //to keep the first element, head::ilk eleman� tutmak i�in, ba�
insert_after(p, q); //and we insert p, after q::ve q'dan sonra p'yi ekleriz:
printList( );
return 0;
}




