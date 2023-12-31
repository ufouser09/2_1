#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int data;
	struct node *next;
}NODE;
void addFront(NODE **head, int data);
void addLast(NODE **head, int data);
void push(NODE **head, int data);
void pop(NODE **head);
void traverseForward(NODE *head);
NODE* searchNode(NODE *head,int data);

int main(){
	NODE *head=NULL;
	NODE *tmp;
    traverseForward(head);
    push(&head,10);
    traverseForward(head);
    push(&head,20);
    traverseForward(head);
    push(&head,30);
    traverseForward(head);
    push(&head,40);
    traverseForward(head);
    pop(&head);
    traverseForward(head);
    pop(&head);
    traverseForward(head);
	return 0;
	
}
NODE* getNode(int data){
	NODE *newNode=(NODE*) malloc(1*sizeof(NODE));
	newNode->data=data;
	newNode->next=NULL;	
	return newNode;
}

NODE* searchNode(NODE *head,int data){
	NODE *tmp=head;
	while(tmp!=NULL && tmp->data!=data){
		tmp = tmp->next;
	}	
	return tmp;
}


void addFront(NODE **head, int data){
	NODE *newNode=getNode(data);
	newNode->next=*head;
	*head=newNode;
}
void push(NODE **head, int data){
	addFront(head,data);
}
void pop(NODE **head){
	NODE *tmp;
	if(*head==NULL){
		printf("Stack is empty\n");
	}else{
		printf("silinen eleman=%d\n",(*head)->data);
		tmp  = *head;
		*head = (*head)->next;
		free(tmp);
	}
	
}
void addLast(NODE **head, int data){
	NODE *tmp;
	NODE *newNode=getNode(data);
	
	if(*head==NULL){
		*head=newNode;
	}
	else{
		tmp = *head;
		while(tmp->next!=NULL){
			tmp = tmp->next;
		}
		tmp->next = newNode;
	}
	
}


void traverseForward(NODE *head){
	NODE *tmp=head;
	while(tmp!=NULL){
		printf("%d ",tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}

/*
10
20 10
30 20 10
40 30 20 10
silinen eleman=40
30 20 10
silinen eleman=30
20 10
*/
