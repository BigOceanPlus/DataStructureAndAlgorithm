#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node Node;  // 树结点的结构体 
typedef struct node{
	Node* left;  // 左孩子结点 
	Node* right;  // 右孩子结点 
	char value;  // 结点值
}Node; 

void TreeNodeCreate(Node** node);  // 创建一棵树(先序)
void LevelTraversal(Node* node);  // 层次遍历

/*
Input:
ABC--DE-G--F---
Output:

*/

int main(){
	Node* rootNode;  // 根结点 
	TreeNodeCreate(&rootNode);
	
	LevelTraversal(rootNode);
	
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

void LevelTraversal(Node* node){
	Node* queue[100];  // 创建空队列（由于该队列不是循环队列，所以树的结点不要超过100个） 
	int begin,end;
	begin = end = -1;
	
	Node* temp = node;  // 根结点入队 
	queue[++ end] = temp;  
	
	while(begin != end){
		temp = queue[++ begin];  // 结点出队 
		printf("%c",temp->value);
		
		if(temp->left)  // 左孩子结点非空结点 
			queue[++ end] = temp->left;  // 结点入队 
			
		if(temp->right)  // 右孩子结点非空结点 
			queue[++ end] = temp->right;  // 结点入队 
	}
}
