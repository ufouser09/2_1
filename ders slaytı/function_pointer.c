We can use some functions as arguments to other functions 
through the function pointers
Bazý iþlevleri, iþlev iþaretçileri aracýlýðýyla diðer iþlevlere argüman olarak kullanabiliriz.

• This possibility opens new doors in terms of flexibility for 
coding.
• Bu olasýlýk, kodlama esnekliði açýsýndan yeni kapýlar açar.

Definition
Taným

int (*pf) (); // pf is a pointer to a function returning an int.

• The () around *pf are necessary for correct grouping. Because: 

• int *pf(); // this is a function allusion returning an int pointer

Assignments to function pointers:
Ýþlev iþaretçilerine atamalar:
	
	extern int f1();
int main( ) {
int (*pf) (); // pf is a pointer to a function returning an int.
pf=f1; // assign the address of f1 to pf
pf=f1(); // ILLEGAL, f1 returns an int, but pf is a pointer
pf=&f1(); /* ILLEGAL, cannot take the address of a function 
result */
pf=&f1; /* ILLEGAL but compiler dependent:
&f1 is a pointer to a pointer, but pf 
is a pointer to an int */
}




Return types:
extern int if1(), if2(), (*pif)();
extern float ff1(), (*pff)();
extern char cf1(), (*pcf)();
int main( ) {
pif = if1; // Legal: Types match
pif = cf1; // ILLEGAL: Type mismatch
pff = if2; // ILLEGAL: Type mismatch
pcf = cf1; // Legal: Types match
if1 = if2; // ILLEGAL: Assign to a constant
}



• Example function call via a function pointer:
#include <stdio.h>
extern int f1(int); //could be defined externally but we have coded it below
int main() {
int n;
int (*pf) ();
int answer;
printf("Bir sayi giriniz: "); scanf("%d",&n);
pf=f1;
answer=(*pf)(n); // calls f1() with argument a => f1(a)
printf("%d", answer);
return 0;
}
int f1( int a ) {
return a+1;
}

