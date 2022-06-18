#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node Node;  // 树结点的结构体 
typedef struct node{
	Node* left;  // 左孩子结点 
	Node* right;  // 右孩子结点 
	char value;  // 结点值 
}Node; 

void TreeNodeCreate(Node** node);  // 创建一棵树(先序)
void PreorderTraversal(Node* node);  // 先序遍历 
void InorderTraversal(Node* node);  // 中序遍历 
void PostorderTraversal(Node* node);  // 后序遍历 

/*
Input:
ABC--DE-G--F---
Output:
前序：ABCDEGF
中序：CBEGDFA
后序：CGEFDBA
*/

int main(){
	Node* rootNode;  // 根结点 
	TreeNodeCreate(&rootNode);
	
	printf("先序：");
	PreorderTraversal(rootNode);
	printf("\n");
	
	printf("中序：");
	InorderTraversal(rootNode);
	printf("\n");
	
	printf("后序：");
	PostorderTraversal(rootNode);
	printf("\n");
	return 0;
}

void TreeNodeCreate(Node** node){
	char ch;
	ch = getchar();  // 接受输入值
	 
	if(ch == '-')  // 空结点 
		*node = NULL;
	else{  // 非空结点 
		(*node) = (Node*)malloc(sizeof(Node));
		(*node)->value = ch;
		
		TreeNodeCreate(&(*node)->left);
		TreeNodeCreate(&(*node)->right);
	}
}

void PreorderTraversal(Node* node){
	if(node != NULL){
		printf("%c",node->value);
		PreorderTraversal(node->left);
		PreorderTraversal(node->right);
	}
}

void InorderTraversal(Node* node){
	if(node != NULL){
		InorderTraversal(node->left);
		printf("%c",node->value);
		InorderTraversal(node->right);
	}
}

void PostorderTraversal(Node* node){
	if(node != NULL){
		PostorderTraversal(node->left);
		PostorderTraversal(node->right);
		printf("%c",node->value);
	}
}

