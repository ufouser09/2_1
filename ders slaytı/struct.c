/*

NESTED STRUCTURE

You can define a structure within(içinde) another, creating data hierarchies.
//Veri hiyerarþileri oluþturarak bir yapýyý baþka bir yapý içinde tanýmlayabilirsiniz.

They can also be used separately, therefore define separately and nest them as needed. 
//Ayrý olarak da kullanýlabilirler, bu nedenle ayrý ayrý tanýmlayýn ve gerektiðinde iç içe geçirin.

Adding the enlisting date of an employee:
//Bir çalýþanýn kayýt tarihini ekleme:

typedef struct {
	short day, month;
	int year; 
} DATE ;
typedef struct {
	char name[20], surname [20];
	int ID; 
	float salary;
	DATE enlisted; 
} EMPLOYEE ;

 Later, you can write:
//Daha sonra þunlarý yazabilirsiniz:

yunus.enlisted.year = 2008;



********************************************************
Passing structures as function parameters

• There are two ways to pass structures as arguments: 
//• Yapýlarý baðýmsýz deðiþken olarak geçirmenin iki yolu vardýr:

pass the structure itself (called pass by value)
//yapýnýn kendisini iletin (deðere göre geçiþ olarak adlandýrýlýr)

EMPLOYEE emp;
printReport(emp);

pass a pointer to the structure (called pass by reference)
//yapýya bir iþaretçi iletin (referansa göre geçiþ olarak adlandýrýlýr)

EMPLOYEE emp;
increaseSalary(&emp);

• Passing by reference is faster and more efficient
//Referansa göre geçiþ daha hýzlý ve daha verimlidir

 Depending on your choice, declare the argument of the 
function as either a structure or a pointer to a structure
//Seçiminize baðlý olarak, iþlevin argümanýný bir yapý veya bir yapýya iþaretçi olarak bildirin.

Then use . or -> in the body of the function
//Sonra kullan . veya -> iþlevin gövdesinde

The pointer points to an entire structure, not to its first field.
//Ýþaretçi, ilk alanýna deðil, tüm yapýya iþaret eder.






******************************************************
Structure example: Linked List Implementation


Array structure is not efficient enough because:
Dizi yapýsý yeterince verimli deðildir çünkü:

They cannot be resized automatically
Otomatik olarak yeniden boyutlandýrýlamazlar

You need to allocate memory for worst-case, which is a waste of memory
//Hafýza kaybý olan en kötü durum için hafýza ayýrmanýz gerekir.

Insertions are hard
//Eklemeler zordur

• You need to shift elements
• Öðeleri deðiþtirmeniz gerekiyor

• A more efficient data structure is a Linked list:
• Daha verimli bir veri yapýsý Baðlantýlý listedir:

A linked list is a chain of structures that are linked one to another, 
like sausages. 
//Baðlantýlý liste, sosis gibi birbirine baðlý bir yapý zinciridir.

• In the simplest linked-list scheme, each structure contains an 
extra member which is a pointer to the next structure in the list.
//• En basit baðlantýlý liste þemasýnda, her yapý, listedeki bir sonraki yapýya iþaret eden fazladan bir üye içerir.

You will learn about lists and other data structures in the 
next term in the namesake course
//Listeler ve diðer veri yapýlarý hakkýnda bilgi edineceksiniz.
adaþý kursunda bir sonraki dönem





******************************************
Structure example: Linked List Implementation


We will use the Employee struct as the data element AND the 
node
Çalýþan yapýsýný veri öðesi VE düðüm olarak kullanacaðýz

Advantage: This will keep things a little bit simpler
//Avantaj: Bu, iþleri biraz daha basit tutacaktýr.

• Definition:

#include <stdio.h>
typedef struct Employee {
	char name[20], surname [20];
	int ID; 
	float salary; 
	struct Employee *next;
} EMPLOYEE;

EMPLOYEE *head;

