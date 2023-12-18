#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Empoloyee{
	char name[21];
	char surname[21];
	char id[12];
	struct Employee *next;
}EMPLOYEE;


int addRecord(EMPLOYEE **head);
int removeRecord(EMPLOYEE **head);
void printRecords(EMPLOYEE *head,void (*fptr)(EMPLOYEE *));
void printNameFirst(EMPLOYEE *employee);
void printSurNameFirst(EMPLOYEE *employee);
void printIdFirst(EMPLOYEE *employee);

int main(){
	EMPLOYEE *head=NULL;

	int choice=0;

	while(choice !=3){

		printf("1.Add record.\n2.Remove record.\n3.Exit\n");
		scanf("%d",&choice);

		switch(choice){

			case 1:addRecord(&head);
			printRecords(head,printIdFirst);
			break;
			
			case 2:removeRecord(&head);
			printRecords(head,printIdFirst);
			break;

		}
		
	}
}
int addRecord(EMPLOYEE **headPP){
	
	EMPLOYEE *employee;
	
	employee=(EMPLOYEE*)malloc(sizeof(EMPLOYEE));
	
	printf("Enter name,surname and id.");
	scanf("%s %s %s",&employee->name,&employee->surname,&employee.id);
	
	employee->next=*headPP;
	
	*headPP=employee;
}
int removeRecord(EMPLOYEE **headPP){
	printf("Enter the id of the employee to be removed.");
	char id[12];
	scanf("%s",id);
	
	

 EMPLOYEE *current=*headPP;
 EMPLOYEE *previous=NULL;
 int found=0;
 while(current !=NULL && !found){
 	if(strcmp(current->id,id)==0){
 		found=1;
 		if(previous==NULL){//head is removed
 			*headPP=current->next;
		 }else{
		 	previous->next=current->next;
		 }
		 free(current);
		 
	 }else{
	 	previous=current;
	 	current=current->next;
	 }
 }
}






void printRecords(EMPLOYEE *head,void (*fptr)(EMPLOYEE *)){
	EMPLOYEE *current=head;
	while(current != NULL){
		fptr(current);
		current=current->next;
	}
}
void printNameFirst(EMPLOYEE *employee){
	printf("%s %s %s\n",employee->name,employee->surname,employee->id);
}
void printSurNameFirst(EMPLOYEE *employee){
	printf("%s %s %s\n",employee->surname,employee->name,employee->id);
	
}
void printIdFirst(EMPLOYEE *employee){
	printf("%s %s %s\n",employee->id,employee->name,employee->surname);

}
