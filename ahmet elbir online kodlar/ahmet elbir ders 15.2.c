#include <stdio.h>
#include <stdlib.h>
typedef struct treeNode{
	int data;
	struct treeNode *left;
	struct treeNode *right;
}TreeNode;
TreeNode *insertNode(TreeNode *root,int data);
TreeNode* createNode(int data){
	TreeNode *tmp=(TreeNode*)malloc(sizeof(TreeNode));
	tmp->data=data;
	tmp->left=tmp=right=NULL;
	return tmp;
}
void preorder(TreeNode *root){
	if(root!=NULL){
		printf("%d",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void inorder(TreeNode *root){
	if(root!=NULL){
		preorder(root->left);
		printf("%d",root->data);
		preorder(root->right);
	}
}
void postorder(TreeNode *root){
	if(root!=NULL){
		
		preorder(root->left);
		preorder(root->right);
		printf("%d",root->data);
	}
}


int main(){
	TreeNode *root=NULL;
	/*root=createNode(10);
	root->left = createNode(5);
	root->right=createNode(15);*/
	int data=1;
	do{
		printf("enter data, 0 for exit");
		scanf("%d",&data);
		
		root=insertNode(root,data);
	}while(data!=0);
	
	
	printf("\n");
	
	
	preorder(root); 
		printf("\n");

	inorder(root);
		printf("\n");

	postorder(root);
}
TreeNode *insertNode(TreeNode *root,int data){
	if(root==NULL){
		root=createNode(data);
		return root;
	}
	else if(data>root->data){
		root->right=insertNode(root->right,data);
		return root;
	}
	else{
		root->left=insertNode(root->left,data);
		return root;
	}
}
