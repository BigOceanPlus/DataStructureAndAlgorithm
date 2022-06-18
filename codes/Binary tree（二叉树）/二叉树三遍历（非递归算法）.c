#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node Node;  // 树结点的结构体 
typedef struct node{
	Node* left;  // 左孩子结点 
	Node* right;  // 右孩子结点 
	char value;  // 结点值
	bool tag;  // 是否进入过栈的标志（用于后序遍历） 
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
		(*node)->tag = false;
		
		TreeNodeCreate(&(*node)->left);
		TreeNodeCreate(&(*node)->right);
	}
}

void PreorderTraversal(Node* node){
	Node* temp = node;  // 初始化 
	
	Node* stack[1000];  // 创建空栈 
	int top = -1;
	
	while(top != -1 || temp){  // 栈不为空且temp不为空结点 
		while(temp){  // 遍历到最左结点 
			stack[++ top] = temp;
			printf("%c",temp->value);
			temp = temp->left;
		}
		
		if(top != -1){  // 栈不为空
			temp = stack[top --];
			temp = temp->right;
		}
	}
}

void InorderTraversal(Node* node){
	Node* temp = node;  // 初始化
	
	Node* stack[1000];  // 创建空栈 
	int top = -1;
	
	while(top != -1 || temp){  // 栈不为空且temp不为空结点 
		while(temp){  // 遍历到最左结点 
			stack[++ top] = temp;
			temp = temp->left;
		}
		
		if(top != -1){  // 栈不为空
			temp = stack[top --];
			printf("%c",temp->value);
			temp = temp->right;
		}
	}
}

void PostorderTraversal(Node* node){
	Node* temp = node;  // 初始化
	
	Node* stack[1000];  // 创建空栈 
	int top = -1;
	
	while(top != -1 || temp){  // 栈不为空且temp不为空结点 
		while(temp){  // 遍历到最左结点 
			stack[++ top] = temp;
			temp = temp->left;
		}
		
		if(top != -1){  // 栈不为空
			temp = stack[top --];
			if(!temp->tag){  // 结点没入过栈 
			
				temp->tag = true;  // 修改tag值后重新入栈 
				stack[++ top] = temp;
				
				temp = temp->right;
			}
			else{  // 结点入过栈
				printf("%c",temp->value);
				temp = NULL;
			}
		}
	}
}
