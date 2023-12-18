Array structure is not efficient enough because:
//Dizi yapýsý yeterince verimli deðildir çünkü:

They cannot be resized automatically	
//Otomatik olarak yeniden boyutlandýrýlamazlar

You need to allocate memory for worst-case, which is a waste of memory
//Hafýza kaybý olan en kötü durum için hafýza ayýrmanýz gerekir.

Insertions are hard
//Eklemeler zordur

You need to shift elements
//Öðeleri kaydýrmanýz gerekiyor

A more efficient data structure is a Linked list:
//Daha verimli bir veri yapýsý Baðlantýlý listedir:
		
A linked list is a chain of structures that are linked one to another,like sausages.	
//Baðlantýlý liste, sosisler gibi birbirine baðlý bir yapý zinciridir.

In the simplest linked-list scheme, each structure contains an extra member which is a pointer to the next structure in the list.
//En basit baðlantýlý liste þemasýnda, her yapý, listedeki bir sonraki yapýya iþaret eden fazladan bir üye içerir.

You will learn about lists and other data structures in the next term in the namesake course
//Listeleri ve diðer veri yapýlarýný sonraki dönemde adaþýlýk kursunda öðreneceksiniz.

We will use the Employee struct as the data element AND the node.
//Çalýþan yapýsýný veri öðesi VE düðüm olarak kullanacaðýz.

Advantage: This will keep things a little bit simpler.
//Avantaj: Bu, iþleri biraz daha kolaylaþtýracaktýr.

Definition:
//Taným:
		
		
#include <stdio.h>
		typedef struct Employee {
			char name[20], surname [20];
			int ID; 
			float salary; 
			struct Employee *next;
		} EMPLOYEE;
		
		EMPLOYEE *head;


We can also define our node structure as follows
//Düðüm yapýmýzý da aþaðýdaki gibi tanýmlayabiliriz.

Advantage: This will keep the struct related with the problem domain separate from the struct related with data representation.
//Avantaj: Bu, problem alanýyla ilgili yapýyý, veri sunumuyla ilgili yapýdan ayrý tutacaktýr.

Left to students as an exercise
//Alýþtýrma olarak öðrencilere býrakýldý	

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
//Bir çalýþanýn bilgilerini ve tüm listeyi yazdýrma:
			
			
	void printElementP( EMPLOYEE *emp ) {
		printf("Employee %d %s has a salary of %f\n",emp->ID, emp->name, emp->salary );
		
	}
	void printList( ) {
		int j; EMPLOYEE *p;
		for(j=0, p=head; p != NULL; p=p->next, j++)
		printf("%d-th person: %d\t%s\t%f\n",j+1, p->ID, p->name, p->salary);

	}

We will need functions to allocate memory for an employee,creating an employee, …
//Bir çalýþan için bellek ayýrmak, bir çalýþan yaratmak için fonksiyonlara ihtiyacýmýz olacak …



				EMPLOYEE* create_list_element( ) {
				
				EMPLOYEE *emp; int i; float s;
				
				emp = (EMPLOYEE*) malloc( sizeof( EMPLOYEE ) );
				
				if( emp == NULL ) {
				
				printf("create_employee: out of memory."); 
				exit(1);
				}
				printf("Enter name of the person: "); 
				scanf("%s", emp->name);
				//can’t get non-pointer struct fields directly in some platforms
				printf("Enter ID of the person: ");
				scanf("%d", &i);
				emp->ID = i;
				
				printf("Enter salary of the person: ");
				scanf("%f", &s);
				
				emp->salary = s;
				emp->next=NULL; 
				return emp;
}


… and adding her/him to the list.
//… ve onu listeye eklemek.

The create_list_element() function allocates memory,but it doesn't link the element to the list.
For this, we need an additional function, add_element():
//create_list_element() iþlevi belleði ayýrýr, ancak öðeyi listeye baðlamaz.
//Bunun için ek bir iþleve ihtiyacýmýz var, add_element():
		
… code will continue in the next slide
//… kod bir sonraki slaytta devam edecek



void add_element(EMPLOYEE *e){
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



• We may need to fire an employee (deleting a node):
/* To delete an element in a linked list,you need to find the element before the one you are deleting so that you can bond the list back together after removing one of the links.
Baðlantýlý bir listedeki bir öðeyi silmek için, sildiðiniz öðeden önceki öðeyi bulmanýz gerekir, böylece baðlantýlardan birini kaldýrdýktan sonra listeyi tekrar birleþtirebilirsiniz.


You also need to use the free() func,to free up the memory used by the deleted element.
Ayrýca, silinen öðe tarafýndan kullanýlan belleði boþaltmak için free() iþlevini kullanmanýz gerekir.

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



• We may need to search an employee:
/* Finding an Element in the Linked List:
Baðlantýlý Listede Bir Öðe Bulma:

There is no easy way to create a general-purpose find() function because you usually search for an element based on one of its data fields(e.g. person's name), which depends on the structure being used.
Genel amaçlý bir find() iþlevi oluþturmanýn kolay bir yolu yoktur, çünkü bir öðeyi genellikle kullanýlan yapýya baðlý olan veri alanlarýndan birine (örneðin, kiþinin adý) göre ararsýnýz.

To write a general-purpose find() function, you can use function pointers(will be studied later).
Genel amaçlý bir find() iþlevi yazmak için iþlev iþaretçilerini kullanabilirsiniz(daha sonra incelenecektir).

The following function, based on the personalstat structure,searches for an element, whose name field matches with the given argument.
Personalstat yapýsýný temel alan aþaðýdaki iþlev, ad alaný verilen baðýmsýz deðiþkenle eþleþen bir öðeyi arar.
*/

EMPLOYEE* find(char *name) {
EMPLOYEE *p;
for(p=head; p!= NULL; p=p->next)
if(strcmp(p->name, name) == 0) // returns 0, if 2 strings are same
return p;
return NULL;
}





We may need to put a new employee between two existing people (inserting a node in between) :
//Mevcut iki kiþinin arasýna yeni bir çalýþan koymamýz gerekebilir (araya bir düðüm ekleyerek):
	
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



• Let’s put them all together and make a demonstration:
//Hepsini bir araya getirelim ve bir gösteri yapalým:
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







• Demonstration cont’d:
// CREATE A NEW ELEMENT AND INSERT IT IN
//YENÝ BÝR ÖÐE OLUÞTURUN VE ONU EKLEYÝN

// BETWEEN THE 1st AND 2nd ELEMENTS IN THE LIST:
//LÝSTEDEKÝ 1. VE 2. ELEMENTLER ARASINDA:

p=create_list_element();
q=head; //to keep the first element, head::ilk elemaný tutmak için, baþ
insert_after(p, q); //and we insert p, after q::ve q'dan sonra p'yi ekleriz:
printList( );
return 0;
}




