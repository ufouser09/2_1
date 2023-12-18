//-----bu C dosyamýzýný adý struct_patient.h'dir.

//Creating Patient Structure
//-----hastalarý belirttigimiz bir dosya 
typedef struct{
	char name[20],surname[30];
	char ID[12];
	int age;
	int prior;
}Patient;

//-----bu hastalarý bir listenin içinde tutmak istiyoruz ya 
//-----o listenin bir tane elemanýný belirticek 
//-----baska bir yapýya daha ihtiyacýmýz var.bu yapýda da nolucak 
//-----hem hasta verisini tutan bir yapý olucak node'umuz.
//-----hem de bir sonraki ifadeyi göstericek pointer iþaretcimize ihtiyacýmýz var.
//-----bir Patient_Node iþaretcisine ihtiyacýmýz var.

//Creating Patient_Node structure
typedef struct Patient_Node{
	Patient data;
	struct Patient_Node *next;
	
}Patient_Node;
