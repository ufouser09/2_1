#include <stdio.h>
#include <stdlib.h>
typedef struct Employee{
	char name[20];
	char surname[20];
	char id[12];
	struct Employee *next;
} EMPLOYEE;
 //typedef struct Employee EMPLOYEE ;
int addRecord(EMPLOYEE **head);
int removeRecord(EMPLOYEE **head);
void printRecords(EMPLOYEE *head, void (*fptr) (EMPLOYEE*) );
void printNameFirst(EMPLOYEE *employee);
void printSurNameFirst(EMPLOYEE *employee);
void printIDFirst(EMPLOYEE *employee);

int main(){
	EMPLOYEE *head=NULL;
	int option=0;
	while(option!=3){
		printf("1-Add\n2-Remove\n3-Exit\n");
		scanf("%d",&option);
		
		switch(option){
			case 1: addRecord(&head); printRecords(head,printIDFirst); break;
			case 2: removeRecord(&head); printRecords(head,printNameFirst); break;
		}
	}
	
}

int addRecord(EMPLOYEE **head){
	EMPLOYEE *emp;
	emp = (EMPLOYEE*) malloc(sizeof(EMPLOYEE));
	if(emp==NULL){
		return -1;
	}
	printf("Enter name, surname, and id, respectively");
	scanf("%s %s %s",&emp->name,emp->surname,emp->id);
	emp->next=*head;
	*head=emp;
	return 0;
}

int removeRecord(EMPLOYEE **head){
	char id[12];
	int found=0;
	printf("Enter id to remove from list"); scanf("%s",id);
	EMPLOYEE *tmp=*head;
	EMPLOYEE *prev=NULL;
	while(tmp!=NULL && !found){
		if(strcmp(tmp->id,id)==0){
			found=1;
			if(prev==NULL){
				*head = tmp->next;
			}
			else{
				prev->next = tmp->next;	
			}
			free(tmp);
		}
		prev = tmp;
		tmp=tmp->next;
		
	}
	return found;
}

void printRecords(EMPLOYEE *head, void (*fptr)(EMPLOYEE *)){
	EMPLOYEE *tmp=head;
	while(tmp!=NULL){
		fptr(tmp);
		tmp = tmp->next;
	}
}

void printNameFirst(EMPLOYEE *e){
	printf("%s %s %s\n",e->name,e->surname,e->id);
}
void printSurNameFirst(EMPLOYEE *e){
	printf("%s %s %s\n",e->surname,e->name,e->id);
}

void printIDFirst(EMPLOYEE *e){
	printf("%s %s %s\n",e->id, e->surname,e->name);
}

