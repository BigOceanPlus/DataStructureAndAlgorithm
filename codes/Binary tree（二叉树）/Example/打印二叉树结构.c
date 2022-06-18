#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node Node;  // 树结点的结构体 
typedef struct node{
	Node* left;  // 左孩子结点 
	Node* right;  // 右孩子结点 
	char value;  // 结点值 
	int height;  // 结点深度 
}Node; 

void TreeNodeCreate(Node** node,int height);  // 创建一个树(先序)
void PrintTreeGroup(Node* node);  // 打印凹入表 

/*
Input: 
AB-D--CE-F---
Output:
   C
         F
      E
A
      D
   B
*/

int main(){
	Node* rootNode;  // 树的根结点 
	
	TreeNodeCreate(&rootNode,1);
	
	PrintTreeGroup(rootNode);
	
	return 0;
}

void TreeNodeCreate(Node** node,int height){
	char ch;
	ch = getchar();
	if(ch == '-')  // 空结点 
		*node = NULL;
	else{  // 非空结点 
	
		(*node) = (Node*)malloc(sizeof(Node));  // DRL遍历方法
		(*node)->value = ch;
		(*node)->height = height;
		
		TreeNodeCreate(&(*node)->left,height + 1);
		TreeNodeCreate(&(*node)->right,height + 1);
	}
}

void PrintTreeGroup(Node* node){
	if(node != NULL){  // RDL遍历方法
		PrintTreeGroup(node->right);
		
		int i;
		for(i = 1; i < node->height; i ++)  // 格式化输出 
			printf("   ");
		printf("%c\n",node->value);
		
		PrintTreeGroup(node->left);
	}
}

