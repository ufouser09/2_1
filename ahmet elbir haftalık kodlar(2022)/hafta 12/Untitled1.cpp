#include <stdio.h>
#include <stdlib.h>
typedef struct treeNode{
	int data;
	struct treeNode *left;
	struct treeNode *right;
}TNODE;
TNODE* createNode(int d);
void preOrder(TNODE* root);
void postOrder(TNODE* root);
void inOrder(TNODE* root);
void createBST();
TNODE* insertNode(TNODE* root, int data);
int main(){
	TNODE* root;
	
	root = createNode(10);
	root->left = createNode(5);
	root->right = createNode(15);
	
	preOrder(root); printf("\n");
	postOrder(root); printf("\n");
	inOrder(root);
	
	createBST();
	
	return 0;
}

void createBST(){
	TNODE* root=NULL;
	int data;
	do{
		printf("Enter data"); scanf("%d",&data);
		if(data!=-1){
			root = insertNode(&root,data);
		}
		inOrder(root); printf("\n");
	}while(data!=-1);
	
}

TNODE* insertNode(TNODE* root, int data){
	if(root == NULL){
		root = createNode(data);
		return root;
	}
	else if(data > root->data){
		root->right = insertNode(root->right, data);
		return root;
	}
	else{
		root->left = insertNode(root->left, data);
		return root;
		
	}
}
TNODE* createNode(int d){
	TNODE* temp = (TNODE*) malloc(sizeof(TNODE));
	temp->data = d;
	temp->left = temp->right = NULL;
	return temp;
}

void preOrder(TNODE* root){
	if(root!=NULL){
		printf("%d ",root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}

void postOrder(TNODE* root){
	if(root!=NULL){
		postOrder(root->left);
		postOrder(root->right);
		printf("%d ",root->data);
		
		
	}
}

void inOrder(TNODE* root){
	if(root!=NULL){
		inOrder(root->left);
		printf("%d ",root->data);
		inOrder(root->right);
	}
}



