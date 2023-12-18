#include <stdio.h>
typedef struct{
	int id,int v1;int v2;
	struct Node* next;
}Node;
void printList(Node* n);
void insert(struct Node** head_ref,int id,int value1,int value2);
Node* intersection(Node* start1,Node* start2,int *(compare)(Node*,Node*));

int compare_by_value1(Node* Node1,Node* Node2);
int compare_by_value2(Node* Node1,Node* Node2);


int main(){
	Node *start =NULL;
	insert(&start,1,10,15);
	insert(&start,2,20,15);
	insert(&start,4,20,15);
	insert(&start,7,30,20);
	insert(&start,10,30,40);
	
	Node *start2=NULL;
	insert(&start2,1,10,15);
	insert(&start2,4,25,15);
	insert(&start2,7,25,20);
	insert(&start2,10,30,41);
	
	Node* node3=intersection(start,start2,compare_by_value1);
	printList(node3);
	Node* node4=intersection(start,start2,compare_by_value2);
	printList(node4);
	
	return 0;
}
void printList(Node* n){
	
	
	
}
int compare_by_value1(Node* Node1,Node* Node2){
	
	
	
}
int compare_by_value2(Node* Node1,Node* Node2){
	return strcmp()
}
void insert(struct Node** head_ref,int id,int value1,int value2){
	
}
Node* intersection(Node* start1,Node* start2,int (*compare)(Node*,Node*)){
	
}
