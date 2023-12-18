/*

NESTED STRUCTURE

You can define a structure within(i�inde) another, creating data hierarchies.
//Veri hiyerar�ileri olu�turarak bir yap�y� ba�ka bir yap� i�inde tan�mlayabilirsiniz.

They can also be used separately, therefore define separately and nest them as needed. 
//Ayr� olarak da kullan�labilirler, bu nedenle ayr� ayr� tan�mlay�n ve gerekti�inde i� i�e ge�irin.

Adding the enlisting date of an employee:
//Bir �al��an�n kay�t tarihini ekleme:

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
//Daha sonra �unlar� yazabilirsiniz:

yunus.enlisted.year = 2008;



********************************************************
Passing structures as function parameters

� There are two ways to pass structures as arguments: 
//� Yap�lar� ba��ms�z de�i�ken olarak ge�irmenin iki yolu vard�r:

pass the structure itself (called pass by value)
//yap�n�n kendisini iletin (de�ere g�re ge�i� olarak adland�r�l�r)

EMPLOYEE emp;
printReport(emp);

pass a pointer to the structure (called pass by reference)
//yap�ya bir i�aret�i iletin (referansa g�re ge�i� olarak adland�r�l�r)

EMPLOYEE emp;
increaseSalary(&emp);

� Passing by reference is faster and more efficient
//Referansa g�re ge�i� daha h�zl� ve daha verimlidir

 Depending on your choice, declare the argument of the 
function as either a structure or a pointer to a structure
//Se�iminize ba�l� olarak, i�levin arg�man�n� bir yap� veya bir yap�ya i�aret�i olarak bildirin.

Then use . or -> in the body of the function
//Sonra kullan . veya -> i�levin g�vdesinde

The pointer points to an entire structure, not to its first field.
//��aret�i, ilk alan�na de�il, t�m yap�ya i�aret eder.






******************************************************
Structure example: Linked List Implementation


Array structure is not efficient enough because:
Dizi yap�s� yeterince verimli de�ildir ��nk�:

They cannot be resized automatically
Otomatik olarak yeniden boyutland�r�lamazlar

You need to allocate memory for worst-case, which is a waste of memory
//Haf�za kayb� olan en k�t� durum i�in haf�za ay�rman�z gerekir.

Insertions are hard
//Eklemeler zordur

� You need to shift elements
� ��eleri de�i�tirmeniz gerekiyor

� A more efficient data structure is a Linked list:
� Daha verimli bir veri yap�s� Ba�lant�l� listedir:

A linked list is a chain of structures that are linked one to another, 
like sausages. 
//Ba�lant�l� liste, sosis gibi birbirine ba�l� bir yap� zinciridir.

� In the simplest linked-list scheme, each structure contains an 
extra member which is a pointer to the next structure in the list.
//� En basit ba�lant�l� liste �emas�nda, her yap�, listedeki bir sonraki yap�ya i�aret eden fazladan bir �ye i�erir.

You will learn about lists and other data structures in the 
next term in the namesake course
//Listeler ve di�er veri yap�lar� hakk�nda bilgi edineceksiniz.
ada�� kursunda bir sonraki d�nem





******************************************
Structure example: Linked List Implementation


We will use the Employee struct as the data element AND the 
node
�al��an yap�s�n� veri ��esi VE d���m olarak kullanaca��z

Advantage: This will keep things a little bit simpler
//Avantaj: Bu, i�leri biraz daha basit tutacakt�r.

� Definition:

#include <stdio.h>
typedef struct Employee {
	char name[20], surname [20];
	int ID; 
	float salary; 
	struct Employee *next;
} EMPLOYEE;

EMPLOYEE *head;

